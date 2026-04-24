/*
 * SPERTE_printer.h
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
  real_T set_ff_Value[4501];
  /* Expression: [-11.9253     -10.1274     -8.39793     -6.75275     -5.21122      -3.7945     -2.52334     -1.41565    -0.484407     0.264024      0.83066      1.22398       1.4592      1.55704      1.54196      1.44033      1.27857      1.08144      0.87069     0.664136     0.475219     0.312998     0.182489    0.0852424    0.0200299    -0.016447   -0.0288663   -0.0226055  -0.00311172    0.0245796    0.0561113    0.0879155     0.117267       0.1423     0.161948      0.17583     0.184111     0.187362     0.186433     0.182328       0.1761     0.168763     0.161212     0.154186     0.148229      0.14369     0.140727     0.139333     0.139367      0.14059     0.142704     0.145385     0.148319     0.151222      0.15386     0.156059     0.157707     0.158754     0.159206     0.159113     0.158559     0.157649     0.156501     0.155231     0.153946     0.152738     0.151681     0.150826     0.150203      0.14982     0.149669     0.149725     0.149954     0.150315     0.150763     0.151255     0.151749     0.152212     0.152616     0.152943      0.15318     0.153326     0.153384     0.153363     0.153276     0.153141     0.152973     0.152791     0.152609     0.152441     0.152296     0.152182     0.152102     0.152057     0.152045     0.152061       0.1521     0.152155      0.15222     0.152289     0.152354     0.152413     0.152461     0.152497     0.152519     0.152529     0.152527     0.152516     0.152497     0.152474     0.152449     0.152424     0.152401     0.152382     0.152368     0.152358     0.152354     0.152353     0.152357     0.152363     0.152372     0.152381      0.15239     0.152398     0.152405     0.152411     0.152415     0.152417     0.152417     0.152416     0.152413      0.15241     0.152407     0.152404     0.152401     0.152398     0.152396     0.152395     0.152394     0.152394     0.152395     0.152395     0.152396     0.152397     0.152399       0.1524     0.152401     0.152401     0.152402     0.152402     0.152402     0.152402     0.152402     0.152401     0.152401       0.1524       0.1524       0.1524       0.1524     0.152399     0.152399     0.152399     0.152399     0.152399       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524       0.1524     0.152399     0.152399     0.152399     0.152399     0.152399     0.152399     0.152399     0.152399       0.1524       0.1524     0.152401     0.152401     0.152402     0.152403     0.152403     0.152403     0.152403     0.152403     0.152402     0.152401     0.152399     0.152398     0.152396     0.152394     0.152392     0.152391      0.15239      0.15239     0.152391     0.152393     0.152397     0.152401     0.152406     0.152411     0.152417     0.152422     0.152427     0.152429      0.15243     0.152428     0.152423     0.152415     0.152403     0.152389     0.152372     0.152355     0.152338     0.152323     0.152312     0.152306     0.152309      0.15232     0.152342     0.152373     0.152414     0.152462     0.152515     0.152569      0.15262     0.152661     0.152687     0.152693     0.152674     0.152625     0.152545     0.152435     0.152298      0.15214      0.15197     0.151802     0.151651     0.151534     0.151468     0.151469     0.151553     0.151729        0.152     0.152363     0.152806     0.153305     0.153828     0.154334     0.154775     0.155096     0.155243     0.155164     0.154818     0.154178     0.153236     0.152012     0.150559     0.148963      0.14735     0.145882      0.14476     0.144217     0.144509     0.145911     0.148703     0.153162     0.159546     0.168087     0.178982     0.192384     0.208403     0.227108     0.248525     0.272647     0.299445     0.328867     0.360854     0.395342     0.432268     0.471569      0.51318     0.557029     0.603023     0.651041     0.700912     0.752406     0.805219     0.858965     0.913171     0.967277      1.02065       1.0726      1.12242      1.16937      1.21279      1.25208      1.28676      1.31647      1.34107      1.36055      1.37508      1.38499      1.39067      1.39257      1.39109      1.38661      1.37945      1.36995       1.3586      1.34601      1.33287      1.31991      1.30786      1.29741      1.28916      1.28354      1.28083      1.28114      1.28438      1.29029      1.29845      1.30821      1.31872      1.32897      1.33795      1.34481        1.349      1.35029      1.34878      1.34489      1.33925       1.3326      1.32567       1.3191      1.31338      1.30887      1.30582      1.30435      1.30446      1.30609      1.30914      1.31356      1.31932      1.32643      1.33481      1.34431      1.35465      1.36545      1.37627      1.38667      1.39626      1.40469      1.41165      1.41688      1.42026      1.42182      1.42183      1.42069      1.41883      1.41663      1.41444      1.41258      1.41126      1.41058      1.41047       1.4108      1.41136      1.41188      1.41206      1.41159      1.41018      1.40748      1.40318      1.39705      1.38892      1.37877      1.36663      1.35259      1.33678       1.3194      1.30069      1.28093      1.26035      1.23913       1.2174      1.19525      1.17279      1.15016      1.12748      1.10489      1.08251       1.0605      1.03911       1.0187     0.999726     0.982615     0.967715     0.955244     0.945285     0.937785     0.932585     0.929481      0.92825     0.928648     0.930402     0.933193     0.936637      0.94031      0.94382     0.946848     0.949148     0.950525     0.950874     0.950212     0.948649     0.946309     0.943283     0.939648     0.935509     0.931033     0.926448     0.922021     0.918041     0.914791     0.912507     0.911343     0.911364     0.912557     0.914837     0.918054     0.922014     0.926499     0.931292     0.936196     0.941043     0.945694     0.950061     0.954118     0.957874     0.961334      0.96451     0.967461     0.970297     0.973177     0.976278     0.979771     0.983758     0.988226     0.993046     0.998039      1.00305      1.00799      1.01275      1.01721      1.02123      1.02474      1.02772      1.03016      1.03196      1.03296      1.03305      1.03222       1.0306      1.02835      1.02561      1.02247      1.01908      1.01562      1.01237      1.00959      1.00742      1.00588      1.00492       1.0044      1.00414       1.0039      1.00343      1.00257      1.00126     0.999503     0.997299     0.994623     0.991444     0.987744     0.983545     0.978923     0.973994     0.968897     0.963783      0.95875     0.953796     0.948843     0.943822     0.938718     0.933577     0.928493     0.923586     0.918982     0.914781     0.911045     0.907837     0.905265     0.903482     0.902612     0.902697     0.903678     0.905412     0.907708     0.910384     0.913315     0.916426     0.919636     0.922831     0.925883     0.928681     0.931134     0.933174     0.934739     0.935773     0.936282     0.936382     0.936277     0.936172     0.936201     0.936414     0.936825     0.937451     0.938311     0.939412     0.940743     0.942274      0.94396     0.945745      0.94756     0.949298     0.950815     0.951963     0.952646     0.952877     0.952772     0.952539     0.952441     0.952739     0.953628     0.955222     0.957574     0.960666     0.964399     0.968596      0.97303     0.977449     0.981577     0.985118     0.987809     0.989487     0.990127     0.989802     0.988624     0.986719     0.984259      0.98149     0.978704     0.976166     0.974083     0.972576     0.971644     0.971169     0.970968     0.970831     0.970534     0.969847     0.968523     0.966319     0.963067     0.958727     0.953379     0.947151     0.940182     0.932647     0.924781     0.916855     0.909108     0.901716     0.894806     0.888465      0.88273     0.877604     0.873113     0.869329     0.866317     0.864081     0.862551     0.861627     0.861229     0.861297     0.861783     0.862636     0.863811      0.86526     0.866933     0.868778     0.870712     0.872624     0.874407     0.875983     0.877311      0.87842     0.879426     0.880493     0.881779     0.883423     0.885589     0.888495       0.8924     0.897547     0.904092     0.912052     0.921278     0.931497     0.942389     0.953645     0.964975     0.976099     0.986758     0.996734      1.00588      1.01408      1.02124      1.02726       1.0321      1.03584      1.03863      1.04063      1.04192      1.04248      1.04223      1.04112      1.03915      1.03636      1.03275       1.0284      1.02343      1.01799      1.01225       1.0064      1.00069     0.995363     0.990664     0.986784      0.98386     0.981979     0.981196     0.981517     0.982885     0.985171     0.988182     0.991666     0.995338     0.998901      1.00208      1.00467       1.0066      1.00794      1.00892      1.00982      1.01089      1.01228      1.01405      1.01614      1.01851      1.02113      1.02397      1.02696      1.02992      1.03265      1.03491      1.03651      1.03731      1.03724      1.03633      1.03466       1.0324      1.02976      1.02698      1.02427      1.02188      1.01997       1.0187      1.01816       1.0184      1.01936      1.02089      1.02274      1.02463      1.02626      1.02735      1.02777      1.02746      1.02644      1.02482      1.02275      1.02047      1.01826      1.01642      1.01523      1.01491       1.0156      1.01735      1.02017      1.02394      1.02845      1.03347      1.03883      1.04431       1.0497      1.05468      1.05892      1.06215      1.06414      1.06475      1.06389      1.06152      1.05765      1.05233      1.04569      1.03794      1.02944      1.02067      1.01221      1.00464     0.998442     0.993957     0.991373     0.990759     0.992057     0.995087     0.999572      1.00513      1.01129      1.01746      1.02309      1.02766      1.03084      1.03252      1.03273      1.03164      1.02947      1.02647      1.02293      1.01914      1.01542      1.01205      1.00932      1.00745      1.00656      1.00675      1.00802      1.01028      1.01338      1.01702      1.02088      1.02462      1.02803      1.03097      1.03338      1.03518      1.03627      1.03652      1.03586       1.0343      1.03194      1.02899      1.02574      1.02248      1.01953      1.01712      1.01541      1.01445      1.01427      1.01491      1.01644       1.0189      1.02226      1.02636       1.0309      1.03551      1.03984      1.04359      1.04654      1.04863      1.04994      1.05067      1.05104      1.05124      1.05146      1.05185      1.05254       1.0536      1.05504      1.05679      1.05872      1.06063      1.06223      1.06322      1.06334      1.06245      1.06056      1.05779      1.05429      1.05022      1.04574      1.04111      1.03666      1.03271       1.0295      1.02714      1.02558      1.02463      1.02406      1.02364      1.02312      1.02228      1.02095      1.01909      1.01682      1.01433      1.01186      1.00964      1.00793      1.00703      1.00721      1.00865      1.01136      1.01525      1.02012      1.02576      1.03196      1.03853      1.04527      1.05195      1.05828        1.064      1.06895      1.07306      1.07635      1.07892      1.08087      1.08226      1.08316      1.08368      1.08395      1.08417       1.0845      1.08501      1.08575      1.08677      1.08815      1.09001      1.09245      1.09548      1.09899       1.1028      1.10675      1.11069      1.11444      1.11778       1.1204      1.12202      1.12238      1.12123      1.11829      1.11334      1.10621      1.09685      1.08527      1.07156      1.05581      1.03816      1.01869     0.997507     0.974771      0.95076     0.925819     0.900305     0.874558     0.848905      0.82368     0.799204     0.775761     0.753603     0.732949     0.713974     0.696812     0.681572     0.668325     0.657059      0.64766     0.639905     0.633504     0.628176     0.623707     0.619959     0.616843     0.614273     0.612147     0.610341     0.608704     0.607082     0.605373     0.603555     0.601653     0.599671     0.597538       0.5951     0.592185     0.588683     0.584566     0.579847     0.574566     0.568814     0.562754     0.556579     0.550469      0.54454     0.538843     0.533392     0.528213     0.523376     0.518987     0.515163     0.511962     0.509373     0.507346     0.505839     0.504818     0.504242     0.504068     0.504253     0.504708     0.505273     0.505781     0.506158     0.506484     0.506988     0.507999     0.509849      0.51276     0.516775      0.52175     0.527386     0.533252     0.538806     0.543406     0.546359     0.547018     0.544879     0.539645     0.531216      0.51969     0.505405     0.489004     0.471425     0.453783     0.437207     0.422704     0.411091     0.402967     0.398695     0.398395      0.40194     0.408945      0.41876     0.430519      0.44324     0.455891     0.467441     0.476934     0.483567     0.486779     0.486304     0.482169     0.474647       0.4642     0.451465     0.437226     0.422341     0.407643     0.393839     0.381453     0.370795     0.361939     0.354727     0.348783      0.34355     0.338333     0.332347     0.324763     0.314769     0.301623     0.284697     0.263519     0.237802     0.207452     0.172552      0.13334    0.0901772    0.0435379  -0.00600741   -0.0578184    -0.111219    -0.165527    -0.220077    -0.274247    -0.327477    -0.379282    -0.429263    -0.477123    -0.522688    -0.565901    -0.606804    -0.645502    -0.682126    -0.716792    -0.749557    -0.780387    -0.809137    -0.835569    -0.859427    -0.880499    -0.898637    -0.913779    -0.925984    -0.935484    -0.942675    -0.948059    -0.952215    -0.955831     -0.95972    -0.964744    -0.971712    -0.981304    -0.994008     -1.01004     -1.02933      -1.0515     -1.07599      -1.1021     -1.12904     -1.15602     -1.18226     -1.20706      -1.2299     -1.25045     -1.26857     -1.28432     -1.29783     -1.30938     -1.31934     -1.32813     -1.33618     -1.34378     -1.35111      -1.3582     -1.36499     -1.37131     -1.37702     -1.38203     -1.38637     -1.39016     -1.39358     -1.39678     -1.39991     -1.40315      -1.4066     -1.41031     -1.41424     -1.41825     -1.42219     -1.42593     -1.42942      -1.4326     -1.43542     -1.43774     -1.43948      -1.4406     -1.44111     -1.44098      -1.4401     -1.43834     -1.43556     -1.43172     -1.42679     -1.42078      -1.4137     -1.40548     -1.39607     -1.38549     -1.37385     -1.36128     -1.34797     -1.33408     -1.31976     -1.30511     -1.29019     -1.27498     -1.25941     -1.24335     -1.22668     -1.20928     -1.19111     -1.17222     -1.15272     -1.13277     -1.11258     -1.09242     -1.07263     -1.05361     -1.03574     -1.01942     -1.00499    -0.992782    -0.983051    -0.975966    -0.971512    -0.969457    -0.969436    -0.971065    -0.974013    -0.978002    -0.982791    -0.988113    -0.993641    -0.999034     -1.00403      -1.0085     -1.01239     -1.01573     -1.01863     -1.02126     -1.02384      -1.0265     -1.02935     -1.03243      -1.0358      -1.0395      -1.0435     -1.04769     -1.05189     -1.05587     -1.05938      -1.0622      -1.0641     -1.06489      -1.0644     -1.06249      -1.0591     -1.05429     -1.04821     -1.04109     -1.03321      -1.0249     -1.01649     -1.00835      -1.0008    -0.994054    -0.988199    -0.983289    -0.979362    -0.976439    -0.974507    -0.973492    -0.973231    -0.973456    -0.973836    -0.974073    -0.973968    -0.973423    -0.972428    -0.971044    -0.969366    -0.967497    -0.965548    -0.963636    -0.961841    -0.960211    -0.958763    -0.957473    -0.956248    -0.954938     -0.95335    -0.951285    -0.948607    -0.945267    -0.941307     -0.93683    -0.932004    -0.927061    -0.922285    -0.917977    -0.914452    -0.912063    -0.911185    -0.912149    -0.915157     -0.92022    -0.927153    -0.935609     -0.94513    -0.955183    -0.965209    -0.974688     -0.98318    -0.990343    -0.995952    -0.999883     -1.00208     -1.00259     -1.00156    -0.999279    -0.996121    -0.992521    -0.988943    -0.985849    -0.983673     -0.98278    -0.983424    -0.985692    -0.989464    -0.994424     -1.00011     -1.00598     -1.01146       -1.016     -1.01917     -1.02067     -1.02037     -1.01825      -1.0145     -1.00942      -1.0034     -0.99693    -0.990559    -0.984824      -0.9802    -0.977062    -0.975681    -0.976199    -0.978603     -0.98273    -0.988277    -0.994828      -1.0019     -1.00897     -1.01558     -1.02134     -1.02604     -1.02958     -1.03197     -1.03322     -1.03334     -1.03237      -1.0304     -1.02755     -1.02396     -1.01975     -1.01506        -1.01     -1.00471    -0.999351     -0.99406    -0.988969    -0.984157    -0.979663    -0.975526    -0.971801    -0.968538    -0.965768    -0.963478    -0.961603    -0.960042    -0.958661     -0.95733    -0.955966     -0.95456    -0.953158    -0.951819    -0.950572    -0.949432    -0.948463    -0.947791     -0.94755    -0.947816    -0.948595    -0.949816     -0.95135    -0.953037    -0.954725    -0.956309    -0.957731    -0.958945    -0.959905    -0.960573    -0.960936    -0.961007    -0.960835    -0.960491    -0.960074    -0.959711    -0.959546    -0.959694    -0.960229    -0.961177    -0.962514    -0.964148    -0.965907    -0.967516    -0.968614    -0.968825     -0.96786    -0.965568    -0.961923    -0.957015     -0.95105    -0.944336    -0.937243     -0.93013    -0.923325    -0.917137     -0.91186    -0.907753    -0.905002    -0.903689    -0.903775     -0.90511    -0.907451    -0.910483    -0.913852    -0.917194    -0.920163    -0.922471    -0.923923    -0.924455    -0.924152    -0.923205    -0.921842    -0.920329    -0.918976    -0.918098    -0.917916    -0.918492    -0.919748    -0.921498    -0.923479    -0.925383    -0.926913    -0.927795    -0.927778     -0.92665    -0.924267    -0.920595    -0.915722    -0.909854    -0.903329    -0.896637    -0.890399    -0.885259    -0.881756    -0.880253    -0.880925    -0.883776    -0.888678    -0.895389    -0.903584    -0.912911    -0.923005    -0.933486    -0.943978    -0.954137    -0.963681    -0.972402    -0.980142    -0.986796    -0.992352    -0.996947     -1.00086     -1.00444       -1.008      -1.0118     -1.01599     -1.02069     -1.02591      -1.0316     -1.03762     -1.04381     -1.04997     -1.05594     -1.06157     -1.06669     -1.07116     -1.07489     -1.07782     -1.07994     -1.08126     -1.08176     -1.08139      -1.0801     -1.07788     -1.07481     -1.07106     -1.06681     -1.06221     -1.05735      -1.0523      -1.0471     -1.04179     -1.03643     -1.03115     -1.02612     -1.02152     -1.01741     -1.01377     -1.01055     -1.00771      -1.0053     -1.00336     -1.00192     -1.00089     -1.00007    -0.999208    -0.998121     -0.99673    -0.994999    -0.992904    -0.990427    -0.987579    -0.984411    -0.981019    -0.977536    -0.974127    -0.970972    -0.968257    -0.966171    -0.964877    -0.964474     -0.96499    -0.966403    -0.968667    -0.971693    -0.975366    -0.979579    -0.984268      -0.9894    -0.994931      -1.0008     -1.00697      -1.0134     -1.02002      -1.0267     -1.03332     -1.03973     -1.04579     -1.05136     -1.05626     -1.06035     -1.06358     -1.06599     -1.06767     -1.06872     -1.06921     -1.06921     -1.06876     -1.06798     -1.06701     -1.06597     -1.06501     -1.06419     -1.06351     -1.06293     -1.06243     -1.06198     -1.06157     -1.06115     -1.06065     -1.05997     -1.05905      -1.0578     -1.05617     -1.05418     -1.05186     -1.04928     -1.04648     -1.04347     -1.04031     -1.03712     -1.03405     -1.03128     -1.02895     -1.02712     -1.02579     -1.02487     -1.02422     -1.02367     -1.02304     -1.02216     -1.02089     -1.01909      -1.0167     -1.01371     -1.01018     -1.00626     -1.00214    -0.998012    -0.994031    -0.990336    -0.987061    -0.984307    -0.982121    -0.980484    -0.979301    -0.978417    -0.977642    -0.976782    -0.975684    -0.974258     -0.97245    -0.970205    -0.967487    -0.964348    -0.960943    -0.957482    -0.954167    -0.951171    -0.948628    -0.946629    -0.945225    -0.944431    -0.944222    -0.944508    -0.945141    -0.945963    -0.946849    -0.947749    -0.948679    -0.949669    -0.950727    -0.951819    -0.952871    -0.953795    -0.954561    -0.955253    -0.956045    -0.957147    -0.958761    -0.961032    -0.964009    -0.967651    -0.971899    -0.976739    -0.982177    -0.988182    -0.994648      -1.0014     -1.00822     -1.01486      -1.0211     -1.02674     -1.03163     -1.03569     -1.03888     -1.04123     -1.04279     -1.04361     -1.04371     -1.04318     -1.04212     -1.04064     -1.03881     -1.03667     -1.03429     -1.03177     -1.02922     -1.02673     -1.02436     -1.02216     -1.02013     -1.01826     -1.01645     -1.01453     -1.01227     -1.00936     -1.00557     -1.00078    -0.994962    -0.988156    -0.980337    -0.971442    -0.961449    -0.950429    -0.938499    -0.925756    -0.912256    -0.898007    -0.882979    -0.867124    -0.850402    -0.832794     -0.81432    -0.795026    -0.774955    -0.754164    -0.732765    -0.710964    -0.689062    -0.667427    -0.646437    -0.626455    -0.607831    -0.590875     -0.57582     -0.56281    -0.551912    -0.543118    -0.536331    -0.531372    -0.528008    -0.525962    -0.524871    -0.524304    -0.523852    -0.523255    -0.522421    -0.521347    -0.520007    -0.518314    -0.516159    -0.513482    -0.510304    -0.506716    -0.502834    -0.498753    -0.494542    -0.490256    -0.485948    -0.481669    -0.477458    -0.473369    -0.469503    -0.466005    -0.463022    -0.460658    -0.458964    -0.457953    -0.457633    -0.458018    -0.459099    -0.460829    -0.463144    -0.465973    -0.469228    -0.472791    -0.476489    -0.480094    -0.483327    -0.485879    -0.487474    -0.487932    -0.487205    -0.485363    -0.482567    -0.479031    -0.474978      -0.4706    -0.466065    -0.461537    -0.457138    -0.452911    -0.448824    -0.444827     -0.44087    -0.436877    -0.432732    -0.428314    -0.423557    -0.418484    -0.413205    -0.407881    -0.402709    -0.397918    -0.393783    -0.390614    -0.388702    -0.388252    -0.389359    -0.392019     -0.39615    -0.401593    -0.408085    -0.415217    -0.422426    -0.429033    -0.434328    -0.437644    -0.438433    -0.436352    -0.431316     -0.42348    -0.413179    -0.400887    -0.387235    -0.373023    -0.359166    -0.346583    -0.336085    -0.328306    -0.323678    -0.322412    -0.324494     -0.32969     -0.33757    -0.347549    -0.358931    -0.370976    -0.382953    -0.394196    -0.404148    -0.412388    -0.418656    -0.422847    -0.425007    -0.425308    -0.424023     -0.42149    -0.418082    -0.414177    -0.410126    -0.406236    -0.402754    -0.399858    -0.397657    -0.396189    -0.395438    -0.395336    -0.395782    -0.396651     -0.39781    -0.399125    -0.400478    -0.401764    -0.402903     -0.40384    -0.404543    -0.405003    -0.405231    -0.405252    -0.405102    -0.404823     -0.40446    -0.404055    -0.403646    -0.403265    -0.402935    -0.402671    -0.402483    -0.402369    -0.402326    -0.402343    -0.402409    -0.402509     -0.40263    -0.402758    -0.402883    -0.402995    -0.403089     -0.40316    -0.403206     -0.40323    -0.403232    -0.403217    -0.403189    -0.403153    -0.403112    -0.403071    -0.403033       -0.403    -0.402974    -0.402956    -0.402946    -0.402942    -0.402945    -0.402953    -0.402964    -0.402977     -0.40299    -0.403003    -0.403014    -0.403023     -0.40303    -0.403034    -0.403036    -0.403036    -0.403034    -0.403031    -0.403027    -0.403022    -0.403018    -0.403014    -0.403011    -0.403008    -0.403007    -0.403006    -0.403006    -0.403006    -0.403007    -0.403009     -0.40301    -0.403012    -0.403013    -0.403014    -0.403015    -0.403015    -0.403016    -0.403016    -0.403016    -0.403015    -0.403015    -0.403014    -0.403014    -0.403014    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403014    -0.403014    -0.403014    -0.403014    -0.403014    -0.403014    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403013    -0.403014    -0.403014    -0.403014    -0.403014    -0.403014    -0.403014    -0.403014    -0.403014    -0.403014    -0.403013    -0.403013    -0.403012    -0.403012    -0.403011    -0.403011     -0.40301     -0.40301     -0.40301    -0.403011    -0.403012    -0.403013    -0.403014    -0.403016    -0.403018    -0.403019    -0.403021    -0.403022    -0.403023    -0.403023    -0.403022     -0.40302    -0.403017    -0.403013    -0.403008    -0.403002    -0.402996    -0.402991    -0.402987    -0.402984    -0.402983    -0.402985     -0.40299    -0.402998     -0.40301    -0.403024    -0.403041    -0.403058    -0.403075     -0.40309    -0.403102    -0.403108    -0.403106    -0.403095    -0.403075    -0.403044    -0.403004    -0.402956    -0.402903    -0.402848    -0.402796    -0.402752    -0.402723    -0.402713    -0.402729    -0.402773     -0.40285    -0.402957    -0.403094    -0.403253    -0.403427    -0.403602    -0.403763    -0.403893    -0.403975     -0.40399    -0.403922    -0.403761    -0.403499    -0.403139    -0.402691    -0.402176    -0.401625    -0.401079    -0.400588    -0.400208    -0.399998    -0.400014    -0.400306     -0.40091    -0.401838    -0.403081    -0.404591    -0.406286    -0.408041    -0.409688    -0.411019    -0.411788    -0.411718    -0.410512    -0.407862    -0.403466     -0.39704    -0.388331    -0.377129    -0.363277    -0.346676    -0.327285    -0.305119    -0.280242    -0.252757    -0.222796    -0.190504    -0.156029    -0.119507    -0.081052   -0.0407521   0.00133419     0.045174     0.090752     0.138058      0.18707     0.237737      0.28996     0.343576     0.398347     0.453949     0.509974     0.565942      0.62131     0.675502     0.727932     0.778038     0.825314     0.869334     0.909774     0.946419     0.979156      1.00796      1.03285      1.05387      1.07107      1.08451      1.09429      1.10058      1.10359      1.10357      1.10083      1.09573      1.08881       1.0807      1.07215      1.06401       1.0572      1.05266      1.05124      1.05368      1.06044      1.07174      1.08748      1.10727      1.13045      1.15611      1.18316      1.21038      1.23657      1.26066      1.28178      1.29935      1.31315      1.32321      1.32983      1.33347      1.33469      1.33408      1.33227      1.32986      1.32743      1.32549      1.32444       1.3246      1.32624      1.32958      1.33478      1.34195      1.35106      1.36192      1.37416      1.38733      1.40085      1.41416      1.42668      1.43789       1.4474      1.45497      1.46053      1.46412       1.4659      1.46606       1.4648      1.46236        1.459      1.45494      1.45041      1.44558      1.44056      1.43541      1.43011      1.42457      1.41865      1.41222      1.40508      1.39694      1.38754       1.3766      1.36389      1.34926      1.33268      1.31428       1.2943        1.273      1.25063      1.22736      1.20339      1.17898      1.15449      1.13037      1.10708      1.08499      1.06446      1.04588      1.02967      1.01627      1.00598     0.998865     0.994741     0.993236     0.993874     0.996121     0.999404      1.00311      1.00659      1.00918       1.0103      1.00951      1.00664      1.00179     0.995273     0.987573     0.979266     0.970915     0.963014     0.955967     0.950069     0.945503     0.942371     0.940694     0.940384     0.941233     0.942955     0.945225     0.947723     0.950164     0.952361     0.954266     0.955934     0.957469     0.959007      0.96072     0.962781     0.965317     0.968392     0.972015     0.976147     0.980709     0.985596      0.99068      0.99584      1.00102      1.00626       1.0117      1.01746      1.02361       1.0302      1.03716      1.04437       1.0516      1.05853      1.06484      1.07024      1.07455      1.07765      1.07946      1.07995      1.07914      1.07718      1.07429      1.07077      1.06694      1.06312      1.05954      1.05639       1.0538      1.05189      1.05074       1.0504       1.0508      1.05179      1.05317       1.0547      1.05604      1.05688      1.05699      1.05628      1.05477      1.05255      1.04968      1.04624      1.04229       1.0379      1.03316      1.02816        1.023       1.0178      1.01264      1.00755      1.00253     0.997532     0.992466     0.987231     0.981739     0.975962     0.969974     0.963929     0.957988     0.952302     0.947048     0.942481     0.938921     0.936675     0.935953     0.936829     0.939233     0.942966     0.947743     0.953262     0.959212     0.965251     0.970975     0.975955     0.979828     0.982381     0.983541     0.983322      0.98182     0.979261     0.976007     0.972506     0.969242     0.966646     0.965012      0.96449     0.965123     0.966861     0.969534     0.972846     0.976438     0.979975     0.983201     0.985967     0.988243     0.990084      0.99157     0.992782     0.993797     0.994703     0.995628     0.996761     0.998325       1.0005      1.00335       1.0068      1.01071      1.01488      1.01909      1.02307      1.02656      1.02933      1.03125      1.03227      1.03241      1.03173      1.03041      1.02864      1.02666      1.02461      1.02265      1.02088      1.01939      1.01823       1.0175      1.01726      1.01749      1.01803       1.0186      1.01887      1.01846      1.01702      1.01428      1.01008      1.00439     0.997297     0.989025     0.979909     0.970337     0.960665     0.951155     0.942017     0.933472     0.925746     0.919014     0.913369     0.908805     0.905222     0.902453     0.900292     0.898514     0.896906     0.895288     0.893525     0.891546     0.889361     0.887057     0.884819     0.882883     0.881467     0.880725     0.880759     0.881648     0.883466     0.886268     0.890049     0.894735      0.90023     0.906454     0.913338     0.920777     0.928592     0.936531     0.944355     0.951916     0.959178     0.966169     0.972912     0.979406     0.985648     0.991662     0.997504      1.00325      1.00895      1.01462      1.02024      1.02583      1.03147      1.03725      1.04315      1.04904      1.05471      1.05991      1.06441      1.06803      1.07062      1.07198      1.07199      1.07058      1.06781      1.06382      1.05881      1.05304      1.04673      1.04014      1.03354      1.02717      1.02128        1.016      1.01146      1.00774      1.00493      1.00311      1.00234      1.00262      1.00386      1.00591       1.0086      1.01181      1.01542      1.01936      1.02353      1.02781      1.03198      1.03586      1.03932      1.04233      1.04488      1.04692      1.04835      1.04907      1.04909      1.04849      1.04741      1.04603      1.04447      1.04289      1.04141      1.04015      1.03919      1.03857      1.03829      1.03835      1.03873      1.03946       1.0406      1.04216      1.04412      1.04641      1.04888      1.05138       1.0537      1.05562      1.05693      1.05749      1.05726      1.05628      1.05472      1.05276      1.05064      1.04861      1.04691      1.04572      1.04519      1.04548      1.04674      1.04905      1.05236      1.05652      1.06129      1.06637      1.07144       1.0762       1.0804      1.08383      1.08634       1.0878       1.0881      1.08717      1.08502      1.08171      1.07741      1.07231      1.06657      1.06036      1.05385      1.04727      1.04097      1.03525      1.03038      1.02649      1.02368      1.02195      1.02123      1.02138      1.02224      1.02366      1.02551      1.02763      1.02985      1.03194      1.03362      1.03463      1.03485      1.03429      1.03303      1.03123      1.02912       1.0269      1.02481      1.02306      1.02188      1.02152      1.02213      1.02382      1.02654      1.03014      1.03435       1.0388      1.04308       1.0468      1.04967       1.0515      1.05221      1.05177       1.0502      1.04761      1.04419      1.04026      1.03621       1.0325      1.02957      1.02778      1.02732      1.02829      1.03067      1.03432      1.03898      1.04428      1.04986      1.05533      1.06038      1.06474      1.06818      1.07054      1.07174       1.0718      1.07078      1.06888      1.06641      1.06377      1.06136      1.05955      1.05865      1.05885      1.06024      1.06276      1.06623       1.0703      1.07456      1.07854      1.08184      1.08414      1.08515      1.08467      1.08263      1.07914      1.07444      1.06888      1.06284      1.05674      1.05095      1.04584      1.04169      1.03868      1.03686      1.03611      1.03616      1.03667      1.03725      1.03757       1.0374      1.03663      1.03529      1.03354       1.0316      1.02968      1.02796      1.02663      1.02586      1.02589      1.02688      1.02891      1.03189      1.03566      1.03998      1.04465       1.0495      1.05442      1.05927      1.06393      1.06828      1.07226      1.07584      1.07907      1.08203      1.08486      1.08767      1.09053      1.09345      1.09643       1.0995      1.10262      1.10575      1.10879      1.11167      1.11435      1.11685      1.11915      1.12127      1.12325      1.12512      1.12688      1.12844      1.12971      1.13061      1.13112      1.13119      1.13068      1.12939      1.12706      1.12342      1.11819      1.11109      1.10187      1.09032       1.0763      1.05975      1.04072       1.0193     0.995747     0.970449      0.94393     0.916757     0.889479     0.862602     0.836566     0.811726     0.788385     0.766814      0.74724     0.729782     0.714435     0.701076     0.689495     0.679437     0.670658     0.662953      0.65614     0.650063       0.6446     0.639657     0.635146     0.630999     0.627201      0.62377     0.620712      0.61796     0.615389     0.612895     0.610435     0.607995     0.605551     0.603046     0.600377     0.597399     0.593983     0.590074     0.585717     0.581029     0.576129     0.571093     0.565962     0.560782     0.555616     0.550534     0.545594     0.540841     0.536306     0.532017     0.528019     0.524403     0.521276     0.518698     0.516646     0.515054     0.513884     0.513149     0.512883     0.513107     0.513815     0.514986     0.516593     0.518647     0.521241     0.524529     0.528634     0.533537     0.539036     0.544768     0.550248       0.5549     0.558116      0.55935     0.558172     0.554281     0.547541      0.53805     0.526165      0.51245     0.497582     0.482293     0.467343     0.453509     0.441559     0.432164     0.425801     0.422679     0.422757     0.425804     0.431452     0.439239     0.448612     0.458915      0.46939     0.479214      0.48757     0.493703     0.496984     0.496984     0.493523     0.486704      0.47689     0.464658     0.450732     0.435908     0.420973     0.406642       0.3935     0.381956     0.372209     0.364218     0.357713     0.352208     0.347046     0.341438     0.334527     0.325447     0.313388     0.297648     0.277685     0.253147     0.223882     0.189922     0.151457     0.108805    0.0623935    0.0127472   -0.0395399   -0.0938334    -0.149482     -0.20583    -0.262239    -0.318095    -0.372818    -0.425873    -0.476787    -0.525189    -0.570817    -0.613528    -0.653291    -0.690181    -0.724356    -0.756029    -0.785423    -0.812706     -0.83794    -0.861058    -0.881892    -0.900232    -0.915905    -0.928858    -0.939229    -0.947387    -0.953909    -0.959518    -0.964992    -0.971071     -0.97839    -0.987465    -0.998704     -1.01239     -1.02867     -1.04751     -1.06871     -1.09183     -1.11623     -1.14116     -1.16591     -1.18985     -1.21251     -1.23353     -1.25269     -1.26993     -1.28536     -1.29921     -1.31178     -1.32343     -1.33446     -1.34509     -1.35542      -1.3654     -1.37488     -1.38367     -1.39157     -1.39842     -1.40408     -1.40847     -1.41165     -1.41376     -1.41506     -1.41582     -1.41631     -1.41673      -1.4173     -1.41815     -1.41938     -1.42103     -1.42313     -1.42569     -1.42867     -1.43194     -1.43531     -1.43859     -1.44155     -1.44392     -1.44542     -1.44584     -1.44497     -1.44275     -1.43919     -1.43442     -1.42863     -1.42203     -1.41475     -1.40689     -1.39854     -1.38978     -1.38063     -1.37103     -1.36084     -1.34979     -1.33751     -1.32365      -1.3079     -1.29001     -1.26992     -1.24779     -1.22401     -1.19917     -1.17394     -1.14895     -1.12487     -1.10229     -1.08174     -1.06369      -1.0485     -1.03644     -1.02757     -1.02176      -1.0187     -1.01793     -1.01896     -1.02131     -1.02451     -1.02817     -1.03194      -1.0355     -1.03858     -1.04099     -1.04271     -1.04382     -1.04451     -1.04505     -1.04574     -1.04682      -1.0484     -1.05051     -1.05319     -1.05644     -1.06023     -1.06444     -1.06886     -1.07324      -1.0773     -1.08078     -1.08348     -1.08526     -1.08606     -1.08585     -1.08464     -1.08247     -1.07943     -1.07564     -1.07126     -1.06646     -1.06144     -1.05638     -1.05144      -1.0467     -1.04218     -1.03787     -1.03372     -1.02975     -1.02592     -1.02224      -1.0187     -1.01531     -1.01208     -1.00903     -1.00617     -1.00352     -1.00105    -0.998734    -0.996506    -0.994294    -0.992046    -0.989746    -0.987394     -0.98498    -0.982512    -0.980058     -0.97775    -0.975756    -0.974216    -0.973216    -0.972779    -0.972858    -0.973339    -0.974068    -0.974877    -0.975581     -0.97598    -0.975855    -0.974992    -0.973265    -0.970705    -0.967492    -0.963882    -0.960148    -0.956587     -0.95357    -0.951536    -0.950919    -0.952055    -0.955102    -0.960022    -0.966609    -0.974524     -0.98333    -0.992537     -1.00166     -1.01026     -1.01792     -1.02429     -1.02914     -1.03234     -1.03394     -1.03405     -1.03293     -1.03089     -1.02831     -1.02562     -1.02317     -1.02126      -1.0201     -1.01986     -1.02057     -1.02213     -1.02429     -1.02673     -1.02913     -1.03115     -1.03251     -1.03295     -1.03234     -1.03063     -1.02788     -1.02425        -1.02     -1.01545     -1.01095     -1.00685      -1.0034     -1.00084    -0.999372    -0.999133     -1.00018     -1.00249     -1.00594     -1.01032     -1.01538     -1.02082     -1.02634     -1.03168     -1.03654     -1.04068     -1.04393     -1.04621     -1.04751     -1.04785     -1.04727     -1.04583     -1.04364     -1.04079      -1.0374     -1.03358     -1.02941     -1.02497     -1.02032     -1.01551     -1.01059     -1.00561     -1.00063    -0.995732    -0.991002     -0.98655    -0.982495    -0.978957    -0.976057    -0.973909    -0.972599     -0.97214    -0.972456    -0.973401    -0.974796    -0.976456    -0.978198    -0.979821    -0.981123    -0.981957    -0.982288    -0.982184    -0.981766    -0.981147    -0.980403     -0.97961    -0.978861    -0.978257    -0.977872    -0.977743    -0.977856    -0.978148    -0.978528    -0.978889    -0.979124    -0.979155    -0.978947    -0.978514    -0.977925    -0.977292    -0.976736    -0.976342    -0.976122    -0.976017    -0.975939    -0.975802    -0.975531    -0.975068    -0.974359    -0.973315    -0.971811    -0.969757    -0.967154    -0.964076    -0.960611    -0.956816    -0.952747    -0.948492    -0.944167    -0.939901    -0.935828    -0.932083    -0.928798    -0.926109    -0.924145    -0.923013    -0.922773    -0.923402    -0.924775    -0.926709    -0.929014    -0.931541    -0.934199     -0.93694    -0.939724    -0.942487    -0.945147    -0.947612    -0.949777     -0.95152    -0.952696    -0.953154    -0.952766    -0.951457    -0.949202    -0.945997     -0.94186    -0.936847    -0.931096    -0.924845    -0.918453    -0.912389    -0.907185    -0.903338    -0.901237    -0.901137    -0.903168    -0.907331    -0.913475     -0.92129    -0.930325    -0.940059    -0.949968    -0.959581    -0.968513    -0.976486    -0.983319    -0.988903    -0.993215    -0.996372    -0.998659     -1.00049      -1.0023     -1.00447      -1.0073     -1.01103     -1.01585     -1.02182     -1.02885     -1.03673     -1.04517     -1.05386     -1.06249     -1.07077     -1.07839     -1.08506     -1.09052     -1.09463     -1.09737      -1.0988     -1.09902     -1.09814     -1.09638     -1.09405     -1.09154     -1.08917     -1.08713     -1.08551     -1.08428     -1.08332     -1.08247     -1.08152     -1.08021     -1.07827     -1.07546     -1.07163     -1.06674     -1.06094     -1.05448     -1.04763     -1.04068     -1.03387     -1.02746     -1.02171     -1.01684     -1.01298      -1.0101      -1.0081     -1.00683     -1.00609     -1.00565     -1.00531     -1.00486     -1.00412       -1.003     -1.00142    -0.999406    -0.997026    -0.994446    -0.991908    -0.989686    -0.988034    -0.987187    -0.987364    -0.988714    -0.991288    -0.995056    -0.999932     -1.00579     -1.01244     -1.01967     -1.02725     -1.03493     -1.04249     -1.04972     -1.05639     -1.06228     -1.06716     -1.07086     -1.07331     -1.07458     -1.07485     -1.07437     -1.07342     -1.07226     -1.07114     -1.07023     -1.06968      -1.0696      -1.0701     -1.07121     -1.07294     -1.07524     -1.07799     -1.08106     -1.08421     -1.08715     -1.08956     -1.09116     -1.09173     -1.09115      -1.0894     -1.08653      -1.0827     -1.07813     -1.07318     -1.06818     -1.06343     -1.05913     -1.05546     -1.05256     -1.05056     -1.04954     -1.04951      -1.0504     -1.05204     -1.05413     -1.05628       -1.058     -1.05886     -1.05854     -1.05693     -1.05407     -1.05014     -1.04542     -1.04019     -1.03472     -1.02922     -1.02394     -1.01908     -1.01485     -1.01137     -1.00867     -1.00664     -1.00504     -1.00358     -1.00203     -1.00024    -0.998167    -0.995786    -0.993105    -0.990133     -0.98688    -0.983394    -0.979806    -0.976334    -0.973226    -0.970691    -0.968845    -0.967705    -0.967204    -0.967214    -0.967573    -0.968137    -0.968806     -0.96951    -0.970164    -0.970623    -0.970692    -0.970208    -0.969118    -0.967516    -0.965601    -0.963622    -0.961824    -0.960423    -0.959605    -0.959515    -0.960254    -0.961893    -0.964478    -0.968005     -0.97239    -0.977467    -0.983039    -0.988937    -0.995035     -1.00122      -1.0074     -1.01349     -1.01943     -1.02522     -1.03085     -1.03635     -1.04171     -1.04687     -1.05169     -1.05604     -1.05983     -1.06304     -1.06564     -1.06754     -1.06859     -1.06864     -1.06757     -1.06533     -1.06197     -1.05768     -1.05273     -1.04745     -1.04219     -1.03732     -1.03314     -1.02989     -1.02761     -1.02622     -1.02555     -1.02531     -1.02518     -1.02478     -1.02373     -1.02164     -1.01817       -1.013     -1.00589    -0.996678    -0.985359     -0.97206    -0.956991    -0.940367    -0.922374    -0.903204    -0.883099    -0.862342    -0.841229    -0.820026    -0.798918    -0.778006    -0.757347    -0.736996    -0.717033    -0.697571    -0.678732    -0.660618    -0.643318    -0.626949    -0.611671    -0.597672    -0.585103    -0.574036    -0.564444    -0.556229    -0.549273    -0.543472    -0.538737    -0.534953    -0.531965    -0.529582     -0.52762    -0.525951    -0.524507    -0.523251    -0.522132    -0.521074    -0.519986    -0.518789    -0.517407    -0.515733    -0.513633     -0.51102    -0.507894    -0.504305    -0.500319     -0.49604    -0.491651    -0.487402    -0.483539    -0.480252    -0.477684    -0.475985    -0.475308    -0.475737    -0.477233     -0.47965    -0.482808     -0.48652    -0.490591    -0.494811    -0.498947    -0.502751     -0.50596    -0.508312    -0.509569     -0.50957    -0.508286    -0.505839    -0.502471    -0.498493    -0.494234    -0.489973    -0.485901    -0.482126    -0.478711    -0.475673    -0.472947    -0.470376    -0.467714    -0.464666    -0.460952    -0.456389    -0.450944    -0.444748    -0.438059    -0.431217    -0.424632    -0.418744    -0.413951    -0.410545    -0.408689    -0.408473    -0.409969    -0.413239    -0.418266    -0.424854    -0.432584    -0.440846    -0.448936    -0.456128    -0.461729    -0.465123     -0.46583    -0.463553    -0.458185    -0.449831    -0.438825    -0.425729    -0.411266    -0.396251    -0.381548     -0.36805    -0.356601    -0.347901    -0.342433    -0.340447    -0.341956    -0.346749    -0.354413    -0.364371     -0.37593    -0.388339    -0.400847    -0.412759    -0.423479    -0.432547    -0.439659    -0.444672    -0.447597    -0.448578     -0.44787      -0.4458    -0.442738    -0.439066    -0.435143     -0.43129    -0.427768     -0.42477    -0.422421    -0.420776     -0.41983    -0.419528    -0.419779    -0.420466    -0.421461    -0.422639    -0.423881    -0.425086    -0.426174    -0.427088    -0.427795    -0.428283    -0.428557     -0.42864    -0.428562     -0.42836    -0.428074    -0.427741    -0.427396    -0.427068    -0.426778    -0.426541    -0.426364    -0.426249    -0.426193    -0.426189    -0.426227    -0.426295    -0.426383     -0.42648    -0.426577    -0.426666    -0.426742    -0.426802    -0.426844    -0.426868    -0.426877    -0.426871    -0.426856    -0.426833    -0.426805    -0.426777    -0.426749    -0.426725    -0.426704    -0.426689    -0.426679    -0.426674    -0.426674    -0.426677    -0.426682     -0.42669    -0.426698    -0.426707    -0.426715    -0.426721    -0.426727    -0.426731    -0.426733    -0.426734    -0.426734    -0.426732     -0.42673    -0.426728    -0.426725    -0.426723    -0.426721    -0.426719    -0.426717    -0.426716    -0.426716    -0.426716    -0.426716    -0.426716    -0.426717    -0.426718    -0.426719    -0.426719     -0.42672    -0.426721    -0.426721    -0.426721    -0.426721    -0.426721    -0.426721    -0.426721    -0.426721    -0.426721     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672     -0.42672    -0.426721    -0.426721    -0.426721    -0.426721    -0.426721    -0.426721    -0.426721     -0.42672     -0.42672    -0.426719    -0.426718    -0.426718    -0.426717    -0.426717    -0.426717    -0.426717    -0.426718    -0.426718     -0.42672    -0.426721    -0.426723    -0.426725    -0.426727    -0.426728    -0.426729     -0.42673    -0.426729    -0.426728    -0.426725    -0.426721    -0.426716    -0.426711    -0.426705      -0.4267    -0.426695    -0.426692    -0.426691    -0.426692    -0.426697    -0.426705    -0.426716     -0.42673    -0.426746    -0.426764     -0.42678    -0.426795    -0.426805    -0.426808    -0.426804    -0.426791    -0.426768    -0.426735    -0.426693    -0.426645    -0.426594    -0.426544    -0.426501     -0.42647    -0.426457    -0.426466    -0.426503    -0.426569    -0.426664    -0.426784    -0.426924    -0.427074    -0.427222    -0.427352    -0.427449    -0.427496    -0.427478    -0.427383    -0.427205    -0.426942    -0.426602    -0.426203    -0.425769    -0.425335    -0.424942    -0.424637    -0.424466    -0.424473    -0.424694    -0.425153    -0.425854    -0.426781    -0.427893    -0.429124    -0.430383    -0.431558    -0.432521    -0.433143    -0.433295    -0.432869     -0.43179    -0.430025      -0.4276    -0.424605    -0.421202    -0.417619    -0.414145    -0.411118    -0.408898    -0.407843    -0.408276    -0.410449    -0.414506    -0.420453    -0.428128    -0.437187      -0.4471    -0.457163    -0.466524    -0.474236    -0.479316    -0.480827    -0.477961    -0.470138    -0.457092    -0.438948    -0.416285    -0.390166    -0.362135    -0.334176    -0.308625    -0.288042    -0.275045    -0.272107    -0.281335    -0.304242    -0.341524    -0.392868    -0.456809    -0.530637    -0.610401    -0.690988    -0.766307    -0.829561    -0.873618    -0.891447    -0.876611    -0.823794    -0.729311    -0.591586    -0.411557    -0.192957    0.0575329     0.330315     0.613097     0.891327      1.14885      1.36878      1.53463      1.63163      1.64822      1.57754      1.41866      1.17729     0.865713     0.501891      0.10754    -0.294297    -0.681158     -1.03205     -1.32802     -1.55325     -1.69655     -1.75252     -1.72196      -1.6116     -1.43335     -1.20295    -0.938546    -0.658998]'
   * Referenced by: '<S4>/set_ff'
   */
  real_T set_Ref_Value[4501];
  /* Expression: [0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0  3.3333e-08  2.6667e-07       9e-07  2.1333e-06  4.1667e-06     7.2e-06  1.1433e-05  1.7067e-05    2.43e-05  3.3333e-05  4.4367e-05    5.76e-05  7.3233e-05  9.1467e-05   0.0001125  0.00013653  0.00016377   0.0001944  0.00022863  0.00026667   0.0003087  0.00035493  0.00040557   0.0004608  0.00052083  0.00058583  0.00065583  0.00073083  0.00081083  0.00089583  0.00098583   0.0010808   0.0011808   0.0012858   0.0013958   0.0015108   0.0016308   0.0017558   0.0018858   0.0020208   0.0021608   0.0023058   0.0024558   0.0026108   0.0027708   0.0029358   0.0031058   0.0032808   0.0034608   0.0036458   0.0038358   0.0040308   0.0042308   0.0044358   0.0046458   0.0048608   0.0050808   0.0053058   0.0055358   0.0057708   0.0060108   0.0062558   0.0065058   0.0067608   0.0070208   0.0072858   0.0075558   0.0078308   0.0081108   0.0083958   0.0086858   0.0089808   0.0092808   0.0095858   0.0098958    0.010211    0.010531    0.010856    0.011186    0.011521    0.011861    0.012206    0.012556    0.012911    0.013271    0.013636    0.014006    0.014381    0.014761    0.015146    0.015536    0.015931    0.016331    0.016736    0.017146    0.017561    0.017981    0.018406    0.018836    0.019271    0.019711    0.020156    0.020605    0.021059    0.021517    0.021979    0.022444    0.022914    0.023387    0.023862    0.024341    0.024823    0.025308    0.025794    0.026283    0.026774    0.027267    0.027761    0.028257    0.028754    0.029252    0.029751     0.03025     0.03075     0.03125     0.03175     0.03225     0.03275     0.03325     0.03375     0.03425     0.03475     0.03525     0.03575     0.03625     0.03675     0.03725     0.03775     0.03825     0.03875     0.03925     0.03975     0.04025     0.04075     0.04125     0.04175     0.04225     0.04275     0.04325     0.04375     0.04425     0.04475     0.04525     0.04575     0.04625     0.04675     0.04725     0.04775     0.04825     0.04875     0.04925     0.04975     0.05025     0.05075     0.05125     0.05175     0.05225     0.05275     0.05325     0.05375     0.05425     0.05475     0.05525     0.05575     0.05625     0.05675     0.05725     0.05775     0.05825     0.05875     0.05925     0.05975     0.06025     0.06075     0.06125     0.06175     0.06225     0.06275     0.06325     0.06375     0.06425     0.06475     0.06525     0.06575     0.06625     0.06675     0.06725     0.06775     0.06825     0.06875     0.06925     0.06975     0.07025     0.07075     0.07125     0.07175     0.07225     0.07275     0.07325     0.07375     0.07425     0.07475     0.07525     0.07575     0.07625     0.07675     0.07725     0.07775     0.07825     0.07875     0.07925     0.07975     0.08025     0.08075     0.08125     0.08175     0.08225     0.08275     0.08325     0.08375     0.08425     0.08475     0.08525     0.08575     0.08625     0.08675     0.08725     0.08775     0.08825     0.08875     0.08925     0.08975     0.09025     0.09075     0.09125     0.09175     0.09225     0.09275     0.09325     0.09375     0.09425     0.09475     0.09525     0.09575     0.09625     0.09675     0.09725     0.09775     0.09825     0.09875     0.09925     0.09975     0.10025     0.10075     0.10125     0.10175     0.10225     0.10275     0.10325     0.10375     0.10425     0.10475     0.10525     0.10575     0.10625     0.10675     0.10725     0.10775     0.10825     0.10875     0.10925     0.10975     0.11025     0.11075     0.11125     0.11175     0.11225     0.11275     0.11325     0.11375     0.11425     0.11475     0.11525     0.11575     0.11625     0.11675     0.11725     0.11775     0.11825     0.11875     0.11925     0.11975     0.12025     0.12075     0.12125     0.12175     0.12225     0.12275     0.12325     0.12375     0.12425     0.12475     0.12525     0.12575     0.12625     0.12675     0.12725     0.12775     0.12825     0.12875     0.12925     0.12975     0.13025     0.13075     0.13125     0.13175     0.13225     0.13275     0.13325     0.13375     0.13425     0.13475     0.13525     0.13575     0.13625     0.13675     0.13725     0.13775     0.13825     0.13875     0.13925     0.13975     0.14025     0.14075     0.14125     0.14175     0.14225     0.14275     0.14325     0.14375     0.14425     0.14475     0.14525     0.14575     0.14625     0.14675     0.14725     0.14775     0.14825     0.14875     0.14925     0.14975     0.15025     0.15075     0.15125     0.15175     0.15225     0.15275     0.15325     0.15375     0.15425     0.15475     0.15525     0.15575     0.15625     0.15675     0.15725     0.15775     0.15825     0.15875     0.15925     0.15975     0.16025     0.16075     0.16125     0.16175     0.16225     0.16275     0.16325     0.16375     0.16425     0.16475     0.16525     0.16575     0.16625     0.16675     0.16725     0.16775     0.16825     0.16875     0.16925     0.16975     0.17025     0.17075     0.17125     0.17175     0.17225     0.17275     0.17325     0.17375     0.17425     0.17475     0.17525     0.17575     0.17625     0.17675     0.17725     0.17775     0.17825     0.17875     0.17925     0.17975     0.18025     0.18075     0.18125     0.18175     0.18225     0.18275     0.18325     0.18375     0.18425     0.18475     0.18525     0.18575     0.18625     0.18675     0.18725     0.18775     0.18825     0.18875     0.18925     0.18975     0.19025     0.19075     0.19125     0.19175     0.19225     0.19275     0.19325     0.19375     0.19425     0.19475     0.19525     0.19575     0.19625     0.19675     0.19725     0.19775     0.19825     0.19875     0.19925     0.19975     0.20025     0.20075     0.20125     0.20175     0.20225     0.20275     0.20325     0.20375     0.20425     0.20475     0.20525     0.20575     0.20625     0.20675     0.20725     0.20775     0.20825     0.20875     0.20925     0.20975     0.21025     0.21075     0.21125     0.21175     0.21225     0.21275     0.21325     0.21375     0.21425     0.21475     0.21525     0.21575     0.21625     0.21675     0.21725     0.21775     0.21825     0.21875     0.21925     0.21975     0.22025     0.22075     0.22125     0.22175     0.22225     0.22275     0.22325     0.22375     0.22425     0.22475     0.22525     0.22575     0.22625     0.22675     0.22725     0.22775     0.22825     0.22875     0.22925     0.22975     0.23025     0.23075     0.23125     0.23175     0.23225     0.23275     0.23325     0.23375     0.23425     0.23475     0.23525     0.23575     0.23625     0.23675     0.23725     0.23775     0.23825     0.23875     0.23925     0.23975     0.24025     0.24075     0.24125     0.24175     0.24225     0.24275     0.24325     0.24375     0.24425     0.24475     0.24525     0.24575     0.24625     0.24675     0.24725     0.24775     0.24825     0.24875     0.24925     0.24975     0.25025     0.25075     0.25125     0.25175     0.25225     0.25275     0.25325     0.25375     0.25425     0.25475     0.25525     0.25575     0.25625     0.25675     0.25725     0.25775     0.25825     0.25875     0.25925     0.25975     0.26025     0.26075     0.26125     0.26175     0.26225     0.26275     0.26325     0.26375     0.26425     0.26475     0.26525     0.26575     0.26625     0.26675     0.26725     0.26775     0.26825     0.26875     0.26925     0.26975     0.27025     0.27075     0.27125     0.27174     0.27224     0.27273     0.27323     0.27372     0.27421     0.27469     0.27518     0.27566     0.27614     0.27661     0.27709     0.27756     0.27802     0.27848     0.27894      0.2794     0.27984     0.28029     0.28073     0.28116     0.28159     0.28202     0.28244     0.28285     0.28326     0.28367     0.28407     0.28446     0.28485     0.28524     0.28562     0.28599     0.28636     0.28673     0.28709     0.28744     0.28779     0.28814     0.28848     0.28881     0.28914     0.28947     0.28979      0.2901     0.29041     0.29072     0.29102     0.29131      0.2916     0.29189     0.29217     0.29244     0.29271     0.29298     0.29324     0.29349     0.29374     0.29399     0.29423     0.29446     0.29469     0.29492     0.29514     0.29535     0.29556     0.29577     0.29597     0.29616     0.29635     0.29654     0.29672     0.29689     0.29706     0.29723     0.29739     0.29754     0.29769     0.29784     0.29798     0.29811     0.29824     0.29837     0.29849      0.2986     0.29871     0.29882     0.29892     0.29901      0.2991     0.29919     0.29927     0.29934     0.29941     0.29948     0.29954     0.29959     0.29965     0.29969     0.29973     0.29977     0.29981     0.29984     0.29986     0.29989     0.29991     0.29993     0.29994     0.29996     0.29997     0.29998     0.29998     0.29999     0.29999         0.3         0.3         0.3         0.3         0.3         0.3         0.3         0.3         0.3         0.3         0.3     0.29999     0.29999     0.29998     0.29998     0.29997     0.29996     0.29994     0.29993     0.29991     0.29989     0.29986     0.29984     0.29981     0.29977     0.29973     0.29969     0.29965     0.29959     0.29954     0.29948     0.29941     0.29934     0.29927     0.29919      0.2991     0.29901     0.29892     0.29882     0.29871      0.2986     0.29849     0.29837     0.29824     0.29811     0.29798     0.29784     0.29769     0.29754     0.29739     0.29723     0.29706     0.29689     0.29672     0.29654     0.29635     0.29616     0.29597     0.29577     0.29556     0.29535     0.29514     0.29492     0.29469     0.29446     0.29423     0.29399     0.29374     0.29349     0.29324     0.29298     0.29271     0.29244     0.29217     0.29189      0.2916     0.29131     0.29102     0.29072     0.29041      0.2901     0.28979     0.28947     0.28914     0.28881     0.28848     0.28814     0.28779     0.28744     0.28709     0.28673     0.28636     0.28599     0.28562     0.28524     0.28485     0.28446     0.28407     0.28367     0.28326     0.28285     0.28244     0.28202     0.28159     0.28116     0.28073     0.28029     0.27984      0.2794     0.27894     0.27848     0.27802     0.27756     0.27709     0.27661     0.27614     0.27566     0.27518     0.27469     0.27421     0.27372     0.27323     0.27273     0.27224     0.27174     0.27125     0.27075     0.27025     0.26975     0.26925     0.26875     0.26825     0.26775     0.26725     0.26675     0.26625     0.26575     0.26525     0.26475     0.26425     0.26375     0.26325     0.26275     0.26225     0.26175     0.26125     0.26075     0.26025     0.25975     0.25925     0.25875     0.25825     0.25775     0.25725     0.25675     0.25625     0.25575     0.25525     0.25475     0.25425     0.25375     0.25325     0.25275     0.25225     0.25175     0.25125     0.25075     0.25025     0.24975     0.24925     0.24875     0.24825     0.24775     0.24725     0.24675     0.24625     0.24575     0.24525     0.24475     0.24425     0.24375     0.24325     0.24275     0.24225     0.24175     0.24125     0.24075     0.24025     0.23975     0.23925     0.23875     0.23825     0.23775     0.23725     0.23675     0.23625     0.23575     0.23525     0.23475     0.23425     0.23375     0.23325     0.23275     0.23225     0.23175     0.23125     0.23075     0.23025     0.22975     0.22925     0.22875     0.22825     0.22775     0.22725     0.22675     0.22625     0.22575     0.22525     0.22475     0.22425     0.22375     0.22325     0.22275     0.22225     0.22175     0.22125     0.22075     0.22025     0.21975     0.21925     0.21875     0.21825     0.21775     0.21725     0.21675     0.21625     0.21575     0.21525     0.21475     0.21425     0.21375     0.21325     0.21275     0.21225     0.21175     0.21125     0.21075     0.21025     0.20975     0.20925     0.20875     0.20825     0.20775     0.20725     0.20675     0.20625     0.20575     0.20525     0.20475     0.20425     0.20375     0.20325     0.20275     0.20225     0.20175     0.20125     0.20075     0.20025     0.19975     0.19925     0.19875     0.19825     0.19775     0.19725     0.19675     0.19625     0.19575     0.19525     0.19475     0.19425     0.19375     0.19325     0.19275     0.19225     0.19175     0.19125     0.19075     0.19025     0.18975     0.18925     0.18875     0.18825     0.18775     0.18725     0.18675     0.18625     0.18575     0.18525     0.18475     0.18425     0.18375     0.18325     0.18275     0.18225     0.18175     0.18125     0.18075     0.18025     0.17975     0.17925     0.17875     0.17825     0.17775     0.17725     0.17675     0.17625     0.17575     0.17525     0.17475     0.17425     0.17375     0.17325     0.17275     0.17225     0.17175     0.17125     0.17075     0.17025     0.16975     0.16925     0.16875     0.16825     0.16775     0.16725     0.16675     0.16625     0.16575     0.16525     0.16475     0.16425     0.16375     0.16325     0.16275     0.16225     0.16175     0.16125     0.16075     0.16025     0.15975     0.15925     0.15875     0.15825     0.15775     0.15725     0.15675     0.15625     0.15575     0.15525     0.15475     0.15425     0.15375     0.15325     0.15275     0.15225     0.15175     0.15125     0.15075     0.15025     0.14975     0.14925     0.14875     0.14825     0.14775     0.14725     0.14675     0.14625     0.14575     0.14525     0.14475     0.14425     0.14375     0.14325     0.14275     0.14225     0.14175     0.14125     0.14075     0.14025     0.13975     0.13925     0.13875     0.13825     0.13775     0.13725     0.13675     0.13625     0.13575     0.13525     0.13475     0.13425     0.13375     0.13325     0.13275     0.13225     0.13175     0.13125     0.13075     0.13025     0.12975     0.12925     0.12875     0.12825     0.12775     0.12725     0.12675     0.12625     0.12575     0.12525     0.12475     0.12425     0.12375     0.12325     0.12275     0.12225     0.12175     0.12125     0.12075     0.12025     0.11975     0.11925     0.11875     0.11825     0.11775     0.11725     0.11675     0.11625     0.11575     0.11525     0.11475     0.11425     0.11375     0.11325     0.11275     0.11225     0.11175     0.11125     0.11075     0.11025     0.10975     0.10925     0.10875     0.10825     0.10775     0.10725     0.10675     0.10625     0.10575     0.10525     0.10475     0.10425     0.10375     0.10325     0.10275     0.10225     0.10175     0.10125     0.10075     0.10025     0.09975     0.09925     0.09875     0.09825     0.09775     0.09725     0.09675     0.09625     0.09575     0.09525     0.09475     0.09425     0.09375     0.09325     0.09275     0.09225     0.09175     0.09125     0.09075     0.09025     0.08975     0.08925     0.08875     0.08825     0.08775     0.08725     0.08675     0.08625     0.08575     0.08525     0.08475     0.08425     0.08375     0.08325     0.08275     0.08225     0.08175     0.08125     0.08075     0.08025     0.07975     0.07925     0.07875     0.07825     0.07775     0.07725     0.07675     0.07625     0.07575     0.07525     0.07475     0.07425     0.07375     0.07325     0.07275     0.07225     0.07175     0.07125     0.07075     0.07025     0.06975     0.06925     0.06875     0.06825     0.06775     0.06725     0.06675     0.06625     0.06575     0.06525     0.06475     0.06425     0.06375     0.06325     0.06275     0.06225     0.06175     0.06125     0.06075     0.06025     0.05975     0.05925     0.05875     0.05825     0.05775     0.05725     0.05675     0.05625     0.05575     0.05525     0.05475     0.05425     0.05375     0.05325     0.05275     0.05225     0.05175     0.05125     0.05075     0.05025     0.04975     0.04925     0.04875     0.04825     0.04775     0.04725     0.04675     0.04625     0.04575     0.04525     0.04475     0.04425     0.04375     0.04325     0.04275     0.04225     0.04175     0.04125     0.04075     0.04025     0.03975     0.03925     0.03875     0.03825     0.03775     0.03725     0.03675     0.03625     0.03575     0.03525     0.03475     0.03425     0.03375     0.03325     0.03275     0.03225     0.03175     0.03125     0.03075     0.03025    0.029751    0.029252    0.028754    0.028257    0.027761    0.027267    0.026774    0.026283    0.025794    0.025308    0.024823    0.024341    0.023862    0.023387    0.022914    0.022444    0.021979    0.021517    0.021059    0.020605    0.020156    0.019711    0.019271    0.018836    0.018406    0.017981    0.017561    0.017146    0.016736    0.016331    0.015931    0.015536    0.015146    0.014761    0.014381    0.014006    0.013636    0.013271    0.012911    0.012556    0.012206    0.011861    0.011521    0.011186    0.010856    0.010531    0.010211   0.0098958   0.0095858   0.0092808   0.0089808   0.0086858   0.0083958   0.0081108   0.0078308   0.0075558   0.0072858   0.0070208   0.0067608   0.0065058   0.0062558   0.0060108   0.0057708   0.0055358   0.0053058   0.0050808   0.0048608   0.0046458   0.0044358   0.0042308   0.0040308   0.0038358   0.0036458   0.0034608   0.0032808   0.0031058   0.0029358   0.0027708   0.0026108   0.0024558   0.0023058   0.0021608   0.0020208   0.0018858   0.0017558   0.0016308   0.0015108   0.0013958   0.0012858   0.0011808   0.0010808  0.00098583  0.00089583  0.00081083  0.00073083  0.00065583  0.00058583  0.00052083   0.0004608  0.00040557  0.00035493   0.0003087  0.00026667  0.00022863   0.0001944  0.00016377  0.00013653   0.0001125  9.1467e-05  7.3233e-05    5.76e-05  4.4367e-05  3.3333e-05    2.43e-05  1.7067e-05  1.1433e-05     7.2e-06  4.1667e-06  2.1333e-06       9e-07  2.6667e-07  3.3333e-08           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0  3.3333e-08  2.6667e-07       9e-07  2.1333e-06  4.1667e-06     7.2e-06  1.1433e-05  1.7067e-05    2.43e-05  3.3333e-05  4.4367e-05    5.76e-05  7.3233e-05  9.1467e-05   0.0001125  0.00013653  0.00016377   0.0001944  0.00022863  0.00026667   0.0003087  0.00035493  0.00040557   0.0004608  0.00052083  0.00058583  0.00065583  0.00073083  0.00081083  0.00089583  0.00098583   0.0010808   0.0011808   0.0012858   0.0013958   0.0015108   0.0016308   0.0017558   0.0018858   0.0020208   0.0021608   0.0023058   0.0024558   0.0026108   0.0027708   0.0029358   0.0031058   0.0032808   0.0034608   0.0036458   0.0038358   0.0040308   0.0042308   0.0044358   0.0046458   0.0048608   0.0050808   0.0053058   0.0055358   0.0057708   0.0060108   0.0062558   0.0065058   0.0067608   0.0070208   0.0072858   0.0075558   0.0078308   0.0081108   0.0083958   0.0086858   0.0089808   0.0092808   0.0095858   0.0098958    0.010211    0.010531    0.010856    0.011186    0.011521    0.011861    0.012206    0.012556    0.012911    0.013271    0.013636    0.014006    0.014381    0.014761    0.015146    0.015536    0.015931    0.016331    0.016736    0.017146    0.017561    0.017981    0.018406    0.018836    0.019271    0.019711    0.020156    0.020605    0.021059    0.021517    0.021979    0.022444    0.022914    0.023387    0.023862    0.024341    0.024823    0.025308    0.025794    0.026283    0.026774    0.027267    0.027761    0.028257    0.028754    0.029252    0.029751     0.03025     0.03075     0.03125     0.03175     0.03225     0.03275     0.03325     0.03375     0.03425     0.03475     0.03525     0.03575     0.03625     0.03675     0.03725     0.03775     0.03825     0.03875     0.03925     0.03975     0.04025     0.04075     0.04125     0.04175     0.04225     0.04275     0.04325     0.04375     0.04425     0.04475     0.04525     0.04575     0.04625     0.04675     0.04725     0.04775     0.04825     0.04875     0.04925     0.04975     0.05025     0.05075     0.05125     0.05175     0.05225     0.05275     0.05325     0.05375     0.05425     0.05475     0.05525     0.05575     0.05625     0.05675     0.05725     0.05775     0.05825     0.05875     0.05925     0.05975     0.06025     0.06075     0.06125     0.06175     0.06225     0.06275     0.06325     0.06375     0.06425     0.06475     0.06525     0.06575     0.06625     0.06675     0.06725     0.06775     0.06825     0.06875     0.06925     0.06975     0.07025     0.07075     0.07125     0.07175     0.07225     0.07275     0.07325     0.07375     0.07425     0.07475     0.07525     0.07575     0.07625     0.07675     0.07725     0.07775     0.07825     0.07875     0.07925     0.07975     0.08025     0.08075     0.08125     0.08175     0.08225     0.08275     0.08325     0.08375     0.08425     0.08475     0.08525     0.08575     0.08625     0.08675     0.08725     0.08775     0.08825     0.08875     0.08925     0.08975     0.09025     0.09075     0.09125     0.09175     0.09225     0.09275     0.09325     0.09375     0.09425     0.09475     0.09525     0.09575     0.09625     0.09675     0.09725     0.09775     0.09825     0.09875     0.09925     0.09975     0.10025     0.10075     0.10125     0.10175     0.10225     0.10275     0.10325     0.10375     0.10425     0.10475     0.10525     0.10575     0.10625     0.10675     0.10725     0.10775     0.10825     0.10875     0.10925     0.10975     0.11025     0.11075     0.11125     0.11175     0.11225     0.11275     0.11325     0.11375     0.11425     0.11475     0.11525     0.11575     0.11625     0.11675     0.11725     0.11775     0.11825     0.11875     0.11925     0.11975     0.12025     0.12075     0.12125     0.12175     0.12225     0.12275     0.12325     0.12375     0.12425     0.12475     0.12525     0.12575     0.12625     0.12675     0.12725     0.12775     0.12825     0.12875     0.12925     0.12975     0.13025     0.13075     0.13125     0.13175     0.13225     0.13275     0.13325     0.13375     0.13425     0.13475     0.13525     0.13575     0.13625     0.13675     0.13725     0.13775     0.13825     0.13875     0.13925     0.13975     0.14025     0.14075     0.14125     0.14175     0.14225     0.14275     0.14325     0.14375     0.14425     0.14475     0.14525     0.14575     0.14625     0.14675     0.14725     0.14775     0.14825     0.14875     0.14925     0.14975     0.15025     0.15075     0.15125     0.15175     0.15225     0.15275     0.15325     0.15375     0.15425     0.15475     0.15525     0.15575     0.15625     0.15675     0.15725     0.15775     0.15825     0.15875     0.15925     0.15975     0.16025     0.16075     0.16125     0.16175     0.16225     0.16275     0.16325     0.16375     0.16425     0.16475     0.16525     0.16575     0.16625     0.16675     0.16725     0.16775     0.16825     0.16875     0.16925     0.16975     0.17025     0.17075     0.17125     0.17175     0.17225     0.17275     0.17325     0.17375     0.17425     0.17475     0.17525     0.17575     0.17625     0.17675     0.17725     0.17775     0.17825     0.17875     0.17925     0.17975     0.18025     0.18075     0.18125     0.18175     0.18225     0.18275     0.18325     0.18375     0.18425     0.18475     0.18525     0.18575     0.18625     0.18675     0.18725     0.18775     0.18825     0.18875     0.18925     0.18975     0.19025     0.19075     0.19125     0.19175     0.19225     0.19275     0.19325     0.19375     0.19425     0.19475     0.19525     0.19575     0.19625     0.19675     0.19725     0.19775     0.19825     0.19875     0.19925     0.19975     0.20025     0.20075     0.20125     0.20175     0.20225     0.20275     0.20325     0.20375     0.20425     0.20475     0.20525     0.20575     0.20625     0.20675     0.20725     0.20775     0.20825     0.20875     0.20925     0.20975     0.21025     0.21075     0.21125     0.21175     0.21225     0.21275     0.21325     0.21375     0.21425     0.21475     0.21525     0.21575     0.21625     0.21675     0.21725     0.21775     0.21825     0.21875     0.21925     0.21975     0.22025     0.22075     0.22125     0.22175     0.22225     0.22275     0.22325     0.22375     0.22425     0.22475     0.22525     0.22575     0.22625     0.22675     0.22725     0.22775     0.22825     0.22875     0.22925     0.22975     0.23025     0.23075     0.23125     0.23175     0.23225     0.23275     0.23325     0.23375     0.23425     0.23475     0.23525     0.23575     0.23625     0.23675     0.23725     0.23775     0.23825     0.23875     0.23925     0.23975     0.24025     0.24075     0.24125     0.24175     0.24225     0.24275     0.24325     0.24375     0.24425     0.24475     0.24525     0.24575     0.24625     0.24675     0.24725     0.24775     0.24825     0.24875     0.24925     0.24975     0.25025     0.25075     0.25125     0.25175     0.25225     0.25275     0.25325     0.25375     0.25425     0.25475     0.25525     0.25575     0.25625     0.25675     0.25725     0.25775     0.25825     0.25875     0.25925     0.25975     0.26025     0.26075     0.26125     0.26175     0.26225     0.26275     0.26325     0.26375     0.26425     0.26475     0.26525     0.26575     0.26625     0.26675     0.26725     0.26775     0.26825     0.26875     0.26925     0.26975     0.27025     0.27075     0.27125     0.27174     0.27224     0.27273     0.27323     0.27372     0.27421     0.27469     0.27518     0.27566     0.27614     0.27661     0.27709     0.27756     0.27802     0.27848     0.27894      0.2794     0.27984     0.28029     0.28073     0.28116     0.28159     0.28202     0.28244     0.28285     0.28326     0.28367     0.28407     0.28446     0.28485     0.28524     0.28562     0.28599     0.28636     0.28673     0.28709     0.28744     0.28779     0.28814     0.28848     0.28881     0.28914     0.28947     0.28979      0.2901     0.29041     0.29072     0.29102     0.29131      0.2916     0.29189     0.29217     0.29244     0.29271     0.29298     0.29324     0.29349     0.29374     0.29399     0.29423     0.29446     0.29469     0.29492     0.29514     0.29535     0.29556     0.29577     0.29597     0.29616     0.29635     0.29654     0.29672     0.29689     0.29706     0.29723     0.29739     0.29754     0.29769     0.29784     0.29798     0.29811     0.29824     0.29837     0.29849      0.2986     0.29871     0.29882     0.29892     0.29901      0.2991     0.29919     0.29927     0.29934     0.29941     0.29948     0.29954     0.29959     0.29965     0.29969     0.29973     0.29977     0.29981     0.29984     0.29986     0.29989     0.29991     0.29993     0.29994     0.29996     0.29997     0.29998     0.29998     0.29999     0.29999         0.3         0.3         0.3         0.3         0.3         0.3         0.3         0.3         0.3         0.3         0.3     0.29999     0.29999     0.29998     0.29998     0.29997     0.29996     0.29994     0.29993     0.29991     0.29989     0.29986     0.29984     0.29981     0.29977     0.29973     0.29969     0.29965     0.29959     0.29954     0.29948     0.29941     0.29934     0.29927     0.29919      0.2991     0.29901     0.29892     0.29882     0.29871      0.2986     0.29849     0.29837     0.29824     0.29811     0.29798     0.29784     0.29769     0.29754     0.29739     0.29723     0.29706     0.29689     0.29672     0.29654     0.29635     0.29616     0.29597     0.29577     0.29556     0.29535     0.29514     0.29492     0.29469     0.29446     0.29423     0.29399     0.29374     0.29349     0.29324     0.29298     0.29271     0.29244     0.29217     0.29189      0.2916     0.29131     0.29102     0.29072     0.29041      0.2901     0.28979     0.28947     0.28914     0.28881     0.28848     0.28814     0.28779     0.28744     0.28709     0.28673     0.28636     0.28599     0.28562     0.28524     0.28485     0.28446     0.28407     0.28367     0.28326     0.28285     0.28244     0.28202     0.28159     0.28116     0.28073     0.28029     0.27984      0.2794     0.27894     0.27848     0.27802     0.27756     0.27709     0.27661     0.27614     0.27566     0.27518     0.27469     0.27421     0.27372     0.27323     0.27273     0.27224     0.27174     0.27125     0.27075     0.27025     0.26975     0.26925     0.26875     0.26825     0.26775     0.26725     0.26675     0.26625     0.26575     0.26525     0.26475     0.26425     0.26375     0.26325     0.26275     0.26225     0.26175     0.26125     0.26075     0.26025     0.25975     0.25925     0.25875     0.25825     0.25775     0.25725     0.25675     0.25625     0.25575     0.25525     0.25475     0.25425     0.25375     0.25325     0.25275     0.25225     0.25175     0.25125     0.25075     0.25025     0.24975     0.24925     0.24875     0.24825     0.24775     0.24725     0.24675     0.24625     0.24575     0.24525     0.24475     0.24425     0.24375     0.24325     0.24275     0.24225     0.24175     0.24125     0.24075     0.24025     0.23975     0.23925     0.23875     0.23825     0.23775     0.23725     0.23675     0.23625     0.23575     0.23525     0.23475     0.23425     0.23375     0.23325     0.23275     0.23225     0.23175     0.23125     0.23075     0.23025     0.22975     0.22925     0.22875     0.22825     0.22775     0.22725     0.22675     0.22625     0.22575     0.22525     0.22475     0.22425     0.22375     0.22325     0.22275     0.22225     0.22175     0.22125     0.22075     0.22025     0.21975     0.21925     0.21875     0.21825     0.21775     0.21725     0.21675     0.21625     0.21575     0.21525     0.21475     0.21425     0.21375     0.21325     0.21275     0.21225     0.21175     0.21125     0.21075     0.21025     0.20975     0.20925     0.20875     0.20825     0.20775     0.20725     0.20675     0.20625     0.20575     0.20525     0.20475     0.20425     0.20375     0.20325     0.20275     0.20225     0.20175     0.20125     0.20075     0.20025     0.19975     0.19925     0.19875     0.19825     0.19775     0.19725     0.19675     0.19625     0.19575     0.19525     0.19475     0.19425     0.19375     0.19325     0.19275     0.19225     0.19175     0.19125     0.19075     0.19025     0.18975     0.18925     0.18875     0.18825     0.18775     0.18725     0.18675     0.18625     0.18575     0.18525     0.18475     0.18425     0.18375     0.18325     0.18275     0.18225     0.18175     0.18125     0.18075     0.18025     0.17975     0.17925     0.17875     0.17825     0.17775     0.17725     0.17675     0.17625     0.17575     0.17525     0.17475     0.17425     0.17375     0.17325     0.17275     0.17225     0.17175     0.17125     0.17075     0.17025     0.16975     0.16925     0.16875     0.16825     0.16775     0.16725     0.16675     0.16625     0.16575     0.16525     0.16475     0.16425     0.16375     0.16325     0.16275     0.16225     0.16175     0.16125     0.16075     0.16025     0.15975     0.15925     0.15875     0.15825     0.15775     0.15725     0.15675     0.15625     0.15575     0.15525     0.15475     0.15425     0.15375     0.15325     0.15275     0.15225     0.15175     0.15125     0.15075     0.15025     0.14975     0.14925     0.14875     0.14825     0.14775     0.14725     0.14675     0.14625     0.14575     0.14525     0.14475     0.14425     0.14375     0.14325     0.14275     0.14225     0.14175     0.14125     0.14075     0.14025     0.13975     0.13925     0.13875     0.13825     0.13775     0.13725     0.13675     0.13625     0.13575     0.13525     0.13475     0.13425     0.13375     0.13325     0.13275     0.13225     0.13175     0.13125     0.13075     0.13025     0.12975     0.12925     0.12875     0.12825     0.12775     0.12725     0.12675     0.12625     0.12575     0.12525     0.12475     0.12425     0.12375     0.12325     0.12275     0.12225     0.12175     0.12125     0.12075     0.12025     0.11975     0.11925     0.11875     0.11825     0.11775     0.11725     0.11675     0.11625     0.11575     0.11525     0.11475     0.11425     0.11375     0.11325     0.11275     0.11225     0.11175     0.11125     0.11075     0.11025     0.10975     0.10925     0.10875     0.10825     0.10775     0.10725     0.10675     0.10625     0.10575     0.10525     0.10475     0.10425     0.10375     0.10325     0.10275     0.10225     0.10175     0.10125     0.10075     0.10025     0.09975     0.09925     0.09875     0.09825     0.09775     0.09725     0.09675     0.09625     0.09575     0.09525     0.09475     0.09425     0.09375     0.09325     0.09275     0.09225     0.09175     0.09125     0.09075     0.09025     0.08975     0.08925     0.08875     0.08825     0.08775     0.08725     0.08675     0.08625     0.08575     0.08525     0.08475     0.08425     0.08375     0.08325     0.08275     0.08225     0.08175     0.08125     0.08075     0.08025     0.07975     0.07925     0.07875     0.07825     0.07775     0.07725     0.07675     0.07625     0.07575     0.07525     0.07475     0.07425     0.07375     0.07325     0.07275     0.07225     0.07175     0.07125     0.07075     0.07025     0.06975     0.06925     0.06875     0.06825     0.06775     0.06725     0.06675     0.06625     0.06575     0.06525     0.06475     0.06425     0.06375     0.06325     0.06275     0.06225     0.06175     0.06125     0.06075     0.06025     0.05975     0.05925     0.05875     0.05825     0.05775     0.05725     0.05675     0.05625     0.05575     0.05525     0.05475     0.05425     0.05375     0.05325     0.05275     0.05225     0.05175     0.05125     0.05075     0.05025     0.04975     0.04925     0.04875     0.04825     0.04775     0.04725     0.04675     0.04625     0.04575     0.04525     0.04475     0.04425     0.04375     0.04325     0.04275     0.04225     0.04175     0.04125     0.04075     0.04025     0.03975     0.03925     0.03875     0.03825     0.03775     0.03725     0.03675     0.03625     0.03575     0.03525     0.03475     0.03425     0.03375     0.03325     0.03275     0.03225     0.03175     0.03125     0.03075     0.03025    0.029751    0.029252    0.028754    0.028257    0.027761    0.027267    0.026774    0.026283    0.025794    0.025308    0.024823    0.024341    0.023863    0.023387    0.022914    0.022444    0.021979    0.021517    0.021059    0.020605    0.020156    0.019711    0.019271    0.018836    0.018406    0.017981    0.017561    0.017146    0.016736    0.016331    0.015931    0.015536    0.015146    0.014761    0.014381    0.014006    0.013636    0.013271    0.012911    0.012556    0.012206    0.011861    0.011521    0.011186    0.010856    0.010531    0.010211   0.0098958   0.0095858   0.0092808   0.0089808   0.0086858   0.0083958   0.0081108   0.0078308   0.0075558   0.0072858   0.0070208   0.0067608   0.0065058   0.0062558   0.0060108   0.0057708   0.0055358   0.0053058   0.0050808   0.0048608   0.0046458   0.0044358   0.0042308   0.0040308   0.0038358   0.0036458   0.0034608   0.0032808   0.0031058   0.0029358   0.0027708   0.0026108   0.0024558   0.0023058   0.0021608   0.0020208   0.0018858   0.0017558   0.0016308   0.0015108   0.0013958   0.0012858   0.0011808   0.0010808  0.00098583  0.00089583  0.00081083  0.00073083  0.00065583  0.00058583  0.00052083   0.0004608  0.00040557  0.00035493   0.0003087  0.00026667  0.00022863   0.0001944  0.00016377  0.00013653   0.0001125  9.1467e-05  7.3233e-05    5.76e-05  4.4367e-05  3.3333e-05    2.43e-05  1.7067e-05  1.1433e-05     7.2e-06  4.1667e-06  2.1333e-06       9e-07  2.6667e-07  3.3333e-08           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0           0]'
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
