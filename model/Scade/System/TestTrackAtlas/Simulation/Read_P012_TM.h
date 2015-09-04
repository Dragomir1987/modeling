/* $*************** KCG Version 6.1.3 (build i6) ****************
** Command: s2c613 -config C:/GITHUB/modeling/model/Scade/System/TestTrackAtlas/Simulation\kcg_s2c_config.txt
** Generation date: 2015-09-04T14:44:59
*************************************************************$ */
#ifndef _Read_P012_TM_H_
#define _Read_P012_TM_H_

#include "kcg_types.h"
#include "C_P012_compr_onboard_TM_conversions.h"
#include "RECV_ReadPackets_TM_lib_internal.h"

/* =====================  no input structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  kcg_bool /* TM::Read_P012::received */ received;
  P012_OBU_T_TM /* TM::Read_P012::P012_OBU_out */ P012_OBU_out;
  /* -----------------------  no local probes  ----------------------- */
  /* -----------------  no initialization variables  ----------------- */
  /* -----------------------  no local memory  ----------------------- */
  /* ---------------------  sub nodes' contexts  --------------------- */
  outC_C_P012_compr_onboard_TM_conversions /* 1 */ _1_Context_1;
  outC_RECV_ReadPackets_TM_lib_internal /* 1 */ Context_1;
  /* ----------------- no clocks of observable data ------------------ */
  /* -------------------- (-debug) no assertions  -------------------- */
  /* ------------------- (-debug) local variables -------------------- */
  array_int_500 /* TM::Read_P012::_L5 */ _L5;
  CompressedPackets_T_Common_Types_Pkg /* TM::Read_P012::_L6 */ _L6;
  MetadataElement_T_Common_Types_Pkg /* TM::Read_P012::_L30 */ _L30;
  P012_OBU_T_TM /* TM::Read_P012::_L166 */ _L166;
  kcg_bool /* TM::Read_P012::_L167 */ _L167;
} outC_Read_P012_TM;

/* ===========  node initialization and cycle functions  =========== */
/* TM::Read_P012 */
extern void Read_P012_TM(
  /* TM::Read_P012::Message_IN */CompressedPackets_T_Common_Types_Pkg *Message_IN,
  outC_Read_P012_TM *outC);

extern void Read_P012_reset_TM(outC_Read_P012_TM *outC);

#endif /* _Read_P012_TM_H_ */
/* $*************** KCG Version 6.1.3 (build i6) ****************
** Read_P012_TM.h
** Generation date: 2015-09-04T14:44:59
*************************************************************$ */
