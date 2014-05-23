/* $*************** KCG Version 6.1.3 (build i6) ****************
** Command: s2c613 -config C:/Users/GiovanniTrotta/Desktop/SoftwareBGO/Simulation\kcg_s2c_config.txt
** Generation date: 2014-05-20T18:38:18
*************************************************************$ */
#ifndef _FinalCheck3_DetermineBGOrientation_LRBG_H_
#define _FinalCheck3_DetermineBGOrientation_LRBG_H_

#include "kcg_types.h"

/* =====================  no input structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  Train_Position_Report_DetermineBGOrientation_LRBG_DataDctionary_Packets /* DetermineBGOrientation_LRBG::FinalCheck3::RBCReport */ RBCReport;
  FilteredBGMessage_DetermineBGOrientation_LRBG_DataDctionary_FilteredBGMessage /* DetermineBGOrientation_LRBG::FinalCheck3::FilteredBGMessage */ FilteredBGMessage;
  /* -----------------------  no local probes  ----------------------- */
  /* -----------------  no initialization variables  ----------------- */
  /* -----------------------  no local memory  ----------------------- */
  /* -------------------- no sub nodes' contexts  -------------------- */
  /* ----------------- no clocks of observable data ------------------ */
  /* -------------------- (-debug) no assertions  -------------------- */
  /* ------------------- (-debug) local variables -------------------- */
  CheckedBGMessage_DetermineBGOrientation_LRBG_DataDctionary_CheckedBGMessage /* DetermineBGOrientation_LRBG::FinalCheck3::_L1 */ _L1;
  Q_DIRTRAIN_DetermineBGOrientation_LRBG_DataDctionary_Variable /* DetermineBGOrientation_LRBG::FinalCheck3::_L2 */ _L2;
  RBCOrientationReport_DetermineBGOrientation_LRBG_DataDctionary_RBCOrientationReport /* DetermineBGOrientation_LRBG::FinalCheck3::_L3 */ _L3;
  Train_Position_Report_DetermineBGOrientation_LRBG_DataDctionary_Packets /* DetermineBGOrientation_LRBG::FinalCheck3::_L27 */ _L27;
  FilteredBGMessage_DetermineBGOrientation_LRBG_DataDctionary_FilteredBGMessage /* DetermineBGOrientation_LRBG::FinalCheck3::_L28 */ _L28;
  Q_DIRTRAIN_DetermineBGOrientation_LRBG_DataDctionary_Variable /* DetermineBGOrientation_LRBG::FinalCheck3::_L29 */ _L29;
  TrainInfo_DetermineBGOrientation_LRBG_DataDctionary_TrainInfo /* DetermineBGOrientation_LRBG::FinalCheck3::_L54 */ _L54;
  M_MODE_DetermineBGOrientation_LRBG_DataDctionary_Variable /* DetermineBGOrientation_LRBG::FinalCheck3::_L58 */ _L58;
  M_LEVELTR_DetermineBGOrientation_LRBG_DataDctionary_Variable /* DetermineBGOrientation_LRBG::FinalCheck3::_L57 */ _L57;
  kcg_bool /* DetermineBGOrientation_LRBG::FinalCheck3::_L60 */ _L60;
  kcg_bool /* DetermineBGOrientation_LRBG::FinalCheck3::_L61 */ _L61;
  kcg_bool /* DetermineBGOrientation_LRBG::FinalCheck3::_L62 */ _L62;
  M_LEVELTR_DetermineBGOrientation_LRBG_DataDctionary_Variable /* DetermineBGOrientation_LRBG::FinalCheck3::_L63 */ _L63;
  M_LEVELTR_DetermineBGOrientation_LRBG_DataDctionary_Variable /* DetermineBGOrientation_LRBG::FinalCheck3::_L64 */ _L64;
  Assignment_of_coordinate_system_DetermineBGOrientation_LRBG_DataDctionary_Packets /* DetermineBGOrientation_LRBG::FinalCheck3::_L66 */ _L66;
  Q_ORIENTATION_DetermineBGOrientation_LRBG_DataDctionary_Variable /* DetermineBGOrientation_LRBG::FinalCheck3::_L90 */ _L90;
  NID_LRBG_DetermineBGOrientation_LRBG_DataDctionary_Variable /* DetermineBGOrientation_LRBG::FinalCheck3::_L89 */ _L89;
  M_ACK_DetermineBGOrientation_LRBG_DataDctionary_Variable /* DetermineBGOrientation_LRBG::FinalCheck3::_L88 */ _L88;
  T_TRAIN_DetermineBGOrientation_LRBG_DataDctionary_Variable /* DetermineBGOrientation_LRBG::FinalCheck3::_L87 */ _L87;
  L_MESSAGE_DetermineBGOrientation_LRBG_DataDctionary_Variable /* DetermineBGOrientation_LRBG::FinalCheck3::_L86 */ _L86;
  NID_MESSAGE_DetermineBGOrientation_LRBG_DataDctionary_Variable /* DetermineBGOrientation_LRBG::FinalCheck3::_L85 */ _L85;
  Q_DIRTRAIN_DetermineBGOrientation_LRBG_DataDctionary_Variable /* DetermineBGOrientation_LRBG::FinalCheck3::_L91 */ _L91;
  kcg_bool /* DetermineBGOrientation_LRBG::FinalCheck3::_L92 */ _L92;
  M_ACK_DetermineBGOrientation_LRBG_DataDctionary_Variable /* DetermineBGOrientation_LRBG::FinalCheck3::_L93 */ _L93;
  Q_DIRTRAIN_DetermineBGOrientation_LRBG_DataDctionary_Variable /* DetermineBGOrientation_LRBG::FinalCheck3::_L95 */ _L95;
  kcg_bool /* DetermineBGOrientation_LRBG::FinalCheck3::_L96 */ _L96;
  Q_ORIENTATION_DetermineBGOrientation_LRBG_DataDctionary_Variable /* DetermineBGOrientation_LRBG::FinalCheck3::_L97 */ _L97;
  Q_DIRTRAIN_DetermineBGOrientation_LRBG_DataDctionary_Variable /* DetermineBGOrientation_LRBG::FinalCheck3::_L98 */ _L98;
  Q_DIRTRAIN_DetermineBGOrientation_LRBG_DataDctionary_Variable /* DetermineBGOrientation_LRBG::FinalCheck3::_L99 */ _L99;
} outC_FinalCheck3_DetermineBGOrientation_LRBG;

