## Embedded Systems Project Report: AVR-UART-Acquisition

## 1. Introduction
his project implements a register-level control node on an ATmega328P microcontroller using native C programming, entirely bypassing high-level 
hardware abstraction layers to interact directly with hardware registers. The system establishes a reliable bidirectional communication link over
UART (9600 baud) to monitor physical button states (PD2) and parse incoming serial commands ("LED on" / "LED off") to trigger digital outputs (PD4),
mirroring the modular design principles used in real-world automotive and industrial network nodes.

## 2. Project Code

**GitHub Repository:**
[Repo_link](https://github.com/Fares-Aboelsoud/AVR-UART-Acquisition.git)

**Local Root Directory**
[link_to_local_root_directory](./Project/Code/main/)

## 3. Test Cases

Test Cases are developed in **[Robot Framework](https://robotframework.org/)** Test steps
[robot_tests](./Project/Tests/test_cases.robot)

## 4. Bill of Materials (BOM)

**BOM**
[bom_file](./Project/BOM/bom_list.csv)

**Optimized BOM**
[optimized_bom_file](./Project/BOM/optimized_bom_list.csv)

## 5. Video Demonstration

[recorded_video](./Project/Demo/Demo.mp4)


## 6. Design
[design_document](./Project/Report/Design.md)
