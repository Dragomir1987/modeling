/* $*************** KCG Version 6.1.3 (build i6) ****************
** Command: s2c613 -config C:/GITHUB/modeling/model/Scade/System/ObuFunctions/TrackAtlas/Simulation\kcg_s2c_config.txt
** Generation date: 2015-09-01T16:26:32
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "Trunc_GP_at_BG_TA_Lib_internal.h"

void Trunc_GP_at_BG_reset_TA_Lib_internal(
  outC_Trunc_GP_at_BG_TA_Lib_internal *outC)
{
  kcg_int i;
  
  for (i = 0; i < 33; i++) {
    /* 1 */ Trunc_GP_at_BG_Loop_reset_TA_Lib_internal(&outC->_1_Context_1[i]);
  }
  /* 1 */ FindFirstRelevantGPForNewLRBG_reset_TA_Lib_internal(&outC->Context_1);
}

/* TA_Lib_internal::Trunc_GP_at_BG */
void Trunc_GP_at_BG_TA_Lib_internal(
  /* TA_Lib_internal::Trunc_GP_at_BG::ProfileIn */GradientProfile_t_TrackAtlasTypes *ProfileIn,
  /* TA_Lib_internal::Trunc_GP_at_BG::Loc_BG */kcg_int Loc_BG,
  /* TA_Lib_internal::Trunc_GP_at_BG::there_is_prv_LRBG */kcg_bool there_is_prv_LRBG,
  outC_Trunc_GP_at_BG_TA_Lib_internal *outC)
{
  kcg_int i2;
  kcg_int i1;
  GradientProfile_t_TrackAtlasTypes tmp;
  kcg_int i;
  
  outC->_L19 = 0;
  outC->_L17 = there_is_prv_LRBG;
  outC->_L16 = Loc_BG;
  if (outC->_L17) {
    outC->_L18 = outC->_L16;
  }
  else {
    outC->_L18 = outC->_L19;
  }
  kcg_copy_GradientProfile_t_TrackAtlasTypes(&outC->_L2, ProfileIn);
  outC->_L13 = 1;
  kcg_copy_GradientProfile_t_TrackAtlasTypes(&outC->_L7, ProfileIn);
  outC->_L3 = Loc_BG;
  /* 1 */
  FindFirstRelevantGPForNewLRBG_TA_Lib_internal(
    &outC->_L7,
    outC->_L3,
    &outC->Context_1);
  outC->_L1 = outC->Context_1.relevant_section;
  outC->_L12 = outC->_L13 + outC->_L1;
  if ((0 <= outC->_L12) & (outC->_L12 < 50)) {
    kcg_copy_Gradient_section_t_TrackAtlasTypes(
      &outC->_L8,
      &outC->_L2[outC->_L12]);
  }
  else {
    kcg_copy_Gradient_section_t_TrackAtlasTypes(
      &outC->_L8,
      (Gradient_section_t_TrackAtlasTypes *) &DEFAULT_GP_Section_TA_Gradient);
  }
  outC->_L9 = outC->_L8.Loc_Absolute;
  outC->_L14 = outC->_L9 - outC->_L18;
  kcg_copy_GradientProfile_t_TrackAtlasTypes(&outC->_L15, &outC->_L2);
  if ((0 <= outC->_L1) & (outC->_L1 < 50)) {
    outC->_L15[outC->_L1].L_Gradient = outC->_L14;
  }
  for (i2 = 0; i2 < 33; i2++) {
    outC->_L6[i2] = outC->_L3;
  }
  for (i1 = 0; i1 < 33; i1++) {
    outC->_L5[i1] = outC->_L1;
  }
  kcg_copy_GradientProfile_t_TrackAtlasTypes(&outC->_L4, &outC->_L15);
  for (i = 0; i < 33; i++) {
    kcg_copy_GradientProfile_t_TrackAtlasTypes(&tmp, &outC->_L4);
    /* 1 */
    Trunc_GP_at_BG_Loop_TA_Lib_internal(
      i,
      &tmp,
      outC->_L5[i],
      outC->_L6[i],
      &outC->_1_Context_1[i]);
    kcg_copy_GradientProfile_t_TrackAtlasTypes(
      &outC->_L4,
      &outC->_1_Context_1[i].ProfileOut);
  }
  kcg_copy_GradientProfile_t_TrackAtlasTypes(&outC->ProfileOut, &outC->_L4);
}

/* $*************** KCG Version 6.1.3 (build i6) ****************
** Trunc_GP_at_BG_TA_Lib_internal.c
** Generation date: 2015-09-01T16:26:32
*************************************************************$ */

