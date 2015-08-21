/* $*************** KCG Version 6.1.3 (build i6) ****************
** Command: s2c613 -config C:/GITHUB/modeling/model/Scade/System/ObuFunctions/ETCS_Messaging/TrackMessages/KCG-Bitwalker/ReadP136\kcg_s2c_config.txt
** Generation date: 2015-08-21T16:12:21
*************************************************************$ */
#ifndef _Read_P136_TM_H_
#define _Read_P136_TM_H_

#include "kcg_types.h"
#include "RECV_ReadPackets_TM_lib_internal.h"
#include "C_P136_compr_onboard_TM_conversions.h"

/* ========================  input structure  ====================== */
typedef struct {
  CompressedPackets_T_Common_Types_Pkg /* TM::Read_P136::Message_IN */ Message_IN;
} inC_Read_P136_TM;

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  kcg_bool /* TM::Read_P136::received */ received;
  P136_OBU_T_TM /* TM::Read_P136::P136_OBU_out */ P136_OBU_out;
  /* -----------------------  no local probes  ----------------------- */
  /* -----------------  no initialization variables  ----------------- */
  /* -----------------------  no local memory  ----------------------- */
  /* -------------------- no sub nodes' contexts  -------------------- */
  /* ----------------- no clocks of observable data ------------------ */
} outC_Read_P136_TM;

/* ===========  node initialization and cycle functions  =========== */
/* TM::Read_P136 */
extern void Read_P136_TM(inC_Read_P136_TM *inC, outC_Read_P136_TM *outC);

extern void Read_P136_reset_TM(outC_Read_P136_TM *outC);

#endif /* _Read_P136_TM_H_ */
/* $*************** KCG Version 6.1.3 (build i6) ****************
** Read_P136_TM.h
** Generation date: 2015-08-21T16:12:21
*************************************************************$ */

