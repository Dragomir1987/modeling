/* $*************** KCG Version 6.1.3 (build i6) ****************
** Command: s2c613 -config C:/GITHUB/modeling/model/Scade/System/TestTrackAtlas/Simulation\kcg_s2c_config.txt
** Generation date: 2015-09-04T14:44:59
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "SSP_Normalize_Profile_loop_TA_SSP.h"

void SSP_Normalize_Profile_loop_reset_TA_SSP(
  outC_SSP_Normalize_Profile_loop_TA_SSP *outC)
{
}

/* TA_SSP::SSP_Normalize_Profile_loop */
void SSP_Normalize_Profile_loop_TA_SSP(
  /* TA_SSP::SSP_Normalize_Profile_loop::i */kcg_int i,
  /* TA_SSP::SSP_Normalize_Profile_loop::ProfileIn */StaticSpeedProfile_t_TrackAtlasTypes *ProfileIn,
  /* TA_SSP::SSP_Normalize_Profile_loop::pos_BG */L_internal_Type_Obu_BasicTypes_Pkg pos_BG,
  outC_SSP_Normalize_Profile_loop_TA_SSP *outC)
{
  outC->_L40 = i;
  kcg_copy_StaticSpeedProfile_t_TrackAtlasTypes(&outC->_L2, ProfileIn);
  outC->_L1 = i;
  if ((0 <= outC->_L1) & (outC->_L1 < 50)) {
    kcg_copy_StaticSpeedSection_t_TrackAtlasTypes(
      &outC->_L4,
      &outC->_L2[outC->_L1]);
  }
  else {
    kcg_copy_StaticSpeedSection_t_TrackAtlasTypes(
      &outC->_L4,
      (StaticSpeedSection_t_TrackAtlasTypes *) &DEFAULT_SSP_section_TA_SSP);
  }
  outC->_L5 = outC->_L4.valid;
  outC->_L38 = outC->_L4.d_static_abs;
  outC->_L3 = pos_BG;
  outC->_L9 = outC->_L38 - outC->_L3;
  outC->_L11 = 0;
  if (outC->_L5) {
    outC->_L10 = outC->_L9;
  }
  else {
    outC->_L10 = outC->_L11;
  }
  kcg_copy_StaticSpeedSection_t_TrackAtlasTypes(&outC->_L7, &outC->_L4);
  if (kcg_true) {
    outC->_L7.d_static_LRBG = outC->_L10;
  }
  kcg_copy_StaticSpeedProfile_t_TrackAtlasTypes(&outC->_L39, &outC->_L2);
  if ((0 <= outC->_L40) & (outC->_L40 < 50)) {
    kcg_copy_StaticSpeedSection_t_TrackAtlasTypes(
      &outC->_L39[outC->_L40],
      &outC->_L7);
  }
  kcg_copy_StaticSpeedProfile_t_TrackAtlasTypes(
    &outC->ProfileNormalized_LRBG,
    &outC->_L39);
}

/* $*************** KCG Version 6.1.3 (build i6) ****************
** SSP_Normalize_Profile_loop_TA_SSP.c
** Generation date: 2015-09-04T14:44:59
*************************************************************$ */

