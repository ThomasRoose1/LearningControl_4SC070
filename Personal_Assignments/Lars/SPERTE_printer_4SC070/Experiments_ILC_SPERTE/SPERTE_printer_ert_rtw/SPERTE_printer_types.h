/*
 * SPERTE_printer_types.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "SPERTE_printer".
 *
 * Model version              : 13.3
 * Simulink Coder version : 25.2 (R2025b) 28-Jul-2025
 * C source code generated on : Fri Apr 24 13:38:06 2026
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex-A (64-bit)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef SPERTE_printer_types_h_
#define SPERTE_printer_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_SupervisorModeType_
#define DEFINED_TYPEDEF_FOR_SupervisorModeType_

typedef enum {
  SupervisorModeType_None = 0,         /* Default value */
  SupervisorModeType_Homing,
  SupervisorModeType_MovetoX0,
  SupervisorModeType_DisableControl,
  SupervisorModeType_ResetEnc,
  SupervisorModeType_EnableRunAndSafety,
  SupervisorModeType_AirbagLeft,
  SupervisorModeType_DisableOutputs,
  SupervisorModeType_AirbagRight
} SupervisorModeType;

#endif

#ifndef struct_emxArray_char_T
#define struct_emxArray_char_T

struct emxArray_char_T
{
  char_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /* struct_emxArray_char_T */

#ifndef typedef_emxArray_char_T_SPERTE_printe_T
#define typedef_emxArray_char_T_SPERTE_printe_T

typedef struct emxArray_char_T emxArray_char_T_SPERTE_printe_T;

#endif                             /* typedef_emxArray_char_T_SPERTE_printe_T */

/* Parameters for system: '<S1>/Triggered Single Pulse' */
typedef struct P_TriggeredSinglePulse_SPERTE_T_ P_TriggeredSinglePulse_SPERTE_T;

/* Parameters for system: '<S2>/Triggered Single Pulse1' */
typedef struct P_TriggeredSinglePulse1_SPERT_T_ P_TriggeredSinglePulse1_SPERT_T;

/* Parameters (default storage) */
typedef struct P_SPERTE_printer_T_ P_SPERTE_printer_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_SPERTE_printer_T RT_MODEL_SPERTE_printer_T;

#endif                                 /* SPERTE_printer_types_h_ */
