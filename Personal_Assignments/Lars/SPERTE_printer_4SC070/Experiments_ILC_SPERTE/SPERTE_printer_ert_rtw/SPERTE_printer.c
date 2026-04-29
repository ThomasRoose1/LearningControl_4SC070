/*
 * SPERTE_printer.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "SPERTE_printer".
 *
 * Model version              : 13.3
 * Simulink Coder version : 25.2 (R2025b) 28-Jul-2025
<<<<<<< Updated upstream
 * C source code generated on : Fri Apr 24 13:38:06 2026
=======
 * C source code generated on : Wed Apr 29 11:15:22 2026
>>>>>>> Stashed changes
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex-A (64-bit)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "SPERTE_printer.h"
#include "rtwtypes.h"
#include "SPERTE_printer_types.h"
#include "SPERTE_printer_private.h"
#include <stddef.h>
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "zero_crossing_types.h"

/* Named constants for MATLAB Function: '<S7>/SPERTE_measurement_function' */
#define SPERTE_printer_CALL_EVENT      (-1)

/* Block signals (default storage) */
B_SPERTE_printer_T SPERTE_printer_B;

/* Block states (default storage) */
DW_SPERTE_printer_T SPERTE_printer_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_SPERTE_printer_T SPERTE_printer_PrevZCX;

/* Real-time model */
static RT_MODEL_SPERTE_printer_T SPERTE_printer_M_;
RT_MODEL_SPERTE_printer_T *const SPERTE_printer_M = &SPERTE_printer_M_;

/* Forward declaration for local functions */
static void SPERTE_printer_emxInit_char_T(emxArray_char_T_SPERTE_printe_T
  **pEmxArray, int32_T numDimensions);
static void SPERTE_emxEnsureCapacity_char_T(emxArray_char_T_SPERTE_printe_T
  *emxArray, int32_T oldNumel);
static void SPERTE_printer_emxFree_char_T(emxArray_char_T_SPERTE_printe_T
  **pEmxArray);
static int8_T SPERTE_printer_filedata(void);
static int8_T SPERTE_printer_cfopen(const emxArray_char_T_SPERTE_printe_T
  *cfilename, const char_T *cpermission);
static int32_T SPERTE_printer_cfclose(real_T fid);

/*
 * System initialize for atomic system:
 *    '<S1>/Triggered Single Pulse'
 *    '<Root>/Triggered Single Pulse1'
 */
void SPERT_TriggeredSinglePulse_Init(DW_TriggeredSinglePulse_SPERT_T *localDW,
  P_TriggeredSinglePulse_SPERTE_T *localP)
{
  /* InitializeConditions for UnitDelay: '<S10>/Delay Input1' */
  localDW->DelayInput1_DSTATE = localP->DelayInput1_InitialCondition;

  /* InitializeConditions for Saturate: '<S8>/Saturation' incorporates:
   *  UnitDelay: '<S8>/Unit Delay1'
   */
  localDW->UnitDelay1_DSTATE = localP->UnitDelay1_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S8>/Unit Delay' */
  localDW->UnitDelay_DSTATE = localP->UnitDelay_InitialCondition;
}

/*
 * Output and update for atomic system:
 *    '<S1>/Triggered Single Pulse'
 *    '<Root>/Triggered Single Pulse1'
 */
void SPERTE_pri_TriggeredSinglePulse(real_T rtu_Trigger, real_T rtp_p_wid,
  B_TriggeredSinglePulse_SPERTE_T *localB, DW_TriggeredSinglePulse_SPERT_T
  *localDW, P_TriggeredSinglePulse_SPERTE_T *localP)
{
  uint8_T rtb_Compare_i;
  uint8_T rtb_FixPtRelationalOperator;

  /* RelationalOperator: '<S12>/Compare' incorporates:
   *  Constant: '<S12>/Constant'
   */
  rtb_Compare_i = (uint8_T)(rtu_Trigger > localP->Constant_Value);

  /* RelationalOperator: '<S10>/FixPt Relational Operator' incorporates:
   *  UnitDelay: '<S10>/Delay Input1'
   */
  rtb_FixPtRelationalOperator = (uint8_T)(rtb_Compare_i >
    localDW->DelayInput1_DSTATE);

  /* Saturate: '<S8>/Saturation' incorporates:
   *  UnitDelay: '<S8>/Unit Delay1'
   */
  if (localDW->UnitDelay1_DSTATE > localP->Saturation_UpperSat) {
    localDW->UnitDelay1_DSTATE = localP->Saturation_UpperSat;
  } else if (localDW->UnitDelay1_DSTATE < localP->Saturation_LowerSat) {
    localDW->UnitDelay1_DSTATE = localP->Saturation_LowerSat;
  }

  /* Product: '<S8>/Product3' incorporates:
   *  Constant: '<S11>/Constant'
   *  Logic: '<S8>/Logical Operator'
   *  RelationalOperator: '<S11>/Compare'
   *  Saturate: '<S8>/Saturation'
   *  UnitDelay: '<S8>/Unit Delay'
   */
  localB->Product3 = (real_T)!(localDW->UnitDelay_DSTATE > rtp_p_wid - 1.0) *
    localDW->UnitDelay1_DSTATE;

  /* Update for UnitDelay: '<S10>/Delay Input1' */
  localDW->DelayInput1_DSTATE = rtb_Compare_i;

  /* Update for Saturate: '<S8>/Saturation' incorporates:
   *  Sum: '<S8>/Add1'
   *  UnitDelay: '<S8>/Unit Delay1'
   */
  localDW->UnitDelay1_DSTATE = localB->Product3 + (real_T)
    rtb_FixPtRelationalOperator;

  /* Update for UnitDelay: '<S8>/Unit Delay' incorporates:
   *  Constant: '<S8>/Constant2'
   *  Product: '<S8>/Product'
   *  Product: '<S8>/Product1'
   *  Sum: '<S8>/Add'
   */
  localDW->UnitDelay_DSTATE = (localP->Constant2_Value * localB->Product3 +
    localDW->UnitDelay_DSTATE) * localB->Product3;
}

/*
 * System initialize for atomic system:
 *    '<S2>/Triggered Single Pulse1'
 *    '<Root>/Triggered Single Pulse'
 */
void SPER_TriggeredSinglePulse1_Init(DW_TriggeredSinglePulse1_SPER_T *localDW,
  P_TriggeredSinglePulse1_SPERT_T *localP)
{
  /* InitializeConditions for UnitDelay: '<S25>/Delay Input1' */
  localDW->DelayInput1_DSTATE = localP->DelayInput1_InitialCondition;

  /* InitializeConditions for Saturate: '<S15>/Saturation' incorporates:
   *  UnitDelay: '<S15>/Unit Delay1'
   */
  localDW->UnitDelay1_DSTATE = localP->UnitDelay1_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S15>/Unit Delay' */
  localDW->UnitDelay_DSTATE = localP->UnitDelay_InitialCondition;
}

/*
 * Output and update for atomic system:
 *    '<S2>/Triggered Single Pulse1'
 *    '<Root>/Triggered Single Pulse'
 */
void SPERTE_pr_TriggeredSinglePulse1(boolean_T rtu_Trigger, real_T rtp_p_wid,
  B_TriggeredSinglePulse1_SPERT_T *localB, DW_TriggeredSinglePulse1_SPER_T
  *localDW, P_TriggeredSinglePulse1_SPERT_T *localP)
{
  uint8_T rtb_Compare_o;
  uint8_T rtb_FixPtRelationalOperator;

  /* RelationalOperator: '<S27>/Compare' incorporates:
   *  Constant: '<S27>/Constant'
   */
  rtb_Compare_o = (uint8_T)((int32_T)rtu_Trigger > (int32_T)
    localP->Constant_Value);

  /* RelationalOperator: '<S25>/FixPt Relational Operator' incorporates:
   *  UnitDelay: '<S25>/Delay Input1'
   */
  rtb_FixPtRelationalOperator = (uint8_T)(rtb_Compare_o >
    localDW->DelayInput1_DSTATE);

  /* Saturate: '<S15>/Saturation' incorporates:
   *  UnitDelay: '<S15>/Unit Delay1'
   */
  if (localDW->UnitDelay1_DSTATE > localP->Saturation_UpperSat) {
    localDW->UnitDelay1_DSTATE = localP->Saturation_UpperSat;
  } else if (localDW->UnitDelay1_DSTATE < localP->Saturation_LowerSat) {
    localDW->UnitDelay1_DSTATE = localP->Saturation_LowerSat;
  }

  /* Product: '<S15>/Product3' incorporates:
   *  Constant: '<S26>/Constant'
   *  Logic: '<S15>/Logical Operator'
   *  RelationalOperator: '<S26>/Compare'
   *  Saturate: '<S15>/Saturation'
   *  UnitDelay: '<S15>/Unit Delay'
   */
  localB->Product3 = (real_T)!(localDW->UnitDelay_DSTATE > rtp_p_wid - 1.0) *
    localDW->UnitDelay1_DSTATE;

  /* Update for UnitDelay: '<S25>/Delay Input1' */
  localDW->DelayInput1_DSTATE = rtb_Compare_o;

  /* Update for Saturate: '<S15>/Saturation' incorporates:
   *  Sum: '<S15>/Add1'
   *  UnitDelay: '<S15>/Unit Delay1'
   */
  localDW->UnitDelay1_DSTATE = localB->Product3 + (real_T)
    rtb_FixPtRelationalOperator;

  /* Update for UnitDelay: '<S15>/Unit Delay' incorporates:
   *  Constant: '<S15>/Constant2'
   *  Product: '<S15>/Product'
   *  Product: '<S15>/Product1'
   *  Sum: '<S15>/Add'
   */
  localDW->UnitDelay_DSTATE = (localP->Constant2_Value * localB->Product3 +
    localDW->UnitDelay_DSTATE) * localB->Product3;
}

