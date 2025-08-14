# 🚗 ABS-SIL-Controller  
_Model-Based Design of an Anti-lock Braking System (ABS) – Software-in-the-Loop (SIL) Implementation_  

![MATLAB](https://img.shields.io/badge/MATLAB-Simulink-blue)
![Stateflow](https://img.shields.io/badge/Stateflow-Control%20Logic-orange)
![SIL](https://img.shields.io/badge/SIL-Validated-brightgreen)

---

## 📜 Table of Contents
- [Introduction](#introduction)
- [Project Goals](#project-goals)
- [Phase 1: Design & Simulation](#phase-1-design--simulation)
- [Phase 2: Code Generation & SIL](#phase-2-code-generation--sil)
- [Next Steps](#next-steps)
- [Getting Started](#getting-started)
- [Project Files Overview](#project-files-overview)
- [Contributors](#contributors)

---

## 📝 Introduction
This project demonstrates **Model-Based Design (MBD)** using **Simulink** and **Stateflow** to develop an Anti-lock Braking System.  
It includes:
- A **plant model** of vehicle dynamics
- **ABS control logic**
- **Simulation**
- **Code generation**
- **Software-in-the-Loop (SIL)** validation

---

## 🎯 Project Goals
- **Model-Based Design**: ABS control logic in Stateflow + plant dynamics in Simulink  
- **System Simulation**: Test braking under various conditions  
- **Driver Simulation**: Realistic pedal activation/release modeling  
- **Data Analysis**: Visualize velocity/braking behavior to confirm ABS effectiveness  

---

## ⚙ Phase 1: Design & Simulation

### 🔧 System Modeling
- **Plant Model (`Plant_Model.slx`)**: Single-wheel vehicle dynamics (mass, inertia, tire friction)
- **Stateflow ABS Controller** with 3 main states:  
  1. **No_Braking** – No brake applied  
  2. **Braking** – Full brake torque applied  
  3. **ABS_ON** – Modulated torque to prevent lock  
- **Driver Input**: Step-function brake pedal to test multiple events  

---

### 📊 Simulation & Verification
- **Behavior**:  
  - Wheel velocity → saw-tooth pattern under hard braking  
  - Vehicle deceleration → smooth (ABS working)  
- **Verification**:  
  - `plot_script.m` → velocity visualization  
  - `ABS_plot.pdf` & `Calculations.pdf` → results and engineering notes  

---

## 🖥 Phase 2: Code Generation & SIL

### 🔄 Code Generation
- **Embedded C code** from Stateflow logic using `ert.tlc`
- Fixed-step discrete solver for embedded compatibility  

### 🧮 Discrete Logic & ADC Handling
- Added **Low_Torque** state for smooth stop near zero speed  
- **ADC Subsystem** converts analog brake signals to digital inputs  

### ✅ SIL Validation
- Embedded code runs inside plant model → output matches original Simulink behavior  

---

## 🚀 Next Steps
- Develop `main.c` for virtual communication  
- Add virtual communication interface between controller and plant model  

---

## 🛠 Getting Started
```bash
git clone https://github.com/deva-praseeth/ABS-SIL-Controller.git
cd ABS-SIL-Controller
# Open Simulink models in MATLAB
