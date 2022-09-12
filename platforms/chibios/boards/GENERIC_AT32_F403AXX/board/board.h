/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio
    ChibiOS - Copyright (C) 2022 Artery Technology
    ChibiOS - Copyright (C) 2022 HorrorTroll

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#ifndef _BOARD_H_
#define _BOARD_H_

/*
 * Setup for a Generic AT32F403A board.
 */

/*
 * Board identifier.
 */
#define BOARD_GENERIC_AT32_F403A
#define BOARD_NAME              "GENERIC AT32F403A board"

/*
 * Board frequencies.
 */
#define STM32_LSECLK            32768
#define STM32_HSECLK            8000000

/*
 * MCU type, supported types are defined in ./os/hal/platforms/hal_lld.h.
 */
#define STM32F103xB

/*
 * IO pins assignments.
 */
#define GPIOA_PIN0                0U
#define GPIOA_PIN1                1U
#define GPIOA_PIN2                2U
#define GPIOA_PIN3                3U
#define GPIOA_PIN4                4U
#define GPIOA_PIN5                5U
#define GPIOA_PIN6                6U
#define GPIOA_PIN7                7U
#define GPIOA_PIN8                8U
#define GPIOA_PIN9                9U
#define GPIOA_PIN10               10U
#define GPIOA_PIN11               11U
#define GPIOA_PIN12               12U
#define GPIOA_PIN13               13U
#define GPIOA_PIN14               14U
#define GPIOA_PIN15               15U

#define GPIOB_PIN0                0U
#define GPIOB_PIN1                1U
#define GPIOB_PIN2                2U
#define GPIOB_PIN3                3U
#define GPIOB_PIN4                4U
#define GPIOB_PIN5                5U
#define GPIOB_PIN6                6U
#define GPIOB_PIN7                7U
#define GPIOB_PIN8                8U
#define GPIOB_PIN9                9U
#define GPIOB_PIN10               10U
#define GPIOB_PIN11               11U
#define GPIOB_PIN12               12U
#define GPIOB_PIN13               13U
#define GPIOB_PIN14               14U
#define GPIOB_PIN15               15U

#define GPIOC_PIN0                0U
#define GPIOC_PIN1                1U
#define GPIOC_PIN2                2U
#define GPIOC_PIN3                3U
#define GPIOC_PIN4                4U
#define GPIOC_PIN5                5U
#define GPIOC_PIN6                6U
#define GPIOC_PIN7                7U
#define GPIOC_PIN8                8U
#define GPIOC_PIN9                9U
#define GPIOC_PIN10               10U
#define GPIOC_PIN11               11U
#define GPIOC_PIN12               12U
#define GPIOC_PIN13               13U
#define GPIOC_PIN14               14U
#define GPIOC_PIN15               15U

#define GPIOD_PIN0                0U
#define GPIOD_PIN1                1U
#define GPIOD_PIN2                2U
#define GPIOD_PIN3                3U
#define GPIOD_PIN4                4U
#define GPIOD_PIN5                5U
#define GPIOD_PIN6                6U
#define GPIOD_PIN7                7U
#define GPIOD_PIN8                8U
#define GPIOD_PIN9                9U
#define GPIOD_PIN10               10U
#define GPIOD_PIN11               11U
#define GPIOD_PIN12               12U
#define GPIOD_PIN13               13U
#define GPIOD_PIN14               14U
#define GPIOD_PIN15               15U

#define GPIOE_PIN0                0U
#define GPIOE_PIN1                1U
#define GPIOE_PIN2                2U
#define GPIOE_PIN3                3U
#define GPIOE_PIN4                4U
#define GPIOE_PIN5                5U
#define GPIOE_PIN6                6U
#define GPIOE_PIN7                7U
#define GPIOE_PIN8                8U
#define GPIOE_PIN9                9U
#define GPIOE_PIN10               10U
#define GPIOE_PIN11               11U
#define GPIOE_PIN12               12U
#define GPIOE_PIN13               13U
#define GPIOE_PIN14               14U
#define GPIOE_PIN15               15U

/*
 * I/O ports initial setup, this configuration is established soon after reset
 * in the initialization code.
 *
 * The digits have the following meaning:
 *   0 - Analog input.
 *   1 - Push Pull output 10MHz.
 *   2 - Push Pull output 2MHz.
 *   3 - Push Pull output 50MHz.
 *   4 - Digital input.
 *   5 - Open Drain output 10MHz.
 *   6 - Open Drain output 2MHz.
 *   7 - Open Drain output 50MHz.
 *   8 - Digital input with PullUp or PullDown resistor depending on ODR.
 *   9 - Alternate Push Pull output 10MHz.
 *   A - Alternate Push Pull output 2MHz.
 *   B - Alternate Push Pull output 50MHz.
 *   C - Reserved.
 *   D - Alternate Open Drain output 10MHz.
 *   E - Alternate Open Drain output 2MHz.
 *   F - Alternate Open Drain output 50MHz.
 * Please refer to the STM32 Reference Manual for details.
 */

/*
 * Port A setup.
 * Everything input with pull-up except:
 */
#define VAL_GPIOACRL            0x88888B88      /*  PA7...PA0 */
#define VAL_GPIOACRH            0x888888B8      /* PA15...PA8 */
#define VAL_GPIOAODR            0xFFFFFFFF

/*
 * Port B setup.
 * Everything input with pull-up except:
 */
#define VAL_GPIOBCRL            0x88888888      /*  PB7...PB0 */
#define VAL_GPIOBCRH            0x88888888      /* PB15...PB8 */
#define VAL_GPIOBODR            0xFFFFFFFF

/*
 * Port C setup.
 * Everything input with pull-up except:
 */
#define VAL_GPIOCCRL            0x88888888      /*  PC7...PC0 */
#define VAL_GPIOCCRH            0x88888888      /* PC15...PC8 */
#define VAL_GPIOCODR            0xFFFFFFFF

/*
 * Port D setup.
 * Everything input with pull-up except:
 * PD0  - Normal input (XTAL).
 * PD1  - Normal input (XTAL).
 */
#define VAL_GPIODCRL            0x88888844      /*  PD7...PD0 */
#define VAL_GPIODCRH            0x88888888      /* PD15...PD8 */
#define VAL_GPIODODR            0xFFFFFFFF

/*
 * Port E setup.
 * Everything input with pull-up except:
 */
#define VAL_GPIOECRL            0x88888888      /*  PE7...PE0 */
#define VAL_GPIOECRH            0x88888888      /* PE15...PE8 */
#define VAL_GPIOEODR            0xFFFFFFFF

/*
 * USB bus activation macro, required by the USB driver.
 */
#define usb_lld_connect_bus(usbp)

/*
 * USB bus de-activation macro, required by the USB driver.
 */
#define usb_lld_disconnect_bus(usbp)

#if !defined(_FROM_ASM_)
#ifdef __cplusplus
extern "C" {
#endif
  void boardInit(void);
#ifdef __cplusplus
}
#endif
#endif /* _FROM_ASM_ */

#endif /* _BOARD_H_ */
