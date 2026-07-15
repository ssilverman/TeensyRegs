// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// DCB.h defines all the DCB registers.
// This file is part of the TeensyRegs library.

#pragma once

#include <cstddef>
#include <cstdint>

#include "hardware/regs/regs.h"

namespace qindesign {
namespace hardware {
namespace teensy4 {

// Structure type to access the Debug Control Block Registers (DCB).
//
// Comments are from BSD-3-licensed NXP SDK.
//
// See:
// * https://github.com/nxp-mcuxpresso/mcu-sdk-cmsis/blob/mcux_main/Core/Include/core_cm7.h
struct DCB_Layout {
  volatile uint32_t DHCSR;                  /*!< Offset: 0x000 (R/W)  Debug Halting Control and Status Register */
  volatile uint32_t DCRSR;                  /*!< Offset: 0x004 ( /W)  Debug Core Register Selector Register */
  volatile uint32_t DCRDR;                  /*!< Offset: 0x008 (R/W)  Debug Core Register Data Register */
  volatile uint32_t DEMCR;                  /*!< Offset: 0x00C (R/W)  Debug Exception and Monitor Control Register */
};

constexpr size_t    kDCB_size = 0x10;
constexpr uintptr_t kDCB_base = 0xE000EDF0;  /*!< Core Debug Base Address */

constexpr regs::RegGroup<DCB_Layout, kDCB_size, kDCB_base> DCB;

template <auto Member, size_t Bits, unsigned int Shift,
          bool DirectAssign = false>
using DCB_Reg = regs::Reg<uint32_t, kDCB_base, DCB_Layout, Member, 0, Bits,
                          Shift, DirectAssign>;

// Undefine anything defined by Teensyduino's imxrt.h

// DCB Debug Halting Control and Status Register Definitions
#undef DCB_DHCSR_DBGKEY
constexpr DCB_Reg<&DCB_Layout::DHCSR, 16, 16> DCB_DHCSR_DBGKEY;       // Debug key
#undef DCB_DHCSR_S_RESET_ST
constexpr DCB_Reg<&DCB_Layout::DHCSR,  1, 25> DCB_DHCSR_S_RESET_ST;   // Reset sticky status
#undef DCB_DHCSR_S_RETIRE_ST
constexpr DCB_Reg<&DCB_Layout::DHCSR,  1, 24> DCB_DHCSR_S_RETIRE_ST;  // Retire sticky status
#undef DCB_DHCSR_S_LOCKUP
constexpr DCB_Reg<&DCB_Layout::DHCSR,  1, 19> DCB_DHCSR_S_LOCKUP;     // Lockup status
#undef DCB_DHCSR_S_SLEEP
constexpr DCB_Reg<&DCB_Layout::DHCSR,  1, 18> DCB_DHCSR_S_SLEEP;      // Sleeping status
#undef DCB_DHCSR_S_HALT
constexpr DCB_Reg<&DCB_Layout::DHCSR,  1, 17> DCB_DHCSR_S_HALT;       // Halted status
#undef DCB_DHCSR_S_REGRDY
constexpr DCB_Reg<&DCB_Layout::DHCSR,  1, 16> DCB_DHCSR_S_REGRDY;     // Register ready status
#undef DCB_DHCSR_C_SNAPSTALL
constexpr DCB_Reg<&DCB_Layout::DHCSR,  1,  5> DCB_DHCSR_C_SNAPSTALL;  // Snap stall control
#undef DCB_DHCSR_C_MASKINTS
constexpr DCB_Reg<&DCB_Layout::DHCSR,  1,  3> DCB_DHCSR_C_MASKINTS;   // Mask interrupts control
#undef DCB_DHCSR_C_STEP
constexpr DCB_Reg<&DCB_Layout::DHCSR,  1,  2> DCB_DHCSR_C_STEP;       // Step control
#undef DCB_DHCSR_C_HALT
constexpr DCB_Reg<&DCB_Layout::DHCSR,  1,  1> DCB_DHCSR_C_HALT;       // Halt control
#undef DCB_DHCSR_C_DEBUGEN
constexpr DCB_Reg<&DCB_Layout::DHCSR,  1,  0> DCB_DHCSR_C_DEBUGEN;    // Debug enable control

// DCB Debug Core Register Selector Register Definitions
#undef DCB_DCRSR_REGWnR
constexpr DCB_Reg<&DCB_Layout::DCRSR, 1, 16> DCB_DCRSR_REGWnR;  // Register write/not-read
#undef DCB_DCRSR_REGSEL
constexpr DCB_Reg<&DCB_Layout::DCRSR, 7,  0> DCB_DCRSR_REGSEL;  // Register selector

// DCB Debug Core Register Data Register Definitions
#undef DCB_DCRDR_DBGTMP
constexpr DCB_Reg<&DCB_Layout::DCRDR, 32, 0> DCB_DCRDR_DBGTMP;  // Data temporary buffer

// DCB Debug Exception and Monitor Control Register Definitions
#undef DCB_DEMCR_TRCENA
constexpr DCB_Reg<&DCB_Layout::DEMCR, 1, 24> DCB_DEMCR_TRCENA;        // Trace enable
#undef DCB_DEMCR_MON_REQ
constexpr DCB_Reg<&DCB_Layout::DEMCR, 1, 19> DCB_DEMCR_MON_REQ;       // Monitor request
#undef DCB_DEMCR_MON_STEP
constexpr DCB_Reg<&DCB_Layout::DEMCR, 1, 18> DCB_DEMCR_MON_STEP;      // Monitor step
#undef DCB_DEMCR_MON_PEND
constexpr DCB_Reg<&DCB_Layout::DEMCR, 1, 17> DCB_DEMCR_MON_PEND;      // Monitor pend
#undef DCB_DEMCR_MON_EN
constexpr DCB_Reg<&DCB_Layout::DEMCR, 1, 16> DCB_DEMCR_MON_EN;        // Monitor enable
#undef DCB_DEMCR_VC_HARDERR
constexpr DCB_Reg<&DCB_Layout::DEMCR, 1, 10> DCB_DEMCR_VC_HARDERR;    // Vector Catch HardFault errors
#undef DCB_DEMCR_VC_INTERR
constexpr DCB_Reg<&DCB_Layout::DEMCR, 1,  9> DCB_DEMCR_VC_INTERR;     // Vector Catch interrupt errors
#undef DCB_DEMCR_VC_BUSERR
constexpr DCB_Reg<&DCB_Layout::DEMCR, 1,  8> DCB_DEMCR_VC_BUSERR;     // Vector Catch BusFault errors
#undef DCB_DEMCR_VC_STATERR
constexpr DCB_Reg<&DCB_Layout::DEMCR, 1,  7> DCB_DEMCR_VC_STATERR;    // Vector Catch state errors
#undef DCB_DEMCR_VC_CHKERR
constexpr DCB_Reg<&DCB_Layout::DEMCR, 1,  6> DCB_DEMCR_VC_CHKERR;     // Vector Catch check errors
#undef DCB_DEMCR_VC_NOCPERR
constexpr DCB_Reg<&DCB_Layout::DEMCR, 1,  5> DCB_DEMCR_VC_NOCPERR;    // Vector Catch NOCP errors
#undef DCB_DEMCR_VC_MMERR
constexpr DCB_Reg<&DCB_Layout::DEMCR, 1,  4> DCB_DEMCR_VC_MMERR;      // Vector Catch MemManage errors
#undef DCB_DEMCR_VC_CORERESET
constexpr DCB_Reg<&DCB_Layout::DEMCR, 1,  0> DCB_DEMCR_VC_CORERESET;  // Vector Catch Core reset

}  // namespace teensy4
}  // namespace hardware
}  // namespace qindesign
