#ifndef _ALEPH_LINES_PARAMS_H_
#define _ALEPH_LINES_PARAMS_H_

#include "param_common.h"

#define PARAM_HZ_MIN OSC_FREQ_MIN
#define PARAM_HZ_MAX OSC_FREQ_MIN
#define PARAM_HZ_DEFAULT (OSC_FREQ_MIN * 16)

#define PARAM_DAC_MIN 0
#define PARAM_DAC_MAX 0x7fffffff
#define PARAM_DAC_RADIX 16

#define PARAM_RATE_MIN 0x2000 // 1/8
#define PARAM_RATE_MAX 0x80000 // 8
#define PARAM_RATE_RADIX 3

#define SMOOTH_FREQ_MIN 0x2000 // 1/8s
#define SMOOTH_FREQ_MAX 0x400000 // 64s
#define SMOOTH_FREQ_RADIX 7

/// FIXME: 
// right now, "fade" is the raw increment of a linear ramp from 0 to 0x7fffffff.
// not very intuitive,
// for 1s, inc = 0x7fffffff / 48k
// let's say max = 8s and min = 1ms
#define PARAM_FADE_MIN  0x2000 		// ~4s
#define PARAM_FADE_MAX  0x2000000 	// ~1ms
#define PARAM_FADE_RADIX 12 

// svf cutoff
#define PARAM_CUT_MAX     0x7fffffff
#define PARAM_CUT_DEFAULT 0x43D0A8EC // ~8k

// rq
#define PARAM_RQ_MIN 0x00000000
#define PARAM_RQ_MAX 0x0000ffff
#define PARAM_RQ_DEFAULT 0x0000FFF0

#define PARAM_AMP_0 (FRACT32_MAX)
#define PARAM_AMP_6 (FRACT32_MAX >> 1)
#define PARAM_AMP_12 (FRACT32_MAX >> 2)

// max time in seconds, 16.16
// 256 seconds, minus 1 bit
// #define PARAM_SECONDS_MAX 0xffffff
// #define PARAM_SECONDS_RADIX 9

// max time in seconds, 16.16
//// revert until shit gets figured out
#define PARAM_SECONDS_MAX 0x003c0000
#define PARAM_SECONDS_RADIX 7

/// smoother default
// about 1ms?
//#define PARAM_SLEW_DEFAULT  0x77000000
/// ehh, try longer
#define PARAM_SLEW_DEFAULT 0x77000000

// cv output
#define PARAM_CV_VAL_DEFAULT PARAM_AMP_6

// enumerate parameters
enum params {
  eParam_q00,
  eParam_q01,
  eParam_q02,
  eParam_q10,
  eParam_q11,
  eParam_q12,
  eParam_q20,
  eParam_q21,
  eParam_q22,

  eParam_b0,
  eParam_b1,
  eParam_b2,

  eParam_c0,
  eParam_c1,
  eParam_c2,

  eParam_g0,
  eParam_g1,
  eParam_g2,

  eParam_m0,
  eParam_m1,
  eParam_m2,

  eParamNumParams
};  


extern void fill_param_desc(ParamDesc* desc);

#endif // header guard 
// EOF
