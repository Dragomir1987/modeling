#include <stdlib.h>
#include <stddef.h>
#include "NewSmuTypes.h"
#include "kcg_types.h"
#include "TrackAtlas_newtype.h"
#include "kcg_conv.h"

char* strDefaultRealFormat="%.5g"; /* (from .etp) */

#define skip_whitespace(str) while(*str == ' ' || *str == '\t') str++

/****************************************************************
 ** utility functions 
 ****************************************************************/

static int string_to_VTable(const char *str, const struct SimTypeVTable *pVTable, void *pValue, char **endptr)
{
    int nRet;
    if (pVTable != NULL && pVTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
        nRet = pVTable->m_pfnFromType(SptString, (const void*)&str, pValue);
        if (nRet != 0) {
            *endptr = (char*)str+strlen(str);
        }
        return nRet;
    };
    return 0;
}

static int is_VTable_double_conversion_allowed(const struct SimTypeVTable *pVTable)
{
    if (pVTable != NULL) {
        int nConversionAllowed = 0;
        nConversionAllowed |= pVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1;
        nConversionAllowed |= pVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1;
        nConversionAllowed |= pVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1;
        nConversionAllowed |= pVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1;
        return nConversionAllowed;
    }
    return 1;
}

int VTable_to_double(const void *pValue, const struct SimTypeVTable *pVTable, double *nRetValue)
{
    if (pVTable != NULL) {
        if (pVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1)
            *nRetValue = (*(double*)pVTable->m_pfnToType(SptDouble, pValue));
        else if (pVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1)
            *nRetValue = (double)(*(float*)pVTable->m_pfnToType(SptFloat, pValue));
        else if (pVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1)
            *nRetValue = (double)(*(long*)pVTable->m_pfnToType(SptLong, pValue));
        else if (pVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1)
            *nRetValue = (double)(*(int*)pVTable->m_pfnToType(SptShort, pValue));
        else
            return 0;
    }
    return 1;
}

static int is_VTable_long_convertion_allowed(const struct SimTypeVTable *pVTable)
{
    if (pVTable != NULL) {
        int nConvertionAllowed = 0;
        nConvertionAllowed |= pVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1;
        nConvertionAllowed |= pVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1;
        return nConvertionAllowed;
    }
    return 1;
}

int VTable_to_long(const void *pValue, const struct SimTypeVTable *pVTable, long *nRetValue)
{
    if (pVTable != NULL) {
        if (pVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1)
            *nRetValue = (*(long*)pVTable->m_pfnToType(SptLong, pValue));
        else if (pVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1)
            *nRetValue = (long)(*(int*)pVTable->m_pfnToType(SptShort, pValue));
        else
            return 0;
    }
    return 1;
}

static int get_enum_signature(const SimEnumValUtils *pEnumVals, int nSize, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    int i;
    pfnStrAppend("E", pData);
    for(i=0; i<nSize; i++) {
        pfnStrAppend("|", pData);
        pfnStrAppend(pEnumVals[i].m_name, pData);
    }
    return 1;
}

static int get_structure_signature(const SimFieldUtils *pFields, int nSize, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    int i;
    pfnStrAppend("(", pData);
    for(i=0; i<nSize; i++) {
        if (i > 0)
            pfnStrAppend(",", pData);
        pFields[i].m_pTypeUtils->m_pfnGetSignature(pfnStrAppend, pData);
    }
    pfnStrAppend(")", pData);
    return 1;
}

/****************************************************************
 ** kcg_real 
 ****************************************************************/

struct SimTypeVTable *pSimDoubleVTable;

int kcg_real_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimDoubleVTable != NULL
        && pSimDoubleVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
        if (pSimDoubleVTable->m_version >= Scv65) {
            /* R15 and higher: pass kcg_<type> variable to VTable function: */
            return pfnStrAppend(*(char**)pSimDoubleVTable->m_pfnToType(SptString, pValue), pData);
        } else {
            /* Before R15: pass a standard C typed variable to VTable function: */
            double value = (double)(*(const kcg_real*)pValue);
            return pfnStrAppend(*(char**)pSimDoubleVTable->m_pfnToType(SptString, &value), pData);
        }
    }
    return predef_kcg_real_to_string(*((kcg_real*)pValue), pConverter->m_RealFormat, pfnStrAppend, pData);
}

int string_to_kcg_real(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    static double rTemp;
    skip_whitespace(str);
    if (pSimDoubleVTable != NULL) {
        if (pSimDoubleVTable->m_version >= Scv65) {
            /* R15 and higher: VTable function must return a kcg_<type> *variable: */
            nRet=string_to_VTable(str, pSimDoubleVTable, pValue, endptr);
        } else {
            /* Before R15: pass a standard C typed variable to VTable function: */
            nRet=string_to_VTable(str, pSimDoubleVTable, &rTemp, endptr);
            if (nRet!=0) {
                *(kcg_real*)pValue = (kcg_real)rTemp;
            }
        }
    }
    if (nRet==0) {
        nRet = predef_string_to_kcg_real(str, (kcg_real*)pValue, endptr);
    }
    return nRet;
}

int is_kcg_real_double_conversion_allowed()
{
    if (pSimDoubleVTable != NULL) {
        return is_VTable_double_conversion_allowed(pSimDoubleVTable);
    }
    return 1;
}

int is_kcg_real_long_convertion_allowed()
{
    if (pSimDoubleVTable != NULL) {
        return is_VTable_long_convertion_allowed(pSimDoubleVTable);
    }
    return 1;
}

