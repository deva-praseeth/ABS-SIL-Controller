# ABS-SIL-Controller

Model-Based Design of ABS-SIL-Controller



### **Introduction**

This repository contains a Software-in-the-Loop (SIL) simulation project for a basic Anti-lock Braking System (ABS) controller. The project is developed using Model-Based Design (MBD) principles, a standard methodology in the automotive industry for designing safety-critical systems.



The core of the project involves a Simulink model (Plant\_Model.slx) of a vehicle's dynamics and a Stateflow chart that implements the ABS control logic. The project demonstrates the full workflow from initial design and simulation to the preparation of a model for code generation.



### **Project Goals**

**Model-Based Design:** Design a functional ABS controller using Simulink and Stateflow.



**System Simulation:** Simulate the controller's behavior and verify its performance under hard braking conditions.



**Driver Interface:** Model a realistic driver input to trigger and release the braking system.



**Data Analysis:** Generate and analyze plots of key system variables (vehicle velocity, wheel velocity) to confirm correct ABS functionality.



### **Completed Work (Phase 1)**

The initial phase of the project, documented here, focuses on the design, simulation, and verification of the monolithic Simulink model. This serves as the "golden reference" for all future development.



###### **1. System Modeling**



**Vehicle Dynamics (Plant Model):** A simplified, single-wheel vehicle dynamics model was created in Simulink (Plant\_Model.slx) to represent the physical behavior of the braking system. This includes models for tire-road friction, wheel inertia, and vehicle mass.



**ABS Controller (Stateflow Chart):** The control logic was developed using a Stateflow chart, which is ideal for modeling the discrete-time state machine behavior of the ABS system. The chart defines three core states:



**Braking:** The initial state where maximum braking torque is applied.



**ABS\_ON:** The state where braking torque is reduced to prevent wheel lock-up.



**ABS\_OFF:** A transient state where braking torque is held to allow the wheel to regain traction before reapplying pressure.



**Timed Logic:** A 1-second delay was implemented using Stateflow's temporal logic (after(1, sec)) to simulate a delay in the application of maximum brake torque, showcasing a more realistic system start-up.



**Driver Input:** A step-function signal was created to represent the driver pressing and releasing the brake pedal, allowing for the simulation of multiple braking events.



###### **2. Simulation and Verification**



The completed model was simulated with the following key results:



**ABS Functionality:** A MATLAB script (plot\_script.m) was created to generate plots of wheel and vehicle velocities, which clearly show the ABS controller's effect. During hard braking, the wheel velocity exhibits the characteristic oscillating "sawtooth" pattern, while the vehicle's velocity decreases in a smooth, controlled manner.



**Driver Input Correlation:** The simulation results confirm that the braking and ABS cycles are correctly initiated when the driver\_input signal is active and cease when the signal is inactive. The system correctly returns to a coasting state when the driver releases the brake pedal.



**Documentation:** The simulation results are documented in ABS\_plot.pdf, and the underlying engineering assumptions and calculations are detailed in Calculations.pdf.



### **Repository Contents**

slprj/: The Simulink project folder, which contains project-specific files.



Plant\_Model.slx: The primary Simulink model file containing the plant dynamics and the Stateflow controller logic.



parameters.m: A MATLAB script that defines the simulation parameters (BT\_max, BT\_hold, etc.) in the workspace.



plot\_script.m: A MATLAB script used to generate and save the velocity and input plots after a simulation run.



Calculations.pdf: A document containing the manual calculations and engineering assumptions used to build the model.



ABS\_plot.pdf: A PDF document containing the final plots of the simulation results, including vehicle velocity, wheel velocity, and driver input.



README.md: This file, documenting the project's progress.



### **Next Steps**

The next phase of this project will involve using the completed Simulink model to generate embedded C code and perform a Software-in-the-Loop (SIL) simulation. This will validate that the generated code behaves identically to the model, a crucial step in the MBD workflow.

