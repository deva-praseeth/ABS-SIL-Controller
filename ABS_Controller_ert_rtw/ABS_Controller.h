/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ABS_Controller.h
 *
 * Code generated for Simulink model 'ABS_Controller'.
 *
 * Model version                  : 1.24
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Tue Aug 12 13:20:11 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef ABS_Controller_h_
#define ABS_Controller_h_
#ifndef ABS_Controller_COMMON_INCLUDES_
#define ABS_Controller_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "math.h"
#endif                                 /* ABS_Controller_COMMON_INCLUDES_ */

#include "ABS_Controller_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  uint8_T is_active_c3_ABS_Controller; /* '<Root>/Controller Logic' */
  uint8_T is_c3_ABS_Controller;        /* '<Root>/Controller Logic' */
} DW_ABS_Controller_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T slip;                         /* '<Root>/slip' */
  real_T vF;                           /* '<Root>/vF' */
  real_T DriverInput;                  /* '<Root>/Driver Input' */
} ExtU_ABS_Controller_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T BrakingTorque;                /* '<Root>/Braking Torque' */
} ExtY_ABS_Controller_T;

/* Real-time Model Data Structure */
struct tag_RTM_ABS_Controller_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_ABS_Controller_T ABS_Controller_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_ABS_Controller_T ABS_Controller_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_ABS_Controller_T ABS_Controller_Y;

/* Model entry point functions */
extern void ABS_Controller_initialize(void);
extern void ABS_Controller_output(void);
extern void ABS_Controller_update(void);
extern void ABS_Controller_terminate(void);

/* Real-time Model object */
extern RT_MODEL_ABS_Controller_T *const ABS_Controller_M;

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
 * '<Root>' : 'ABS_Controller'
 * '<S1>'   : 'ABS_Controller/Controller Logic'
 */
#endif                                 /* ABS_Controller_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
