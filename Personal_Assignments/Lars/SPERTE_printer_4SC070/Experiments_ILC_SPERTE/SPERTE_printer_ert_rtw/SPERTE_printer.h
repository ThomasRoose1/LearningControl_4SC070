/*
 * SPERTE_printer.h
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

#ifndef SPERTE_printer_h_
#define SPERTE_printer_h_
#ifndef SPERTE_printer_COMMON_INCLUDES_
#define SPERTE_printer_COMMON_INCLUDES_
#include <stdio.h>
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ext_mode.h"
#endif                                 /* SPERTE_printer_COMMON_INCLUDES_ */

#include "SPERTE_printer_types.h"
#include <stddef.h>
#include "rt_zcfcn.h"
#include "rt_nonfinite.h"
#include "rtGetNaN.h"
#include <string.h>
#include "zero_crossing_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetSampleHitArray
#define rtmGetSampleHitArray(rtm)      ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmGetStepSize
#define rtmGetStepSize(rtm)            ((rtm)->Timing.stepSize)
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
#define rtmGet_TimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmGetTStart
#define rtmGetTStart(rtm)              ((rtm)->Timing.tStart)
#endif

#ifndef rtmGetTimeOfLastOutput
#define rtmGetTimeOfLastOutput(rtm)    ((rtm)->Timing.timeOfLastOutput)
#endif

/* Block signals for system '<S1>/Triggered Single Pulse' */
typedef struct {
  real_T Product3;                     /* '<S8>/Product3' */
} B_TriggeredSinglePulse_SPERTE_T;

/* Block states (default storage) for system '<S1>/Triggered Single Pulse' */
typedef struct {
  real_T UnitDelay1_DSTATE;            /* '<S8>/Unit Delay1' */
  real_T UnitDelay_DSTATE;             /* '<S8>/Unit Delay' */
  uint8_T DelayInput1_DSTATE;          /* '<S10>/Delay Input1' */
} DW_TriggeredSinglePulse_SPERT_T;

/* Block signals for system '<S2>/Triggered Single Pulse1' */
typedef struct {
  real_T Product3;                     /* '<S15>/Product3' */
} B_TriggeredSinglePulse1_SPERT_T;

/* Block states (default storage) for system '<S2>/Triggered Single Pulse1' */
typedef struct {
  real_T UnitDelay1_DSTATE;            /* '<S15>/Unit Delay1' */
  real_T UnitDelay_DSTATE;             /* '<S15>/Unit Delay' */
  uint8_T DelayInput1_DSTATE;          /* '<S25>/Delay Input1' */
} DW_TriggeredSinglePulse1_SPER_T;

