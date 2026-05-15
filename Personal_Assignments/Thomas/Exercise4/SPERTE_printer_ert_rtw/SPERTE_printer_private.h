/*
 * SPERTE_printer_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "SPERTE_printer".
 *
 * Model version              : 15.0
 * Simulink Coder version : 25.2 (R2025b) 28-Jul-2025
 * C source code generated on : Tue Apr 28 10:40:51 2026
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex-A (64-bit)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef SPERTE_printer_private_h_
#define SPERTE_printer_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "SPERTE_printer.h"
#include "SPERTE_printer_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

/* Skipping ulong/long check: insufficient preprocessor integer range. */

/* Skipping ulong_long/long_long check: insufficient preprocessor integer range. */
extern void ec_Supervisor(SimStruct *rts);
extern void ec_Ebox(SimStruct *rts);
extern void dpd(SimStruct *rts);
extern void dlowpass2(SimStruct *rts);
extern void dweakint_resettable(SimStruct *rts);
extern void ec_EboxResetEnc(SimStruct *rts);
extern void SPERT_TriggeredSinglePulse_Init(DW_TriggeredSinglePulse_SPERT_T
  *localDW, P_TriggeredSinglePulse_SPERTE_T *localP);
extern void SPERTE_pri_TriggeredSinglePulse(real_T rtu_Trigger, real_T rtp_p_wid,
  B_TriggeredSinglePulse_SPERTE_T *localB, DW_TriggeredSinglePulse_SPERT_T
  *localDW, P_TriggeredSinglePulse_SPERTE_T *localP);
extern void SPER_TriggeredSinglePulse1_Init(DW_TriggeredSinglePulse1_SPER_T
  *localDW, P_TriggeredSinglePulse1_SPERT_T *localP);
extern void SPERTE_pr_TriggeredSinglePulse1(boolean_T rtu_Trigger, real_T
  rtp_p_wid, B_TriggeredSinglePulse1_SPERT_T *localB,
  DW_TriggeredSinglePulse1_SPER_T *localDW, P_TriggeredSinglePulse1_SPERT_T
  *localP);

#endif                                 /* SPERTE_printer_private_h_ */
