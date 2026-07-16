// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// DWT.h defines all the DWT registers.
// This file is part of the TeensyRegs library.

#pragma once

#include <cstddef>
#include <cstdint>

#include "hardware/regs/regs.h"

namespace qindesign {
namespace hardware {
namespace teensy4 {

// Structure type to access the Data Watchpoint and Trace Register (DWT).
//
// Comments are from BSD-3-licensed NXP SDK.
//
// See:
// * https://github.com/nxp-mcuxpresso/mcu-sdk-cmsis/blob/mcux_main/Core/Include/core_cm7.h
struct DWT_Layout {
  volatile uint32_t CTRL;                   /*!< Offset: 0x000 (R/W)  Control Register */
  volatile uint32_t CYCCNT;                 /*!< Offset: 0x004 (R/W)  Cycle Count Register */
  volatile uint32_t CPICNT;                 /*!< Offset: 0x008 (R/W)  CPI Count Register */
  volatile uint32_t EXCCNT;                 /*!< Offset: 0x00C (R/W)  Exception Overhead Count Register */
  volatile uint32_t SLEEPCNT;               /*!< Offset: 0x010 (R/W)  Sleep Count Register */
  volatile uint32_t LSUCNT;                 /*!< Offset: 0x014 (R/W)  LSU Count Register */
  volatile uint32_t FOLDCNT;                /*!< Offset: 0x018 (R/W)  Folded-instruction Count Register */
  const volatile uint32_t PCSR;             /*!< Offset: 0x01C (R/ )  Program Counter Sample Register */
  volatile uint32_t COMP0;                  /*!< Offset: 0x020 (R/W)  Comparator Register 0 */
  volatile uint32_t MASK0;                  /*!< Offset: 0x024 (R/W)  Mask Register 0 */
  volatile uint32_t FUNCTION0;              /*!< Offset: 0x028 (R/W)  Function Register 0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[1];
  volatile uint32_t COMP1;                  /*!< Offset: 0x030 (R/W)  Comparator Register 1 */
  volatile uint32_t MASK1;                  /*!< Offset: 0x034 (R/W)  Mask Register 1 */
  volatile uint32_t FUNCTION1;              /*!< Offset: 0x038 (R/W)  Function Register 1 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[1];
  volatile uint32_t COMP2;                  /*!< Offset: 0x040 (R/W)  Comparator Register 2 */
  volatile uint32_t MASK2;                  /*!< Offset: 0x044 (R/W)  Mask Register 2 */
  volatile uint32_t FUNCTION2;              /*!< Offset: 0x048 (R/W)  Function Register 2 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[1];
  volatile uint32_t COMP3;                  /*!< Offset: 0x050 (R/W)  Comparator Register 3 */
  volatile uint32_t MASK3;                  /*!< Offset: 0x054 (R/W)  Mask Register 3 */
  volatile uint32_t FUNCTION3;              /*!< Offset: 0x058 (R/W)  Function Register 3 */
};

constexpr size_t    kDWT_size = 0x5C;
constexpr uintptr_t kDWT_base = 0xE0001000;  /*!< DWT Base Address */

constexpr regs::RegGroup<DWT_Layout, kDWT_size, kDWT_base> DWT;

template <auto Member, size_t Bits, unsigned int Shift,
          bool DirectAssign = false>
using DWT_Reg =
    regs::Reg32<kDWT_base, DWT_Layout, Member, 0, Bits, Shift, DirectAssign>;

// Undefine anything defined by Teensyduino's imxrt.h

// DWT Control Register Definitions
#undef DWT_CTRL_NUMCOMP
constexpr DWT_Reg<&DWT_Layout::CTRL, 4, 28> DWT_CTRL_NUMCOMP;
#undef DWT_CTRL_NOTRCPKT
constexpr DWT_Reg<&DWT_Layout::CTRL, 1, 27> DWT_CTRL_NOTRCPKT;
#undef DWT_CTRL_NOEXTTRIG
constexpr DWT_Reg<&DWT_Layout::CTRL, 1, 26> DWT_CTRL_NOEXTTRIG;
#undef DWT_CTRL_NOCYCCNT
constexpr DWT_Reg<&DWT_Layout::CTRL, 1, 25> DWT_CTRL_NOCYCCNT;
#undef DWT_CTRL_NOPRFCNT
constexpr DWT_Reg<&DWT_Layout::CTRL, 1, 24> DWT_CTRL_NOPRFCNT;
#undef DWT_CTRL_CYCEVTENA
constexpr DWT_Reg<&DWT_Layout::CTRL, 1, 22> DWT_CTRL_CYCEVTENA;
#undef DWT_CTRL_FOLDEVTENA
constexpr DWT_Reg<&DWT_Layout::CTRL, 1, 21> DWT_CTRL_FOLDEVTENA;
#undef DWT_CTRL_LSUEVTENA
constexpr DWT_Reg<&DWT_Layout::CTRL, 1, 20> DWT_CTRL_LSUEVTENA;
#undef DWT_CTRL_SLEEPEVTENA
constexpr DWT_Reg<&DWT_Layout::CTRL, 1, 19> DWT_CTRL_SLEEPEVTENA;
#undef DWT_CTRL_EXCEVTENA
constexpr DWT_Reg<&DWT_Layout::CTRL, 1, 18> DWT_CTRL_EXCEVTENA;
#undef DWT_CTRL_CPIEVTENA
constexpr DWT_Reg<&DWT_Layout::CTRL, 1, 17> DWT_CTRL_CPIEVTENA;
#undef DWT_CTRL_EXCTRCENA
constexpr DWT_Reg<&DWT_Layout::CTRL, 1, 16> DWT_CTRL_EXCTRCENA;
#undef DWT_CTRL_PCSAMPLENA
constexpr DWT_Reg<&DWT_Layout::CTRL, 1, 12> DWT_CTRL_PCSAMPLENA;
#undef DWT_CTRL_SYNCTAP
constexpr DWT_Reg<&DWT_Layout::CTRL, 2, 10> DWT_CTRL_SYNCTAP;
#undef DWT_CTRL_CYCTAP
constexpr DWT_Reg<&DWT_Layout::CTRL, 1,  9> DWT_CTRL_CYCTAP;
#undef DWT_CTRL_POSTINIT
constexpr DWT_Reg<&DWT_Layout::CTRL, 4,  5> DWT_CTRL_POSTINIT;
#undef DWT_CTRL_POSTPRESET
constexpr DWT_Reg<&DWT_Layout::CTRL, 4,  1> DWT_CTRL_POSTPRESET;
#undef DWT_CTRL_CYCCNTENA
constexpr DWT_Reg<&DWT_Layout::CTRL, 1,  0> DWT_CTRL_CYCCNTENA;

// DWT CPI Count Register Definitions
#undef DWT_CPICNT_CPICNT
constexpr DWT_Reg<&DWT_Layout::CPICNT, 8, 0> DWT_CPICNT_CPICNT;

// DWT Exception Overhead Count Register Definitions
#undef DWT_EXCCNT_EXCCNT
constexpr DWT_Reg<&DWT_Layout::EXCCNT, 8, 0> DWT_EXCCNT_EXCCNT;

// DWT Sleep Count Register Definitions
#undef DWT_SLEEPCNT_SLEEPCNT
constexpr DWT_Reg<&DWT_Layout::SLEEPCNT, 8, 0> DWT_SLEEPCNT_SLEEPCNT;

// DWT LSU Count Register Definitions
#undef DWT_LSUCNT_LSUCNT
constexpr DWT_Reg<&DWT_Layout::LSUCNT, 8, 0> DWT_LSUCNT_LSUCNT;

// DWT Folded-instruction Count Register Definitions
#undef DWT_FOLDCNT_FOLDCNT
constexpr DWT_Reg<&DWT_Layout::FOLDCNT, 8, 0> DWT_FOLDCNT_FOLDCNT;

// DWT Comparator Mask Register Definitions
#undef DWT_MASK_MASK
constexpr regs::RegValue32<5, 0> DWT_MASK_MASK;

// DWT Comparator Function Register Definitions
#undef DWT_FUNCTION_MATCHED
constexpr regs::RegValue32<1, 24> DWT_FUNCTION_MATCHED;
#undef DWT_FUNCTION_DATAVADDR1
constexpr regs::RegValue32<4, 16> DWT_FUNCTION_DATAVADDR1;
#undef DWT_FUNCTION_DATAVADDR0
constexpr regs::RegValue32<4, 12> DWT_FUNCTION_DATAVADDR0;
#undef DWT_FUNCTION_DATAVSIZE
constexpr regs::RegValue32<2, 10> DWT_FUNCTION_DATAVSIZE;
#undef DWT_FUNCTION_LNK1ENA
constexpr regs::RegValue32<1,  9> DWT_FUNCTION_LNK1ENA;
#undef DWT_FUNCTION_DATAVMATCH
constexpr regs::RegValue32<1,  8> DWT_FUNCTION_DATAVMATCH;
#undef DWT_FUNCTION_CYCMATCH
constexpr regs::RegValue32<1,  7> DWT_FUNCTION_CYCMATCH;
#undef DWT_FUNCTION_EMITRANGE
constexpr regs::RegValue32<1,  5> DWT_FUNCTION_EMITRANGE;
#undef DWT_FUNCTION_FUNCTION
constexpr regs::RegValue32<4,  0> DWT_FUNCTION_FUNCTION;

}  // namespace teensy4
}  // namespace hardware
}  // namespace qindesign