/* Block signals (default storage) */
typedef struct {
  real_T SFunction;                    /* '<S17>/S-Function' */
  real_T ec_Ebox_o1[2];                /* '<S16>/ec_Ebox' */
  real_T ec_Ebox_o2[2];                /* '<S16>/ec_Ebox' */
  real_T ec_Ebox_o3[8];                /* '<S16>/ec_Ebox' */
  real_T Gain[2];                      /* '<S16>/Gain' */
  real_T CountstoMeter1;               /* '<S13>/Counts to Meter1' */
  real_T RateTransition5;              /* '<S13>/Rate Transition5' */
  real_T active;                       /* '<Root>/active' */
  real_T Gain_c;                       /* '<S3>/Gain' */
  real_T Dctpd;                        /* '<S3>/Dctpd' */
  real_T Dct2lowpass;                  /* '<S3>/Dct2lowpass' */
  real_T Gain1;                        /* '<S22>/Gain1' */
  real_T Dctpd2;                       /* '<S22>/Dctpd2' */
  real_T Dct2lowpass3;                 /* '<S22>/Dct2lowpass3' */
  real_T CastToDouble;                 /* '<S22>/Cast To Double' */
  real_T Dctintegrator1;               /* '<S22>/Dctintegrator1' */
  real_T Gain1_j;                      /* '<S21>/Gain1' */
  real_T Dctpd2_k;                     /* '<S21>/Dctpd2' */
  real_T Dct2lowpass3_o;               /* '<S21>/Dct2lowpass3' */
  real_T Saturation[2];                /* '<S16>/Saturation' */
  real_T Clock;                        /* '<Root>/Clock' */
  real_T Sum1;                         /* '<S4>/Sum1' */
  real_T DirectLookupTableref;         /* '<S4>/Direct Lookup Table ref' */
  real_T DirectLookupTableff;          /* '<S4>/Direct Lookup Table ff' */
  real_T jogSpeed;                     /* '<S14>/Supervisor' */
  real_T toPoint;                      /* '<S14>/Supervisor' */
  real_T homeControllerEnabled;        /* '<S14>/Supervisor' */
  real_T resetEnc;                     /* '<S14>/Supervisor' */
  real_T homingBusy;                   /* '<S14>/Supervisor' */
  real_T airBagEnabled;                /* '<S14>/Supervisor' */
  real_T airBagRef;                    /* '<S14>/Supervisor' */
  real_T controlEnabled;               /* '<S14>/Supervisor' */
  SupervisorModeType SupervisorMode;   /* '<S14>/Supervisor' */
  uint8_T status;                      /* '<S7>/SPERTE_measurement_function' */
  boolean_T UnitDelay1;                /* '<S14>/Unit Delay1' */
  boolean_T LogicalOperator2;          /* '<S14>/Logical Operator2' */
  boolean_T Compare;                   /* '<S28>/Compare' */
  B_TriggeredSinglePulse_SPERTE_T TriggeredSinglePulse1_o;/* '<Root>/Triggered Single Pulse1' */
  B_TriggeredSinglePulse1_SPERT_T TriggeredSinglePulse;/* '<Root>/Triggered Single Pulse' */
  B_TriggeredSinglePulse1_SPERT_T TriggeredSinglePulse1;/* '<S2>/Triggered Single Pulse1' */
  B_TriggeredSinglePulse_SPERTE_T TriggeredSinglePulse_j;/* '<S1>/Triggered Single Pulse' */
} B_SPERTE_printer_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S14>/Discrete-Time Integrator' */
  real_T UD_DSTATE;                    /* '<S24>/UD' */
  real_T Memory_PreviousInput;         /* '<S4>/Memory' */
  real_T Memory_PreviousInput_g;       /* '<S19>/Memory' */
  real_T fileID;                       /* '<S7>/SPERTE_measurement_function' */
  real_T Dctpd_RWORK[2];               /* '<S3>/Dctpd' */
  real_T Dct2lowpass_RWORK[4];         /* '<S3>/Dct2lowpass' */
  real_T Dctpd2_RWORK[2];              /* '<S22>/Dctpd2' */
  real_T Dct2lowpass3_RWORK[4];        /* '<S22>/Dct2lowpass3' */
  real_T Dctintegrator1_RWORK[2];      /* '<S22>/Dctintegrator1' */
  real_T Dctpd2_RWORK_p[2];            /* '<S21>/Dctpd2' */
  real_T Dct2lowpass3_RWORK_c[4];      /* '<S21>/Dct2lowpass3' */
  FILE* eml_openfiles[20];             /* '<S7>/SPERTE_measurement_function' */
  int32_T sfEvent;                     /* '<S14>/Supervisor' */
  int32_T sfEvent_h;                   /* '<S7>/SPERTE_measurement_function' */
  uint32_T NS;                         /* '<S7>/SPERTE_measurement_function' */
  int16_T NF;                          /* '<S7>/SPERTE_measurement_function' */
  uint16_T temporalCounter_i1;         /* '<S14>/Supervisor' */
  boolean_T UnitDelay_DSTATE;          /* '<S2>/Unit Delay' */
  boolean_T UnitDelay1_DSTATE;         /* '<S14>/Unit Delay1' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S14>/Discrete-Time Integrator' */
  int8_T Reference_SubsysRanBC;        /* '<Root>/Reference' */
  uint8_T is_active_c1_SPERTE_printer; /* '<S14>/Supervisor' */
  uint8_T busy;                        /* '<S7>/SPERTE_measurement_function' */
  boolean_T doneDoubleBufferReInit;    /* '<S7>/SPERTE_measurement_function' */
  boolean_T fileID_not_empty;          /* '<S7>/SPERTE_measurement_function' */
  boolean_T NF_not_empty;              /* '<S7>/SPERTE_measurement_function' */
  boolean_T busy_not_empty;            /* '<S7>/SPERTE_measurement_function' */
  boolean_T NS_not_empty;              /* '<S7>/SPERTE_measurement_function' */
  boolean_T eml_openfiles_not_empty;   /* '<S7>/SPERTE_measurement_function' */
  boolean_T eml_autoflush[20];         /* '<S7>/SPERTE_measurement_function' */
  boolean_T eml_autoflush_not_empty;   /* '<S7>/SPERTE_measurement_function' */
  boolean_T Reference_MODE;            /* '<Root>/Reference' */
  DW_TriggeredSinglePulse_SPERT_T TriggeredSinglePulse1_o;/* '<Root>/Triggered Single Pulse1' */
  DW_TriggeredSinglePulse1_SPER_T TriggeredSinglePulse;/* '<Root>/Triggered Single Pulse' */
  DW_TriggeredSinglePulse1_SPER_T TriggeredSinglePulse1;/* '<S2>/Triggered Single Pulse1' */
  DW_TriggeredSinglePulse_SPERT_T TriggeredSinglePulse_j;/* '<S1>/Triggered Single Pulse' */
} DW_SPERTE_printer_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Homingreference_Reset_ZCE;/* '<S14>/Homing reference' */
} PrevZCX_SPERTE_printer_T;

