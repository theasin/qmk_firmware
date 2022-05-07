# SPCGear GK530 Tournament

![GK530 Tournament](https://i.imgur.com/X9qO3WR.png)

A tenkeyless 87-key keyboard made by SPCGear, which controlled by an SN32F248F chipset. The keyboard features per-key RGB.

* Keyboard Maintainer: [HorrorTroll](https://github.com/HorrorTroll)
* Hardware Supported: SN32F248F
* Hardware Availability: [Amazon](https://www.amazon.de/-/en/GK530-Tournament-Gaming-Mechanical-Keyboard/dp/B07HXKL6M6)

Make example for this keyboard (after setting up your build environment):

    make spcgear/gk530:default

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader
* **Reset by wire**: Using a wire, 1 head to GND hole and other one to Boot pin on MCU
* **Keycode in layout**: Press the key mapped to RESET if it is available
