/*
 * File: ABS_Controller_ca.h
 *
 * Abstract: Tests assumptions in the generated code.
 */

#ifndef ABS_CONTROLLER_CA_H
#define ABS_CONTROLLER_CA_H

/* preprocessor validation checks */
#include "ABS_Controller_ca_preproc.h"
#include "coder_assumptions_hwimpl.h"

/* variables holding test results */
extern CA_HWImpl_TestResults CA_ABS_Controller_HWRes;
extern CA_PWS_TestResults CA_ABS_Controller_PWSRes;

/* variables holding "expected" and "actual" hardware implementation */
extern const CA_HWImpl CA_ABS_Controller_ExpHW;
extern CA_HWImpl CA_ABS_Controller_ActHW;

/* entry point function to run tests */
void ABS_Controller_caRunTests(void);

#endif                                 /* ABS_CONTROLLER_CA_H */
