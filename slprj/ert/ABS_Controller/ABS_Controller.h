/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ABS_Controller.h
 *
 * Code generated for Simulink model 'ABS_Controller'.
 *
 * Model version                  : 1.21
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Sun Aug 10 16:55:42 2025
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

/* Block states (default storage) for model 'ABS_Controller' */
typedef struct {
  uint16_T temporalCounter_i1;         /* '<Root>/Controller Logic' */
  uint8_T is_active_c3_ABS_Controller; /* '<Root>/Controller Logic' */
  uint8_T is_c3_ABS_Controller;        /* '<Root>/Controller Logic' */
} DW_ABS_Controller_f_T;

/* Real-time Model Data Structure */
struct tag_RTM_ABS_Controller_T {
  const char_T **errorStatus;
};

typedef struct {
  DW_ABS_Controller_f_T rtdw;
  RT_MODEL_ABS_Controller_T rtm;
} MdlrefDW_ABS_Controller_T;

/* Model reference registration function */
extern void ABS_Controller_initialize(const char_T **rt_errorStatus,
  RT_MODEL_ABS_Controller_T *const ABS_Controller_M);
extern void ABS_Controller(const real_T *rtu_slip, const real_T *rtu_vF, const
  real_T *rtu_DriverInput, real_T *rty_BrakingTorque, DW_ABS_Controller_f_T
  *localDW);

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
