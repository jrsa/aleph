 
#include <string.h>
#include "module.h"
#include "param_common.h"
#include "params.h" 

void fill_param_desc(ParamDesc* desc) {
    strcpy(desc[eParam_q00].label, "q00");
    desc[eParam_q00].type = eParamTypeAmp;
    desc[eParam_q00].min = 0x00000000;
    desc[eParam_q00].max = PARAM_AMP_12;
    desc[eParam_q00].radix = 16;

    strcpy(desc[eParam_q01].label, "q01");
    desc[eParam_q01].type = eParamTypeAmp;
    desc[eParam_q01].min = 0x00000000;
    desc[eParam_q01].max = PARAM_AMP_12;
    desc[eParam_q01].radix = 16;

    strcpy(desc[eParam_q02].label, "q02");
    desc[eParam_q02].type = eParamTypeAmp;
    desc[eParam_q02].min = 0x00000000;
    desc[eParam_q02].max = PARAM_AMP_12;
    desc[eParam_q02].radix = 16;

    strcpy(desc[eParam_q10].label, "q10");
    desc[eParam_q10].type = eParamTypeAmp;
    desc[eParam_q10].min = 0x00000000;
    desc[eParam_q10].max = PARAM_AMP_12;
    desc[eParam_q10].radix = 16;

    strcpy(desc[eParam_q11].label, "q11");
    desc[eParam_q11].type = eParamTypeAmp;
    desc[eParam_q11].min = 0x00000000;
    desc[eParam_q11].max = PARAM_AMP_12;
    desc[eParam_q11].radix = 16;

    strcpy(desc[eParam_q12].label, "q12");
    desc[eParam_q12].type = eParamTypeAmp;
    desc[eParam_q12].min = 0x00000000;
    desc[eParam_q12].max = PARAM_AMP_12;
    desc[eParam_q12].radix = 16;

    strcpy(desc[eParam_q20].label, "q20");
    desc[eParam_q20].type = eParamTypeAmp;
    desc[eParam_q20].min = 0x00000000;
    desc[eParam_q20].max = PARAM_AMP_12;
    desc[eParam_q20].radix = 16;

    strcpy(desc[eParam_q21].label, "q21");
    desc[eParam_q21].type = eParamTypeAmp;
    desc[eParam_q21].min = 0x00000000;
    desc[eParam_q21].max = PARAM_AMP_12;
    desc[eParam_q21].radix = 16;

    strcpy(desc[eParam_q22].label, "q22");
    desc[eParam_q22].type = eParamTypeAmp;
    desc[eParam_q22].min = 0x00000000;
    desc[eParam_q22].max = PARAM_AMP_12;
    desc[eParam_q22].radix = 16;


    strcpy(desc[eParam_b0].label, "b0");
    desc[eParam_b0].type = eParamTypeAmp;
    desc[eParam_b0].min = 0x00000000;
    desc[eParam_b0].max = PARAM_AMP_12;
    desc[eParam_b0].radix = 16;

    strcpy(desc[eParam_b1].label, "b1");
    desc[eParam_b1].type = eParamTypeAmp;
    desc[eParam_b1].min = 0x00000000;
    desc[eParam_b1].max = PARAM_AMP_12;
    desc[eParam_b1].radix = 16;

    strcpy(desc[eParam_b2].label, "b2");
    desc[eParam_b2].type = eParamTypeAmp;
    desc[eParam_b2].min = 0x00000000;
    desc[eParam_b2].max = PARAM_AMP_12;
    desc[eParam_b2].radix = 16;


    strcpy(desc[eParam_c0].label, "c0");
    desc[eParam_c0].type = eParamTypeAmp;
    desc[eParam_c0].min = 0x00000000;
    desc[eParam_c0].max = PARAM_AMP_12;
    desc[eParam_c0].radix = 16;

    strcpy(desc[eParam_c1].label, "c1");
    desc[eParam_c1].type = eParamTypeAmp;
    desc[eParam_c1].min = 0x00000000;
    desc[eParam_c1].max = PARAM_AMP_12;
    desc[eParam_c1].radix = 16;

    strcpy(desc[eParam_c2].label, "c2");
    desc[eParam_c2].type = eParamTypeAmp;
    desc[eParam_c2].min = 0x00000000;
    desc[eParam_c2].max = PARAM_AMP_12;
    desc[eParam_c2].radix = 16;


    strcpy(desc[eParam_g0].label, "g0");
    desc[eParam_g0].type = eParamTypeAmp;
    desc[eParam_g0].min = 0x00000000;
    desc[eParam_g0].max = PARAM_AMP_12;
    desc[eParam_g0].radix = 16;

    strcpy(desc[eParam_g1].label, "g1");
    desc[eParam_g1].type = eParamTypeAmp;
    desc[eParam_g1].min = 0x00000000;
    desc[eParam_g1].max = PARAM_AMP_12;
    desc[eParam_g1].radix = 16;

    strcpy(desc[eParam_g2].label, "g2");
    desc[eParam_g2].type = eParamTypeAmp;
    desc[eParam_g2].min = 0x00000000;
    desc[eParam_g2].max = PARAM_AMP_12;
    desc[eParam_g2].radix = 16;


    strcpy(desc[eParam_m0].label, "m0");
    desc[eParam_m0].type = eParamTypeAmp;
    desc[eParam_m0].min = 0x00000000;
    desc[eParam_m0].max = 0x2bf200;
    desc[eParam_m0].radix = 16;

    strcpy(desc[eParam_m1].label, "m1");
    desc[eParam_m1].type = eParamTypeAmp;
    desc[eParam_m1].min = 0x00000000;
    desc[eParam_m1].max = 0x2bf200;
    desc[eParam_m1].radix = 16;

    strcpy(desc[eParam_m2].label, "m2");
    desc[eParam_m2].type = eParamTypeAmp;
    desc[eParam_m2].min = 0x00000000;
    desc[eParam_m2].max = 0x2bf200;
    desc[eParam_m2].radix = 16;

}

// EOF
