# **RWA2 - Multi-Terrain Mobile Robot Simulation (ENPM809Y)**

## **Project Overview**
This project is part of **ENPM809Y - Robot Programming** at the **University of Maryland, College Park**. It focuses on implementing an **object-oriented robotic system** to simulate various **autonomous mobile robots** operating in different environments.

The simulation includes **four types of mobile robots**, each with **unique behaviors**:

1. **Wheeled Robots** 🏎️  
   - Used for ground navigation.
   - Capable of **accelerating, braking, and turning**.
   - Example: **Autonomous Vehicles, TurtleBot3**.

2. **Legged Robots** 🦿  
   - Designed for **terrain traversal**.
   - Features **jumping and kicking mechanics**.
   - Example: **Boston Dynamics' Spot Robot**.

3. **Aerial Robots** 🚁  
   - Operate in **three-dimensional space**.
   - Includes **takeoff, landing, altitude management**.
   - Example: **Quadcopters, CrazyFlie Drones**.

4. **Aquatic Robots** 🤿  
   - Navigate **underwater**.
   - Perform **diving, surfacing, and depth control**.
   - Example: **Sofi, Underwater Drones**.

### **Core Features**
✔ Implements **Object-Oriented Programming (OOP)**: **Encapsulation, Abstraction, Inheritance, and Polymorphism**.  
✔ Uses a **Battery Management System (BMS)** to simulate **charging and discharging** of robots.  
✔ Integrates **Sensor Systems** for robots to perceive their environment.  
✔ Uses **dynamic polymorphism** to ensure different robot types can be controlled under a unified interface.  
✔ The main program **executes commands** such as:
  - **Moving, Rotating, Flying, Diving, Jumping, and Braking**.
  - **Monitoring Battery Levels**.
  - **Collecting Sensor Data**.

### **Why This Project Matters?**
- It demonstrates **modular software design** for robotics.
- Showcases **how different robots interact with their environment**.
- Provides **a foundation for future robotic control systems** using **ROS2 or real-world implementations**.

---

## **Table of Contents**
- [Project Overview](#project-overview)
- [Features](#features)
- [Installation](#installation)
  - [Step 1: Clone the Repository](#step-1-clone-the-repository)
  - [Step 2: Install Dependencies](#step-2-install-dependencies)
  - [Step 3: Build the Project](#step-3-build-the-project)
- [Running the Project](#running-the-project)
- [Project Structure](#project-structure)
- [How the Code Works](#how-the-code-works)

---

## **Installation**
### **Prerequisites**
Ensure you have the following dependencies installed:
- **Ubuntu 22.04** (or later) or **Windows with WSL**
- **C++ Compiler (g++)**
- **CMake** (for build system)
- **Make** (for compiling)

### **Step 1: Clone the Repository**
```bash
cd ~
git clone <your-repository-url> rwa2_project
cd rwa2_project
```

### **Step2: Install Dependencies**
Ensure that you have CMake and a C++ compiler (g++) installed:
```bash
sudo apt update
sudo apt install cmake g++

```

### **Step 3: Build the Package**
```bash
mkdir build
cd build
cmake ..
make
```
## **Running the Project**
Once the project is compiled, you can run the simulation using:
```
./build/main
```
This will execute the main.cpp file, where multiple robots will perform actions such as:

Flying, Diving, Driving, and Jumping
Using Sensors to Collect Data
Managing Battery Usage & Charging

## **Project Structure**
```
rwa2_project/
├── include/
│   ├── mobile_robot.h          # Base class for all mobile robots
│   ├── wheeled_robot.h         # Wheeled robot class (e.g., TurtleBot)
│   ├── legged_robot.h          # Legged robot class (e.g., Spot)
│   ├── aerial_robot.h          # Aerial robot class (e.g., CrazyFlie)
│   ├── aquatic_robot.h         # Aquatic robot class (e.g., Sofi)
│   ├── sensor.h                # Sensor class for data collection
│   ├── battery.h               # Battery management system
│
├── src/
│   ├── main.cpp                # Main program execution
│   ├── mobile_robot.cpp        # Base class implementation
│   ├── wheeled_robot.cpp       # Wheeled robot logic
│   ├── legged_robot.cpp        # Legged robot logic
│   ├── aerial_robot.cpp        # Aerial robot logic
│   ├── aquatic_robot.cpp       # Aquatic robot logic
│   ├── sensor.cpp              # Sensor data collection implementation
│   ├── battery.cpp             # Battery charging/discharging logic
│
├── CMakeLists.txt              # CMake build configuration
├── README.md                   # Documentation

```

### **How the Code Works**
**1. Mobile Robot Base Class**
mobile_robot.h & mobile_robot.cpp define a base class for all robot types.
Implements position, orientation, and movement methods.

**2. Robot Types & Behaviors**
wheeled_robot.cpp: Implements acceleration, deceleration, and braking.
legged_robot.cpp: Implements jumping and kicking.
aerial_robot.cpp: Implements takeoff, landing, and altitude management.
aquatic_robot.cpp: Implements diving and surfacing.

**3. Battery & Sensor Systems**
battery.cpp: Simulates battery charging and discharging.
sensor.cpp: Simulates sensor data collection.

**4. Main Execution (main.cpp)**
Creates multiple robot objects.
Uses dynamic polymorphism to call move() functions specific to each robot type.
