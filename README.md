#VSCode Arduino 101 Starter Project for Zephyr

This is a skeleton project to use when writing applications for the Arduino 101 using the Zephyr RTOS.  It has settings for the VSCode project and was implemented on a mac.

Firstly you will need to install the [C/C++ Extension](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools) for VS Code:

    ext install cpptools

You will find the following tasks available once you open the directory (hopefully the names are self-explanatory):
- clean
- build
- deploy
- x86_debug_server (this one starts the openocd debug server for x86 that you can attach GDB to)
- arc_debug_server (this one starts the openocd debug server for arc that you can attach GDB to)

The project is split into an `x86` and an `arc` area where you can put the code you want to run on each core.

**NOTE** It assumes that you have a volume called `/Volumes/CrossToolNG` that contains `zephyr` and `arc-elf32` sub-directories containing the zephyr project kernel source and version **1.6.4+1.0** of the ARC tools.  Take a look in `.vscode/tasks.json` if not.

##Further Information

Getting the Zephyr project to work properly on the mac takes a bit of fiddling, I have made a few gists of notes that may help:

- [Building Zephyr OS on Mac](https://gist.github.com/kmp1/9d6068766b1bd841494cad3ab1128622)
- [Compiling an Application on Zephyr OS for Arduino 101 on the MAC](https://gist.github.com/kmp1/60247d08d4c9c235439872c7bfce2ab4)
- [Notes on Getting Flashing a Zephyr Image using a JTAG Adapter on MAC](https://gist.github.com/kmp1/7fc987aebb11e73cab433264e0ed8123)

##Example Application Details

The example application uses the `arc` and `x86` cores to blink two LEDs.  The red one is controlled by the `x86` core and the green by the `arc` core.  The red is connected to pin **IO8** and green to pin **A0**.

Components Required:

- 3 x Jumper Wire
- 2 x LED
- 2 x 220 ohm Resistor

###Circuit

Following is details of the circuit.  The fritzing format file can be found at `circuit/double_led.fzz`.

####Breadboard

![Double LED Circuit Breadboard](circuit/double_led_breadboard.png)

####Schematic
![Double LED Circuit Schematic](circuit/double_led_schematic.png)