/* ===========  node initialization and cycle functions  =========== */
/* DetermineBGOrientation_LRBG::FinalCheck3 */
extern void FinalCheck3_DetermineBGOrientation_LRBG(
  /* DetermineBGOrientation_LRBG::FinalCheck3::CheckedBGMessage */CheckedBGMessage_DetermineBGOrientation_LRBG_DataDctionary_CheckedBGMessage *CheckedBGMessage,
  /* DetermineBGOrientation_LRBG::FinalCheck3::Orientation */Q_DIRTRAIN_DetermineBGOrientation_LRBG_DataDctionary_Variable Orientation,
  /* DetermineBGOrientation_LRBG::FinalCheck3::RBCOrientationReport */RBCOrientationReport_DetermineBGOrientation_LRBG_DataDctionary_RBCOrientationReport *RBCOrientationReport,
  /* DetermineBGOrientation_LRBG::FinalCheck3::TrainInfo */TrainInfo_DetermineBGOrientation_LRBG_DataDctionary_TrainInfo *TrainInfo,
  outC_FinalCheck3_DetermineBGOrientation_LRBG *outC);

extern void FinalCheck3_reset_DetermineBGOrientation_LRBG(
  outC_FinalCheck3_DetermineBGOrientation_LRBG *outC);

#endif /* _FinalCheck3_DetermineBGOrientation_LRBG_H_ */
/* $*************** KCG Version 6.1.3 (build i6) ****************
** FinalCheck3_DetermineBGOrientation_LRBG.h
** Generation date: 2014-05-20T18:38:18
*************************************************************$ */

