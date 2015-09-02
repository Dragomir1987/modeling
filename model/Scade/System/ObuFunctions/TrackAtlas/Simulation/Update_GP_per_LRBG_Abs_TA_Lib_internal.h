/* $*************** KCG Version 6.1.3 (build i6) ****************
** Command: s2c613 -config C:/GITHUB/modeling/model/Scade/System/ObuFunctions/TrackAtlas/Simulation\kcg_s2c_config.txt
** Generation date: 2015-08-31T17:37:26
*************************************************************$ */
#ifndef _Update_GP_per_LRBG_Abs_TA_Lib_internal_H_
#define _Update_GP_per_LRBG_Abs_TA_Lib_internal_H_

#include "kcg_types.h"
#include "_1_FindStartOfNewGradientPro_TA_Lib_internal.h"
#include "Update_GP_per_LRBG_Abs_loop_TA_Lib_internal.h"

/* ========================  input structure  ====================== */
typedef struct {
  GradientProfile_t_TrackAtlasTypes /* TA_Lib_internal::Update_GP_per_LRBG_Abs::new_GP */ new_GP;
  GradientProfile_t_TrackAtlasTypes /* TA_Lib_internal::Update_GP_per_LRBG_Abs::Last_GradientProfile_in */ Last_GradientProfile_in;
} inC_Update_GP_per_LRBG_Abs_TA_Lib_internal;

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  GradientProfile_t_TrackAtlasTypes /* TA_Lib_internal::Update_GP_per_LRBG_Abs::GradientdProfile_out */ GradientdProfile_out;
  /* -----------------------  no local probes  ----------------------- */
  /* -----------------  no initialization variables  ----------------- */
  /* -----------------------  no local memory  ----------------------- */
  /* ---------------------  sub nodes' contexts  --------------------- */
  outC_Update_GP_per_LRBG_Abs_loop_TA_Lib_internal /* 1 */ _1_Context_1[33];
  outC__1_FindStartOfNewGradientPro_TA_Lib_internal /* 1 */ Context_1;
  /* ------------------ clocks of observable data -------------------- */
  kcg_bool tmp;
  /* -------------------- (-debug) no assertions  -------------------- */
  /* ------------------- (-debug) local variables -------------------- */
  kcg_int /* TA_Lib_internal::Update_GP_per_LRBG_Abs::_L1 */ _L1;
  GradientProfile_t_TrackAtlasTypes /* TA_Lib_internal::Update_GP_per_LRBG_Abs::_L5 */ _L5;
  array_int_33 /* TA_Lib_internal::Update_GP_per_LRBG_Abs::_L9 */ _L9;
  GradientProfile_t_TrackAtlasTypes /* TA_Lib_internal::Update_GP_per_LRBG_Abs::_L14 */ _L14;
  GradientProfile_t_TrackAtlasTypes /* TA_Lib_internal::Update_GP_per_LRBG_Abs::_L45 */ _L45;
  array__248 /* TA_Lib_internal::Update_GP_per_LRBG_Abs::_L47 */ _L47;
  kcg_bool /* TA_Lib_internal::Update_GP_per_LRBG_Abs::_L148 */ _L148;
} outC_Update_GP_per_LRBG_Abs_TA_Lib_internal;

/* ===========  node initialization and cycle functions  =========== */
/* TA_Lib_internal::Update_GP_per_LRBG_Abs */
extern void Update_GP_per_LRBG_Abs_TA_Lib_internal(
  inC_Update_GP_per_LRBG_Abs_TA_Lib_internal *inC,
  outC_Update_GP_per_LRBG_Abs_TA_Lib_internal *outC);

extern void Update_GP_per_LRBG_Abs_reset_TA_Lib_internal(
  outC_Update_GP_per_LRBG_Abs_TA_Lib_internal *outC);

#endif /* _Update_GP_per_LRBG_Abs_TA_Lib_internal_H_ */
/* $*************** KCG Version 6.1.3 (build i6) ****************
** Update_GP_per_LRBG_Abs_TA_Lib_internal.h
** Generation date: 2015-08-31T17:37:26
*************************************************************$ */

