// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// WDOG.h defines all the WDOG registers.
// This file is part of the TeensyRegs library.

#pragma once

#include <cstddef>
#include <cstdint>

#include "hardware/regs/regs.h"

namespace qindesign {
namespace hardware {
namespace teensy4 {

// WDOG layout. Comments are from BSD-3-licensed NXP SDK.
//
// See:
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/periph/PERI_WDOG.h
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/MIMXRT1062/MIMXRT1062_COMMON.h
struct WDOG_Layout {
  volatile uint16_t WCR;                               /**< Watchdog Control Register, offset: 0x0 */
  volatile uint16_t WSR;                               /**< Watchdog Service Register, offset: 0x2 */
  const volatile uint16_t WRSR;                        /**< Watchdog Reset Status Register, offset: 0x4 */
  volatile uint16_t WICR;                              /**< Watchdog Interrupt Control Register, offset: 0x6 */
  volatile uint16_t WMCR;                              /**< Watchdog Miscellaneous Control Register, offset: 0x8 */
};

constexpr size_t    kWDOG_size  = 0xA;
constexpr uintptr_t kWDOG1_base = 0x400B8000;
constexpr uintptr_t kWDOG2_base = 0x400D0000;

constexpr regs::RegGroup<WDOG_Layout, kWDOG_size, kWDOG1_base> WDOG1;
constexpr regs::RegGroup<WDOG_Layout, kWDOG_size, kWDOG2_base> WDOG2;

template <auto Member, size_t Bits, unsigned int Shift,
          bool DirectAssign = false>
using WDOG1_Reg =
    regs::Reg16<kWDOG1_base, WDOG_Layout, Member, 0, Bits, Shift, DirectAssign>;

template <auto Member, size_t Bits, unsigned int Shift,
          bool DirectAssign = false>
using WDOG2_Reg =
    regs::Reg16<kWDOG2_base, WDOG_Layout, Member, 0, Bits, Shift, DirectAssign>;

// Undefine anything defined by Teensyduino's imxrt.h

// Watchdog Control Register
#undef WDOG_WCR_WT
constexpr WDOG1_Reg<&WDOG_Layout::WCR, 8, 8> WDOG_WCR_WT;
    // 0b00000000..- 0.5 Seconds (Default).
    // 0b00000001..- 1.0 Seconds.
    // 0b00000010..- 1.5 Seconds.
    // 0b00000011..- 2.0 Seconds.
    // 0b11111111..- 128 Seconds.
#undef WDOG_WCR_WDW
constexpr WDOG1_Reg<&WDOG_Layout::WCR, 1, 7> WDOG_WCR_WDW;
    // 0b0..Continue WDOG timer operation (Default).
    // 0b1..Suspend WDOG timer operation.
#undef WDOG_WCR_SRE
constexpr WDOG1_Reg<&WDOG_Layout::WCR, 1, 6> WDOG_WCR_SRE;  // Software Reset Extension, an optional way to generate software reset
    // 0b0..using original way to generate software reset (default)
    // 0b1..using new way to generate software reset.
#undef WDOG_WCR_WDA
constexpr WDOG1_Reg<&WDOG_Layout::WCR, 1, 5> WDOG_WCR_WDA;
    // 0b0..Assert WDOG_B output.
    // 0b1..No effect on system (Default).
#undef WDOG_WCR_SRS
constexpr WDOG1_Reg<&WDOG_Layout::WCR, 1, 4> WDOG_WCR_SRS;
    // 0b0..Assert system reset signal.
    // 0b1..No effect on the system (Default).
#undef WDOG_WCR_WDT
constexpr WDOG1_Reg<&WDOG_Layout::WCR, 1, 3> WDOG_WCR_WDT;
    // 0b0..No effect on WDOG_B (Default).
    // 0b1..Assert WDOG_B upon a Watchdog Time-out event.
#undef WDOG_WCR_WDE
constexpr WDOG1_Reg<&WDOG_Layout::WCR, 1, 2> WDOG_WCR_WDE;
    // 0b0..Disable the Watchdog (Default).
    // 0b1..Enable the Watchdog.
#undef WDOG_WCR_WDBG
constexpr WDOG1_Reg<&WDOG_Layout::WCR, 1, 1> WDOG_WCR_WDBG;
    // 0b0..Continue WDOG timer operation (Default).
    // 0b1..Suspend the watchdog timer.
#undef WDOG_WCR_WDZST
constexpr WDOG1_Reg<&WDOG_Layout::WCR, 1, 0> WDOG_WCR_WDZST;
    // 0b0..Continue timer operation (Default).
    // 0b1..Suspend the watchdog timer.

// Watchdog Service Register
#undef WDOG_WSR_WSR
constexpr WDOG1_Reg<&WDOG_Layout::WSR, 16, 0, true> WDOG_WSR_WSR;
    // 0b0101010101010101..Write to the Watchdog Service Register (WDOG_WSR).
    // 0b1010101010101010..Write to the Watchdog Service Register (WDOG_WSR).

// Watchdog Reset Status Register
#undef WDOG_WRSR_POR
constexpr WDOG1_Reg<&WDOG_Layout::WRSR, 1, 4> WDOG_WRSR_POR;
    // 0b0..Reset is not the result of a power on reset.
    // 0b1..Reset is the result of a power on reset.
#undef WDOG_WRSR_TOUT
constexpr WDOG1_Reg<&WDOG_Layout::WRSR, 1, 1> WDOG_WRSR_TOUT;
    // 0b0..Reset is not the result of a WDOG timeout.
    // 0b1..Reset is the result of a WDOG timeout.
#undef WDOG_WRSR_SFTW
constexpr WDOG1_Reg<&WDOG_Layout::WRSR, 1, 0> WDOG_WRSR_SFTW;
    // 0b0..Reset is not the result of a software reset.
    // 0b1..Reset is the result of a software reset.

// Watchdog Interrupt Control Register
#undef WDOG_WICR_WIE
constexpr WDOG1_Reg<&WDOG_Layout::WICR, 1, 15> WDOG_WICR_WIE;
    // 0b0..Disable Interrupt (Default).
    // 0b1..Enable Interrupt.
#undef WDOG_WICR_WTIS
constexpr WDOG1_Reg<&WDOG_Layout::WICR, 1, 14> WDOG_WICR_WTIS;
    // 0b0..No interrupt has occurred (Default).
    // 0b1..Interrupt has occurred
#undef WDOG_WICR_WICT
constexpr WDOG1_Reg<&WDOG_Layout::WICR, 8,  0> WDOG_WICR_WICT;
    // 0b00000000..WICT[7:0] = Time duration between interrupt and time-out is 0 seconds.
    // 0b00000001..WICT[7:0] = Time duration between interrupt and time-out is 0.5 seconds.
    // 0b00000100..WICT[7:0] = Time duration between interrupt and time-out is 2 seconds (Default).
    // 0b11111111..WICT[7:0] = Time duration between interrupt and time-out is 127.5 seconds.

// Watchdog Miscellaneous Control Register
#undef WDOG_WMCR_PDE
constexpr WDOG1_Reg<&WDOG_Layout::WMCR, 1, 0> WDOG_WMCR_PDE;
    // 0b0..Power Down Counter of WDOG is disabled.
    // 0b1..Power Down Counter of WDOG is enabled (Default).

// WDOG2 Watchdog Control Register
#undef WDOG2_WCR_WT
constexpr WDOG2_Reg<&WDOG_Layout::WCR, 8, 8> WDOG2_WCR_WT;
#undef WDOG2_WCR_WDW
constexpr WDOG2_Reg<&WDOG_Layout::WCR, 1, 7> WDOG2_WCR_WDW;
#undef WDOG2_WCR_SRE
constexpr WDOG2_Reg<&WDOG_Layout::WCR, 1, 6> WDOG2_WCR_SRE;
#undef WDOG2_WCR_WDA
constexpr WDOG2_Reg<&WDOG_Layout::WCR, 1, 5> WDOG2_WCR_WDA;
#undef WDOG2_WCR_SRS
constexpr WDOG2_Reg<&WDOG_Layout::WCR, 1, 4> WDOG2_WCR_SRS;
#undef WDOG2_WCR_WDT
constexpr WDOG2_Reg<&WDOG_Layout::WCR, 1, 3> WDOG2_WCR_WDT;
#undef WDOG2_WCR_WDE
constexpr WDOG2_Reg<&WDOG_Layout::WCR, 1, 2> WDOG2_WCR_WDE;
#undef WDOG2_WCR_WDBG
constexpr WDOG2_Reg<&WDOG_Layout::WCR, 1, 1> WDOG2_WCR_WDBG;
#undef WDOG2_WCR_WDZST
constexpr WDOG2_Reg<&WDOG_Layout::WCR, 1, 0> WDOG2_WCR_WDZST;

// WDOG2 Watchdog Service Register
#undef WDOG2_WSR_WSR
constexpr WDOG2_Reg<&WDOG_Layout::WSR, 16, 0, true> WDOG2_WSR_WSR;

// WDOG2 Watchdog Reset Status Register
#undef WDOG2_WRSR_POR
constexpr WDOG2_Reg<&WDOG_Layout::WRSR, 1, 4> WDOG2_WRSR_POR;
#undef WDOG2_WRSR_TOUT
constexpr WDOG2_Reg<&WDOG_Layout::WRSR, 1, 1> WDOG2_WRSR_TOUT;
#undef WDOG2_WRSR_SFTW
constexpr WDOG2_Reg<&WDOG_Layout::WRSR, 1, 0> WDOG2_WRSR_SFTW;

// WDOG2 Watchdog Interrupt Control Register
#undef WDOG2_WICR_WIE
constexpr WDOG2_Reg<&WDOG_Layout::WICR, 1, 15> WDOG2_WICR_WIE;
#undef WDOG2_WICR_WTIS
constexpr WDOG2_Reg<&WDOG_Layout::WICR, 1, 14> WDOG2_WICR_WTIS;
#undef WDOG2_WICR_WICT
constexpr WDOG2_Reg<&WDOG_Layout::WICR, 8,  0> WDOG2_WICR_WICT;

// WDOG2 Watchdog Miscellaneous Control Register
#undef WDOG2_WMCR_PDE
constexpr WDOG2_Reg<&WDOG_Layout::WMCR, 1, 0> WDOG2_WMCR_PDE;

}  // namespace teensy4
}  // namespace hardware
}  // namespace qindesign
