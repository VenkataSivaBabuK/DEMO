# STM32 GPIO Low-Level Driver

## Project Overview

This project implements a low-level General Purpose Input/Output (GPIO) driver for the STM32F446RE microcontroller using Embedded C.

The driver is developed to understand GPIO peripheral configuration and direct register-level programming without relying on the STM32 HAL GPIO APIs for the driver implementation.

The project demonstrates GPIO initialization, pin configuration, LED control, and external interrupt handling using the STM32F446RE microcontroller.

## Hardware Requirements

* STM32 NUCLEO-F446RE development board
* USB cable for programming and debugging
* STM32 onboard LED (LD2)
* STM32 onboard user push button (PC13)

## Software Requirements

* STM32CubeIDE
* Embedded C
* ARM Cortex-M4 microcontroller architecture

## Features Implemented

* Low-level GPIO driver development using Embedded C
* GPIO peripheral register configuration
* GPIO pin mode configuration
* GPIO output control for LED operation
* GPIO input handling
* External interrupt configuration and handling
* Onboard user button interrupt handling
* Direct interaction with microcontroller registers

## GPIO Driver Implementation

The GPIO driver is organized into header and source files.

### Header Files

**`stm32f446xx.h`**

* Contains microcontroller register definitions used by the driver.

**`stm32f446xx_gpio.h`**

* Contains GPIO register definitions, configuration structures, macros, and function declarations.

### Source Files

**`stm32f446xx_gpio.c`**

* Implements GPIO driver functions for peripheral initialization and pin operations.

**Application source files**

* `Led_toggle.c` — LED toggling application.
* `led_toggle_with_onboard_button.c` — LED control using the onboard user button.
* `GPIO_int.c` — GPIO interrupt-related implementation.
* `Int_both_edges.c` — Interrupt handling for both signal edges.

The application files demonstrate different GPIO usage scenarios. The exact functionality depends on the implementation in each source file.

## GPIO Configuration

The driver supports configuring GPIO pins through microcontroller registers.

GPIO configuration involves:

* Enabling the GPIO peripheral clock.
* Configuring the pin mode as input, output, alternate function, or analog.
* Configuring output type and speed.
* Configuring pull-up and pull-down resistors.
* Reading input pin states and controlling output pin states.

## Interrupt Handling

The project includes GPIO external interrupt-related implementations.

The interrupt configuration involves the GPIO input, EXTI configuration, and interrupt handling through the microcontroller's interrupt controller, where implemented.

The onboard user button on the NUCLEO-F446RE board is connected to PC13.

## Development Environment

| Component            | Details                                   |
| -------------------- | ----------------------------------------- |
| Microcontroller      | STM32F446RE                               |
| Architecture         | ARM Cortex-M4                             |
| Programming Language | Embedded C                                |
| IDE                  | STM32CubeIDE                              |
| Driver Approach      | Low-level register programming            |
| Application          | GPIO, LED control, and interrupt handling |

## Learning Outcomes

* Understanding GPIO peripheral registers.
* Developing reusable low-level drivers in Embedded C.
* Configuring microcontroller pins through register-level programming.
* Understanding GPIO input and output operations.
* Learning the relationship between GPIO, EXTI, and interrupt handling.
* Separating peripheral driver implementation from application code.

## Repository Structure

```text
gpio/
├── Driver/
│   ├── Inc/
│   │   ├── stm32f446xx.h
│   │   └── stm32f446xx_gpio.h
│   └── Src/
│       └── stm32f446xx_gpio.c
├── Src/
│   ├── GPIO_int.c
│   ├── Int_both_edges.c
│   ├── Led_toggle.c
│   ├── led_toggle_with_onboard_button.c
│   └── main.c
├── Startup/
├── .project
├── .cproject
└── README.md
```

## Future Improvements

* Add more GPIO configuration examples.
* Improve driver error handling and validation.
* Add documentation for each public driver API.
* Add test cases for different GPIO configurations.
