/* $*************** KCG Version 6.1.3 (build i6) ****************
** Command: s2c613 -config C:/GITHUB/modeling/model/Scade/System/TracksideDynamicModel/TestTracks/UtrechtAmsterdam_oETCS/TrackSim_imp_dll\kcg_s2c_config.txt
** Generation date: 2015-08-27T15:14:25
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "UAB_Write_P015_TM_trackside.h"

/* TM_trackside::Write_P015 */
void UAB_Write_P015_TM_trackside(
  /* TM_trackside::Write_P015::Packet15 */UAB_P015_trackside_int_T_TM *Packet15,
  /* TM_trackside::Write_P015::Packets */UAB_CompressedPackets_T_Common_Types_Pkg *Packets,
  /* TM_trackside::Write_P015::Error */kcg_bool *Error,
  /* TM_trackside::Write_P015::RadioPacketsOut */UAB_CompressedPackets_T_Common_Types_Pkg *RadioPacketsOut)
{
  /* TM_trackside::Write_P015::_L21 */
  static kcg_int _L21;
  /* TM_trackside::Write_P015::_L22 */
  static kcg_int _L22;
  /* TM_trackside::Write_P015::_L44 */
  static UAB_CompressedPacketData_T_Common_Types_Pkg _L44;
  /* TM_trackside::Write_P015::_L43 */
  static UAB_MetadataElement_T_Common_Types_Pkg _L43;
  
  *Error = kcg_false;
  /* 1 */ UAB_C_P015_tracksim_compr_TM_conversions(Packet15, &_L43, &_L44);
  /* 1 */
  UAB_SEND_WriteBaliseMessageHeader_TM_lib_internal(
    &(*Packets).PacketHeaders,
    &_L43,
    &(*RadioPacketsOut).PacketHeaders,
    &_L21,
    &_L22);
  /* 1 */
  UAB_SEND_MessageData_TM_lib_internal(
    _L21,
    _L22,
    &(*Packets).PacketData,
    &_L44,
    &(*RadioPacketsOut).PacketData);
}

/* $*************** KCG Version 6.1.3 (build i6) ****************
** UAB_Write_P015_TM_trackside.c
** Generation date: 2015-08-27T15:14:25
*************************************************************$ */