/* Parameters for system: '<S1>/Triggered Single Pulse' */
struct P_TriggeredSinglePulse_SPERTE_T_ {
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S12>/Constant'
                                        */
  real_T UnitDelay1_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<S8>/Unit Delay1'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 1
                                        * Referenced by: '<S8>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S8>/Saturation'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S8>/Unit Delay'
                                        */
  real_T Constant2_Value;              /* Expression: 1
                                        * Referenced by: '<S8>/Constant2'
                                        */
  uint8_T DelayInput1_InitialCondition;
                             /* Computed Parameter: DelayInput1_InitialCondition
                              * Referenced by: '<S10>/Delay Input1'
                              */
};

/* Parameters for system: '<S2>/Triggered Single Pulse1' */
struct P_TriggeredSinglePulse1_SPERT_T_ {
  real_T UnitDelay1_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<S15>/Unit Delay1'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 1
                                        * Referenced by: '<S15>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S15>/Saturation'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S15>/Unit Delay'
                                        */
  real_T Constant2_Value;              /* Expression: 1
                                        * Referenced by: '<S15>/Constant2'
                                        */
  boolean_T Constant_Value;            /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S27>/Constant'
                                        */
  uint8_T DelayInput1_InitialCondition;
                             /* Computed Parameter: DelayInput1_InitialCondition
                              * Referenced by: '<S25>/Delay Input1'
                              */
};