void compare_kcg_real(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    if (pSimDoubleVTable != NULL && pData!=NULL
        && pSimDoubleVTable->m_version >= Scv65
        && pSimDoubleVTable->m_pfnCompareWithTol != NULL ) {
        /* Customized comparison with tolerance (R15 and higher): */
        unitResult = pSimDoubleVTable->m_pfnCompareWithTol(pResult, pValue1, pValue2, pData);
    } else if (pSimDoubleVTable != NULL && pData==NULL
               && pSimDoubleVTable->m_version >= Scv612
               && pSimDoubleVTable->m_pfnCompare != NULL) {
        /* Customized comparison without tolerance: */
        if (pSimDoubleVTable->m_version >= Scv65) {
            /* R15 and higher: pass kcg_<type> * to VTable function: */
            unitResult = pSimDoubleVTable->m_pfnCompare(pResult, pValue1, pValue2);
         } else {
             /* Before R15: VTable function returns a standard C typed *variable: */
             double value1 = (double)(*(const kcg_real*)pValue1);
             double value2 = (double)(*(const kcg_real*)pValue2);
             pSimDoubleVTable->m_pfnCompare(&unitResult, &value1, &value2);
             updateCompareResult(unitResult, pResult);
         }
    } else {
        /* Predefined comparison (with/without tolerance): */
        unitResult = predef_compare_kcg_real(pResult, *((kcg_real*)pValue1), *((kcg_real*)pValue2), pData);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int kcg_real_to_double(const void *pValue, double *nRetValue)
{
    if (pSimDoubleVTable != NULL) {
        if (pSimDoubleVTable->m_version >= Scv65) {
            /* R15 and higher: pass kcg_<type> * to VTable function: */
            return VTable_to_double(pValue, pSimDoubleVTable, nRetValue);
        } else {
            /* Before R15: pass a standard C typed variable to VTable function: */
            double value = (double)(*(const kcg_real*)pValue);
            return VTable_to_double(&value, pSimDoubleVTable, nRetValue);
        }
    }
    *nRetValue = (double)*((kcg_real*)pValue);
    return 1;
}

int kcg_real_to_long(const void *pValue, long *nRetValue)
{
    if (pSimDoubleVTable != NULL) {
        if (pSimDoubleVTable->m_version >= Scv65) {
            /* R15 and higher: pass kcg_<type> * to VTable function: */
            return VTable_to_long(pValue, pSimDoubleVTable, nRetValue);
        } else {
            /* Before R15: pass a standard C typed variable to VTable function: */
            double value = (double)(*(const kcg_real*)pValue);
            return VTable_to_long(&value, pSimDoubleVTable, nRetValue);
        }
    }
    *nRetValue = (long)*((kcg_real*)pValue);
    return 1;
}

int get_kcg_real_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    return pfnStrAppend("R", pData);
}

int set_kcg_real_default_value(void *pValue)
{
    *(kcg_real*)pValue = 0.0;
    return 1;
}

int check_kcg_real_string(const char *str, char **endptr)
{
    static kcg_real rTemp;
    return string_to_kcg_real(str, &rTemp, endptr);
}

SimTypeUtils _Type_kcg_real_Utils = {
    kcg_real_to_string,
    check_kcg_real_string,
    string_to_kcg_real,
    is_kcg_real_double_conversion_allowed,
    kcg_real_to_double,
    is_kcg_real_long_convertion_allowed,
    kcg_real_to_long,
    compare_kcg_real,
    get_kcg_real_signature,
    set_kcg_real_default_value,
    sizeof(kcg_real)
};

/****************************************************************
 ** kcg_bool 
 ****************************************************************/

struct SimTypeVTable *pSimBoolVTable;

int kcg_bool_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimBoolVTable != NULL
        && pSimBoolVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
        if (pSimBoolVTable->m_version >= Scv65) {
            /* R15 and higher: pass kcg_<type> variable to VTable function: */
            return pfnStrAppend(*(char**)pSimBoolVTable->m_pfnToType(SptString, pValue), pData);
        } else {
            /* Before R15: pass a standard C typed variable to VTable function: */
            SimBool value = (*((const kcg_bool*)pValue) == kcg_true)? SbTrue : SbFalse;
            return pfnStrAppend(*(char**)pSimBoolVTable->m_pfnToType(SptString, &value), pData);
        }
    }
    return predef_kcg_bool_to_string(*((kcg_bool*)pValue), pfnStrAppend, pData);
}

int string_to_kcg_bool(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    static SimBool rTemp;
    skip_whitespace(str);
    if (pSimBoolVTable != NULL) {
        if (pSimBoolVTable->m_version >= Scv65) {
            /* R15 and higher: VTable function must return a kcg_<type> *variable: */
            nRet=string_to_VTable(str, pSimBoolVTable, pValue, endptr);
        } else {
            /* Before R15: pass a standard C typed variable to VTable function: */
            nRet=string_to_VTable(str, pSimBoolVTable, &rTemp, endptr);
            if (nRet!=0) {
                *(kcg_bool*)pValue = (rTemp == SbTrue)? kcg_true : kcg_false;
            }
        }
    }
    if (nRet==0) {
        nRet = predef_string_to_kcg_bool(str, (kcg_bool*)pValue, endptr);
    }
    return nRet;
}

