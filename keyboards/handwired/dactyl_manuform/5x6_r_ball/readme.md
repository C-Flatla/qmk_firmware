# handwired/dactyl_manuform/5x6_r_ball

This is a flat Dactyl ManuForm 5x6 with a 5 key bottom row.
The left thumb has 6 keys.
The right thumb has a PMW3360 trackball and 3 keys.
Totalling 67 keys.

![handwired/dactyl_manuform/5x6_r_ball](https://gist.github.com/user-attachments/assets/22ae1590-f1c3-43dc-8121-b4e86978b64c)

*A short description of the keyboard/project*

* Keyboard Maintainer: [Cody Flatla](https://github.com/C-Flatla)
* Hardware Supported: *The PCBs, controllers supported*
* Hardware Availability: *Links to where you can find this hardware*

Make example for this keyboard (after setting up your build environment):

    make handwired/dactyl_manuform/5x6_r_ball:default

Flashing example for this keyboard:

    make handwired/dactyl_manuform/5x6_r_ball:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
