/* $*************** KCG Version 6.1.3 (build i6) ****************
** Command: s2c613 -config C:/GITHUB/modeling/model/Scade/System/TestTrackAtlas/Simulation\kcg_s2c_config.txt
** Generation date: 2015-09-04T14:44:59
*************************************************************$ */
#ifndef _SP_STM_MaxSpeed_TA_SpeedProfiles_H_
#define _SP_STM_MaxSpeed_TA_SpeedProfiles_H_

#include "kcg_types.h"

/* =====================  no input structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  SSP_cat_t_TA_MRSP /* TA_SpeedProfiles::SP_STM_MaxSpeed::STM_MaxSpeed */ STM_MaxSpeed;
  /* -----------------------  no local probes  ----------------------- */
  /* -----------------  no initialization variables  ----------------- */
  /* -----------------------  no local memory  ----------------------- */
  /* -------------------- no sub nodes' contexts  -------------------- */
  /* ----------------- no clocks of observable data ------------------ */
  /* -------------------- (-debug) no assertions  -------------------- */
  /* ------------------- (-debug) local variables -------------------- */
  ReceivedMessage_T_Common_Types_Pkg /* TA_SpeedProfiles::SP_STM_MaxSpeed::_L1 */ _L1;
  SSP_cat_t_TA_MRSP /* TA_SpeedProfiles::SP_STM_MaxSpeed::_L2 */ _L2;
  kcg_bool /* TA_SpeedProfiles::SP_STM_MaxSpeed::_L3 */ _L3;
} outC_SP_STM_MaxSpeed_TA_SpeedProfiles;

/* ===========  node initialization and cycle functions  =========== */
/* TA_SpeedProfiles::SP_STM_MaxSpeed */
extern void SP_STM_MaxSpeed_TA_SpeedProfiles(
  /* TA_SpeedProfiles::SP_STM_MaxSpeed::reset */kcg_bool reset,
  /* TA_SpeedProfiles::SP_STM_MaxSpeed::PacketsIn */ReceivedMessage_T_Common_Types_Pkg *PacketsIn,
  outC_SP_STM_MaxSpeed_TA_SpeedProfiles *outC);

extern void SP_STM_MaxSpeed_reset_TA_SpeedProfiles(
  outC_SP_STM_MaxSpeed_TA_SpeedProfiles *outC);

#endif /* _SP_STM_MaxSpeed_TA_SpeedProfiles_H_ */
/* $*************** KCG Version 6.1.3 (build i6) ****************
** SP_STM_MaxSpeed_TA_SpeedProfiles.h
** Generation date: 2015-09-04T14:44:59
*************************************************************$ */