int is_kcg_bool_double_conversion_allowed()
{
    if (pSimBoolVTable != NULL) {
        return is_VTable_double_conversion_allowed(pSimBoolVTable);
    }
    return 1;
}

int is_kcg_bool_long_convertion_allowed()
{
    if (pSimBoolVTable != NULL) {
        return is_VTable_long_convertion_allowed(pSimBoolVTable);
    }
    return 1;
}

void compare_kcg_bool(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimBoolVTable != NULL
        && pSimBoolVTable->m_version >= Scv612
        && pSimBoolVTable->m_pfnCompare != NULL) {
        if (pSimBoolVTable->m_version >= Scv65) {
            /* R15 and higher: pass kcg_<type> * to VTable function: */
            unitResult = pSimBoolVTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /* Before R15: pass a standard C typed variable to VTable function: */
            SimBool value1 = (*((const kcg_bool*)pValue1) == kcg_true)? SbTrue : SbFalse;
            SimBool value2 = (*((const kcg_bool*)pValue2) == kcg_true)? SbTrue : SbFalse;
            pSimBoolVTable->m_pfnCompare(&unitResult, &value1, &value2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        unitResult = predef_compare_kcg_bool(pResult, *((kcg_bool*)pValue1), *((kcg_bool*)pValue2), pData);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int kcg_bool_to_double(const void *pValue, double *nRetValue)
{
    if (pSimBoolVTable != NULL) {
        if (pSimBoolVTable->m_version >= Scv65) {
            /* R15 and higher: pass kcg_<type> * to VTable function: */
            return VTable_to_double(pValue, pSimBoolVTable, nRetValue);
        } else {
            /* Before R15: pass a standard C typed variable to VTable function: */
            SimBool value = (*((const kcg_bool*)pValue) == kcg_true)? SbTrue : SbFalse;
            return VTable_to_double(&value, pSimBoolVTable, nRetValue);
        }
    }
    *nRetValue = *((kcg_bool*)pValue) == kcg_true ? 1.0 : 0.0;
    return 1;
}

int kcg_bool_to_long(const void *pValue, long *nRetValue)
{
    if (pSimBoolVTable != NULL) {
        if (pSimBoolVTable->m_version >= Scv65) {
            /* R15 and higher: pass kcg_<type> * to VTable function: */
            return VTable_to_long(pValue, pSimBoolVTable, nRetValue);
        } else {
            /* Before R15: pass a standard C typed variable to VTable function: */
            SimBool value = (*((const kcg_bool*)pValue) == kcg_true)? SbTrue : SbFalse;
            return VTable_to_long(&value, pSimBoolVTable, nRetValue);
        }
    }
    *nRetValue = *((kcg_bool*)pValue) == kcg_true ? 1 : 0;
    return 1;
}

int get_kcg_bool_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    return pfnStrAppend("B", pData);
}

int set_kcg_bool_default_value(void *pValue)
{
    *(kcg_bool*)pValue = kcg_false;
    return 1;
}

int check_kcg_bool_string(const char *str, char **endptr)
{
    static kcg_bool rTemp;
    return string_to_kcg_bool(str, &rTemp, endptr);
}

SimTypeUtils _Type_kcg_bool_Utils = {
    kcg_bool_to_string,
    check_kcg_bool_string,
    string_to_kcg_bool,
    is_kcg_bool_double_conversion_allowed,
    kcg_bool_to_double,
    is_kcg_bool_long_convertion_allowed,
    kcg_bool_to_long,
    compare_kcg_bool,
    get_kcg_bool_signature,
    set_kcg_bool_default_value,
    sizeof(kcg_bool)
};

/****************************************************************
 ** kcg_char 
 ****************************************************************/

struct SimTypeVTable *pSimCharVTable;

int kcg_char_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimCharVTable != NULL
        && pSimCharVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
        if (pSimCharVTable->m_version >= Scv65) {
            /* R15 and higher: pass kcg_<type> variable to VTable function: */
            return pfnStrAppend(*(char**)pSimCharVTable->m_pfnToType(SptString, pValue), pData);
        } else {
            /* Before R15: pass a standard C typed variable to VTable function: */
            char value = (char)(*(const kcg_char*)pValue);
            return pfnStrAppend(*(char**)pSimCharVTable->m_pfnToType(SptString, &value), pData);
        }
    }
    return predef_kcg_char_to_string(*((kcg_char*)pValue), pfnStrAppend, pData);
}

int string_to_kcg_char(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    static char rTemp;
    skip_whitespace(str);
    if (pSimCharVTable != NULL) {
        if (pSimCharVTable->m_version >= Scv65) {
            /* R15 and higher: VTable function must return a kcg_<type> *variable: */
            nRet=string_to_VTable(str, pSimCharVTable, pValue, endptr);
        } else {
            /* Before R15: pass a standard C typed variable to VTable function: */
            nRet=string_to_VTable(str, pSimCharVTable, &rTemp, endptr);
            if (nRet!=0) {
                *(kcg_char*)pValue = (kcg_char)rTemp;
            }
        }
    }
    if (nRet==0) {
        nRet = predef_string_to_kcg_char(str, (kcg_char*)pValue, endptr);
    }
    return nRet;
}

int is_kcg_char_double_conversion_allowed()
{
    if (pSimCharVTable != NULL) {
        return is_VTable_double_conversion_allowed(pSimCharVTable);
    }
    return 1;
}

