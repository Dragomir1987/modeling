/* $*************** KCG Version 6.1.3 (build i6) ****************
** Command: s2c613 -config C:/GITHUB/modeling/model/Scade/System/ObuFunctions/TrackAtlas/Simulation\kcg_s2c_config.txt
** Generation date: 2015-09-02T13:44:15
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "EVAL_Q_GDIR_TA_Lib_internal.h"

void EVAL_Q_GDIR_reset_TA_Lib_internal(outC_EVAL_Q_GDIR_TA_Lib_internal *outC)
{
}

/* TA_Lib_internal::EVAL_Q_GDIR */
void EVAL_Q_GDIR_TA_Lib_internal(
  inC_EVAL_Q_GDIR_TA_Lib_internal *inC,
  outC_EVAL_Q_GDIR_TA_Lib_internal *outC)
{
  outC->_L2 = inC->g_a;
  outC->_L11 = 255;
  outC->_L10 = outC->_L2 == outC->_L11;
  outC->_L3 = ENUM_Q_GDIR_uphill_TM_conversions;
  outC->_L1 = inC->q_gdir;
  outC->_L4 = outC->_L3 == outC->_L1;
  outC->_L5 = 1;
  outC->_L6 = - 1;
  if (outC->_L4) {
    outC->_L7 = outC->_L5;
  }
  else {
    outC->_L7 = outC->_L6;
  }
  outC->_L8 = outC->_L7 * outC->_L2;
  if (outC->_L10) {
    outC->_L13 = outC->_L11;
  }
  else {
    outC->_L13 = outC->_L8;
  }
  outC->gradient = outC->_L13;
}

/* $*************** KCG Version 6.1.3 (build i6) ****************
** EVAL_Q_GDIR_TA_Lib_internal.c
** Generation date: 2015-09-02T13:44:15
*************************************************************$ */

