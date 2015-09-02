/* $*************** KCG Version 6.1.3 (build i6) ****************
** Command: s2c613 -config C:/GITHUB/modeling/model/Scade/System/TestTrackAtlas/Simulation\kcg_s2c_config.txt
** Generation date: 2015-09-02T17:34:33
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "CAST_Int_to_L_TAFDISPLAY_TM_conversions.h"

void CAST_Int_to_L_TAFDISPLAY_reset_TM_conversions(
  outC_CAST_Int_to_L_TAFDISPLAY_TM_conversions *outC)
{
}

/* TM_conversions::CAST_Int_to_L_TAFDISPLAY */
void CAST_Int_to_L_TAFDISPLAY_TM_conversions(
  /* TM_conversions::CAST_Int_to_L_TAFDISPLAY::l_tafdisplay_int */kcg_int l_tafdisplay_int,
  outC_CAST_Int_to_L_TAFDISPLAY_TM_conversions *outC)
{
  kcg_bool noname;
  kcg_bool _1_noname;
  
  outC->_L1 = l_tafdisplay_int;
  outC->l_tafdisplay = outC->_L1;
  outC->_L11 = DIM_L_min_TM_conversions;
  outC->_L10 = DIM_L_max_TM_conversions;
  outC->_L9 = outC->_L1 > outC->_L10;
  outC->_L8 = outC->_L1 < outC->_L11;
  _1_noname = outC->_L8;
  noname = outC->_L9;
}

/* $*************** KCG Version 6.1.3 (build i6) ****************
** CAST_Int_to_L_TAFDISPLAY_TM_conversions.c
** Generation date: 2015-09-02T17:34:33
*************************************************************$ */

