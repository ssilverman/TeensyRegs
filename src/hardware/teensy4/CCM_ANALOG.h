// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// CCM_ANALOG.h defines all the CCM_ANALOG registers.
// This file is part of the TeensyRegs library.

#pragma once

#include <cstddef>
#include <cstdint>

#include "hardware/regs/regs.h"

namespace qindesign {
namespace hardware {
namespace teensy4 {

// CCM_ANALOG layout. Comments are from BSD-3-licensed NXP SDK.
//
// See:
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/periph/PERI_CCM_ANALOG.h
// * https://github.com/nxp-mcuxpresso/legacy-mcux-sdk/blob/main/devices/MIMXRT1062/MIMXRT1062.h
struct CCM_ANALOG_Layout {
  volatile uint32_t PLL_ARM;                           /**< Analog ARM PLL control Register, offset: 0x0 */
  volatile uint32_t PLL_ARM_SET;                       /**< Analog ARM PLL control Register, offset: 0x4 */
  volatile uint32_t PLL_ARM_CLR;                       /**< Analog ARM PLL control Register, offset: 0x8 */
  volatile uint32_t PLL_ARM_TOG;                       /**< Analog ARM PLL control Register, offset: 0xC */
  volatile uint32_t PLL_USB1;                          /**< Analog USB1 480MHz PLL Control Register, offset: 0x10 */
  volatile uint32_t PLL_USB1_SET;                      /**< Analog USB1 480MHz PLL Control Register, offset: 0x14 */
  volatile uint32_t PLL_USB1_CLR;                      /**< Analog USB1 480MHz PLL Control Register, offset: 0x18 */
  volatile uint32_t PLL_USB1_TOG;                      /**< Analog USB1 480MHz PLL Control Register, offset: 0x1C */
  volatile uint32_t PLL_USB2;                          /**< Analog USB2 480MHz PLL Control Register, offset: 0x20 */
  volatile uint32_t PLL_USB2_SET;                      /**< Analog USB2 480MHz PLL Control Register, offset: 0x24 */
  volatile uint32_t PLL_USB2_CLR;                      /**< Analog USB2 480MHz PLL Control Register, offset: 0x28 */
  volatile uint32_t PLL_USB2_TOG;                      /**< Analog USB2 480MHz PLL Control Register, offset: 0x2C */
  volatile uint32_t PLL_SYS;                           /**< Analog System PLL Control Register, offset: 0x30 */
  volatile uint32_t PLL_SYS_SET;                       /**< Analog System PLL Control Register, offset: 0x34 */
  volatile uint32_t PLL_SYS_CLR;                       /**< Analog System PLL Control Register, offset: 0x38 */
  volatile uint32_t PLL_SYS_TOG;                       /**< Analog System PLL Control Register, offset: 0x3C */
  volatile uint32_t PLL_SYS_SS;                        /**< 528MHz System PLL Spread Spectrum Register, offset: 0x40 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t PLL_SYS_NUM;                       /**< Numerator of 528MHz System PLL Fractional Loop Divider Register, offset: 0x50 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t PLL_SYS_DENOM;                     /**< Denominator of 528MHz System PLL Fractional Loop Divider Register, offset: 0x60 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t PLL_AUDIO;                         /**< Analog Audio PLL control Register, offset: 0x70 */
  volatile uint32_t PLL_AUDIO_SET;                     /**< Analog Audio PLL control Register, offset: 0x74 */
  volatile uint32_t PLL_AUDIO_CLR;                     /**< Analog Audio PLL control Register, offset: 0x78 */
  volatile uint32_t PLL_AUDIO_TOG;                     /**< Analog Audio PLL control Register, offset: 0x7C */
  volatile uint32_t PLL_AUDIO_NUM;                     /**< Numerator of Audio PLL Fractional Loop Divider Register, offset: 0x80 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t PLL_AUDIO_DENOM;                   /**< Denominator of Audio PLL Fractional Loop Divider Register, offset: 0x90 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t PLL_VIDEO;                         /**< Analog Video PLL control Register, offset: 0xA0 */
  volatile uint32_t PLL_VIDEO_SET;                     /**< Analog Video PLL control Register, offset: 0xA4 */
  volatile uint32_t PLL_VIDEO_CLR;                     /**< Analog Video PLL control Register, offset: 0xA8 */
  volatile uint32_t PLL_VIDEO_TOG;                     /**< Analog Video PLL control Register, offset: 0xAC */
  volatile uint32_t PLL_VIDEO_NUM;                     /**< Numerator of Video PLL Fractional Loop Divider Register, offset: 0xB0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t PLL_VIDEO_DENOM;                   /**< Denominator of Video PLL Fractional Loop Divider Register, offset: 0xC0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[7];
  volatile uint32_t PLL_ENET;                          /**< Analog ENET PLL Control Register, offset: 0xE0 */
  volatile uint32_t PLL_ENET_SET;                      /**< Analog ENET PLL Control Register, offset: 0xE4 */
  volatile uint32_t PLL_ENET_CLR;                      /**< Analog ENET PLL Control Register, offset: 0xE8 */
  volatile uint32_t PLL_ENET_TOG;                      /**< Analog ENET PLL Control Register, offset: 0xEC */
  volatile uint32_t PFD_480;                           /**< 480MHz Clock (PLL3) Phase Fractional Divider Control Register, offset: 0xF0 */
  volatile uint32_t PFD_480_SET;                       /**< 480MHz Clock (PLL3) Phase Fractional Divider Control Register, offset: 0xF4 */
  volatile uint32_t PFD_480_CLR;                       /**< 480MHz Clock (PLL3) Phase Fractional Divider Control Register, offset: 0xF8 */
  volatile uint32_t PFD_480_TOG;                       /**< 480MHz Clock (PLL3) Phase Fractional Divider Control Register, offset: 0xFC */
  volatile uint32_t PFD_528;                           /**< 528MHz Clock (PLL2) Phase Fractional Divider Control Register, offset: 0x100 */
  volatile uint32_t PFD_528_SET;                       /**< 528MHz Clock (PLL2) Phase Fractional Divider Control Register, offset: 0x104 */
  volatile uint32_t PFD_528_CLR;                       /**< 528MHz Clock (PLL2) Phase Fractional Divider Control Register, offset: 0x108 */
  volatile uint32_t PFD_528_TOG;                       /**< 528MHz Clock (PLL2) Phase Fractional Divider Control Register, offset: 0x10C */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[16];
  volatile uint32_t MISC0;                             /**< Miscellaneous Register 0, offset: 0x150 */
  volatile uint32_t MISC0_SET;                         /**< Miscellaneous Register 0, offset: 0x154 */
  volatile uint32_t MISC0_CLR;                         /**< Miscellaneous Register 0, offset: 0x158 */
  volatile uint32_t MISC0_TOG;                         /**< Miscellaneous Register 0, offset: 0x15C */
  volatile uint32_t MISC1;                             /**< Miscellaneous Register 1, offset: 0x160 */
  volatile uint32_t MISC1_SET;                         /**< Miscellaneous Register 1, offset: 0x164 */
  volatile uint32_t MISC1_CLR;                         /**< Miscellaneous Register 1, offset: 0x168 */
  volatile uint32_t MISC1_TOG;                         /**< Miscellaneous Register 1, offset: 0x16C */
  volatile uint32_t MISC2;                             /**< Miscellaneous Register 2, offset: 0x170 */
  volatile uint32_t MISC2_SET;                         /**< Miscellaneous Register 2, offset: 0x174 */
  volatile uint32_t MISC2_CLR;                         /**< Miscellaneous Register 2, offset: 0x178 */
  volatile uint32_t MISC2_TOG;                         /**< Miscellaneous Register 2, offset: 0x17C */
};

constexpr size_t    kCCM_ANALOG_size = 0x180;
constexpr uintptr_t kCCM_ANALOG_base = 0x400D8000;

constexpr regs::RegGroup<CCM_ANALOG_Layout, kCCM_ANALOG_size, kCCM_ANALOG_base>
    CCM_ANALOG;

template <auto Member, size_t Bits, unsigned int Shift,
          bool DirectAssign = false>
using CCM_ANALOG_Reg = regs::Reg32<kCCM_ANALOG_base, CCM_ANALOG_Layout, Member,
                                   0, Bits, Shift, DirectAssign>;

// Undefine anything defined by Teensyduino's imxrt.h

//  Analog ARM PLL control Register
#undef CCM_ANALOG_PLL_ARM_LOCK
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ARM, 1, 31> CCM_ANALOG_PLL_ARM_LOCK;
#undef CCM_ANALOG_PLL_ARM_PLL_SEL
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ARM, 1, 19> CCM_ANALOG_PLL_ARM_PLL_SEL;
#undef CCM_ANALOG_PLL_ARM_BYPASS
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ARM, 1, 16> CCM_ANALOG_PLL_ARM_BYPASS;
#undef CCM_ANALOG_PLL_ARM_BYPASS_CLK_SRC
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ARM, 2, 14> CCM_ANALOG_PLL_ARM_BYPASS_CLK_SRC;
    // 0b00..Select the 24MHz oscillator as source.
    // 0b01..Select the CLK1_N / CLK1_P as source.
    // 0b10..Reserved1
    // 0b11..Reserved2
#undef CCM_ANALOG_PLL_ARM_ENABLE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ARM, 1, 13> CCM_ANALOG_PLL_ARM_ENABLE;
#undef CCM_ANALOG_PLL_ARM_POWERDOWN
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ARM, 1, 12> CCM_ANALOG_PLL_ARM_POWERDOWN;
#undef CCM_ANALOG_PLL_ARM_DIV_SELECT
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ARM, 7,  0> CCM_ANALOG_PLL_ARM_DIV_SELECT;

//  Analog ARM PLL control Register
#undef CCM_ANALOG_PLL_ARM_SET_LOCK
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ARM_SET, 1, 31, true> CCM_ANALOG_PLL_ARM_SET_LOCK;
#undef CCM_ANALOG_PLL_ARM_SET_PLL_SEL
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ARM_SET, 1, 19, true> CCM_ANALOG_PLL_ARM_SET_PLL_SEL;
#undef CCM_ANALOG_PLL_ARM_SET_BYPASS
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ARM_SET, 1, 16, true> CCM_ANALOG_PLL_ARM_SET_BYPASS;
#undef CCM_ANALOG_PLL_ARM_SET_BYPASS_CLK_SRC
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ARM_SET, 2, 14, true> CCM_ANALOG_PLL_ARM_SET_BYPASS_CLK_SRC;
#undef CCM_ANALOG_PLL_ARM_SET_ENABLE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ARM_SET, 1, 13, true> CCM_ANALOG_PLL_ARM_SET_ENABLE;
#undef CCM_ANALOG_PLL_ARM_SET_POWERDOWN
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ARM_SET, 1, 12, true> CCM_ANALOG_PLL_ARM_SET_POWERDOWN;
#undef CCM_ANALOG_PLL_ARM_SET_DIV_SELECT
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ARM_SET, 7,  0, true> CCM_ANALOG_PLL_ARM_SET_DIV_SELECT;

//  Analog ARM PLL control Register
#undef CCM_ANALOG_PLL_ARM_CLR_LOCK
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ARM_CLR, 1, 31, true> CCM_ANALOG_PLL_ARM_CLR_LOCK;
#undef CCM_ANALOG_PLL_ARM_CLR_PLL_SEL
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ARM_CLR, 1, 19, true> CCM_ANALOG_PLL_ARM_CLR_PLL_SEL;
#undef CCM_ANALOG_PLL_ARM_CLR_BYPASS
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ARM_CLR, 1, 16, true> CCM_ANALOG_PLL_ARM_CLR_BYPASS;
#undef CCM_ANALOG_PLL_ARM_CLR_BYPASS_CLK_SRC
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ARM_CLR, 2, 14, true> CCM_ANALOG_PLL_ARM_CLR_BYPASS_CLK_SRC;
#undef CCM_ANALOG_PLL_ARM_CLR_ENABLE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ARM_CLR, 1, 13, true> CCM_ANALOG_PLL_ARM_CLR_ENABLE;
#undef CCM_ANALOG_PLL_ARM_CLR_POWERDOWN
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ARM_CLR, 1, 12, true> CCM_ANALOG_PLL_ARM_CLR_POWERDOWN;
#undef CCM_ANALOG_PLL_ARM_CLR_DIV_SELECT
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ARM_CLR, 7,  0, true> CCM_ANALOG_PLL_ARM_CLR_DIV_SELECT;

//  Analog ARM PLL control Register
#undef CCM_ANALOG_PLL_ARM_TOG_LOCK
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ARM_TOG, 1, 31, true> CCM_ANALOG_PLL_ARM_TOG_LOCK;
#undef CCM_ANALOG_PLL_ARM_TOG_PLL_SEL
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ARM_TOG, 1, 19, true> CCM_ANALOG_PLL_ARM_TOG_PLL_SEL;
#undef CCM_ANALOG_PLL_ARM_TOG_BYPASS
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ARM_TOG, 1, 16, true> CCM_ANALOG_PLL_ARM_TOG_BYPASS;
#undef CCM_ANALOG_PLL_ARM_TOG_BYPASS_CLK_SRC
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ARM_TOG, 2, 14, true> CCM_ANALOG_PLL_ARM_TOG_BYPASS_CLK_SRC;
#undef CCM_ANALOG_PLL_ARM_TOG_ENABLE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ARM_TOG, 1, 13, true> CCM_ANALOG_PLL_ARM_TOG_ENABLE;
#undef CCM_ANALOG_PLL_ARM_TOG_POWERDOWN
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ARM_TOG, 1, 12, true> CCM_ANALOG_PLL_ARM_TOG_POWERDOWN;
#undef CCM_ANALOG_PLL_ARM_TOG_DIV_SELECT
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ARM_TOG, 7,  0, true> CCM_ANALOG_PLL_ARM_TOG_DIV_SELECT;

// Analog USB1 480MHz PLL Control Register
#undef CCM_ANALOG_PLL_USB1_LOCK
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB1, 1, 31> CCM_ANALOG_PLL_USB1_LOCK;
#undef CCM_ANALOG_PLL_USB1_BYPASS
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB1, 1, 16> CCM_ANALOG_PLL_USB1_BYPASS;
#undef CCM_ANALOG_PLL_USB1_BYPASS_CLK_SRC
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB1, 2, 14> CCM_ANALOG_PLL_USB1_BYPASS_CLK_SRC;
    // 0b00..Select the 24MHz oscillator as source.
    // 0b01..Select the CLK1_N / CLK1_P as source.
#undef CCM_ANALOG_PLL_USB1_ENABLE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB1, 1, 13> CCM_ANALOG_PLL_USB1_ENABLE;
#undef CCM_ANALOG_PLL_USB1_POWER
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB1, 1, 12> CCM_ANALOG_PLL_USB1_POWER;
#undef CCM_ANALOG_PLL_USB1_EN_USB_CLKS
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB1, 1,  6> CCM_ANALOG_PLL_USB1_EN_USB_CLKS;
    // 0b0..PLL outputs for USBPHYn off.
    // 0b1..PLL outputs for USBPHYn on.
#undef CCM_ANALOG_PLL_USB1_DIV_SELECT
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB1, 1,  1> CCM_ANALOG_PLL_USB1_DIV_SELECT;

// Analog USB1 480MHz PLL Control Register
#undef CCM_ANALOG_PLL_USB1_SET_LOCK
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB1_SET, 1, 31, true> CCM_ANALOG_PLL_USB1_SET_LOCK;
#undef CCM_ANALOG_PLL_USB1_SET_BYPASS
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB1_SET, 1, 16, true> CCM_ANALOG_PLL_USB1_SET_BYPASS;
#undef CCM_ANALOG_PLL_USB1_SET_BYPASS_CLK_SRC
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB1_SET, 2, 14, true> CCM_ANALOG_PLL_USB1_SET_BYPASS_CLK_SRC;
#undef CCM_ANALOG_PLL_USB1_SET_ENABLE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB1_SET, 1, 13, true> CCM_ANALOG_PLL_USB1_SET_ENABLE;
#undef CCM_ANALOG_PLL_USB1_SET_POWER
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB1_SET, 1, 12, true> CCM_ANALOG_PLL_USB1_SET_POWER;
#undef CCM_ANALOG_PLL_USB1_SET_EN_USB_CLKS
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB1_SET, 1,  6, true> CCM_ANALOG_PLL_USB1_SET_EN_USB_CLKS;
#undef CCM_ANALOG_PLL_USB1_SET_DIV_SELECT
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB1_SET, 1,  1, true> CCM_ANALOG_PLL_USB1_SET_DIV_SELECT;

// Analog USB1 480MHz PLL Control Register
#undef CCM_ANALOG_PLL_USB1_CLR_LOCK
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB1_CLR, 1, 31, true> CCM_ANALOG_PLL_USB1_CLR_LOCK;
#undef CCM_ANALOG_PLL_USB1_CLR_BYPASS
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB1_CLR, 1, 16, true> CCM_ANALOG_PLL_USB1_CLR_BYPASS;
#undef CCM_ANALOG_PLL_USB1_CLR_BYPASS_CLK_SRC
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB1_CLR, 2, 14, true> CCM_ANALOG_PLL_USB1_CLR_BYPASS_CLK_SRC;
#undef CCM_ANALOG_PLL_USB1_CLR_ENABLE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB1_CLR, 1, 13, true> CCM_ANALOG_PLL_USB1_CLR_ENABLE;
#undef CCM_ANALOG_PLL_USB1_CLR_POWER
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB1_CLR, 1, 12, true> CCM_ANALOG_PLL_USB1_CLR_POWER;
#undef CCM_ANALOG_PLL_USB1_CLR_EN_USB_CLKS
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB1_CLR, 1,  6, true> CCM_ANALOG_PLL_USB1_CLR_EN_USB_CLKS;
#undef CCM_ANALOG_PLL_USB1_CLR_DIV_SELECT
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB1_CLR, 1,  1, true> CCM_ANALOG_PLL_USB1_CLR_DIV_SELECT;

// Analog USB1 480MHz PLL Control Register
#undef CCM_ANALOG_PLL_USB1_TOG_LOCK
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB1_TOG, 1, 31, true> CCM_ANALOG_PLL_USB1_TOG_LOCK;
#undef CCM_ANALOG_PLL_USB1_TOG_BYPASS
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB1_TOG, 1, 16, true> CCM_ANALOG_PLL_USB1_TOG_BYPASS;
#undef CCM_ANALOG_PLL_USB1_TOG_BYPASS_CLK_SRC
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB1_TOG, 2, 14, true> CCM_ANALOG_PLL_USB1_TOG_BYPASS_CLK_SRC;
#undef CCM_ANALOG_PLL_USB1_TOG_ENABLE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB1_TOG, 1, 13, true> CCM_ANALOG_PLL_USB1_TOG_ENABLE;
#undef CCM_ANALOG_PLL_USB1_TOG_POWER
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB1_TOG, 1, 12, true> CCM_ANALOG_PLL_USB1_TOG_POWER;
#undef CCM_ANALOG_PLL_USB1_TOG_EN_USB_CLKS
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB1_TOG, 1,  6, true> CCM_ANALOG_PLL_USB1_TOG_EN_USB_CLKS;
#undef CCM_ANALOG_PLL_USB1_TOG_DIV_SELECT
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB1_TOG, 1,  1, true> CCM_ANALOG_PLL_USB1_TOG_DIV_SELECT;

// Analog USB2 480MHz PLL Control Register
#undef CCM_ANALOG_PLL_USB2_LOCK
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB2, 1, 31> CCM_ANALOG_PLL_USB2_LOCK;
#undef CCM_ANALOG_PLL_USB2_BYPASS
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB2, 1, 16> CCM_ANALOG_PLL_USB2_BYPASS;
#undef CCM_ANALOG_PLL_USB2_BYPASS_CLK_SRC
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB2, 2, 14> CCM_ANALOG_PLL_USB2_BYPASS_CLK_SRC;
    // 0b00..Select the 24MHz oscillator as source.
    // 0b01..Select the CLK1_N / CLK1_P as source.
    // 0b10..Reserved1
    // 0b11..Reserved2
#undef CCM_ANALOG_PLL_USB2_ENABLE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB2, 1, 13> CCM_ANALOG_PLL_USB2_ENABLE;
#undef CCM_ANALOG_PLL_USB2_POWER
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB2, 1, 12> CCM_ANALOG_PLL_USB2_POWER;
#undef CCM_ANALOG_PLL_USB2_EN_USB_CLKS
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB2, 1,  6> CCM_ANALOG_PLL_USB2_EN_USB_CLKS;
#undef CCM_ANALOG_PLL_USB2_DIV_SELECT
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB2, 1,  1> CCM_ANALOG_PLL_USB2_DIV_SELECT;

// Analog USB2 480MHz PLL Control Register
#undef CCM_ANALOG_PLL_USB2_SET_LOCK
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB2_SET, 1, 31, true> CCM_ANALOG_PLL_USB2_SET_LOCK;
#undef CCM_ANALOG_PLL_USB2_SET_BYPASS
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB2_SET, 1, 16, true> CCM_ANALOG_PLL_USB2_SET_BYPASS;
#undef CCM_ANALOG_PLL_USB2_SET_BYPASS_CLK_SRC
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB2_SET, 2, 14, true> CCM_ANALOG_PLL_USB2_SET_BYPASS_CLK_SRC;
#undef CCM_ANALOG_PLL_USB2_SET_ENABLE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB2_SET, 1, 13, true> CCM_ANALOG_PLL_USB2_SET_ENABLE;
#undef CCM_ANALOG_PLL_USB2_SET_POWER
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB2_SET, 1, 12, true> CCM_ANALOG_PLL_USB2_SET_POWER;
#undef CCM_ANALOG_PLL_USB2_SET_EN_USB_CLKS
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB2_SET, 1,  6, true> CCM_ANALOG_PLL_USB2_SET_EN_USB_CLKS;
#undef CCM_ANALOG_PLL_USB2_SET_DIV_SELECT
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB2_SET, 1,  1, true> CCM_ANALOG_PLL_USB2_SET_DIV_SELECT;

// Analog USB2 480MHz PLL Control Register
#undef CCM_ANALOG_PLL_USB2_CLR_LOCK
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB2_CLR, 1, 31, true> CCM_ANALOG_PLL_USB2_CLR_LOCK;
#undef CCM_ANALOG_PLL_USB2_CLR_BYPASS
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB2_CLR, 1, 16, true> CCM_ANALOG_PLL_USB2_CLR_BYPASS;
#undef CCM_ANALOG_PLL_USB2_CLR_BYPASS_CLK_SRC
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB2_CLR, 2, 14, true> CCM_ANALOG_PLL_USB2_CLR_BYPASS_CLK_SRC;
#undef CCM_ANALOG_PLL_USB2_CLR_ENABLE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB2_CLR, 1, 13, true> CCM_ANALOG_PLL_USB2_CLR_ENABLE;
#undef CCM_ANALOG_PLL_USB2_CLR_POWER
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB2_CLR, 1, 12, true> CCM_ANALOG_PLL_USB2_CLR_POWER;
#undef CCM_ANALOG_PLL_USB2_CLR_EN_USB_CLKS
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB2_CLR, 1,  6, true> CCM_ANALOG_PLL_USB2_CLR_EN_USB_CLKS;
#undef CCM_ANALOG_PLL_USB2_CLR_DIV_SELECT
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB2_CLR, 1,  1, true> CCM_ANALOG_PLL_USB2_CLR_DIV_SELECT;

// Analog USB2 480MHz PLL Control Register
#undef CCM_ANALOG_PLL_USB2_TOG_LOCK
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB2_TOG, 1, 31, true> CCM_ANALOG_PLL_USB2_TOG_LOCK;
#undef CCM_ANALOG_PLL_USB2_TOG_BYPASS
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB2_TOG, 1, 16, true> CCM_ANALOG_PLL_USB2_TOG_BYPASS;
#undef CCM_ANALOG_PLL_USB2_TOG_BYPASS_CLK_SRC
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB2_TOG, 2, 14, true> CCM_ANALOG_PLL_USB2_TOG_BYPASS_CLK_SRC;
#undef CCM_ANALOG_PLL_USB2_TOG_ENABLE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB2_TOG, 1, 13, true> CCM_ANALOG_PLL_USB2_TOG_ENABLE;
#undef CCM_ANALOG_PLL_USB2_TOG_POWER
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB2_TOG, 1, 12, true> CCM_ANALOG_PLL_USB2_TOG_POWER;
#undef CCM_ANALOG_PLL_USB2_TOG_EN_USB_CLKS
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB2_TOG, 1,  6, true> CCM_ANALOG_PLL_USB2_TOG_EN_USB_CLKS;
#undef CCM_ANALOG_PLL_USB2_TOG_DIV_SELECT
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_USB2_TOG, 1,  1, true> CCM_ANALOG_PLL_USB2_TOG_DIV_SELECT;

// Analog System PLL Control Register
#undef CCM_ANALOG_PLL_SYS_LOCK
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_SYS, 1, 31> CCM_ANALOG_PLL_SYS_LOCK;
#undef CCM_ANALOG_PLL_SYS_BYPASS
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_SYS, 1, 16> CCM_ANALOG_PLL_SYS_BYPASS;
#undef CCM_ANALOG_PLL_SYS_BYPASS_CLK_SRC
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_SYS, 2, 14> CCM_ANALOG_PLL_SYS_BYPASS_CLK_SRC;
    // 0b00..Select the 24MHz oscillator as source.
    // 0b01..Select the CLK1_N / CLK1_P as source.
#undef CCM_ANALOG_PLL_SYS_ENABLE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_SYS, 1, 13> CCM_ANALOG_PLL_SYS_ENABLE;
#undef CCM_ANALOG_PLL_SYS_POWERDOWN
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_SYS, 1, 12> CCM_ANALOG_PLL_SYS_POWERDOWN;
#undef CCM_ANALOG_PLL_SYS_DIV_SELECT_MASK
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_SYS, 1,  0> CCM_ANALOG_PLL_SYS_DIV_SELECT_MASK;

// Analog System PLL Control Register
#undef CCM_ANALOG_PLL_SYS_SET_LOCK
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_SYS_SET, 1, 31, true> CCM_ANALOG_PLL_SYS_SET_LOCK;
#undef CCM_ANALOG_PLL_SYS_SET_BYPASS
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_SYS_SET, 1, 16, true> CCM_ANALOG_PLL_SYS_SET_BYPASS;
#undef CCM_ANALOG_PLL_SYS_SET_BYPASS_CLK_SRC
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_SYS_SET, 2, 14, true> CCM_ANALOG_PLL_SYS_SET_BYPASS_CLK_SRC;
#undef CCM_ANALOG_PLL_SYS_SET_ENABLE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_SYS_SET, 1, 13, true> CCM_ANALOG_PLL_SYS_SET_ENABLE;
#undef CCM_ANALOG_PLL_SYS_SET_POWERDOWN
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_SYS_SET, 1, 12, true> CCM_ANALOG_PLL_SYS_SET_POWERDOWN;
#undef CCM_ANALOG_PLL_SYS_SET_DIV_SELECT_MASK
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_SYS_SET, 1,  0, true> CCM_ANALOG_PLL_SYS_SET_DIV_SELECT_MASK;

// Analog System PLL Control Register
#undef CCM_ANALOG_PLL_SYS_CLR_LOCK
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_SYS_CLR, 1, 31, true> CCM_ANALOG_PLL_SYS_CLR_LOCK;
#undef CCM_ANALOG_PLL_SYS_CLR_BYPASS
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_SYS_CLR, 1, 16, true> CCM_ANALOG_PLL_SYS_CLR_BYPASS;
#undef CCM_ANALOG_PLL_SYS_CLR_BYPASS_CLK_SRC
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_SYS_CLR, 2, 14, true> CCM_ANALOG_PLL_SYS_CLR_BYPASS_CLK_SRC;
#undef CCM_ANALOG_PLL_SYS_CLR_ENABLE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_SYS_CLR, 1, 13, true> CCM_ANALOG_PLL_SYS_CLR_ENABLE;
#undef CCM_ANALOG_PLL_SYS_CLR_POWERDOWN
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_SYS_CLR, 1, 12, true> CCM_ANALOG_PLL_SYS_CLR_POWERDOWN;
#undef CCM_ANALOG_PLL_SYS_CLR_DIV_SELECT_MASK
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_SYS_CLR, 1,  0, true> CCM_ANALOG_PLL_SYS_CLR_DIV_SELECT_MASK;

// Analog System PLL Control Register
#undef CCM_ANALOG_PLL_SYS_TOG_LOCK
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_SYS_TOG, 1, 31, true> CCM_ANALOG_PLL_SYS_TOG_LOCK;
#undef CCM_ANALOG_PLL_SYS_TOG_BYPASS
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_SYS_TOG, 1, 16, true> CCM_ANALOG_PLL_SYS_TOG_BYPASS;
#undef CCM_ANALOG_PLL_SYS_TOG_BYPASS_CLK_SRC
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_SYS_TOG, 2, 14, true> CCM_ANALOG_PLL_SYS_TOG_BYPASS_CLK_SRC;
#undef CCM_ANALOG_PLL_SYS_TOG_ENABLE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_SYS_TOG, 1, 13, true> CCM_ANALOG_PLL_SYS_TOG_ENABLE;
#undef CCM_ANALOG_PLL_SYS_TOG_POWERDOWN
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_SYS_TOG, 1, 12, true> CCM_ANALOG_PLL_SYS_TOG_POWERDOWN;
#undef CCM_ANALOG_PLL_SYS_TOG_DIV_SELECT_MASK
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_SYS_TOG, 1,  0, true> CCM_ANALOG_PLL_SYS_TOG_DIV_SELECT_MASK;

// 528MHz System PLL Spread Spectrum Register
#undef CCM_ANALOG_PLL_SYS_SS_STOP
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_SYS_SS, 16, 16> CCM_ANALOG_PLL_SYS_SS_STOP;
#undef CCM_ANALOG_PLL_SYS_SS_ENABLE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_SYS_SS,  1, 15> CCM_ANALOG_PLL_SYS_SS_ENABLE;  // Enable bit
    // 0b0..Spread spectrum modulation disabled
    // 0b1..Spread spectrum modulation enabled
#undef CCM_ANALOG_PLL_SYS_SS_STEP
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_SYS_SS, 15,  0> CCM_ANALOG_PLL_SYS_SS_STEP;

// Numerator of 528MHz System PLL Fractional Loop Divider Register
#undef CCM_ANALOG_PLL_SYS_NUM_A
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_SYS_NUM, 30, 0> CCM_ANALOG_PLL_SYS_NUM_A;

// Denominator of 528MHz System PLL Fractional Loop Divider Register
#undef CCM_ANALOG_PLL_SYS_DENOM_B
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_SYS_DENOM, 30, 0> CCM_ANALOG_PLL_SYS_DENOM_B;

// Analog Audio PLL control Register
#undef CCM_ANALOG_PLL_AUDIO_LOCK
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_AUDIO, 1, 31> CCM_ANALOG_PLL_AUDIO_LOCK;
#undef CCM_ANALOG_PLL_AUDIO_POST_DIV_SELECT
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_AUDIO, 2, 19> CCM_ANALOG_PLL_AUDIO_POST_DIV_SELECT;
    // 0b00..Divide by 4.
    // 0b01..Divide by 2.
    // 0b10..Divide by 1.
    // 0b11..Reserved
#undef CCM_ANALOG_PLL_AUDIO_BYPASS
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_AUDIO, 1, 16> CCM_ANALOG_PLL_AUDIO_BYPASS;
#undef CCM_ANALOG_PLL_AUDIO_BYPASS_CLK_SRC
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_AUDIO, 2, 14> CCM_ANALOG_PLL_AUDIO_BYPASS_CLK_SRC;
    // 0b00..Select the 24MHz oscillator as source.
    // 0b01..Select the CLK1_N / CLK1_P as source.
    // 0b10..Reserved1
    // 0b11..Reserved2
#undef CCM_ANALOG_PLL_AUDIO_ENABLE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_AUDIO, 1, 13> CCM_ANALOG_PLL_AUDIO_ENABLE;
#undef CCM_ANALOG_PLL_AUDIO_POWERDOWN
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_AUDIO, 1, 12> CCM_ANALOG_PLL_AUDIO_POWERDOWN;
#undef CCM_ANALOG_PLL_AUDIO_DIV_SELECT
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_AUDIO, 7,  0> CCM_ANALOG_PLL_AUDIO_DIV_SELECT;

// Analog Audio PLL control Register
#undef CCM_ANALOG_PLL_AUDIO_SET_LOCK
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_AUDIO_SET, 1, 31, true> CCM_ANALOG_PLL_AUDIO_SET_LOCK;
#undef CCM_ANALOG_PLL_AUDIO_SET_POST_DIV_SELECT
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_AUDIO_SET, 2, 19, true> CCM_ANALOG_PLL_AUDIO_SET_POST_DIV_SELECT;
#undef CCM_ANALOG_PLL_AUDIO_SET_BYPASS
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_AUDIO_SET, 1, 16, true> CCM_ANALOG_PLL_AUDIO_SET_BYPASS;
#undef CCM_ANALOG_PLL_AUDIO_SET_BYPASS_CLK_SRC
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_AUDIO_SET, 2, 14, true> CCM_ANALOG_PLL_AUDIO_SET_BYPASS_CLK_SRC;
#undef CCM_ANALOG_PLL_AUDIO_SET_ENABLE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_AUDIO_SET, 1, 13, true> CCM_ANALOG_PLL_AUDIO_SET_ENABLE;
#undef CCM_ANALOG_PLL_AUDIO_SET_POWERDOWN
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_AUDIO_SET, 1, 12, true> CCM_ANALOG_PLL_AUDIO_SET_POWERDOWN;
#undef CCM_ANALOG_PLL_AUDIO_SET_DIV_SELECT
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_AUDIO_SET, 7,  0, true> CCM_ANALOG_PLL_AUDIO_SET_DIV_SELECT;

// Analog Audio PLL control Register
#undef CCM_ANALOG_PLL_AUDIO_CLR_LOCK
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_AUDIO_CLR, 1, 31, true> CCM_ANALOG_PLL_AUDIO_CLR_LOCK;
#undef CCM_ANALOG_PLL_AUDIO_CLR_POST_DIV_SELECT
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_AUDIO_CLR, 2, 19, true> CCM_ANALOG_PLL_AUDIO_CLR_POST_DIV_SELECT;
#undef CCM_ANALOG_PLL_AUDIO_CLR_BYPASS
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_AUDIO_CLR, 1, 16, true> CCM_ANALOG_PLL_AUDIO_CLR_BYPASS;
#undef CCM_ANALOG_PLL_AUDIO_CLR_BYPASS_CLK_SRC
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_AUDIO_CLR, 2, 14, true> CCM_ANALOG_PLL_AUDIO_CLR_BYPASS_CLK_SRC;
#undef CCM_ANALOG_PLL_AUDIO_CLR_ENABLE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_AUDIO_CLR, 1, 13, true> CCM_ANALOG_PLL_AUDIO_CLR_ENABLE;
#undef CCM_ANALOG_PLL_AUDIO_CLR_POWERDOWN
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_AUDIO_CLR, 1, 12, true> CCM_ANALOG_PLL_AUDIO_CLR_POWERDOWN;
#undef CCM_ANALOG_PLL_AUDIO_CLR_DIV_SELECT
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_AUDIO_CLR, 7,  0, true> CCM_ANALOG_PLL_AUDIO_CLR_DIV_SELECT;

// Analog Audio PLL control Register
#undef CCM_ANALOG_PLL_AUDIO_TOG_LOCK
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_AUDIO_TOG, 1, 31, true> CCM_ANALOG_PLL_AUDIO_TOG_LOCK;
#undef CCM_ANALOG_PLL_AUDIO_TOG_POST_DIV_SELECT
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_AUDIO_TOG, 2, 19, true> CCM_ANALOG_PLL_AUDIO_TOG_POST_DIV_SELECT;
#undef CCM_ANALOG_PLL_AUDIO_TOG_BYPASS
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_AUDIO_TOG, 1, 16, true> CCM_ANALOG_PLL_AUDIO_TOG_BYPASS;
#undef CCM_ANALOG_PLL_AUDIO_TOG_BYPASS_CLK_SRC
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_AUDIO_TOG, 2, 14, true> CCM_ANALOG_PLL_AUDIO_TOG_BYPASS_CLK_SRC;
#undef CCM_ANALOG_PLL_AUDIO_TOG_ENABLE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_AUDIO_TOG, 1, 13, true> CCM_ANALOG_PLL_AUDIO_TOG_ENABLE;
#undef CCM_ANALOG_PLL_AUDIO_TOG_POWERDOWN
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_AUDIO_TOG, 1, 12, true> CCM_ANALOG_PLL_AUDIO_TOG_POWERDOWN;
#undef CCM_ANALOG_PLL_AUDIO_TOG_DIV_SELECT
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_AUDIO_TOG, 7,  0, true> CCM_ANALOG_PLL_AUDIO_TOG_DIV_SELECT;

// Numerator of Audio PLL Fractional Loop Divider Register
#undef CCM_ANALOG_PLL_AUDIO_NUM_A
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_AUDIO_NUM, 30, 0> CCM_ANALOG_PLL_AUDIO_NUM_A;

// Denominator of Audio PLL Fractional Loop Divider Register
#undef CCM_ANALOG_PLL_AUDIO_DENOM_B
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_AUDIO_DENOM, 30, 0> CCM_ANALOG_PLL_AUDIO_DENOM_B;

// Analog Video PLL control Register
#undef CCM_ANALOG_PLL_VIDEO_LOCK
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_VIDEO, 1, 31> CCM_ANALOG_PLL_VIDEO_LOCK;
#undef CCM_ANALOG_PLL_VIDEO_POST_DIV_SELECT
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_VIDEO, 2, 19> CCM_ANALOG_PLL_VIDEO_POST_DIV_SELECT;
    // 0b00..Divide by 4.
    // 0b01..Divide by 2.
    // 0b10..Divide by 1.
    // 0b11..Reserved
#undef CCM_ANALOG_PLL_VIDEO_BYPASS
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_VIDEO, 1, 16> CCM_ANALOG_PLL_VIDEO_BYPASS;
#undef CCM_ANALOG_PLL_VIDEO_BYPASS_CLK_SRC
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_VIDEO, 2, 14> CCM_ANALOG_PLL_VIDEO_BYPASS_CLK_SRC;
    // 0b00..Select the 24MHz oscillator as source.
    // 0b01..Select the CLK1_N / CLK1_P as source.
    // 0b10..Reserved1
    // 0b11..Reserved2
#undef CCM_ANALOG_PLL_VIDEO_ENABLE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_VIDEO, 1, 13> CCM_ANALOG_PLL_VIDEO_ENABLE;
#undef CCM_ANALOG_PLL_VIDEO_POWERDOWN
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_VIDEO, 1, 12> CCM_ANALOG_PLL_VIDEO_POWERDOWN;
#undef CCM_ANALOG_PLL_VIDEO_DIV_SELECT
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_VIDEO, 7,  0> CCM_ANALOG_PLL_VIDEO_DIV_SELECT;

// Analog Video PLL control Register
#undef CCM_ANALOG_PLL_VIDEO_SET_LOCK
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_VIDEO_SET, 1, 31, true> CCM_ANALOG_PLL_VIDEO_SET_LOCK;
#undef CCM_ANALOG_PLL_VIDEO_SET_POST_DIV_SELECT
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_VIDEO_SET, 2, 19, true> CCM_ANALOG_PLL_VIDEO_SET_POST_DIV_SELECT;
#undef CCM_ANALOG_PLL_VIDEO_SET_BYPASS
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_VIDEO_SET, 1, 16, true> CCM_ANALOG_PLL_VIDEO_SET_BYPASS;
#undef CCM_ANALOG_PLL_VIDEO_SET_BYPASS_CLK_SRC
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_VIDEO_SET, 2, 14, true> CCM_ANALOG_PLL_VIDEO_SET_BYPASS_CLK_SRC;
#undef CCM_ANALOG_PLL_VIDEO_SET_ENABLE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_VIDEO_SET, 1, 13, true> CCM_ANALOG_PLL_VIDEO_SET_ENABLE;
#undef CCM_ANALOG_PLL_VIDEO_SET_POWERDOWN
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_VIDEO_SET, 1, 12, true> CCM_ANALOG_PLL_VIDEO_SET_POWERDOWN;
#undef CCM_ANALOG_PLL_VIDEO_SET_DIV_SELECT
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_VIDEO_SET, 7,  0, true> CCM_ANALOG_PLL_VIDEO_SET_DIV_SELECT;

// Analog Video PLL control Register
#undef CCM_ANALOG_PLL_VIDEO_CLR_LOCK
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_VIDEO_CLR, 1, 31, true> CCM_ANALOG_PLL_VIDEO_CLR_LOCK;
#undef CCM_ANALOG_PLL_VIDEO_CLR_POST_DIV_SELECT
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_VIDEO_CLR, 2, 19, true> CCM_ANALOG_PLL_VIDEO_CLR_POST_DIV_SELECT;
#undef CCM_ANALOG_PLL_VIDEO_CLR_BYPASS
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_VIDEO_CLR, 1, 16, true> CCM_ANALOG_PLL_VIDEO_CLR_BYPASS;
#undef CCM_ANALOG_PLL_VIDEO_CLR_BYPASS_CLK_SRC
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_VIDEO_CLR, 2, 14, true> CCM_ANALOG_PLL_VIDEO_CLR_BYPASS_CLK_SRC;
#undef CCM_ANALOG_PLL_VIDEO_CLR_ENABLE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_VIDEO_CLR, 1, 13, true> CCM_ANALOG_PLL_VIDEO_CLR_ENABLE;
#undef CCM_ANALOG_PLL_VIDEO_CLR_POWERDOWN
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_VIDEO_CLR, 1, 12, true> CCM_ANALOG_PLL_VIDEO_CLR_POWERDOWN;
#undef CCM_ANALOG_PLL_VIDEO_CLR_DIV_SELECT
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_VIDEO_CLR, 7,  0, true> CCM_ANALOG_PLL_VIDEO_CLR_DIV_SELECT;

// Analog Video PLL control Register
#undef CCM_ANALOG_PLL_VIDEO_TOG_LOCK
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_VIDEO_TOG, 1, 31, true> CCM_ANALOG_PLL_VIDEO_TOG_LOCK;
#undef CCM_ANALOG_PLL_VIDEO_TOG_POST_DIV_SELECT
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_VIDEO_TOG, 2, 19, true> CCM_ANALOG_PLL_VIDEO_TOG_POST_DIV_SELECT;
#undef CCM_ANALOG_PLL_VIDEO_TOG_BYPASS
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_VIDEO_TOG, 1, 16, true> CCM_ANALOG_PLL_VIDEO_TOG_BYPASS;
#undef CCM_ANALOG_PLL_VIDEO_TOG_BYPASS_CLK_SRC
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_VIDEO_TOG, 2, 14, true> CCM_ANALOG_PLL_VIDEO_TOG_BYPASS_CLK_SRC;
#undef CCM_ANALOG_PLL_VIDEO_TOG_ENABLE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_VIDEO_TOG, 1, 13, true> CCM_ANALOG_PLL_VIDEO_TOG_ENABLE;
#undef CCM_ANALOG_PLL_VIDEO_TOG_POWERDOWN
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_VIDEO_TOG, 1, 12, true> CCM_ANALOG_PLL_VIDEO_TOG_POWERDOWN;
#undef CCM_ANALOG_PLL_VIDEO_TOG_DIV_SELECT
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_VIDEO_TOG, 7,  0, true> CCM_ANALOG_PLL_VIDEO_TOG_DIV_SELECT;

// Numerator of Video PLL Fractional Loop Divider Register
#undef CCM_ANALOG_PLL_VIDEO_NUM_A
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_VIDEO_NUM, 30, 0> CCM_ANALOG_PLL_VIDEO_NUM_A;

// Denominator of Video PLL Fractional Loop Divider Register
#undef CCM_ANALOG_PLL_VIDEO_DENOM_B
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_VIDEO_DENOM, 30, 0> CCM_ANALOG_PLL_VIDEO_DENOM_B;

// Analog ENET PLL Control Register
#undef CCM_ANALOG_PLL_ENET_LOCK
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ENET,  1, 31> CCM_ANALOG_PLL_ENET_LOCK;
#undef CCM_ANALOG_PLL_ENET_ENET_25M_REF_EN
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ENET,  1, 21> CCM_ANALOG_PLL_ENET_ENET_25M_REF_EN;
#undef CCM_ANALOG_PLL_ENET_ENET2_REF_EN
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ENET,  1, 20> CCM_ANALOG_PLL_ENET_ENET2_REF_EN;
#undef CCM_ANALOG_PLL_ENET_BYPASS
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ENET,  1, 16> CCM_ANALOG_PLL_ENET_BYPASS;
#undef CCM_ANALOG_PLL_ENET_BYPASS_CLK_SRC
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ENET,  2, 14> CCM_ANALOG_PLL_ENET_BYPASS_CLK_SRC;
    // 0b00..Select the 24MHz oscillator as source.
    // 0b01..Select the CLK1_N / CLK1_P as source.
    // 0b10..Reserved1
    // 0b11..Reserved2
#undef CCM_ANALOG_PLL_ENET_ENABLE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ENET,  1, 13> CCM_ANALOG_PLL_ENET_ENABLE;
#undef CCM_ANALOG_PLL_ENET_POWERDOWN
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ENET,  1, 12> CCM_ANALOG_PLL_ENET_POWERDOWN;
#undef CCM_ANALOG_PLL_ENET_ENET2_DIV_SELECT
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ENET,  2,  2> CCM_ANALOG_PLL_ENET_ENET2_DIV_SELECT;
    // 0b00..25MHz
    // 0b01..50MHz
    // 0b10..100MHz (not 50% duty cycle)
    // 0b11..125MHz
#undef CCM_ANALOG_PLL_ENET_DIV_SELECT
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ENET,  2,  0> CCM_ANALOG_PLL_ENET_DIV_SELECT;

// Analog ENET PLL Control Register
#undef CCM_ANALOG_PLL_ENET_SET_LOCK
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ENET_SET,  1, 31, true> CCM_ANALOG_PLL_ENET_SET_LOCK;
#undef CCM_ANALOG_PLL_ENET_SET_ENET_25M_REF_EN
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ENET_SET,  1, 21, true> CCM_ANALOG_PLL_ENET_SET_ENET_25M_REF_EN;
#undef CCM_ANALOG_PLL_ENET_SET_ENET2_REF_EN
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ENET_SET,  1, 20, true> CCM_ANALOG_PLL_ENET_SET_ENET2_REF_EN;
#undef CCM_ANALOG_PLL_ENET_SET_BYPASS
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ENET_SET,  1, 16, true> CCM_ANALOG_PLL_ENET_SET_BYPASS;
#undef CCM_ANALOG_PLL_ENET_SET_BYPASS_CLK_SRC
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ENET_SET,  2, 14, true> CCM_ANALOG_PLL_ENET_SET_BYPASS_CLK_SRC;
#undef CCM_ANALOG_PLL_ENET_SET_ENABLE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ENET_SET,  1, 13, true> CCM_ANALOG_PLL_ENET_SET_ENABLE;
#undef CCM_ANALOG_PLL_ENET_SET_POWERDOWN
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ENET_SET,  1, 12, true> CCM_ANALOG_PLL_ENET_SET_POWERDOWN;
#undef CCM_ANALOG_PLL_ENET_SET_ENET2_DIV_SELECT
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ENET_SET,  2,  2, true> CCM_ANALOG_PLL_ENET_SET_ENET2_DIV_SELECT;
#undef CCM_ANALOG_PLL_ENET_SET_DIV_SELECT
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ENET_SET,  2,  0, true> CCM_ANALOG_PLL_ENET_SET_DIV_SELECT;

// Analog ENET PLL Control Register
#undef CCM_ANALOG_PLL_ENET_CLR_LOCK
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ENET_CLR,  1, 31, true> CCM_ANALOG_PLL_ENET_CLR_LOCK;
#undef CCM_ANALOG_PLL_ENET_CLR_ENET_25M_REF_EN
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ENET_CLR,  1, 21, true> CCM_ANALOG_PLL_ENET_CLR_ENET_25M_REF_EN;
#undef CCM_ANALOG_PLL_ENET_CLR_ENET2_REF_EN
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ENET_CLR,  1, 20, true> CCM_ANALOG_PLL_ENET_CLR_ENET2_REF_EN;
#undef CCM_ANALOG_PLL_ENET_CLR_BYPASS
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ENET_CLR,  1, 16, true> CCM_ANALOG_PLL_ENET_CLR_BYPASS;
#undef CCM_ANALOG_PLL_ENET_CLR_BYPASS_CLK_SRC
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ENET_CLR,  2, 14, true> CCM_ANALOG_PLL_ENET_CLR_BYPASS_CLK_SRC;
#undef CCM_ANALOG_PLL_ENET_CLR_ENABLE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ENET_CLR,  1, 13, true> CCM_ANALOG_PLL_ENET_CLR_ENABLE;
#undef CCM_ANALOG_PLL_ENET_CLR_POWERDOWN
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ENET_CLR,  1, 12, true> CCM_ANALOG_PLL_ENET_CLR_POWERDOWN;
#undef CCM_ANALOG_PLL_ENET_CLR_ENET2_DIV_SELECT
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ENET_CLR,  2,  2, true> CCM_ANALOG_PLL_ENET_CLR_ENET2_DIV_SELECT;
#undef CCM_ANALOG_PLL_ENET_CLR_DIV_SELECT
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ENET_CLR,  2,  0, true> CCM_ANALOG_PLL_ENET_CLR_DIV_SELECT;

// Analog ENET PLL Control Register
#undef CCM_ANALOG_PLL_ENET_TOG_LOCK
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ENET_TOG,  1, 31, true> CCM_ANALOG_PLL_ENET_TOG_LOCK;
#undef CCM_ANALOG_PLL_ENET_TOG_ENET_25M_REF_EN
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ENET_TOG,  1, 21, true> CCM_ANALOG_PLL_ENET_TOG_ENET_25M_REF_EN;
#undef CCM_ANALOG_PLL_ENET_TOG_ENET2_REF_EN
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ENET_TOG,  1, 20, true> CCM_ANALOG_PLL_ENET_TOG_ENET2_REF_EN;
#undef CCM_ANALOG_PLL_ENET_TOG_BYPASS
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ENET_TOG,  1, 16, true> CCM_ANALOG_PLL_ENET_TOG_BYPASS;
#undef CCM_ANALOG_PLL_ENET_TOG_BYPASS_CLK_SRC
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ENET_TOG,  2, 14, true> CCM_ANALOG_PLL_ENET_TOG_BYPASS_CLK_SRC;
#undef CCM_ANALOG_PLL_ENET_TOG_ENABLE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ENET_TOG,  1, 13, true> CCM_ANALOG_PLL_ENET_TOG_ENABLE;
#undef CCM_ANALOG_PLL_ENET_TOG_POWERDOWN
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ENET_TOG,  1, 12, true> CCM_ANALOG_PLL_ENET_TOG_POWERDOWN;
#undef CCM_ANALOG_PLL_ENET_TOG_ENET2_DIV_SELECT
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ENET_TOG,  2,  2, true> CCM_ANALOG_PLL_ENET_TOG_ENET2_DIV_SELECT;
#undef CCM_ANALOG_PLL_ENET_TOG_DIV_SELECT
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PLL_ENET_TOG,  2,  0, true> CCM_ANALOG_PLL_ENET_TOG_DIV_SELECT;

// 480MHz Clock (PLL3) Phase Fractional Divider Control Register
#undef CCM_ANALOG_PFD_480_PFD3_CLKGATE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480, 1, 31> CCM_ANALOG_PFD_480_PFD3_CLKGATE;
#undef CCM_ANALOG_PFD_480_PFD3_STABLE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480, 1, 30> CCM_ANALOG_PFD_480_PFD3_STABLE;
#undef CCM_ANALOG_PFD_480_PFD3_FRAC
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480, 6, 24> CCM_ANALOG_PFD_480_PFD3_FRAC;
#undef CCM_ANALOG_PFD_480_PFD2_CLKGATE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480, 1, 23> CCM_ANALOG_PFD_480_PFD2_CLKGATE;
#undef CCM_ANALOG_PFD_480_PFD2_STABLE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480, 1, 22> CCM_ANALOG_PFD_480_PFD2_STABLE;
#undef CCM_ANALOG_PFD_480_PFD2_FRAC
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480, 6, 16> CCM_ANALOG_PFD_480_PFD2_FRAC;
#undef CCM_ANALOG_PFD_480_PFD1_CLKGATE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480, 1, 15> CCM_ANALOG_PFD_480_PFD1_CLKGATE;
#undef CCM_ANALOG_PFD_480_PFD1_STABLE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480, 1, 14> CCM_ANALOG_PFD_480_PFD1_STABLE;
#undef CCM_ANALOG_PFD_480_PFD1_FRAC
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480, 6,  8> CCM_ANALOG_PFD_480_PFD1_FRAC;
#undef CCM_ANALOG_PFD_480_PFD0_CLKGATE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480, 1,  7> CCM_ANALOG_PFD_480_PFD0_CLKGATE;
#undef CCM_ANALOG_PFD_480_PFD0_STABLE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480, 1,  6> CCM_ANALOG_PFD_480_PFD0_STABLE;
#undef CCM_ANALOG_PFD_480_PFD0_FRAC
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480, 6,  0> CCM_ANALOG_PFD_480_PFD0_FRAC;

// 480MHz Clock (PLL3) Phase Fractional Divider Control Register
#undef CCM_ANALOG_PFD_480_SET_PFD3_CLKGATE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480_SET, 1, 31, true> CCM_ANALOG_PFD_480_SET_PFD3_CLKGATE;
#undef CCM_ANALOG_PFD_480_SET_PFD3_STABLE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480_SET, 1, 30, true> CCM_ANALOG_PFD_480_SET_PFD3_STABLE;
#undef CCM_ANALOG_PFD_480_SET_PFD3_FRAC
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480_SET, 6, 24, true> CCM_ANALOG_PFD_480_SET_PFD3_FRAC;
#undef CCM_ANALOG_PFD_480_SET_PFD2_CLKGATE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480_SET, 1, 23, true> CCM_ANALOG_PFD_480_SET_PFD2_CLKGATE;
#undef CCM_ANALOG_PFD_480_SET_PFD2_STABLE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480_SET, 1, 22, true> CCM_ANALOG_PFD_480_SET_PFD2_STABLE;
#undef CCM_ANALOG_PFD_480_SET_PFD2_FRAC
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480_SET, 6, 16, true> CCM_ANALOG_PFD_480_SET_PFD2_FRAC;
#undef CCM_ANALOG_PFD_480_SET_PFD1_CLKGATE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480_SET, 1, 15, true> CCM_ANALOG_PFD_480_SET_PFD1_CLKGATE;
#undef CCM_ANALOG_PFD_480_SET_PFD1_STABLE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480_SET, 1, 14, true> CCM_ANALOG_PFD_480_SET_PFD1_STABLE;
#undef CCM_ANALOG_PFD_480_SET_PFD1_FRAC
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480_SET, 6,  8, true> CCM_ANALOG_PFD_480_SET_PFD1_FRAC;
#undef CCM_ANALOG_PFD_480_SET_PFD0_CLKGATE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480_SET, 1,  7, true> CCM_ANALOG_PFD_480_SET_PFD0_CLKGATE;
#undef CCM_ANALOG_PFD_480_SET_PFD0_STABLE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480_SET, 1,  6, true> CCM_ANALOG_PFD_480_SET_PFD0_STABLE;
#undef CCM_ANALOG_PFD_480_SET_PFD0_FRAC
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480_SET, 6,  0, true> CCM_ANALOG_PFD_480_SET_PFD0_FRAC;

// 480MHz Clock (PLL3) Phase Fractional Divider Control Register
#undef CCM_ANALOG_PFD_480_CLR_PFD3_CLKGATE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480_CLR, 1, 31, true> CCM_ANALOG_PFD_480_CLR_PFD3_CLKGATE;
#undef CCM_ANALOG_PFD_480_CLR_PFD3_STABLE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480_CLR, 1, 30, true> CCM_ANALOG_PFD_480_CLR_PFD3_STABLE;
#undef CCM_ANALOG_PFD_480_CLR_PFD3_FRAC
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480_CLR, 6, 24, true> CCM_ANALOG_PFD_480_CLR_PFD3_FRAC;
#undef CCM_ANALOG_PFD_480_CLR_PFD2_CLKGATE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480_CLR, 1, 23, true> CCM_ANALOG_PFD_480_CLR_PFD2_CLKGATE;
#undef CCM_ANALOG_PFD_480_CLR_PFD2_STABLE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480_CLR, 1, 22, true> CCM_ANALOG_PFD_480_CLR_PFD2_STABLE;
#undef CCM_ANALOG_PFD_480_CLR_PFD2_FRAC
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480_CLR, 6, 16, true> CCM_ANALOG_PFD_480_CLR_PFD2_FRAC;
#undef CCM_ANALOG_PFD_480_CLR_PFD1_CLKGATE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480_CLR, 1, 15, true> CCM_ANALOG_PFD_480_CLR_PFD1_CLKGATE;
#undef CCM_ANALOG_PFD_480_CLR_PFD1_STABLE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480_CLR, 1, 14, true> CCM_ANALOG_PFD_480_CLR_PFD1_STABLE;
#undef CCM_ANALOG_PFD_480_CLR_PFD1_FRAC
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480_CLR, 6,  8, true> CCM_ANALOG_PFD_480_CLR_PFD1_FRAC;
#undef CCM_ANALOG_PFD_480_CLR_PFD0_CLKGATE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480_CLR, 1,  7, true> CCM_ANALOG_PFD_480_CLR_PFD0_CLKGATE;
#undef CCM_ANALOG_PFD_480_CLR_PFD0_STABLE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480_CLR, 1,  6, true> CCM_ANALOG_PFD_480_CLR_PFD0_STABLE;
#undef CCM_ANALOG_PFD_480_CLR_PFD0_FRAC
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480_CLR, 6,  0, true> CCM_ANALOG_PFD_480_CLR_PFD0_FRAC;

// 480MHz Clock (PLL3) Phase Fractional Divider Control Register
#undef CCM_ANALOG_PFD_480_TOG_PFD3_CLKGATE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480_TOG, 1, 31, true> CCM_ANALOG_PFD_480_TOG_PFD3_CLKGATE;
#undef CCM_ANALOG_PFD_480_TOG_PFD3_STABLE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480_TOG, 1, 30, true> CCM_ANALOG_PFD_480_TOG_PFD3_STABLE;
#undef CCM_ANALOG_PFD_480_TOG_PFD3_FRAC
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480_TOG, 6, 24, true> CCM_ANALOG_PFD_480_TOG_PFD3_FRAC;
#undef CCM_ANALOG_PFD_480_TOG_PFD2_CLKGATE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480_TOG, 1, 23, true> CCM_ANALOG_PFD_480_TOG_PFD2_CLKGATE;
#undef CCM_ANALOG_PFD_480_TOG_PFD2_STABLE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480_TOG, 1, 22, true> CCM_ANALOG_PFD_480_TOG_PFD2_STABLE;
#undef CCM_ANALOG_PFD_480_TOG_PFD2_FRAC
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480_TOG, 6, 16, true> CCM_ANALOG_PFD_480_TOG_PFD2_FRAC;
#undef CCM_ANALOG_PFD_480_TOG_PFD1_CLKGATE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480_TOG, 1, 15, true> CCM_ANALOG_PFD_480_TOG_PFD1_CLKGATE;
#undef CCM_ANALOG_PFD_480_TOG_PFD1_STABLE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480_TOG, 1, 14, true> CCM_ANALOG_PFD_480_TOG_PFD1_STABLE;
#undef CCM_ANALOG_PFD_480_TOG_PFD1_FRAC
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480_TOG, 6,  8, true> CCM_ANALOG_PFD_480_TOG_PFD1_FRAC;
#undef CCM_ANALOG_PFD_480_TOG_PFD0_CLKGATE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480_TOG, 1,  7, true> CCM_ANALOG_PFD_480_TOG_PFD0_CLKGATE;
#undef CCM_ANALOG_PFD_480_TOG_PFD0_STABLE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480_TOG, 1,  6, true> CCM_ANALOG_PFD_480_TOG_PFD0_STABLE;
#undef CCM_ANALOG_PFD_480_TOG_PFD0_FRAC
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_480_TOG, 6,  0, true> CCM_ANALOG_PFD_480_TOG_PFD0_FRAC;

// 528MHz Clock (PLL2) Phase Fractional Divider Control Register
#undef CCM_ANALOG_PFD_528_PFD3_CLKGATE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528, 1, 31> CCM_ANALOG_PFD_528_PFD3_CLKGATE;
#undef CCM_ANALOG_PFD_528_PFD3_STABLE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528, 1, 30> CCM_ANALOG_PFD_528_PFD3_STABLE;
#undef CCM_ANALOG_PFD_528_PFD3_FRAC
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528, 6, 24> CCM_ANALOG_PFD_528_PFD3_FRAC;
#undef CCM_ANALOG_PFD_528_PFD2_CLKGATE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528, 1, 23> CCM_ANALOG_PFD_528_PFD2_CLKGATE;
#undef CCM_ANALOG_PFD_528_PFD2_STABLE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528, 1, 22> CCM_ANALOG_PFD_528_PFD2_STABLE;
#undef CCM_ANALOG_PFD_528_PFD2_FRAC
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528, 6, 16> CCM_ANALOG_PFD_528_PFD2_FRAC;
#undef CCM_ANALOG_PFD_528_PFD1_CLKGATE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528, 1, 15> CCM_ANALOG_PFD_528_PFD1_CLKGATE;
#undef CCM_ANALOG_PFD_528_PFD1_STABLE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528, 1, 14> CCM_ANALOG_PFD_528_PFD1_STABLE;
#undef CCM_ANALOG_PFD_528_PFD1_FRAC
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528, 6,  8> CCM_ANALOG_PFD_528_PFD1_FRAC;
#undef CCM_ANALOG_PFD_528_PFD0_CLKGATE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528, 1,  7> CCM_ANALOG_PFD_528_PFD0_CLKGATE;
#undef CCM_ANALOG_PFD_528_PFD0_STABLE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528, 1,  6> CCM_ANALOG_PFD_528_PFD0_STABLE;
#undef CCM_ANALOG_PFD_528_PFD0_FRAC
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528, 6,  0> CCM_ANALOG_PFD_528_PFD0_FRAC;

// 528MHz Clock (PLL2) Phase Fractional Divider Control Register
#undef CCM_ANALOG_PFD_528_SET_PFD3_CLKGATE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528_SET, 1, 31, true> CCM_ANALOG_PFD_528_SET_PFD3_CLKGATE;
#undef CCM_ANALOG_PFD_528_SET_PFD3_STABLE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528_SET, 1, 30, true> CCM_ANALOG_PFD_528_SET_PFD3_STABLE;
#undef CCM_ANALOG_PFD_528_SET_PFD3_FRAC
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528_SET, 6, 24, true> CCM_ANALOG_PFD_528_SET_PFD3_FRAC;
#undef CCM_ANALOG_PFD_528_SET_PFD2_CLKGATE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528_SET, 1, 23, true> CCM_ANALOG_PFD_528_SET_PFD2_CLKGATE;
#undef CCM_ANALOG_PFD_528_SET_PFD2_STABLE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528_SET, 1, 22, true> CCM_ANALOG_PFD_528_SET_PFD2_STABLE;
#undef CCM_ANALOG_PFD_528_SET_PFD2_FRAC
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528_SET, 6, 16, true> CCM_ANALOG_PFD_528_SET_PFD2_FRAC;
#undef CCM_ANALOG_PFD_528_SET_PFD1_CLKGATE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528_SET, 1, 15, true> CCM_ANALOG_PFD_528_SET_PFD1_CLKGATE;
#undef CCM_ANALOG_PFD_528_SET_PFD1_STABLE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528_SET, 1, 14, true> CCM_ANALOG_PFD_528_SET_PFD1_STABLE;
#undef CCM_ANALOG_PFD_528_SET_PFD1_FRAC
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528_SET, 6,  8, true> CCM_ANALOG_PFD_528_SET_PFD1_FRAC;
#undef CCM_ANALOG_PFD_528_SET_PFD0_CLKGATE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528_SET, 1,  7, true> CCM_ANALOG_PFD_528_SET_PFD0_CLKGATE;
#undef CCM_ANALOG_PFD_528_SET_PFD0_STABLE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528_SET, 1,  6, true> CCM_ANALOG_PFD_528_SET_PFD0_STABLE;
#undef CCM_ANALOG_PFD_528_SET_PFD0_FRAC
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528_SET, 6,  0, true> CCM_ANALOG_PFD_528_SET_PFD0_FRAC;

// 528MHz Clock (PLL2) Phase Fractional Divider Control Register
#undef CCM_ANALOG_PFD_528_CLR_PFD3_CLKGATE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528_CLR, 1, 31, true> CCM_ANALOG_PFD_528_CLR_PFD3_CLKGATE;
#undef CCM_ANALOG_PFD_528_CLR_PFD3_STABLE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528_CLR, 1, 30, true> CCM_ANALOG_PFD_528_CLR_PFD3_STABLE;
#undef CCM_ANALOG_PFD_528_CLR_PFD3_FRAC
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528_CLR, 6, 24, true> CCM_ANALOG_PFD_528_CLR_PFD3_FRAC;
#undef CCM_ANALOG_PFD_528_CLR_PFD2_CLKGATE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528_CLR, 1, 23, true> CCM_ANALOG_PFD_528_CLR_PFD2_CLKGATE;
#undef CCM_ANALOG_PFD_528_CLR_PFD2_STABLE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528_CLR, 1, 22, true> CCM_ANALOG_PFD_528_CLR_PFD2_STABLE;
#undef CCM_ANALOG_PFD_528_CLR_PFD2_FRAC
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528_CLR, 6, 16, true> CCM_ANALOG_PFD_528_CLR_PFD2_FRAC;
#undef CCM_ANALOG_PFD_528_CLR_PFD1_CLKGATE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528_CLR, 1, 15, true> CCM_ANALOG_PFD_528_CLR_PFD1_CLKGATE;
#undef CCM_ANALOG_PFD_528_CLR_PFD1_STABLE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528_CLR, 1, 14, true> CCM_ANALOG_PFD_528_CLR_PFD1_STABLE;
#undef CCM_ANALOG_PFD_528_CLR_PFD1_FRAC
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528_CLR, 6,  8, true> CCM_ANALOG_PFD_528_CLR_PFD1_FRAC;
#undef CCM_ANALOG_PFD_528_CLR_PFD0_CLKGATE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528_CLR, 1,  7, true> CCM_ANALOG_PFD_528_CLR_PFD0_CLKGATE;
#undef CCM_ANALOG_PFD_528_CLR_PFD0_STABLE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528_CLR, 1,  6, true> CCM_ANALOG_PFD_528_CLR_PFD0_STABLE;
#undef CCM_ANALOG_PFD_528_CLR_PFD0_FRAC
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528_CLR, 6,  0, true> CCM_ANALOG_PFD_528_CLR_PFD0_FRAC;

// 528MHz Clock (PLL2) Phase Fractional Divider Control Register
#undef CCM_ANALOG_PFD_528_TOG_PFD3_CLKGATE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528_TOG, 1, 31, true> CCM_ANALOG_PFD_528_TOG_PFD3_CLKGATE;
#undef CCM_ANALOG_PFD_528_TOG_PFD3_STABLE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528_TOG, 1, 30, true> CCM_ANALOG_PFD_528_TOG_PFD3_STABLE;
#undef CCM_ANALOG_PFD_528_TOG_PFD3_FRAC
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528_TOG, 6, 24, true> CCM_ANALOG_PFD_528_TOG_PFD3_FRAC;
#undef CCM_ANALOG_PFD_528_TOG_PFD2_CLKGATE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528_TOG, 1, 23, true> CCM_ANALOG_PFD_528_TOG_PFD2_CLKGATE;
#undef CCM_ANALOG_PFD_528_TOG_PFD2_STABLE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528_TOG, 1, 22, true> CCM_ANALOG_PFD_528_TOG_PFD2_STABLE;
#undef CCM_ANALOG_PFD_528_TOG_PFD2_FRAC
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528_TOG, 6, 16, true> CCM_ANALOG_PFD_528_TOG_PFD2_FRAC;
#undef CCM_ANALOG_PFD_528_TOG_PFD1_CLKGATE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528_TOG, 1, 15, true> CCM_ANALOG_PFD_528_TOG_PFD1_CLKGATE;
#undef CCM_ANALOG_PFD_528_TOG_PFD1_STABLE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528_TOG, 1, 14, true> CCM_ANALOG_PFD_528_TOG_PFD1_STABLE;
#undef CCM_ANALOG_PFD_528_TOG_PFD1_FRAC
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528_TOG, 6,  8, true> CCM_ANALOG_PFD_528_TOG_PFD1_FRAC;
#undef CCM_ANALOG_PFD_528_TOG_PFD0_CLKGATE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528_TOG, 1,  7, true> CCM_ANALOG_PFD_528_TOG_PFD0_CLKGATE;
#undef CCM_ANALOG_PFD_528_TOG_PFD0_STABLE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528_TOG, 1,  6, true> CCM_ANALOG_PFD_528_TOG_PFD0_STABLE;
#undef CCM_ANALOG_PFD_528_TOG_PFD0_FRAC
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::PFD_528_TOG, 6,  0, true> CCM_ANALOG_PFD_528_TOG_PFD0_FRAC;

// Miscellaneous Register 0
#undef CCM_ANALOG_MISC0_XTAL_24M_PWD
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0, 1, 30> CCM_ANALOG_MISC0_XTAL_24M_PWD;
#undef CCM_ANALOG_MISC0_RTC_XTAL_SOURCE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0, 1, 29> CCM_ANALOG_MISC0_RTC_XTAL_SOURCE;
    // 0b0..Internal ring oscillator
    // 0b1..RTC_XTAL
#undef CCM_ANALOG_MISC0_CLKGATE_DELAY
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0, 3, 26> CCM_ANALOG_MISC0_CLKGATE_DELAY;
    // 0b000..0.5ms
    // 0b001..1.0ms
    // 0b010..2.0ms
    // 0b011..3.0ms
    // 0b100..4.0ms
    // 0b101..5.0ms
    // 0b110..6.0ms
    // 0b111..7.0ms
#undef CCM_ANALOG_MISC0_CLKGATE_CTRL
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0, 1, 25> CCM_ANALOG_MISC0_CLKGATE_CTRL;
    // 0b0..Allow the logic to automatically gate the clock when the XTAL is powered down.
    // 0b1..Prevent the logic from ever gating off the clock.
#undef CCM_ANALOG_MISC0_OSC_XTALOK_EN
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0, 1, 16> CCM_ANALOG_MISC0_OSC_XTALOK_EN;
#undef CCM_ANALOG_MISC0_OSC_XTALOK
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0, 1, 15> CCM_ANALOG_MISC0_OSC_XTALOK;
#undef CCM_ANALOG_MISC0_OSC_I
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0, 2, 13> CCM_ANALOG_MISC0_OSC_I;
    // Decrease current by 'value'*12.5%:
    // 0b00..Nominal
    // 0b01..Decrease current by 12.5%
    // 0b10..Decrease current by 25.0%
    // 0b11..Decrease current by 37.5%
#undef CCM_ANALOG_MISC0_DISCON_HIGH_SNVS
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0, 1, 12> CCM_ANALOG_MISC0_DISCON_HIGH_SNVS;
    // 0b0..Turn on the switch
    // 0b1..Turn off the switch
#undef CCM_ANALOG_MISC0_STOP_MODE_CONFIG
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0, 2, 10> CCM_ANALOG_MISC0_STOP_MODE_CONFIG;
    // 0b00..All analog except RTC powered down on stop mode assertion.
    // 0b01..Beside RTC, analog bandgap, 1p1 and 2p5 regulators are also on.
    // 0b10..Beside RTC, 1p1 and 2p5 regulators are also on, low-power bandgap is selected so that the normal analog
    //       bandgap together with the rest analog is powered down.
    // 0b11..Beside RTC, low-power bandgap is selected and the rest analog is powered down.
#undef CCM_ANALOG_MISC0_REFTOP_VBGUP
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0, 1,  7> CCM_ANALOG_MISC0_REFTOP_VBGUP;
#undef CCM_ANALOG_MISC0_REFTOP_VBGADJ
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0, 3,  4> CCM_ANALOG_MISC0_REFTOP_VBGADJ;
    // 0b000..Nominal VBG
    // 0b001..VBG+0.78%
    // 0b010..VBG+1.56%
    // 0b011..VBG+2.34%
    // 0b100..VBG-0.78%
    // 0b101..VBG-1.56%
    // 0b110..VBG-2.34%
    // 0b111..VBG-3.12%
#undef CCM_ANALOG_MISC0_REFTOP_SELFBIASOFF
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0, 1,  3> CCM_ANALOG_MISC0_REFTOP_SELFBIASOFF;
    // 0b0..Uses coarse bias currents for startup
    // 0b1..Uses bandgap-based bias currents for best performance.
#undef CCM_ANALOG_MISC0_REFTOP_PWD
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0, 1,  0> CCM_ANALOG_MISC0_REFTOP_PWD;

// Miscellaneous Register 0
#undef CCM_ANALOG_MISC0_SET_XTAL_24M_PWD
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0_SET, 1, 30, true> CCM_ANALOG_MISC0_SET_XTAL_24M_PWD;
#undef CCM_ANALOG_MISC0_SET_RTC_XTAL_SOURCE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0_SET, 1, 29, true> CCM_ANALOG_MISC0_SET_RTC_XTAL_SOURCE;
#undef CCM_ANALOG_MISC0_SET_CLKGATE_DELAY
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0_SET, 3, 26, true> CCM_ANALOG_MISC0_SET_CLKGATE_DELAY;
#undef CCM_ANALOG_MISC0_SET_CLKGATE_CTRL
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0_SET, 1, 25, true> CCM_ANALOG_MISC0_SET_CLKGATE_CTRL;
#undef CCM_ANALOG_MISC0_SET_OSC_XTALOK_EN
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0_SET, 1, 16, true> CCM_ANALOG_MISC0_SET_OSC_XTALOK_EN;
#undef CCM_ANALOG_MISC0_SET_OSC_XTALOK
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0_SET, 1, 15, true> CCM_ANALOG_MISC0_SET_OSC_XTALOK;
#undef CCM_ANALOG_MISC0_SET_OSC_I
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0_SET, 2, 13, true> CCM_ANALOG_MISC0_SET_OSC_I;
#undef CCM_ANALOG_MISC0_SET_DISCON_HIGH_SNVS
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0_SET, 1, 12, true> CCM_ANALOG_MISC0_SET_DISCON_HIGH_SNVS;
#undef CCM_ANALOG_MISC0_SET_STOP_MODE_CONFIG
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0_SET, 2, 10, true> CCM_ANALOG_MISC0_SET_STOP_MODE_CONFIG;
#undef CCM_ANALOG_MISC0_SET_REFTOP_VBGUP
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0_SET, 1,  7, true> CCM_ANALOG_MISC0_SET_REFTOP_VBGUP;
#undef CCM_ANALOG_MISC0_SET_REFTOP_VBGADJ
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0_SET, 3,  4, true> CCM_ANALOG_MISC0_SET_REFTOP_VBGADJ;
#undef CCM_ANALOG_MISC0_SET_REFTOP_SELFBIASOFF
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0_SET, 1,  3, true> CCM_ANALOG_MISC0_SET_REFTOP_SELFBIASOFF;
#undef CCM_ANALOG_MISC0_SET_REFTOP_PWD
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0_SET, 1,  0, true> CCM_ANALOG_MISC0_SET_REFTOP_PWD;

// Miscellaneous Register 0
#undef CCM_ANALOG_MISC0_CLR_XTAL_24M_PWD
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0_CLR, 1, 30, true> CCM_ANALOG_MISC0_CLR_XTAL_24M_PWD;
#undef CCM_ANALOG_MISC0_CLR_RTC_XTAL_SOURCE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0_CLR, 1, 29, true> CCM_ANALOG_MISC0_CLR_RTC_XTAL_SOURCE;
#undef CCM_ANALOG_MISC0_CLR_CLKGATE_DELAY
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0_CLR, 3, 26, true> CCM_ANALOG_MISC0_CLR_CLKGATE_DELAY;
#undef CCM_ANALOG_MISC0_CLR_CLKGATE_CTRL
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0_CLR, 1, 25, true> CCM_ANALOG_MISC0_CLR_CLKGATE_CTRL;
#undef CCM_ANALOG_MISC0_CLR_OSC_XTALOK_EN
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0_CLR, 1, 16, true> CCM_ANALOG_MISC0_CLR_OSC_XTALOK_EN;
#undef CCM_ANALOG_MISC0_CLR_OSC_XTALOK
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0_CLR, 1, 15, true> CCM_ANALOG_MISC0_CLR_OSC_XTALOK;
#undef CCM_ANALOG_MISC0_CLR_OSC_I
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0_CLR, 2, 13, true> CCM_ANALOG_MISC0_CLR_OSC_I;
#undef CCM_ANALOG_MISC0_CLR_DISCON_HIGH_SNVS
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0_CLR, 1, 12, true> CCM_ANALOG_MISC0_CLR_DISCON_HIGH_SNVS;
#undef CCM_ANALOG_MISC0_CLR_STOP_MODE_CONFIG
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0_CLR, 2, 10, true> CCM_ANALOG_MISC0_CLR_STOP_MODE_CONFIG;
#undef CCM_ANALOG_MISC0_CLR_REFTOP_VBGUP
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0_CLR, 1,  7, true> CCM_ANALOG_MISC0_CLR_REFTOP_VBGUP;
#undef CCM_ANALOG_MISC0_CLR_REFTOP_VBGADJ
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0_CLR, 3,  4, true> CCM_ANALOG_MISC0_CLR_REFTOP_VBGADJ;
#undef CCM_ANALOG_MISC0_CLR_REFTOP_SELFBIASOFF
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0_CLR, 1,  3, true> CCM_ANALOG_MISC0_CLR_REFTOP_SELFBIASOFF;
#undef CCM_ANALOG_MISC0_CLR_REFTOP_PWD
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0_CLR, 1,  0, true> CCM_ANALOG_MISC0_CLR_REFTOP_PWD;

// Miscellaneous Register 0
#undef CCM_ANALOG_MISC0_TOG_XTAL_24M_PWD
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0_TOG, 1, 30, true> CCM_ANALOG_MISC0_TOG_XTAL_24M_PWD;
#undef CCM_ANALOG_MISC0_TOG_RTC_XTAL_SOURCE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0_TOG, 1, 29, true> CCM_ANALOG_MISC0_TOG_RTC_XTAL_SOURCE;
#undef CCM_ANALOG_MISC0_TOG_CLKGATE_DELAY
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0_TOG, 3, 26, true> CCM_ANALOG_MISC0_TOG_CLKGATE_DELAY;
#undef CCM_ANALOG_MISC0_TOG_CLKGATE_CTRL
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0_TOG, 1, 25, true> CCM_ANALOG_MISC0_TOG_CLKGATE_CTRL;
#undef CCM_ANALOG_MISC0_TOG_OSC_XTALOK_EN
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0_TOG, 1, 16, true> CCM_ANALOG_MISC0_TOG_OSC_XTALOK_EN;
#undef CCM_ANALOG_MISC0_TOG_OSC_XTALOK
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0_TOG, 1, 15, true> CCM_ANALOG_MISC0_TOG_OSC_XTALOK;
#undef CCM_ANALOG_MISC0_TOG_OSC_I
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0_TOG, 2, 13, true> CCM_ANALOG_MISC0_TOG_OSC_I;
#undef CCM_ANALOG_MISC0_TOG_DISCON_HIGH_SNVS
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0_TOG, 1, 12, true> CCM_ANALOG_MISC0_TOG_DISCON_HIGH_SNVS;
#undef CCM_ANALOG_MISC0_TOG_STOP_MODE_CONFIG
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0_TOG, 2, 10, true> CCM_ANALOG_MISC0_TOG_STOP_MODE_CONFIG;
#undef CCM_ANALOG_MISC0_TOG_REFTOP_VBGUP
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0_TOG, 1,  7, true> CCM_ANALOG_MISC0_TOG_REFTOP_VBGUP;
#undef CCM_ANALOG_MISC0_TOG_REFTOP_VBGADJ
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0_TOG, 3,  4, true> CCM_ANALOG_MISC0_TOG_REFTOP_VBGADJ;
#undef CCM_ANALOG_MISC0_TOG_REFTOP_SELFBIASOFF
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0_TOG, 1,  3, true> CCM_ANALOG_MISC0_TOG_REFTOP_SELFBIASOFF;
#undef CCM_ANALOG_MISC0_TOG_REFTOP_PWD
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC0_TOG, 1,  0, true> CCM_ANALOG_MISC0_TOG_REFTOP_PWD;

// Miscellaneous Register 1
#undef CCM_ANALOG_MISC1_IRQ_DIG_BO
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1, 1, 31> CCM_ANALOG_MISC1_IRQ_DIG_BO;
#undef CCM_ANALOG_MISC1_IRQ_ANA_BO
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1, 1, 30> CCM_ANALOG_MISC1_IRQ_ANA_BO;
#undef CCM_ANALOG_MISC1_IRQ_TEMPHIGH
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1, 1, 29> CCM_ANALOG_MISC1_IRQ_TEMPHIGH;
#undef CCM_ANALOG_MISC1_IRQ_TEMPLOW
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1, 1, 28> CCM_ANALOG_MISC1_IRQ_TEMPLOW;
#undef CCM_ANALOG_MISC1_IRQ_TEMPPANIC
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1, 1, 27> CCM_ANALOG_MISC1_IRQ_TEMPPANIC;
#undef CCM_ANALOG_MISC1_PFD_528_AUTOGATE_EN
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1, 1, 17> CCM_ANALOG_MISC1_PFD_528_AUTOGATE_EN;
#undef CCM_ANALOG_MISC1_PFD_480_AUTOGATE_EN
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1, 1, 16> CCM_ANALOG_MISC1_PFD_480_AUTOGATE_EN;
#undef CCM_ANALOG_MISC1_LVDSCLK1_IBEN
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1, 1, 12> CCM_ANALOG_MISC1_LVDSCLK1_IBEN;
#undef CCM_ANALOG_MISC1_LVDSCLK1_OBEN
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1, 1, 10> CCM_ANALOG_MISC1_LVDSCLK1_OBEN;
#undef CCM_ANALOG_MISC1_LVDS1_CLK_SEL
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1, 5,  0> CCM_ANALOG_MISC1_LVDS1_CLK_SEL;
    // 0b00000..Arm PLL
    // 0b00001..System PLL
    // 0b00010..ref_pfd4_clk == pll2_pfd0_clk
    // 0b00011..ref_pfd5_clk == pll2_pfd1_clk
    // 0b00100..ref_pfd6_clk == pll2_pfd2_clk
    // 0b00101..ref_pfd7_clk == pll2_pfd3_clk
    // 0b00110..Audio PLL
    // 0b00111..Video PLL
    // 0b01001..ethernet ref clock (ENET_PLL)
    // 0b01100..USB1 PLL clock
    // 0b01101..USB2 PLL clock
    // 0b01110..ref_pfd0_clk == pll3_pfd0_clk
    // 0b01111..ref_pfd1_clk == pll3_pfd1_clk
    // 0b10000..ref_pfd2_clk == pll3_pfd2_clk
    // 0b10001..ref_pfd3_clk == pll3_pfd3_clk
    // 0b10010..xtal (24M)

// Miscellaneous Register 1
#undef CCM_ANALOG_MISC1_SET_IRQ_DIG_BO
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1_SET, 1, 31, true> CCM_ANALOG_MISC1_SET_IRQ_DIG_BO;
#undef CCM_ANALOG_MISC1_SET_IRQ_ANA_BO
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1_SET, 1, 30, true> CCM_ANALOG_MISC1_SET_IRQ_ANA_BO;
#undef CCM_ANALOG_MISC1_SET_IRQ_TEMPHIGH
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1_SET, 1, 29, true> CCM_ANALOG_MISC1_SET_IRQ_TEMPHIGH;
#undef CCM_ANALOG_MISC1_SET_IRQ_TEMPLOW
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1_SET, 1, 28, true> CCM_ANALOG_MISC1_SET_IRQ_TEMPLOW;
#undef CCM_ANALOG_MISC1_SET_IRQ_TEMPPANIC
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1_SET, 1, 27, true> CCM_ANALOG_MISC1_SET_IRQ_TEMPPANIC;
#undef CCM_ANALOG_MISC1_SET_PFD_528_AUTOGATE_EN
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1_SET, 1, 17, true> CCM_ANALOG_MISC1_SET_PFD_528_AUTOGATE_EN;
#undef CCM_ANALOG_MISC1_SET_PFD_480_AUTOGATE_EN
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1_SET, 1, 16, true> CCM_ANALOG_MISC1_SET_PFD_480_AUTOGATE_EN;
#undef CCM_ANALOG_MISC1_SET_LVDSCLK1_IBEN
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1_SET, 1, 12, true> CCM_ANALOG_MISC1_SET_LVDSCLK1_IBEN;
#undef CCM_ANALOG_MISC1_SET_LVDSCLK1_OBEN
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1_SET, 1, 10, true> CCM_ANALOG_MISC1_SET_LVDSCLK1_OBEN;
#undef CCM_ANALOG_MISC1_SET_LVDS1_CLK_SEL
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1_SET, 5,  0, true> CCM_ANALOG_MISC1_SET_LVDS1_CLK_SEL;

// Miscellaneous Register 1
#undef CCM_ANALOG_MISC1_CLR_IRQ_DIG_BO
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1_CLR, 1, 31, true> CCM_ANALOG_MISC1_CLR_IRQ_DIG_BO;
#undef CCM_ANALOG_MISC1_CLR_IRQ_ANA_BO
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1_CLR, 1, 30, true> CCM_ANALOG_MISC1_CLR_IRQ_ANA_BO;
#undef CCM_ANALOG_MISC1_CLR_IRQ_TEMPHIGH
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1_CLR, 1, 29, true> CCM_ANALOG_MISC1_CLR_IRQ_TEMPHIGH;
#undef CCM_ANALOG_MISC1_CLR_IRQ_TEMPLOW
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1_CLR, 1, 28, true> CCM_ANALOG_MISC1_CLR_IRQ_TEMPLOW;
#undef CCM_ANALOG_MISC1_CLR_IRQ_TEMPPANIC
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1_CLR, 1, 27, true> CCM_ANALOG_MISC1_CLR_IRQ_TEMPPANIC;
#undef CCM_ANALOG_MISC1_CLR_PFD_528_AUTOGATE_EN
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1_CLR, 1, 17, true> CCM_ANALOG_MISC1_CLR_PFD_528_AUTOGATE_EN;
#undef CCM_ANALOG_MISC1_CLR_PFD_480_AUTOGATE_EN
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1_CLR, 1, 16, true> CCM_ANALOG_MISC1_CLR_PFD_480_AUTOGATE_EN;
#undef CCM_ANALOG_MISC1_CLR_LVDSCLK1_IBEN
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1_CLR, 1, 12, true> CCM_ANALOG_MISC1_CLR_LVDSCLK1_IBEN;
#undef CCM_ANALOG_MISC1_CLR_LVDSCLK1_OBEN
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1_CLR, 1, 10, true> CCM_ANALOG_MISC1_CLR_LVDSCLK1_OBEN;
#undef CCM_ANALOG_MISC1_CLR_LVDS1_CLK_SEL
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1_CLR, 5,  0, true> CCM_ANALOG_MISC1_CLR_LVDS1_CLK_SEL;

// Miscellaneous Register 1
#undef CCM_ANALOG_MISC1_TOG_IRQ_DIG_BO
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1_TOG, 1, 31, true> CCM_ANALOG_MISC1_TOG_IRQ_DIG_BO;
#undef CCM_ANALOG_MISC1_TOG_IRQ_ANA_BO
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1_TOG, 1, 30, true> CCM_ANALOG_MISC1_TOG_IRQ_ANA_BO;
#undef CCM_ANALOG_MISC1_TOG_IRQ_TEMPHIGH
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1_TOG, 1, 29, true> CCM_ANALOG_MISC1_TOG_IRQ_TEMPHIGH;
#undef CCM_ANALOG_MISC1_TOG_IRQ_TEMPLOW
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1_TOG, 1, 28, true> CCM_ANALOG_MISC1_TOG_IRQ_TEMPLOW;
#undef CCM_ANALOG_MISC1_TOG_IRQ_TEMPPANIC
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1_TOG, 1, 27, true> CCM_ANALOG_MISC1_TOG_IRQ_TEMPPANIC;
#undef CCM_ANALOG_MISC1_TOG_PFD_528_AUTOGATE_EN
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1_TOG, 1, 17, true> CCM_ANALOG_MISC1_TOG_PFD_528_AUTOGATE_EN;
#undef CCM_ANALOG_MISC1_TOG_PFD_480_AUTOGATE_EN
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1_TOG, 1, 16, true> CCM_ANALOG_MISC1_TOG_PFD_480_AUTOGATE_EN;
#undef CCM_ANALOG_MISC1_TOG_LVDSCLK1_IBEN
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1_TOG, 1, 12, true> CCM_ANALOG_MISC1_TOG_LVDSCLK1_IBEN;
#undef CCM_ANALOG_MISC1_TOG_LVDSCLK1_OBEN
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1_TOG, 1, 10, true> CCM_ANALOG_MISC1_TOG_LVDSCLK1_OBEN;
#undef CCM_ANALOG_MISC1_TOG_LVDS1_CLK_SEL
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC1_TOG, 5,  0, true> CCM_ANALOG_MISC1_TOG_LVDS1_CLK_SEL;

// Miscellaneous Register 2
#undef CCM_ANALOG_MISC2_VIDEO_DIV
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2, 2, 30> CCM_ANALOG_MISC2_VIDEO_DIV;
    // 0b00..divide by 1 (Default)
    // 0b01..divide by 2
    // 0b10..divide by 1
    // 0b11..divide by 4
#undef CCM_ANALOG_MISC2_REG2_STEP_TIME
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2, 2, 28> CCM_ANALOG_MISC2_REG2_STEP_TIME;
    // 64 * 2^'value':
    // 0b00..64
    // 0b01..128
    // 0b10..256
    // 0b11..512
#undef CCM_ANALOG_MISC2_REG1_STEP_TIME
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2, 2, 26> CCM_ANALOG_MISC2_REG1_STEP_TIME;
    // 64 * 2^'value':
    // 0b00..64
    // 0b01..128
    // 0b10..256
    // 0b11..512
#undef CCM_ANALOG_MISC2_REG0_STEP_TIME
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2, 2, 24> CCM_ANALOG_MISC2_REG0_STEP_TIME;
    // 64 * 2^'value':
    // 0b00..64
    // 0b01..128
    // 0b10..256
    // 0b11..512
#undef CCM_ANALOG_MISC2_AUDIO_DIV_MSB
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2, 1, 23> CCM_ANALOG_MISC2_AUDIO_DIV_MSB;
    // 1/2^'value':
    // 0b0..divide by 1 (Default)
    // 0b1..divide by 2
#undef CCM_ANALOG_MISC2_REG2_OK
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2, 1, 22> CCM_ANALOG_MISC2_REG2_OK;
#undef CCM_ANALOG_MISC2_REG2_ENABLE_BO
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2, 1, 21> CCM_ANALOG_MISC2_REG2_ENABLE_BO;
#undef CCM_ANALOG_MISC2_REG2_BO_STATUS
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2, 1, 19> CCM_ANALOG_MISC2_REG2_BO_STATUS;
#undef CCM_ANALOG_MISC2_REG2_BO_OFFSET
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2, 3, 16> CCM_ANALOG_MISC2_REG2_BO_OFFSET;
    // 0b100..Brownout offset = 0.100V
    // 0b111..Brownout offset = 0.175V
#undef CCM_ANALOG_MISC2_AUDIO_DIV_LSB
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2, 1, 15> CCM_ANALOG_MISC2_AUDIO_DIV_LSB;
    // 1/2^'value':
    // 0b0..divide by 1 (Default)
    // 0b1..divide by 2
#undef CCM_ANALOG_MISC2_REG1_OK
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2, 1, 14> CCM_ANALOG_MISC2_REG1_OK;
#undef CCM_ANALOG_MISC2_REG1_ENABLE_BO
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2, 1, 13> CCM_ANALOG_MISC2_REG1_ENABLE_BO;
#undef CCM_ANALOG_MISC2_REG1_BO_STATUS
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2, 1, 11> CCM_ANALOG_MISC2_REG1_BO_STATUS;
    // 0b1..Brownout, supply is below target minus brownout offset.
#undef CCM_ANALOG_MISC2_REG1_BO_OFFSET
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2, 3,  8> CCM_ANALOG_MISC2_REG1_BO_OFFSET;
    // 0b100..Brownout offset = 0.100V
    // 0b111..Brownout offset = 0.175V
#undef CCM_ANALOG_MISC2_PLL3_DISABLE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2, 1,  7> CCM_ANALOG_MISC2_PLL3_DISABLE;
    // 0b0..PLL3 is being used by peripherals and is enabled when SoC is not in any low power mode
    // 0b1..PLL3 can be disabled when the SoC is not in any low power mode
#undef CCM_ANALOG_MISC2_REG0_OK
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2, 1,  6> CCM_ANALOG_MISC2_REG0_OK;
#undef CCM_ANALOG_MISC2_REG0_ENABLE_BO
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2, 1,  5> CCM_ANALOG_MISC2_REG0_ENABLE_BO;
#undef CCM_ANALOG_MISC2_REG0_BO_STATUS
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2, 1,  3> CCM_ANALOG_MISC2_REG0_BO_STATUS;
    // 0b1..Brownout, supply is below target minus brownout offset.
#undef CCM_ANALOG_MISC2_REG0_BO_OFFSET
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2, 3,  0> CCM_ANALOG_MISC2_REG0_BO_OFFSET;
    // 0b100..Brownout offset = 0.100V
    // 0b111..Brownout offset = 0.175V

// Miscellaneous Register 2
#undef CCM_ANALOG_MISC2_SET_VIDEO_DIV
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_SET, 2, 30, true> CCM_ANALOG_MISC2_SET_VIDEO_DIV;
#undef CCM_ANALOG_MISC2_SET_REG2_STEP_TIME
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_SET, 2, 28, true> CCM_ANALOG_MISC2_SET_REG2_STEP_TIME;
#undef CCM_ANALOG_MISC2_SET_REG1_STEP_TIME
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_SET, 2, 26, true> CCM_ANALOG_MISC2_SET_REG1_STEP_TIME;
#undef CCM_ANALOG_MISC2_SET_REG0_STEP_TIME
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_SET, 2, 24, true> CCM_ANALOG_MISC2_SET_REG0_STEP_TIME;
#undef CCM_ANALOG_MISC2_SET_AUDIO_DIV_MSB
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_SET, 1, 23, true> CCM_ANALOG_MISC2_SET_AUDIO_DIV_MSB;
#undef CCM_ANALOG_MISC2_SET_REG2_OK
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_SET, 1, 22, true> CCM_ANALOG_MISC2_SET_REG2_OK;
#undef CCM_ANALOG_MISC2_SET_REG2_ENABLE_BO
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_SET, 1, 21, true> CCM_ANALOG_MISC2_SET_REG2_ENABLE_BO;
#undef CCM_ANALOG_MISC2_SET_REG2_BO_STATUS
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_SET, 1, 19, true> CCM_ANALOG_MISC2_SET_REG2_BO_STATUS;
#undef CCM_ANALOG_MISC2_SET_REG2_BO_OFFSET
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_SET, 3, 16, true> CCM_ANALOG_MISC2_SET_REG2_BO_OFFSET;
#undef CCM_ANALOG_MISC2_SET_AUDIO_DIV_LSB
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_SET, 1, 15, true> CCM_ANALOG_MISC2_SET_AUDIO_DIV_LSB;
#undef CCM_ANALOG_MISC2_SET_REG1_OK
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_SET, 1, 14, true> CCM_ANALOG_MISC2_SET_REG1_OK;
#undef CCM_ANALOG_MISC2_SET_REG1_ENABLE_BO
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_SET, 1, 13, true> CCM_ANALOG_MISC2_SET_REG1_ENABLE_BO;
#undef CCM_ANALOG_MISC2_SET_REG1_BO_STATUS
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_SET, 1, 11, true> CCM_ANALOG_MISC2_SET_REG1_BO_STATUS;
#undef CCM_ANALOG_MISC2_SET_REG1_BO_OFFSET
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_SET, 3,  8, true> CCM_ANALOG_MISC2_SET_REG1_BO_OFFSET;
#undef CCM_ANALOG_MISC2_SET_PLL3_DISABLE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_SET, 1,  7, true> CCM_ANALOG_MISC2_SET_PLL3_DISABLE;
#undef CCM_ANALOG_MISC2_SET_REG0_OK
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_SET, 1,  6, true> CCM_ANALOG_MISC2_SET_REG0_OK;
#undef CCM_ANALOG_MISC2_SET_REG0_ENABLE_BO
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_SET, 1,  5, true> CCM_ANALOG_MISC2_SET_REG0_ENABLE_BO;
#undef CCM_ANALOG_MISC2_SET_REG0_BO_STATUS
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_SET, 1,  3, true> CCM_ANALOG_MISC2_SET_REG0_BO_STATUS;
#undef CCM_ANALOG_MISC2_SET_REG0_BO_OFFSET
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_SET, 3,  0, true> CCM_ANALOG_MISC2_SET_REG0_BO_OFFSET;

// Miscellaneous Register 2
#undef CCM_ANALOG_MISC2_CLR_VIDEO_DIV
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_CLR, 2, 30, true> CCM_ANALOG_MISC2_CLR_VIDEO_DIV;
#undef CCM_ANALOG_MISC2_CLR_REG2_STEP_TIME
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_CLR, 2, 28, true> CCM_ANALOG_MISC2_CLR_REG2_STEP_TIME;
#undef CCM_ANALOG_MISC2_CLR_REG1_STEP_TIME
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_CLR, 2, 26, true> CCM_ANALOG_MISC2_CLR_REG1_STEP_TIME;
#undef CCM_ANALOG_MISC2_CLR_REG0_STEP_TIME
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_CLR, 2, 24, true> CCM_ANALOG_MISC2_CLR_REG0_STEP_TIME;
#undef CCM_ANALOG_MISC2_CLR_AUDIO_DIV_MSB
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_CLR, 1, 23, true> CCM_ANALOG_MISC2_CLR_AUDIO_DIV_MSB;
#undef CCM_ANALOG_MISC2_CLR_REG2_OK
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_CLR, 1, 22, true> CCM_ANALOG_MISC2_CLR_REG2_OK;
#undef CCM_ANALOG_MISC2_CLR_REG2_ENABLE_BO
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_CLR, 1, 21, true> CCM_ANALOG_MISC2_CLR_REG2_ENABLE_BO;
#undef CCM_ANALOG_MISC2_CLR_REG2_BO_STATUS
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_CLR, 1, 19, true> CCM_ANALOG_MISC2_CLR_REG2_BO_STATUS;
#undef CCM_ANALOG_MISC2_CLR_REG2_BO_OFFSET
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_CLR, 3, 16, true> CCM_ANALOG_MISC2_CLR_REG2_BO_OFFSET;
#undef CCM_ANALOG_MISC2_CLR_AUDIO_DIV_LSB
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_CLR, 1, 15, true> CCM_ANALOG_MISC2_CLR_AUDIO_DIV_LSB;
#undef CCM_ANALOG_MISC2_CLR_REG1_OK
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_CLR, 1, 14, true> CCM_ANALOG_MISC2_CLR_REG1_OK;
#undef CCM_ANALOG_MISC2_CLR_REG1_ENABLE_BO
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_CLR, 1, 13, true> CCM_ANALOG_MISC2_CLR_REG1_ENABLE_BO;
#undef CCM_ANALOG_MISC2_CLR_REG1_BO_STATUS
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_CLR, 1, 11, true> CCM_ANALOG_MISC2_CLR_REG1_BO_STATUS;
#undef CCM_ANALOG_MISC2_CLR_REG1_BO_OFFSET
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_CLR, 3,  8, true> CCM_ANALOG_MISC2_CLR_REG1_BO_OFFSET;
#undef CCM_ANALOG_MISC2_CLR_PLL3_DISABLE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_CLR, 1,  7, true> CCM_ANALOG_MISC2_CLR_PLL3_DISABLE;
#undef CCM_ANALOG_MISC2_CLR_REG0_OK
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_CLR, 1,  6, true> CCM_ANALOG_MISC2_CLR_REG0_OK;
#undef CCM_ANALOG_MISC2_CLR_REG0_ENABLE_BO
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_CLR, 1,  5, true> CCM_ANALOG_MISC2_CLR_REG0_ENABLE_BO;
#undef CCM_ANALOG_MISC2_CLR_REG0_BO_STATUS
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_CLR, 1,  3, true> CCM_ANALOG_MISC2_CLR_REG0_BO_STATUS;
#undef CCM_ANALOG_MISC2_CLR_REG0_BO_OFFSET
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_CLR, 3,  0, true> CCM_ANALOG_MISC2_CLR_REG0_BO_OFFSET;

// Miscellaneous Register 2
#undef CCM_ANALOG_MISC2_TOG_VIDEO_DIV
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_TOG, 2, 30, true> CCM_ANALOG_MISC2_TOG_VIDEO_DIV;
#undef CCM_ANALOG_MISC2_TOG_REG2_STEP_TIME
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_TOG, 2, 28, true> CCM_ANALOG_MISC2_TOG_REG2_STEP_TIME;
#undef CCM_ANALOG_MISC2_TOG_REG1_STEP_TIME
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_TOG, 2, 26, true> CCM_ANALOG_MISC2_TOG_REG1_STEP_TIME;
#undef CCM_ANALOG_MISC2_TOG_REG0_STEP_TIME
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_TOG, 2, 24, true> CCM_ANALOG_MISC2_TOG_REG0_STEP_TIME;
#undef CCM_ANALOG_MISC2_TOG_AUDIO_DIV_MSB
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_TOG, 1, 23, true> CCM_ANALOG_MISC2_TOG_AUDIO_DIV_MSB;
#undef CCM_ANALOG_MISC2_TOG_REG2_OK
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_TOG, 1, 22, true> CCM_ANALOG_MISC2_TOG_REG2_OK;
#undef CCM_ANALOG_MISC2_TOG_REG2_ENABLE_BO
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_TOG, 1, 21, true> CCM_ANALOG_MISC2_TOG_REG2_ENABLE_BO;
#undef CCM_ANALOG_MISC2_TOG_REG2_BO_STATUS
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_TOG, 1, 19, true> CCM_ANALOG_MISC2_TOG_REG2_BO_STATUS;
#undef CCM_ANALOG_MISC2_TOG_REG2_BO_OFFSET
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_TOG, 3, 16, true> CCM_ANALOG_MISC2_TOG_REG2_BO_OFFSET;
#undef CCM_ANALOG_MISC2_TOG_AUDIO_DIV_LSB
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_TOG, 1, 15, true> CCM_ANALOG_MISC2_TOG_AUDIO_DIV_LSB;
#undef CCM_ANALOG_MISC2_TOG_REG1_OK
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_TOG, 1, 14, true> CCM_ANALOG_MISC2_TOG_REG1_OK;
#undef CCM_ANALOG_MISC2_TOG_REG1_ENABLE_BO
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_TOG, 1, 13, true> CCM_ANALOG_MISC2_TOG_REG1_ENABLE_BO;
#undef CCM_ANALOG_MISC2_TOG_REG1_BO_STATUS
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_TOG, 1, 11, true> CCM_ANALOG_MISC2_TOG_REG1_BO_STATUS;
#undef CCM_ANALOG_MISC2_TOG_REG1_BO_OFFSET
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_TOG, 3,  8, true> CCM_ANALOG_MISC2_TOG_REG1_BO_OFFSET;
#undef CCM_ANALOG_MISC2_TOG_PLL3_DISABLE
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_TOG, 1,  7, true> CCM_ANALOG_MISC2_TOG_PLL3_DISABLE;
#undef CCM_ANALOG_MISC2_TOG_REG0_OK
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_TOG, 1,  6, true> CCM_ANALOG_MISC2_TOG_REG0_OK;
#undef CCM_ANALOG_MISC2_TOG_REG0_ENABLE_BO
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_TOG, 1,  5, true> CCM_ANALOG_MISC2_TOG_REG0_ENABLE_BO;
#undef CCM_ANALOG_MISC2_TOG_REG0_BO_STATUS
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_TOG, 1,  3, true> CCM_ANALOG_MISC2_TOG_REG0_BO_STATUS;
#undef CCM_ANALOG_MISC2_TOG_REG0_BO_OFFSET
constexpr CCM_ANALOG_Reg<&CCM_ANALOG_Layout::MISC2_TOG, 3,  0, true> CCM_ANALOG_MISC2_TOG_REG0_BO_OFFSET;

// CCM_ANALOG_PLL_xxx_BYPASS_CLK_SRC values
constexpr uint32_t kCCM_ANALOG_PLL_xxx_BYPASS_CLK_SRC_24MHZ = 0;
constexpr uint32_t kCCM_ANALOG_PLL_xxx_BYPASS_CLK_SRC_CLK1  = 1;

// Analog ENET PLL Control Register values
constexpr uint32_t kCCM_ANALOG_PLL_ENET_ENET2_DIV_SELECT_25MHZ  = 0;
constexpr uint32_t kCCM_ANALOG_PLL_ENET_ENET2_DIV_SELECT_50MHZ  = 1;
constexpr uint32_t kCCM_ANALOG_PLL_ENET_ENET2_DIV_SELECT_100MHZ = 2;
constexpr uint32_t kCCM_ANALOG_PLL_ENET_ENET2_DIV_SELECT_125MHZ = 3;

// Miscellaneous Register 0 values
constexpr uint32_t kCCM_ANALOG_MISC0_REFTOP_VBGADJ_NOMINAL    = 0;
constexpr uint32_t kCCM_ANALOG_MISC0_REFTOP_VBGADJ_PLUS_0p78  = 1;
constexpr uint32_t kCCM_ANALOG_MISC0_REFTOP_VBGADJ_PLUS_1p56  = 2;
constexpr uint32_t kCCM_ANALOG_MISC0_REFTOP_VBGADJ_PLUS_2p34  = 3;
constexpr uint32_t kCCM_ANALOG_MISC0_REFTOP_VBGADJ_MINUS_0p78 = 4;
constexpr uint32_t kCCM_ANALOG_MISC0_REFTOP_VBGADJ_MINUS_1p56 = 5;
constexpr uint32_t kCCM_ANALOG_MISC0_REFTOP_VBGADJ_MINUS_2p34 = 6;
constexpr uint32_t kCCM_ANALOG_MISC0_REFTOP_VBGADJ_MINUS_3p12 = 7;
constexpr uint32_t kCCM_ANALOG_MISC0_RTC_XTAL_SOURCE_INTERNAL = 0;
constexpr uint32_t kCCM_ANALOG_MISC0_RTC_XTAL_SOURCE_XTAL     = 1;

}  // namespace teensy4
}  // namespace hardware
}  // namespace qindesign
