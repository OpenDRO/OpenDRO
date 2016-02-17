# TouchDRO

Adaptation of Yuriy Krushelnytskiy’s [TouchDRO project][2] to Sherline lathe and milling machines.

## Features
*   uses CUI's AMT102 rotary encoder
*   requires only adaptation of existing parts, easily modifiable by purchasing a new set of bushings and handwheels
*   inexpensive electronic components, including a tachometer
*   custom designed printed circuit board eliminates the need for lots of wiring
*   based on the teensyduino but compatible with any arduino-based microcontroller
*   the TouchDRO project's app is compatible with any Android device with bluetooth

<a href="http://mirskytech.com/wp-content/uploads/2016/02/workbench.jpg" rel="attachment wp-att-231"><img class="alignleft wp-image-231 size-medium" src="http://mirskytech.com/wp-content/uploads/2016/02/workbench-300x138.jpg" alt="workbench" width="300" height="138" /></a>

And includes all of TouchDRO's features:

*   Bluetooth connectivity support
*   Display for up to four axes
*   Support for metric an imperial units (mm and inch)
*   Support for standard DRO functions:
    *   Tool Offset
    *   Preset Dimension
    *   “1/2” Function
    *   Hole Circle (Arch)
    *   Hole Grid
    *   Point memory only limited by internal storage capacity of device
    *   Multiple workspaces
    *   Worskpace preview

Implementation details can be found here:

*   [mechanical adaptation][3] of lathe and/or mill for rotary encoders
*   [electronic components and firmware][4] for encoder interface


## Updates

There is now a second version of the interface (rev 2) with several enhancements. More information can be found here [TouchDRO rev 2][5].

[2]: http://www.yuriystoys.com/p/android-dro.html
[3]: http://mirskytech.com/sherline-touchdro-mechanical/
[4]: http://mirskytech.com/sherline-touchdro-electronics/
[5]: http://mirskytech.com/touchdro-for-sherline-rev-2/