int is_kcg_char_long_convertion_allowed()
{
    if (pSimCharVTable != NULL) {
        return is_VTable_long_convertion_allowed(pSimCharVTable);
    }
    return 1;
}

void compare_kcg_char(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimCharVTable != NULL
        && pSimCharVTable->m_version >= Scv612
        && pSimCharVTable->m_pfnCompare != NULL) {
        if (pSimCharVTable->m_version >= Scv65) {
            /* R15 and higher: pass kcg_<type> * to VTable function: */
            unitResult = pSimCharVTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /* Before R15: pass a standard C typed variable to VTable function: */
            char value1 = (char)(*(const kcg_char*)pValue1);
            char value2 = (char)(*(const kcg_char*)pValue2);
            pSimCharVTable->m_pfnCompare(&unitResult, &value1, &value2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        unitResult = predef_compare_kcg_char(pResult, *((kcg_char*)pValue1), *((kcg_char*)pValue2), pData);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int kcg_char_to_double(const void *pValue, double *nRetValue)
{
    if (pSimCharVTable != NULL) {
        if (pSimCharVTable->m_version >= Scv65) {
            /* R15 and higher: pass kcg_<type> * to VTable function: */
            return VTable_to_double(pValue, pSimCharVTable, nRetValue);
        } else {
            /* Before R15: pass a standard C typed variable to VTable function: */
            char value = (char)(*(const kcg_char*)pValue);
            return VTable_to_double(&value, pSimCharVTable, nRetValue);
        }
    }
    *nRetValue = (double)*((kcg_char*)pValue);
    return 1;
}

int kcg_char_to_long(const void *pValue, long *nRetValue)
{
    if (pSimCharVTable != NULL) {
        if (pSimCharVTable->m_version >= Scv65) {
            /* R15 and higher: pass kcg_<type> * to VTable function: */
            return VTable_to_long(pValue, pSimCharVTable, nRetValue);
        } else {
            /* Before R15: pass a standard C typed variable to VTable function: */
            char value = (char)(*(const kcg_char*)pValue);
            return VTable_to_long(&value, pSimCharVTable, nRetValue);
        }
    }
    *nRetValue = (long)*((kcg_char*)pValue);
    return 1;
}

int get_kcg_char_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    return pfnStrAppend("C", pData);
}

int set_kcg_char_default_value(void *pValue)
{
    *(kcg_char*)pValue = 0;
    return 1;
}

int check_kcg_char_string(const char *str, char **endptr)
{
    static kcg_char rTemp;
    return string_to_kcg_char(str, &rTemp, endptr);
}

SimTypeUtils _Type_kcg_char_Utils = {
    kcg_char_to_string,
    check_kcg_char_string,
    string_to_kcg_char,
    is_kcg_char_double_conversion_allowed,
    kcg_char_to_double,
    is_kcg_char_long_convertion_allowed,
    kcg_char_to_long,
    compare_kcg_char,
    get_kcg_char_signature,
    set_kcg_char_default_value,
    sizeof(kcg_char)
};

/****************************************************************
 ** kcg_int 
 ****************************************************************/

struct SimTypeVTable *pSimLongVTable;

int kcg_int_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimLongVTable != NULL
        && pSimLongVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
        if (pSimLongVTable->m_version >= Scv65) {
            /* R15 and higher: pass kcg_<type> variable to VTable function: */
            return pfnStrAppend(*(char**)pSimLongVTable->m_pfnToType(SptString, pValue), pData);
        } else {
            /* Before R15: pass a standard C typed variable to VTable function: */
            long value = (long)(*(const kcg_int*)pValue);
            return pfnStrAppend(*(char**)pSimLongVTable->m_pfnToType(SptString, &value), pData);
        }
    }
    return predef_kcg_int_to_string(*((kcg_int*)pValue), pfnStrAppend, pData);
}

int string_to_kcg_int(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    static long rTemp;
    skip_whitespace(str);
    if (pSimLongVTable != NULL) {
        if (pSimLongVTable->m_version >= Scv65) {
            /* R15 and higher: VTable function must return a kcg_<type> *variable: */
            nRet=string_to_VTable(str, pSimLongVTable, pValue, endptr);
        } else {
            /* Before R15: pass a standard C typed variable to VTable function: */
            nRet=string_to_VTable(str, pSimLongVTable, &rTemp, endptr);
            if (nRet!=0) {
                *(kcg_int*)pValue = (kcg_int)rTemp;
            }
        }
    }
    if (nRet==0) {
        nRet = predef_string_to_kcg_int(str, (kcg_int*)pValue, endptr);
    }
    return nRet;
}

int is_kcg_int_double_conversion_allowed()
{
    if (pSimLongVTable != NULL) {
        return is_VTable_double_conversion_allowed(pSimLongVTable);
    }
    return 1;
}

int is_kcg_int_long_convertion_allowed()
{
    if (pSimLongVTable != NULL) {
        return is_VTable_long_convertion_allowed(pSimLongVTable);
    }
    return 1;
}