/* Parameters (default storage) */
struct P_SPERTE_printer_T_ {
  real_T DiscreteDerivative_ICPrevScaled;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                               * Referenced by: '<S24>/UD'
                               */
  real_T _const;                       /* Mask Parameter: _const
                                        * Referenced by: '<S28>/Constant'
                                        */
  real_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S23>/Constant'
                                       */
  real_T TriggeredSinglePulse_p_wid;
                                   /* Mask Parameter: TriggeredSinglePulse_p_wid
                                    * Referenced by: '<S1>/Triggered Single Pulse'
                                    */
  real_T TriggeredSinglePulse1_p_wid;
                                  /* Mask Parameter: TriggeredSinglePulse1_p_wid
                                   * Referenced by: '<S2>/Triggered Single Pulse1'
                                   */
  real_T TriggeredSinglePulse1_p_wid_a;
                                /* Mask Parameter: TriggeredSinglePulse1_p_wid_a
                                 * Referenced by: '<Root>/Triggered Single Pulse1'
                                 */
  real_T TriggeredSinglePulse_p_wid_a;
                                 /* Mask Parameter: TriggeredSinglePulse_p_wid_a
                                  * Referenced by: '<Root>/Triggered Single Pulse'
                                  */
  uint32_T MeasurementBlock_N_samples;
                                   /* Mask Parameter: MeasurementBlock_N_samples
                                    * Referenced by: '<S7>/SPERTE_measurement_samples'
                                    */
  uint8_T MeasurementBlock_trigger_comman;
                              /* Mask Parameter: MeasurementBlock_trigger_comman
                               * Referenced by: '<S7>/SPERTE_measurement_trigger_command'
                               */
  uint8_T MeasurementBlock_triggertype;
                                 /* Mask Parameter: MeasurementBlock_triggertype
                                  * Referenced by: '<S7>/SPERTE_measurement_function'
                                  */
  real_T homing_ref_Value[600];
  /* Expression: [0           0  1.2531e-05  3.7594e-05  7.5188e-05  0.00012531  0.00018797  0.00026316  0.00035088  0.00045113  0.00056391  0.00068922  0.00082707  0.00097744   0.0011404   0.0013158   0.0015038   0.0017043   0.0019173   0.0021429    0.002381   0.0026316   0.0028947   0.0031704   0.0034586   0.0037594   0.0040727   0.0043985   0.0047368   0.0050877   0.0054511   0.0058271   0.0062155   0.0066165   0.0070301   0.0074561   0.0078947   0.0083459   0.0088095   0.0092857   0.0097744    0.010276    0.010789    0.011316    0.011855    0.012406     0.01297    0.013546    0.014135    0.014737    0.015351    0.015977    0.016617    0.017268    0.017932    0.018609    0.019298        0.02    0.020714    0.021441     0.02218    0.022932    0.023697    0.024474    0.025263    0.026065     0.02688    0.027707    0.028546    0.029398    0.030263     0.03114     0.03203    0.032932    0.033847    0.034774    0.035714    0.036667    0.037632    0.038609    0.039599    0.040602    0.041617    0.042644    0.043684    0.044737    0.045802     0.04688     0.04797    0.049073    0.050188    0.051316    0.052456    0.053609    0.054774    0.055952    0.057143    0.058346    0.059561    0.060789     0.06203    0.063283    0.064549    0.065827    0.067118    0.068421    0.069737    0.071065    0.072406    0.073759    0.075125    0.076504    0.077895    0.079298    0.080714    0.082143    0.083584    0.085038    0.086504    0.087982    0.089474    0.090977    0.092494    0.094023    0.095564    0.097118    0.098684     0.10026     0.10185     0.10346     0.10508      0.1067     0.10835        0.11     0.11167     0.11335     0.11504     0.11674     0.11846     0.12019     0.12193     0.12368     0.12545     0.12723     0.12902     0.13083     0.13264     0.13447     0.13632     0.13817     0.14004     0.14192     0.14381     0.14571     0.14763     0.14956      0.1515     0.15346     0.15543     0.15741      0.1594      0.1614     0.16342     0.16545     0.16749     0.16955     0.17162      0.1737     0.17579     0.17789     0.18001     0.18214     0.18429     0.18644     0.18861     0.19079     0.19298     0.19519     0.19741     0.19964     0.20188     0.20414      0.2064     0.20868     0.21098     0.21328      0.2156     0.21793     0.22028     0.22263       0.225     0.22738     0.22977     0.23218      0.2346     0.23703     0.23947     0.24193      0.2444     0.24688     0.24937     0.25188     0.25439     0.25689      0.2594      0.2619     0.26441     0.26692     0.26942     0.27193     0.27444     0.27694     0.27945     0.28195     0.28446     0.28697     0.28947     0.29198     0.29449     0.29699      0.2995     0.30201     0.30451     0.30702     0.30952     0.31203     0.31454     0.31704     0.31955     0.32206     0.32456     0.32707     0.32957     0.33208     0.33459     0.33709      0.3396     0.34211     0.34461     0.34712     0.34962     0.35213     0.35464     0.35714     0.35965     0.36216     0.36466     0.36717     0.36967     0.37218     0.37469     0.37719      0.3797     0.38221     0.38471     0.38722     0.38972     0.39223     0.39474     0.39724     0.39975     0.40226     0.40476     0.40727     0.40977     0.41228     0.41479     0.41729      0.4198     0.42231     0.42481     0.42732     0.42982     0.43233     0.43484     0.43734     0.43985     0.44236     0.44486     0.44737     0.44987     0.45238     0.45489     0.45739      0.4599     0.46241     0.46491     0.46742     0.46992     0.47243     0.47494     0.47744     0.47995     0.48246     0.48496     0.48747     0.48997     0.49248     0.49499     0.49749         0.5     0.50251     0.50501     0.50752     0.51003     0.51253     0.51504     0.51754     0.52005     0.52256     0.52506     0.52757     0.53008     0.53258     0.53509     0.53759      0.5401     0.54261     0.54511     0.54762     0.55013     0.55263     0.55514     0.55764     0.56015     0.56266     0.56516     0.56767     0.57018     0.57268     0.57519     0.57769      0.5802     0.58271     0.58521     0.58772     0.59023     0.59273     0.59524     0.59774     0.60025     0.60276     0.60526     0.60777     0.61028     0.61278     0.61529     0.61779      0.6203     0.62281     0.62531     0.62782     0.63033     0.63283     0.63534     0.63784     0.64035     0.64286     0.64536     0.64787     0.65038     0.65288     0.65539     0.65789      0.6604     0.66291     0.66541     0.66792     0.67043     0.67293     0.67544     0.67794     0.68045     0.68296     0.68546     0.68797     0.69048     0.69298     0.69549     0.69799      0.7005     0.70301     0.70551     0.70802     0.71053     0.71303     0.71554     0.71805     0.72055     0.72306     0.72556     0.72807     0.73058     0.73308     0.73559      0.7381      0.7406     0.74311     0.74561     0.74812     0.75063     0.75312      0.7556     0.75807     0.76053     0.76297      0.7654     0.76782     0.77023     0.77262       0.775     0.77737     0.77972     0.78207      0.7844     0.78672     0.78902     0.79132      0.7936     0.79586     0.79812     0.80036     0.80259     0.80481     0.80702     0.80921     0.81139     0.81356     0.81571     0.81786     0.81999     0.82211     0.82421      0.8263     0.82838     0.83045     0.83251     0.83455     0.83658      0.8386      0.8406     0.84259     0.84457     0.84654      0.8485     0.85044     0.85237     0.85429     0.85619     0.85808     0.85996     0.86183     0.86368     0.86553     0.86736     0.86917     0.87098     0.87277     0.87455     0.87632     0.87807     0.87981     0.88154     0.88326     0.88496     0.88665     0.88833        0.89     0.89165      0.8933     0.89492     0.89654     0.89815     0.89974     0.90132     0.90288     0.90444     0.90598     0.90751     0.90902     0.91053     0.91202      0.9135     0.91496     0.91642     0.91786     0.91929      0.9207     0.92211      0.9235     0.92487     0.92624     0.92759     0.92893     0.93026     0.93158     0.93288     0.93417     0.93545     0.93672     0.93797     0.93921     0.94044     0.94165     0.94286     0.94405     0.94523     0.94639     0.94754     0.94868     0.94981     0.95093     0.95203     0.95312      0.9542     0.95526     0.95632     0.95736     0.95838      0.9594      0.9604     0.96139     0.96237     0.96333     0.96429     0.96523     0.96615     0.96707     0.96797     0.96886     0.96974      0.9706     0.97145     0.97229     0.97312     0.97393     0.97474     0.97553      0.9763     0.97707     0.97782     0.97856     0.97929        0.98      0.9807     0.98139     0.98207     0.98273     0.98338     0.98402     0.98465     0.98526     0.98586     0.98645     0.98703     0.98759     0.98815     0.98868     0.98921     0.98972     0.99023     0.99071     0.99119     0.99165     0.99211     0.99254     0.99297     0.99338     0.99378     0.99417     0.99455     0.99491     0.99526      0.9956     0.99593     0.99624     0.99654     0.99683     0.99711     0.99737     0.99762     0.99786     0.99808      0.9983      0.9985     0.99868     0.99886     0.99902     0.99917     0.99931     0.99944     0.99955     0.99965     0.99974     0.99981     0.99987     0.99992     0.99996     0.99999           1]'
   * Referenced by: '<S19>/homing_ref'
   */
  real_T Memory_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S19>/Memory'
                                        */
  real_T One_Value;                    /* Expression: 1
                                        * Referenced by: '<S19>/One'
                                        */
  real_T HomingRunningSwitch_Threshold;/* Expression: 0.5
                                        * Referenced by: '<S14>/Homing Running Switch'
                                        */
  real_T Time_Y0;                      /* Computed Parameter: Time_Y0
                                        * Referenced by: '<S4>/Time'
                                        */
  real_T Feedforward_Y0;               /* Computed Parameter: Feedforward_Y0
                                        * Referenced by: '<S4>/Feedforward'
                                        */
  real_T Reference_Y0;                 /* Computed Parameter: Reference_Y0
                                        * Referenced by: '<S4>/Reference'
                                        */
  real_T set_ff_Value[4501];           /* Expression: zeros(4501,1)
                                        * Referenced by: '<S4>/set_ff'
                                        */
  real_T set_Ref_Value[4501];          /* Expression: zeros(4501,1)
                                        * Referenced by: '<S4>/set_Ref'
                                        */
  real_T Memory_InitialCondition_i;    /* Expression: 0
                                        * Referenced by: '<S4>/Memory'
                                        */
  real_T One_Value_f;                  /* Expression: 1
                                        * Referenced by: '<S4>/One'
                                        */
  real_T SFunction_P1_Size[2];         /* Computed Parameter: SFunction_P1_Size
                                        * Referenced by: '<S17>/S-Function'
                                        */
  real_T SFunction_P1;                 /* Expression: portid
                                        * Referenced by: '<S17>/S-Function'
                                        */
  real_T SFunction_P2_Size[2];         /* Computed Parameter: SFunction_P2_Size
                                        * Referenced by: '<S17>/S-Function'
                                        */
  real_T SFunction_P2;                 /* Expression: ectimeout
                                        * Referenced by: '<S17>/S-Function'
                                        */
  real_T ec_Ebox_P1_Size[2];           /* Computed Parameter: ec_Ebox_P1_Size
                                        * Referenced by: '<S16>/ec_Ebox'
                                        */
  real_T ec_Ebox_P1;                   /* Expression: link_id
                                        * Referenced by: '<S16>/ec_Ebox'
                                        */
  real_T Gain_Gain;                    /* Expression: 1/100
                                        * Referenced by: '<S16>/Gain'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S13>/Constant2'
                                        */
  real_T CountstoMeter1_Gain;          /* Expression: 1/(600*100/2.54)
                                        * Referenced by: '<S13>/Counts to Meter1'
                                        */
  real_T force_home_Value;             /* Expression: 0
                                        * Referenced by: '<S2>/force_home'
                                        */
  real_T active_Value;                 /* Expression: 0
                                        * Referenced by: '<Root>/active'
                                        */
  real_T Gain_Gain_j;                  /* Expression: 4
                                        * Referenced by: '<S3>/Gain'
                                        */
  real_T Dctpd_P1_Size[2];             /* Computed Parameter: Dctpd_P1_Size
                                        * Referenced by: '<S3>/Dctpd'
                                        */
  real_T Dctpd_P1;                     /* Expression: kp
                                        * Referenced by: '<S3>/Dctpd'
                                        */
  real_T Dctpd_P2_Size[2];             /* Computed Parameter: Dctpd_P2_Size
                                        * Referenced by: '<S3>/Dctpd'
                                        */
  real_T Dctpd_P2;                     /* Expression: kv
                                        * Referenced by: '<S3>/Dctpd'
                                        */
  real_T Dctpd_P3_Size[2];             /* Computed Parameter: Dctpd_P3_Size
                                        * Referenced by: '<S3>/Dctpd'
                                        */
  real_T Dctpd_P3;                     /* Expression: 0.001
                                        * Referenced by: '<S3>/Dctpd'
                                        */
  real_T Dct2lowpass_P1_Size[2];      /* Computed Parameter: Dct2lowpass_P1_Size
                                       * Referenced by: '<S3>/Dct2lowpass'
                                       */
  real_T Dct2lowpass_P1;               /* Expression: f_den
                                        * Referenced by: '<S3>/Dct2lowpass'
                                        */
  real_T Dct2lowpass_P2_Size[2];      /* Computed Parameter: Dct2lowpass_P2_Size
                                       * Referenced by: '<S3>/Dct2lowpass'
                                       */
  real_T Dct2lowpass_P2;               /* Expression: b_den
                                        * Referenced by: '<S3>/Dct2lowpass'
                                        */
  real_T Dct2lowpass_P3_Size[2];      /* Computed Parameter: Dct2lowpass_P3_Size
                                       * Referenced by: '<S3>/Dct2lowpass'
                                       */
  real_T Dct2lowpass_P3;               /* Expression: 0.001
                                        * Referenced by: '<S3>/Dct2lowpass'
                                        */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S14>/Discrete-Time Integrator'
                            */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S14>/Discrete-Time Integrator'
                                        */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S24>/TSamp'
                                        */
  real_T Gain1_Gain;                   /* Expression: 4
                                        * Referenced by: '<S22>/Gain1'
                                        */
  real_T Dctpd2_P1_Size[2];            /* Computed Parameter: Dctpd2_P1_Size
                                        * Referenced by: '<S22>/Dctpd2'
                                        */
  real_T Dctpd2_P1;                    /* Expression: kp
                                        * Referenced by: '<S22>/Dctpd2'
                                        */
  real_T Dctpd2_P2_Size[2];            /* Computed Parameter: Dctpd2_P2_Size
                                        * Referenced by: '<S22>/Dctpd2'
                                        */
  real_T Dctpd2_P2;                    /* Expression: kv
                                        * Referenced by: '<S22>/Dctpd2'
                                        */
  real_T Dctpd2_P3_Size[2];            /* Computed Parameter: Dctpd2_P3_Size
                                        * Referenced by: '<S22>/Dctpd2'
                                        */
  real_T Dctpd2_P3;                    /* Expression: 0.001
                                        * Referenced by: '<S22>/Dctpd2'
                                        */
  real_T Dct2lowpass3_P1_Size[2];    /* Computed Parameter: Dct2lowpass3_P1_Size
                                      * Referenced by: '<S22>/Dct2lowpass3'
                                      */
  real_T Dct2lowpass3_P1;              /* Expression: f_den
                                        * Referenced by: '<S22>/Dct2lowpass3'
                                        */
  real_T Dct2lowpass3_P2_Size[2];    /* Computed Parameter: Dct2lowpass3_P2_Size
                                      * Referenced by: '<S22>/Dct2lowpass3'
                                      */
  real_T Dct2lowpass3_P2;              /* Expression: b_den
                                        * Referenced by: '<S22>/Dct2lowpass3'
                                        */
  real_T Dct2lowpass3_P3_Size[2];    /* Computed Parameter: Dct2lowpass3_P3_Size
                                      * Referenced by: '<S22>/Dct2lowpass3'
                                      */
  real_T Dct2lowpass3_P3;              /* Expression: 0.001
                                        * Referenced by: '<S22>/Dct2lowpass3'
                                        */
  real_T Dctintegrator1_P1_Size[2];/* Computed Parameter: Dctintegrator1_P1_Size
                                    * Referenced by: '<S22>/Dctintegrator1'
                                    */
  real_T Dctintegrator1_P1;            /* Expression: f_num
                                        * Referenced by: '<S22>/Dctintegrator1'
                                        */
  real_T Dctintegrator1_P2_Size[2];/* Computed Parameter: Dctintegrator1_P2_Size
                                    * Referenced by: '<S22>/Dctintegrator1'
                                    */
  real_T Dctintegrator1_P2;            /* Expression: 0.001
                                        * Referenced by: '<S22>/Dctintegrator1'
                                        */
  real_T Gain1_Gain_j;                 /* Expression: 4
                                        * Referenced by: '<S21>/Gain1'
                                        */
  real_T Dctpd2_P1_Size_b[2];          /* Computed Parameter: Dctpd2_P1_Size_b
                                        * Referenced by: '<S21>/Dctpd2'
                                        */
  real_T Dctpd2_P1_m;                  /* Expression: kp
                                        * Referenced by: '<S21>/Dctpd2'
                                        */
  real_T Dctpd2_P2_Size_l[2];          /* Computed Parameter: Dctpd2_P2_Size_l
                                        * Referenced by: '<S21>/Dctpd2'
                                        */
  real_T Dctpd2_P2_n;                  /* Expression: kv
                                        * Referenced by: '<S21>/Dctpd2'
                                        */
  real_T Dctpd2_P3_Size_g[2];          /* Computed Parameter: Dctpd2_P3_Size_g
                                        * Referenced by: '<S21>/Dctpd2'
                                        */
  real_T Dctpd2_P3_d;                  /* Expression: 0.001
                                        * Referenced by: '<S21>/Dctpd2'
                                        */
  real_T Dct2lowpass3_P1_Size_f[2];/* Computed Parameter: Dct2lowpass3_P1_Size_f
                                    * Referenced by: '<S21>/Dct2lowpass3'
                                    */
  real_T Dct2lowpass3_P1_g;            /* Expression: f_den
                                        * Referenced by: '<S21>/Dct2lowpass3'
                                        */
  real_T Dct2lowpass3_P2_Size_k[2];/* Computed Parameter: Dct2lowpass3_P2_Size_k
                                    * Referenced by: '<S21>/Dct2lowpass3'
                                    */
  real_T Dct2lowpass3_P2_a;            /* Expression: b_den
                                        * Referenced by: '<S21>/Dct2lowpass3'
                                        */
  real_T Dct2lowpass3_P3_Size_j[2];/* Computed Parameter: Dct2lowpass3_P3_Size_j
                                    * Referenced by: '<S21>/Dct2lowpass3'
                                    */
  real_T Dct2lowpass3_P3_i;            /* Expression: 0.001
                                        * Referenced by: '<S21>/Dct2lowpass3'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 2.5
                                        * Referenced by: '<S13>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -2.5
                                        * Referenced by: '<S13>/Saturation'
                                        */
  real_T Saturation_UpperSat_l;        /* Expression: 10
                                        * Referenced by: '<S16>/Saturation'
                                        */
  real_T Saturation_LowerSat_o;        /* Expression: -10
                                        * Referenced by: '<S16>/Saturation'
                                        */
  real_T ResetEncoder_P1_Size[2];    /* Computed Parameter: ResetEncoder_P1_Size
                                      * Referenced by: '<S14>/Reset Encoder'
                                      */
  real_T ResetEncoder_P1;              /* Expression: link_id
                                        * Referenced by: '<S14>/Reset Encoder'
                                        */
  boolean_T ref_finished_Y0;           /* Computed Parameter: ref_finished_Y0
                                        * Referenced by: '<S4>/ref_finished'
                                        */
  boolean_T UnitDelay_InitialCondition;
                               /* Computed Parameter: UnitDelay_InitialCondition
                                * Referenced by: '<S2>/Unit Delay'
                                */
  boolean_T UnitDelay1_InitialCondition;
                              /* Computed Parameter: UnitDelay1_InitialCondition
                               * Referenced by: '<S14>/Unit Delay1'
                               */
  uint8_T signvBF_Gain;                /* Computed Parameter: signvBF_Gain
                                        * Referenced by: '<S18>/sign(v) BF'
                                        */
  P_TriggeredSinglePulse_SPERTE_T TriggeredSinglePulse1_o;/* '<Root>/Triggered Single Pulse1' */
  P_TriggeredSinglePulse1_SPERT_T TriggeredSinglePulse;/* '<Root>/Triggered Single Pulse' */
  P_TriggeredSinglePulse1_SPERT_T TriggeredSinglePulse1;/* '<S2>/Triggered Single Pulse1' */
  P_TriggeredSinglePulse_SPERTE_T TriggeredSinglePulse_j;/* '<S1>/Triggered Single Pulse' */
};

