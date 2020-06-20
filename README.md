# ObstacleAvoidingCar
Code for small car controlled using an Arduino and Ultrasonic Sensor to detect and avoid obstacles. 

Video of Car: https://www.youtube.com/watch?v=yoW-r739SYg&feature=youtu.be

Link to Blog: https://medium.com/@shubhsehgal03/arduino-obstacle-avoiding-car-project-c9cfb818f50b

How it Works 
To start the car, the power cable should be connected to the Arduino, and then the red jumper cable going from the motor driver should be connected to the power column of the breadboard. This provides power to both the Arduino and the motors. The Arduino will then setup the ultrasonic sensor, and begin driving forward. As it moves, the ultrasonic sensor will constantly take distance readings. If the distance in front of it is less than or equal to 20 cm, the car will stop and turn. After turning, the car will take another distance reading, and decide whether to move forward or turn again. This will keep going on until the motor driver power and Arduino power are disconnected.

To 