void compare_kcg_int(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimLongVTable != NULL
        && pSimLongVTable->m_version >= Scv612
        && pSimLongVTable->m_pfnCompare != NULL) {
        if (pSimLongVTable->m_version >= Scv65) {
            /* R15 and higher: pass kcg_<type> * to VTable function: */
            unitResult = pSimLongVTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /* Before R15: pass a standard C typed variable to VTable function: */
            long value1 = (long)(*(const kcg_int*)pValue1);
            long value2 = (long)(*(const kcg_int*)pValue2);
            pSimLongVTable->m_pfnCompare(&unitResult, &value1, &value2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        unitResult = predef_compare_kcg_int(pResult, *((kcg_int*)pValue1), *((kcg_int*)pValue2), pData);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int kcg_int_to_double(const void *pValue, double *nRetValue)
{
    if (pSimLongVTable != NULL) {
        if (pSimLongVTable->m_version >= Scv65) {
            /* R15 and higher: pass kcg_<type> * to VTable function: */
            return VTable_to_double(pValue, pSimLongVTable, nRetValue);
        } else {
            /* Before R15: pass a standard C typed variable to VTable function: */
            long value = (long)(*(const kcg_int*)pValue);
            return VTable_to_double(&value, pSimLongVTable, nRetValue);
        }
    }
    *nRetValue = (double)*((kcg_int*)pValue);
    return 1;
}

int kcg_int_to_long(const void *pValue, long *nRetValue)
{
    if (pSimLongVTable != NULL) {
        if (pSimLongVTable->m_version >= Scv65) {
            /* R15 and higher: pass kcg_<type> * to VTable function: */
            return VTable_to_long(pValue, pSimLongVTable, nRetValue);
        } else {
            /* Before R15: pass a standard C typed variable to VTable function: */
            long value = (long)(*(const kcg_int*)pValue);
            return VTable_to_long(&value, pSimLongVTable, nRetValue);
        }
    }
    *nRetValue = (long)*((kcg_int*)pValue);
    return 1;
}

int get_kcg_int_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    return pfnStrAppend("I", pData);
}

int set_kcg_int_default_value(void *pValue)
{
    *(kcg_int*)pValue = 0;
    return 1;
}

int check_kcg_int_string(const char *str, char **endptr)
{
    static kcg_int rTemp;
    return string_to_kcg_int(str, &rTemp, endptr);
}

SimTypeUtils _Type_kcg_int_Utils = {
    kcg_int_to_string,
    check_kcg_int_string,
    string_to_kcg_int,
    is_kcg_int_double_conversion_allowed,
    kcg_int_to_double,
    is_kcg_int_long_convertion_allowed,
    kcg_int_to_long,
    compare_kcg_int,
    get_kcg_int_signature,
    set_kcg_int_default_value,
    sizeof(kcg_int)
};

/****************************************************************
 ** struct__129 
 ****************************************************************/

struct SimTypeVTable *pSimstruct__129VTable;

static SimFieldUtils struct__129_fields[] = {
    {"valid", offsetof(struct__129,valid), &_Type_kcg_bool_Utils},
    {"Loc_Abs", offsetof(struct__129,Loc_Abs), &_Type_kcg_int_Utils},
    {"Loc_LRBG", offsetof(struct__129,Loc_LRBG), &_Type_kcg_int_Utils},
    {"MRS", offsetof(struct__129,MRS), &_Type_kcg_int_Utils},
};

int struct__129_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimstruct__129VTable != NULL
        && pSimstruct__129VTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimstruct__129VTable->m_pfnToType(SptString, pValue), pData);
    }
    return pConverter->m_pfnStructureToString(pValue, struct__129_fields, 4, pfnStrAppend, pData);
}

int string_to_struct__129(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimstruct__129VTable != NULL) {
        nRet=string_to_VTable(str, pSimstruct__129VTable, pValue, endptr);
    }
    if (nRet==0) {
        nRet=pConverter->m_pfnStringToStructure(str, pValue, struct__129_fields, 4, endptr);
    }
    return nRet;
}

int is_struct__129_double_conversion_allowed()
{
    if (pSimstruct__129VTable != NULL) {
        return is_VTable_double_conversion_allowed(pSimstruct__129VTable);
    }
    return 0;
}

int is_struct__129_long_convertion_allowed()
{
    if (pSimstruct__129VTable != NULL) {
        return is_VTable_long_convertion_allowed(pSimstruct__129VTable);
    }
    return 0;
}

void compare_struct__129(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimstruct__129VTable != NULL
        && pSimstruct__129VTable->m_version >= Scv612
        && pSimstruct__129VTable->m_pfnCompare != NULL) {
        if (pSimstruct__129VTable->m_version >= Scv65) {
            /* R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimstruct__129VTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /* Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimstruct__129VTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        pConverter->m_pfnStructureComparison(pResult, pValue1, pValue2, struct__129_fields, 4, pData, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int struct__129_to_double(const void *pValue, double *nRetValue)
{
    if (pSimstruct__129VTable != NULL) {
        return VTable_to_double(pValue, pSimstruct__129VTable, nRetValue);
    }
    return 0;
}

int struct__129_to_long(const void *pValue, long *nRetValue)
{
    if (pSimstruct__129VTable != NULL) {
        return VTable_to_long(pValue, pSimstruct__129VTable, nRetValue);
    }
    return 0;
}

int get_struct__129_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    return get_structure_signature(struct__129_fields, 4, pfnStrAppend, pData);
}

int set_struct__129_default_value(void *pValue)
{
    set_kcg_bool_default_value(&(((struct__129*)pValue)->valid));
    set_kcg_int_default_value(&(((struct__129*)pValue)->Loc_Abs));
    set_kcg_int_default_value(&(((struct__129*)pValue)->Loc_LRBG));
    set_kcg_int_default_value(&(((struct__129*)pValue)->MRS));
    return 1;
}

int check_struct__129_string(const char *str, char **endptr)
{
    static struct__129 rTemp;
    return string_to_struct__129(str, &rTemp, endptr);
}

SimTypeUtils _Type_struct__129_Utils = {
    struct__129_to_string,
    check_struct__129_string,
    string_to_struct__129,
    is_struct__129_double_conversion_allowed,
    struct__129_to_double,
    is_struct__129_long_convertion_allowed,
    struct__129_to_long,
    compare_struct__129,
    get_struct__129_signature,
    set_struct__129_default_value,
    sizeof(struct__129)
};

/****************************************************************
 ** MRSP_section_t_TrackAtlasTypes 
 ****************************************************************/

struct SimTypeVTable *pSimMRSP_section_t_TrackAtlasTypesVTable;

int MRSP_section_t_TrackAtlasTypes_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimMRSP_section_t_TrackAtlasTypesVTable != NULL
        && pSimMRSP_section_t_TrackAtlasTypesVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimMRSP_section_t_TrackAtlasTypesVTable->m_pfnToType(SptString, pValue), pData);
    }
    return struct__129_to_string(pValue, pfnStrAppend, pData);
}

