# Ajazz AK33

![AK33](https://i.imgur.com/nOqxtaa.png)

A keyboard 82-key made by Ajazz, which controlled by an SN32F248F chipset. The keyboard features per-key RGB.

* Keyboard Maintainer: [HorrorTroll](https://github.com/HorrorTroll)
* Hardware Supported: SN32F248F
* Hardware Availability: [Amazon](https://www.amazon.co.uk/AK33-Mechanical-Anti-Ghosting-Multimedia-Ergonomic/dp/B075XHTT1D) / [AliExpress](https://www.aliexpress.com/item/1005002669571128.html)

Make example for this keyboard (after setting up your build environment):

    make ajazz/ak33/rev1:default

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader
* **Reset by wire**: Using a wire, 1 head to GND hole and other one to Boot pin on MCU
* **Keycode in layout**: Press the key mapped to RESET if it is available
