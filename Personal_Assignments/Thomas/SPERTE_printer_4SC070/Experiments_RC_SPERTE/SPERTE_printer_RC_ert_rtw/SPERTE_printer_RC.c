/*
 * SPERTE_printer_RC.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "SPERTE_printer_RC".
 *
 * Model version              : 13.1
 * Simulink Coder version : 25.2 (R2025b) 28-Jul-2025
 * C source code generated on : Wed Apr 29 17:28:11 2026
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex-A (64-bit)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "SPERTE_printer_RC.h"
#include "SPERTE_printer_RC_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include "SPERTE_printer_RC_private.h"
#include <math.h>
#include "rt_nonfinite.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "zero_crossing_types.h"
#include <float.h>

/* Named constants for MATLAB Function: '<S6>/SPERTE_measurement_function' */
#define SPERTE_printer_RC_CALL_EVENT   (-1)

/* Block signals (default storage) */
B_SPERTE_printer_RC_T SPERTE_printer_RC_B;

/* Block states (default storage) */
DW_SPERTE_printer_RC_T SPERTE_printer_RC_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_SPERTE_printer_RC_T SPERTE_printer_RC_PrevZCX;

/* Real-time model */
static RT_MODEL_SPERTE_printer_RC_T SPERTE_printer_RC_M_;
RT_MODEL_SPERTE_printer_RC_T *const SPERTE_printer_RC_M = &SPERTE_printer_RC_M_;

/* Forward declaration for local functions */
static void SPERTE_printer_R_emxInit_char_T(emxArray_char_T_SPERTE_printe_T
  **pEmxArray, int32_T numDimensions);
static void SPERTE_emxEnsureCapacity_char_T(emxArray_char_T_SPERTE_printe_T
  *emxArray, int32_T oldNumel);
static void SPERTE_printer_R_emxFree_char_T(emxArray_char_T_SPERTE_printe_T
  **pEmxArray);
static int8_T SPERTE_printer_RC_filedata(void);
static int8_T SPERTE_printer_RC_cfopen(const emxArray_char_T_SPERTE_printe_T
  *cfilename, const char_T *cpermission);
static int32_T SPERTE_printer_RC_cfclose(real_T fid);
real_T rt_remd_snf(real_T u0, real_T u1)
{
  real_T q;
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (rtIsInf(u1)) {
    y = u0;
  } else {
    if (u1 < 0.0) {
      q = ceil(u1);
    } else {
      q = floor(u1);
    }

    if ((u1 != 0.0) && (u1 != q)) {
      q = fabs(u0 / u1);
      if (!(fabs(q - floor(q + 0.5)) > DBL_EPSILON * q)) {
        y = 0.0 * u0;
      } else {
        y = fmod(u0, u1);
      }
    } else {
      y = fmod(u0, u1);
    }
  }

  return y;
}

static void SPERTE_printer_R_emxInit_char_T(emxArray_char_T_SPERTE_printe_T
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

static void SPERTE_printer_R_emxFree_char_T(emxArray_char_T_SPERTE_printe_T
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

/* Function for MATLAB Function: '<S6>/SPERTE_measurement_function' */
static int8_T SPERTE_printer_RC_filedata(void)
{
  int32_T k;
  int8_T f;
  boolean_T exitg1;
  f = 0;
  k = 1;
  exitg1 = false;
  while ((!exitg1) && (k - 1 < 20)) {
    if (SPERTE_printer_RC_DW.eml_openfiles[(int8_T)k - 1] == NULL) {
      f = (int8_T)k;
      exitg1 = true;
    } else {
      k++;
    }
  }

  return f;
}

/* Function for MATLAB Function: '<S6>/SPERTE_measurement_function' */
static int8_T SPERTE_printer_RC_cfopen(const emxArray_char_T_SPERTE_printe_T
  *cfilename, const char_T *cpermission)
{
  FILE *filestar;
  emxArray_char_T_SPERTE_printe_T *ccfilename;
  int32_T loop_ub;
  int8_T fileid;
  int8_T j;
  fileid = -1;
  j = SPERTE_printer_RC_filedata();
  if (j >= 1) {
    SPERTE_printer_R_emxInit_char_T(&ccfilename, 2);
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
    SPERTE_printer_R_emxFree_char_T(&ccfilename);
    if (filestar != NULL) {
      SPERTE_printer_RC_DW.eml_openfiles[j - 1] = filestar;
      SPERTE_printer_RC_DW.eml_autoflush[j - 1] = true;
      loop_ub = j + 2;
      if (j + 2 > 127) {
        loop_ub = 127;
      }

      fileid = (int8_T)loop_ub;
    }
  }

  return fileid;
}

/* Function for MATLAB Function: '<S6>/SPERTE_measurement_function' */
static int32_T SPERTE_printer_RC_cfclose(real_T fid)
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
    f = SPERTE_printer_RC_DW.eml_openfiles[b_fileid - 3];
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
      SPERTE_printer_RC_DW.eml_openfiles[fileid - 3] = NULL;
      SPERTE_printer_RC_DW.eml_autoflush[fileid - 3] = true;
    }
  }

  return st;
}