int string_to_MRSP_section_t_TrackAtlasTypes(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimMRSP_section_t_TrackAtlasTypesVTable != NULL) {
        nRet=string_to_VTable(str, pSimMRSP_section_t_TrackAtlasTypesVTable, pValue, endptr);
    }
    if (nRet==0) {
        nRet = string_to_struct__129(str, pValue, endptr);
    }
    return nRet;
}

int is_MRSP_section_t_TrackAtlasTypes_double_conversion_allowed()
{
    if (pSimMRSP_section_t_TrackAtlasTypesVTable != NULL) {
        return is_VTable_double_conversion_allowed(pSimMRSP_section_t_TrackAtlasTypesVTable);
    }
    return is_struct__129_double_conversion_allowed();
}

int is_MRSP_section_t_TrackAtlasTypes_long_convertion_allowed()
{
    if (pSimMRSP_section_t_TrackAtlasTypesVTable != NULL) {
        return is_VTable_long_convertion_allowed(pSimMRSP_section_t_TrackAtlasTypesVTable);
    }
    return is_struct__129_long_convertion_allowed();
}

void compare_MRSP_section_t_TrackAtlasTypes(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimMRSP_section_t_TrackAtlasTypesVTable != NULL
        && pSimMRSP_section_t_TrackAtlasTypesVTable->m_version >= Scv612
        && pSimMRSP_section_t_TrackAtlasTypesVTable->m_pfnCompare != NULL) {
        if (pSimMRSP_section_t_TrackAtlasTypesVTable->m_version >= Scv65) {
            /* R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimMRSP_section_t_TrackAtlasTypesVTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /* Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimMRSP_section_t_TrackAtlasTypesVTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        compare_struct__129(pResult, pValue1, pValue2, pData, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int MRSP_section_t_TrackAtlasTypes_to_double(const void *pValue, double *nRetValue)
{
    if (pSimMRSP_section_t_TrackAtlasTypesVTable != NULL) {
        return VTable_to_double(pValue, pSimMRSP_section_t_TrackAtlasTypesVTable, nRetValue);
    }
    return struct__129_to_double(pValue, nRetValue);
}

int MRSP_section_t_TrackAtlasTypes_to_long(const void *pValue, long *nRetValue)
{
    if (pSimMRSP_section_t_TrackAtlasTypesVTable != NULL) {
        return VTable_to_long(pValue, pSimMRSP_section_t_TrackAtlasTypesVTable, nRetValue);
    }
    return struct__129_to_long(pValue, nRetValue);
}

int get_MRSP_section_t_TrackAtlasTypes_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    return get_struct__129_signature(pfnStrAppend, pData);
}

int set_MRSP_section_t_TrackAtlasTypes_default_value(void *pValue)
{
    return set_struct__129_default_value(pValue);
}

int check_MRSP_section_t_TrackAtlasTypes_string(const char *str, char **endptr)
{
    static MRSP_section_t_TrackAtlasTypes rTemp;
    return string_to_MRSP_section_t_TrackAtlasTypes(str, &rTemp, endptr);
}

SimTypeUtils _Type_MRSP_section_t_TrackAtlasTypes_Utils = {
    MRSP_section_t_TrackAtlasTypes_to_string,
    check_MRSP_section_t_TrackAtlasTypes_string,
    string_to_MRSP_section_t_TrackAtlasTypes,
    is_MRSP_section_t_TrackAtlasTypes_double_conversion_allowed,
    MRSP_section_t_TrackAtlasTypes_to_double,
    is_MRSP_section_t_TrackAtlasTypes_long_convertion_allowed,
    MRSP_section_t_TrackAtlasTypes_to_long,
    compare_MRSP_section_t_TrackAtlasTypes,
    get_MRSP_section_t_TrackAtlasTypes_signature,
    set_MRSP_section_t_TrackAtlasTypes_default_value,
    sizeof(MRSP_section_t_TrackAtlasTypes)
};

/****************************************************************
 ** L_internal_Type_Obu_BasicTypes_Pkg 
 ****************************************************************/

struct SimTypeVTable *pSimL_internal_Type_Obu_BasicTypes_PkgVTable;

int L_internal_Type_Obu_BasicTypes_Pkg_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimL_internal_Type_Obu_BasicTypes_PkgVTable != NULL
        && pSimL_internal_Type_Obu_BasicTypes_PkgVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimL_internal_Type_Obu_BasicTypes_PkgVTable->m_pfnToType(SptString, pValue), pData);
    }
    return kcg_int_to_string(pValue, pfnStrAppend, pData);
}

