# TouchDRO

Adaptation of Yuriy Krushelnytskiy’s [TouchDRO project][2] to Sherline lathe and milling machines.

## Features

*   uses CUI's AMT102 rotary encoder @ $23 each. (V2 adds the ability to use Sherline's rotary encoder hand wheels @ $68 each)
*   no major modifications needed to the lathe or mill by using replacement bushings ($30) and new set of handwheels ($45)
*   inexpensive electronic components @ ~$10 including a tachometer
*   custom designed printed circuit board eliminates the need for lots of wiring
*   based on the teensyduino @ $9 but compatible with any arduino-based microcontroller
*   the TouchDRO project's app is compatible with any Android device with bluetooth Total cost, including an unbranded 7" android tablet from ebay: $250.

<a href="http://mirskytech.com/wp-content/uploads/2016/02/workbench.jpg" rel="attachment wp-att-231"><img class="alignleft wp-image-231 size-medium" src="http://mirskytech.com/wp-content/uploads/2016/02/workbench-300x138.jpg" alt="workbench" width="300" height="138" /></a>

And includes all of TouchDRO's features:

* Bluetooth connectivity support
* Display for up to four axes
* Support for metric an imperial units (mm and inch)
* Support for standard DRO functions:
  * Tool Offset
  * Preset Dimension
  * “1/2” Function
  * Hole Circle (Arch)
  * Hole Grid
  * Point memory only limited by internal storage capacity of device
  * Multiple workspaces
  * Worskpace preview

Implementation details can be found here:

*   [mechanical adaptation][3] of lathe and/or mill for rotary encoders
*   [electronic components and firmware][4] for encoder interface

## Updates

There is now a second version of the interface (rev 2) with several enhancements. More information can be found here [TouchDRO rev 2][5].

[2]: http://www.yuriystoys.com/p/android-dro.html
[3]: http://mirskytech.com/sherline-touchdro-mechanical/
[4]: http://mirskytech.com/sherline-touchdro-electronics/
[5]: http://mirskytech.com/touchdro-for-sherline-rev-2/
