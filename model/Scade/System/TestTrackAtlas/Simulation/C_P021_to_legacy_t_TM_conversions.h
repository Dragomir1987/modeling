/* $*************** KCG Version 6.1.3 (build i6) ****************
** Command: s2c613 -config C:/GITHUB/modeling/model/Scade/System/TestTrackAtlas/Simulation\kcg_s2c_config.txt
** Generation date: 2015-09-04T14:44:59
*************************************************************$ */
#ifndef _C_P021_to_legacy_t_TM_conversions_H_
#define _C_P021_to_legacy_t_TM_conversions_H_

#include "kcg_types.h"
#include "C_P021_to_legacy_loop_TM_conversions.h"

/* =====================  no input structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  P21_GradientProfiles_T_Packet_Types_Pkg /* TM_conversions::C_P021_to_legacy_t::P021_legacy_out */ P021_legacy_out;
  /* -----------------------  no local probes  ----------------------- */
  /* -----------------  no initialization variables  ----------------- */
  /* -----------------------  no local memory  ----------------------- */
  /* ---------------------  sub nodes' contexts  --------------------- */
  outC_C_P021_to_legacy_loop_TM_conversions /* 1 */ Context_1[7];
  /* ----------------- no clocks of observable data ------------------ */
  /* -------------------- (-debug) no assertions  -------------------- */
  /* ------------------- (-debug) local variables -------------------- */
  P021_OBU_T_TM /* TM_conversions::C_P021_to_legacy_t::_L1 */ _L1;
  array__23540 /* TM_conversions::C_P021_to_legacy_t::_L20 */ _L20;
  array__24120 /* TM_conversions::C_P021_to_legacy_t::_L23 */ _L23;
  array__24123 /* TM_conversions::C_P021_to_legacy_t::_L26 */ _L26;
  P021_OBU_sectionlist_enum_T_TM /* TM_conversions::C_P021_to_legacy_t::_L45 */ _L45;
} outC_C_P021_to_legacy_t_TM_conversions;

/* ===========  node initialization and cycle functions  =========== */
/* TM_conversions::C_P021_to_legacy_t */
extern void C_P021_to_legacy_t_TM_conversions(
  /* TM_conversions::C_P021_to_legacy_t::P021_in */P021_OBU_T_TM *P021_in,
  outC_C_P021_to_legacy_t_TM_conversions *outC);

extern void C_P021_to_legacy_t_reset_TM_conversions(
  outC_C_P021_to_legacy_t_TM_conversions *outC);

#endif /* _C_P021_to_legacy_t_TM_conversions_H_ */
/* $*************** KCG Version 6.1.3 (build i6) ****************
** C_P021_to_legacy_t_TM_conversions.h
** Generation date: 2015-09-04T14:44:59
*************************************************************$ */

