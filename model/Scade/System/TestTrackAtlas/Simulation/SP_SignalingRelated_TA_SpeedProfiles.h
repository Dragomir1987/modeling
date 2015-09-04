/* $*************** KCG Version 6.1.3 (build i6) ****************
** Command: s2c613 -config C:/GITHUB/modeling/model/Scade/System/TestTrackAtlas/Simulation\kcg_s2c_config.txt
** Generation date: 2015-09-04T14:44:59
*************************************************************$ */
#ifndef _SP_SignalingRelated_TA_SpeedProfiles_H_
#define _SP_SignalingRelated_TA_SpeedProfiles_H_

#include "kcg_types.h"

/* =====================  no input structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  SSP_cat_t_TA_MRSP /* TA_SpeedProfiles::SP_SignalingRelated::SignalingRelated */ SignalingRelated;
  /* -----------------------  no local probes  ----------------------- */
  /* -----------------  no initialization variables  ----------------- */
  /* -----------------------  no local memory  ----------------------- */
  /* -------------------- no sub nodes' contexts  -------------------- */
  /* ----------------- no clocks of observable data ------------------ */
  /* -------------------- (-debug) no assertions  -------------------- */
  /* ------------------- (-debug) local variables -------------------- */
  ReceivedMessage_T_Common_Types_Pkg /* TA_SpeedProfiles::SP_SignalingRelated::_L1 */ _L1;
  SSP_cat_t_TA_MRSP /* TA_SpeedProfiles::SP_SignalingRelated::_L2 */ _L2;
  kcg_bool /* TA_SpeedProfiles::SP_SignalingRelated::_L3 */ _L3;
} outC_SP_SignalingRelated_TA_SpeedProfiles;

/* ===========  node initialization and cycle functions  =========== */
/* TA_SpeedProfiles::SP_SignalingRelated */
extern void SP_SignalingRelated_TA_SpeedProfiles(
  /* TA_SpeedProfiles::SP_SignalingRelated::reset */kcg_bool reset,
  /* TA_SpeedProfiles::SP_SignalingRelated::MessageIn */ReceivedMessage_T_Common_Types_Pkg *MessageIn,
  outC_SP_SignalingRelated_TA_SpeedProfiles *outC);

extern void SP_SignalingRelated_reset_TA_SpeedProfiles(
  outC_SP_SignalingRelated_TA_SpeedProfiles *outC);

#endif /* _SP_SignalingRelated_TA_SpeedProfiles_H_ */
/* $*************** KCG Version 6.1.3 (build i6) ****************
** SP_SignalingRelated_TA_SpeedProfiles.h
** Generation date: 2015-09-04T14:44:59
*************************************************************$ */

