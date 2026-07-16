// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// USB.h defines all the USB registers.
// This file is part of the TeensyRegs library.

#pragma once

#include <cstddef>
#include <cstdint>

#include "hardware/regs/regs.h"

namespace qindesign {
namespace hardware {
namespace teensy4 {

constexpr size_t kUSB_ENDPTCTRL_count = 8;

// USB layout. Comments are from BSD-3-licensed NXP SDK.
//
// See:
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/periph/PERI_USB.h
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/MIMXRT1062/MIMXRT1062_COMMON.h
struct USB_Layout {
  const volatile uint32_t ID;                                /**< Identification register, offset: 0x0 */
  const volatile uint32_t HWGENERAL;                         /**< Hardware General, offset: 0x4 */
  const volatile uint32_t HWHOST;                            /**< Host Hardware Parameters, offset: 0x8 */
  const volatile uint32_t HWDEVICE;                          /**< Device Hardware Parameters, offset: 0xC */
  const volatile uint32_t HWTXBUF;                           /**< TX Buffer Hardware Parameters, offset: 0x10 */
  const volatile uint32_t HWRXBUF;                           /**< RX Buffer Hardware Parameters, offset: 0x14 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[26];
  volatile uint32_t GPTIMER0LD;                              /**< General Purpose Timer #0 Load, offset: 0x80 */
  volatile uint32_t GPTIMER0CTRL;                            /**< General Purpose Timer #0 Controller, offset: 0x84 */
  volatile uint32_t GPTIMER1LD;                              /**< General Purpose Timer #1 Load, offset: 0x88 */
  volatile uint32_t GPTIMER1CTRL;                            /**< General Purpose Timer #1 Controller, offset: 0x8C */
  volatile uint32_t SBUSCFG;                                 /**< System Bus Config, offset: 0x90 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[27];
  const volatile uint8_t CAPLENGTH;                          /**< Capability Registers Length, offset: 0x100 */
  uint8_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[1];
  const volatile uint16_t HCIVERSION;                        /**< Host Controller Interface Version, offset: 0x102 */
  const volatile uint32_t HCSPARAMS;                         /**< Host Controller Structural Parameters, offset: 0x104 */
  const volatile uint32_t HCCPARAMS;                         /**< Host Controller Capability Parameters, offset: 0x108 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[5];
  const volatile uint16_t DCIVERSION;                        /**< Device Controller Interface Version, offset: 0x120 */
  uint8_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[2];
  const volatile uint32_t DCCPARAMS;                         /**< Device Controller Capability Parameters, offset: 0x124 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[6];
  volatile uint32_t USBCMD;                                  /**< USB Command Register, offset: 0x140 */
  volatile uint32_t USBSTS;                                  /**< USB Status Register, offset: 0x144 */
  volatile uint32_t USBINTR;                                 /**< Interrupt Enable Register, offset: 0x148 */
  volatile uint32_t FRINDEX;                                 /**< USB Frame Index, offset: 0x14C */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[1];
  union {                                                /* offset: 0x154 */
    volatile uint32_t DEVICEADDR;                            /**< Device Address, offset: 0x154 */
    volatile uint32_t PERIODICLISTBASE;                      /**< Frame List Base Address, offset: 0x154 */
  };
  union {                                                /* offset: 0x158 */
    volatile uint32_t ASYNCLISTADDR;                         /**< Next Asynch. Address, offset: 0x158 */
    volatile uint32_t ENDPTLISTADDR;                         /**< Endpoint List Address, offset: 0x158 */
  };
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[1];
  volatile uint32_t BURSTSIZE;                               /**< Programmable Burst Size, offset: 0x160 */
  volatile uint32_t TXFILLTUNING;                            /**< TX FIFO Fill Tuning, offset: 0x164 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[4];
  volatile uint32_t ENDPTNAK;                                /**< Endpoint NAK, offset: 0x178 */
  volatile uint32_t ENDPTNAKEN;                              /**< Endpoint NAK Enable, offset: 0x17C */
  const volatile uint32_t CONFIGFLAG;                        /**< Configure Flag Register, offset: 0x180 */
  volatile uint32_t PORTSC1;                                 /**< Port Status & Control, offset: 0x184 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[7];
  volatile uint32_t OTGSC;                                   /**< On-The-Go Status & control, offset: 0x1A4 */
  volatile uint32_t USBMODE;                                 /**< USB Device Mode, offset: 0x1A8 */
  volatile uint32_t ENDPTSETUPSTAT;                          /**< Endpoint Setup Status, offset: 0x1AC */
  volatile uint32_t ENDPTPRIME;                              /**< Endpoint Prime, offset: 0x1B0 */
  volatile uint32_t ENDPTFLUSH;                              /**< Endpoint Flush, offset: 0x1B4 */
  const volatile uint32_t ENDPTSTAT;                         /**< Endpoint Status, offset: 0x1B8 */
  volatile uint32_t ENDPTCOMPLETE;                           /**< Endpoint Complete, offset: 0x1BC */
//   volatile uint32_t ENDPTCTRL0;                              /**< Endpoint Control0, offset: 0x1C0 */
//   volatile uint32_t ENDPTCTRL[kUSB_ENDPTCTRL_count];         /**< Endpoint Control 1..Endpoint Control 7, array offset: 0x1C4, array step: 0x4 */
  volatile uint32_t ENDPTCTRL[kUSB_ENDPTCTRL_count];         /**< Endpoint Control 0..Endpoint Control 7, array offset: 0x1C0, array step: 0x4 */
};

constexpr size_t    kUSB_size  = 0x1E0;
constexpr uintptr_t kUSB1_base = 0x402E0000;
constexpr uintptr_t kUSB2_base = 0x402E0200;

constexpr regs::RegGroup<USB_Layout, kUSB_size, kUSB1_base> USB1;
constexpr regs::RegGroup<USB_Layout, kUSB_size, kUSB2_base> USB2;

template <auto Member, size_t Bits, unsigned int Shift,
          bool DirectAssign = false>
using USB1_Reg =
    regs::Reg32<kUSB1_base, USB_Layout, Member, 0, Bits, Shift, DirectAssign>;

template <auto Member, size_t Bits, unsigned int Shift,
          bool DirectAssign = false>
using USB2_Reg =
    regs::Reg32<kUSB2_base, USB_Layout, Member, 0, Bits, Shift, DirectAssign>;

// Undefine anything defined by Teensyduino's imxrt.h

// USB1 Identification register
#undef USB1_ID_REVISION
constexpr USB1_Reg<&USB_Layout::ID, 8, 16> USB1_ID_REVISION;
#undef USB1_ID_NID
constexpr USB1_Reg<&USB_Layout::ID, 6,  8> USB1_ID_NID;
#undef USB1_ID_ID
constexpr USB1_Reg<&USB_Layout::ID, 6,  0> USB1_ID_ID;

// USB1 Hardware General
#undef USB1_HWGENERAL_SM
constexpr USB1_Reg<&USB_Layout::HWGENERAL, 2, 9> USB1_HWGENERAL_SM;
    // 0b00..No Serial Engine, always use parallel signalling.
    // 0b01..Serial Engine present, always use serial signalling for FS/LS.
    // 0b10..Software programmable - Reset to use parallel signalling for FS/LS
    // 0b11..Software programmable - Reset to use serial signalling for FS/LS
#undef USB1_HWGENERAL_PHYM
constexpr USB1_Reg<&USB_Layout::HWGENERAL, 3, 6> USB1_HWGENERAL_PHYM;
    // 0b000..UTMI/UMTI+
    // 0b001..ULPI DDR
    // 0b010..ULPI
    // 0b011..Serial Only
    // 0b100..Software programmable - reset to UTMI/UTMI+
    // 0b101..Software programmable - reset to ULPI DDR
    // 0b110..Software programmable - reset to ULPI
    // 0b111..Software programmable - reset to Serial
#undef USB1_HWGENERAL_PHYW
constexpr USB1_Reg<&USB_Layout::HWGENERAL, 2, 4> USB1_HWGENERAL_PHYW;
    // 0b00..8 bit wide data bus Software non-programmable
    // 0b01..16 bit wide data bus Software non-programmable
    // 0b10..Reset to 8 bit wide data bus Software programmable
    // 0b11..Reset to 16 bit wide data bus Software programmable

// USB1 Host Hardware Parameters
#undef USB1_HWHOST_NPORT
constexpr USB1_Reg<&USB_Layout::HWHOST, 3, 1> USB1_HWHOST_NPORT;
#undef USB1_HWHOST_HC
constexpr USB1_Reg<&USB_Layout::HWHOST, 1, 0> USB1_HWHOST_HC;
    // 0b0..Not supported
    // 0b1..Supported

// USB1 Device Hardware Parameters
#undef USB1_HWDEVICE_DEVEP
constexpr USB1_Reg<&USB_Layout::HWDEVICE, 5, 1> USB1_HWDEVICE_DEVEP;
#undef USB1_HWDEVICE_DC
constexpr USB1_Reg<&USB_Layout::HWDEVICE, 1, 0> USB1_HWDEVICE_DC;
    // 0b0..Not supported
    // 0b1..Supported

// USB1 TX Buffer Hardware Parameters
#undef USB1_HWTXBUF_TXCHANADD
constexpr USB1_Reg<&USB_Layout::HWTXBUF, 8, 16> USB1_HWTXBUF_TXCHANADD;
#undef USB1_HWTXBUF_TXBURST
constexpr USB1_Reg<&USB_Layout::HWTXBUF, 8,  0> USB1_HWTXBUF_TXBURST;

// USB1 RX Buffer Hardware Parameters
#undef USB1_HWRXBUF_RXADD
constexpr USB1_Reg<&USB_Layout::HWRXBUF, 8, 8> USB1_HWRXBUF_RXADD;
#undef USB1_HWRXBUF_RXBURST
constexpr USB1_Reg<&USB_Layout::HWRXBUF, 8, 0> USB1_HWRXBUF_RXBURST;

// USB1 General Purpose Timer #0 Load
#undef USB1_GPTIMER0LD_GPTLD
constexpr USB1_Reg<&USB_Layout::GPTIMER0LD, 24, 0> USB1_GPTIMER0LD_GPTLD;

// USB1 General Purpose Timer #0 Controller
#undef USB1_GPTIMER0CTRL_GPTRUN
constexpr USB1_Reg<&USB_Layout::GPTIMER0CTRL,  1, 31> USB1_GPTIMER0CTRL_GPTRUN;
    // 0b0..Stop counting
    // 0b1..Run
#undef USB1_GPTIMER0CTRL_GPTRST
constexpr USB1_Reg<&USB_Layout::GPTIMER0CTRL,  1, 30> USB1_GPTIMER0CTRL_GPTRST;
    // 0b0..No action
    // 0b1..Load counter value from GPTLD bits in n_GPTIMER0LD
#undef USB1_GPTIMER0CTRL_GPTMODE
constexpr USB1_Reg<&USB_Layout::GPTIMER0CTRL,  1, 24> USB1_GPTIMER0CTRL_GPTMODE;
    // 0b0..One Shot Mode
    // 0b1..Repeat Mode
#undef USB1_GPTIMER0CTRL_GPTCNT
constexpr USB1_Reg<&USB_Layout::GPTIMER0CTRL, 24,  0> USB1_GPTIMER0CTRL_GPTCNT;

// USB1 General Purpose Timer #1 Load
#undef USB1_GPTIMER1LD_GPTLD
constexpr USB1_Reg<&USB_Layout::GPTIMER1LD, 24,  0> USB1_GPTIMER1LD_GPTLD;

// USB1 General Purpose Timer #1 Controller
#undef USB1_GPTIMER1CTRL_GPTRUN
constexpr USB1_Reg<&USB_Layout::GPTIMER1CTRL,  1, 31> USB1_GPTIMER1CTRL_GPTRUN;
    // 0b0..Stop counting
    // 0b1..Run
#undef USB1_GPTIMER1CTRL_GPTRST
constexpr USB1_Reg<&USB_Layout::GPTIMER1CTRL,  1, 30> USB1_GPTIMER1CTRL_GPTRST;
    // 0b0..No action
    // 0b1..Load counter value from GPTLD bits in USB_n_GPTIMER0LD
#undef USB1_GPTIMER1CTRL_GPTMODE
constexpr USB1_Reg<&USB_Layout::GPTIMER1CTRL,  1, 24> USB1_GPTIMER1CTRL_GPTMODE;
    // 0b0..One Shot Mode
    // 0b1..Repeat Mode
#undef USB1_GPTIMER1CTRL_GPTCNT
constexpr USB1_Reg<&USB_Layout::GPTIMER1CTRL, 24,  0> USB1_GPTIMER1CTRL_GPTCNT;

// USB1 System Bus Config
#undef USB1_SBUSCFG_AHBBRST
constexpr USB1_Reg<&USB_Layout::SBUSCFG, 3, 0> USB1_SBUSCFG_AHBBRST;
    // 0b000..Incremental burst of unspecified length only
    // 0b001..INCR4 burst, then single transfer
    // 0b010..INCR8 burst, INCR4 burst, then single transfer
    // 0b011..INCR16 burst, INCR8 burst, INCR4 burst, then single transfer
    // 0b100..Reserved, don't use
    // 0b101..INCR4 burst, then incremental burst of unspecified length
    // 0b110..INCR8 burst, INCR4 burst, then incremental burst of unspecified length
    // 0b111..INCR16 burst, INCR8 burst, INCR4 burst, then incremental burst of unspecified length

// USB1 Host Controller Structural Parameters
#undef USB1_HCSPARAMS_N_TT
constexpr USB1_Reg<&USB_Layout::HCSPARAMS, 4, 24> USB1_HCSPARAMS_N_TT;
#undef USB1_HCSPARAMS_N_PTT
constexpr USB1_Reg<&USB_Layout::HCSPARAMS, 4, 20> USB1_HCSPARAMS_N_PTT;
#undef USB1_HCSPARAMS_PI
constexpr USB1_Reg<&USB_Layout::HCSPARAMS, 1, 16> USB1_HCSPARAMS_PI;
#undef USB1_HCSPARAMS_N_CC
constexpr USB1_Reg<&USB_Layout::HCSPARAMS, 4, 12> USB1_HCSPARAMS_N_CC;
    // 0b0000..There is no internal Companion Controller and port-ownership hand-off is not supported.
    // 0b0001..There are internal companion controller(s) and port-ownership hand-offs is supported.
#undef USB1_HCSPARAMS_N_PCC
constexpr USB1_Reg<&USB_Layout::HCSPARAMS, 4,  8> USB1_HCSPARAMS_N_PCC;
#undef USB1_HCSPARAMS_PPC
constexpr USB1_Reg<&USB_Layout::HCSPARAMS, 1,  4> USB1_HCSPARAMS_PPC;
#undef USB1_HCSPARAMS_N_PORTS
constexpr USB1_Reg<&USB_Layout::HCSPARAMS, 4,  0> USB1_HCSPARAMS_N_PORTS;

// USB1 Host Controller Capability Parameters
#undef USB1_HCCPARAMS_EECP
constexpr USB1_Reg<&USB_Layout::HCCPARAMS, 8, 8> USB1_HCCPARAMS_EECP;
#undef USB1_HCCPARAMS_IST
constexpr USB1_Reg<&USB_Layout::HCCPARAMS, 4, 4> USB1_HCCPARAMS_IST;
#undef USB1_HCCPARAMS_ASP
constexpr USB1_Reg<&USB_Layout::HCCPARAMS, 1, 2> USB1_HCCPARAMS_ASP;
#undef USB1_HCCPARAMS_PFL
constexpr USB1_Reg<&USB_Layout::HCCPARAMS, 1, 1> USB1_HCCPARAMS_PFL;
#undef USB1_HCCPARAMS_ADC
constexpr USB1_Reg<&USB_Layout::HCCPARAMS, 1, 0> USB1_HCCPARAMS_ADC;

// USB1 Device Controller Capability Parameters
#undef USB1_DCCPARAMS_HC
constexpr USB1_Reg<&USB_Layout::DCCPARAMS, 1, 8> USB1_DCCPARAMS_HC;
#undef USB1_DCCPARAMS_DC
constexpr USB1_Reg<&USB_Layout::DCCPARAMS, 1, 7> USB1_DCCPARAMS_DC;
#undef USB1_DCCPARAMS_DEN
constexpr USB1_Reg<&USB_Layout::DCCPARAMS, 5, 0> USB1_DCCPARAMS_DEN;

// USB1 USB Command Register
#undef USB1_USBCMD_ITC
constexpr USB1_Reg<&USB_Layout::USBCMD, 8, 16> USB1_USBCMD_ITC;
    // 0b00000000..Immediate (no threshold)
    // 0b00000001..1 micro-frame
    // 0b00000010..2 micro-frames
    // 0b00000100..4 micro-frames
    // 0b00001000..8 micro-frames
    // 0b00010000..16 micro-frames
    // 0b00100000..32 micro-frames
    // 0b01000000..64 micro-frames
#undef USB1_USBCMD_FS_2
constexpr USB1_Reg<&USB_Layout::USBCMD, 1, 15> USB1_USBCMD_FS_2;
    // 0b0..1024 elements (4096 bytes) Default value
    // 0b1..512 elements (2048 bytes)
#undef USB1_USBCMD_ATDTW
constexpr USB1_Reg<&USB_Layout::USBCMD, 1, 14> USB1_USBCMD_ATDTW;
#undef USB1_USBCMD_SUTW
constexpr USB1_Reg<&USB_Layout::USBCMD, 1, 13> USB1_USBCMD_SUTW;
#undef USB1_USBCMD_ASPE
constexpr USB1_Reg<&USB_Layout::USBCMD, 1, 11> USB1_USBCMD_ASPE;
#undef USB1_USBCMD_ASP
constexpr USB1_Reg<&USB_Layout::USBCMD, 2,  8> USB1_USBCMD_ASP;
#undef USB1_USBCMD_IAA
constexpr USB1_Reg<&USB_Layout::USBCMD, 1,  6> USB1_USBCMD_IAA;
#undef USB1_USBCMD_ASE
constexpr USB1_Reg<&USB_Layout::USBCMD, 1,  5> USB1_USBCMD_ASE;
    // 0b0..Do not process the Asynchronous Schedule.
    // 0b1..Use the ASYNCLISTADDR register to access the Asynchronous Schedule.
#undef USB1_USBCMD_PSE
constexpr USB1_Reg<&USB_Layout::USBCMD, 1,  4> USB1_USBCMD_PSE;
    // 0b0..Do not process the Periodic Schedule
    // 0b1..Use the PERIODICLISTBASE register to access the Periodic Schedule.
#undef USB1_USBCMD_FS_1
constexpr USB1_Reg<&USB_Layout::USBCMD, 2,  2> USB1_USBCMD_FS_1;
#undef USB1_USBCMD_RST
constexpr USB1_Reg<&USB_Layout::USBCMD, 1,  1> USB1_USBCMD_RST;
#undef USB1_USBCMD_RS
constexpr USB1_Reg<&USB_Layout::USBCMD, 1,  0> USB1_USBCMD_RS;

// USB1 USB Status Register
#undef USB1_USBSTS_TI1
constexpr USB1_Reg<&USB_Layout::USBSTS, 1, 25> USB1_USBSTS_TI1;
#undef USB1_USBSTS_TI0
constexpr USB1_Reg<&USB_Layout::USBSTS, 1, 24> USB1_USBSTS_TI0;
#undef USB1_USBSTS_NAKI
constexpr USB1_Reg<&USB_Layout::USBSTS, 1, 16> USB1_USBSTS_NAKI;
#undef USB1_USBSTS_AS
constexpr USB1_Reg<&USB_Layout::USBSTS, 1, 15> USB1_USBSTS_AS;
#undef USB1_USBSTS_PS
constexpr USB1_Reg<&USB_Layout::USBSTS, 1, 14> USB1_USBSTS_PS;
#undef USB1_USBSTS_RCL
constexpr USB1_Reg<&USB_Layout::USBSTS, 1, 13> USB1_USBSTS_RCL;
#undef USB1_USBSTS_HCH
constexpr USB1_Reg<&USB_Layout::USBSTS, 1, 12> USB1_USBSTS_HCH;
#undef USB1_USBSTS_ULPII
constexpr USB1_Reg<&USB_Layout::USBSTS, 1, 10> USB1_USBSTS_ULPII;
#undef USB1_USBSTS_SLI
constexpr USB1_Reg<&USB_Layout::USBSTS, 1,  8> USB1_USBSTS_SLI;
#undef USB1_USBSTS_SRI
constexpr USB1_Reg<&USB_Layout::USBSTS, 1,  7> USB1_USBSTS_SRI;
#undef USB1_USBSTS_URI
constexpr USB1_Reg<&USB_Layout::USBSTS, 1,  6> USB1_USBSTS_URI;
#undef USB1_USBSTS_AAI
constexpr USB1_Reg<&USB_Layout::USBSTS, 1,  5> USB1_USBSTS_AAI;
#undef USB1_USBSTS_SEI
constexpr USB1_Reg<&USB_Layout::USBSTS, 1,  4> USB1_USBSTS_SEI;
#undef USB1_USBSTS_FRI
constexpr USB1_Reg<&USB_Layout::USBSTS, 1,  3> USB1_USBSTS_FRI;
#undef USB1_USBSTS_PCI
constexpr USB1_Reg<&USB_Layout::USBSTS, 1,  2> USB1_USBSTS_PCI;
#undef USB1_USBSTS_UEI
constexpr USB1_Reg<&USB_Layout::USBSTS, 1,  1> USB1_USBSTS_UEI;
#undef USB1_USBSTS_UI
constexpr USB1_Reg<&USB_Layout::USBSTS, 1,  0> USB1_USBSTS_UI;

// USB1 Interrupt Enable Register
#undef USB1_USBINTR_TIE1
constexpr USB1_Reg<&USB_Layout::USBINTR, 1, 25> USB1_USBINTR_TIE1;
#undef USB1_USBINTR_TIE0
constexpr USB1_Reg<&USB_Layout::USBINTR, 1, 24> USB1_USBINTR_TIE0;
#undef USB1_USBINTR_UPIE
constexpr USB1_Reg<&USB_Layout::USBINTR, 1, 19> USB1_USBINTR_UPIE;
#undef USB1_USBINTR_UAIE
constexpr USB1_Reg<&USB_Layout::USBINTR, 1, 18> USB1_USBINTR_UAIE;
#undef USB1_USBINTR_NAKE
constexpr USB1_Reg<&USB_Layout::USBINTR, 1, 16> USB1_USBINTR_NAKE;
#undef USB1_USBINTR_ULPIE
constexpr USB1_Reg<&USB_Layout::USBINTR, 1, 10> USB1_USBINTR_ULPIE;
#undef USB1_USBINTR_SLE
constexpr USB1_Reg<&USB_Layout::USBINTR, 1,  8> USB1_USBINTR_SLE;
#undef USB1_USBINTR_SRE
constexpr USB1_Reg<&USB_Layout::USBINTR, 1,  7> USB1_USBINTR_SRE;
#undef USB1_USBINTR_URE
constexpr USB1_Reg<&USB_Layout::USBINTR, 1,  6> USB1_USBINTR_URE;
#undef USB1_USBINTR_AAE
constexpr USB1_Reg<&USB_Layout::USBINTR, 1,  5> USB1_USBINTR_AAE;
#undef USB1_USBINTR_SEE
constexpr USB1_Reg<&USB_Layout::USBINTR, 1,  4> USB1_USBINTR_SEE;
#undef USB1_USBINTR_FRE
constexpr USB1_Reg<&USB_Layout::USBINTR, 1,  3> USB1_USBINTR_FRE;
#undef USB1_USBINTR_PCE
constexpr USB1_Reg<&USB_Layout::USBINTR, 1,  2> USB1_USBINTR_PCE;
#undef USB1_USBINTR_UEE
constexpr USB1_Reg<&USB_Layout::USBINTR, 1,  1> USB1_USBINTR_UEE;
#undef USB1_USBINTR_UE
constexpr USB1_Reg<&USB_Layout::USBINTR, 1,  0> USB1_USBINTR_UE;

// USB1 USB Frame Index
#undef USB1_FRINDEX_FRINDEX
constexpr USB1_Reg<&USB_Layout::FRINDEX, 14, 0> USB1_FRINDEX_FRINDEX;
    // 0b00000000000000..(1024) 12
    // 0b00000000000001..(512) 11
    // 0b00000000000010..(256) 10
    // 0b00000000000011..(128) 9
    // 0b00000000000100..(64) 8
    // 0b00000000000101..(32) 7
    // 0b00000000000110..(16) 6
    // 0b00000000000111..(8) 5

// USB1 Device Address
#undef USB1_DEVICEADDR_USBADR
constexpr USB1_Reg<&USB_Layout::DEVICEADDR, 7, 25> USB1_DEVICEADDR_USBADR;
#undef USB1_DEVICEADDR_USBADRA
constexpr USB1_Reg<&USB_Layout::DEVICEADDR, 1, 24> USB1_DEVICEADDR_USBADRA;

// USB1 Frame List Base Address
#undef USB1_PERIODICLISTBASE_BASEADR
constexpr USB1_Reg<&USB_Layout::PERIODICLISTBASE, 20, 12> USB1_PERIODICLISTBASE_BASEADR;

// USB1 Next Asynch. Address
#undef USB1_ASYNCLISTADDR_ASYBASE
constexpr USB1_Reg<&USB_Layout::ASYNCLISTADDR, 27, 5> USB1_ASYNCLISTADDR_ASYBASE;

// USB1 Endpoint List Address
#undef USB1_ENDPTLISTADDR_EPBASE
constexpr USB1_Reg<&USB_Layout::ENDPTLISTADDR, 21, 11> USB1_ENDPTLISTADDR_EPBASE;

// USB1 Programmable Burst Size
#undef USB1_BURSTSIZE_TXPBURST
constexpr USB1_Reg<&USB_Layout::BURSTSIZE, 9, 8> USB1_BURSTSIZE_TXPBURST;
#undef USB1_BURSTSIZE_RXPBURST
constexpr USB1_Reg<&USB_Layout::BURSTSIZE, 8, 0> USB1_BURSTSIZE_RXPBURST;

// USB1 TX FIFO Fill Tuning
#undef USB1_TXFILLTUNING_TXFIFOTHRES
constexpr USB1_Reg<&USB_Layout::TXFILLTUNING, 6, 16> USB1_TXFILLTUNING_TXFIFOTHRES;
#undef USB1_TXFILLTUNING_TXSCHHEALTH
constexpr USB1_Reg<&USB_Layout::TXFILLTUNING, 5,  8> USB1_TXFILLTUNING_TXSCHHEALTH;
#undef USB1_TXFILLTUNING_TXSCHOH
constexpr USB1_Reg<&USB_Layout::TXFILLTUNING, 8,  0> USB1_TXFILLTUNING_TXSCHOH;

// USB1 Endpoint NAK
#undef USB1_ENDPTNAK_EPTN
constexpr USB1_Reg<&USB_Layout::ENDPTNAK, 8, 16> USB1_ENDPTNAK_EPTN;
#undef USB1_ENDPTNAK_EPRN
constexpr USB1_Reg<&USB_Layout::ENDPTNAK, 8,  0> USB1_ENDPTNAK_EPRN;

// USB1 Endpoint NAK Enable
#undef USB1_ENDPTNAKEN_EPTNE
constexpr USB1_Reg<&USB_Layout::ENDPTNAKEN, 8, 16> USB1_ENDPTNAKEN_EPTNE;
#undef USB1_ENDPTNAKEN_EPRNE
constexpr USB1_Reg<&USB_Layout::ENDPTNAKEN, 8,  0> USB1_ENDPTNAKEN_EPRNE;

// USB1 Configure Flag Register
#undef USB1_CONFIGFLAG_CF
constexpr USB1_Reg<&USB_Layout::CONFIGFLAG, 1, 0> USB1_CONFIGFLAG_CF;
    // 0b0..Port routing control logic default-routes each port to an implementation dependent classic host controller.
    // 0b1..Port routing control logic default-routes all ports to this host controller.

// USB1 Port Status & Control
#undef USB1_PORTSC1_PTS_1
constexpr USB1_Reg<&USB_Layout::PORTSC1, 2, 30> USB1_PORTSC1_PTS_1;
#undef USB1_PORTSC1_STS
constexpr USB1_Reg<&USB_Layout::PORTSC1, 1, 29> USB1_PORTSC1_STS;
#undef USB1_PORTSC1_PTW
constexpr USB1_Reg<&USB_Layout::PORTSC1, 1, 28> USB1_PORTSC1_PTW;
    // 0b0..Select the 8-bit UTMI interface [60MHz]
    // 0b1..Select the 16-bit UTMI interface [30MHz]
#undef USB1_PORTSC1_PSPD
constexpr USB1_Reg<&USB_Layout::PORTSC1, 2, 26> USB1_PORTSC1_PSPD;
    // 0b00..Full Speed
    // 0b01..Low Speed
    // 0b10..High Speed
    // 0b11..Undefined
#undef USB1_PORTSC1_PTS_2
constexpr USB1_Reg<&USB_Layout::PORTSC1, 1, 25> USB1_PORTSC1_PTS_2;
#undef USB1_PORTSC1_PFSC
constexpr USB1_Reg<&USB_Layout::PORTSC1, 1, 24> USB1_PORTSC1_PFSC;
    // 0b0..Normal operation
    // 0b1..Forced to full speed
#undef USB1_PORTSC1_PHCD
constexpr USB1_Reg<&USB_Layout::PORTSC1, 1, 23> USB1_PORTSC1_PHCD;
    // 0b0..Enable PHY clock
    // 0b1..Disable PHY clock
#undef USB1_PORTSC1_WKOC
constexpr USB1_Reg<&USB_Layout::PORTSC1, 1, 22> USB1_PORTSC1_WKOC;
#undef USB1_PORTSC1_WKDC
constexpr USB1_Reg<&USB_Layout::PORTSC1, 1, 21> USB1_PORTSC1_WKDC;
#undef USB1_PORTSC1_WKCN
constexpr USB1_Reg<&USB_Layout::PORTSC1, 1, 20> USB1_PORTSC1_WKCN;
#undef USB1_PORTSC1_PTC
constexpr USB1_Reg<&USB_Layout::PORTSC1, 4, 16> USB1_PORTSC1_PTC;
    // 0b0000..TEST_MODE_DISABLE
    // 0b0001..J_STATE
    // 0b0010..K_STATE
    // 0b0011..SE0 (host) / NAK (device)
    // 0b0100..Packet
    // 0b0101..FORCE_ENABLE_HS
    // 0b0110..FORCE_ENABLE_FS
    // 0b0111..FORCE_ENABLE_LS
    // 0b1000-0b1111..Reserved
#undef USB1_PORTSC1_PIC
constexpr USB1_Reg<&USB_Layout::PORTSC1, 2, 14> USB1_PORTSC1_PIC;
    // 0b00..Port indicators are off
    // 0b01..Amber
    // 0b10..Green
    // 0b11..Undefined
#undef USB1_PORTSC1_PO
constexpr USB1_Reg<&USB_Layout::PORTSC1, 1, 13> USB1_PORTSC1_PO;
#undef USB1_PORTSC1_PP
constexpr USB1_Reg<&USB_Layout::PORTSC1, 1, 12> USB1_PORTSC1_PP;
#undef USB1_PORTSC1_LS
constexpr USB1_Reg<&USB_Layout::PORTSC1, 2, 10> USB1_PORTSC1_LS;
    // 0b00..SE0
    // 0b01..K-state
    // 0b10..J-state
    // 0b11..Undefined
#undef USB1_PORTSC1_HSP
constexpr USB1_Reg<&USB_Layout::PORTSC1, 1, 9> USB1_PORTSC1_HSP;
#undef USB1_PORTSC1_PR
constexpr USB1_Reg<&USB_Layout::PORTSC1, 1, 8> USB1_PORTSC1_PR;
#undef USB1_PORTSC1_SUSP
constexpr USB1_Reg<&USB_Layout::PORTSC1, 1, 7> USB1_PORTSC1_SUSP;
#undef USB1_PORTSC1_FPR
constexpr USB1_Reg<&USB_Layout::PORTSC1, 1, 6> USB1_PORTSC1_FPR;
#undef USB1_PORTSC1_OCC
constexpr USB1_Reg<&USB_Layout::PORTSC1, 1, 5> USB1_PORTSC1_OCC;
#undef USB1_PORTSC1_OCA
constexpr USB1_Reg<&USB_Layout::PORTSC1, 1, 4> USB1_PORTSC1_OCA;
    // 0b0..This port does not have an over-current condition.
    // 0b1..This port currently has an over-current condition
#undef USB1_PORTSC1_PEC
constexpr USB1_Reg<&USB_Layout::PORTSC1, 1, 3> USB1_PORTSC1_PEC;
#undef USB1_PORTSC1_PE
constexpr USB1_Reg<&USB_Layout::PORTSC1, 1, 2> USB1_PORTSC1_PE;
#undef USB1_PORTSC1_CSC
constexpr USB1_Reg<&USB_Layout::PORTSC1, 1, 1> USB1_PORTSC1_CSC;
#undef USB1_PORTSC1_CCS
constexpr USB1_Reg<&USB_Layout::PORTSC1, 1, 0> USB1_PORTSC1_CCS;

// USB1 On-The-Go Status & control
#undef USB1_OTGSC_DPIE
constexpr USB1_Reg<&USB_Layout::OTGSC, 1, 30> USB1_OTGSC_DPIE;
#undef USB1_OTGSC_EN_1MS
constexpr USB1_Reg<&USB_Layout::OTGSC, 1, 29> USB1_OTGSC_EN_1MS;
#undef USB1_OTGSC_BSEIE
constexpr USB1_Reg<&USB_Layout::OTGSC, 1, 28> USB1_OTGSC_BSEIE;
#undef USB1_OTGSC_BSVIE
constexpr USB1_Reg<&USB_Layout::OTGSC, 1, 27> USB1_OTGSC_BSVIE;
#undef USB1_OTGSC_ASVIE
constexpr USB1_Reg<&USB_Layout::OTGSC, 1, 26> USB1_OTGSC_ASVIE;
#undef USB1_OTGSC_AVVIE
constexpr USB1_Reg<&USB_Layout::OTGSC, 1, 25> USB1_OTGSC_AVVIE;
#undef USB1_OTGSC_IDIE
constexpr USB1_Reg<&USB_Layout::OTGSC, 1, 24> USB1_OTGSC_IDIE;
#undef USB1_OTGSC_DPIS
constexpr USB1_Reg<&USB_Layout::OTGSC, 1, 22> USB1_OTGSC_DPIS;
#undef USB1_OTGSC_STATUS_1MS
constexpr USB1_Reg<&USB_Layout::OTGSC, 1, 21> USB1_OTGSC_STATUS_1MS;
#undef USB1_OTGSC_BSEIS
constexpr USB1_Reg<&USB_Layout::OTGSC, 1, 20> USB1_OTGSC_BSEIS;
#undef USB1_OTGSC_BSVIS
constexpr USB1_Reg<&USB_Layout::OTGSC, 1, 19> USB1_OTGSC_BSVIS;
#undef USB1_OTGSC_ASVIS
constexpr USB1_Reg<&USB_Layout::OTGSC, 1, 18> USB1_OTGSC_ASVIS;
#undef USB1_OTGSC_AVVIS
constexpr USB1_Reg<&USB_Layout::OTGSC, 1, 17> USB1_OTGSC_AVVIS;
#undef USB1_OTGSC_IDIS
constexpr USB1_Reg<&USB_Layout::OTGSC, 1, 16> USB1_OTGSC_IDIS;
#undef USB1_OTGSC_DPS
constexpr USB1_Reg<&USB_Layout::OTGSC, 1, 14> USB1_OTGSC_DPS;
#undef USB1_OTGSC_TOG_1MS
constexpr USB1_Reg<&USB_Layout::OTGSC, 1, 13> USB1_OTGSC_TOG_1MS;
#undef USB1_OTGSC_BSE
constexpr USB1_Reg<&USB_Layout::OTGSC, 1, 12> USB1_OTGSC_BSE;
#undef USB1_OTGSC_BSV
constexpr USB1_Reg<&USB_Layout::OTGSC, 1, 11> USB1_OTGSC_BSV;
#undef USB1_OTGSC_ASV
constexpr USB1_Reg<&USB_Layout::OTGSC, 1, 10> USB1_OTGSC_ASV;
#undef USB1_OTGSC_AVV
constexpr USB1_Reg<&USB_Layout::OTGSC, 1,  9> USB1_OTGSC_AVV;
#undef USB1_OTGSC_ID
constexpr USB1_Reg<&USB_Layout::OTGSC, 1,  8> USB1_OTGSC_ID;
#undef USB1_OTGSC_IDPU
constexpr USB1_Reg<&USB_Layout::OTGSC, 1,  5> USB1_OTGSC_IDPU;
#undef USB1_OTGSC_DP
constexpr USB1_Reg<&USB_Layout::OTGSC, 1,  4> USB1_OTGSC_DP;
#undef USB1_OTGSC_OT
constexpr USB1_Reg<&USB_Layout::OTGSC, 1,  3> USB1_OTGSC_OT;
#undef USB1_OTGSC_VC
constexpr USB1_Reg<&USB_Layout::OTGSC, 1,  1> USB1_OTGSC_VC;
#undef USB1_OTGSC_VD
constexpr USB1_Reg<&USB_Layout::OTGSC, 1,  0> USB1_OTGSC_VD;

// USB1 USB Device Mode
#undef USB1_USBMODE_SDIS
constexpr USB1_Reg<&USB_Layout::USBMODE, 1, 4> USB1_USBMODE_SDIS;
#undef USB1_USBMODE_SLOM
constexpr USB1_Reg<&USB_Layout::USBMODE, 1, 3> USB1_USBMODE_SLOM;
    // 0b0..Setup Lockouts On (default);
    // 0b1..Setup Lockouts Off (DCD requires use of Setup Data Buffer Tripwire in USBCMDUSB Command Register .
#undef USB1_USBMODE_ES
constexpr USB1_Reg<&USB_Layout::USBMODE, 1, 2> USB1_USBMODE_ES;
    // 0b0..Little Endian [Default]
    // 0b1..Big Endian
#undef USB1_USBMODE_CM
constexpr USB1_Reg<&USB_Layout::USBMODE, 2, 0> USB1_USBMODE_CM;
    // 0b00..Idle [Default for combination host/device]
    // 0b01..Reserved
    // 0b10..Device Controller [Default for device only controller]
    // 0b11..Host Controller [Default for host only controller]

// USB1 Endpoint Setup Status
#undef USB1_ENDPTSETUPSTAT_ENDPTSETUPSTAT
constexpr USB1_Reg<&USB_Layout::ENDPTSETUPSTAT, 16, 0> USB1_ENDPTSETUPSTAT_ENDPTSETUPSTAT;

// USB1 Endpoint Prime
#undef USB1_ENDPTPRIME_PETB
constexpr USB1_Reg<&USB_Layout::ENDPTPRIME, 8, 16> USB1_ENDPTPRIME_PETB;
#undef USB1_ENDPTPRIME_PERB
constexpr USB1_Reg<&USB_Layout::ENDPTPRIME, 8,  0> USB1_ENDPTPRIME_PERB;

// USB1 Endpoint Flush
#undef USB1_ENDPTFLUSH_FETB
constexpr USB1_Reg<&USB_Layout::ENDPTFLUSH, 8, 16> USB1_ENDPTFLUSH_FETB;
#undef USB1_ENDPTFLUSH_FERB
constexpr USB1_Reg<&USB_Layout::ENDPTFLUSH, 8,  0> USB1_ENDPTFLUSH_FERB;

// USB1 Endpoint Status
#undef USB1_ENDPTSTAT_ETBR
constexpr USB1_Reg<&USB_Layout::ENDPTSTAT, 8, 16> USB1_ENDPTSTAT_ETBR;
#undef USB1_ENDPTSTAT_ERBR
constexpr USB1_Reg<&USB_Layout::ENDPTSTAT, 8,  0> USB1_ENDPTSTAT_ERBR;

// USB1 Endpoint Complete
#undef USB1_ENDPTCOMPLETE_ETCE
constexpr USB1_Reg<&USB_Layout::ENDPTCOMPLETE, 8, 16> USB1_ENDPTCOMPLETE_ETCE;
#undef USB1_ENDPTCOMPLETE_ERCE
constexpr USB1_Reg<&USB_Layout::ENDPTCOMPLETE, 8,  0> USB1_ENDPTCOMPLETE_ERCE;

// Endpoint Control values
#undef USB_ENDPTCTRL_TXE
constexpr regs::RegValue32<1, 23> USB_ENDPTCTRL_TXE;
#undef USB_ENDPTCTRL_TXR
constexpr regs::RegValue32<1, 22> USB_ENDPTCTRL_TXR;
#undef USB_ENDPTCTRL_TXI
constexpr regs::RegValue32<1, 21> USB_ENDPTCTRL_TXI;
#undef USB_ENDPTCTRL_TXT
constexpr regs::RegValue32<2, 18> USB_ENDPTCTRL_TXT;
#undef USB_ENDPTCTRL_TXD
constexpr regs::RegValue32<1, 17> USB_ENDPTCTRL_TXD;
#undef USB_ENDPTCTRL_TXS
constexpr regs::RegValue32<1, 16> USB_ENDPTCTRL_TXS;
#undef USB_ENDPTCTRL_RXE
constexpr regs::RegValue32<1,  7> USB_ENDPTCTRL_RXE;
#undef USB_ENDPTCTRL_RXR
constexpr regs::RegValue32<1,  6> USB_ENDPTCTRL_RXR;
#undef USB_ENDPTCTRL_RXI
constexpr regs::RegValue32<1,  5> USB_ENDPTCTRL_RXI;
#undef USB_ENDPTCTRL_RXT
constexpr regs::RegValue32<2,  2> USB_ENDPTCTRL_RXT;
#undef USB_ENDPTCTRL_RXD
constexpr regs::RegValue32<1,  1> USB_ENDPTCTRL_RXD;
#undef USB_ENDPTCTRL_RXS
constexpr regs::RegValue32<1,  0> USB_ENDPTCTRL_RXS;

// USB2 Identification register
#undef USB2_ID_REVISION
constexpr USB2_Reg<&USB_Layout::ID, 8, 16> USB2_ID_REVISION;
#undef USB2_ID_NID
constexpr USB2_Reg<&USB_Layout::ID, 6,  8> USB2_ID_NID;
#undef USB2_ID_ID
constexpr USB2_Reg<&USB_Layout::ID, 6,  0> USB2_ID_ID;

// USB2 Hardware General
#undef USB2_HWGENERAL_SM
constexpr USB2_Reg<&USB_Layout::HWGENERAL, 2, 9> USB2_HWGENERAL_SM;
#undef USB2_HWGENERAL_PHYM
constexpr USB2_Reg<&USB_Layout::HWGENERAL, 3, 6> USB2_HWGENERAL_PHYM;
#undef USB2_HWGENERAL_PHYW
constexpr USB2_Reg<&USB_Layout::HWGENERAL, 2, 4> USB2_HWGENERAL_PHYW;

// USB2 Host Hardware Parameters
#undef USB2_HWHOST_NPORT
constexpr USB2_Reg<&USB_Layout::HWHOST, 3, 1> USB2_HWHOST_NPORT;
#undef USB2_HWHOST_HC
constexpr USB2_Reg<&USB_Layout::HWHOST, 1, 0> USB2_HWHOST_HC;

// USB2 Device Hardware Parameters
#undef USB2_HWDEVICE_DEVEP
constexpr USB2_Reg<&USB_Layout::HWDEVICE, 5, 1> USB2_HWDEVICE_DEVEP;
#undef USB2_HWDEVICE_DC
constexpr USB2_Reg<&USB_Layout::HWDEVICE, 1, 0> USB2_HWDEVICE_DC;

// USB2 TX Buffer Hardware Parameters
#undef USB2_HWTXBUF_TXCHANADD
constexpr USB2_Reg<&USB_Layout::HWTXBUF, 8, 16> USB2_HWTXBUF_TXCHANADD;
#undef USB2_HWTXBUF_TXBURST
constexpr USB2_Reg<&USB_Layout::HWTXBUF, 8,  0> USB2_HWTXBUF_TXBURST;

// USB2 RX Buffer Hardware Parameters
#undef USB2_HWRXBUF_RXADD
constexpr USB2_Reg<&USB_Layout::HWRXBUF, 8, 8> USB2_HWRXBUF_RXADD;
#undef USB2_HWRXBUF_RXBURST
constexpr USB2_Reg<&USB_Layout::HWRXBUF, 8, 0> USB2_HWRXBUF_RXBURST;

// USB2 General Purpose Timer #0 Load
#undef USB2_GPTIMER0LD_GPTLD
constexpr USB2_Reg<&USB_Layout::GPTIMER0LD, 24, 0> USB2_GPTIMER0LD_GPTLD;

// USB2 General Purpose Timer #0 Controller
#undef USB2_GPTIMER0CTRL_GPTRUN
constexpr USB2_Reg<&USB_Layout::GPTIMER0CTRL,  1, 31> USB2_GPTIMER0CTRL_GPTRUN;
#undef USB2_GPTIMER0CTRL_GPTRST
constexpr USB2_Reg<&USB_Layout::GPTIMER0CTRL,  1, 30> USB2_GPTIMER0CTRL_GPTRST;
#undef USB2_GPTIMER0CTRL_GPTMODE
constexpr USB2_Reg<&USB_Layout::GPTIMER0CTRL,  1, 24> USB2_GPTIMER0CTRL_GPTMODE;
#undef USB2_GPTIMER0CTRL_GPTCNT
constexpr USB2_Reg<&USB_Layout::GPTIMER0CTRL, 24,  0> USB2_GPTIMER0CTRL_GPTCNT;

// USB2 General Purpose Timer #1 Load
#undef USB2_GPTIMER1LD_GPTLD
constexpr USB2_Reg<&USB_Layout::GPTIMER1LD, 24, 0> USB2_GPTIMER1LD_GPTLD;

// USB2 General Purpose Timer #1 Controller
#undef USB2_GPTIMER1CTRL_GPTRUN
constexpr USB2_Reg<&USB_Layout::GPTIMER1CTRL,  1, 31> USB2_GPTIMER1CTRL_GPTRUN;
#undef USB2_GPTIMER1CTRL_GPTRST
constexpr USB2_Reg<&USB_Layout::GPTIMER1CTRL,  1, 30> USB2_GPTIMER1CTRL_GPTRST;
#undef USB2_GPTIMER1CTRL_GPTMODE
constexpr USB2_Reg<&USB_Layout::GPTIMER1CTRL,  1, 24> USB2_GPTIMER1CTRL_GPTMODE;
#undef USB2_GPTIMER1CTRL_GPTCNT
constexpr USB2_Reg<&USB_Layout::GPTIMER1CTRL, 24,  0> USB2_GPTIMER1CTRL_GPTCNT;

// USB2 System Bus Config
#undef USB2_SBUSCFG_AHBBRST
constexpr USB2_Reg<&USB_Layout::SBUSCFG, 3, 0> USB2_SBUSCFG_AHBBRST;

// USB2 Host Controller Structural Parameters
#undef USB2_HCSPARAMS_N_TT
constexpr USB2_Reg<&USB_Layout::HCSPARAMS, 4, 24> USB2_HCSPARAMS_N_TT;
#undef USB2_HCSPARAMS_N_PTT
constexpr USB2_Reg<&USB_Layout::HCSPARAMS, 4, 20> USB2_HCSPARAMS_N_PTT;
#undef USB2_HCSPARAMS_PI
constexpr USB2_Reg<&USB_Layout::HCSPARAMS, 1, 16> USB2_HCSPARAMS_PI;
#undef USB2_HCSPARAMS_N_CC
constexpr USB2_Reg<&USB_Layout::HCSPARAMS, 4, 12> USB2_HCSPARAMS_N_CC;
#undef USB2_HCSPARAMS_N_PCC
constexpr USB2_Reg<&USB_Layout::HCSPARAMS, 4,  8> USB2_HCSPARAMS_N_PCC;
#undef USB2_HCSPARAMS_PPC
constexpr USB2_Reg<&USB_Layout::HCSPARAMS, 1,  4> USB2_HCSPARAMS_PPC;
#undef USB2_HCSPARAMS_N_PORTS
constexpr USB2_Reg<&USB_Layout::HCSPARAMS, 4,  0> USB2_HCSPARAMS_N_PORTS;

// USB2 Host Controller Capability Parameters
#undef USB2_HCCPARAMS_EECP
constexpr USB2_Reg<&USB_Layout::HCCPARAMS, 8, 8> USB2_HCCPARAMS_EECP;
#undef USB2_HCCPARAMS_IST
constexpr USB2_Reg<&USB_Layout::HCCPARAMS, 4, 4> USB2_HCCPARAMS_IST;
#undef USB2_HCCPARAMS_ASP
constexpr USB2_Reg<&USB_Layout::HCCPARAMS, 1, 2> USB2_HCCPARAMS_ASP;
#undef USB2_HCCPARAMS_PFL
constexpr USB2_Reg<&USB_Layout::HCCPARAMS, 1, 1> USB2_HCCPARAMS_PFL;
#undef USB2_HCCPARAMS_ADC
constexpr USB2_Reg<&USB_Layout::HCCPARAMS, 1, 0> USB2_HCCPARAMS_ADC;

// USB2 Device Controller Capability Parameters
#undef USB2_DCCPARAMS_HC
constexpr USB2_Reg<&USB_Layout::DCCPARAMS, 1, 8> USB2_DCCPARAMS_HC;
#undef USB2_DCCPARAMS_DC
constexpr USB2_Reg<&USB_Layout::DCCPARAMS, 1, 7> USB2_DCCPARAMS_DC;
#undef USB2_DCCPARAMS_DEN
constexpr USB2_Reg<&USB_Layout::DCCPARAMS, 5, 0> USB2_DCCPARAMS_DEN;

// USB2 USB Command Register
#undef USB2_USBCMD_ITC
constexpr USB2_Reg<&USB_Layout::USBCMD, 8, 16> USB2_USBCMD_ITC;
#undef USB2_USBCMD_FS_2
constexpr USB2_Reg<&USB_Layout::USBCMD, 1, 15> USB2_USBCMD_FS_2;
#undef USB2_USBCMD_ATDTW
constexpr USB2_Reg<&USB_Layout::USBCMD, 1, 14> USB2_USBCMD_ATDTW;
#undef USB2_USBCMD_SUTW
constexpr USB2_Reg<&USB_Layout::USBCMD, 1, 13> USB2_USBCMD_SUTW;
#undef USB2_USBCMD_ASPE
constexpr USB2_Reg<&USB_Layout::USBCMD, 1, 11> USB2_USBCMD_ASPE;
#undef USB2_USBCMD_ASP
constexpr USB2_Reg<&USB_Layout::USBCMD, 2,  8> USB2_USBCMD_ASP;
#undef USB2_USBCMD_IAA
constexpr USB2_Reg<&USB_Layout::USBCMD, 1,  6> USB2_USBCMD_IAA;
#undef USB2_USBCMD_ASE
constexpr USB2_Reg<&USB_Layout::USBCMD, 1,  5> USB2_USBCMD_ASE;
#undef USB2_USBCMD_PSE
constexpr USB2_Reg<&USB_Layout::USBCMD, 1,  4> USB2_USBCMD_PSE;
#undef USB2_USBCMD_FS_1
constexpr USB2_Reg<&USB_Layout::USBCMD, 2,  2> USB2_USBCMD_FS_1;
#undef USB2_USBCMD_RST
constexpr USB2_Reg<&USB_Layout::USBCMD, 1,  1> USB2_USBCMD_RST;
#undef USB2_USBCMD_RS
constexpr USB2_Reg<&USB_Layout::USBCMD, 1,  0> USB2_USBCMD_RS;

// USB2 USB Status Register
#undef USB2_USBSTS_TI1
constexpr USB2_Reg<&USB_Layout::USBSTS, 1, 25> USB2_USBSTS_TI1;
#undef USB2_USBSTS_TI0
constexpr USB2_Reg<&USB_Layout::USBSTS, 1, 24> USB2_USBSTS_TI0;
#undef USB2_USBSTS_NAKI
constexpr USB2_Reg<&USB_Layout::USBSTS, 1, 16> USB2_USBSTS_NAKI;
#undef USB2_USBSTS_AS
constexpr USB2_Reg<&USB_Layout::USBSTS, 1, 15> USB2_USBSTS_AS;
#undef USB2_USBSTS_PS
constexpr USB2_Reg<&USB_Layout::USBSTS, 1, 14> USB2_USBSTS_PS;
#undef USB2_USBSTS_RCL
constexpr USB2_Reg<&USB_Layout::USBSTS, 1, 13> USB2_USBSTS_RCL;
#undef USB2_USBSTS_HCH
constexpr USB2_Reg<&USB_Layout::USBSTS, 1, 12> USB2_USBSTS_HCH;
#undef USB2_USBSTS_ULPII
constexpr USB2_Reg<&USB_Layout::USBSTS, 1, 10> USB2_USBSTS_ULPII;
#undef USB2_USBSTS_SLI
constexpr USB2_Reg<&USB_Layout::USBSTS, 1,  8> USB2_USBSTS_SLI;
#undef USB2_USBSTS_SRI
constexpr USB2_Reg<&USB_Layout::USBSTS, 1,  7> USB2_USBSTS_SRI;
#undef USB2_USBSTS_URI
constexpr USB2_Reg<&USB_Layout::USBSTS, 1,  6> USB2_USBSTS_URI;
#undef USB2_USBSTS_AAI
constexpr USB2_Reg<&USB_Layout::USBSTS, 1,  5> USB2_USBSTS_AAI;
#undef USB2_USBSTS_SEI
constexpr USB2_Reg<&USB_Layout::USBSTS, 1,  4> USB2_USBSTS_SEI;
#undef USB2_USBSTS_FRI
constexpr USB2_Reg<&USB_Layout::USBSTS, 1,  3> USB2_USBSTS_FRI;
#undef USB2_USBSTS_PCI
constexpr USB2_Reg<&USB_Layout::USBSTS, 1,  2> USB2_USBSTS_PCI;
#undef USB2_USBSTS_UEI
constexpr USB2_Reg<&USB_Layout::USBSTS, 1,  1> USB2_USBSTS_UEI;
#undef USB2_USBSTS_UI
constexpr USB2_Reg<&USB_Layout::USBSTS, 1,  0> USB2_USBSTS_UI;

// USB2 Interrupt Enable Register
#undef USB2_USBINTR_TIE1
constexpr USB2_Reg<&USB_Layout::USBINTR, 1, 25> USB2_USBINTR_TIE1;
#undef USB2_USBINTR_TIE0
constexpr USB2_Reg<&USB_Layout::USBINTR, 1, 24> USB2_USBINTR_TIE0;
#undef USB2_USBINTR_UPIE
constexpr USB2_Reg<&USB_Layout::USBINTR, 1, 19> USB2_USBINTR_UPIE;
#undef USB2_USBINTR_UAIE
constexpr USB2_Reg<&USB_Layout::USBINTR, 1, 18> USB2_USBINTR_UAIE;
#undef USB2_USBINTR_NAKE
constexpr USB2_Reg<&USB_Layout::USBINTR, 1, 16> USB2_USBINTR_NAKE;
#undef USB2_USBINTR_ULPIE
constexpr USB2_Reg<&USB_Layout::USBINTR, 1, 10> USB2_USBINTR_ULPIE;
#undef USB2_USBINTR_SLE
constexpr USB2_Reg<&USB_Layout::USBINTR, 1,  8> USB2_USBINTR_SLE;
#undef USB2_USBINTR_SRE
constexpr USB2_Reg<&USB_Layout::USBINTR, 1,  7> USB2_USBINTR_SRE;
#undef USB2_USBINTR_URE
constexpr USB2_Reg<&USB_Layout::USBINTR, 1,  6> USB2_USBINTR_URE;
#undef USB2_USBINTR_AAE
constexpr USB2_Reg<&USB_Layout::USBINTR, 1,  5> USB2_USBINTR_AAE;
#undef USB2_USBINTR_SEE
constexpr USB2_Reg<&USB_Layout::USBINTR, 1,  4> USB2_USBINTR_SEE;
#undef USB2_USBINTR_FRE
constexpr USB2_Reg<&USB_Layout::USBINTR, 1,  3> USB2_USBINTR_FRE;
#undef USB2_USBINTR_PCE
constexpr USB2_Reg<&USB_Layout::USBINTR, 1,  2> USB2_USBINTR_PCE;
#undef USB2_USBINTR_UEE
constexpr USB2_Reg<&USB_Layout::USBINTR, 1,  1> USB2_USBINTR_UEE;
#undef USB2_USBINTR_UE
constexpr USB2_Reg<&USB_Layout::USBINTR, 1,  0> USB2_USBINTR_UE;

// USB2 USB Frame Index
#undef USB2_FRINDEX_FRINDEX
constexpr USB2_Reg<&USB_Layout::FRINDEX, 14, 0> USB2_FRINDEX_FRINDEX;

// USB2 Device Address
#undef USB2_DEVICEADDR_USBADR
constexpr USB2_Reg<&USB_Layout::DEVICEADDR, 7, 25> USB2_DEVICEADDR_USBADR;
#undef USB2_DEVICEADDR_USBADRA
constexpr USB2_Reg<&USB_Layout::DEVICEADDR, 1, 24> USB2_DEVICEADDR_USBADRA;

// USB2 Frame List Base Address
#undef USB2_PERIODICLISTBASE_BASEADR
constexpr USB2_Reg<&USB_Layout::PERIODICLISTBASE, 20, 12> USB2_PERIODICLISTBASE_BASEADR;

// USB2 Next Asynch. Address
#undef USB2_ASYNCLISTADDR_ASYBASE
constexpr USB2_Reg<&USB_Layout::ASYNCLISTADDR, 27, 5> USB2_ASYNCLISTADDR_ASYBASE;

// USB2 Endpoint List Address
#undef USB2_ENDPTLISTADDR_EPBASE
constexpr USB2_Reg<&USB_Layout::ENDPTLISTADDR, 21, 11> USB2_ENDPTLISTADDR_EPBASE;

// USB2 Programmable Burst Size
#undef USB2_BURSTSIZE_TXPBURST
constexpr USB2_Reg<&USB_Layout::BURSTSIZE, 9, 8> USB2_BURSTSIZE_TXPBURST;
#undef USB2_BURSTSIZE_RXPBURST
constexpr USB2_Reg<&USB_Layout::BURSTSIZE, 8, 0> USB2_BURSTSIZE_RXPBURST;

// USB2 TX FIFO Fill Tuning
#undef USB2_TXFILLTUNING_TXFIFOTHRES
constexpr USB2_Reg<&USB_Layout::TXFILLTUNING, 6, 16> USB2_TXFILLTUNING_TXFIFOTHRES;
#undef USB2_TXFILLTUNING_TXSCHHEALTH
constexpr USB2_Reg<&USB_Layout::TXFILLTUNING, 5,  8> USB2_TXFILLTUNING_TXSCHHEALTH;
#undef USB2_TXFILLTUNING_TXSCHOH
constexpr USB2_Reg<&USB_Layout::TXFILLTUNING, 8,  0> USB2_TXFILLTUNING_TXSCHOH;

// USB2 Endpoint NAK
#undef USB2_ENDPTNAK_EPTN
constexpr USB2_Reg<&USB_Layout::ENDPTNAK, 8, 16> USB2_ENDPTNAK_EPTN;
#undef USB2_ENDPTNAK_EPRN
constexpr USB2_Reg<&USB_Layout::ENDPTNAK, 8,  0> USB2_ENDPTNAK_EPRN;

// USB2 Endpoint NAK Enable
#undef USB2_ENDPTNAKEN_EPTNE
constexpr USB2_Reg<&USB_Layout::ENDPTNAKEN, 8, 16> USB2_ENDPTNAKEN_EPTNE;
#undef USB2_ENDPTNAKEN_EPRNE
constexpr USB2_Reg<&USB_Layout::ENDPTNAKEN, 8,  0> USB2_ENDPTNAKEN_EPRNE;

// USB2 Configure Flag Register
#undef USB2_CONFIGFLAG_CF
constexpr USB2_Reg<&USB_Layout::CONFIGFLAG, 1, 0> USB2_CONFIGFLAG_CF;

// USB2 Port Status & Control
#undef USB2_PORTSC1_PTS_1
constexpr USB2_Reg<&USB_Layout::PORTSC1, 2, 30> USB2_PORTSC1_PTS_1;
#undef USB2_PORTSC1_STS
constexpr USB2_Reg<&USB_Layout::PORTSC1, 1, 29> USB2_PORTSC1_STS;
#undef USB2_PORTSC1_PTW
constexpr USB2_Reg<&USB_Layout::PORTSC1, 1, 28> USB2_PORTSC1_PTW;
#undef USB2_PORTSC1_PSPD
constexpr USB2_Reg<&USB_Layout::PORTSC1, 2, 26> USB2_PORTSC1_PSPD;
#undef USB2_PORTSC1_PTS_2
constexpr USB2_Reg<&USB_Layout::PORTSC1, 1, 25> USB2_PORTSC1_PTS_2;
#undef USB2_PORTSC1_PFSC
constexpr USB2_Reg<&USB_Layout::PORTSC1, 1, 24> USB2_PORTSC1_PFSC;
#undef USB2_PORTSC1_PHCD
constexpr USB2_Reg<&USB_Layout::PORTSC1, 1, 23> USB2_PORTSC1_PHCD;
#undef USB2_PORTSC1_WKOC
constexpr USB2_Reg<&USB_Layout::PORTSC1, 1, 22> USB2_PORTSC1_WKOC;
#undef USB2_PORTSC1_WKDC
constexpr USB2_Reg<&USB_Layout::PORTSC1, 1, 21> USB2_PORTSC1_WKDC;
#undef USB2_PORTSC1_WKCN
constexpr USB2_Reg<&USB_Layout::PORTSC1, 1, 20> USB2_PORTSC1_WKCN;
#undef USB2_PORTSC1_PTC
constexpr USB2_Reg<&USB_Layout::PORTSC1, 4, 16> USB2_PORTSC1_PTC;
#undef USB2_PORTSC1_PIC
constexpr USB2_Reg<&USB_Layout::PORTSC1, 2, 14> USB2_PORTSC1_PIC;
#undef USB2_PORTSC1_PO
constexpr USB2_Reg<&USB_Layout::PORTSC1, 1, 13> USB2_PORTSC1_PO;
#undef USB2_PORTSC1_PP
constexpr USB2_Reg<&USB_Layout::PORTSC1, 1, 12> USB2_PORTSC1_PP;
#undef USB2_PORTSC1_LS
constexpr USB2_Reg<&USB_Layout::PORTSC1, 2, 10> USB2_PORTSC1_LS;
#undef USB2_PORTSC1_HSP
constexpr USB2_Reg<&USB_Layout::PORTSC1, 1,  9> USB2_PORTSC1_HSP;
#undef USB2_PORTSC1_PR
constexpr USB2_Reg<&USB_Layout::PORTSC1, 1,  8> USB2_PORTSC1_PR;
#undef USB2_PORTSC1_SUSP
constexpr USB2_Reg<&USB_Layout::PORTSC1, 1,  7> USB2_PORTSC1_SUSP;
#undef USB2_PORTSC1_FPR
constexpr USB2_Reg<&USB_Layout::PORTSC1, 1,  6> USB2_PORTSC1_FPR;
#undef USB2_PORTSC1_OCC
constexpr USB2_Reg<&USB_Layout::PORTSC1, 1,  5> USB2_PORTSC1_OCC;
#undef USB2_PORTSC1_OCA
constexpr USB2_Reg<&USB_Layout::PORTSC1, 1,  4> USB2_PORTSC1_OCA;
#undef USB2_PORTSC1_PEC
constexpr USB2_Reg<&USB_Layout::PORTSC1, 1,  3> USB2_PORTSC1_PEC;
#undef USB2_PORTSC1_PE
constexpr USB2_Reg<&USB_Layout::PORTSC1, 1,  2> USB2_PORTSC1_PE;
#undef USB2_PORTSC1_CSC
constexpr USB2_Reg<&USB_Layout::PORTSC1, 1,  1> USB2_PORTSC1_CSC;
#undef USB2_PORTSC1_CCS
constexpr USB2_Reg<&USB_Layout::PORTSC1, 1,  0> USB2_PORTSC1_CCS;

// USB2 On-The-Go Status & control
#undef USB2_OTGSC_DPIE
constexpr USB2_Reg<&USB_Layout::OTGSC, 1, 30> USB2_OTGSC_DPIE;
#undef USB2_OTGSC_EN_1MS
constexpr USB2_Reg<&USB_Layout::OTGSC, 1, 29> USB2_OTGSC_EN_1MS;
#undef USB2_OTGSC_BSEIE
constexpr USB2_Reg<&USB_Layout::OTGSC, 1, 28> USB2_OTGSC_BSEIE;
#undef USB2_OTGSC_BSVIE
constexpr USB2_Reg<&USB_Layout::OTGSC, 1, 27> USB2_OTGSC_BSVIE;
#undef USB2_OTGSC_ASVIE
constexpr USB2_Reg<&USB_Layout::OTGSC, 1, 26> USB2_OTGSC_ASVIE;
#undef USB2_OTGSC_AVVIE
constexpr USB2_Reg<&USB_Layout::OTGSC, 1, 25> USB2_OTGSC_AVVIE;
#undef USB2_OTGSC_IDIE
constexpr USB2_Reg<&USB_Layout::OTGSC, 1, 24> USB2_OTGSC_IDIE;
#undef USB2_OTGSC_DPIS
constexpr USB2_Reg<&USB_Layout::OTGSC, 1, 22> USB2_OTGSC_DPIS;
#undef USB2_OTGSC_STATUS_1MS
constexpr USB2_Reg<&USB_Layout::OTGSC, 1, 21> USB2_OTGSC_STATUS_1MS;
#undef USB2_OTGSC_BSEIS
constexpr USB2_Reg<&USB_Layout::OTGSC, 1, 20> USB2_OTGSC_BSEIS;
#undef USB2_OTGSC_BSVIS
constexpr USB2_Reg<&USB_Layout::OTGSC, 1, 19> USB2_OTGSC_BSVIS;
#undef USB2_OTGSC_ASVIS
constexpr USB2_Reg<&USB_Layout::OTGSC, 1, 18> USB2_OTGSC_ASVIS;
#undef USB2_OTGSC_AVVIS
constexpr USB2_Reg<&USB_Layout::OTGSC, 1, 17> USB2_OTGSC_AVVIS;
#undef USB2_OTGSC_IDIS
constexpr USB2_Reg<&USB_Layout::OTGSC, 1, 16> USB2_OTGSC_IDIS;
#undef USB2_OTGSC_DPS
constexpr USB2_Reg<&USB_Layout::OTGSC, 1, 14> USB2_OTGSC_DPS;
#undef USB2_OTGSC_TOG_1MS
constexpr USB2_Reg<&USB_Layout::OTGSC, 1, 13> USB2_OTGSC_TOG_1MS;
#undef USB2_OTGSC_BSE
constexpr USB2_Reg<&USB_Layout::OTGSC, 1, 12> USB2_OTGSC_BSE;
#undef USB2_OTGSC_BSV
constexpr USB2_Reg<&USB_Layout::OTGSC, 1, 11> USB2_OTGSC_BSV;
#undef USB2_OTGSC_ASV
constexpr USB2_Reg<&USB_Layout::OTGSC, 1, 10> USB2_OTGSC_ASV;
#undef USB2_OTGSC_AVV
constexpr USB2_Reg<&USB_Layout::OTGSC, 1,  9> USB2_OTGSC_AVV;
#undef USB2_OTGSC_ID
constexpr USB2_Reg<&USB_Layout::OTGSC, 1,  8> USB2_OTGSC_ID;
#undef USB2_OTGSC_IDPU
constexpr USB2_Reg<&USB_Layout::OTGSC, 1,  5> USB2_OTGSC_IDPU;
#undef USB2_OTGSC_DP
constexpr USB2_Reg<&USB_Layout::OTGSC, 1,  4> USB2_OTGSC_DP;
#undef USB2_OTGSC_OT
constexpr USB2_Reg<&USB_Layout::OTGSC, 1,  3> USB2_OTGSC_OT;
#undef USB2_OTGSC_VC
constexpr USB2_Reg<&USB_Layout::OTGSC, 1,  1> USB2_OTGSC_VC;
#undef USB2_OTGSC_VD
constexpr USB2_Reg<&USB_Layout::OTGSC, 1,  0> USB2_OTGSC_VD;

// USB2 USB Device Mode
#undef USB2_USBMODE_SDIS
constexpr USB2_Reg<&USB_Layout::USBMODE, 1, 4> USB2_USBMODE_SDIS;
#undef USB2_USBMODE_SLOM
constexpr USB2_Reg<&USB_Layout::USBMODE, 1, 3> USB2_USBMODE_SLOM;
#undef USB2_USBMODE_ES
constexpr USB2_Reg<&USB_Layout::USBMODE, 1, 2> USB2_USBMODE_ES;
#undef USB2_USBMODE_CM
constexpr USB2_Reg<&USB_Layout::USBMODE, 2, 0> USB2_USBMODE_CM;

// USB2 Endpoint Setup Status
#undef USB2_ENDPTSETUPSTAT_ENDPTSETUPSTAT
constexpr USB2_Reg<&USB_Layout::ENDPTSETUPSTAT, 16, 0> USB2_ENDPTSETUPSTAT_ENDPTSETUPSTAT;

// USB2 Endpoint Prime
#undef USB2_ENDPTPRIME_PETB
constexpr USB2_Reg<&USB_Layout::ENDPTPRIME, 8, 16> USB2_ENDPTPRIME_PETB;
#undef USB2_ENDPTPRIME_PERB
constexpr USB2_Reg<&USB_Layout::ENDPTPRIME, 8,  0> USB2_ENDPTPRIME_PERB;

// USB2 Endpoint Flush
#undef USB2_ENDPTFLUSH_FETB
constexpr USB2_Reg<&USB_Layout::ENDPTFLUSH, 8, 16> USB2_ENDPTFLUSH_FETB;
#undef USB2_ENDPTFLUSH_FERB
constexpr USB2_Reg<&USB_Layout::ENDPTFLUSH, 8,  0> USB2_ENDPTFLUSH_FERB;

// USB2 Endpoint Status
#undef USB2_ENDPTSTAT_ETBR
constexpr USB2_Reg<&USB_Layout::ENDPTSTAT, 8, 16> USB2_ENDPTSTAT_ETBR;
#undef USB2_ENDPTSTAT_ERBR
constexpr USB2_Reg<&USB_Layout::ENDPTSTAT, 8,  0> USB2_ENDPTSTAT_ERBR;

// USB2 Endpoint Complete
#undef USB2_ENDPTCOMPLETE_ETCE
constexpr USB2_Reg<&USB_Layout::ENDPTCOMPLETE, 8, 16> USB2_ENDPTCOMPLETE_ETCE;
#undef USB2_ENDPTCOMPLETE_ERCE
constexpr USB2_Reg<&USB_Layout::ENDPTCOMPLETE, 8,  0> USB2_ENDPTCOMPLETE_ERCE;

}  // namespace teensy4
}  // namespace hardware
}  // namespace qindesign
