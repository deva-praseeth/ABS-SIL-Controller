# ABS-SIL-Controller

Model-Based Design of ABS-SIL-Controller

**-----------------------------------------------------**



### **Introduction**



This repository contains a Software-in-the-Loop (SIL) simulation project for a basic Anti-lock Braking System (ABS) controller. The project is developed using Model-Based Design (MBD) principles, a standard methodology in the automotive industry for designing safety-critical systems.



The core of the project involves a Simulink model (**Plant\_Model.slx**) of a vehicle's dynamics and a Stateflow chart that implements the ABS control logic. The project demonstrates the full workflow from initial design and simulation to the preparation of a model for code generation.



**-----------------------------------------------------**



### **Project Goals**



* **Model-Based Design:** Design a functional ABS controller using Simulink and Stateflow.
* **System Simulation:** Simulate the controller's behavior and verify its performance under hard braking conditions.
* **Driver Interface:** Model a realistic driver input to trigger and release the braking system.
* **Data Analysis:** Generate and analyze plots of key system variables (vehicle velocity, wheel velocity) to confirm correct ABS functionality.



**-----------------------------------------------------**



### **Phase 1: Initial Design and Simulation**



The initial phase of the project focuses on the design, simulation, and verification of a monolithic Simulink model, which serves as the "golden reference" for all future development.



#### **1. System Modeling**



* **Vehicle Dynamics (Plant Model):** A simplified, single-wheel vehicle dynamics model was created in Simulink (**Plant\_Model.slx**). This model represents the physical behavior of the braking system and includes models for tire-road friction, wheel inertia, and vehicle mass.



* **ABS Controller (Stateflow Chart):** The control logic was developed using a Stateflow chart, which is ideal for modeling the discrete-time state machine behavior of the ABS system. The chart defines three core states:

   	\* No\_**Braking:** The initial default state where no braking torque is applied.
    	\* **Braking:** The state where maximum braking torque is applied upon driver's input.
   	\* **ABS\_ON:** The state where braking torque is reduced to prevent wheel lock-up.
 

* **Driver Input:** A step-function signal was created to represent the driver pressing and releasing the brake pedal, allowing for the simulation of multiple braking events.



#### **2. Simulation and Verification**



The completed model was simulated with the following key results:



* **ABS Functionality:** A MATLAB script (**plot\_script.m**) was created to generate plots of wheel and vehicle velocities. During hard braking, the wheel velocity exhibits the characteristic oscillating "sawtooth" pattern, while the vehicle's velocity decreases in a smooth, controlled manner, confirming the ABS controller's effect.



* **Driver Input Correlation:** The simulation results confirm that the braking and ABS cycles are correctly initiated when the `driver\\\\\\\_input` signal is active and cease when the signal is inactive. The system correctly returns to a coasting state when the driver releases the brake pedal.



* **Documentation:** The simulation results are documented in **ABS\_plot.pdf**, and the underlying engineering assumptions and calculations are detailed in **Calculations.pdf**.



**-----------------------------------------------------**



### **Phase 2: Code Generation and SIL Simulation**



This phase involved converting the validated Simulink model into a format suitable for embedded C code generation and validating the code's behavior through Software-in-the-Loop (SIL) simulation.



#### **1. Code Generation**



The control logic was converted into a referenced model for code generation. The **Embedded Code (ert.tlc)** target was used with the Simulink Embedded Coder. To emulate real-time processing, the control logic and incoming signals were fully discretized.



#### **2. Continuous to Discrete Conversion**



* **Fixed-Step Solver:** For embedded code generation, the plant model was solved using a fixed-step ode4 solver, and the referenced model used a fixed-step discrete solver. 



* Low\_Torque State: To compensate for numerical instability caused by these solvers as the vehicle velocity approached zero, a new state was added to the Stateflow chart. This state gradually reduced braking torque to bring the vehicle to a complete stop.



* **ADC Subsystem:** An **Analog-to-Digital Converter (ADC)** subsystem was introduced immediately before the control logic to discretize the input signals. This was necessary to prevent unwanted continuous-time solver functions from being included in the embedded code, which could cause compilation errors.



#### **3. Code Validation**



Embedded code was generated, and the control logic was simulated as SIL within the plant model. The output was validated against the monolithic model results, confirming that the code behaved identically to the original simulation.



**-----------------------------------------------------**



### **Next Steps**

In the next phase, a `main.c` file will be created. A TCP/IP communication will be established between the controller and the plant model for a more advanced SIL simulation setup.