/* Real-time Model Data Structure */
struct tag_RTM_SPERTE_printer_T {
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;

  /*
   * NonInlinedSFcns:
   * The following substructure contains information regarding
   * non-inlined s-functions used in the model.
   */
  struct {
    RTWSfcnInfo sfcnInfo;
    time_T *taskTimePtrs[2];
    SimStruct childSFunctions[10];
    SimStruct *childSFunctionPtrs[10];
    struct _ssBlkInfo2 blkInfo2[10];
    struct _ssSFcnModelMethods2 methods2[10];
    struct _ssSFcnModelMethods3 methods3[10];
    struct _ssSFcnModelMethods4 methods4[10];
    struct _ssStatesInfo2 statesInfo2[10];
    ssPeriodicStatesInfo periodicStatesInfo[10];
    struct _ssPortInfo2 inputOutputPortInfo2[10];
    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn0;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[3];
      struct _ssInPortUnit inputPortUnits[3];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[3];
      real_T const *UPtrs0[2];
      real_T const *UPtrs1[2];
      real_T const *UPtrs2[8];
      struct _ssPortOutputs outputPortInfo[3];
      struct _ssOutPortUnit outputPortUnits[3];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[3];
      uint_T attribs[1];
      mxArray *params[1];
    } Sfcn1;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      real_T const *UPtrs0[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[3];
      mxArray *params[3];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn2;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      real_T const *UPtrs0[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[3];
      mxArray *params[3];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn3;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      real_T const *UPtrs0[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[3];
      mxArray *params[3];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn4;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      real_T const *UPtrs0[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[3];
      mxArray *params[3];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn5;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
      struct _ssInPortUnit inputPortUnits[2];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[2];
      real_T const *UPtrs0[1];
      real_T const *UPtrs1[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[2];
      mxArray *params[2];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn6;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      real_T const *UPtrs0[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[3];
      mxArray *params[3];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn7;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      real_T const *UPtrs0[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[3];
      mxArray *params[3];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn8;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      real_T const *UPtrs0[1];
      uint_T attribs[1];
      mxArray *params[1];
    } Sfcn9;
  } NonInlinedSFcns;

  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T stepSize1;
    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[2];
    time_T offsetTimesArray[2];
    int_T sampleTimeTaskIDArray[2];
    int_T sampleHitArray[2];
    int_T perTaskSampleHitsArray[4];
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_SPERTE_printer_T SPERTE_printer_P;

/* Block signals (default storage) */
extern B_SPERTE_printer_T SPERTE_printer_B;

/* Block states (default storage) */
extern DW_SPERTE_printer_T SPERTE_printer_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_SPERTE_printer_T SPERTE_printer_PrevZCX;

/* Model entry point functions */
extern void SPERTE_printer_initialize(void);
extern void SPERTE_printer_step(void);
extern void SPERTE_printer_terminate(void);

/* Real-time Model object */
extern RT_MODEL_SPERTE_printer_T *const SPERTE_printer_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S13>/Rate Transition12' : Unused code path elimination
 * Block '<S13>/Rate Transition13' : Unused code path elimination
 * Block '<S13>/Rate Transition15' : Unused code path elimination
 * Block '<S13>/Rate Transition16' : Unused code path elimination
 * Block '<S13>/Rate Transition17' : Unused code path elimination
 * Block '<S13>/Rate Transition18' : Unused code path elimination
 * Block '<S13>/Rate Transition19' : Unused code path elimination
 * Block '<S13>/Rate Transition20' : Unused code path elimination
 * Block '<S13>/Rate Transition21' : Unused code path elimination
 * Block '<S13>/Rate Transition22' : Unused code path elimination
 * Block '<S24>/Data Type Duplicate' : Unused code path elimination
 * Block '<S13>/Rate Transition14' : Eliminated since input and output rates are identical
 * Block '<S19>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S4>/Data Type Conversion' : Eliminate redundant data type conversion
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'SPERTE_printer'
 * '<S1>'   : 'SPERTE_printer/Measurement'
 * '<S2>'   : 'SPERTE_printer/Printer'
 * '<S3>'   : 'SPERTE_printer/Printer Controller'
 * '<S4>'   : 'SPERTE_printer/Reference'
 * '<S5>'   : 'SPERTE_printer/Triggered Single Pulse'
 * '<S6>'   : 'SPERTE_printer/Triggered Single Pulse1'
 * '<S7>'   : 'SPERTE_printer/Measurement/Measurement Block'
 * '<S8>'   : 'SPERTE_printer/Measurement/Triggered Single Pulse'
 * '<S9>'   : 'SPERTE_printer/Measurement/Measurement Block/SPERTE_measurement_function'
 * '<S10>'  : 'SPERTE_printer/Measurement/Triggered Single Pulse/+ve edge detect'
 * '<S11>'  : 'SPERTE_printer/Measurement/Triggered Single Pulse/Compare To Constant'
 * '<S12>'  : 'SPERTE_printer/Measurement/Triggered Single Pulse/+ve edge detect/Positive'
 * '<S13>'  : 'SPERTE_printer/Printer/E//BOX I-O'
 * '<S14>'  : 'SPERTE_printer/Printer/Supervisory Controller'
 * '<S15>'  : 'SPERTE_printer/Printer/Triggered Single Pulse1'
 * '<S16>'  : 'SPERTE_printer/Printer/E//BOX I-O/Ethercat E-box'
 * '<S17>'  : 'SPERTE_printer/Printer/E//BOX I-O/Ethercat Supervisor'
 * '<S18>'  : 'SPERTE_printer/Printer/Supervisory Controller/Homing feedforward'
 * '<S19>'  : 'SPERTE_printer/Printer/Supervisory Controller/Homing reference'
 * '<S20>'  : 'SPERTE_printer/Printer/Supervisory Controller/Supervisor'
 * '<S21>'  : 'SPERTE_printer/Printer/Supervisory Controller/airbagController'
 * '<S22>'  : 'SPERTE_printer/Printer/Supervisory Controller/homingController'
 * '<S23>'  : 'SPERTE_printer/Printer/Supervisory Controller/Homing feedforward/Compare To Constant'
 * '<S24>'  : 'SPERTE_printer/Printer/Supervisory Controller/Homing feedforward/Discrete Derivative'
 * '<S25>'  : 'SPERTE_printer/Printer/Triggered Single Pulse1/+ve edge detect'
 * '<S26>'  : 'SPERTE_printer/Printer/Triggered Single Pulse1/Compare To Constant'
 * '<S27>'  : 'SPERTE_printer/Printer/Triggered Single Pulse1/+ve edge detect/Positive'
 * '<S28>'  : 'SPERTE_printer/Reference/ '
 * '<S29>'  : 'SPERTE_printer/Triggered Single Pulse/+ve edge detect'
 * '<S30>'  : 'SPERTE_printer/Triggered Single Pulse/Compare To Constant'
 * '<S31>'  : 'SPERTE_printer/Triggered Single Pulse/+ve edge detect/Positive'
 * '<S32>'  : 'SPERTE_printer/Triggered Single Pulse1/+ve edge detect'
 * '<S33>'  : 'SPERTE_printer/Triggered Single Pulse1/Compare To Constant'
 * '<S34>'  : 'SPERTE_printer/Triggered Single Pulse1/+ve edge detect/Positive'
 */
#endif                                 /* SPERTE_printer_h_ */
