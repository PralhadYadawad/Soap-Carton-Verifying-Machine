# Soap-Carton-Verifying-Machine
The Soap Carton Verifying Machine, utilizing an ARMTM7 processor on the LPC2148 board, integrates advanced technologies for accurate soap count verification. Meticulously crafted code ensures seamless component interaction, showcasing technical sophistication in automated soap manufacturing.

**Project Brief: Soap Carton Verifying Machine**

**Problem Statement:**
In a manufacturing setting, it is crucial to ensure that soap cartons are filled with the required quantity, typically 10 soaps per carton. The challenge lies in efficiently verifying the soap count within each carton and taking corrective action if the count is below the specified threshold.

**Problem Analysis:**
To address this issue, we have developed a Soap Carton Verifying Machine. The system utilizes a DC motor as a conveyor belt to continuously move cartons. An ultrasonic sensor, strategically placed parallel to the conveyor belt, employs triggering and echo waves to determine the soap count within the carton.

- If the soap count is less than 10, the system displays "Cart is empty" on a 4-bit mode LCD and activates a stepper motor. The stepper motor, coupled with an L-shaped claw, removes the unfilled carton from the conveyor belt.
  
- If the soap count is 10, the system displays "Cart is full" on the LCD, and the conveyor belt continues its operation.

**Technological Implementation:**
The solution is implemented on an ARMTM7 processor, specifically the LPC2148 board. The algorithmic logic is executed through code integration on the processor.

**Technical Specifications:**
- **Microcontroller:**
  - ARMTM7 (Cortex-M7)
- **Evaluation Board:**
  - LPC2148 Evaluation Board
- **Peripherals:**
  1. **UART (Universal Asynchronous Receiver-Transmitter):**
     - Used for serial communication.
     - Displays precise distance measured by the ultrasonic sensor.
  2. **Ultrasonic Sensor:**
     - Utilizes triggering and echo waves to measure distances accurately.
     - Positioned parallel to the conveyor belt to assess soap count within cartons.
  3. **LCD (Liquid Crystal Display):**
     - 4-bit mode LCD used for real-time feedback.
     - Displays messages such as "Cart is empty" or "Cart is full" based on soap count.
  4. **Stepper Motor:**
     - Activated when soap count is below the specified threshold.
     - Attached to an L-shaped claw to remove unfilled cartons from the conveyor belt.
     - Rotates through a fixed angle to execute the removal process.
  5. **DC Motor:**
     - Drives the conveyor belt for continuous carton movement.
     - Ensures the smooth and uninterrupted flow of cartons during the verification process.

**Key Features:**
1. Continuous operation: The conveyor belt, driven by a DC motor, runs continuously for efficient carton movement.
2. Ultrasonic sensing: An ultrasonic sensor accurately measures soap count within each carton.
3. Real-time feedback: The LCD provides instant feedback on the carton status, ensuring timely corrective action.
4. Stepper motor mechanism: A stepper motor, triggered when the soap count is below the threshold, removes unfilled cartons from the conveyor belt.
5. Process optimization: The system ensures that only cartons containing the correct soap count proceed, minimizing manufacturing defects.

**Benefits:**
- Prevents manufacturing defects by verifying soap count in real-time.
- Increases operational efficiency by automating the verification process.
- Facilitates continuous production flow with timely corrective actions.

**Conclusion:**
The Soap Carton Verifying Machine offers a reliable and automated solution to address the challenge of ensuring the correct soap count in manufacturing processes. By integrating advanced technologies and efficient algorithms, the system contributes to enhanced production quality and reduced defects.
