# ECE484_HRS

HARDWARE OVERVIEW

The front of the sensor, with the heart logo, is where you put your finger. You’ll also notice a tiny circular opening through which the Kingbright’s reverse mounted green LED shines.

![Untitled](https://github.com/CarloB26/ECE484_HRS/assets/153125389/8c886f7e-b6fd-4116-bb4d-695993e891cc)

Just beneath the circular opening is a small ambient light photo sensor – APDS-9008

On the back of the module are an MCP6001 Op-Amp from Microchip and a few resistors and capacitors that make up the R/C filter network. Additionally, there is a reverse protection diode to prevent damage in the event that the power leads are accidentally reversed.

![Screenshot 2024-03-13 021712](https://github.com/CarloB26/ECE484_HRS/assets/153125389/24ce898b-f4cc-429b-bb47-99ebbab6f618)

The module requires a DC power supply ranging from 3.3 to 5V and draws less than 4mA of current.

TECHNICAL SPECIFICATIONS 

Here are the technical specifications:

Maximum Ratings (VCC, IMax, VOut)

VCC	3.0 – 5.5V

IMax (Maximum Current Draw)	< 4mA

VOut (Output Voltage Range)	0.3V to Vcc

Wavelength (LED output, Sensor Input)

LED Output	565nm

Sensor Input	525nm


