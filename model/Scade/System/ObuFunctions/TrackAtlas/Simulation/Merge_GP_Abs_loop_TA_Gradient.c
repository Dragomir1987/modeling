/* $*************** KCG Version 6.1.3 (build i6) ****************
** Command: s2c613 -config C:/GITHUB/modeling/model/Scade/System/ObuFunctions/TrackAtlas/Simulation\kcg_s2c_config.txt
** Generation date: 2015-08-31T19:03:53
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "Merge_GP_Abs_loop_TA_Gradient.h"

void Merge_GP_Abs_loop_reset_TA_Gradient(
  outC_Merge_GP_Abs_loop_TA_Gradient *outC)
{
}

/* TA_Gradient::Merge_GP_Abs_loop */
void Merge_GP_Abs_loop_TA_Gradient(
  /* TA_Gradient::Merge_GP_Abs_loop::i */kcg_int i,
  /* TA_Gradient::Merge_GP_Abs_loop::GP */GradientProfile_t_TrackAtlasTypes *GP,
  /* TA_Gradient::Merge_GP_Abs_loop::First_Section_To_Replace */kcg_int First_Section_To_Replace,
  /* TA_Gradient::Merge_GP_Abs_loop::new_GP_received */GradientProfile_t_TrackAtlasTypes *new_GP_received,
  outC_Merge_GP_Abs_loop_TA_Gradient *outC)
{
  kcg_copy_GradientProfile_t_TrackAtlasTypes(&outC->_L20, GP);
  kcg_copy_GradientProfile_t_TrackAtlasTypes(&outC->_L6, new_GP_received);
  outC->_L11 = i;
  if ((0 <= outC->_L11) & (outC->_L11 < 50)) {
    kcg_copy_Gradient_section_t_TrackAtlasTypes(
      &outC->_L15,
      &outC->_L6[outC->_L11]);
  }
  else {
    kcg_copy_Gradient_section_t_TrackAtlasTypes(
      &outC->_L15,
      (Gradient_section_t_TrackAtlasTypes *)
        &DEFAULT_GradientSection_TrackAtlasTypes);
  }
  outC->_L5 = i;
  outC->_L4 = First_Section_To_Replace;
  outC->_L7 = outC->_L5 + outC->_L4;
  kcg_copy_GradientProfile_t_TrackAtlasTypes(&outC->_L19, &outC->_L20);
  if ((0 <= outC->_L7) & (outC->_L7 < 50)) {
    kcg_copy_Gradient_section_t_TrackAtlasTypes(
      &outC->_L19[outC->_L7],
      &outC->_L15);
  }
  kcg_copy_GradientProfile_t_TrackAtlasTypes(
    &outC->GradientProfile_out,
    &outC->_L19);
}

/* $*************** KCG Version 6.1.3 (build i6) ****************
** Merge_GP_Abs_loop_TA_Gradient.c
** Generation date: 2015-08-31T19:03:53
*************************************************************$ */

