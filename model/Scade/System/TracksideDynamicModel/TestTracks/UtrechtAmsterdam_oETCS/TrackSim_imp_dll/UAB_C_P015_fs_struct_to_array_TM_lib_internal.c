/* $*************** KCG Version 6.1.3 (build i6) ****************
** Command: s2c613 -config C:/GITHUB/modeling/model/Scade/System/TracksideDynamicModel/TestTracks/UtrechtAmsterdam_oETCS/TrackSim_imp_dll\kcg_s2c_config.txt
** Generation date: 2015-08-27T15:14:25
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "UAB_C_P015_fs_struct_to_array_TM_lib_internal.h"

/* TM_lib_internal::C_P015_fs_struct_to_array */
void UAB_C_P015_fs_struct_to_array_TM_lib_internal(
  /* TM_lib_internal::C_P015_fs_struct_to_array::section */UAB_P015_section_int_T_TM *section,
  /* TM_lib_internal::C_P015_fs_struct_to_array::section_arrays */UAB_P015_section_array_T_TM *section_arrays)
{
  (*section_arrays)[0] = (*section).L_SECTION;
  (*section_arrays)[1] = (*section).Q_SECTIONTIMER;
  (*section_arrays)[2] = (*section).T_SECTIONTIMER;
  (*section_arrays)[3] = (*section).D_SECTIONTIMERSTOPLOC;
}

/* $*************** KCG Version 6.1.3 (build i6) ****************
** UAB_C_P015_fs_struct_to_array_TM_lib_internal.c
** Generation date: 2015-08-27T15:14:25
*************************************************************$ */

