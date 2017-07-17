
// aleph-common
#include "fix.h"
#include "types.h"

#include "bfin_core.h"
#include "cv.h"
#include "fract_math.h"
#include <fract2float_conv.h>

// audio
#include "buffer.h"
#include "delay.h"
#include "module.h"
/// lines
#include "params.h"

#define LINES_BUF_FRAMES 0x2bf200
#define NLINES 3

typedef struct _linesData {
  ModuleData super;
  ParamData mParamData[eParamNumParams];
  volatile fract32 audioBuffer[NLINES][LINES_BUF_FRAMES];
} linesData;

ModuleData* gModuleData; 
linesData* pLinesData;
delayLine lines[NLINES];

fract32 in_del[NLINES] = { 0, 0, 0 };
fract32 out_del[NLINES] = { 0, 0, 0 };
fract32 out_mat[NLINES] = { 0, 0, 0 };

u16 m[NLINES] = { 1987, 1699, 1237 };
fract32 q[NLINES][NLINES] = { { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } };
fract32 b[NLINES] = { 0, 0, 0 }; // in
fract32 c[NLINES] = { 0, 0, 0 }; // out
fract32 g[NLINES] = { 0, 0, 0 }; // post matrix fb gain

static inline void param_setup(u32 id, ParamValue v) {
  gModuleData->paramData[id].value = v;
  module_set_param(id, v);
}

void module_init(void) {
  pLinesData = (linesData*)SDRAM_ADDRESS;
  
  gModuleData = &(pLinesData->super);
  strcpy(gModuleData->name, "lines");

  gModuleData->paramData = (ParamData*)pLinesData->mParamData;
  gModuleData->numParams = eParamNumParams;

  param_setup(eParam_q00, PARAM_AMP_12);
  param_setup(eParam_q01, PARAM_AMP_12);
  param_setup(eParam_q02, PARAM_AMP_12);
  param_setup(eParam_q10, PARAM_AMP_12);
  param_setup(eParam_q11, PARAM_AMP_12);
  param_setup(eParam_q12, PARAM_AMP_12);
  param_setup(eParam_q20, PARAM_AMP_12);
  param_setup(eParam_q21, PARAM_AMP_12);
  param_setup(eParam_q22, PARAM_AMP_12);

  param_setup(eParam_b0, PARAM_AMP_12);
  param_setup(eParam_b1, PARAM_AMP_12);
  param_setup(eParam_b2, PARAM_AMP_12);

  param_setup(eParam_c0, PARAM_AMP_12);
  param_setup(eParam_c1, PARAM_AMP_12);
  param_setup(eParam_c2, PARAM_AMP_12);

  param_setup(eParam_g0, PARAM_AMP_12);
  param_setup(eParam_g1, PARAM_AMP_12);
  param_setup(eParam_g2, PARAM_AMP_12);

  param_setup(eParam_m0, PARAM_AMP_12);
  param_setup(eParam_m1, PARAM_AMP_12);
  param_setup(eParam_m2, PARAM_AMP_12);

  delay_init(&(lines[0]), pLinesData->audioBuffer[0], LINES_BUF_FRAMES);
  memset(pLinesData->audioBuffer[0], 0, LINES_BUF_FRAMES * sizeof(fract32));

  delay_init(&(lines[1]), pLinesData->audioBuffer[1], LINES_BUF_FRAMES);
  memset(pLinesData->audioBuffer[1], 0, LINES_BUF_FRAMES * sizeof(fract32));

  delay_init(&(lines[1]), pLinesData->audioBuffer[2], LINES_BUF_FRAMES);
  memset(pLinesData->audioBuffer[2], 0, LINES_BUF_FRAMES * sizeof(fract32));
  
  delay_set_delay_samp(&(lines[0]), m[0]);
  delay_set_delay_samp(&(lines[1]), m[1]); 
  delay_set_delay_samp(&(lines[2]), m[2]); 
}

void module_deinit(void) {
}

