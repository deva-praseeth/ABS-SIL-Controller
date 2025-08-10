/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ABS_Controller.c
 *
 * Code generated for Simulink model 'ABS_Controller'.
 *
 * Model version                  : 1.23
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Sun Aug 10 18:53:08 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ABS_Controller.h"
#include "rtwtypes.h"
#include <math.h>
#include "ABS_Controller_private.h"

/* Named constants for Chart: '<Root>/Controller Logic' */
#define ABS_Controller_IN_ABS_ON       ((uint8_T)1U)
#define ABS_Controller_IN_Braking      ((uint8_T)2U)
#define ABS_Controller_IN_Low_Torque   ((uint8_T)3U)
#define ABS_Controller_IN_No_Braking   ((uint8_T)4U)
#define ABS_Controller_step_size       (0.1)

/* Output and update for referenced model: 'ABS_Controller' */
void ABS_Controller(const real_T *rtu_slip, const real_T *rtu_vF, const real_T
                    *rtu_DriverInput, real_T *rty_BrakingTorque,
                    DW_ABS_Controller_f_T *localDW)
{
  /* Chart: '<Root>/Controller Logic' */
  if (localDW->is_active_c3_ABS_Controller == 0) {
    localDW->is_active_c3_ABS_Controller = 1U;
    localDW->is_c3_ABS_Controller = ABS_Controller_IN_No_Braking;
  } else {
    switch (localDW->is_c3_ABS_Controller) {
     case ABS_Controller_IN_ABS_ON:
      if ((*rtu_DriverInput == 1.0) && (*rtu_slip <= 0.13)) {
        localDW->is_c3_ABS_Controller = ABS_Controller_IN_Braking;
      } else if (*rtu_DriverInput == 0.0) {
        localDW->is_c3_ABS_Controller = ABS_Controller_IN_No_Braking;
      } else {
        *rty_BrakingTorque = 0.0;
      }
      break;

     case ABS_Controller_IN_Braking:
      if ((*rtu_DriverInput == 1.0) && (*rtu_slip > 0.13)) {
        localDW->is_c3_ABS_Controller = ABS_Controller_IN_ABS_ON;
        *rty_BrakingTorque = 5355.0;
      } else if (*rtu_DriverInput == 0.0) {
        localDW->is_c3_ABS_Controller = ABS_Controller_IN_No_Braking;
      } else if (*rtu_vF <= 1.786) {
        localDW->is_c3_ABS_Controller = ABS_Controller_IN_Low_Torque;
        *rty_BrakingTorque = 5355.0;
      } else {
        *rty_BrakingTorque = 5355.0;
      }
      break;

     case ABS_Controller_IN_Low_Torque:
      if (*rtu_DriverInput == 0.0) {
        localDW->is_c3_ABS_Controller = ABS_Controller_IN_No_Braking;
      } else {
        *rty_BrakingTorque = fmin(*rty_BrakingTorque - ABS_Controller_step_size,
          5355.0);
      }
      break;

     default:
      /* case IN_No_Braking: */
      if (*rtu_DriverInput == 1.0) {
        localDW->is_c3_ABS_Controller = ABS_Controller_IN_Braking;
      } else {
        *rty_BrakingTorque = 0.0;
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Controller Logic' */
}

/* Model initialize function */
void ABS_Controller_initialize(const char_T **rt_errorStatus,
  RT_MODEL_ABS_Controller_T *const ABS_Controller_M)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatusPointer(ABS_Controller_M, rt_errorStatus);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
