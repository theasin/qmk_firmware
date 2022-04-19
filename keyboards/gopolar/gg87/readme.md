# Gopolar GG87 Tai-Chi

![GG87 Tai-Chi](https://i.imgur.com/1KJQi91.png)

A tenkeyless 87-key keyboard made by Gopolar, which controlled by an Atmega32u4 chipset. The keyboard features per-key RGB as well as underglow RGB, and an OLED screen for displaying useful information.

* Keyboard Maintainer: Gopolar
* Hardware Supported: Atmega32u4
* Hardware Availability: [AliExpress](https://www.aliexpress.com/item/1005003787699983.html)

Make example for this keyboard (after setting up your build environment):

    make gopolar/gg87:default 

Flashing example for this keyboard:

    make gopolar/gg87:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader
* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (Esc key) and plug in the keyboard
* **Physical reset button**: Short press the button under Spacebar keycap to enter the Bootloader and flash the firmware
* **Keycode in layout**: Press the key mapped to QK_BOOT if it is available