/* Model step function */
void SPERTE_printer_RC_step(void)
{
  /* local block i/o variables */
  real_T rtb_TSamp;
  real_T rtb_Delay1;
  real_T rtb_Internal;
  boolean_T rtb_NOT;
  boolean_T rtb_LogicalOperator3;
  FILE *f;
  size_t bytesOutSizet;
  emxArray_char_T_SPERTE_printe_T *str;
  emxArray_char_T_SPERTE_printe_T *str_0;
  real_T rtb_Delay;
  real_T rtb_Sum2;
  int32_T i;
  int32_T tmp;
  real32_T xout[4];
  int8_T b_fileid;
  boolean_T autoflush;

  /* Reset subsysRan breadcrumbs */
  srClearBC(SPERTE_printer_RC_DW.Reference_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(SPERTE_printer_RC_DW.RepetitiveController_SubsysRanB);

  /* S-Function (ec_Supervisor): '<S11>/S-Function' */

  /* Level2 S-Function Block: '<S11>/S-Function' (ec_Supervisor) */
  {
    SimStruct *rts = SPERTE_printer_RC_M->childSfunctions[0];
    sfcnOutputs(rts,0);
  }

  /* S-Function (ec_Ebox): '<S10>/ec_Ebox' */

  /* Level2 S-Function Block: '<S10>/ec_Ebox' (ec_Ebox) */
  {
    SimStruct *rts = SPERTE_printer_RC_M->childSfunctions[1];
    sfcnOutputs(rts,0);
  }

  /* Gain: '<S10>/Gain' */
  SPERTE_printer_RC_B.Gain[0] = SPERTE_printer_RC_P.Gain_Gain_k * 0.0;
  SPERTE_printer_RC_B.Gain[1] = SPERTE_printer_RC_P.Gain_Gain_k * 0.0;

  /* Gain: '<S8>/Counts to Meter1' */
  SPERTE_printer_RC_B.CountstoMeter1 = SPERTE_printer_RC_P.CountstoMeter1_Gain *
    SPERTE_printer_RC_B.ec_Ebox_o2[0];

  /* RateTransition: '<S8>/Rate Transition5' */
  SPERTE_printer_RC_B.RateTransition5 = SPERTE_printer_RC_B.ec_Ebox_o3[1];

  /* Chart: '<S9>/Supervisor' */
  if (SPERTE_printer_RC_DW.temporalCounter_i1 < 1023) {
    SPERTE_printer_RC_DW.temporalCounter_i1++;
  }

  SPERTE_printer_RC_DW.sfEvent = SPERTE_printer_RC_CALL_EVENT;
  if (SPERTE_printer_RC_DW.is_active_c1_SPERTE_printer_RC == 0) {
    SPERTE_printer_RC_DW.is_active_c1_SPERTE_printer_RC = 1U;
    SPERTE_printer_RC_B.SupervisorMode = SupervisorModeType_Homing;

    /* Set jog speed and homing state */
    SPERTE_printer_RC_B.toPoint = 0.0;
    SPERTE_printer_RC_B.homingBusy = 1.0;
    SPERTE_printer_RC_B.jogSpeed = -0.2;
    SPERTE_printer_RC_B.homeControllerEnabled = 1.0;
  } else {
    switch (SPERTE_printer_RC_B.SupervisorMode) {
     case SupervisorModeType_AirbagLeft:
      SPERTE_printer_RC_B.airBagEnabled = 1.0;
      SPERTE_printer_RC_B.airBagRef = -0.01;
      if (SPERTE_printer_RC_DW.temporalCounter_i1 >= 1000) {
        SPERTE_printer_RC_B.SupervisorMode = SupervisorModeType_DisableOutputs;
        SPERTE_printer_RC_B.controlEnabled = 0.0;
      }
      break;

     case SupervisorModeType_AirbagRight:
      SPERTE_printer_RC_B.airBagEnabled = 1.0;
      SPERTE_printer_RC_B.airBagRef = 0.35;
      if (SPERTE_printer_RC_DW.temporalCounter_i1 >= 1000) {
        SPERTE_printer_RC_B.SupervisorMode = SupervisorModeType_DisableOutputs;
        SPERTE_printer_RC_B.controlEnabled = 0.0;
      }
      break;

     case SupervisorModeType_DisableControl:
      SPERTE_printer_RC_B.homeControllerEnabled = 0.0;

      /* Allow settling of belt */
      if (SPERTE_printer_RC_DW.temporalCounter_i1 >= 500) {
        SPERTE_printer_RC_DW.temporalCounter_i1 = 0U;
        SPERTE_printer_RC_B.SupervisorMode = SupervisorModeType_ResetEnc;
        SPERTE_printer_RC_B.resetEnc = 1.0;
      }
      break;

     case SupervisorModeType_DisableOutputs:
      SPERTE_printer_RC_B.controlEnabled = 0.0;
      break;

     case SupervisorModeType_EnableRunAndSafety:
      SPERTE_printer_RC_B.resetEnc = 0.0;
      SPERTE_printer_RC_B.homingBusy = 0.0;
      if (SPERTE_printer_RC_B.CountstoMeter1 < -0.01) {
        SPERTE_printer_RC_DW.temporalCounter_i1 = 0U;
        SPERTE_printer_RC_B.SupervisorMode = SupervisorModeType_AirbagLeft;
        SPERTE_printer_RC_B.airBagEnabled = 1.0;
        SPERTE_printer_RC_B.airBagRef = -0.01;
      } else if (SPERTE_printer_RC_B.CountstoMeter1 > 0.35) {
        SPERTE_printer_RC_DW.temporalCounter_i1 = 0U;
        SPERTE_printer_RC_B.SupervisorMode = SupervisorModeType_AirbagRight;
        SPERTE_printer_RC_B.airBagEnabled = 1.0;
        SPERTE_printer_RC_B.airBagRef = 0.35;
      }
      break;

     case SupervisorModeType_Homing:
      SPERTE_printer_RC_B.toPoint = 0.0;
      SPERTE_printer_RC_B.homingBusy = 1.0;
      SPERTE_printer_RC_B.jogSpeed = -0.2;
      SPERTE_printer_RC_B.homeControllerEnabled = 1.0;

      /* Transition if homeswitch becomes high */
      if (SPERTE_printer_RC_B.RateTransition5 != 0.0) {
        SPERTE_printer_RC_DW.temporalCounter_i1 = 0U;
        SPERTE_printer_RC_B.SupervisorMode = SupervisorModeType_MovetoX0;
        SPERTE_printer_RC_B.jogSpeed = 0.0;
        SPERTE_printer_RC_B.toPoint = 0.06;
      }
      break;

     case SupervisorModeType_MovetoX0:
      SPERTE_printer_RC_B.jogSpeed = 0.0;
      SPERTE_printer_RC_B.toPoint = 0.06;

      /* Allow time for moving */
      if (SPERTE_printer_RC_DW.temporalCounter_i1 >= 1000) {
        SPERTE_printer_RC_DW.temporalCounter_i1 = 0U;
        SPERTE_printer_RC_B.SupervisorMode = SupervisorModeType_DisableControl;
        SPERTE_printer_RC_B.homeControllerEnabled = 0.0;
      }
      break;

     default:
      /* State ResetEnc */
      SPERTE_printer_RC_B.resetEnc = 1.0;
      if (SPERTE_printer_RC_DW.temporalCounter_i1 >= 100) {
        SPERTE_printer_RC_B.SupervisorMode =
          SupervisorModeType_EnableRunAndSafety;
        SPERTE_printer_RC_B.resetEnc = 0.0;
        SPERTE_printer_RC_B.homingBusy = 0.0;
      }
      break;
    }
  }

  /* End of Chart: '<S9>/Supervisor' */

  /* UnitDelay: '<S9>/Unit Delay1' */
  SPERTE_printer_RC_B.UnitDelay1 = SPERTE_printer_RC_DW.UnitDelay1_DSTATE;

  /* Outputs for Enabled SubSystem: '<Root>/Reference' incorporates:
   *  EnablePort: '<S4>/Enable'
   */
  if (SPERTE_printer_RC_B.UnitDelay1) {
    if (!SPERTE_printer_RC_DW.Reference_MODE) {
      /* InitializeConditions for Sum: '<S4>/Sum1' incorporates:
       *  Memory: '<S4>/Memory'
       */
      SPERTE_printer_RC_DW.Memory_PreviousInput =
        SPERTE_printer_RC_P.Memory_InitialCondition_c;
      SPERTE_printer_RC_DW.Reference_MODE = true;
    }

    /* Sum: '<S4>/Sum1' incorporates:
     *  Constant: '<S4>/One'
     *  Memory: '<S4>/Memory'
     */
    SPERTE_printer_RC_DW.Memory_PreviousInput += SPERTE_printer_RC_P.One_Value_h;

    /* LookupNDDirect: '<S4>/Direct Lookup Table ref1' incorporates:
     *  Constant: '<S4>/Constant'
     *  Math: '<S4>/Math Function'
     *
     * About '<S4>/Direct Lookup Table ref1':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     *   */
    rtb_Delay = rt_remd_snf(SPERTE_printer_RC_DW.Memory_PreviousInput,
      SPERTE_printer_RC_P.N);
    if (rtb_Delay > 1807.0) {
      rtb_Delay = 1807.0;
    } else if (rtb_Delay < 0.0) {
      rtb_Delay = 0.0;
    }

    /* LookupNDDirect: '<S4>/Direct Lookup Table ref1' incorporates:
     *  Constant: '<S4>/set_Ref'
     *
     * About '<S4>/Direct Lookup Table ref1':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     *   */
    SPERTE_printer_RC_B.DirectLookupTableref1 =
      SPERTE_printer_RC_P.set_Ref_Value[(int32_T)rtb_Delay];

    /* Product: '<S4>/Product' incorporates:
     *  Constant: '<S20>/Constant'
     *  Constant: '<S21>/Constant'
     *  Constant: '<S4>/Constant'
     *  Product: '<S4>/Divide'
     *  RelationalOperator: '<S20>/Compare'
     *  RelationalOperator: '<S21>/Compare'
     *  Rounding: '<S4>/Rounding Function'
     */
    SPERTE_printer_RC_B.Product = (uint16_T)
      (SPERTE_printer_RC_DW.Memory_PreviousInput < SPERTE_printer_RC_P.N *
       SPERTE_printer_RC_P.N_trial - 1.0 ? floor
       (SPERTE_printer_RC_DW.Memory_PreviousInput / SPERTE_printer_RC_P.N) >=
       SPERTE_printer_RC_P.N_RC_activate - 1.0 : 0);

    /* Stop: '<S4>/Stop Simulation' incorporates:
     *  Constant: '<S19>/Constant'
     *  RelationalOperator: '<S19>/Compare'
     */
    if (SPERTE_printer_RC_DW.Memory_PreviousInput >= SPERTE_printer_RC_P.N *
        SPERTE_printer_RC_P.N_trial) {
      rtmSetStopRequested(SPERTE_printer_RC_M, 1);
    }

    /* End of Stop: '<S4>/Stop Simulation' */

    /* Sum: '<S4>/Sum' incorporates:
     *  Constant: '<S4>/Constant1'
     *  Gain: '<S4>/Gain'
     */
    SPERTE_printer_RC_B.Sum = SPERTE_printer_RC_P.Gain_Gain *
      SPERTE_printer_RC_DW.Memory_PreviousInput -
      SPERTE_printer_RC_P.Constant1_Value;
    srUpdateBC(SPERTE_printer_RC_DW.Reference_SubsysRanBC);
  } else {
    SPERTE_printer_RC_DW.Reference_MODE = false;
  }

  /* End of Outputs for SubSystem: '<Root>/Reference' */

  /* Sum: '<Root>/Sum2' */
  rtb_Sum2 = SPERTE_printer_RC_B.DirectLookupTableref1 -
    SPERTE_printer_RC_B.CountstoMeter1;

  /* Outputs for Enabled SubSystem: '<Root>/Repetitive Controller' incorporates:
   *  EnablePort: '<S5>/Enable'
   */
  if (SPERTE_printer_RC_B.Product > 0) {
    if (!SPERTE_printer_RC_DW.RepetitiveController_MODE) {
      /* InitializeConditions for Delay: '<S5>/Delay' */
      SPERTE_printer_RC_DW.Delay_DSTATE[0] =
        SPERTE_printer_RC_P.Delay_InitialCondition;
      SPERTE_printer_RC_DW.Delay_DSTATE[1] =
        SPERTE_printer_RC_P.Delay_InitialCondition;
      SPERTE_printer_RC_DW.Delay_DSTATE[2] =
        SPERTE_printer_RC_P.Delay_InitialCondition;
      SPERTE_printer_RC_DW.Delay_DSTATE[3] =
        SPERTE_printer_RC_P.Delay_InitialCondition;

      /* InitializeConditions for Delay: '<S5>/Delay1' */
      for (i = 0; i < 1754; i++) {
        SPERTE_printer_RC_DW.Delay1_DSTATE[i] =
          SPERTE_printer_RC_P.Delay1_InitialCondition;
      }

      /* End of InitializeConditions for Delay: '<S5>/Delay1' */

      /* InitializeConditions for DiscreteStateSpace: '<S22>/Internal' */
      {
        int_T i1;
        real_T *dw_DSTATE = &SPERTE_printer_RC_DW.Internal_DSTATE[0];
        for (i1=0; i1 < 100; i1++) {
          dw_DSTATE[i1] = SPERTE_printer_RC_P.Internal_InitialCondition;
        }
      }

      /* InitializeConditions for DiscreteStateSpace: '<S23>/Internal' */
      {
        int_T i1;
        real_T *dw_DSTATE = &SPERTE_printer_RC_DW.Internal_DSTATE_l[0];
        for (i1=0; i1 < 10; i1++) {
          dw_DSTATE[i1] = SPERTE_printer_RC_P.Internal_InitialCondition_g;
        }
      }

      SPERTE_printer_RC_DW.RepetitiveController_MODE = true;
    }

    /* Delay: '<S5>/Delay' */
    rtb_Delay = SPERTE_printer_RC_DW.Delay_DSTATE[0];

    /* Delay: '<S5>/Delay1' */
    rtb_Delay1 = SPERTE_printer_RC_DW.Delay1_DSTATE[0];

    /* DiscreteStateSpace: '<S22>/Internal' */
    {
      rtb_Internal = SPERTE_printer_RC_P.Internal_D*rtb_Delay1;

      {
        int_T nx = 100;
        const real_T *x = &SPERTE_printer_RC_DW.Internal_DSTATE[0];
        const real_T *Cmtx = SPERTE_printer_RC_P.Internal_C;
        while (nx--) {
          rtb_Internal += (*Cmtx) * (*x++);
          Cmtx += 1;
        }
      }
    }

    /* DiscreteStateSpace: '<S23>/Internal' */
    {
      {
        static const int_T colCidxRow0[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

        const int_T *pCidx = &colCidxRow0[0];
        const real_T *pC0 = SPERTE_printer_RC_P.Internal_C_m;
        const real_T *xd = &SPERTE_printer_RC_DW.Internal_DSTATE_l[0];
        real_T *y0 = &SPERTE_printer_RC_B.Internal;
        int_T numNonZero = 9;
        *y0 = (*pC0++) * xd[*pCidx++];
        while (numNonZero--) {
          *y0 += (*pC0++) * xd[*pCidx++];
        }
      }

      SPERTE_printer_RC_B.Internal += SPERTE_printer_RC_P.Internal_D_m*
        rtb_Internal;
    }

    /* Update for Delay: '<S5>/Delay' */
    SPERTE_printer_RC_DW.Delay_DSTATE[0] = SPERTE_printer_RC_DW.Delay_DSTATE[1];
    SPERTE_printer_RC_DW.Delay_DSTATE[1] = SPERTE_printer_RC_DW.Delay_DSTATE[2];
    SPERTE_printer_RC_DW.Delay_DSTATE[2] = SPERTE_printer_RC_DW.Delay_DSTATE[3];
    SPERTE_printer_RC_DW.Delay_DSTATE[3] = rtb_Internal;

    /* Update for Delay: '<S5>/Delay1' incorporates:
     *  Sum: '<S5>/Sum4'
     */
    for (i = 0; i < 1753; i++) {
      SPERTE_printer_RC_DW.Delay1_DSTATE[i] =
        SPERTE_printer_RC_DW.Delay1_DSTATE[i + 1];
    }

    SPERTE_printer_RC_DW.Delay1_DSTATE[1753] = rtb_Sum2 + rtb_Delay;

    /* End of Update for Delay: '<S5>/Delay1' */

    /* Update for DiscreteStateSpace: '<S22>/Internal' */
    {
      int_T i;
      const real_T *Amtx = SPERTE_printer_RC_P.Internal_A;
      real_T *x = &SPERTE_printer_RC_DW.Internal_DSTATE[0];
      real_T xtmp = rtb_Delay1;
      for (i=99; i>0; i--) {
        xtmp += Amtx[i]*x[i];
        x[i] = x[i-1];
      }

      x[0] = xtmp + Amtx[0]*x[0];
    }

    /* Update for DiscreteStateSpace: '<S23>/Internal' */
    {
      real_T xnew[10];
      xnew[0] = (SPERTE_printer_RC_P.Internal_A_f[0])*
        SPERTE_printer_RC_DW.Internal_DSTATE_l[0]
        + (SPERTE_printer_RC_P.Internal_A_f[1])*
        SPERTE_printer_RC_DW.Internal_DSTATE_l[1];
      xnew[0] += (SPERTE_printer_RC_P.Internal_B[0])*rtb_Internal;
      xnew[1] = (SPERTE_printer_RC_P.Internal_A_f[2])*
        SPERTE_printer_RC_DW.Internal_DSTATE_l[0];
      xnew[2] = (SPERTE_printer_RC_P.Internal_A_f[3])*
        SPERTE_printer_RC_DW.Internal_DSTATE_l[0]
        + (SPERTE_printer_RC_P.Internal_A_f[4])*
        SPERTE_printer_RC_DW.Internal_DSTATE_l[1];
      xnew[2] += (SPERTE_printer_RC_P.Internal_B[1])*rtb_Internal;
      xnew[3] = (SPERTE_printer_RC_P.Internal_A_f[5])*
        SPERTE_printer_RC_DW.Internal_DSTATE_l[2];
      xnew[4] = (SPERTE_printer_RC_P.Internal_A_f[6])*
        SPERTE_printer_RC_DW.Internal_DSTATE_l[0]
        + (SPERTE_printer_RC_P.Internal_A_f[7])*
        SPERTE_printer_RC_DW.Internal_DSTATE_l[1]
        + (SPERTE_printer_RC_P.Internal_A_f[8])*
        SPERTE_printer_RC_DW.Internal_DSTATE_l[2]
        + (SPERTE_printer_RC_P.Internal_A_f[9])*
        SPERTE_printer_RC_DW.Internal_DSTATE_l[3];
      xnew[4] += (SPERTE_printer_RC_P.Internal_B[2])*rtb_Internal;
      xnew[5] = (SPERTE_printer_RC_P.Internal_A_f[10])*
        SPERTE_printer_RC_DW.Internal_DSTATE_l[4];

      {
        static const int_T colAidxRow6[6] = { 0, 1, 2, 3, 4, 5 };

        const int_T *pAidx = &colAidxRow6[0];
        const real_T *pA11 = &SPERTE_printer_RC_P.Internal_A_f[11];
        const real_T *xd = &SPERTE_printer_RC_DW.Internal_DSTATE_l[0];
        real_T *pxnew6 = &xnew[6];
        int_T numNonZero = 5;
        *pxnew6 = (*pA11++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew6 += (*pA11++) * xd[*pAidx++];
        }
      }

      xnew[6] += (SPERTE_printer_RC_P.Internal_B[3])*rtb_Internal;
      xnew[7] = (SPERTE_printer_RC_P.Internal_A_f[17])*
        SPERTE_printer_RC_DW.Internal_DSTATE_l[6];

      {
        static const int_T colAidxRow8[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

        const int_T *pAidx = &colAidxRow8[0];
        const real_T *pA18 = &SPERTE_printer_RC_P.Internal_A_f[18];
        const real_T *xd = &SPERTE_printer_RC_DW.Internal_DSTATE_l[0];
        real_T *pxnew8 = &xnew[8];
        int_T numNonZero = 9;
        *pxnew8 = (*pA18++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew8 += (*pA18++) * xd[*pAidx++];
        }
      }

      xnew[8] += (SPERTE_printer_RC_P.Internal_B[4])*rtb_Internal;
      xnew[9] = (SPERTE_printer_RC_P.Internal_A_f[28])*
        SPERTE_printer_RC_DW.Internal_DSTATE_l[8];
      (void) memcpy(&SPERTE_printer_RC_DW.Internal_DSTATE_l[0], xnew,
                    sizeof(real_T)*10);
    }

    srUpdateBC(SPERTE_printer_RC_DW.RepetitiveController_SubsysRanB);
  } else {
    SPERTE_printer_RC_DW.RepetitiveController_MODE = false;
  }

  /* End of Outputs for SubSystem: '<Root>/Repetitive Controller' */

  /* Gain: '<S3>/Gain' incorporates:
   *  Product: '<Root>/Product'
   *  Sum: '<Root>/Sum'
   */
  SPERTE_printer_RC_B.Gain_c = (SPERTE_printer_RC_B.Internal * (real_T)
    SPERTE_printer_RC_B.Product + rtb_Sum2) * SPERTE_printer_RC_P.Gain_Gain_j;

  /* S-Function (dpd): '<S3>/Dctpd' */

  /* Level2 S-Function Block: '<S3>/Dctpd' (dpd) */
  {
    SimStruct *rts = SPERTE_printer_RC_M->childSfunctions[2];
    sfcnOutputs(rts,0);
  }

  /* S-Function (dlowpass2): '<S3>/Dct2lowpass' */

  /* Level2 S-Function Block: '<S3>/Dct2lowpass' (dlowpass2) */
  {
    SimStruct *rts = SPERTE_printer_RC_M->childSfunctions[3];
    sfcnOutputs(rts,0);
  }

  /* Logic: '<S9>/NOT' */
  rtb_NOT = !(SPERTE_printer_RC_B.homeControllerEnabled != 0.0);

  /* DiscreteIntegrator: '<S9>/Discrete-Time Integrator' */
  if (rtb_NOT || (SPERTE_printer_RC_DW.DiscreteTimeIntegrator_PrevRese != 0)) {
    SPERTE_printer_RC_DW.DiscreteTimeIntegrator_DSTATE =
      SPERTE_printer_RC_P.DiscreteTimeIntegrator_IC;
  }

  /* Outputs for Resettable SubSystem: '<S9>/Homing reference' incorporates:
   *  ResetPort: '<S13>/Reset'
   */
  if (rt_ZCFcn(RISING_ZERO_CROSSING,
               &SPERTE_printer_RC_PrevZCX.Homingreference_Reset_ZCE,
               (SPERTE_printer_RC_B.RateTransition5)) != NO_ZCEVENT) {
    /* InitializeConditions for Sum: '<S13>/Sum1' incorporates:
     *  Memory: '<S13>/Memory'
     */
    SPERTE_printer_RC_DW.Memory_PreviousInput_g =
      SPERTE_printer_RC_P.Memory_InitialCondition;
  }

  /* Sum: '<S13>/Sum1' incorporates:
   *  Constant: '<S13>/One'
   *  Memory: '<S13>/Memory'
   */
  SPERTE_printer_RC_DW.Memory_PreviousInput_g += SPERTE_printer_RC_P.One_Value;

  /* LookupNDDirect: '<S13>/Direct Lookup Table ref' incorporates:
   *  Sum: '<S13>/Sum1'
   *
   * About '<S13>/Direct Lookup Table ref':
   *  1-dimensional Direct Look-Up returning a Scalar,
   *
   *     Remove protection against out-of-range input in generated code: 'off'
   *   */
  if (SPERTE_printer_RC_DW.Memory_PreviousInput_g > 599.0) {
    rtb_Delay = 599.0;
  } else if (SPERTE_printer_RC_DW.Memory_PreviousInput_g < 0.0) {
    rtb_Delay = 0.0;
  } else {
    rtb_Delay = SPERTE_printer_RC_DW.Memory_PreviousInput_g;
  }

  /* Sum: '<S9>/Sum' incorporates:
   *  Constant: '<S13>/homing_ref'
   *  DiscreteIntegrator: '<S9>/Discrete-Time Integrator'
   *  LookupNDDirect: '<S13>/Direct Lookup Table ref'
   *  Product: '<S13>/Product'
   *
   * About '<S13>/Direct Lookup Table ref':
   *  1-dimensional Direct Look-Up returning a Scalar,
   *
   *     Remove protection against out-of-range input in generated code: 'off'
   *   */
  rtb_Delay = SPERTE_printer_RC_B.toPoint
    * SPERTE_printer_RC_P.homing_ref_Value[(int32_T)rtb_Delay] +
    SPERTE_printer_RC_DW.DiscreteTimeIntegrator_DSTATE;

  /* End of Outputs for SubSystem: '<S9>/Homing reference' */

  /* SampleTimeMath: '<S18>/TSamp'
   *
   * About '<S18>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *   */
  rtb_TSamp = rtb_Delay * SPERTE_printer_RC_P.TSamp_WtEt;

  /* Gain: '<S16>/Gain1' incorporates:
   *  Sum: '<S9>/Sum2'
   */
  SPERTE_printer_RC_B.Gain1 = (rtb_Delay - SPERTE_printer_RC_B.CountstoMeter1) *
    SPERTE_printer_RC_P.Gain1_Gain;

  /* S-Function (dpd): '<S16>/Dctpd2' */

  /* Level2 S-Function Block: '<S16>/Dctpd2' (dpd) */
  {
    SimStruct *rts = SPERTE_printer_RC_M->childSfunctions[4];
    sfcnOutputs(rts,0);
  }

  /* S-Function (dlowpass2): '<S16>/Dct2lowpass3' */

  /* Level2 S-Function Block: '<S16>/Dct2lowpass3' (dlowpass2) */
  {
    SimStruct *rts = SPERTE_printer_RC_M->childSfunctions[5];
    sfcnOutputs(rts,0);
  }

  /* DataTypeConversion: '<S16>/Cast To Double' */
  SPERTE_printer_RC_B.CastToDouble = rtb_NOT;

  /* S-Function (dweakint_resettable): '<S16>/Dctintegrator1' */

  /* Level2 S-Function Block: '<S16>/Dctintegrator1' (dweakint_resettable) */
  {
    SimStruct *rts = SPERTE_printer_RC_M->childSfunctions[6];
    sfcnOutputs(rts,0);
  }

  /* Gain: '<S15>/Gain1' incorporates:
   *  Sum: '<S9>/Sum1'
   */
  SPERTE_printer_RC_B.Gain1_j = (SPERTE_printer_RC_B.airBagRef -
    SPERTE_printer_RC_B.CountstoMeter1) * SPERTE_printer_RC_P.Gain1_Gain_j;

  /* S-Function (dpd): '<S15>/Dctpd2' */

  /* Level2 S-Function Block: '<S15>/Dctpd2' (dpd) */
  {
    SimStruct *rts = SPERTE_printer_RC_M->childSfunctions[7];
    sfcnOutputs(rts,0);
  }

  /* S-Function (dlowpass2): '<S15>/Dct2lowpass3' */

  /* Level2 S-Function Block: '<S15>/Dct2lowpass3' (dlowpass2) */
  {
    SimStruct *rts = SPERTE_printer_RC_M->childSfunctions[8];
    sfcnOutputs(rts,0);
  }

  /* Switch: '<S9>/AirbagSwitch' incorporates:
   *  Logic: '<S9>/Logical Operator1'
   */
  if (!(SPERTE_printer_RC_B.airBagEnabled != 0.0)) {
    /* Switch: '<S9>/Homing Running Switch' incorporates:
     *  Constant: '<S17>/Constant'
     *  Gain: '<S12>/sign(v) BF'
     *  Product: '<S9>/Product'
     *  RelationalOperator: '<S17>/Compare'
     *  Signum: '<S12>/Sign'
     *  Sum: '<S9>/Sum7'
     */
    if (SPERTE_printer_RC_B.homingBusy >=
        SPERTE_printer_RC_P.HomingRunningSwitch_Threshold) {
      /* Sum: '<S18>/Diff' incorporates:
       *  UnitDelay: '<S18>/UD'
       */
      rtb_Delay = rtb_TSamp - SPERTE_printer_RC_DW.UD_DSTATE;

      /* Signum: '<S12>/Sign' */
      if (rtIsNaN(rtb_Delay)) {
        rtb_Delay = (rtNaN);
      } else if (rtb_Delay < 0.0) {
        rtb_Delay = -1.0;
      } else {
        rtb_Delay = (rtb_Delay > 0.0);
      }

      rtb_Delay = ((real_T)((rtb_Delay >
        SPERTE_printer_RC_P.CompareToConstant_const) *
                            SPERTE_printer_RC_P.signvBF_Gain) * 0.0078125 +
                   SPERTE_printer_RC_B.Dctintegrator1) *
        SPERTE_printer_RC_B.homeControllerEnabled;
    } else {
      rtb_Delay = SPERTE_printer_RC_B.Dct2lowpass;
    }

    /* End of Switch: '<S9>/Homing Running Switch' */
  } else {
    rtb_Delay = SPERTE_printer_RC_B.Dct2lowpass3_o;
  }

  /* End of Switch: '<S9>/AirbagSwitch' */

  /* Product: '<S9>/Product1' */
  rtb_Delay *= SPERTE_printer_RC_B.controlEnabled;

  /* Saturate: '<S8>/Saturation' */
  if (rtb_Delay > SPERTE_printer_RC_P.Saturation_UpperSat) {
    rtb_Delay = SPERTE_printer_RC_P.Saturation_UpperSat;
  } else if (rtb_Delay < SPERTE_printer_RC_P.Saturation_LowerSat) {
    rtb_Delay = SPERTE_printer_RC_P.Saturation_LowerSat;
  }

  /* Saturate: '<S10>/Saturation' */
  if (rtb_Delay > SPERTE_printer_RC_P.Saturation_UpperSat_e) {
    /* Saturate: '<S10>/Saturation' */
    SPERTE_printer_RC_B.Saturation[0] =
      SPERTE_printer_RC_P.Saturation_UpperSat_e;
  } else if (rtb_Delay < SPERTE_printer_RC_P.Saturation_LowerSat_i) {
    /* Saturate: '<S10>/Saturation' */
    SPERTE_printer_RC_B.Saturation[0] =
      SPERTE_printer_RC_P.Saturation_LowerSat_i;
  } else {
    /* Saturate: '<S10>/Saturation' */
    SPERTE_printer_RC_B.Saturation[0] = rtb_Delay;
  }

  /* Saturate: '<S8>/Saturation' incorporates:
   *  Constant: '<S8>/Constant2'
   */
  if (SPERTE_printer_RC_P.Constant2_Value >
      SPERTE_printer_RC_P.Saturation_UpperSat) {
    rtb_Delay = SPERTE_printer_RC_P.Saturation_UpperSat;
  } else if (SPERTE_printer_RC_P.Constant2_Value <
             SPERTE_printer_RC_P.Saturation_LowerSat) {
    rtb_Delay = SPERTE_printer_RC_P.Saturation_LowerSat;
  } else {
    rtb_Delay = SPERTE_printer_RC_P.Constant2_Value;
  }

  /* Saturate: '<S10>/Saturation' */
  if (rtb_Delay > SPERTE_printer_RC_P.Saturation_UpperSat_e) {
    /* Saturate: '<S10>/Saturation' */
    SPERTE_printer_RC_B.Saturation[1] =
      SPERTE_printer_RC_P.Saturation_UpperSat_e;
  } else if (rtb_Delay < SPERTE_printer_RC_P.Saturation_LowerSat_i) {
    /* Saturate: '<S10>/Saturation' */
    SPERTE_printer_RC_B.Saturation[1] =
      SPERTE_printer_RC_P.Saturation_LowerSat_i;
  } else {
    /* Saturate: '<S10>/Saturation' */
    SPERTE_printer_RC_B.Saturation[1] = rtb_Delay;
  }

  /* Outputs for Atomic SubSystem: '<Root>/Measurement' */
  /* MATLAB Function: '<S6>/SPERTE_measurement_function' incorporates:
   *  Constant: '<S6>/SPERTE_measurement_samples'
   *  Constant: '<S6>/SPERTE_measurement_trigger_command'
   *  DataTypeConversion: '<S1>/Data Type Conversion'
   *  SignalConversion generated from: '<S7>/ SFunction '
   */
  SPERTE_printer_RC_DW.sfEvent_f = SPERTE_printer_RC_CALL_EVENT;
  if ((((SPERTE_printer_RC_P.MeasurementBlock_triggertype == 0) &&
        SPERTE_printer_RC_B.UnitDelay1) ||
       ((SPERTE_printer_RC_P.MeasurementBlock_triggertype == 1) &&
        (SPERTE_printer_RC_P.MeasurementBlock_trigger_comman == 1)) ||
       ((SPERTE_printer_RC_P.MeasurementBlock_triggertype == 2) &&
        ((SPERTE_printer_RC_P.MeasurementBlock_trigger_comman == 1) ||
         SPERTE_printer_RC_B.UnitDelay1))) && (SPERTE_printer_RC_DW.busy != 1))
  {
    i = (int32_T)snprintf(NULL, 0, "measurement_%d.bin", SPERTE_printer_RC_DW.NF)
      + 1;
    SPERTE_printer_R_emxInit_char_T(&str, 2);
    tmp = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = i;
    SPERTE_emxEnsureCapacity_char_T(str, tmp);
    snprintf(&str->data[0], (size_t)i, "measurement_%d.bin",
             SPERTE_printer_RC_DW.NF);
    if (i - 1 < 1) {
      i = -1;
    } else {
      i -= 2;
    }

    SPERTE_printer_R_emxInit_char_T(&str_0, 2);
    tmp = str_0->size[0] * str_0->size[1];
    str_0->size[0] = 1;
    str_0->size[1] = i + 1;
    SPERTE_emxEnsureCapacity_char_T(str_0, tmp);
    if (i >= 0) {
      memcpy(&str_0->data[0], &str->data[0], (uint32_T)(i + 1) * sizeof(char_T));
    }

    SPERTE_printer_R_emxFree_char_T(&str);
    b_fileid = SPERTE_printer_RC_cfopen(str_0, "wb");
    SPERTE_printer_R_emxFree_char_T(&str_0);
    SPERTE_printer_RC_DW.fileID = b_fileid;
    i = SPERTE_printer_RC_DW.NF + 1;
    if (SPERTE_printer_RC_DW.NF + 1 > 32767) {
      i = 32767;
    }

    SPERTE_printer_RC_DW.NF = (int16_T)i;
    SPERTE_printer_RC_DW.busy = 1U;
    SPERTE_printer_RC_DW.NS = 0U;
  }

  if (SPERTE_printer_RC_DW.busy == 1) {
    if (SPERTE_printer_RC_DW.NS < SPERTE_printer_RC_P.MeasurementBlock_N_samples)
    {
      b_fileid = (int8_T)SPERTE_printer_RC_DW.fileID;
      if (((int8_T)SPERTE_printer_RC_DW.fileID < 0) ||
          (SPERTE_printer_RC_DW.fileID != (int8_T)SPERTE_printer_RC_DW.fileID))
      {
        b_fileid = -1;
      }

      if (b_fileid >= 3) {
        autoflush = SPERTE_printer_RC_DW.eml_autoflush[b_fileid - 3];
        f = SPERTE_printer_RC_DW.eml_openfiles[b_fileid - 3];
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

      if (!(SPERTE_printer_RC_DW.fileID != 0.0)) {
        f = NULL;
      }

      if (!(f == NULL)) {
        xout[0] = (real32_T)SPERTE_printer_RC_B.Sum;
        xout[1] = (real32_T)SPERTE_printer_RC_B.Internal;
        xout[2] = (real32_T)rtb_Sum2;
        xout[3] = (real32_T)SPERTE_printer_RC_B.Dct2lowpass;
        bytesOutSizet = fwrite(&xout[0], sizeof(real32_T), (size_t)4, f);
        if (((real_T)bytesOutSizet > 0.0) && autoflush) {
          fflush(f);
        }
      }

      SPERTE_printer_RC_DW.NS++;
    } else {
      SPERTE_printer_RC_cfclose(SPERTE_printer_RC_DW.fileID);
      SPERTE_printer_RC_DW.busy = 0U;
      SPERTE_printer_RC_DW.NS = 0U;
    }
  }

  SPERTE_printer_RC_B.status = SPERTE_printer_RC_DW.busy;

  /* End of MATLAB Function: '<S6>/SPERTE_measurement_function' */
  /* End of Outputs for SubSystem: '<Root>/Measurement' */
  /* Logic: '<S9>/Logical Operator2' */
  SPERTE_printer_RC_B.LogicalOperator2 = !(SPERTE_printer_RC_B.controlEnabled !=
    0.0);

  /* Logic: '<S9>/Logical Operator3' */
  rtb_LogicalOperator3 = !(SPERTE_printer_RC_B.homingBusy != 0.0);

  /* S-Function (ec_EboxResetEnc): '<S9>/Reset Encoder' */

  /* Level2 S-Function Block: '<S9>/Reset Encoder' (ec_EboxResetEnc) */
  {
    SimStruct *rts = SPERTE_printer_RC_M->childSfunctions[9];
    sfcnOutputs(rts,0);
  }

  /* Clock: '<Root>/Clock' */
  SPERTE_printer_RC_B.Clock = SPERTE_printer_RC_M->Timing.t[0];

  /* Update for UnitDelay: '<S9>/Unit Delay1' */
  SPERTE_printer_RC_DW.UnitDelay1_DSTATE = rtb_LogicalOperator3;

  /* Update for DiscreteIntegrator: '<S9>/Discrete-Time Integrator' */
  SPERTE_printer_RC_DW.DiscreteTimeIntegrator_DSTATE +=
    SPERTE_printer_RC_P.DiscreteTimeIntegrator_gainval *
    SPERTE_printer_RC_B.jogSpeed;
  SPERTE_printer_RC_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)rtb_NOT;

  /* Update for UnitDelay: '<S18>/UD' */
  SPERTE_printer_RC_DW.UD_DSTATE = rtb_TSamp;

  {                                    /* Sample time: [0.001s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T extmodeTime = (extmodeSimulationTime_T)
      SPERTE_printer_RC_M->Timing.t[1];

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
  if (!(++SPERTE_printer_RC_M->Timing.clockTick0)) {
    ++SPERTE_printer_RC_M->Timing.clockTickH0;
  }

  SPERTE_printer_RC_M->Timing.t[0] = SPERTE_printer_RC_M->Timing.clockTick0 *
    SPERTE_printer_RC_M->Timing.stepSize0 +
    SPERTE_printer_RC_M->Timing.clockTickH0 *
    SPERTE_printer_RC_M->Timing.stepSize0 * 4294967296.0;

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
    if (!(++SPERTE_printer_RC_M->Timing.clockTick1)) {
      ++SPERTE_printer_RC_M->Timing.clockTickH1;
    }

    SPERTE_printer_RC_M->Timing.t[1] = SPERTE_printer_RC_M->Timing.clockTick1 *
      SPERTE_printer_RC_M->Timing.stepSize1 +
      SPERTE_printer_RC_M->Timing.clockTickH1 *
      SPERTE_printer_RC_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Model initialize function */
void SPERTE_printer_RC_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)SPERTE_printer_RC_M, 0,
                sizeof(RT_MODEL_SPERTE_printer_RC_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&SPERTE_printer_RC_M->solverInfo,
                          &SPERTE_printer_RC_M->Timing.simTimeStep);
    rtsiSetTPtr(&SPERTE_printer_RC_M->solverInfo, &rtmGetTPtr
                (SPERTE_printer_RC_M));
    rtsiSetStepSizePtr(&SPERTE_printer_RC_M->solverInfo,
                       &SPERTE_printer_RC_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&SPERTE_printer_RC_M->solverInfo, (&rtmGetErrorStatus
      (SPERTE_printer_RC_M)));
    rtsiSetRTModelPtr(&SPERTE_printer_RC_M->solverInfo, SPERTE_printer_RC_M);
  }

  rtsiSetSimTimeStep(&SPERTE_printer_RC_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&SPERTE_printer_RC_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&SPERTE_printer_RC_M->solverInfo, false);
  rtsiSetSolverName(&SPERTE_printer_RC_M->solverInfo,"FixedStepDiscrete");
  SPERTE_printer_RC_M->solverInfoPtr = (&SPERTE_printer_RC_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = SPERTE_printer_RC_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    SPERTE_printer_RC_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    SPERTE_printer_RC_M->Timing.sampleTimes =
      (&SPERTE_printer_RC_M->Timing.sampleTimesArray[0]);
    SPERTE_printer_RC_M->Timing.offsetTimes =
      (&SPERTE_printer_RC_M->Timing.offsetTimesArray[0]);

    /* task periods */
    SPERTE_printer_RC_M->Timing.sampleTimes[0] = (0.0);
    SPERTE_printer_RC_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    SPERTE_printer_RC_M->Timing.offsetTimes[0] = (0.0);
    SPERTE_printer_RC_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(SPERTE_printer_RC_M, &SPERTE_printer_RC_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = SPERTE_printer_RC_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    SPERTE_printer_RC_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(SPERTE_printer_RC_M, -1);
  SPERTE_printer_RC_M->Timing.stepSize0 = 0.001;
  SPERTE_printer_RC_M->Timing.stepSize1 = 0.001;

  /* External mode info */
  SPERTE_printer_RC_M->Sizes.checksums[0] = (3423691752U);
  SPERTE_printer_RC_M->Sizes.checksums[1] = (384221367U);
  SPERTE_printer_RC_M->Sizes.checksums[2] = (1022517809U);
  SPERTE_printer_RC_M->Sizes.checksums[3] = (3482368117U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[9];
    SPERTE_printer_RC_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = (sysRanDType *)&SPERTE_printer_RC_DW.Reference_SubsysRanBC;
    systemRan[8] = (sysRanDType *)
      &SPERTE_printer_RC_DW.RepetitiveController_SubsysRanB;
    rteiSetModelMappingInfoPtr(SPERTE_printer_RC_M->extModeInfo,
      &SPERTE_printer_RC_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(SPERTE_printer_RC_M->extModeInfo,
                        SPERTE_printer_RC_M->Sizes.checksums);
    rteiSetTPtr(SPERTE_printer_RC_M->extModeInfo, rtmGetTPtr(SPERTE_printer_RC_M));
  }

  SPERTE_printer_RC_M->solverInfoPtr = (&SPERTE_printer_RC_M->solverInfo);
  SPERTE_printer_RC_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&SPERTE_printer_RC_M->solverInfo, 0.001);
  rtsiSetSolverMode(&SPERTE_printer_RC_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  (void) memset(((void *) &SPERTE_printer_RC_B), 0,
                sizeof(B_SPERTE_printer_RC_T));

  {
    SPERTE_printer_RC_B.SupervisorMode = SupervisorModeType_None;
  }

  /* states (dwork) */
  (void) memset((void *)&SPERTE_printer_RC_DW, 0,
                sizeof(DW_SPERTE_printer_RC_T));

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &SPERTE_printer_RC_M->NonInlinedSFcns.sfcnInfo;
    SPERTE_printer_RC_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(SPERTE_printer_RC_M)));
    SPERTE_printer_RC_M->Sizes.numSampTimes = (2);
    rtssSetNumRootSampTimesPtr(sfcnInfo,
      &SPERTE_printer_RC_M->Sizes.numSampTimes);
    SPERTE_printer_RC_M->NonInlinedSFcns.taskTimePtrs[0] = (&rtmGetTPtr
      (SPERTE_printer_RC_M)[0]);
    SPERTE_printer_RC_M->NonInlinedSFcns.taskTimePtrs[1] = (&rtmGetTPtr
      (SPERTE_printer_RC_M)[1]);
    rtssSetTPtrPtr(sfcnInfo,SPERTE_printer_RC_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(SPERTE_printer_RC_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(SPERTE_printer_RC_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (SPERTE_printer_RC_M));
    rtssSetStepSizePtr(sfcnInfo, &SPERTE_printer_RC_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(SPERTE_printer_RC_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &SPERTE_printer_RC_M->derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &SPERTE_printer_RC_M->zCCacheNeedsReset);
    rtssSetContTimeOutputInconsistentWithStateAtMajorStepPtr(sfcnInfo,
      &SPERTE_printer_RC_M->CTOutputIncnstWithState);
    rtssSetSampleHitsPtr(sfcnInfo, &SPERTE_printer_RC_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &SPERTE_printer_RC_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &SPERTE_printer_RC_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &SPERTE_printer_RC_M->solverInfoPtr);
  }

  SPERTE_printer_RC_M->Sizes.numSFcns = (10);

  /* register each child */
  {
    (void) memset((void *)&SPERTE_printer_RC_M->NonInlinedSFcns.childSFunctions
                  [0], 0,
                  10*sizeof(SimStruct));
    SPERTE_printer_RC_M->childSfunctions =
      (&SPERTE_printer_RC_M->NonInlinedSFcns.childSFunctionPtrs[0]);

    {
      int_T i;
      for (i = 0; i < 10; i++) {
        SPERTE_printer_RC_M->childSfunctions[i] =
          (&SPERTE_printer_RC_M->NonInlinedSFcns.childSFunctions[i]);
      }
    }

    /* Level2 S-Function Block: SPERTE_printer_RC/<S11>/S-Function (ec_Supervisor) */
    {
      SimStruct *rts = SPERTE_printer_RC_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &SPERTE_printer_RC_M->NonInlinedSFcns.blkInfo2[0]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &SPERTE_printer_RC_M->NonInlinedSFcns.inputOutputPortInfo2[0]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, SPERTE_printer_RC_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &SPERTE_printer_RC_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &SPERTE_printer_RC_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &SPERTE_printer_RC_M->NonInlinedSFcns.methods4[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &SPERTE_printer_RC_M->NonInlinedSFcns.statesInfo2
                         [0]);
        ssSetPeriodicStatesInfo(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.periodicStatesInfo[0]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        ssSetPortInfoForOutputs(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn0.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn0.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &SPERTE_printer_RC_B.SFunction));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts,
                "SPERTE_printer_RC/Printer/E//BOX I-O/Ethercat Supervisor/S-Function");
      ssSetRTModel(rts,SPERTE_printer_RC_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)SPERTE_printer_RC_P.SFunction_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)SPERTE_printer_RC_P.SFunction_P2_Size);
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

    /* Level2 S-Function Block: SPERTE_printer_RC/<S10>/ec_Ebox (ec_Ebox) */
    {
      SimStruct *rts = SPERTE_printer_RC_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &SPERTE_printer_RC_M->NonInlinedSFcns.blkInfo2[1]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &SPERTE_printer_RC_M->NonInlinedSFcns.inputOutputPortInfo2[1]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, SPERTE_printer_RC_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &SPERTE_printer_RC_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &SPERTE_printer_RC_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &SPERTE_printer_RC_M->NonInlinedSFcns.methods4[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &SPERTE_printer_RC_M->NonInlinedSFcns.statesInfo2
                         [1]);
        ssSetPeriodicStatesInfo(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.periodicStatesInfo[1]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 3);
        ssSetPortInfoForInputs(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn1.inputPortInfo[0]);
        ssSetPortInfoForInputs(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn1.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn1.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        ssSetInputPortUnit(rts, 1, 0);
        ssSetInputPortUnit(rts, 2, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn1.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);
        ssSetInputPortIsContinuousQuantity(rts, 1, 0);
        ssSetInputPortIsContinuousQuantity(rts, 2, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn1.UPtrs0;
          sfcnUPtrs[0] = SPERTE_printer_RC_B.Saturation;
          sfcnUPtrs[1] = &SPERTE_printer_RC_B.Saturation[1];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 2);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn1.UPtrs1;
          sfcnUPtrs[0] = SPERTE_printer_RC_B.Gain;
          sfcnUPtrs[1] = &SPERTE_printer_RC_B.Gain[1];
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidthAsInt(rts, 1, 2);
        }

        /* port 2 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn1.UPtrs2;
          sfcnUPtrs[0] = &SPERTE_printer_RC_B.homeControllerEnabled;
          sfcnUPtrs[1] = &SPERTE_printer_RC_B.homeControllerEnabled;
          sfcnUPtrs[2] = &SPERTE_printer_RC_B.homeControllerEnabled;
          sfcnUPtrs[3] = &SPERTE_printer_RC_B.homeControllerEnabled;
          sfcnUPtrs[4] = &SPERTE_printer_RC_B.homeControllerEnabled;
          sfcnUPtrs[5] = &SPERTE_printer_RC_B.homeControllerEnabled;
          sfcnUPtrs[6] = &SPERTE_printer_RC_B.homeControllerEnabled;
          sfcnUPtrs[7] = &SPERTE_printer_RC_B.homeControllerEnabled;
          ssSetInputPortSignalPtrs(rts, 2, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidthAsInt(rts, 2, 8);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn1.outputPortInfo[0]);
        ssSetPortInfoForOutputs(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn1.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 3);
        _ssSetPortInfo2ForOutputUnits(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn1.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        ssSetOutputPortUnit(rts, 1, 0);
        ssSetOutputPortUnit(rts, 2, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn1.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 1, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 2, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            SPERTE_printer_RC_B.ec_Ebox_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidthAsInt(rts, 1, 2);
          ssSetOutputPortSignal(rts, 1, ((real_T *)
            SPERTE_printer_RC_B.ec_Ebox_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidthAsInt(rts, 2, 8);
          ssSetOutputPortSignal(rts, 2, ((real_T *)
            SPERTE_printer_RC_B.ec_Ebox_o3));
        }
      }

      /* path info */
      ssSetModelName(rts, "ec_Ebox");
      ssSetPath(rts,
                "SPERTE_printer_RC/Printer/E//BOX I-O/Ethercat E-box/ec_Ebox");
      ssSetRTModel(rts,SPERTE_printer_RC_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)SPERTE_printer_RC_P.ec_Ebox_P1_Size);
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

    /* Level2 S-Function Block: SPERTE_printer_RC/<S3>/Dctpd (dpd) */
    {
      SimStruct *rts = SPERTE_printer_RC_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod = SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset = SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap = SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &SPERTE_printer_RC_M->NonInlinedSFcns.blkInfo2[2]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &SPERTE_printer_RC_M->NonInlinedSFcns.inputOutputPortInfo2[2]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, SPERTE_printer_RC_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &SPERTE_printer_RC_M->NonInlinedSFcns.methods2[2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &SPERTE_printer_RC_M->NonInlinedSFcns.methods3[2]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &SPERTE_printer_RC_M->NonInlinedSFcns.methods4[2]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &SPERTE_printer_RC_M->NonInlinedSFcns.statesInfo2
                         [2]);
        ssSetPeriodicStatesInfo(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.periodicStatesInfo[2]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn2.inputPortInfo[0]);
        ssSetPortInfoForInputs(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn2.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn2.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn2.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn2.UPtrs0;
          sfcnUPtrs[0] = &SPERTE_printer_RC_B.Gain_c;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn2.outputPortInfo[0]);
        ssSetPortInfoForOutputs(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn2.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn2.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn2.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &SPERTE_printer_RC_B.Dctpd));
        }
      }

      /* path info */
      ssSetModelName(rts, "Dctpd");
      ssSetPath(rts, "SPERTE_printer_RC/Printer Controller/Dctpd");
      ssSetRTModel(rts,SPERTE_printer_RC_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 3);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)SPERTE_printer_RC_P.Dctpd_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)SPERTE_printer_RC_P.Dctpd_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)SPERTE_printer_RC_P.Dctpd_P3_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &SPERTE_printer_RC_DW.Dctpd_RWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn2.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn2.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        ssSetNumDWorkAsInt(rts, 1);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &SPERTE_printer_RC_DW.Dctpd_RWORK[0]);
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

    /* Level2 S-Function Block: SPERTE_printer_RC/<S3>/Dct2lowpass (dlowpass2) */
    {
      SimStruct *rts = SPERTE_printer_RC_M->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod = SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset = SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap = SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &SPERTE_printer_RC_M->NonInlinedSFcns.blkInfo2[3]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &SPERTE_printer_RC_M->NonInlinedSFcns.inputOutputPortInfo2[3]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, SPERTE_printer_RC_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &SPERTE_printer_RC_M->NonInlinedSFcns.methods2[3]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &SPERTE_printer_RC_M->NonInlinedSFcns.methods3[3]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &SPERTE_printer_RC_M->NonInlinedSFcns.methods4[3]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &SPERTE_printer_RC_M->NonInlinedSFcns.statesInfo2
                         [3]);
        ssSetPeriodicStatesInfo(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.periodicStatesInfo[3]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn3.inputPortInfo[0]);
        ssSetPortInfoForInputs(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn3.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn3.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn3.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn3.UPtrs0;
          sfcnUPtrs[0] = &SPERTE_printer_RC_B.Dctpd;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn3.outputPortInfo[0]);
        ssSetPortInfoForOutputs(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn3.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn3.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn3.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &SPERTE_printer_RC_B.Dct2lowpass));
        }
      }

      /* path info */
      ssSetModelName(rts, "Dct2lowpass");
      ssSetPath(rts, "SPERTE_printer_RC/Printer Controller/Dct2lowpass");
      ssSetRTModel(rts,SPERTE_printer_RC_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn3.params;
        ssSetSFcnParamsCount(rts, 3);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)SPERTE_printer_RC_P.Dct2lowpass_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)SPERTE_printer_RC_P.Dct2lowpass_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)SPERTE_printer_RC_P.Dct2lowpass_P3_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &SPERTE_printer_RC_DW.Dct2lowpass_RWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn3.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn3.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        ssSetNumDWorkAsInt(rts, 1);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 4);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &SPERTE_printer_RC_DW.Dct2lowpass_RWORK[0]);
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

    /* Level2 S-Function Block: SPERTE_printer_RC/<S16>/Dctpd2 (dpd) */
    {
      SimStruct *rts = SPERTE_printer_RC_M->childSfunctions[4];

      /* timing info */
      time_T *sfcnPeriod = SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn4.sfcnPeriod;
      time_T *sfcnOffset = SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn4.sfcnOffset;
      int_T *sfcnTsMap = SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn4.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &SPERTE_printer_RC_M->NonInlinedSFcns.blkInfo2[4]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &SPERTE_printer_RC_M->NonInlinedSFcns.inputOutputPortInfo2[4]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, SPERTE_printer_RC_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &SPERTE_printer_RC_M->NonInlinedSFcns.methods2[4]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &SPERTE_printer_RC_M->NonInlinedSFcns.methods3[4]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &SPERTE_printer_RC_M->NonInlinedSFcns.methods4[4]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &SPERTE_printer_RC_M->NonInlinedSFcns.statesInfo2
                         [4]);
        ssSetPeriodicStatesInfo(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.periodicStatesInfo[4]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn4.inputPortInfo[0]);
        ssSetPortInfoForInputs(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn4.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn4.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn4.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn4.UPtrs0;
          sfcnUPtrs[0] = &SPERTE_printer_RC_B.Gain1;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn4.outputPortInfo[0]);
        ssSetPortInfoForOutputs(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn4.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn4.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn4.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &SPERTE_printer_RC_B.Dctpd2));
        }
      }

      /* path info */
      ssSetModelName(rts, "Dctpd2");
      ssSetPath(rts,
                "SPERTE_printer_RC/Printer/Supervisory Controller/homingController/Dctpd2");
      ssSetRTModel(rts,SPERTE_printer_RC_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn4.params;
        ssSetSFcnParamsCount(rts, 3);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)SPERTE_printer_RC_P.Dctpd2_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)SPERTE_printer_RC_P.Dctpd2_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)SPERTE_printer_RC_P.Dctpd2_P3_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &SPERTE_printer_RC_DW.Dctpd2_RWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn4.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn4.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        ssSetNumDWorkAsInt(rts, 1);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &SPERTE_printer_RC_DW.Dctpd2_RWORK[0]);
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

    /* Level2 S-Function Block: SPERTE_printer_RC/<S16>/Dct2lowpass3 (dlowpass2) */
    {
      SimStruct *rts = SPERTE_printer_RC_M->childSfunctions[5];

      /* timing info */
      time_T *sfcnPeriod = SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn5.sfcnPeriod;
      time_T *sfcnOffset = SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn5.sfcnOffset;
      int_T *sfcnTsMap = SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn5.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &SPERTE_printer_RC_M->NonInlinedSFcns.blkInfo2[5]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &SPERTE_printer_RC_M->NonInlinedSFcns.inputOutputPortInfo2[5]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, SPERTE_printer_RC_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &SPERTE_printer_RC_M->NonInlinedSFcns.methods2[5]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &SPERTE_printer_RC_M->NonInlinedSFcns.methods3[5]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &SPERTE_printer_RC_M->NonInlinedSFcns.methods4[5]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &SPERTE_printer_RC_M->NonInlinedSFcns.statesInfo2
                         [5]);
        ssSetPeriodicStatesInfo(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.periodicStatesInfo[5]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn5.inputPortInfo[0]);
        ssSetPortInfoForInputs(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn5.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn5.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn5.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn5.UPtrs0;
          sfcnUPtrs[0] = &SPERTE_printer_RC_B.Dctpd2;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn5.outputPortInfo[0]);
        ssSetPortInfoForOutputs(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn5.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn5.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn5.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &SPERTE_printer_RC_B.Dct2lowpass3));
        }
      }

      /* path info */
      ssSetModelName(rts, "Dct2lowpass3");
      ssSetPath(rts,
                "SPERTE_printer_RC/Printer/Supervisory Controller/homingController/Dct2lowpass3");
      ssSetRTModel(rts,SPERTE_printer_RC_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn5.params;
        ssSetSFcnParamsCount(rts, 3);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       SPERTE_printer_RC_P.Dct2lowpass3_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       SPERTE_printer_RC_P.Dct2lowpass3_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       SPERTE_printer_RC_P.Dct2lowpass3_P3_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &SPERTE_printer_RC_DW.Dct2lowpass3_RWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn5.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn5.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        ssSetNumDWorkAsInt(rts, 1);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 4);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &SPERTE_printer_RC_DW.Dct2lowpass3_RWORK[0]);
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

    /* Level2 S-Function Block: SPERTE_printer_RC/<S16>/Dctintegrator1 (dweakint_resettable) */
    {
      SimStruct *rts = SPERTE_printer_RC_M->childSfunctions[6];

      /* timing info */
      time_T *sfcnPeriod = SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn6.sfcnPeriod;
      time_T *sfcnOffset = SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn6.sfcnOffset;
      int_T *sfcnTsMap = SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn6.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &SPERTE_printer_RC_M->NonInlinedSFcns.blkInfo2[6]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &SPERTE_printer_RC_M->NonInlinedSFcns.inputOutputPortInfo2[6]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, SPERTE_printer_RC_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &SPERTE_printer_RC_M->NonInlinedSFcns.methods2[6]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &SPERTE_printer_RC_M->NonInlinedSFcns.methods3[6]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &SPERTE_printer_RC_M->NonInlinedSFcns.methods4[6]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &SPERTE_printer_RC_M->NonInlinedSFcns.statesInfo2
                         [6]);
        ssSetPeriodicStatesInfo(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.periodicStatesInfo[6]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn6.inputPortInfo[0]);
        ssSetPortInfoForInputs(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn6.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn6.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        ssSetInputPortUnit(rts, 1, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn6.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);
        ssSetInputPortIsContinuousQuantity(rts, 1, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn6.UPtrs0;
          sfcnUPtrs[0] = &SPERTE_printer_RC_B.Dct2lowpass3;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn6.UPtrs1;
          sfcnUPtrs[0] = &SPERTE_printer_RC_B.CastToDouble;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidthAsInt(rts, 1, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn6.outputPortInfo[0]);
        ssSetPortInfoForOutputs(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn6.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn6.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn6.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &SPERTE_printer_RC_B.Dctintegrator1));
        }
      }

      /* path info */
      ssSetModelName(rts, "Dctintegrator1");
      ssSetPath(rts,
                "SPERTE_printer_RC/Printer/Supervisory Controller/homingController/Dctintegrator1");
      ssSetRTModel(rts,SPERTE_printer_RC_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn6.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       SPERTE_printer_RC_P.Dctintegrator1_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       SPERTE_printer_RC_P.Dctintegrator1_P2_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &SPERTE_printer_RC_DW.Dctintegrator1_RWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn6.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn6.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        ssSetNumDWorkAsInt(rts, 1);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &SPERTE_printer_RC_DW.Dctintegrator1_RWORK[0]);
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

    /* Level2 S-Function Block: SPERTE_printer_RC/<S15>/Dctpd2 (dpd) */
    {
      SimStruct *rts = SPERTE_printer_RC_M->childSfunctions[7];

      /* timing info */
      time_T *sfcnPeriod = SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn7.sfcnPeriod;
      time_T *sfcnOffset = SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn7.sfcnOffset;
      int_T *sfcnTsMap = SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn7.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &SPERTE_printer_RC_M->NonInlinedSFcns.blkInfo2[7]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &SPERTE_printer_RC_M->NonInlinedSFcns.inputOutputPortInfo2[7]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, SPERTE_printer_RC_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &SPERTE_printer_RC_M->NonInlinedSFcns.methods2[7]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &SPERTE_printer_RC_M->NonInlinedSFcns.methods3[7]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &SPERTE_printer_RC_M->NonInlinedSFcns.methods4[7]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &SPERTE_printer_RC_M->NonInlinedSFcns.statesInfo2
                         [7]);
        ssSetPeriodicStatesInfo(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.periodicStatesInfo[7]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn7.inputPortInfo[0]);
        ssSetPortInfoForInputs(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn7.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn7.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn7.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn7.UPtrs0;
          sfcnUPtrs[0] = &SPERTE_printer_RC_B.Gain1_j;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn7.outputPortInfo[0]);
        ssSetPortInfoForOutputs(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn7.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn7.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn7.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &SPERTE_printer_RC_B.Dctpd2_k));
        }
      }

      /* path info */
      ssSetModelName(rts, "Dctpd2");
      ssSetPath(rts,
                "SPERTE_printer_RC/Printer/Supervisory Controller/airbagController/Dctpd2");
      ssSetRTModel(rts,SPERTE_printer_RC_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn7.params;
        ssSetSFcnParamsCount(rts, 3);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)SPERTE_printer_RC_P.Dctpd2_P1_Size_b);
        ssSetSFcnParam(rts, 1, (mxArray*)SPERTE_printer_RC_P.Dctpd2_P2_Size_l);
        ssSetSFcnParam(rts, 2, (mxArray*)SPERTE_printer_RC_P.Dctpd2_P3_Size_g);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &SPERTE_printer_RC_DW.Dctpd2_RWORK_p[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn7.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn7.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        ssSetNumDWorkAsInt(rts, 1);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &SPERTE_printer_RC_DW.Dctpd2_RWORK_p[0]);
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

    /* Level2 S-Function Block: SPERTE_printer_RC/<S15>/Dct2lowpass3 (dlowpass2) */
    {
      SimStruct *rts = SPERTE_printer_RC_M->childSfunctions[8];

      /* timing info */
      time_T *sfcnPeriod = SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn8.sfcnPeriod;
      time_T *sfcnOffset = SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn8.sfcnOffset;
      int_T *sfcnTsMap = SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn8.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &SPERTE_printer_RC_M->NonInlinedSFcns.blkInfo2[8]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &SPERTE_printer_RC_M->NonInlinedSFcns.inputOutputPortInfo2[8]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, SPERTE_printer_RC_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &SPERTE_printer_RC_M->NonInlinedSFcns.methods2[8]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &SPERTE_printer_RC_M->NonInlinedSFcns.methods3[8]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &SPERTE_printer_RC_M->NonInlinedSFcns.methods4[8]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &SPERTE_printer_RC_M->NonInlinedSFcns.statesInfo2
                         [8]);
        ssSetPeriodicStatesInfo(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.periodicStatesInfo[8]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn8.inputPortInfo[0]);
        ssSetPortInfoForInputs(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn8.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn8.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn8.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn8.UPtrs0;
          sfcnUPtrs[0] = &SPERTE_printer_RC_B.Dctpd2_k;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn8.outputPortInfo[0]);
        ssSetPortInfoForOutputs(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn8.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn8.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn8.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &SPERTE_printer_RC_B.Dct2lowpass3_o));
        }
      }

      /* path info */
      ssSetModelName(rts, "Dct2lowpass3");
      ssSetPath(rts,
                "SPERTE_printer_RC/Printer/Supervisory Controller/airbagController/Dct2lowpass3");
      ssSetRTModel(rts,SPERTE_printer_RC_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn8.params;
        ssSetSFcnParamsCount(rts, 3);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       SPERTE_printer_RC_P.Dct2lowpass3_P1_Size_f);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       SPERTE_printer_RC_P.Dct2lowpass3_P2_Size_k);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       SPERTE_printer_RC_P.Dct2lowpass3_P3_Size_j);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &SPERTE_printer_RC_DW.Dct2lowpass3_RWORK_c[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn8.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn8.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        ssSetNumDWorkAsInt(rts, 1);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 4);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &SPERTE_printer_RC_DW.Dct2lowpass3_RWORK_c[0]);
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

    /* Level2 S-Function Block: SPERTE_printer_RC/<S9>/Reset Encoder (ec_EboxResetEnc) */
    {
      SimStruct *rts = SPERTE_printer_RC_M->childSfunctions[9];

      /* timing info */
      time_T *sfcnPeriod = SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn9.sfcnPeriod;
      time_T *sfcnOffset = SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn9.sfcnOffset;
      int_T *sfcnTsMap = SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn9.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &SPERTE_printer_RC_M->NonInlinedSFcns.blkInfo2[9]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &SPERTE_printer_RC_M->NonInlinedSFcns.inputOutputPortInfo2[9]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, SPERTE_printer_RC_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &SPERTE_printer_RC_M->NonInlinedSFcns.methods2[9]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &SPERTE_printer_RC_M->NonInlinedSFcns.methods3[9]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &SPERTE_printer_RC_M->NonInlinedSFcns.methods4[9]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &SPERTE_printer_RC_M->NonInlinedSFcns.statesInfo2
                         [9]);
        ssSetPeriodicStatesInfo(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.periodicStatesInfo[9]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn9.inputPortInfo[0]);
        ssSetPortInfoForInputs(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn9.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn9.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn9.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn9.UPtrs0;
          sfcnUPtrs[0] = &SPERTE_printer_RC_B.resetEnc;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Reset Encoder");
      ssSetPath(rts,
                "SPERTE_printer_RC/Printer/Supervisory Controller/Reset Encoder");
      ssSetRTModel(rts,SPERTE_printer_RC_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &SPERTE_printer_RC_M->NonInlinedSFcns.Sfcn9.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       SPERTE_printer_RC_P.ResetEncoder_P1_Size);
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

  /* Start for S-Function (ec_Supervisor): '<S11>/S-Function' */
  /* Level2 S-Function Block: '<S11>/S-Function' (ec_Supervisor) */
  {
    SimStruct *rts = SPERTE_printer_RC_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for Enabled SubSystem: '<Root>/Reference' */
  SPERTE_printer_RC_DW.Reference_MODE = false;

  /* End of Start for SubSystem: '<Root>/Reference' */

  /* Start for Enabled SubSystem: '<Root>/Repetitive Controller' */
  SPERTE_printer_RC_DW.RepetitiveController_MODE = false;

  /* End of Start for SubSystem: '<Root>/Repetitive Controller' */

  /* Start for S-Function (dpd): '<S3>/Dctpd' */
  /* Level2 S-Function Block: '<S3>/Dctpd' (dpd) */
  {
    SimStruct *rts = SPERTE_printer_RC_M->childSfunctions[2];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (dlowpass2): '<S3>/Dct2lowpass' */
  /* Level2 S-Function Block: '<S3>/Dct2lowpass' (dlowpass2) */
  {
    SimStruct *rts = SPERTE_printer_RC_M->childSfunctions[3];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (dpd): '<S16>/Dctpd2' */
  /* Level2 S-Function Block: '<S16>/Dctpd2' (dpd) */
  {
    SimStruct *rts = SPERTE_printer_RC_M->childSfunctions[4];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (dlowpass2): '<S16>/Dct2lowpass3' */
  /* Level2 S-Function Block: '<S16>/Dct2lowpass3' (dlowpass2) */
  {
    SimStruct *rts = SPERTE_printer_RC_M->childSfunctions[5];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (dweakint_resettable): '<S16>/Dctintegrator1' */
  /* Level2 S-Function Block: '<S16>/Dctintegrator1' (dweakint_resettable) */
  {
    SimStruct *rts = SPERTE_printer_RC_M->childSfunctions[6];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (dpd): '<S15>/Dctpd2' */
  /* Level2 S-Function Block: '<S15>/Dctpd2' (dpd) */
  {
    SimStruct *rts = SPERTE_printer_RC_M->childSfunctions[7];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (dlowpass2): '<S15>/Dct2lowpass3' */
  /* Level2 S-Function Block: '<S15>/Dct2lowpass3' (dlowpass2) */
  {
    SimStruct *rts = SPERTE_printer_RC_M->childSfunctions[8];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  SPERTE_printer_RC_PrevZCX.Homingreference_Reset_ZCE = UNINITIALIZED_ZCSIG;

  {
    int32_T i;

    /* InitializeConditions for UnitDelay: '<S9>/Unit Delay1' */
    SPERTE_printer_RC_DW.UnitDelay1_DSTATE =
      SPERTE_printer_RC_P.UnitDelay1_InitialCondition;

    /* InitializeConditions for DiscreteIntegrator: '<S9>/Discrete-Time Integrator' */
    SPERTE_printer_RC_DW.DiscreteTimeIntegrator_DSTATE =
      SPERTE_printer_RC_P.DiscreteTimeIntegrator_IC;
    SPERTE_printer_RC_DW.DiscreteTimeIntegrator_PrevRese = 0;

    /* InitializeConditions for UnitDelay: '<S18>/UD' */
    SPERTE_printer_RC_DW.UD_DSTATE =
      SPERTE_printer_RC_P.DiscreteDerivative_ICPrevScaled;

    /* SystemInitialize for Chart: '<S9>/Supervisor' */
    SPERTE_printer_RC_DW.temporalCounter_i1 = 0U;
    SPERTE_printer_RC_DW.sfEvent = SPERTE_printer_RC_CALL_EVENT;
    SPERTE_printer_RC_B.jogSpeed = 0.0;
    SPERTE_printer_RC_B.toPoint = 0.0;
    SPERTE_printer_RC_B.homeControllerEnabled = 0.0;
    SPERTE_printer_RC_B.resetEnc = 0.0;
    SPERTE_printer_RC_B.homingBusy = 1.0;
    SPERTE_printer_RC_B.airBagEnabled = 0.0;
    SPERTE_printer_RC_B.airBagRef = 0.0;
    SPERTE_printer_RC_B.controlEnabled = 1.0;
    SPERTE_printer_RC_DW.is_active_c1_SPERTE_printer_RC = 0U;
    SPERTE_printer_RC_B.SupervisorMode = SupervisorModeType_None;

    /* SystemInitialize for Enabled SubSystem: '<Root>/Reference' */
    /* InitializeConditions for Sum: '<S4>/Sum1' incorporates:
     *  Memory: '<S4>/Memory'
     */
    SPERTE_printer_RC_DW.Memory_PreviousInput =
      SPERTE_printer_RC_P.Memory_InitialCondition_c;

    /* SystemInitialize for Product: '<S4>/Product' incorporates:
     *  Outport: '<S4>/RCactivate'
     */
    SPERTE_printer_RC_B.Product = SPERTE_printer_RC_P.RCactivate_Y0;

    /* SystemInitialize for Sum: '<S4>/Sum' incorporates:
     *  Outport: '<S4>/simulationTime'
     */
    SPERTE_printer_RC_B.Sum = SPERTE_printer_RC_P.simulationTime_Y0;

    /* SystemInitialize for LookupNDDirect: '<S4>/Direct Lookup Table ref1' incorporates:
     *  Outport: '<S4>/reference'
     *
     * About '<S4>/Direct Lookup Table ref1':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     *   */
    SPERTE_printer_RC_B.DirectLookupTableref1 = SPERTE_printer_RC_P.reference_Y0;

    /* End of SystemInitialize for SubSystem: '<Root>/Reference' */

    /* SystemInitialize for Enabled SubSystem: '<Root>/Repetitive Controller' */
    /* InitializeConditions for Delay: '<S5>/Delay' */
    SPERTE_printer_RC_DW.Delay_DSTATE[0] =
      SPERTE_printer_RC_P.Delay_InitialCondition;
    SPERTE_printer_RC_DW.Delay_DSTATE[1] =
      SPERTE_printer_RC_P.Delay_InitialCondition;
    SPERTE_printer_RC_DW.Delay_DSTATE[2] =
      SPERTE_printer_RC_P.Delay_InitialCondition;
    SPERTE_printer_RC_DW.Delay_DSTATE[3] =
      SPERTE_printer_RC_P.Delay_InitialCondition;

    /* InitializeConditions for Delay: '<S5>/Delay1' */
    for (i = 0; i < 1754; i++) {
      SPERTE_printer_RC_DW.Delay1_DSTATE[i] =
        SPERTE_printer_RC_P.Delay1_InitialCondition;
    }

    /* End of InitializeConditions for Delay: '<S5>/Delay1' */

    /* InitializeConditions for DiscreteStateSpace: '<S22>/Internal' */
    {
      int_T i1;
      real_T *dw_DSTATE = &SPERTE_printer_RC_DW.Internal_DSTATE[0];
      for (i1=0; i1 < 100; i1++) {
        dw_DSTATE[i1] = SPERTE_printer_RC_P.Internal_InitialCondition;
      }
    }

    /* InitializeConditions for DiscreteStateSpace: '<S23>/Internal' */
    {
      int_T i1;
      real_T *dw_DSTATE = &SPERTE_printer_RC_DW.Internal_DSTATE_l[0];
      for (i1=0; i1 < 10; i1++) {
        dw_DSTATE[i1] = SPERTE_printer_RC_P.Internal_InitialCondition_g;
      }
    }

    /* SystemInitialize for DiscreteStateSpace: '<S23>/Internal' incorporates:
     *  Outport: '<S5>/Output'
     */
    SPERTE_printer_RC_B.Internal = SPERTE_printer_RC_P.Output_Y0;

    /* End of SystemInitialize for SubSystem: '<Root>/Repetitive Controller' */

    /* SystemInitialize for Resettable SubSystem: '<S9>/Homing reference' */
    /* InitializeConditions for Sum: '<S13>/Sum1' incorporates:
     *  Memory: '<S13>/Memory'
     */
    SPERTE_printer_RC_DW.Memory_PreviousInput_g =
      SPERTE_printer_RC_P.Memory_InitialCondition;

    /* End of SystemInitialize for SubSystem: '<S9>/Homing reference' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/Measurement' */
    /* SystemInitialize for MATLAB Function: '<S6>/SPERTE_measurement_function' */
    for (i = 0; i < 20; i++) {
      SPERTE_printer_RC_DW.eml_autoflush[i] = false;
    }

    SPERTE_printer_RC_DW.eml_autoflush_not_empty = true;
    for (i = 0; i < 20; i++) {
      SPERTE_printer_RC_DW.eml_openfiles[i] = NULL;
    }

    SPERTE_printer_RC_DW.eml_openfiles_not_empty = true;
    SPERTE_printer_RC_DW.NF = 0;
    SPERTE_printer_RC_DW.NF_not_empty = true;
    SPERTE_printer_RC_DW.NS = 0U;
    SPERTE_printer_RC_DW.NS_not_empty = true;
    SPERTE_printer_RC_DW.fileID = 0.0;
    SPERTE_printer_RC_DW.fileID_not_empty = true;
    SPERTE_printer_RC_DW.busy = 0U;
    SPERTE_printer_RC_DW.busy_not_empty = true;
    SPERTE_printer_RC_DW.sfEvent_f = SPERTE_printer_RC_CALL_EVENT;

    /* End of SystemInitialize for MATLAB Function: '<S6>/SPERTE_measurement_function' */
    /* End of SystemInitialize for SubSystem: '<Root>/Measurement' */
  }
}

/* Model terminate function */
void SPERTE_printer_RC_terminate(void)
{
  /* Terminate for S-Function (ec_Supervisor): '<S11>/S-Function' */
  /* Level2 S-Function Block: '<S11>/S-Function' (ec_Supervisor) */
  {
    SimStruct *rts = SPERTE_printer_RC_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (ec_Ebox): '<S10>/ec_Ebox' */
  /* Level2 S-Function Block: '<S10>/ec_Ebox' (ec_Ebox) */
  {
    SimStruct *rts = SPERTE_printer_RC_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (dpd): '<S3>/Dctpd' */
  /* Level2 S-Function Block: '<S3>/Dctpd' (dpd) */
  {
    SimStruct *rts = SPERTE_printer_RC_M->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (dlowpass2): '<S3>/Dct2lowpass' */
  /* Level2 S-Function Block: '<S3>/Dct2lowpass' (dlowpass2) */
  {
    SimStruct *rts = SPERTE_printer_RC_M->childSfunctions[3];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (dpd): '<S16>/Dctpd2' */
  /* Level2 S-Function Block: '<S16>/Dctpd2' (dpd) */
  {
    SimStruct *rts = SPERTE_printer_RC_M->childSfunctions[4];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (dlowpass2): '<S16>/Dct2lowpass3' */
  /* Level2 S-Function Block: '<S16>/Dct2lowpass3' (dlowpass2) */
  {
    SimStruct *rts = SPERTE_printer_RC_M->childSfunctions[5];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (dweakint_resettable): '<S16>/Dctintegrator1' */
  /* Level2 S-Function Block: '<S16>/Dctintegrator1' (dweakint_resettable) */
  {
    SimStruct *rts = SPERTE_printer_RC_M->childSfunctions[6];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (dpd): '<S15>/Dctpd2' */
  /* Level2 S-Function Block: '<S15>/Dctpd2' (dpd) */
  {
    SimStruct *rts = SPERTE_printer_RC_M->childSfunctions[7];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (dlowpass2): '<S15>/Dct2lowpass3' */
  /* Level2 S-Function Block: '<S15>/Dct2lowpass3' (dlowpass2) */
  {
    SimStruct *rts = SPERTE_printer_RC_M->childSfunctions[8];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (ec_EboxResetEnc): '<S9>/Reset Encoder' */
  /* Level2 S-Function Block: '<S9>/Reset Encoder' (ec_EboxResetEnc) */
  {
    SimStruct *rts = SPERTE_printer_RC_M->childSfunctions[9];
    sfcnTerminate(rts);
  }
}
