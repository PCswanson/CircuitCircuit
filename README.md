# CircuitCircuit 1.1
Code for Adafruit's Circuit Playground Developers Board which gives it 8 capacitive touch connections like a Makey-Makey has.

The +/- switch turns the functions on and off.

The default connections and their keyboard / mouse outputs are:

Up Arrow Key: pin 10

Down Arrow Key: pin 9

Left Arrow Key: pin 6

Right Arrow Key: pin 12

Space Bar: pin 1

"a" key: pin 0

"b" key: pin 2

"c" key: pin 3

Pressing the right button will send through the keyboard: "l###" followed by carriage return where ### is a number between 0-1024 signifying the light level at the eyeball on the Circuit Playground.

Pressing the left button will send through the keyboard: "t##" followed by carriage return where ## is a temperature F (unless you uncomment the specified line to switch it to C).

Both of these functions are formatted for easy use with Scratch's Question block.
