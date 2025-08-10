/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ABS_Controller.c
 *
 * Code generated for Simulink model 'ABS_Controller'.
 *
 * Model version                  : 1.21
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Sun Aug 10 16:53:46 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ABS_Controller.h"
#include "rtwtypes.h"
#include <math.h>

/* Named constants for Chart: '<Root>/Controller Logic' */
#define ABS_Controller_IN_ABS_ON       ((uint8_T)1U)
#define ABS_Controller_IN_Braking      ((uint8_T)2U)
#define ABS_Controller_IN_Low_Torque   ((uint8_T)3U)
#define ABS_Controller_IN_No_Braking   ((uint8_T)4U)
#define ABS_Controller_step_size       (0.1)

/* Block states (default storage) */
DW_ABS_Controller_T ABS_Controller_DW;

/* External inputs (root inport signals with default storage) */
ExtU_ABS_Controller_T ABS_Controller_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_ABS_Controller_T ABS_Controller_Y;

/* Real-time model */
static RT_MODEL_ABS_Controller_T ABS_Controller_M_;
RT_MODEL_ABS_Controller_T *const ABS_Controller_M = &ABS_Controller_M_;

/* Model output function */
void ABS_Controller_output(void)
{
  /* Chart: '<Root>/Controller Logic' incorporates:
   *  Inport: '<Root>/Driver Input'
   *  Inport: '<Root>/slip'
   *  Inport: '<Root>/vF'
   */
  if (ABS_Controller_DW.temporalCounter_i1 < 16383) {
    ABS_Controller_DW.temporalCounter_i1++;
  }

  if (ABS_Controller_DW.is_active_c3_ABS_Controller == 0) {
    ABS_Controller_DW.is_active_c3_ABS_Controller = 1U;
    ABS_Controller_DW.temporalCounter_i1 = 0U;
    ABS_Controller_DW.is_c3_ABS_Controller = ABS_Controller_IN_No_Braking;
  } else {
    switch (ABS_Controller_DW.is_c3_ABS_Controller) {
     case ABS_Controller_IN_ABS_ON:
      if ((ABS_Controller_U.DriverInput == 1.0) && (ABS_Controller_U.slip <=
           0.13)) {
        ABS_Controller_DW.is_c3_ABS_Controller = ABS_Controller_IN_Braking;
      } else if (ABS_Controller_U.DriverInput == 0.0) {
        ABS_Controller_DW.temporalCounter_i1 = 0U;
        ABS_Controller_DW.is_c3_ABS_Controller = ABS_Controller_IN_No_Braking;
      } else {
        /* Outport: '<Root>/Braking Torque' */
        ABS_Controller_Y.BrakingTorque = 0.0;
      }
      break;

     case ABS_Controller_IN_Braking:
      if ((ABS_Controller_U.DriverInput == 1.0) && (ABS_Controller_U.slip > 0.13))
      {
        ABS_Controller_DW.is_c3_ABS_Controller = ABS_Controller_IN_ABS_ON;

        /* Outport: '<Root>/Braking Torque' */
        ABS_Controller_Y.BrakingTorque = 5355.0;
      } else if (ABS_Controller_U.DriverInput == 0.0) {
        ABS_Controller_DW.temporalCounter_i1 = 0U;
        ABS_Controller_DW.is_c3_ABS_Controller = ABS_Controller_IN_No_Braking;
      } else if (ABS_Controller_U.vF <= 1.786) {
        ABS_Controller_DW.is_c3_ABS_Controller = ABS_Controller_IN_Low_Torque;

        /* Outport: '<Root>/Braking Torque' */
        ABS_Controller_Y.BrakingTorque = 5355.0;
      } else {
        /* Outport: '<Root>/Braking Torque' */
        ABS_Controller_Y.BrakingTorque = 5355.0;
      }
      break;

     case ABS_Controller_IN_Low_Torque:
      if (ABS_Controller_U.DriverInput == 0.0) {
        ABS_Controller_DW.temporalCounter_i1 = 0U;
        ABS_Controller_DW.is_c3_ABS_Controller = ABS_Controller_IN_No_Braking;
      } else {
        /* Outport: '<Root>/Braking Torque' */
        ABS_Controller_Y.BrakingTorque = fmin(ABS_Controller_Y.BrakingTorque -
          ABS_Controller_step_size, 5355.0);
      }
      break;

     default:
      /* case IN_No_Braking: */
      if ((ABS_Controller_DW.temporalCounter_i1 >= 10000) &&
          (ABS_Controller_U.DriverInput == 1.0)) {
        ABS_Controller_DW.is_c3_ABS_Controller = ABS_Controller_IN_Braking;
      } else {
        /* Outport: '<Root>/Braking Torque' */
        ABS_Controller_Y.BrakingTorque = 0.0;
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Controller Logic' */
}

/* Model update function */
void ABS_Controller_update(void)
{
  /* (no update code required) */
}

/* Model initialize function */
void ABS_Controller_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void ABS_Controller_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
