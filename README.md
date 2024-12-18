## Obstacle-Avoiding Robot
![1719131258805](https://github.com/user-attachments/assets/2400d553-8b34-406b-a855-a872efb3988a)


### Overview

The Obstacle-Avoiding Robot is an autonomous robotic vehicle designed to navigate through its environment while avoiding obstacles in its path. This project showcases the integration of various sensors, motors, and microcontrollers to create a functional robot capable of intelligent movement and decision-making. It's a great project for beginners in robotics and enthusiasts looking to understand the basics of sensor integration, motor control, and algorithm development.

### Features

- **Obstacle Detection**: Utilizes ultrasonic sensors to detect obstacles in the robot's path.
- **Intelligent Navigation**: Implements algorithms to navigate around obstacles.
- **Real-Time Decision Making**: Capable of making real-time decisions to change direction and avoid collisions.
- **Modular Design**: Easily extendable to include additional features like remote control, camera integration, or advanced navigation algorithms.
- **Open-Source**: All code and design files are available for modification and improvement.

### Components

- **Microcontroller**: Arduino Uno or any compatible microcontroller board.
- **Sensors**: Ultrasonic sensors (e.g., HC-SR04) for distance measurement.
- **Motors**: DC motors with motor driver (e.g., L298N) for controlling the wheels.
- **Chassis**: A robot chassis kit with wheels and a platform to mount components.
- **Power Supply**: Battery pack to power the microcontroller and motors.
- **Miscellaneous**: Breadboard, jumper wires, resistors, and other basic electronics components.

### Getting Started

1. **Assemble the Hardware**:
   - Mount the ultrasonic sensors on the front of the robot.
   - Connect the DC motors to the motor driver and then to the wheels.
   - Attach the motor driver and ultrasonic sensors to the microcontroller.
   - Ensure all connections are secure and power the setup with the battery pack.

2. **Install the Software**:
   - Download and install the Arduino IDE from [Arduino's official website](https://www.arduino.cc/en/software).
   - Clone or download this repository and open the provided Arduino sketch in the IDE.

3. **Upload the Code**:
   - Connect the Arduino to your computer via USB.
   - Select the correct board and port from the Arduino IDE.
   - Upload the code to the Arduino.


##
   ```cpp
   #include <Servo.h>
   #include <Ultrasonic.h>
   
   Servo s = Servo();
   Ultrasonic u = Ultrasonic(2, 3);
   
   #define ENA 11 // LHS
   #define in1 12
   #define in2 13
   
   #define ENB 10 // RHS
   #define in3 8
   #define in4 9

   void setup() {
     // put your setup code here, to run once:
     Serial.begin(9600);

     s.attach(4);
   
     pinMode(ENA, OUTPUT);
     pinMode(in1, OUTPUT);
     pinMode(in2, OUTPUT);
   
     pinMode(ENB, OUTPUT);
     pinMode(in3, OUTPUT);
     pinMode(in4, OUTPUT);
   
     analogWrite(ENA, 300); // Adjusted PWM value to fit 8-bit range (0-255)
     analogWrite(ENB, 255);
   }
   
   void loop() {
     // put your main code here, to run repeatedly:
   
     int x = Serial.read();
   
     if (x == '1') { // forward
       s.write(90);
       delay(400);
       int d = u.read();

    if (d > 10) {
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
      delay(500);
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
      delay(500);
    } else {
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      delay(500);
    }
     }

     if (x == '2') { // backward
       digitalWrite(in1, HIGH);
       digitalWrite(in2, LOW);
       digitalWrite(in3, HIGH);
       digitalWrite(in4, LOW);
       delay(500);
       digitalWrite(in1, LOW);
       digitalWrite(in2, LOW);
       digitalWrite(in3, LOW);
       digitalWrite(in4, LOW);
       delay(500);
     }
   }
   
   ```