u32 module_get_num_params(void) {
  return eParamNumParams;
}

void module_process_frame(void) { 
  // mono only for now (siso fdn)
  in_del[0] = mult_fr1x32x32(in[0], b[0]);
  in_del[0] = add_fr1x32(in_del[0], mult_fr1x32x32(out_mat[0], g[0]));

  in_del[1] = mult_fr1x32x32(in[1], b[1]);
  in_del[1] = add_fr1x32(in_del[1], mult_fr1x32x32(out_mat[1], g[1]));

  in_del[2] = mult_fr1x32x32(in[2], b[2]);
  in_del[2] = add_fr1x32(in_del[2], mult_fr1x32x32(out_mat[2], g[2]));

  // tick delay lines
  out_del[0] = delay_next(&(lines[0]), in_del[0]);
  out_del[1] = delay_next(&(lines[1]), in_del[1]);
  out_del[2] = delay_next(&(lines[2]), in_del[2]);

  out_mat[0] = mult_fr1x32x32(out_del[0], q[0][0]);
  out_mat[0] = add_fr1x32(out_mat[0], mult_fr1x32x32(out_del[1], q[0][1]));
  out_mat[0] = add_fr1x32(out_mat[0], mult_fr1x32x32(out_del[2], q[0][2]));

  out_mat[1] = mult_fr1x32x32(out_del[0], q[1][0]);
  out_mat[1] = add_fr1x32(out_mat[1], mult_fr1x32x32(out_del[1], q[1][1]));
  out_mat[1] = add_fr1x32(out_mat[1], mult_fr1x32x32(out_del[2], q[1][2]));

  out_mat[2] = mult_fr1x32x32(out_del[0], q[2][0]);
  out_mat[2] = add_fr1x32(out_mat[2], mult_fr1x32x32(out_del[1], q[2][1]));
  out_mat[2] = add_fr1x32(out_mat[2], mult_fr1x32x32(out_del[2], q[2][2]));

  out[0] = mult_fr1x32x32(out_del[0], c[0]);
  out[0] = add_fr1x32(out[0], mult_fr1x32x32(out_del[1], c[1]));
  out[0] = add_fr1x32(out[0], mult_fr1x32x32(out_del[2], c[2]));
}

void module_set_param(u32 idx, ParamValue v) {
  // switch(idx) {
  //   case eParam_q00:
  //     q[0][0] = v;
  //     break;

  //   case eParam_q01:
  //     q[0][1] = v;
  //     break;

  //   case eParam_q02:
  //     q[0][2] = v;
  //     break;

  //   case eParam_q10:
  //     q[1][0] = v;
  //     break;

  //   case eParam_q11:
  //     q[1][1] = v;
  //     break;

  //   case eParam_q12:
  //     q[1][2] = v;
  //     break;

  //   case eParam_q20:
  //     q[2][0] = v;
  //     break;

  //   case eParam_q21:
  //     q[2][1] = v;
  //     break;

  //   case eParam_q22:
  //     q[2][2] = v;
  //     break;


  //   case eParam_b0:
  //     b[0] = v;
  //     break;

  //   case eParam_b1:
  //     b[1] = v;
  //     break;

  //   case eParam_b2:
  //     b[2] = v;
  //     break;


  //   case eParam_c0:
  //     c[0] = v;
  //     break;

  //   case eParam_c1:
  //     c[1] = v;
  //     break;

  //   case eParam_c2:
  //     c[2] = v;
  //     break;


  //   case eParam_g0:
  //     g[0] = v;
  //     break;

  //   case eParam_g1:
  //     g[1] = v;
  //     break;

  //   case eParam_g2:
  //     g[2] = v;
  //     break;

  //   // need to talk to delay object in these to recompute read heads
  //   case eParam_m0:
  //     // param set here1
  //     break;

  //   case eParam_m1:
  //     // param set here
  //     break;

  //   case eParam_m2:
  //     // param set here
  //     break;


  //   default:
  //     break;
  // }
}
