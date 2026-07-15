// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// GPIO.h defines all the GPIO registers.
// This file is part of the TeensyRegs library.

#pragma once

#include <cstddef>
#include <cstdint>

#include "hardware/regs/regs.h"

namespace qindesign {
namespace hardware {
namespace teensy4 {

// GPIO layout. Comments are from BSD-3-licensed NXP SDK.
//
// See:
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/periph/PERI_GPIO.h
// * https://github.com/nxp-mcuxpresso/legacy-mcux-sdk/blob/main/devices/MIMXRT1062/MIMXRT1062.h

struct GPIO_Layout {
  volatile uint32_t DR;                                /**< GPIO data register, offset: 0x0 */
  volatile uint32_t GDIR;                              /**< GPIO direction register, offset: 0x4 */
  const volatile uint32_t PSR;                         /**< GPIO pad status register, offset: 0x8 */
  volatile uint32_t ICR1;                              /**< GPIO interrupt configuration register1, offset: 0xC */
  volatile uint32_t ICR2;                              /**< GPIO interrupt configuration register2, offset: 0x10 */
  volatile uint32_t IMR;                               /**< GPIO interrupt mask register, offset: 0x14 */
  volatile uint32_t ISR;                               /**< GPIO interrupt status register, offset: 0x18 */
  volatile uint32_t EDGE_SEL;                          /**< GPIO edge select register, offset: 0x1C */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[25];
  volatile uint32_t DR_SET;                            /**< GPIO data register SET, offset: 0x84 */
  volatile uint32_t DR_CLEAR;                          /**< GPIO data register CLEAR, offset: 0x88 */
  volatile uint32_t DR_TOGGLE;                         /**< GPIO data register TOGGLE, offset: 0x8C */
};

constexpr size_t    kGPIO_size  = 0x90;
constexpr uintptr_t kGPIO1_base = 0x401B8000;
constexpr uintptr_t kGPIO2_base = 0x401BC000;
constexpr uintptr_t kGPIO3_base = 0x401C0000;
constexpr uintptr_t kGPIO4_base = 0x401C4000;
constexpr uintptr_t kGPIO5_base = 0x400C0000;
constexpr uintptr_t kGPIO6_base = 0x42000000;
constexpr uintptr_t kGPIO7_base = 0x42004000;
constexpr uintptr_t kGPIO8_base = 0x42008000;
constexpr uintptr_t kGPIO9_base = 0x4200C000;

constexpr regs::RegGroup<GPIO_Layout, kGPIO_size, kGPIO1_base> GPIO1;
constexpr regs::RegGroup<GPIO_Layout, kGPIO_size, kGPIO2_base> GPIO2;
constexpr regs::RegGroup<GPIO_Layout, kGPIO_size, kGPIO3_base> GPIO3;
constexpr regs::RegGroup<GPIO_Layout, kGPIO_size, kGPIO4_base> GPIO4;
constexpr regs::RegGroup<GPIO_Layout, kGPIO_size, kGPIO5_base> GPIO5;
constexpr regs::RegGroup<GPIO_Layout, kGPIO_size, kGPIO6_base> GPIO6;
constexpr regs::RegGroup<GPIO_Layout, kGPIO_size, kGPIO7_base> GPIO7;
constexpr regs::RegGroup<GPIO_Layout, kGPIO_size, kGPIO8_base> GPIO8;
constexpr regs::RegGroup<GPIO_Layout, kGPIO_size, kGPIO9_base> GPIO9;

// Undefine anything defined by Teensyduino's imxrt.h

// ICR1 values
#undef GPIO_ICR15
constexpr regs::RegValue<uint32_t, 2, 30> GPIO_ICR15;
#undef GPIO_ICR14
constexpr regs::RegValue<uint32_t, 2, 28> GPIO_ICR14;
#undef GPIO_ICR13
constexpr regs::RegValue<uint32_t, 2, 26> GPIO_ICR13;
#undef GPIO_ICR12
constexpr regs::RegValue<uint32_t, 2, 24> GPIO_ICR12;
#undef GPIO_ICR11
constexpr regs::RegValue<uint32_t, 2, 22> GPIO_ICR11;
#undef GPIO_ICR10
constexpr regs::RegValue<uint32_t, 2, 20> GPIO_ICR10;
#undef GPIO_ICR9
constexpr regs::RegValue<uint32_t, 2, 18> GPIO_ICR9;
#undef GPIO_ICR8
constexpr regs::RegValue<uint32_t, 2, 16> GPIO_ICR8;
#undef GPIO_ICR7
constexpr regs::RegValue<uint32_t, 2, 14> GPIO_ICR7;
#undef GPIO_ICR6
constexpr regs::RegValue<uint32_t, 2, 12> GPIO_ICR6;
#undef GPIO_ICR5
constexpr regs::RegValue<uint32_t, 2, 10> GPIO_ICR5;
#undef GPIO_ICR4
constexpr regs::RegValue<uint32_t, 2,  8> GPIO_ICR4;
#undef GPIO_ICR3
constexpr regs::RegValue<uint32_t, 2,  6> GPIO_ICR3;
#undef GPIO_ICR2
constexpr regs::RegValue<uint32_t, 2,  4> GPIO_ICR2;
#undef GPIO_ICR1
constexpr regs::RegValue<uint32_t, 2,  2> GPIO_ICR1;
#undef GPIO_ICR0
constexpr regs::RegValue<uint32_t, 2,  0> GPIO_ICR0;

// ICR2 values
#undef GPIO_ICR31
constexpr regs::RegValue<uint32_t, 2, 30> GPIO_ICR31;
#undef GPIO_ICR30
constexpr regs::RegValue<uint32_t, 2, 28> GPIO_ICR30;
#undef GPIO_ICR29
constexpr regs::RegValue<uint32_t, 2, 26> GPIO_ICR29;
#undef GPIO_ICR28
constexpr regs::RegValue<uint32_t, 2, 24> GPIO_ICR28;
#undef GPIO_ICR27
constexpr regs::RegValue<uint32_t, 2, 22> GPIO_ICR27;
#undef GPIO_ICR26
constexpr regs::RegValue<uint32_t, 2, 20> GPIO_ICR26;
#undef GPIO_ICR25
constexpr regs::RegValue<uint32_t, 2, 18> GPIO_ICR25;
#undef GPIO_ICR24
constexpr regs::RegValue<uint32_t, 2, 16> GPIO_ICR24;
#undef GPIO_ICR23
constexpr regs::RegValue<uint32_t, 2, 14> GPIO_ICR23;
#undef GPIO_ICR22
constexpr regs::RegValue<uint32_t, 2, 12> GPIO_ICR22;
#undef GPIO_ICR21
constexpr regs::RegValue<uint32_t, 2, 10> GPIO_ICR21;
#undef GPIO_ICR20
constexpr regs::RegValue<uint32_t, 2,  8> GPIO_ICR20;
#undef GPIO_ICR19
constexpr regs::RegValue<uint32_t, 2,  6> GPIO_ICR19;
#undef GPIO_ICR18
constexpr regs::RegValue<uint32_t, 2,  4> GPIO_ICR18;
#undef GPIO_ICR17
constexpr regs::RegValue<uint32_t, 2,  2> GPIO_ICR17;
#undef GPIO_ICR16
constexpr regs::RegValue<uint32_t, 2,  0> GPIO_ICR16;

// Individual bits
#undef GPIO_BIT_31
constexpr regs::RegValue<uint32_t, 1, 31> GPIO_BIT_31;
#undef GPIO_BIT_30
constexpr regs::RegValue<uint32_t, 1, 30> GPIO_BIT_30;
#undef GPIO_BIT_29
constexpr regs::RegValue<uint32_t, 1, 29> GPIO_BIT_29;
#undef GPIO_BIT_28
constexpr regs::RegValue<uint32_t, 1, 28> GPIO_BIT_28;
#undef GPIO_BIT_27
constexpr regs::RegValue<uint32_t, 1, 27> GPIO_BIT_27;
#undef GPIO_BIT_26
constexpr regs::RegValue<uint32_t, 1, 26> GPIO_BIT_26;
#undef GPIO_BIT_25
constexpr regs::RegValue<uint32_t, 1, 25> GPIO_BIT_25;
#undef GPIO_BIT_24
constexpr regs::RegValue<uint32_t, 1, 24> GPIO_BIT_24;
#undef GPIO_BIT_23
constexpr regs::RegValue<uint32_t, 1, 23> GPIO_BIT_23;
#undef GPIO_BIT_22
constexpr regs::RegValue<uint32_t, 1, 22> GPIO_BIT_22;
#undef GPIO_BIT_21
constexpr regs::RegValue<uint32_t, 1, 21> GPIO_BIT_21;
#undef GPIO_BIT_20
constexpr regs::RegValue<uint32_t, 1, 20> GPIO_BIT_20;
#undef GPIO_BIT_19
constexpr regs::RegValue<uint32_t, 1, 19> GPIO_BIT_19;
#undef GPIO_BIT_18
constexpr regs::RegValue<uint32_t, 1, 18> GPIO_BIT_18;
#undef GPIO_BIT_17
constexpr regs::RegValue<uint32_t, 1, 17> GPIO_BIT_17;
#undef GPIO_BIT_16
constexpr regs::RegValue<uint32_t, 1, 16> GPIO_BIT_16;
#undef GPIO_BIT_15
constexpr regs::RegValue<uint32_t, 1, 15> GPIO_BIT_15;
#undef GPIO_BIT_14
constexpr regs::RegValue<uint32_t, 1, 14> GPIO_BIT_14;
#undef GPIO_BIT_13
constexpr regs::RegValue<uint32_t, 1, 13> GPIO_BIT_13;
#undef GPIO_BIT_12
constexpr regs::RegValue<uint32_t, 1, 12> GPIO_BIT_12;
#undef GPIO_BIT_11
constexpr regs::RegValue<uint32_t, 1, 11> GPIO_BIT_11;
#undef GPIO_BIT_10
constexpr regs::RegValue<uint32_t, 1, 10> GPIO_BIT_10;
#undef GPIO_BIT_9
constexpr regs::RegValue<uint32_t, 1,  9> GPIO_BIT_9;
#undef GPIO_BIT_8
constexpr regs::RegValue<uint32_t, 1,  8> GPIO_BIT_8;
#undef GPIO_BIT_7
constexpr regs::RegValue<uint32_t, 1,  7> GPIO_BIT_7;
#undef GPIO_BIT_6
constexpr regs::RegValue<uint32_t, 1,  6> GPIO_BIT_6;
#undef GPIO_BIT_5
constexpr regs::RegValue<uint32_t, 1,  5> GPIO_BIT_5;
#undef GPIO_BIT_4
constexpr regs::RegValue<uint32_t, 1,  4> GPIO_BIT_4;
#undef GPIO_BIT_3
constexpr regs::RegValue<uint32_t, 1,  3> GPIO_BIT_3;
#undef GPIO_BIT_2
constexpr regs::RegValue<uint32_t, 1,  2> GPIO_BIT_2;
#undef GPIO_BIT_1
constexpr regs::RegValue<uint32_t, 1,  1> GPIO_BIT_1;
#undef GPIO_BIT_0
constexpr regs::RegValue<uint32_t, 1,  0> GPIO_BIT_0;

// Directions
constexpr uint32_t kGPIO_GDIR_INPUT  = 0;
constexpr uint32_t kGPIO_GDIR_OUTPUT = 1;

// ICR active condition values
constexpr uint32_t kGPIO_ICR_LOW     = 0;
constexpr uint32_t kGPIO_ICR_HIGH    = 1;
constexpr uint32_t kGPIO_ICR_RISING  = 2;
constexpr uint32_t kGPIO_ICR_FALLING = 3;

}  // namespace teensy4
}  // namespace hardware
}  // namespace qindesign
