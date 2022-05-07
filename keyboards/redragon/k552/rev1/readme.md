# Redragon K552 Kumara

![K552 Kumara](https://i.imgur.com/taX2SOfh.jpg)

A tenkeyless 87-key keyboard made by Redragon, which controlled by an SN32F248F chipset. The keyboard features per-key RGB.

* Keyboard Maintainer: [HorrorTroll](https://github.com/HorrorTroll)
* Hardware Supported: SN32F248F
* Hardware Availability: [Amazon](https://www.amazon.com/Redragon-K552-RGB-Mechanical-Keyboard-Construction/dp/B019O9BLVY)

Make example for this keyboard (after setting up your build environment):

    make redragon/k552/rev1:default

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader
* **Reset by wire**: Using a wire, 1 head to GND hole and other one to Boot pin on MCU
* **Keycode in layout**: Press the key mapped to RESET if it is available
