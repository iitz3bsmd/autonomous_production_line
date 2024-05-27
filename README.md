# 🤖 Autonomous Production Line | autonomous_production_line
A production line running autonomously with multiple stages, powered by a SCARA Robotic Arm and using the VDI-Model Design Methodology

![image](https://github.com/iitz3bsmd/autonomous_production_line/assets/112030326/c6d7c2af-2c2c-4b9c-89a7-df40bdbd94b6)


## [Stages Demo](https://drive.google.com/file/d/1443hU0NkG-to6Uk8_kxw53MRVE9NHp7r/view?usp=sharing)

![WhatsApp Image 2024-05-28 at 00 24 29_9f93d7916](https://github.com/iitz3bsmd/autonomous_production_line/assets/112030326/101797b4-60e6-4377-ba44-289231853e26)


## System Requirements 
•	Functionality: The system should be able to autonomously assemble products or components according to predefined specifications.

•	The system must be capable of performing the following tasks on products yet in no particular order of operations: Feeding, Assembly, Sorting, Handling and Storage.

•	Integration: The system should seamlessly integrate the before mentioned stages.

•	Reliability: The system should operate reliably over extended periods without frequent breakdowns or interruptions.

•	Flexibility: The system should be adaptable to changes in production requirements or product configurations.

•	The System must incorporate the following features: Camera for part recognition, PID control.


## System Design
### Mechanical Modules
•	Feeding Module: this subsystem is responsible for feeding parts to the conveyer part by part.
•	Conveyer Module: this subsystem is responsible for moving and stopping the part at different stages such as color detection and sorting and is controlled with a PID controller.
•	Arm Module: this final subsystem is responsible for assembling and storing the assembled parts.
### System Control Architecture
The main controller for the system is a Raspberry Pi 2, which handles communication between other microcontrollers and keeps track of parts to be assembled.

![image](https://github.com/iitz3bsmd/autonomous_production_line/assets/112030326/6e304f1f-a3ee-43bd-a93c-b5c014211c16)


## Matalab Work
We used MATLAB for:
1. Actuator Sizing
2. System Identification 
3. PID Control

### Actuator Sizing
We Modeled the full System on MATLAB Simulink to achieve proper sizing for the motors

![image](https://github.com/iitz3bsmd/autonomous_production_line/assets/112030326/c5f14da9-2522-49b2-9e30-7e8594c5bb77)
![image](https://github.com/iitz3bsmd/autonomous_production_line/assets/112030326/fbb73a8b-d378-45e4-97b9-68f8e0a8e9a8)
![image](https://github.com/iitz3bsmd/autonomous_production_line/assets/112030326/a61c6916-c80e-4232-bae8-6b5ceb125d7d)


### System Identification
To achieve PID control we must know the system parameters. so, using the system identification toolbox in MATLAB we got the closest estimation for system parameters

![WhatsApp Image 2024-05-19 at 15 05 48_c1fa91fb](https://github.com/iitz3bsmd/autonomous_production_line/assets/112030326/a3b0ad27-0cf9-4f57-b298-2ba320d5be88)
![WhatsApp Image 2024-05-19 at 15 05 47_0a50b853](https://github.com/iitz3bsmd/autonomous_production_line/assets/112030326/59d12c13-ef0f-4c9e-9951-0d556f74eea9)
![WhatsApp Image 2024-05-19 at 15 05 48_93cebdd8](https://github.com/iitz3bsmd/autonomous_production_line/assets/112030326/b1e552a4-004f-4067-a533-ac63e38adf4a)


### PID Control
The last step was to model the PID control and tune the parameters which was achieved to errors below 1% !

![WhatsApp Image 2024-05-19 at 15 05 48_7eb4c3910](https://github.com/iitz3bsmd/autonomous_production_line/assets/112030326/c7909cef-31a0-4163-95b5-a10b8fa5ceda)
![WhatsApp Image 2024-05-19 at 15 16 46_9bbdb05c](https://github.com/iitz3bsmd/autonomous_production_line/assets/112030326/414a1f56-df4f-4b84-aab7-9a8e51a4a099)


## PCB Design
One of our goals was project reliability, and for that reason we designed and manufacutured a PCB housing 2 arduinos and connects to the entire system.

![image](https://github.com/iitz3bsmd/autonomous_production_line/assets/112030326/e0c93e10-152a-4fea-b518-86f2a65c9483)
![image](https://github.com/iitz3bsmd/autonomous_production_line/assets/112030326/78ce6c2d-4d70-4660-a49b-7f38ac758491)
<img src="https://github.com/iitz3bsmd/autonomous_production_line/assets/112030326/381c20bd-786a-48bd-931c-9bf723da73f1" width="700" >








