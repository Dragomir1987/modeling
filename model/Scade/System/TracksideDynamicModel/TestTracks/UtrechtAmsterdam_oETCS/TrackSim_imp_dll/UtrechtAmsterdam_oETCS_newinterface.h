#ifndef UAB_TESTP015_INTERNAL_TESTS_INTERFACE
#define UAB_TESTP015_INTERNAL_TESTS_INTERFACE


#include "NewSmuTypes.h"
#include "kcg_types.h"
#include "UAB_TestP015_Internal_Tests.h"

extern SimSimulator * pSimulator;

/*******************************
 * Validity
 *******************************/
extern int valid(void*);
extern int notvalid(void*);

#ifdef EXTENDED_SIM
void BeforeSimInit();
void AfterSimInit();
void BeforeSimStep();
void AfterSimStep();
void ExtendedSimStop();
void ExtendedGatherDumpData(char * pData);
void ExtendedRestoreDumpData(const char * pData);
int ExtendedGetDumpSize();
void UpdateValues();
extern void UpdateSimulatorValues();
extern int GraphicalInputsConnected;
#endif /* EXTENDED_SIM */

#define SIM_INFO    1
#define SIM_WARNING 2
#define SIM_ERROR   3
extern void SsmOutputMessage(int level, const char* str);

#endif /*UAB_TESTP015_INTERNAL_TESTS_INTERFACE */
