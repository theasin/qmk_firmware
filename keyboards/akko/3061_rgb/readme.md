# AKKO 3061S World Tour Tokyo R2

This is the 3061S World Tour Tokyo R2 made by AKKO

* Keyboard Maintainer: [HorrorTroll](https://github.com/HorrorTroll)
* Hardware Supported: SN32F248B

Make example for this keyboard (after setting up your build environment):

    make akko/3061_rgb:default

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Not working right now
* **Reset by wire**: Unplug USB. Using a wire, 1 head to GND and other one to Boot pin on MCU. Hold the wire, and then plug USB
* **Keycode in layout**: Press the key mapped to RESET if it is available
