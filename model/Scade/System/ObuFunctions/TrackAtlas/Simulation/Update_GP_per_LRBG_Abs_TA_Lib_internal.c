/* $*************** KCG Version 6.1.3 (build i6) ****************
** Command: s2c613 -config C:/GITHUB/modeling/model/Scade/System/ObuFunctions/TrackAtlas/Simulation\kcg_s2c_config.txt
** Generation date: 2015-08-31T17:37:26
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "Update_GP_per_LRBG_Abs_TA_Lib_internal.h"

void Update_GP_per_LRBG_Abs_reset_TA_Lib_internal(
  outC_Update_GP_per_LRBG_Abs_TA_Lib_internal *outC)
{
  kcg_int i;
  
  for (i = 0; i < 33; i++) {
    /* 1 */
    Update_GP_per_LRBG_Abs_loop_reset_TA_Lib_internal(&outC->_1_Context_1[i]);
  }
  /* 1 */ _1_FindStartOfNewGradientPro_reset_TA_Lib_internal(&outC->Context_1);
}

/* TA_Lib_internal::Update_GP_per_LRBG_Abs */
void Update_GP_per_LRBG_Abs_TA_Lib_internal(
  inC_Update_GP_per_LRBG_Abs_TA_Lib_internal *inC,
  outC_Update_GP_per_LRBG_Abs_TA_Lib_internal *outC)
{
  kcg_int i2;
  kcg_int i1;
  GradientProfile_t_TrackAtlasTypes tmp;
  kcg_int i;
  kcg_int tmp3;
  
  kcg_copy_GradientProfile_t_TrackAtlasTypes(
    &outC->_L45,
    &inC->Last_GradientProfile_in);
  outC->_L148 = outC->_L45[0].valid;
  kcg_copy_GradientProfile_t_TrackAtlasTypes(&outC->_L5, &inC->new_GP);
  for (i2 = 0; i2 < 33; i2++) {
    kcg_copy_GradientProfile_t_TrackAtlasTypes(&outC->_L47[i2], &outC->_L5);
  }
  outC->tmp = outC->_L148;
  if (outC->tmp) {
    /* 1 */
    _1_FindStartOfNewGradientPro_TA_Lib_internal(
      &outC->_L45,
      &outC->_L5,
      &outC->Context_1);
    tmp3 = outC->Context_1.relevant_section;
    outC->_L1 = tmp3;
  }
  else {
    outC->_L1 = 0;
  }
  for (i1 = 0; i1 < 33; i1++) {
    outC->_L9[i1] = outC->_L1;
  }
  kcg_copy_GradientProfile_t_TrackAtlasTypes(&outC->_L14, &outC->_L45);
  for (i = 0; i < 33; i++) {
    kcg_copy_GradientProfile_t_TrackAtlasTypes(&tmp, &outC->_L14);
    /* 1 */
    Update_GP_per_LRBG_Abs_loop_TA_Lib_internal(
      i,
      &tmp,
      outC->_L9[i],
      &outC->_L47[i],
      &outC->_1_Context_1[i]);
    kcg_copy_GradientProfile_t_TrackAtlasTypes(
      &outC->_L14,
      &outC->_1_Context_1[i].GradientProfile_out);
  }
  kcg_copy_GradientProfile_t_TrackAtlasTypes(
    &outC->GradientdProfile_out,
    &outC->_L14);
}

/* $*************** KCG Version 6.1.3 (build i6) ****************
** Update_GP_per_LRBG_Abs_TA_Lib_internal.c
** Generation date: 2015-08-31T17:37:26
*************************************************************$ */