int string_to_L_internal_Type_Obu_BasicTypes_Pkg(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimL_internal_Type_Obu_BasicTypes_PkgVTable != NULL) {
        nRet=string_to_VTable(str, pSimL_internal_Type_Obu_BasicTypes_PkgVTable, pValue, endptr);
    }
    if (nRet==0) {
        nRet = string_to_kcg_int(str, pValue, endptr);
    }
    return nRet;
}

int is_L_internal_Type_Obu_BasicTypes_Pkg_double_conversion_allowed()
{
    if (pSimL_internal_Type_Obu_BasicTypes_PkgVTable != NULL) {
        return is_VTable_double_conversion_allowed(pSimL_internal_Type_Obu_BasicTypes_PkgVTable);
    }
    return is_kcg_int_double_conversion_allowed();
}

int is_L_internal_Type_Obu_BasicTypes_Pkg_long_convertion_allowed()
{
    if (pSimL_internal_Type_Obu_BasicTypes_PkgVTable != NULL) {
        return is_VTable_long_convertion_allowed(pSimL_internal_Type_Obu_BasicTypes_PkgVTable);
    }
    return is_kcg_int_long_convertion_allowed();
}

void compare_L_internal_Type_Obu_BasicTypes_Pkg(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimL_internal_Type_Obu_BasicTypes_PkgVTable != NULL
        && pSimL_internal_Type_Obu_BasicTypes_PkgVTable->m_version >= Scv612
        && pSimL_internal_Type_Obu_BasicTypes_PkgVTable->m_pfnCompare != NULL) {
        if (pSimL_internal_Type_Obu_BasicTypes_PkgVTable->m_version >= Scv65) {
            /* R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimL_internal_Type_Obu_BasicTypes_PkgVTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /* Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimL_internal_Type_Obu_BasicTypes_PkgVTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        compare_kcg_int(pResult, pValue1, pValue2, pData, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int L_internal_Type_Obu_BasicTypes_Pkg_to_double(const void *pValue, double *nRetValue)
{
    if (pSimL_internal_Type_Obu_BasicTypes_PkgVTable != NULL) {
        return VTable_to_double(pValue, pSimL_internal_Type_Obu_BasicTypes_PkgVTable, nRetValue);
    }
    return kcg_int_to_double(pValue, nRetValue);
}

int L_internal_Type_Obu_BasicTypes_Pkg_to_long(const void *pValue, long *nRetValue)
{
    if (pSimL_internal_Type_Obu_BasicTypes_PkgVTable != NULL) {
        return VTable_to_long(pValue, pSimL_internal_Type_Obu_BasicTypes_PkgVTable, nRetValue);
    }
    return kcg_int_to_long(pValue, nRetValue);
}

int get_L_internal_Type_Obu_BasicTypes_Pkg_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    return get_kcg_int_signature(pfnStrAppend, pData);
}

int set_L_internal_Type_Obu_BasicTypes_Pkg_default_value(void *pValue)
{
    return set_kcg_int_default_value(pValue);
}

int check_L_internal_Type_Obu_BasicTypes_Pkg_string(const char *str, char **endptr)
{
    static L_internal_Type_Obu_BasicTypes_Pkg rTemp;
    return string_to_L_internal_Type_Obu_BasicTypes_Pkg(str, &rTemp, endptr);
}

SimTypeUtils _Type_L_internal_Type_Obu_BasicTypes_Pkg_Utils = {
    L_internal_Type_Obu_BasicTypes_Pkg_to_string,
    check_L_internal_Type_Obu_BasicTypes_Pkg_string,
    string_to_L_internal_Type_Obu_BasicTypes_Pkg,
    is_L_internal_Type_Obu_BasicTypes_Pkg_double_conversion_allowed,
    L_internal_Type_Obu_BasicTypes_Pkg_to_double,
    is_L_internal_Type_Obu_BasicTypes_Pkg_long_convertion_allowed,
    L_internal_Type_Obu_BasicTypes_Pkg_to_long,
    compare_L_internal_Type_Obu_BasicTypes_Pkg,
    get_L_internal_Type_Obu_BasicTypes_Pkg_signature,
    set_L_internal_Type_Obu_BasicTypes_Pkg_default_value,
    sizeof(L_internal_Type_Obu_BasicTypes_Pkg)
};

/****************************************************************
 ** V_internal_Type_Obu_BasicTypes_Pkg 
 ****************************************************************/

struct SimTypeVTable *pSimV_internal_Type_Obu_BasicTypes_PkgVTable;

int V_internal_Type_Obu_BasicTypes_Pkg_to_string(const void *pValue, PFNSTRAPPEND pfnStrAppend, void *pData)
{
    if (pSimV_internal_Type_Obu_BasicTypes_PkgVTable != NULL
        && pSimV_internal_Type_Obu_BasicTypes_PkgVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
       return pfnStrAppend(*(char**)pSimV_internal_Type_Obu_BasicTypes_PkgVTable->m_pfnToType(SptString, pValue), pData);
    }
    return kcg_int_to_string(pValue, pfnStrAppend, pData);
}

int string_to_V_internal_Type_Obu_BasicTypes_Pkg(const char *str, void *pValue, char **endptr)
{
    int nRet=0;
    skip_whitespace(str);
    if (pSimV_internal_Type_Obu_BasicTypes_PkgVTable != NULL) {
        nRet=string_to_VTable(str, pSimV_internal_Type_Obu_BasicTypes_PkgVTable, pValue, endptr);
    }
    if (nRet==0) {
        nRet = string_to_kcg_int(str, pValue, endptr);
    }
    return nRet;
}

int is_V_internal_Type_Obu_BasicTypes_Pkg_double_conversion_allowed()
{
    if (pSimV_internal_Type_Obu_BasicTypes_PkgVTable != NULL) {
        return is_VTable_double_conversion_allowed(pSimV_internal_Type_Obu_BasicTypes_PkgVTable);
    }
    return is_kcg_int_double_conversion_allowed();
}

int is_V_internal_Type_Obu_BasicTypes_Pkg_long_convertion_allowed()
{
    if (pSimV_internal_Type_Obu_BasicTypes_PkgVTable != NULL) {
        return is_VTable_long_convertion_allowed(pSimV_internal_Type_Obu_BasicTypes_PkgVTable);
    }
    return is_kcg_int_long_convertion_allowed();
}

void compare_V_internal_Type_Obu_BasicTypes_Pkg(int *pResult, const void *pValue1, const void *pValue2, void *pData, const char *pszPath, PFNSTRAPPEND pfnStrListAppend, void *pListErrPaths)
{
    int unitResult=0;
    /* Customized comparison */
    if (pSimV_internal_Type_Obu_BasicTypes_PkgVTable != NULL
        && pSimV_internal_Type_Obu_BasicTypes_PkgVTable->m_version >= Scv612
        && pSimV_internal_Type_Obu_BasicTypes_PkgVTable->m_pfnCompare != NULL) {
        if (pSimV_internal_Type_Obu_BasicTypes_PkgVTable->m_version >= Scv65) {
            /* R15 and higher: VTable Compare function shall UPDATE *pResult global flag (*pResult|=SIM_CMP_RES_LT/...): */
            unitResult=pSimV_internal_Type_Obu_BasicTypes_PkgVTable->m_pfnCompare(pResult, pValue1, pValue2);
        } else {
            /* Before R15: VTable Compare function shall SET *pResult global flag (*pResult=-1/1/0): */
            pSimV_internal_Type_Obu_BasicTypes_PkgVTable->m_pfnCompare(&unitResult, pValue1, pValue2);
            updateCompareResult(unitResult, pResult);
        }
    } else {
        /* Predefined comparison */
        compare_kcg_int(pResult, pValue1, pValue2, pData, pszPath, pfnStrListAppend, pListErrPaths);
    }
    if (unitResult!=0 && pfnStrListAppend!=NULL && pszPath!=NULL && *pszPath!=0 && pListErrPaths!=NULL)
        pfnStrListAppend(pszPath, pListErrPaths);
}

int V_internal_Type_Obu_BasicTypes_Pkg_to_double(const void *pValue, double *nRetValue)
{
    if (pSimV_internal_Type_Obu_BasicTypes_PkgVTable != NULL) {
        return VTable_to_double(pValue, pSimV_internal_Type_Obu_BasicTypes_PkgVTable, nRetValue);
    }
    return kcg_int_to_double(pValue, nRetValue);
}

int V_internal_Type_Obu_BasicTypes_Pkg_to_long(const void *pValue, long *nRetValue)
{
    if (pSimV_internal_Type_Obu_BasicTypes_PkgVTable != NULL) {
        return VTable_to_long(pValue, pSimV_internal_Type_Obu_BasicTypes_PkgVTable, nRetValue);
    }
    return kcg_int_to_long(pValue, nRetValue);
}

int get_V_internal_Type_Obu_BasicTypes_Pkg_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    return get_kcg_int_signature(pfnStrAppend, pData);
}

int set_V_internal_Type_Obu_BasicTypes_Pkg_default_value(void *pValue)
{
    return set_kcg_int_default_value(pValue);
}

int check_V_internal_Type_Obu_BasicTypes_Pkg_string(const char *str, char **endptr)
{
    static V_internal_Type_Obu_BasicTypes_Pkg rTemp;
    return string_to_V_internal_Type_Obu_BasicTypes_Pkg(str, &rTemp, endptr);
}

SimTypeUtils _Type_V_internal_Type_Obu_BasicTypes_Pkg_Utils = {
    V_internal_Type_Obu_BasicTypes_Pkg_to_string,
    check_V_internal_Type_Obu_BasicTypes_Pkg_string,
    string_to_V_internal_Type_Obu_BasicTypes_Pkg,
    is_V_internal_Type_Obu_BasicTypes_Pkg_double_conversion_allowed,
    V_internal_Type_Obu_BasicTypes_Pkg_to_double,
    is_V_internal_Type_Obu_BasicTypes_Pkg_long_convertion_allowed,
    V_internal_Type_Obu_BasicTypes_Pkg_to_long,
    compare_V_internal_Type_Obu_BasicTypes_Pkg,
    get_V_internal_Type_Obu_BasicTypes_Pkg_signature,
    set_V_internal_Type_Obu_BasicTypes_Pkg_default_value,
    sizeof(V_internal_Type_Obu_BasicTypes_Pkg)
};

#include "C:/Program Files/Esterel Technologies/SCADE R16.1/SCADE/lib/kcg_conv.c"
