/* $*************** KCG Version 6.1.3 (build i6) ****************
** Command: s2c613 -config C:/GITHUB/modeling/model/Scade/System/TestTrackAtlas/Simulation\kcg_s2c_config.txt
** Generation date: 2015-09-02T17:34:33
*************************************************************$ */
#ifndef _GP_Convert_P21_to_DistanceProfile_loop_TA_Gradient_H_
#define _GP_Convert_P21_to_DistanceProfile_loop_TA_Gradient_H_

#include "kcg_types.h"
#include "Normalize_Distance_d_internal_t_TA_Lib_internal.h"
#include "EVAL_Q_GDIR_TA_Lib_internal.h"

/* =====================  no input structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  GradientProfile_t_TrackAtlasTypes /* TA_Gradient::GP_Convert_P21_to_DistanceProfile_loop::GradientProfile */ GradientProfile;
  /* -----------------------  no local probes  ----------------------- */
  /* -----------------  no initialization variables  ----------------- */
  /* -----------------------  no local memory  ----------------------- */
  /* ---------------------  sub nodes' contexts  --------------------- */
  outC_Normalize_Distance_d_internal_t_TA_Lib_internal /* 4 */ Context_4;
  outC_EVAL_Q_GDIR_TA_Lib_internal /* 2 */ Context_2;
  outC_Normalize_Distance_d_internal_t_TA_Lib_internal /* 3 */ Context_3;
  /* ----------------- no clocks of observable data ------------------ */
  /* -------------------- (-debug) no assertions  -------------------- */
  /* ------------------- (-debug) local variables -------------------- */
  kcg_int /* TA_Gradient::GP_Convert_P21_to_DistanceProfile_loop::_L141 */ _L141;
  P021_section_enum_T_TM /* TA_Gradient::GP_Convert_P21_to_DistanceProfile_loop::_L140 */ _L140;
  Q_SCALE /* TA_Gradient::GP_Convert_P21_to_DistanceProfile_loop::_L139 */ _L139;
  D_GRADIENT /* TA_Gradient::GP_Convert_P21_to_DistanceProfile_loop::_L138 */ _L138;
  D_GRADIENT /* TA_Gradient::GP_Convert_P21_to_DistanceProfile_loop::_L137 */ _L137;
  Gradient_section_t_TrackAtlasTypes /* TA_Gradient::GP_Convert_P21_to_DistanceProfile_loop::_L136 */ _L136;
  L_internal_Type_Obu_BasicTypes_Pkg /* TA_Gradient::GP_Convert_P21_to_DistanceProfile_loop::_L135 */ _L135;
  kcg_int /* TA_Gradient::GP_Convert_P21_to_DistanceProfile_loop::_L134 */ _L134;
  GradientProfile_t_TrackAtlasTypes /* TA_Gradient::GP_Convert_P21_to_DistanceProfile_loop::_L133 */ _L133;
  kcg_int /* TA_Gradient::GP_Convert_P21_to_DistanceProfile_loop::_L131 */ _L131;
  kcg_bool /* TA_Gradient::GP_Convert_P21_to_DistanceProfile_loop::_L130 */ _L130;
  Q_GDIR /* TA_Gradient::GP_Convert_P21_to_DistanceProfile_loop::_L129 */ _L129;
  P021_OBU_sectionlist_enum_T_TM /* TA_Gradient::GP_Convert_P21_to_DistanceProfile_loop::_L128 */ _L128;
  G_internal_Type_Obu_BasicTypes_Pkg /* TA_Gradient::GP_Convert_P21_to_DistanceProfile_loop::_L127 */ _L127;
  kcg_int /* TA_Gradient::GP_Convert_P21_to_DistanceProfile_loop::_L126 */ _L126;
  GradientProfile_t_TrackAtlasTypes /* TA_Gradient::GP_Convert_P21_to_DistanceProfile_loop::_L125 */ _L125;
  G_A /* TA_Gradient::GP_Convert_P21_to_DistanceProfile_loop::_L124 */ _L124;
  P021_section_enum_T_TM /* TA_Gradient::GP_Convert_P21_to_DistanceProfile_loop::_L123 */ _L123;
  L_internal_Type_Obu_BasicTypes_Pkg /* TA_Gradient::GP_Convert_P21_to_DistanceProfile_loop::_L122 */ _L122;
  P021_OBU_sectionlist_enum_T_TM /* TA_Gradient::GP_Convert_P21_to_DistanceProfile_loop::_L121 */ _L121;
  GradientProfile_t_TrackAtlasTypes /* TA_Gradient::GP_Convert_P21_to_DistanceProfile_loop::_L142 */ _L142;
  Gradient_section_t_TrackAtlasTypes /* TA_Gradient::GP_Convert_P21_to_DistanceProfile_loop::_L143 */ _L143;
  kcg_int /* TA_Gradient::GP_Convert_P21_to_DistanceProfile_loop::_L144 */ _L144;
  kcg_int /* TA_Gradient::GP_Convert_P21_to_DistanceProfile_loop::_L145 */ _L145;
  kcg_int /* TA_Gradient::GP_Convert_P21_to_DistanceProfile_loop::_L146 */ _L146;
  L_internal_Type_Obu_BasicTypes_Pkg /* TA_Gradient::GP_Convert_P21_to_DistanceProfile_loop::_L147 */ _L147;
  L_internal_Type_Obu_BasicTypes_Pkg /* TA_Gradient::GP_Convert_P21_to_DistanceProfile_loop::_L148 */ _L148;
  kcg_int /* TA_Gradient::GP_Convert_P21_to_DistanceProfile_loop::_L149 */ _L149;
  kcg_int /* TA_Gradient::GP_Convert_P21_to_DistanceProfile_loop::_L150 */ _L150;
  kcg_int /* TA_Gradient::GP_Convert_P21_to_DistanceProfile_loop::_L151 */ _L151;
  kcg_int /* TA_Gradient::GP_Convert_P21_to_DistanceProfile_loop::_L152 */ _L152;
  kcg_int /* TA_Gradient::GP_Convert_P21_to_DistanceProfile_loop::_L153 */ _L153;
} outC_GP_Convert_P21_to_DistanceProfile_loop_TA_Gradient;

/* ===========  node initialization and cycle functions  =========== */
/* TA_Gradient::GP_Convert_P21_to_DistanceProfile_loop */
extern void GP_Convert_P21_to_DistanceProfile_loop_TA_Gradient(
  /* TA_Gradient::GP_Convert_P21_to_DistanceProfile_loop::i */kcg_int i,
  /* TA_Gradient::GP_Convert_P21_to_DistanceProfile_loop::ProfileAccu */GradientProfile_t_TrackAtlasTypes *ProfileAccu,
  /* TA_Gradient::GP_Convert_P21_to_DistanceProfile_loop::SectionIn */P021_OBU_sectionlist_enum_T_TM *SectionIn,
  /* TA_Gradient::GP_Convert_P21_to_DistanceProfile_loop::q_scale */Q_SCALE q_scale,
  outC_GP_Convert_P21_to_DistanceProfile_loop_TA_Gradient *outC);

extern void GP_Convert_P21_to_DistanceProfile_loop_reset_TA_Gradient(
  outC_GP_Convert_P21_to_DistanceProfile_loop_TA_Gradient *outC);

#endif /* _GP_Convert_P21_to_DistanceProfile_loop_TA_Gradient_H_ */
/* $*************** KCG Version 6.1.3 (build i6) ****************
** GP_Convert_P21_to_DistanceProfile_loop_TA_Gradient.h
** Generation date: 2015-09-02T17:34:33
*************************************************************$ */

