# Claw-Machine-Booth-2024

Code for the claw machine all goes here. Together with some explanations and notes about setting up.

Pin Allocation:
- 3: driver step pin
- 4: driver dir pin
- 7: right limit 
- 8: left limit
- 10: pulley button
- 12: left button
- 13: right button

Limit Switch:
- Connect to NO and C
- Use a pull-down resistor

Stepper Motor:
- Stepper motor moves in steps
- Increasing the delay for LOW reduces the speed of the motor
- Seems to have a minimum of 500 microseconds for delay
