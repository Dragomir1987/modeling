/* $*************** KCG Version 6.1.3 (build i6) ****************
** Command: s2c613 -config C:/GITHUB/modeling/model/Scade/System/TestTrackAtlas/Simulation\kcg_s2c_config.txt
** Generation date: 2015-09-04T14:44:59
*************************************************************$ */
#ifndef _C_P138_to_legacy_t_TM_conversions_H_
#define _C_P138_to_legacy_t_TM_conversions_H_

#include "kcg_types.h"

/* =====================  no input structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  P138_ReversingAreaInformation_T_Packet_Types_Pkg /* TM_conversions::C_P138_to_legacy_t::P138_legacy_out */ P138_legacy_out;
  /* -----------------------  no local probes  ----------------------- */
  /* -----------------  no initialization variables  ----------------- */
  /* -----------------------  no local memory  ----------------------- */
  /* -------------------- no sub nodes' contexts  -------------------- */
  /* ----------------- no clocks of observable data ------------------ */
  /* -------------------- (-debug) no assertions  -------------------- */
  /* ------------------- (-debug) local variables -------------------- */
  P138_OBU_T_TM /* TM_conversions::C_P138_to_legacy_t::_L1 */ _L1;
  P138_ReversingAreaInformation_T_Packet_Types_Pkg /* TM_conversions::C_P138_to_legacy_t::_L2 */ _L2;
  L_REVERSEAREA /* TM_conversions::C_P138_to_legacy_t::_L7 */ _L7;
  D_STARTREVERSE /* TM_conversions::C_P138_to_legacy_t::_L6 */ _L6;
  Q_SCALE /* TM_conversions::C_P138_to_legacy_t::_L5 */ _L5;
  Q_DIR /* TM_conversions::C_P138_to_legacy_t::_L4 */ _L4;
  kcg_bool /* TM_conversions::C_P138_to_legacy_t::_L3 */ _L3;
} outC_C_P138_to_legacy_t_TM_conversions;

/* ===========  node initialization and cycle functions  =========== */
/* TM_conversions::C_P138_to_legacy_t */
extern void C_P138_to_legacy_t_TM_conversions(
  /* TM_conversions::C_P138_to_legacy_t::P138_in */P138_OBU_T_TM *P138_in,
  outC_C_P138_to_legacy_t_TM_conversions *outC);

extern void C_P138_to_legacy_t_reset_TM_conversions(
  outC_C_P138_to_legacy_t_TM_conversions *outC);

#endif /* _C_P138_to_legacy_t_TM_conversions_H_ */
/* $*************** KCG Version 6.1.3 (build i6) ****************
** C_P138_to_legacy_t_TM_conversions.h
** Generation date: 2015-09-04T14:44:59
*************************************************************$ */

