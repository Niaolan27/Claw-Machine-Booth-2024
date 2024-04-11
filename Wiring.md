Breadboard: 
Left driver is Pulley
Right driver is LR



Purple: direction
White: step
Green: sleep to sleep
Yellow: logic power
Orange: logic ground

Driver to Motor:


           --------------
<NA>    MS1|            | VMOT  Green 
<NA>    MS2|            | GND  White
<NA>    MS2|            | 2B   White --> Green (Horizontal) | Red (Pulley)
<NA>    MS3|            | 2A   Black --> Gray (Horizontal) | Black (Pulley)
Yellow  RST|            | 1A   Brown --> Red (Horizontal) | Blue (Pulley)
Yellow  SLP|            | 1B   Red --> Yellow (Horizontal) | Green (Pulley)
White  STEP|            | VDD  Red
Purple  DIR|            | GND  Black

1A and 1B are paired
2A and 2B are paired
RST and SLP are connected

Jumper cables to keep:
Breadboard power and ground to Arduino

Interface to the crate:
12 wires to buttons (3 buttons)
Mains power
Limit Switch Left: 2 wires  
Stationary Motor Left: 4 wires
Limit Switch Right 2 wires
Moving Motor: 4 wires (coiled wire)

Along ceiling (to middle):


Coiled wire: 

 
To Solder:
Moving Motor to Coiled Wire (cut short motor mires first)
ECE wire to limit switch x2
Stationary Motor to ECE wire
Coiled Wire to ECE Wire