static void SPERTE_printer_emxInit_char_T(emxArray_char_T_SPERTE_printe_T
  **pEmxArray, int32_T numDimensions)
{
  emxArray_char_T_SPERTE_printe_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_char_T_SPERTE_printe_T *)malloc(sizeof
    (emxArray_char_T_SPERTE_printe_T));
  emxArray = *pEmxArray;
  emxArray->data = (char_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)malloc(sizeof(int32_T) * (uint32_T)numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

static void SPERTE_emxEnsureCapacity_char_T(emxArray_char_T_SPERTE_printe_T
  *emxArray, int32_T oldNumel)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = malloc((uint32_T)i * sizeof(char_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(char_T) * (uint32_T)oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = (char_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

static void SPERTE_printer_emxFree_char_T(emxArray_char_T_SPERTE_printe_T
  **pEmxArray)
{
  if (*pEmxArray != (emxArray_char_T_SPERTE_printe_T *)NULL) {
    if (((*pEmxArray)->data != (char_T *)NULL) && (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_char_T_SPERTE_printe_T *)NULL;
  }
}

/* Function for MATLAB Function: '<S7>/SPERTE_measurement_function' */
static int8_T SPERTE_printer_filedata(void)
{
  int32_T k;
  int8_T f;
  boolean_T exitg1;
  f = 0;
  k = 1;
  exitg1 = false;
  while ((!exitg1) && (k - 1 < 20)) {
    if (SPERTE_printer_DW.eml_openfiles[(int8_T)k - 1] == NULL) {
      f = (int8_T)k;
      exitg1 = true;
    } else {
      k++;
    }
  }

  return f;
}

/* Function for MATLAB Function: '<S7>/SPERTE_measurement_function' */
static int8_T SPERTE_printer_cfopen(const emxArray_char_T_SPERTE_printe_T
  *cfilename, const char_T *cpermission)
{
  FILE *filestar;
  emxArray_char_T_SPERTE_printe_T *ccfilename;
  int32_T loop_ub;
  int8_T fileid;
  int8_T j;
  fileid = -1;
  j = SPERTE_printer_filedata();
  if (j >= 1) {
    SPERTE_printer_emxInit_char_T(&ccfilename, 2);
    loop_ub = ccfilename->size[0] * ccfilename->size[1];
    ccfilename->size[0] = 1;
    ccfilename->size[1] = cfilename->size[1] + 1;
    SPERTE_emxEnsureCapacity_char_T(ccfilename, loop_ub);
    loop_ub = cfilename->size[1];
    if (loop_ub - 1 >= 0) {
      memcpy(&ccfilename->data[0], &cfilename->data[0], (uint32_T)loop_ub *
             sizeof(char_T));
    }

    ccfilename->data[cfilename->size[1]] = '\x00';
    filestar = fopen(&ccfilename->data[0], cpermission);
    SPERTE_printer_emxFree_char_T(&ccfilename);
    if (filestar != NULL) {
      SPERTE_printer_DW.eml_openfiles[j - 1] = filestar;
      SPERTE_printer_DW.eml_autoflush[j - 1] = true;
      loop_ub = j + 2;
      if (j + 2 > 127) {
        loop_ub = 127;
      }

      fileid = (int8_T)loop_ub;
    }
  }

  return fileid;
}

/* Function for MATLAB Function: '<S7>/SPERTE_measurement_function' */
static int32_T SPERTE_printer_cfclose(real_T fid)
{
  FILE *f;
  int32_T cst;
  int32_T st;
  int8_T b_fileid;
  int8_T fileid;
  st = -1;
  fileid = (int8_T)fid;
  if (((int8_T)fid < 0) || (fid != (int8_T)fid)) {
    fileid = -1;
  }

  b_fileid = fileid;
  if (fileid < 0) {
    b_fileid = -1;
  }

  if (b_fileid >= 3) {
    f = SPERTE_printer_DW.eml_openfiles[b_fileid - 3];
  } else if (b_fileid == 0) {
    f = stdin;
  } else if (b_fileid == 1) {
    f = stdout;
  } else if (b_fileid == 2) {
    f = stderr;
  } else {
    f = NULL;
  }

  if ((f != NULL) && (fileid >= 3)) {
    cst = fclose(f);
    if (cst == 0) {
      st = 0;
      SPERTE_printer_DW.eml_openfiles[fileid - 3] = NULL;
      SPERTE_printer_DW.eml_autoflush[fileid - 3] = true;
    }
  }

  return st;
}

/* Model step function */
void SPERTE_printer_step(void)
{
  /* local block i/o variables */
  real_T rtb_TSamp;
  boolean_T rtb_OR;
  boolean_T rtb_AND;
  boolean_T rtb_NOT;
  boolean_T rtb_LogicalOperator3;
  FILE *f;
  size_t bytesOutSizet;
  emxArray_char_T_SPERTE_printe_T *str;
  emxArray_char_T_SPERTE_printe_T *str_0;
  real_T rtb_Product1;
  real_T rtb_Sum2;
  real_T rtb_Sum4;
  int32_T nbytes;
  int32_T tmp;
  real32_T xout[4];
  int8_T b_fileid;
  uint8_T DataTypeConversion;
  boolean_T autoflush;

  /* Reset subsysRan breadcrumbs */
  srClearBC(SPERTE_printer_DW.Reference_SubsysRanBC);

  /* S-Function (ec_Supervisor): '<S17>/S-Function' */

  /* Level2 S-Function Block: '<S17>/S-Function' (ec_Supervisor) */
  {
    SimStruct *rts = SPERTE_printer_M->childSfunctions[0];
    sfcnOutputs(rts,0);
  }

  /* S-Function (ec_Ebox): '<S16>/ec_Ebox' */

  /* Level2 S-Function Block: '<S16>/ec_Ebox' (ec_Ebox) */
  {
    SimStruct *rts = SPERTE_printer_M->childSfunctions[1];
    sfcnOutputs(rts,0);
  }

  /* Gain: '<S16>/Gain' */
  SPERTE_printer_B.Gain[0] = SPERTE_printer_P.Gain_Gain * 0.0;
  SPERTE_printer_B.Gain[1] = SPERTE_printer_P.Gain_Gain * 0.0;

  /* Gain: '<S13>/Counts to Meter1' */
  SPERTE_printer_B.CountstoMeter1 = SPERTE_printer_P.CountstoMeter1_Gain *
    SPERTE_printer_B.ec_Ebox_o2[0];

  /* RateTransition: '<S13>/Rate Transition5' */
  SPERTE_printer_B.RateTransition5 = SPERTE_printer_B.ec_Ebox_o3[1];

  /* Logic: '<S2>/OR' incorporates:
   *  Constant: '<S2>/force_home'
   *  UnitDelay: '<S2>/Unit Delay'
   */
  rtb_OR = (SPERTE_printer_DW.UnitDelay_DSTATE ||
            (SPERTE_printer_P.force_home_Value != 0.0));

  /* Outputs for Atomic SubSystem: '<S2>/Triggered Single Pulse1' */
  /* Outputs for Atomic SubSystem: '<S2>/Triggered Single Pulse1' */
  SPERTE_pr_TriggeredSinglePulse1(rtb_OR,
    SPERTE_printer_P.TriggeredSinglePulse1_p_wid,
    &SPERTE_printer_B.TriggeredSinglePulse1,
    &SPERTE_printer_DW.TriggeredSinglePulse1,
    &SPERTE_printer_P.TriggeredSinglePulse1);

  /* End of Outputs for SubSystem: '<S2>/Triggered Single Pulse1' */
  /* End of Outputs for SubSystem: '<S2>/Triggered Single Pulse1' */

  /* Chart: '<S14>/Supervisor' */
  if (SPERTE_printer_DW.temporalCounter_i1 < 1023) {
    SPERTE_printer_DW.temporalCounter_i1++;
  }

  SPERTE_printer_DW.sfEvent = SPERTE_printer_CALL_EVENT;
  if (SPERTE_printer_DW.is_active_c1_SPERTE_printer == 0) {
    SPERTE_printer_DW.is_active_c1_SPERTE_printer = 1U;
    SPERTE_printer_B.SupervisorMode = SupervisorModeType_Homing;

    /* Set jog speed and homing state */
    SPERTE_printer_B.toPoint = 0.0;
    SPERTE_printer_B.homingBusy = 1.0;
    SPERTE_printer_B.jogSpeed = -0.2;
    SPERTE_printer_B.homeControllerEnabled = 1.0;
  } else {
    switch (SPERTE_printer_B.SupervisorMode) {
     case SupervisorModeType_AirbagLeft:
      SPERTE_printer_B.airBagEnabled = 1.0;
      SPERTE_printer_B.airBagRef = -0.01;
      if (SPERTE_printer_DW.temporalCounter_i1 >= 1000) {
        SPERTE_printer_B.SupervisorMode = SupervisorModeType_DisableOutputs;
        SPERTE_printer_B.controlEnabled = 0.0;
      }
      break;

     case SupervisorModeType_AirbagRight:
      SPERTE_printer_B.airBagEnabled = 1.0;
      SPERTE_printer_B.airBagRef = 0.35;
      if (SPERTE_printer_DW.temporalCounter_i1 >= 1000) {
        SPERTE_printer_B.SupervisorMode = SupervisorModeType_DisableOutputs;
        SPERTE_printer_B.controlEnabled = 0.0;
      }
      break;

     case SupervisorModeType_DisableControl:
      SPERTE_printer_B.homeControllerEnabled = 0.0;

      /* Allow settling of belt */
      if (SPERTE_printer_DW.temporalCounter_i1 >= 500) {
        SPERTE_printer_DW.temporalCounter_i1 = 0U;
        SPERTE_printer_B.SupervisorMode = SupervisorModeType_ResetEnc;
        SPERTE_printer_B.resetEnc = 1.0;
      }
      break;

     case SupervisorModeType_DisableOutputs:
      SPERTE_printer_B.controlEnabled = 0.0;
      break;

     case SupervisorModeType_EnableRunAndSafety:
      SPERTE_printer_B.resetEnc = 0.0;
      SPERTE_printer_B.homingBusy = 0.0;
      if (SPERTE_printer_B.TriggeredSinglePulse1.Product3 != 0.0) {
        SPERTE_printer_B.SupervisorMode = SupervisorModeType_Homing;

        /* Set jog speed and homing state */
        SPERTE_printer_B.toPoint = 0.0;
        SPERTE_printer_B.homingBusy = 1.0;
        SPERTE_printer_B.jogSpeed = -0.2;
        SPERTE_printer_B.homeControllerEnabled = 1.0;
      } else if (SPERTE_printer_B.CountstoMeter1 < -0.01) {
        SPERTE_printer_DW.temporalCounter_i1 = 0U;
        SPERTE_printer_B.SupervisorMode = SupervisorModeType_AirbagLeft;
        SPERTE_printer_B.airBagEnabled = 1.0;
        SPERTE_printer_B.airBagRef = -0.01;
      } else if (SPERTE_printer_B.CountstoMeter1 > 0.35) {
        SPERTE_printer_DW.temporalCounter_i1 = 0U;
        SPERTE_printer_B.SupervisorMode = SupervisorModeType_AirbagRight;
        SPERTE_printer_B.airBagEnabled = 1.0;
        SPERTE_printer_B.airBagRef = 0.35;
      }
      break;

     case SupervisorModeType_Homing:
      SPERTE_printer_B.toPoint = 0.0;
      SPERTE_printer_B.homingBusy = 1.0;
      SPERTE_printer_B.jogSpeed = -0.2;
      SPERTE_printer_B.homeControllerEnabled = 1.0;

      /* Transition if homeswitch becomes high */
      if (SPERTE_printer_B.RateTransition5 != 0.0) {
        SPERTE_printer_DW.temporalCounter_i1 = 0U;
        SPERTE_printer_B.SupervisorMode = SupervisorModeType_MovetoX0;
        SPERTE_printer_B.jogSpeed = 0.0;
        SPERTE_printer_B.toPoint = 0.06;
      }
      break;

     case SupervisorModeType_MovetoX0:
      SPERTE_printer_B.jogSpeed = 0.0;
      SPERTE_printer_B.toPoint = 0.06;

      /* Allow time for moving */
      if (SPERTE_printer_DW.temporalCounter_i1 >= 1000) {
        SPERTE_printer_DW.temporalCounter_i1 = 0U;
        SPERTE_printer_B.SupervisorMode = SupervisorModeType_DisableControl;
        SPERTE_printer_B.homeControllerEnabled = 0.0;
      }
      break;

     default:
      /* State ResetEnc */
      SPERTE_printer_B.resetEnc = 1.0;
      if (SPERTE_printer_DW.temporalCounter_i1 >= 100) {
        SPERTE_printer_B.SupervisorMode = SupervisorModeType_EnableRunAndSafety;
        SPERTE_printer_B.resetEnc = 0.0;
        SPERTE_printer_B.homingBusy = 0.0;
      }
      break;
    }
  }

  /* End of Chart: '<S14>/Supervisor' */

  /* Constant: '<Root>/active' */
  SPERTE_printer_B.active = SPERTE_printer_P.active_Value;

  /* Outputs for Atomic SubSystem: '<Root>/Triggered Single Pulse1' */
  /* Outputs for Atomic SubSystem: '<Root>/Triggered Single Pulse1' */
  SPERTE_pri_TriggeredSinglePulse(SPERTE_printer_B.active,
    SPERTE_printer_P.TriggeredSinglePulse1_p_wid_a,
    &SPERTE_printer_B.TriggeredSinglePulse1_o,
    &SPERTE_printer_DW.TriggeredSinglePulse1_o,
    &SPERTE_printer_P.TriggeredSinglePulse1_o);

  /* End of Outputs for SubSystem: '<Root>/Triggered Single Pulse1' */
  /* End of Outputs for SubSystem: '<Root>/Triggered Single Pulse1' */

  /* UnitDelay: '<S14>/Unit Delay1' */
  SPERTE_printer_B.UnitDelay1 = SPERTE_printer_DW.UnitDelay1_DSTATE;

  /* Logic: '<Root>/AND' */
  rtb_AND = ((SPERTE_printer_B.TriggeredSinglePulse1_o.Product3 != 0.0) &&
             SPERTE_printer_B.UnitDelay1);

  /* Outputs for Atomic SubSystem: '<Root>/Triggered Single Pulse' */
  /* Outputs for Atomic SubSystem: '<Root>/Triggered Single Pulse' */
  SPERTE_pr_TriggeredSinglePulse1(rtb_AND,
    SPERTE_printer_P.TriggeredSinglePulse_p_wid_a,
    &SPERTE_printer_B.TriggeredSinglePulse,
    &SPERTE_printer_DW.TriggeredSinglePulse,
    &SPERTE_printer_P.TriggeredSinglePulse);

  /* End of Outputs for SubSystem: '<Root>/Triggered Single Pulse' */
  /* End of Outputs for SubSystem: '<Root>/Triggered Single Pulse' */

  /* Outputs for Enabled SubSystem: '<Root>/Reference' incorporates:
   *  EnablePort: '<S4>/Enable'
   */
  if (SPERTE_printer_B.TriggeredSinglePulse.Product3 > 0.0) {
    if (!SPERTE_printer_DW.Reference_MODE) {
      /* InitializeConditions for Memory: '<S4>/Memory' */
      SPERTE_printer_DW.Memory_PreviousInput =
        SPERTE_printer_P.Memory_InitialCondition_i;
      SPERTE_printer_DW.Reference_MODE = true;
    }

    /* Sum: '<S4>/Sum1' incorporates:
     *  Constant: '<S4>/One'
     *  Memory: '<S4>/Memory'
     */
    SPERTE_printer_B.Sum1 = SPERTE_printer_DW.Memory_PreviousInput +
      SPERTE_printer_P.One_Value_f;

    /* LookupNDDirect: '<S4>/Direct Lookup Table ref' incorporates:
     *  Sum: '<S4>/Sum1'
     *
     * About '<S4>/Direct Lookup Table ref':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     *   */
    if (SPERTE_printer_B.Sum1 > 4500.0) {
      rtb_Product1 = 4500.0;
    } else if (SPERTE_printer_B.Sum1 < 0.0) {
      rtb_Product1 = 0.0;
    } else {
      rtb_Product1 = SPERTE_printer_B.Sum1;
    }

    /* LookupNDDirect: '<S4>/Direct Lookup Table ref' incorporates:
     *  Constant: '<S4>/set_Ref'
     *
     * About '<S4>/Direct Lookup Table ref':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     *   */
    SPERTE_printer_B.DirectLookupTableref = SPERTE_printer_P.set_Ref_Value
      [(int32_T)rtb_Product1];

    /* RelationalOperator: '<S28>/Compare' incorporates:
     *  Constant: '<S28>/Constant'
     */
    SPERTE_printer_B.Compare = (SPERTE_printer_B.Sum1 >= SPERTE_printer_P._const);

    /* LookupNDDirect: '<S4>/Direct Lookup Table ff' incorporates:
     *  Sum: '<S4>/Sum1'
     *
     * About '<S4>/Direct Lookup Table ff':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     *   */
    if (SPERTE_printer_B.Sum1 > 4500.0) {
      rtb_Product1 = 4500.0;
    } else if (SPERTE_printer_B.Sum1 < 0.0) {
      rtb_Product1 = 0.0;
    } else {
      rtb_Product1 = SPERTE_printer_B.Sum1;
    }

    /* LookupNDDirect: '<S4>/Direct Lookup Table ff' incorporates:
     *  Constant: '<S4>/set_ff'
     *
     * About '<S4>/Direct Lookup Table ff':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     *   */
    SPERTE_printer_B.DirectLookupTableff = SPERTE_printer_P.set_ff_Value
      [(int32_T)rtb_Product1];

    /* Update for Memory: '<S4>/Memory' */
    SPERTE_printer_DW.Memory_PreviousInput = SPERTE_printer_B.Sum1;
    srUpdateBC(SPERTE_printer_DW.Reference_SubsysRanBC);
  } else {
    SPERTE_printer_DW.Reference_MODE = false;
  }

  /* End of Outputs for SubSystem: '<Root>/Reference' */

  /* Sum: '<Root>/Sum2' */
  rtb_Sum2 = SPERTE_printer_B.DirectLookupTableref -
    SPERTE_printer_B.CountstoMeter1;

  /* Gain: '<S3>/Gain' */
  SPERTE_printer_B.Gain_c = SPERTE_printer_P.Gain_Gain_j * rtb_Sum2;

  /* S-Function (dpd): '<S3>/Dctpd' */

  /* Level2 S-Function Block: '<S3>/Dctpd' (dpd) */
  {
    SimStruct *rts = SPERTE_printer_M->childSfunctions[2];
    sfcnOutputs(rts,0);
  }

  /* S-Function (dlowpass2): '<S3>/Dct2lowpass' */

  /* Level2 S-Function Block: '<S3>/Dct2lowpass' (dlowpass2) */
  {
    SimStruct *rts = SPERTE_printer_M->childSfunctions[3];
    sfcnOutputs(rts,0);
  }

  /* Sum: '<Root>/Sum4' */
  rtb_Sum4 = SPERTE_printer_B.DirectLookupTableff + SPERTE_printer_B.Dct2lowpass;

  /* Logic: '<S14>/NOT' */
  rtb_NOT = !(SPERTE_printer_B.homeControllerEnabled != 0.0);

  /* DiscreteIntegrator: '<S14>/Discrete-Time Integrator' */
  if (rtb_NOT || (SPERTE_printer_DW.DiscreteTimeIntegrator_PrevRese != 0)) {
    SPERTE_printer_DW.DiscreteTimeIntegrator_DSTATE =
      SPERTE_printer_P.DiscreteTimeIntegrator_IC;
  }

  /* Outputs for Resettable SubSystem: '<S14>/Homing reference' incorporates:
   *  ResetPort: '<S19>/Reset'
   */
  if (rt_ZCFcn(RISING_ZERO_CROSSING,
               &SPERTE_printer_PrevZCX.Homingreference_Reset_ZCE,
               (SPERTE_printer_B.RateTransition5)) != NO_ZCEVENT) {
    /* InitializeConditions for Sum: '<S19>/Sum1' incorporates:
     *  Memory: '<S19>/Memory'
     */
    SPERTE_printer_DW.Memory_PreviousInput_g =
      SPERTE_printer_P.Memory_InitialCondition;
  }

  /* Sum: '<S19>/Sum1' incorporates:
   *  Constant: '<S19>/One'
   *  Memory: '<S19>/Memory'
   */
  SPERTE_printer_DW.Memory_PreviousInput_g += SPERTE_printer_P.One_Value;

  /* LookupNDDirect: '<S19>/Direct Lookup Table ref' incorporates:
   *  Sum: '<S19>/Sum1'
   *
   * About '<S19>/Direct Lookup Table ref':
   *  1-dimensional Direct Look-Up returning a Scalar,
   *
   *     Remove protection against out-of-range input in generated code: 'off'
   *   */
  if (SPERTE_printer_DW.Memory_PreviousInput_g > 599.0) {
    rtb_Product1 = 599.0;
  } else if (SPERTE_printer_DW.Memory_PreviousInput_g < 0.0) {
    rtb_Product1 = 0.0;
  } else {
    rtb_Product1 = SPERTE_printer_DW.Memory_PreviousInput_g;
  }

  /* Sum: '<S14>/Sum' incorporates:
   *  Constant: '<S19>/homing_ref'
   *  DiscreteIntegrator: '<S14>/Discrete-Time Integrator'
   *  LookupNDDirect: '<S19>/Direct Lookup Table ref'
   *  Product: '<S19>/Product'
   *
   * About '<S19>/Direct Lookup Table ref':
   *  1-dimensional Direct Look-Up returning a Scalar,
   *
   *     Remove protection against out-of-range input in generated code: 'off'
   *   */
  rtb_Product1 = SPERTE_printer_B.toPoint * SPERTE_printer_P.homing_ref_Value
    [(int32_T)rtb_Product1] + SPERTE_printer_DW.DiscreteTimeIntegrator_DSTATE;

  /* End of Outputs for SubSystem: '<S14>/Homing reference' */

  /* SampleTimeMath: '<S24>/TSamp'
   *
   * About '<S24>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *   */
  rtb_TSamp = rtb_Product1 * SPERTE_printer_P.TSamp_WtEt;

  /* Gain: '<S22>/Gain1' incorporates:
   *  Sum: '<S14>/Sum2'
   */
  SPERTE_printer_B.Gain1 = (rtb_Product1 - SPERTE_printer_B.CountstoMeter1) *
    SPERTE_printer_P.Gain1_Gain;

  /* S-Function (dpd): '<S22>/Dctpd2' */

  /* Level2 S-Function Block: '<S22>/Dctpd2' (dpd) */
  {
    SimStruct *rts = SPERTE_printer_M->childSfunctions[4];
    sfcnOutputs(rts,0);
  }

  /* S-Function (dlowpass2): '<S22>/Dct2lowpass3' */

  /* Level2 S-Function Block: '<S22>/Dct2lowpass3' (dlowpass2) */
  {
    SimStruct *rts = SPERTE_printer_M->childSfunctions[5];
    sfcnOutputs(rts,0);
  }

  /* DataTypeConversion: '<S22>/Cast To Double' */
  SPERTE_printer_B.CastToDouble = rtb_NOT;

  /* S-Function (dweakint_resettable): '<S22>/Dctintegrator1' */

  /* Level2 S-Function Block: '<S22>/Dctintegrator1' (dweakint_resettable) */
  {
    SimStruct *rts = SPERTE_printer_M->childSfunctions[6];
    sfcnOutputs(rts,0);
  }

  /* Gain: '<S21>/Gain1' incorporates:
   *  Sum: '<S14>/Sum1'
   */
  SPERTE_printer_B.Gain1_j = (SPERTE_printer_B.airBagRef -
    SPERTE_printer_B.CountstoMeter1) * SPERTE_printer_P.Gain1_Gain_j;

  /* S-Function (dpd): '<S21>/Dctpd2' */

  /* Level2 S-Function Block: '<S21>/Dctpd2' (dpd) */
  {
    SimStruct *rts = SPERTE_printer_M->childSfunctions[7];
    sfcnOutputs(rts,0);
  }

  /* S-Function (dlowpass2): '<S21>/Dct2lowpass3' */

  /* Level2 S-Function Block: '<S21>/Dct2lowpass3' (dlowpass2) */
  {
    SimStruct *rts = SPERTE_printer_M->childSfunctions[8];
    sfcnOutputs(rts,0);
  }

  /* Switch: '<S14>/AirbagSwitch' incorporates:
   *  Logic: '<S14>/Logical Operator1'
   */
  if (!(SPERTE_printer_B.airBagEnabled != 0.0)) {
    /* Switch: '<S14>/Homing Running Switch' incorporates:
     *  Constant: '<S23>/Constant'
     *  Gain: '<S18>/sign(v) BF'
     *  Product: '<S14>/Product'
     *  RelationalOperator: '<S23>/Compare'
     *  Signum: '<S18>/Sign'
     *  Sum: '<S14>/Sum7'
     */
    if (SPERTE_printer_B.homingBusy >=
        SPERTE_printer_P.HomingRunningSwitch_Threshold) {
      /* Sum: '<S24>/Diff' incorporates:
       *  UnitDelay: '<S24>/UD'
       */
      rtb_Product1 = rtb_TSamp - SPERTE_printer_DW.UD_DSTATE;

      /* Signum: '<S18>/Sign' */
      if (rtIsNaN(rtb_Product1)) {
        rtb_Product1 = (rtNaN);
      } else if (rtb_Product1 < 0.0) {
        rtb_Product1 = -1.0;
      } else {
        rtb_Product1 = (rtb_Product1 > 0.0);
      }

      rtb_Product1 = ((real_T)((rtb_Product1 >
        SPERTE_printer_P.CompareToConstant_const) *
        SPERTE_printer_P.signvBF_Gain) * 0.0078125 +
                      SPERTE_printer_B.Dctintegrator1) *
        SPERTE_printer_B.homeControllerEnabled;
    } else {
      rtb_Product1 = rtb_Sum4;
    }

    /* End of Switch: '<S14>/Homing Running Switch' */
  } else {
    rtb_Product1 = SPERTE_printer_B.Dct2lowpass3_o;
  }

  /* End of Switch: '<S14>/AirbagSwitch' */

  /* Product: '<S14>/Product1' */
  rtb_Product1 *= SPERTE_printer_B.controlEnabled;

  /* Saturate: '<S13>/Saturation' */
  if (rtb_Product1 > SPERTE_printer_P.Saturation_UpperSat) {
    rtb_Product1 = SPERTE_printer_P.Saturation_UpperSat;
  } else if (rtb_Product1 < SPERTE_printer_P.Saturation_LowerSat) {
    rtb_Product1 = SPERTE_printer_P.Saturation_LowerSat;
  }

  /* Saturate: '<S16>/Saturation' */
  if (rtb_Product1 > SPERTE_printer_P.Saturation_UpperSat_l) {
    /* Saturate: '<S16>/Saturation' */
    SPERTE_printer_B.Saturation[0] = SPERTE_printer_P.Saturation_UpperSat_l;
  } else if (rtb_Product1 < SPERTE_printer_P.Saturation_LowerSat_o) {
    /* Saturate: '<S16>/Saturation' */
    SPERTE_printer_B.Saturation[0] = SPERTE_printer_P.Saturation_LowerSat_o;
  } else {
    /* Saturate: '<S16>/Saturation' */
    SPERTE_printer_B.Saturation[0] = rtb_Product1;
  }

  /* Saturate: '<S13>/Saturation' incorporates:
   *  Constant: '<S13>/Constant2'
   */
  if (SPERTE_printer_P.Constant2_Value > SPERTE_printer_P.Saturation_UpperSat) {
    rtb_Product1 = SPERTE_printer_P.Saturation_UpperSat;
  } else if (SPERTE_printer_P.Constant2_Value <
             SPERTE_printer_P.Saturation_LowerSat) {
    rtb_Product1 = SPERTE_printer_P.Saturation_LowerSat;
  } else {
    rtb_Product1 = SPERTE_printer_P.Constant2_Value;
  }

  /* Saturate: '<S16>/Saturation' */
  if (rtb_Product1 > SPERTE_printer_P.Saturation_UpperSat_l) {
    /* Saturate: '<S16>/Saturation' */
    SPERTE_printer_B.Saturation[1] = SPERTE_printer_P.Saturation_UpperSat_l;
  } else if (rtb_Product1 < SPERTE_printer_P.Saturation_LowerSat_o) {
    /* Saturate: '<S16>/Saturation' */
    SPERTE_printer_B.Saturation[1] = SPERTE_printer_P.Saturation_LowerSat_o;
  } else {
    /* Saturate: '<S16>/Saturation' */
    SPERTE_printer_B.Saturation[1] = rtb_Product1;
  }

  /* Outputs for Atomic SubSystem: '<Root>/Measurement' */
  /* Outputs for Atomic SubSystem: '<S1>/Triggered Single Pulse' */
  /* Outputs for Atomic SubSystem: '<S1>/Triggered Single Pulse' */
  SPERTE_pri_TriggeredSinglePulse(SPERTE_printer_B.TriggeredSinglePulse.Product3,
    SPERTE_printer_P.TriggeredSinglePulse_p_wid,
    &SPERTE_printer_B.TriggeredSinglePulse_j,
    &SPERTE_printer_DW.TriggeredSinglePulse_j,
    &SPERTE_printer_P.TriggeredSinglePulse_j);

  /* End of Outputs for SubSystem: '<S1>/Triggered Single Pulse' */
  /* End of Outputs for SubSystem: '<S1>/Triggered Single Pulse' */

  /* DataTypeConversion: '<S1>/Data Type Conversion' */
  rtb_Product1 = floor(SPERTE_printer_B.TriggeredSinglePulse_j.Product3);
  if (rtIsNaN(rtb_Product1) || rtIsInf(rtb_Product1)) {
    rtb_Product1 = 0.0;
  } else {
    rtb_Product1 = fmod(rtb_Product1, 256.0);
  }

  /* DataTypeConversion: '<S1>/Data Type Conversion' */
  DataTypeConversion = (uint8_T)(rtb_Product1 < 0.0 ? (int32_T)(uint8_T)-(int8_T)
    (uint8_T)-rtb_Product1 : (int32_T)(uint8_T)rtb_Product1);

  /* MATLAB Function: '<S7>/SPERTE_measurement_function' incorporates:
   *  Constant: '<S7>/SPERTE_measurement_samples'
   *  Constant: '<S7>/SPERTE_measurement_trigger_command'
   *  SignalConversion generated from: '<S9>/ SFunction '
   */
  SPERTE_printer_DW.sfEvent_h = SPERTE_printer_CALL_EVENT;
  if ((((SPERTE_printer_P.MeasurementBlock_triggertype == 0) &&
        (DataTypeConversion == 1)) ||
       ((SPERTE_printer_P.MeasurementBlock_triggertype == 1) &&
        (SPERTE_printer_P.MeasurementBlock_trigger_comman == 1)) ||
       ((SPERTE_printer_P.MeasurementBlock_triggertype == 2) &&
        ((SPERTE_printer_P.MeasurementBlock_trigger_comman == 1) ||
         (DataTypeConversion == 1)))) && (SPERTE_printer_DW.busy != 1)) {
    nbytes = (int32_T)snprintf(NULL, 0, "measurement_%d.bin",
      SPERTE_printer_DW.NF) + 1;
    SPERTE_printer_emxInit_char_T(&str, 2);
    tmp = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = nbytes;
    SPERTE_emxEnsureCapacity_char_T(str, tmp);
    snprintf(&str->data[0], (size_t)nbytes, "measurement_%d.bin",
             SPERTE_printer_DW.NF);
    if (nbytes - 1 < 1) {
      nbytes = -1;
    } else {
      nbytes -= 2;
    }

    SPERTE_printer_emxInit_char_T(&str_0, 2);
    tmp = str_0->size[0] * str_0->size[1];
    str_0->size[0] = 1;
    str_0->size[1] = nbytes + 1;
    SPERTE_emxEnsureCapacity_char_T(str_0, tmp);
    if (nbytes >= 0) {
      memcpy(&str_0->data[0], &str->data[0], (uint32_T)(nbytes + 1) * sizeof
             (char_T));
    }

    SPERTE_printer_emxFree_char_T(&str);
    b_fileid = SPERTE_printer_cfopen(str_0, "wb");
    SPERTE_printer_emxFree_char_T(&str_0);
    SPERTE_printer_DW.fileID = b_fileid;
    nbytes = SPERTE_printer_DW.NF + 1;
    if (SPERTE_printer_DW.NF + 1 > 32767) {
      nbytes = 32767;
    }

    SPERTE_printer_DW.NF = (int16_T)nbytes;
    SPERTE_printer_DW.busy = 1U;
    SPERTE_printer_DW.NS = 0U;
  }

  if (SPERTE_printer_DW.busy == 1) {
    if (SPERTE_printer_DW.NS < SPERTE_printer_P.MeasurementBlock_N_samples) {
      b_fileid = (int8_T)SPERTE_printer_DW.fileID;
      if (((int8_T)SPERTE_printer_DW.fileID < 0) || (SPERTE_printer_DW.fileID !=
           (int8_T)SPERTE_printer_DW.fileID)) {
        b_fileid = -1;
      }

      if (b_fileid >= 3) {
        autoflush = SPERTE_printer_DW.eml_autoflush[b_fileid - 3];
        f = SPERTE_printer_DW.eml_openfiles[b_fileid - 3];
      } else if (b_fileid == 0) {
        f = stdin;
        autoflush = true;
      } else if (b_fileid == 1) {
        f = stdout;
        autoflush = true;
      } else if (b_fileid == 2) {
        f = stderr;
        autoflush = true;
      } else {
        f = NULL;
        autoflush = true;
      }

      if (!(SPERTE_printer_DW.fileID != 0.0)) {
        f = NULL;
      }

      if (!(f == NULL)) {
        xout[0] = (real32_T)SPERTE_printer_B.Sum1;
        xout[1] = (real32_T)rtb_Sum4;
        xout[2] = (real32_T)rtb_Sum2;
        xout[3] = (real32_T)SPERTE_printer_B.DirectLookupTableref;
        bytesOutSizet = fwrite(&xout[0], sizeof(real32_T), (size_t)4, f);
        if (((real_T)bytesOutSizet > 0.0) && autoflush) {
          fflush(f);
        }
      }

      SPERTE_printer_DW.NS++;
    } else {
      SPERTE_printer_cfclose(SPERTE_printer_DW.fileID);
      SPERTE_printer_DW.busy = 0U;
      SPERTE_printer_DW.NS = 0U;
    }
  }

  SPERTE_printer_B.status = SPERTE_printer_DW.busy;

  /* End of MATLAB Function: '<S7>/SPERTE_measurement_function' */
  /* End of Outputs for SubSystem: '<Root>/Measurement' */
  /* Logic: '<S14>/Logical Operator2' */
  SPERTE_printer_B.LogicalOperator2 = !(SPERTE_printer_B.controlEnabled != 0.0);

  /* Logic: '<S14>/Logical Operator3' */
  rtb_LogicalOperator3 = !(SPERTE_printer_B.homingBusy != 0.0);

  /* S-Function (ec_EboxResetEnc): '<S14>/Reset Encoder' */

  /* Level2 S-Function Block: '<S14>/Reset Encoder' (ec_EboxResetEnc) */
  {
    SimStruct *rts = SPERTE_printer_M->childSfunctions[9];
    sfcnOutputs(rts,0);
  }

  /* Clock: '<Root>/Clock' */
  SPERTE_printer_B.Clock = SPERTE_printer_M->Timing.t[0];

  /* Update for UnitDelay: '<S2>/Unit Delay' */
  SPERTE_printer_DW.UnitDelay_DSTATE = SPERTE_printer_B.Compare;

  /* Update for UnitDelay: '<S14>/Unit Delay1' */
  SPERTE_printer_DW.UnitDelay1_DSTATE = rtb_LogicalOperator3;

  /* Update for DiscreteIntegrator: '<S14>/Discrete-Time Integrator' */
  SPERTE_printer_DW.DiscreteTimeIntegrator_DSTATE +=
    SPERTE_printer_P.DiscreteTimeIntegrator_gainval * SPERTE_printer_B.jogSpeed;
  SPERTE_printer_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)rtb_NOT;

  /* Update for UnitDelay: '<S24>/UD' */
  SPERTE_printer_DW.UD_DSTATE = rtb_TSamp;

  {                                    /* Sample time: [0.001s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T extmodeTime = (extmodeSimulationTime_T)
      SPERTE_printer_M->Timing.t[1];

    /* Trigger External Mode event */
    errorCode = extmodeEvent(1, extmodeTime);
    if (errorCode != EXTMODE_SUCCESS) {
      /* Code to handle External Mode event errors
         may be added here */
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++SPERTE_printer_M->Timing.clockTick0)) {
    ++SPERTE_printer_M->Timing.clockTickH0;
  }

  SPERTE_printer_M->Timing.t[0] = SPERTE_printer_M->Timing.clockTick0 *
    SPERTE_printer_M->Timing.stepSize0 + SPERTE_printer_M->Timing.clockTickH0 *
    SPERTE_printer_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++SPERTE_printer_M->Timing.clockTick1)) {
      ++SPERTE_printer_M->Timing.clockTickH1;
    }

    SPERTE_printer_M->Timing.t[1] = SPERTE_printer_M->Timing.clockTick1 *
      SPERTE_printer_M->Timing.stepSize1 + SPERTE_printer_M->Timing.clockTickH1 *
      SPERTE_printer_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Model initialize function */
void SPERTE_printer_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)SPERTE_printer_M, 0,
                sizeof(RT_MODEL_SPERTE_printer_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&SPERTE_printer_M->solverInfo,
                          &SPERTE_printer_M->Timing.simTimeStep);
    rtsiSetTPtr(&SPERTE_printer_M->solverInfo, &rtmGetTPtr(SPERTE_printer_M));
    rtsiSetStepSizePtr(&SPERTE_printer_M->solverInfo,
                       &SPERTE_printer_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&SPERTE_printer_M->solverInfo, (&rtmGetErrorStatus
      (SPERTE_printer_M)));
    rtsiSetRTModelPtr(&SPERTE_printer_M->solverInfo, SPERTE_printer_M);
  }

  rtsiSetSimTimeStep(&SPERTE_printer_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&SPERTE_printer_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&SPERTE_printer_M->solverInfo, false);
  rtsiSetSolverName(&SPERTE_printer_M->solverInfo,"FixedStepDiscrete");
  SPERTE_printer_M->solverInfoPtr = (&SPERTE_printer_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = SPERTE_printer_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    SPERTE_printer_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    SPERTE_printer_M->Timing.sampleTimes =
      (&SPERTE_printer_M->Timing.sampleTimesArray[0]);
    SPERTE_printer_M->Timing.offsetTimes =
      (&SPERTE_printer_M->Timing.offsetTimesArray[0]);

    /* task periods */
    SPERTE_printer_M->Timing.sampleTimes[0] = (0.0);
    SPERTE_printer_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    SPERTE_printer_M->Timing.offsetTimes[0] = (0.0);
    SPERTE_printer_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(SPERTE_printer_M, &SPERTE_printer_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = SPERTE_printer_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    SPERTE_printer_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(SPERTE_printer_M, -1);
  SPERTE_printer_M->Timing.stepSize0 = 0.001;
  SPERTE_printer_M->Timing.stepSize1 = 0.001;

  /* External mode info */
  SPERTE_printer_M->Sizes.checksums[0] = (3854718624U);
  SPERTE_printer_M->Sizes.checksums[1] = (3059125798U);
  SPERTE_printer_M->Sizes.checksums[2] = (1639568766U);
  SPERTE_printer_M->Sizes.checksums[3] = (263776998U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[12];
    SPERTE_printer_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = (sysRanDType *)&SPERTE_printer_DW.Reference_SubsysRanBC;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(SPERTE_printer_M->extModeInfo,
      &SPERTE_printer_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(SPERTE_printer_M->extModeInfo,
                        SPERTE_printer_M->Sizes.checksums);
    rteiSetTPtr(SPERTE_printer_M->extModeInfo, rtmGetTPtr(SPERTE_printer_M));
  }

  SPERTE_printer_M->solverInfoPtr = (&SPERTE_printer_M->solverInfo);
  SPERTE_printer_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&SPERTE_printer_M->solverInfo, 0.001);
  rtsiSetSolverMode(&SPERTE_printer_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  (void) memset(((void *) &SPERTE_printer_B), 0,
                sizeof(B_SPERTE_printer_T));

  {
    SPERTE_printer_B.SupervisorMode = SupervisorModeType_None;
  }

  /* states (dwork) */
  (void) memset((void *)&SPERTE_printer_DW, 0,
                sizeof(DW_SPERTE_printer_T));

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &SPERTE_printer_M->NonInlinedSFcns.sfcnInfo;
    SPERTE_printer_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(SPERTE_printer_M)));
    SPERTE_printer_M->Sizes.numSampTimes = (2);
    rtssSetNumRootSampTimesPtr(sfcnInfo, &SPERTE_printer_M->Sizes.numSampTimes);
    SPERTE_printer_M->NonInlinedSFcns.taskTimePtrs[0] = (&rtmGetTPtr
      (SPERTE_printer_M)[0]);
    SPERTE_printer_M->NonInlinedSFcns.taskTimePtrs[1] = (&rtmGetTPtr
      (SPERTE_printer_M)[1]);
    rtssSetTPtrPtr(sfcnInfo,SPERTE_printer_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(SPERTE_printer_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(SPERTE_printer_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (SPERTE_printer_M));
    rtssSetStepSizePtr(sfcnInfo, &SPERTE_printer_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(SPERTE_printer_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &SPERTE_printer_M->derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo, &SPERTE_printer_M->zCCacheNeedsReset);
    rtssSetContTimeOutputInconsistentWithStateAtMajorStepPtr(sfcnInfo,
      &SPERTE_printer_M->CTOutputIncnstWithState);
    rtssSetSampleHitsPtr(sfcnInfo, &SPERTE_printer_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &SPERTE_printer_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &SPERTE_printer_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &SPERTE_printer_M->solverInfoPtr);
  }

  SPERTE_printer_M->Sizes.numSFcns = (10);

  /* register each child */
  {
    (void) memset((void *)&SPERTE_printer_M->NonInlinedSFcns.childSFunctions[0],
                  0,
                  10*sizeof(SimStruct));
    SPERTE_printer_M->childSfunctions =
      (&SPERTE_printer_M->NonInlinedSFcns.childSFunctionPtrs[0]);

    {
      int_T i;
      for (i = 0; i < 10; i++) {
        SPERTE_printer_M->childSfunctions[i] =
          (&SPERTE_printer_M->NonInlinedSFcns.childSFunctions[i]);
      }
    }

    /* Level2 S-Function Block: SPERTE_printer/<S17>/S-Function (ec_Supervisor) */
    {
      SimStruct *rts = SPERTE_printer_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = SPERTE_printer_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = SPERTE_printer_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = SPERTE_printer_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &SPERTE_printer_M->NonInlinedSFcns.blkInfo2[0]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &SPERTE_printer_M->NonInlinedSFcns.inputOutputPortInfo2[0]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, SPERTE_printer_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &SPERTE_printer_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &SPERTE_printer_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &SPERTE_printer_M->NonInlinedSFcns.methods4[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &SPERTE_printer_M->NonInlinedSFcns.statesInfo2[0]);
        ssSetPeriodicStatesInfo(rts,
          &SPERTE_printer_M->NonInlinedSFcns.periodicStatesInfo[0]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        ssSetPortInfoForOutputs(rts,
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn0.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn0.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &SPERTE_printer_B.SFunction));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts,
                "SPERTE_printer/Printer/E//BOX I-O/Ethercat Supervisor/S-Function");
      ssSetRTModel(rts,SPERTE_printer_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)SPERTE_printer_P.SFunction_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)SPERTE_printer_P.SFunction_P2_Size);
      }

      /* registration */
      ec_Supervisor(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: SPERTE_printer/<S16>/ec_Ebox (ec_Ebox) */
    {
      SimStruct *rts = SPERTE_printer_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = SPERTE_printer_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = SPERTE_printer_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = SPERTE_printer_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &SPERTE_printer_M->NonInlinedSFcns.blkInfo2[1]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &SPERTE_printer_M->NonInlinedSFcns.inputOutputPortInfo2[1]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, SPERTE_printer_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &SPERTE_printer_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &SPERTE_printer_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &SPERTE_printer_M->NonInlinedSFcns.methods4[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &SPERTE_printer_M->NonInlinedSFcns.statesInfo2[1]);
        ssSetPeriodicStatesInfo(rts,
          &SPERTE_printer_M->NonInlinedSFcns.periodicStatesInfo[1]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 3);
        ssSetPortInfoForInputs(rts,
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn1.inputPortInfo[0]);
        ssSetPortInfoForInputs(rts,
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn1.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn1.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        ssSetInputPortUnit(rts, 1, 0);
        ssSetInputPortUnit(rts, 2, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn1.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);
        ssSetInputPortIsContinuousQuantity(rts, 1, 0);
        ssSetInputPortIsContinuousQuantity(rts, 2, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &SPERTE_printer_M->NonInlinedSFcns.Sfcn1.UPtrs0;
          sfcnUPtrs[0] = SPERTE_printer_B.Saturation;
          sfcnUPtrs[1] = &SPERTE_printer_B.Saturation[1];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 2);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &SPERTE_printer_M->NonInlinedSFcns.Sfcn1.UPtrs1;
          sfcnUPtrs[0] = SPERTE_printer_B.Gain;
          sfcnUPtrs[1] = &SPERTE_printer_B.Gain[1];
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidthAsInt(rts, 1, 2);
        }

        /* port 2 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &SPERTE_printer_M->NonInlinedSFcns.Sfcn1.UPtrs2;
          sfcnUPtrs[0] = &SPERTE_printer_B.homeControllerEnabled;
          sfcnUPtrs[1] = &SPERTE_printer_B.homeControllerEnabled;
          sfcnUPtrs[2] = &SPERTE_printer_B.homeControllerEnabled;
          sfcnUPtrs[3] = &SPERTE_printer_B.homeControllerEnabled;
          sfcnUPtrs[4] = &SPERTE_printer_B.homeControllerEnabled;
          sfcnUPtrs[5] = &SPERTE_printer_B.homeControllerEnabled;
          sfcnUPtrs[6] = &SPERTE_printer_B.homeControllerEnabled;
          sfcnUPtrs[7] = &SPERTE_printer_B.homeControllerEnabled;
          ssSetInputPortSignalPtrs(rts, 2, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidthAsInt(rts, 2, 8);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn1.outputPortInfo[0]);
        ssSetPortInfoForOutputs(rts,
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn1.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 3);
        _ssSetPortInfo2ForOutputUnits(rts,
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn1.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        ssSetOutputPortUnit(rts, 1, 0);
        ssSetOutputPortUnit(rts, 2, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn1.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 1, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 2, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *) SPERTE_printer_B.ec_Ebox_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidthAsInt(rts, 1, 2);
          ssSetOutputPortSignal(rts, 1, ((real_T *) SPERTE_printer_B.ec_Ebox_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidthAsInt(rts, 2, 8);
          ssSetOutputPortSignal(rts, 2, ((real_T *) SPERTE_printer_B.ec_Ebox_o3));
        }
      }

      /* path info */
      ssSetModelName(rts, "ec_Ebox");
      ssSetPath(rts, "SPERTE_printer/Printer/E//BOX I-O/Ethercat E-box/ec_Ebox");
      ssSetRTModel(rts,SPERTE_printer_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)SPERTE_printer_P.ec_Ebox_P1_Size);
      }

      /* registration */
      ec_Ebox(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);
      _ssSetInputPortConnected(rts, 2, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 2, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);
      _ssSetOutputPortBeingMerged(rts, 2, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
      ssSetInputPortBufferDstPort(rts, 2, -1);
    }

    /* Level2 S-Function Block: SPERTE_printer/<S3>/Dctpd (dpd) */
    {
      SimStruct *rts = SPERTE_printer_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod = SPERTE_printer_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset = SPERTE_printer_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap = SPERTE_printer_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &SPERTE_printer_M->NonInlinedSFcns.blkInfo2[2]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &SPERTE_printer_M->NonInlinedSFcns.inputOutputPortInfo2[2]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, SPERTE_printer_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &SPERTE_printer_M->NonInlinedSFcns.methods2[2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &SPERTE_printer_M->NonInlinedSFcns.methods3[2]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &SPERTE_printer_M->NonInlinedSFcns.methods4[2]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &SPERTE_printer_M->NonInlinedSFcns.statesInfo2[2]);
        ssSetPeriodicStatesInfo(rts,
          &SPERTE_printer_M->NonInlinedSFcns.periodicStatesInfo[2]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn2.inputPortInfo[0]);
        ssSetPortInfoForInputs(rts,
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn2.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn2.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn2.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &SPERTE_printer_M->NonInlinedSFcns.Sfcn2.UPtrs0;
          sfcnUPtrs[0] = &SPERTE_printer_B.Gain_c;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn2.outputPortInfo[0]);
        ssSetPortInfoForOutputs(rts,
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn2.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn2.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn2.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &SPERTE_printer_B.Dctpd));
        }
      }

      /* path info */
      ssSetModelName(rts, "Dctpd");
      ssSetPath(rts, "SPERTE_printer/Printer Controller/Dctpd");
      ssSetRTModel(rts,SPERTE_printer_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 3);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)SPERTE_printer_P.Dctpd_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)SPERTE_printer_P.Dctpd_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)SPERTE_printer_P.Dctpd_P3_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &SPERTE_printer_DW.Dctpd_RWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn2.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn2.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        ssSetNumDWorkAsInt(rts, 1);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &SPERTE_printer_DW.Dctpd_RWORK[0]);
      }

      /* registration */
      dpd(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: SPERTE_printer/<S3>/Dct2lowpass (dlowpass2) */
    {
      SimStruct *rts = SPERTE_printer_M->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod = SPERTE_printer_M->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset = SPERTE_printer_M->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap = SPERTE_printer_M->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &SPERTE_printer_M->NonInlinedSFcns.blkInfo2[3]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &SPERTE_printer_M->NonInlinedSFcns.inputOutputPortInfo2[3]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, SPERTE_printer_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &SPERTE_printer_M->NonInlinedSFcns.methods2[3]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &SPERTE_printer_M->NonInlinedSFcns.methods3[3]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &SPERTE_printer_M->NonInlinedSFcns.methods4[3]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &SPERTE_printer_M->NonInlinedSFcns.statesInfo2[3]);
        ssSetPeriodicStatesInfo(rts,
          &SPERTE_printer_M->NonInlinedSFcns.periodicStatesInfo[3]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn3.inputPortInfo[0]);
        ssSetPortInfoForInputs(rts,
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn3.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn3.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn3.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &SPERTE_printer_M->NonInlinedSFcns.Sfcn3.UPtrs0;
          sfcnUPtrs[0] = &SPERTE_printer_B.Dctpd;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn3.outputPortInfo[0]);
        ssSetPortInfoForOutputs(rts,
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn3.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn3.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn3.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &SPERTE_printer_B.Dct2lowpass));
        }
      }

      /* path info */
      ssSetModelName(rts, "Dct2lowpass");
      ssSetPath(rts, "SPERTE_printer/Printer Controller/Dct2lowpass");
      ssSetRTModel(rts,SPERTE_printer_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn3.params;
        ssSetSFcnParamsCount(rts, 3);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)SPERTE_printer_P.Dct2lowpass_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)SPERTE_printer_P.Dct2lowpass_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)SPERTE_printer_P.Dct2lowpass_P3_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &SPERTE_printer_DW.Dct2lowpass_RWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn3.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn3.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        ssSetNumDWorkAsInt(rts, 1);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 4);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &SPERTE_printer_DW.Dct2lowpass_RWORK[0]);
      }

      /* registration */
      dlowpass2(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: SPERTE_printer/<S22>/Dctpd2 (dpd) */
    {
      SimStruct *rts = SPERTE_printer_M->childSfunctions[4];

      /* timing info */
      time_T *sfcnPeriod = SPERTE_printer_M->NonInlinedSFcns.Sfcn4.sfcnPeriod;
      time_T *sfcnOffset = SPERTE_printer_M->NonInlinedSFcns.Sfcn4.sfcnOffset;
      int_T *sfcnTsMap = SPERTE_printer_M->NonInlinedSFcns.Sfcn4.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &SPERTE_printer_M->NonInlinedSFcns.blkInfo2[4]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &SPERTE_printer_M->NonInlinedSFcns.inputOutputPortInfo2[4]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, SPERTE_printer_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &SPERTE_printer_M->NonInlinedSFcns.methods2[4]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &SPERTE_printer_M->NonInlinedSFcns.methods3[4]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &SPERTE_printer_M->NonInlinedSFcns.methods4[4]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &SPERTE_printer_M->NonInlinedSFcns.statesInfo2[4]);
        ssSetPeriodicStatesInfo(rts,
          &SPERTE_printer_M->NonInlinedSFcns.periodicStatesInfo[4]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn4.inputPortInfo[0]);
        ssSetPortInfoForInputs(rts,
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn4.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn4.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn4.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &SPERTE_printer_M->NonInlinedSFcns.Sfcn4.UPtrs0;
          sfcnUPtrs[0] = &SPERTE_printer_B.Gain1;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn4.outputPortInfo[0]);
        ssSetPortInfoForOutputs(rts,
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn4.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn4.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn4.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &SPERTE_printer_B.Dctpd2));
        }
      }

      /* path info */
      ssSetModelName(rts, "Dctpd2");
      ssSetPath(rts,
                "SPERTE_printer/Printer/Supervisory Controller/homingController/Dctpd2");
      ssSetRTModel(rts,SPERTE_printer_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn4.params;
        ssSetSFcnParamsCount(rts, 3);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)SPERTE_printer_P.Dctpd2_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)SPERTE_printer_P.Dctpd2_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)SPERTE_printer_P.Dctpd2_P3_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &SPERTE_printer_DW.Dctpd2_RWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn4.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn4.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        ssSetNumDWorkAsInt(rts, 1);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &SPERTE_printer_DW.Dctpd2_RWORK[0]);
      }

      /* registration */
      dpd(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: SPERTE_printer/<S22>/Dct2lowpass3 (dlowpass2) */
    {
      SimStruct *rts = SPERTE_printer_M->childSfunctions[5];

      /* timing info */
      time_T *sfcnPeriod = SPERTE_printer_M->NonInlinedSFcns.Sfcn5.sfcnPeriod;
      time_T *sfcnOffset = SPERTE_printer_M->NonInlinedSFcns.Sfcn5.sfcnOffset;
      int_T *sfcnTsMap = SPERTE_printer_M->NonInlinedSFcns.Sfcn5.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &SPERTE_printer_M->NonInlinedSFcns.blkInfo2[5]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &SPERTE_printer_M->NonInlinedSFcns.inputOutputPortInfo2[5]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, SPERTE_printer_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &SPERTE_printer_M->NonInlinedSFcns.methods2[5]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &SPERTE_printer_M->NonInlinedSFcns.methods3[5]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &SPERTE_printer_M->NonInlinedSFcns.methods4[5]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &SPERTE_printer_M->NonInlinedSFcns.statesInfo2[5]);
        ssSetPeriodicStatesInfo(rts,
          &SPERTE_printer_M->NonInlinedSFcns.periodicStatesInfo[5]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn5.inputPortInfo[0]);
        ssSetPortInfoForInputs(rts,
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn5.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn5.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn5.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &SPERTE_printer_M->NonInlinedSFcns.Sfcn5.UPtrs0;
          sfcnUPtrs[0] = &SPERTE_printer_B.Dctpd2;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn5.outputPortInfo[0]);
        ssSetPortInfoForOutputs(rts,
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn5.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn5.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn5.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &SPERTE_printer_B.Dct2lowpass3));
        }
      }

      /* path info */
      ssSetModelName(rts, "Dct2lowpass3");
      ssSetPath(rts,
                "SPERTE_printer/Printer/Supervisory Controller/homingController/Dct2lowpass3");
      ssSetRTModel(rts,SPERTE_printer_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn5.params;
        ssSetSFcnParamsCount(rts, 3);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)SPERTE_printer_P.Dct2lowpass3_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)SPERTE_printer_P.Dct2lowpass3_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)SPERTE_printer_P.Dct2lowpass3_P3_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &SPERTE_printer_DW.Dct2lowpass3_RWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn5.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn5.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        ssSetNumDWorkAsInt(rts, 1);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 4);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &SPERTE_printer_DW.Dct2lowpass3_RWORK[0]);
      }

      /* registration */
      dlowpass2(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: SPERTE_printer/<S22>/Dctintegrator1 (dweakint_resettable) */
    {
      SimStruct *rts = SPERTE_printer_M->childSfunctions[6];

      /* timing info */
      time_T *sfcnPeriod = SPERTE_printer_M->NonInlinedSFcns.Sfcn6.sfcnPeriod;
      time_T *sfcnOffset = SPERTE_printer_M->NonInlinedSFcns.Sfcn6.sfcnOffset;
      int_T *sfcnTsMap = SPERTE_printer_M->NonInlinedSFcns.Sfcn6.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &SPERTE_printer_M->NonInlinedSFcns.blkInfo2[6]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &SPERTE_printer_M->NonInlinedSFcns.inputOutputPortInfo2[6]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, SPERTE_printer_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &SPERTE_printer_M->NonInlinedSFcns.methods2[6]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &SPERTE_printer_M->NonInlinedSFcns.methods3[6]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &SPERTE_printer_M->NonInlinedSFcns.methods4[6]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &SPERTE_printer_M->NonInlinedSFcns.statesInfo2[6]);
        ssSetPeriodicStatesInfo(rts,
          &SPERTE_printer_M->NonInlinedSFcns.periodicStatesInfo[6]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn6.inputPortInfo[0]);
        ssSetPortInfoForInputs(rts,
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn6.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn6.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        ssSetInputPortUnit(rts, 1, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn6.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);
        ssSetInputPortIsContinuousQuantity(rts, 1, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &SPERTE_printer_M->NonInlinedSFcns.Sfcn6.UPtrs0;
          sfcnUPtrs[0] = &SPERTE_printer_B.Dct2lowpass3;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &SPERTE_printer_M->NonInlinedSFcns.Sfcn6.UPtrs1;
          sfcnUPtrs[0] = &SPERTE_printer_B.CastToDouble;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidthAsInt(rts, 1, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn6.outputPortInfo[0]);
        ssSetPortInfoForOutputs(rts,
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn6.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn6.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn6.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &SPERTE_printer_B.Dctintegrator1));
        }
      }

      /* path info */
      ssSetModelName(rts, "Dctintegrator1");
      ssSetPath(rts,
                "SPERTE_printer/Printer/Supervisory Controller/homingController/Dctintegrator1");
      ssSetRTModel(rts,SPERTE_printer_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn6.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)SPERTE_printer_P.Dctintegrator1_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)SPERTE_printer_P.Dctintegrator1_P2_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &SPERTE_printer_DW.Dctintegrator1_RWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn6.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn6.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        ssSetNumDWorkAsInt(rts, 1);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &SPERTE_printer_DW.Dctintegrator1_RWORK[0]);
      }

      /* registration */
      dweakint_resettable(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
    }

    /* Level2 S-Function Block: SPERTE_printer/<S21>/Dctpd2 (dpd) */
    {
      SimStruct *rts = SPERTE_printer_M->childSfunctions[7];

      /* timing info */
      time_T *sfcnPeriod = SPERTE_printer_M->NonInlinedSFcns.Sfcn7.sfcnPeriod;
      time_T *sfcnOffset = SPERTE_printer_M->NonInlinedSFcns.Sfcn7.sfcnOffset;
      int_T *sfcnTsMap = SPERTE_printer_M->NonInlinedSFcns.Sfcn7.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &SPERTE_printer_M->NonInlinedSFcns.blkInfo2[7]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &SPERTE_printer_M->NonInlinedSFcns.inputOutputPortInfo2[7]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, SPERTE_printer_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &SPERTE_printer_M->NonInlinedSFcns.methods2[7]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &SPERTE_printer_M->NonInlinedSFcns.methods3[7]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &SPERTE_printer_M->NonInlinedSFcns.methods4[7]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &SPERTE_printer_M->NonInlinedSFcns.statesInfo2[7]);
        ssSetPeriodicStatesInfo(rts,
          &SPERTE_printer_M->NonInlinedSFcns.periodicStatesInfo[7]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn7.inputPortInfo[0]);
        ssSetPortInfoForInputs(rts,
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn7.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn7.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn7.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &SPERTE_printer_M->NonInlinedSFcns.Sfcn7.UPtrs0;
          sfcnUPtrs[0] = &SPERTE_printer_B.Gain1_j;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn7.outputPortInfo[0]);
        ssSetPortInfoForOutputs(rts,
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn7.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn7.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn7.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &SPERTE_printer_B.Dctpd2_k));
        }
      }

      /* path info */
      ssSetModelName(rts, "Dctpd2");
      ssSetPath(rts,
                "SPERTE_printer/Printer/Supervisory Controller/airbagController/Dctpd2");
      ssSetRTModel(rts,SPERTE_printer_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn7.params;
        ssSetSFcnParamsCount(rts, 3);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)SPERTE_printer_P.Dctpd2_P1_Size_b);
        ssSetSFcnParam(rts, 1, (mxArray*)SPERTE_printer_P.Dctpd2_P2_Size_l);
        ssSetSFcnParam(rts, 2, (mxArray*)SPERTE_printer_P.Dctpd2_P3_Size_g);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &SPERTE_printer_DW.Dctpd2_RWORK_p[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn7.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn7.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        ssSetNumDWorkAsInt(rts, 1);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &SPERTE_printer_DW.Dctpd2_RWORK_p[0]);
      }

      /* registration */
      dpd(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: SPERTE_printer/<S21>/Dct2lowpass3 (dlowpass2) */
    {
      SimStruct *rts = SPERTE_printer_M->childSfunctions[8];

      /* timing info */
      time_T *sfcnPeriod = SPERTE_printer_M->NonInlinedSFcns.Sfcn8.sfcnPeriod;
      time_T *sfcnOffset = SPERTE_printer_M->NonInlinedSFcns.Sfcn8.sfcnOffset;
      int_T *sfcnTsMap = SPERTE_printer_M->NonInlinedSFcns.Sfcn8.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &SPERTE_printer_M->NonInlinedSFcns.blkInfo2[8]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &SPERTE_printer_M->NonInlinedSFcns.inputOutputPortInfo2[8]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, SPERTE_printer_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &SPERTE_printer_M->NonInlinedSFcns.methods2[8]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &SPERTE_printer_M->NonInlinedSFcns.methods3[8]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &SPERTE_printer_M->NonInlinedSFcns.methods4[8]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &SPERTE_printer_M->NonInlinedSFcns.statesInfo2[8]);
        ssSetPeriodicStatesInfo(rts,
          &SPERTE_printer_M->NonInlinedSFcns.periodicStatesInfo[8]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn8.inputPortInfo[0]);
        ssSetPortInfoForInputs(rts,
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn8.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn8.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn8.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &SPERTE_printer_M->NonInlinedSFcns.Sfcn8.UPtrs0;
          sfcnUPtrs[0] = &SPERTE_printer_B.Dctpd2_k;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn8.outputPortInfo[0]);
        ssSetPortInfoForOutputs(rts,
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn8.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn8.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn8.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &SPERTE_printer_B.Dct2lowpass3_o));
        }
      }

      /* path info */
      ssSetModelName(rts, "Dct2lowpass3");
      ssSetPath(rts,
                "SPERTE_printer/Printer/Supervisory Controller/airbagController/Dct2lowpass3");
      ssSetRTModel(rts,SPERTE_printer_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn8.params;
        ssSetSFcnParamsCount(rts, 3);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)SPERTE_printer_P.Dct2lowpass3_P1_Size_f);
        ssSetSFcnParam(rts, 1, (mxArray*)SPERTE_printer_P.Dct2lowpass3_P2_Size_k);
        ssSetSFcnParam(rts, 2, (mxArray*)SPERTE_printer_P.Dct2lowpass3_P3_Size_j);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &SPERTE_printer_DW.Dct2lowpass3_RWORK_c[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn8.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn8.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        ssSetNumDWorkAsInt(rts, 1);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 4);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &SPERTE_printer_DW.Dct2lowpass3_RWORK_c[0]);
      }

      /* registration */
      dlowpass2(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: SPERTE_printer/<S14>/Reset Encoder (ec_EboxResetEnc) */
    {
      SimStruct *rts = SPERTE_printer_M->childSfunctions[9];

      /* timing info */
      time_T *sfcnPeriod = SPERTE_printer_M->NonInlinedSFcns.Sfcn9.sfcnPeriod;
      time_T *sfcnOffset = SPERTE_printer_M->NonInlinedSFcns.Sfcn9.sfcnOffset;
      int_T *sfcnTsMap = SPERTE_printer_M->NonInlinedSFcns.Sfcn9.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &SPERTE_printer_M->NonInlinedSFcns.blkInfo2[9]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &SPERTE_printer_M->NonInlinedSFcns.inputOutputPortInfo2[9]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, SPERTE_printer_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &SPERTE_printer_M->NonInlinedSFcns.methods2[9]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &SPERTE_printer_M->NonInlinedSFcns.methods3[9]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &SPERTE_printer_M->NonInlinedSFcns.methods4[9]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &SPERTE_printer_M->NonInlinedSFcns.statesInfo2[9]);
        ssSetPeriodicStatesInfo(rts,
          &SPERTE_printer_M->NonInlinedSFcns.periodicStatesInfo[9]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn9.inputPortInfo[0]);
        ssSetPortInfoForInputs(rts,
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn9.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn9.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn9.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &SPERTE_printer_M->NonInlinedSFcns.Sfcn9.UPtrs0;
          sfcnUPtrs[0] = &SPERTE_printer_B.resetEnc;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Reset Encoder");
      ssSetPath(rts,
                "SPERTE_printer/Printer/Supervisory Controller/Reset Encoder");
      ssSetRTModel(rts,SPERTE_printer_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &SPERTE_printer_M->NonInlinedSFcns.Sfcn9.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)SPERTE_printer_P.ResetEncoder_P1_Size);
      }

      /* registration */
      ec_EboxResetEnc(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }
  }

  /* Start for S-Function (ec_Supervisor): '<S17>/S-Function' */
  /* Level2 S-Function Block: '<S17>/S-Function' (ec_Supervisor) */
  {
    SimStruct *rts = SPERTE_printer_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for Enabled SubSystem: '<Root>/Reference' */
  SPERTE_printer_DW.Reference_MODE = false;

  /* Start for S-Function (dpd): '<S3>/Dctpd' */
  /* Level2 S-Function Block: '<S3>/Dctpd' (dpd) */
  {
    SimStruct *rts = SPERTE_printer_M->childSfunctions[2];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (dlowpass2): '<S3>/Dct2lowpass' */
  /* Level2 S-Function Block: '<S3>/Dct2lowpass' (dlowpass2) */
  {
    SimStruct *rts = SPERTE_printer_M->childSfunctions[3];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (dpd): '<S22>/Dctpd2' */
  /* Level2 S-Function Block: '<S22>/Dctpd2' (dpd) */
  {
    SimStruct *rts = SPERTE_printer_M->childSfunctions[4];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (dlowpass2): '<S22>/Dct2lowpass3' */
  /* Level2 S-Function Block: '<S22>/Dct2lowpass3' (dlowpass2) */
  {
    SimStruct *rts = SPERTE_printer_M->childSfunctions[5];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (dweakint_resettable): '<S22>/Dctintegrator1' */
  /* Level2 S-Function Block: '<S22>/Dctintegrator1' (dweakint_resettable) */
  {
    SimStruct *rts = SPERTE_printer_M->childSfunctions[6];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (dpd): '<S21>/Dctpd2' */
  /* Level2 S-Function Block: '<S21>/Dctpd2' (dpd) */
  {
    SimStruct *rts = SPERTE_printer_M->childSfunctions[7];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (dlowpass2): '<S21>/Dct2lowpass3' */
  /* Level2 S-Function Block: '<S21>/Dct2lowpass3' (dlowpass2) */
  {
    SimStruct *rts = SPERTE_printer_M->childSfunctions[8];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  SPERTE_printer_PrevZCX.Homingreference_Reset_ZCE = UNINITIALIZED_ZCSIG;

  {
    int32_T i;

    /* InitializeConditions for UnitDelay: '<S2>/Unit Delay' */
    SPERTE_printer_DW.UnitDelay_DSTATE =
      SPERTE_printer_P.UnitDelay_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S14>/Unit Delay1' */
    SPERTE_printer_DW.UnitDelay1_DSTATE =
      SPERTE_printer_P.UnitDelay1_InitialCondition;

    /* InitializeConditions for DiscreteIntegrator: '<S14>/Discrete-Time Integrator' */
    SPERTE_printer_DW.DiscreteTimeIntegrator_DSTATE =
      SPERTE_printer_P.DiscreteTimeIntegrator_IC;
    SPERTE_printer_DW.DiscreteTimeIntegrator_PrevRese = 0;

    /* InitializeConditions for UnitDelay: '<S24>/UD' */
    SPERTE_printer_DW.UD_DSTATE =
      SPERTE_printer_P.DiscreteDerivative_ICPrevScaled;

    /* SystemInitialize for Atomic SubSystem: '<S2>/Triggered Single Pulse1' */
    SPER_TriggeredSinglePulse1_Init(&SPERTE_printer_DW.TriggeredSinglePulse1,
      &SPERTE_printer_P.TriggeredSinglePulse1);

    /* End of SystemInitialize for SubSystem: '<S2>/Triggered Single Pulse1' */

    /* SystemInitialize for Chart: '<S14>/Supervisor' */
    SPERTE_printer_DW.temporalCounter_i1 = 0U;
    SPERTE_printer_DW.sfEvent = SPERTE_printer_CALL_EVENT;
    SPERTE_printer_B.jogSpeed = 0.0;
    SPERTE_printer_B.toPoint = 0.0;
    SPERTE_printer_B.homeControllerEnabled = 0.0;
    SPERTE_printer_B.resetEnc = 0.0;
    SPERTE_printer_B.homingBusy = 1.0;
    SPERTE_printer_B.airBagEnabled = 0.0;
    SPERTE_printer_B.airBagRef = 0.0;
    SPERTE_printer_B.controlEnabled = 1.0;
    SPERTE_printer_DW.is_active_c1_SPERTE_printer = 0U;
    SPERTE_printer_B.SupervisorMode = SupervisorModeType_None;

    /* SystemInitialize for Atomic SubSystem: '<Root>/Triggered Single Pulse1' */
    SPERT_TriggeredSinglePulse_Init(&SPERTE_printer_DW.TriggeredSinglePulse1_o,
      &SPERTE_printer_P.TriggeredSinglePulse1_o);

    /* End of SystemInitialize for SubSystem: '<Root>/Triggered Single Pulse1' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/Triggered Single Pulse' */
    SPER_TriggeredSinglePulse1_Init(&SPERTE_printer_DW.TriggeredSinglePulse,
      &SPERTE_printer_P.TriggeredSinglePulse);

    /* End of SystemInitialize for SubSystem: '<Root>/Triggered Single Pulse' */

    /* SystemInitialize for Enabled SubSystem: '<Root>/Reference' */
    /* InitializeConditions for Memory: '<S4>/Memory' */
    SPERTE_printer_DW.Memory_PreviousInput =
      SPERTE_printer_P.Memory_InitialCondition_i;

    /* SystemInitialize for Sum: '<S4>/Sum1' incorporates:
     *  Outport: '<S4>/Time'
     */
    SPERTE_printer_B.Sum1 = SPERTE_printer_P.Time_Y0;

    /* SystemInitialize for RelationalOperator: '<S28>/Compare' incorporates:
     *  Outport: '<S4>/ref_finished'
     */
    SPERTE_printer_B.Compare = SPERTE_printer_P.ref_finished_Y0;

    /* SystemInitialize for LookupNDDirect: '<S4>/Direct Lookup Table ff' incorporates:
     *  Outport: '<S4>/Feedforward'
     *
     * About '<S4>/Direct Lookup Table ff':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     *   */
    SPERTE_printer_B.DirectLookupTableff = SPERTE_printer_P.Feedforward_Y0;

    /* SystemInitialize for LookupNDDirect: '<S4>/Direct Lookup Table ref' incorporates:
     *  Outport: '<S4>/Reference'
     *
     * About '<S4>/Direct Lookup Table ref':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     *   */
    SPERTE_printer_B.DirectLookupTableref = SPERTE_printer_P.Reference_Y0;

    /* End of SystemInitialize for SubSystem: '<Root>/Reference' */

    /* SystemInitialize for Resettable SubSystem: '<S14>/Homing reference' */
    /* InitializeConditions for Sum: '<S19>/Sum1' incorporates:
     *  Memory: '<S19>/Memory'
     */
    SPERTE_printer_DW.Memory_PreviousInput_g =
      SPERTE_printer_P.Memory_InitialCondition;

    /* End of SystemInitialize for SubSystem: '<S14>/Homing reference' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/Measurement' */
    /* SystemInitialize for Atomic SubSystem: '<S1>/Triggered Single Pulse' */
    SPERT_TriggeredSinglePulse_Init(&SPERTE_printer_DW.TriggeredSinglePulse_j,
      &SPERTE_printer_P.TriggeredSinglePulse_j);

    /* End of SystemInitialize for SubSystem: '<S1>/Triggered Single Pulse' */

    /* SystemInitialize for MATLAB Function: '<S7>/SPERTE_measurement_function' */
    for (i = 0; i < 20; i++) {
      SPERTE_printer_DW.eml_autoflush[i] = false;
    }

    SPERTE_printer_DW.eml_autoflush_not_empty = true;
    for (i = 0; i < 20; i++) {
      SPERTE_printer_DW.eml_openfiles[i] = NULL;
    }

    SPERTE_printer_DW.eml_openfiles_not_empty = true;
    SPERTE_printer_DW.NF = 0;
    SPERTE_printer_DW.NF_not_empty = true;
    SPERTE_printer_DW.NS = 0U;
    SPERTE_printer_DW.NS_not_empty = true;
    SPERTE_printer_DW.fileID = 0.0;
    SPERTE_printer_DW.fileID_not_empty = true;
    SPERTE_printer_DW.busy = 0U;
    SPERTE_printer_DW.busy_not_empty = true;
    SPERTE_printer_DW.sfEvent_h = SPERTE_printer_CALL_EVENT;

    /* End of SystemInitialize for MATLAB Function: '<S7>/SPERTE_measurement_function' */
    /* End of SystemInitialize for SubSystem: '<Root>/Measurement' */
  }
}

/* Model terminate function */
void SPERTE_printer_terminate(void)
{
  /* Terminate for S-Function (ec_Supervisor): '<S17>/S-Function' */
  /* Level2 S-Function Block: '<S17>/S-Function' (ec_Supervisor) */
  {
    SimStruct *rts = SPERTE_printer_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (ec_Ebox): '<S16>/ec_Ebox' */
  /* Level2 S-Function Block: '<S16>/ec_Ebox' (ec_Ebox) */
  {
    SimStruct *rts = SPERTE_printer_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (dpd): '<S3>/Dctpd' */
  /* Level2 S-Function Block: '<S3>/Dctpd' (dpd) */
  {
    SimStruct *rts = SPERTE_printer_M->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (dlowpass2): '<S3>/Dct2lowpass' */
  /* Level2 S-Function Block: '<S3>/Dct2lowpass' (dlowpass2) */
  {
    SimStruct *rts = SPERTE_printer_M->childSfunctions[3];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (dpd): '<S22>/Dctpd2' */
  /* Level2 S-Function Block: '<S22>/Dctpd2' (dpd) */
  {
    SimStruct *rts = SPERTE_printer_M->childSfunctions[4];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (dlowpass2): '<S22>/Dct2lowpass3' */
  /* Level2 S-Function Block: '<S22>/Dct2lowpass3' (dlowpass2) */
  {
    SimStruct *rts = SPERTE_printer_M->childSfunctions[5];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (dweakint_resettable): '<S22>/Dctintegrator1' */
  /* Level2 S-Function Block: '<S22>/Dctintegrator1' (dweakint_resettable) */
  {
    SimStruct *rts = SPERTE_printer_M->childSfunctions[6];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (dpd): '<S21>/Dctpd2' */
  /* Level2 S-Function Block: '<S21>/Dctpd2' (dpd) */
  {
    SimStruct *rts = SPERTE_printer_M->childSfunctions[7];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (dlowpass2): '<S21>/Dct2lowpass3' */
  /* Level2 S-Function Block: '<S21>/Dct2lowpass3' (dlowpass2) */
  {
    SimStruct *rts = SPERTE_printer_M->childSfunctions[8];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (ec_EboxResetEnc): '<S14>/Reset Encoder' */
  /* Level2 S-Function Block: '<S14>/Reset Encoder' (ec_EboxResetEnc) */
  {
    SimStruct *rts = SPERTE_printer_M->childSfunctions[9];
    sfcnTerminate(rts);
  }
}
