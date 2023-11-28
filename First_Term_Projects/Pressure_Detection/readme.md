# Abstract :  
-------------
This project is a Pressure controlling System, where the system  will inform the crew of the cabin with an alarm when the pressure exceeds 20 bars in the cabin, also the system will be tracking the measured values. 

This report contains the system architecting and Design sequence, so this report is divided into six n  sections : 

1-  Case study 

2-  Method  

3-  Requirement  

4-  Space Exploration and partitioning  5-  System Analysis 

6-  System Design 

1- Case Study.  

- Client requirements : 

The client expects you to deliver the software of the following system specifications : 

- Pressure controller informs the crew of a cabin with an alarm when the pressure exceeds 20 bars in the cabin. 
- The alarm duration equal 60 seconds.  
- Keep track of the measured value. 
- Pressure Control Assumptions : 
- Setup and shutdown procedures are not modeled  
- Pressure sensor will never fail 
- Alarm will never fail. 
- The controller never faces power cut. 
- No display of the tracked values. 
- Versioning : 

the “ keep track of measured value “ option will not be modeled in the first version. 

# 2- Method. 
-------------
The SDLC method that will be used is the V-Model 

![](https://github.com/mahmoudHussein202/Mastering-Embedded-Systems-deploma/blob/master/First_Term_Projects/Pressure_Detection/Report/Aspose.Words.a28f5dfc-a86e-4b51-bb70-9f4134a593e7.001.jpeg)

# 3- System Requirements.  
--------------------------
After studying the customer requirements, this is the requirement diagram that will be used in  The next meeting with the customer. 

![](https://github.com/mahmoudHussein202/Mastering-Embedded-Systems-deploma/blob/master/First_Term_Projects/Pressure_Detection/Report/Aspose.Words.a28f5dfc-a86e-4b51-bb70-9f4134a593e7.002.jpeg)

# 4- Space Exploration and partitioning. 
------------------------------------------
The MCU that will be used is STM32 ![](https://github.com/mahmoudHussein202/Mastering-Embedded-Systems-deploma/blob/master/First_Term_Projects/Pressure_Detection/Report/Aspose.Words.a28f5dfc-a86e-4b51-bb70-9f4134a593e7.003.png)

# 5- System Analysis. 
----------------------
System Analysis consists of three main sections : 
- Use Case Diagram “System Boundaries and main functions” 
- Activity Diagram “Relation between main functions” 
- Sequence Diagram “Communications between main system entities and actors” 

A-  Use case Diagram : 

![](https://github.com/mahmoudHussein202/Mastering-Embedded-Systems-deploma/blob/master/First_Term_Projects/Pressure_Detection/Report/Aspose.Words.a28f5dfc-a86e-4b51-bb70-9f4134a593e7.004.jpeg)

B-  Activity Diagram 

![](https://github.com/mahmoudHussein202/Mastering-Embedded-Systems-deploma/blob/master/First_Term_Projects/Pressure_Detection/Report/Aspose.Words.a28f5dfc-a86e-4b51-bb70-9f4134a593e7.005.jpeg)

C-  Sequential Diagram 

![](https://github.com/mahmoudHussein202/Mastering-Embedded-Systems-deploma/blob/master/First_Term_Projects/Pressure_Detection/Report/Aspose.Words.a28f5dfc-a86e-4b51-bb70-9f4134a593e7.006.jpeg)

# 6- System Design 
-------------------
- Block Diagram : 

![](https://github.com/mahmoudHussein202/Mastering-Embedded-Systems-deploma/blob/master/First_Term_Projects/Pressure_Detection/Report/Aspose.Words.a28f5dfc-a86e-4b51-bb70-9f4134a593e7.007.jpeg)

- Pressure Reading Block 

![](https://github.com/mahmoudHussein202/Mastering-Embedded-Systems-deploma/blob/master/First_Term_Projects/Pressure_Detection/Report/Aspose.Words.a28f5dfc-a86e-4b51-bb70-9f4134a593e7.008.jpeg)

- Main Algorithm Block   

![](https://github.com/mahmoudHussein202/Mastering-Embedded-Systems-deploma/blob/master/First_Term_Projects/Pressure_Detection/Report/Aspose.Words.a28f5dfc-a86e-4b51-bb70-9f4134a593e7.009.jpeg)

- Alarm Controller block 

![](https://github.com/mahmoudHussein202/Mastering-Embedded-Systems-deploma/blob/master/First_Term_Projects/Pressure_Detection/Report/Aspose.Words.a28f5dfc-a86e-4b51-bb70-9f4134a593e7.010.jpeg)

Simulation : 

pressure below the threshold :  

0  ![](https://github.com/mahmoudHussein202/Mastering-Embedded-Systems-deploma/blob/master/First_Term_Projects/Pressure_Detection/Report/Aspose.Words.a28f5dfc-a86e-4b51-bb70-9f4134a593e7.011.jpeg)![](https://github.com/mahmoudHussein202/Mastering-Embedded-Systems-deploma/blob/master/First_Term_Projects/Pressure_Detection/Report/Aspose.Words.a28f5dfc-a86e-4b51-bb70-9f4134a593e7.012.png)0  

Input  0  ![](https://github.com/mahmoudHussein202/Mastering-Embedded-Systems-deploma/blob/master/First_Term_Projects/Pressure_Detection/Report/Aspose.Words.a28f5dfc-a86e-4b51-bb70-9f4134a593e7.013.png)pressure  0  

- 16   

1  0  0  0  

Pressure above the threshold : 

0  ![](https://github.com/mahmoudHussein202/Mastering-Embedded-Systems-deploma/blob/master/First_Term_Projects/Pressure_Detection/Report/Aspose.Words.a28f5dfc-a86e-4b51-bb70-9f4134a593e7.014.jpeg)![](https://github.com/mahmoudHussein202/Mastering-Embedded-Systems-deploma/blob/master/First_Term_Projects/Pressure_Detection/Report/Aspose.Words.a28f5dfc-a86e-4b51-bb70-9f4134a593e7.015.png)

0  

0  ![](https://github.com/mahmoudHussein202/Mastering-Embedded-Systems-deploma/blob/master/First_Term_Projects/Pressure_Detection/Report/Aspose.Words.a28f5dfc-a86e-4b51-bb70-9f4134a593e7.016.png)Input  

pressure  0  

- 48   

1  1  0  0  

Recommendation in Version 1.1 : 

Need to store the values of the Measured pressures in the flash memory 

![](https://github.com/mahmoudHussein202/Mastering-Embedded-Systems-deploma/blob/master/First_Term_Projects/Pressure_Detection/Report/Aspose.Words.a28f5dfc-a86e-4b51-bb70-9f4134a593e7.017.jpeg)

Conclusion : 

After implementation and testing, the system works as required, it’s not completely efficient so it’s recommended to offer some safety features to the customer to improve the system performance. 
