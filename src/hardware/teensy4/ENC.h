// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// ENC.h defines all the ENC registers.
// This file is part of the TeensyRegs library.

#pragma once

#include <cstddef>
#include <cstdint>

#include "hardware/regs/regs.h"

namespace qindesign {
namespace hardware {
namespace teensy4 {

// ENC layout. Comments are from BSD-3-licensed NXP SDK.
//
// See:
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/periph/PERI_ENC.h
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/MIMXRT1062/MIMXRT1062_COMMON.h
struct ENC_Layout {
  volatile uint16_t CTRL;                              /**< Control Register, offset: 0x0 */
  volatile uint16_t FILT;                              /**< Input Filter Register, offset: 0x2 */
  volatile uint16_t WTR;                               /**< Watchdog Timeout Register, offset: 0x4 */
  volatile uint16_t POSD;                              /**< Position Difference Counter Register, offset: 0x6 */
  const volatile uint16_t POSDH;                       /**< Position Difference Hold Register, offset: 0x8 */
  volatile uint16_t REV;                               /**< Revolution Counter Register, offset: 0xA */
  const volatile uint16_t REVH;                        /**< Revolution Hold Register, offset: 0xC */
  volatile uint16_t UPOS;                              /**< Upper Position Counter Register, offset: 0xE */
  volatile uint16_t LPOS;                              /**< Lower Position Counter Register, offset: 0x10 */
  const volatile uint16_t UPOSH;                       /**< Upper Position Hold Register, offset: 0x12 */
  const volatile uint16_t LPOSH;                       /**< Lower Position Hold Register, offset: 0x14 */
  volatile uint16_t UINIT;                             /**< Upper Initialization Register, offset: 0x16 */
  volatile uint16_t LINIT;                             /**< Lower Initialization Register, offset: 0x18 */
  const volatile uint16_t IMR;                         /**< Input Monitor Register, offset: 0x1A */
  volatile uint16_t TST;                               /**< Test Register, offset: 0x1C */
  volatile uint16_t CTRL2;                             /**< Control 2 Register, offset: 0x1E */
  volatile uint16_t UMOD;                              /**< Upper Modulus Register, offset: 0x20 */
  volatile uint16_t LMOD;                              /**< Lower Modulus Register, offset: 0x22 */
  volatile uint16_t UCOMP;                             /**< Upper Position Compare Register, offset: 0x24 */
  volatile uint16_t LCOMP;                             /**< Lower Position Compare Register, offset: 0x26 */
};

constexpr size_t    kENC_size  = 0x28;
constexpr uintptr_t kENC1_base = 0x403C8000;
constexpr uintptr_t kENC2_base = 0x403CC000;
constexpr uintptr_t kENC3_base = 0x403D0000;
constexpr uintptr_t kENC4_base = 0x403D4000;

constexpr regs::RegGroup<ENC_Layout, kENC_size, kENC1_base> ENC1;
constexpr regs::RegGroup<ENC_Layout, kENC_size, kENC2_base> ENC2;
constexpr regs::RegGroup<ENC_Layout, kENC_size, kENC3_base> ENC3;
constexpr regs::RegGroup<ENC_Layout, kENC_size, kENC4_base> ENC4;

template <auto Member, size_t Bits, unsigned int Shift,
          bool DirectAssign = false>
using ENC1_Reg = regs::Reg<uint16_t, kENC1_base, ENC_Layout, Member, 0, Bits,
                           Shift, DirectAssign>;

template <auto Member, size_t Bits, unsigned int Shift,
          bool DirectAssign = false>
using ENC2_Reg = regs::Reg<uint16_t, kENC2_base, ENC_Layout, Member, 0, Bits,
                           Shift, DirectAssign>;

template <auto Member, size_t Bits, unsigned int Shift,
          bool DirectAssign = false>
using ENC3_Reg = regs::Reg<uint16_t, kENC3_base, ENC_Layout, Member, 0, Bits,
                           Shift, DirectAssign>;

template <auto Member, size_t Bits, unsigned int Shift,
          bool DirectAssign = false>
using ENC4_Reg = regs::Reg<uint16_t, kENC4_base, ENC_Layout, Member, 0, Bits,
                           Shift, DirectAssign>;

// Undefine anything defined by Teensyduino's imxrt.h

// ENC1 Control Register
#undef ENC1_CTRL_HIRQ
constexpr ENC1_Reg<&ENC_Layout::CTRL, 1, 15> ENC1_CTRL_HIRQ;    // HOME Signal Transition Interrupt Request
    // 0b0..No transition on the HOME signal has occurred
    // 0b1..A transition on the HOME signal has occurred
#undef ENC1_CTRL_HIE
constexpr ENC1_Reg<&ENC_Layout::CTRL, 1, 14> ENC1_CTRL_HIE;     // HOME Interrupt Enable
    // 0b0..Disabled
    // 0b1..Enabled
#undef ENC1_CTRL_HIP
constexpr ENC1_Reg<&ENC_Layout::CTRL, 1, 13> ENC1_CTRL_HIP;     // Enable HOME to Initialize Position Counters UPOS and LPOS
    // 0b0..No action
    // 0b1..HOME signal initializes the position counter
#undef ENC1_CTRL_HNE
constexpr ENC1_Reg<&ENC_Layout::CTRL, 1, 12> ENC1_CTRL_HNE;     // Use Negative Edge of HOME Input
    // 0b0..Use positive-going edge-to-trigger initialization of position counters UPOS and LPOS
    // 0b1..Use negative-going edge-to-trigger initialization of position counters UPOS and LPOS
#undef ENC1_CTRL_SWIP
constexpr ENC1_Reg<&ENC_Layout::CTRL, 1, 11> ENC1_CTRL_SWIP;    // Software-Triggered Initialization of Position Counters UPOS and LPOS
    // 0b0..No action
    // 0b1..Initialize position counter (using upper and lower initialization registers, UINIT and LINIT)
#undef ENC1_CTRL_REV
constexpr ENC1_Reg<&ENC_Layout::CTRL, 1, 10> ENC1_CTRL_REV;     // Enable Reverse Direction Counting
    // 0b0..Count normally
    // 0b1..Count in the reverse direction
#undef ENC1_CTRL_PH1
constexpr ENC1_Reg<&ENC_Layout::CTRL, 1,  9> ENC1_CTRL_PH1;     // Enable Signal Phase Count Mode
    // 0b0..Use the standard quadrature decoder, where PHASEA and PHASEB represent a two-phase quadrature signal.
    // 0b1..Bypass the quadrature decoder. A positive transition of the PHASEA input generates a count signal. The
    //      PHASEB input and the REV bit control the counter direction: If CTRL[REV] = 0, PHASEB = 0, then count up If
    //      CTRL[REV] = 1, PHASEB = 1, then count up If CTRL[REV] = 0, PHASEB = 1, then count down If CTRL[REV] = 1,
    //      PHASEB = 0, then count down
#undef ENC1_CTRL_XIRQ
constexpr ENC1_Reg<&ENC_Layout::CTRL, 1,  8> ENC1_CTRL_XIRQ;    // INDEX Pulse Interrupt Request
    // 0b0..INDEX pulse has not occurred
    // 0b1..INDEX pulse has occurred
#undef ENC1_CTRL_XIE
constexpr ENC1_Reg<&ENC_Layout::CTRL, 1,  7> ENC1_CTRL_XIE;     // INDEX Pulse Interrupt Enable
    // 0b0..Disabled
    // 0b1..Enabled
#undef ENC1_CTRL_XIP
constexpr ENC1_Reg<&ENC_Layout::CTRL, 1,  6> ENC1_CTRL_XIP;     // INDEX Triggered Initialization of Position Counters UPOS and LPOS
    // 0b0..INDEX pulse does not initialize the position counter
    // 0b1..INDEX pulse initializes the position counter
#undef ENC1_CTRL_XNE
constexpr ENC1_Reg<&ENC_Layout::CTRL, 1,  5> ENC1_CTRL_XNE;     // Use Negative Edge of INDEX Pulse
    // 0b0..Use positive edge of INDEX pulse
    // 0b1..Use negative edge of INDEX pulse
#undef ENC1_CTRL_DIRQ
constexpr ENC1_Reg<&ENC_Layout::CTRL, 1,  4> ENC1_CTRL_DIRQ;    // Watchdog Timeout Interrupt Request
    // 0b0..No Watchdog timeout interrupt has occurred
    // 0b1..Watchdog timeout interrupt has occurred
#undef ENC1_CTRL_DIE
constexpr ENC1_Reg<&ENC_Layout::CTRL, 1,  3> ENC1_CTRL_DIE;     // Watchdog Timeout Interrupt Enable
    // 0b0..Disabled
    // 0b1..Enabled
#undef ENC1_CTRL_WDE
constexpr ENC1_Reg<&ENC_Layout::CTRL, 1,  2> ENC1_CTRL_WDE;     // Watchdog Enable
    // 0b0..Disabled
    // 0b1..Enabled
#undef ENC1_CTRL_CMPIRQ
constexpr ENC1_Reg<&ENC_Layout::CTRL, 1,  1> ENC1_CTRL_CMPIRQ;  // Compare Interrupt Request
    // 0b0..No match has occurred (the counter does not match the COMP value)
    // 0b1..COMP match has occurred (the counter matches the COMP value)
#undef ENC1_CTRL_CMPIE
constexpr ENC1_Reg<&ENC_Layout::CTRL, 1,  0> ENC1_CTRL_CMPIE;   // Compare Interrupt Enable
    // 0b0..Disabled
    // 0b1..Enabled

// ENC1 Input Filter Register
#undef ENC1_FILT_FILT_PRSC
constexpr ENC1_Reg<&ENC_Layout::FILT, 3, 13> ENC1_FILT_FILT_PRSC;  // prescaler divide IPbus clock to FILT clk
#undef ENC1_FILT_FILT_CNT
constexpr ENC1_Reg<&ENC_Layout::FILT, 3,  8> ENC1_FILT_FILT_CNT;   // Input Filter Sample Count
#undef ENC1_FILT_FILT_PER
constexpr ENC1_Reg<&ENC_Layout::FILT, 8,  0> ENC1_FILT_FILT_PER;   // Input Filter Sample Period

// ENC1 Input Monitor Register
#undef ENC1_IMR_FPHA
constexpr ENC1_Reg<&ENC_Layout::IMR, 1, 7> ENC1_IMR_FPHA;
#undef ENC1_IMR_FPHB
constexpr ENC1_Reg<&ENC_Layout::IMR, 1, 6> ENC1_IMR_FPHB;
#undef ENC1_IMR_FIND
constexpr ENC1_Reg<&ENC_Layout::IMR, 1, 5> ENC1_IMR_FIND;
#undef ENC1_IMR_FHOM
constexpr ENC1_Reg<&ENC_Layout::IMR, 1, 4> ENC1_IMR_FHOM;
#undef ENC1_IMR_PHA
constexpr ENC1_Reg<&ENC_Layout::IMR, 1, 3> ENC1_IMR_PHA;
#undef ENC1_IMR_PHB
constexpr ENC1_Reg<&ENC_Layout::IMR, 1, 2> ENC1_IMR_PHB;
#undef ENC1_IMR_INDEX
constexpr ENC1_Reg<&ENC_Layout::IMR, 1, 1> ENC1_IMR_INDEX;
#undef ENC1_IMR_HOME
constexpr ENC1_Reg<&ENC_Layout::IMR, 1, 0> ENC1_IMR_HOME;

// ENC1 Test Register
#undef ENC1_TST_TEN
constexpr ENC1_Reg<&ENC_Layout::TST,  1, 15> ENC1_TST_TEN;  // Test Mode Enable
    // 0b0..Disabled
    // 0b1..Enabled
#undef ENC1_TST_TCE
constexpr ENC1_Reg<&ENC_Layout::TST,  1, 14> ENC1_TST_TCE;  // Test Counter Enable
    // 0b0..Disabled
    // 0b1..Enabled
#undef ENC1_TST_QDN
constexpr ENC1_Reg<&ENC_Layout::TST,  1, 13> ENC1_TST_QDN;  // Quadrature Decoder Negative Signal
    // 0b0..Generates a positive quadrature decoder signal
    // 0b1..Generates a negative quadrature decoder signal
#undef ENC1_TST_TEST_PERIOD
constexpr ENC1_Reg<&ENC_Layout::TST,  5,  8> ENC1_TST_TEST_PERIOD;
#undef ENC1_TST_TEST_COUNT
constexpr ENC1_Reg<&ENC_Layout::TST,  8,  0> ENC1_TST_TEST_COUNT;

// ENC1 Control 2 Register
#undef ENC1_CTRL2_OUTCTL
constexpr ENC1_Reg<&ENC_Layout::CTRL2,  1,  9> ENC1_CTRL2_OUTCTL;  // Output Control
    // 0b0..POSMATCH pulses when a match occurs between the position counters (POS) and the corresponding compare value (COMP )
    // 0b1..POSMATCH pulses when the UPOS, LPOS, REV, or POSD registers are read
#undef ENC1_CTRL2_REVMOD
constexpr ENC1_Reg<&ENC_Layout::CTRL2,  1,  8> ENC1_CTRL2_REVMOD;  // Revolution Counter Modulus Enable
    // 0b0..Use INDEX pulse to increment/decrement revolution counter (REV)
    // 0b1..Use modulus counting roll-over/under to increment/decrement revolution counter (REV)
#undef ENC1_CTRL2_ROIRQ
constexpr ENC1_Reg<&ENC_Layout::CTRL2,  1,  7> ENC1_CTRL2_ROIRQ;   // Roll-over Interrupt Request
    // 0b0..No roll-over has occurred
    // 0b1..Roll-over has occurred
#undef ENC1_CTRL2_ROIE
constexpr ENC1_Reg<&ENC_Layout::CTRL2,  1,  6> ENC1_CTRL2_ROIE;    // Roll-over Interrupt Enable
    // 0b0..Disabled
    // 0b1..Enabled
#undef ENC1_CTRL2_RUIRQ
constexpr ENC1_Reg<&ENC_Layout::CTRL2,  1,  5> ENC1_CTRL2_RUIRQ;   // Roll-under Interrupt Request
    // 0b0..No roll-under has occurred
    // 0b1..Roll-under has occurred
#undef ENC1_CTRL2_RUIE
constexpr ENC1_Reg<&ENC_Layout::CTRL2,  1,  4> ENC1_CTRL2_RUIE;    // Roll-under Interrupt Enable
    // 0b0..Disabled
    // 0b1..Enabled
#undef ENC1_CTRL2_DIR
constexpr ENC1_Reg<&ENC_Layout::CTRL2,  1,  3> ENC1_CTRL2_DIR;     // Count Direction Flag
    // 0b0..Last count was in the down direction
    // 0b1..Last count was in the up direction
#undef ENC1_CTRL2_MOD
constexpr ENC1_Reg<&ENC_Layout::CTRL2,  1,  2> ENC1_CTRL2_MOD;     // Enable Modulo Counting
    // 0b0..Disable modulo counting
    // 0b1..Enable modulo counting
#undef ENC1_CTRL2_UPDPOS
constexpr ENC1_Reg<&ENC_Layout::CTRL2,  1,  1> ENC1_CTRL2_UPDPOS;  // Update Position Registers
    // 0b0..No action for POSD, REV, UPOS and LPOS registers on rising edge of TRIGGER
    // 0b1..Clear POSD, REV, UPOS and LPOS registers on rising edge of TRIGGER
#undef ENC1_CTRL2_UPDHLD
constexpr ENC1_Reg<&ENC_Layout::CTRL2,  1,  0> ENC1_CTRL2_UPDHLD;  // Update Hold Registers
    // 0b0..Disable updates of hold registers on the rising edge of TRIGGER input signal
    // 0b1..Enable updates of hold registers on the rising edge of TRIGGER input signal

// ENC2 Control Register
#undef ENC2_CTRL_HIRQ
constexpr ENC2_Reg<&ENC_Layout::CTRL, 1, 15> ENC2_CTRL_HIRQ;
#undef ENC2_CTRL_HIE
constexpr ENC2_Reg<&ENC_Layout::CTRL, 1, 14> ENC2_CTRL_HIE;
#undef ENC2_CTRL_HIP
constexpr ENC2_Reg<&ENC_Layout::CTRL, 1, 13> ENC2_CTRL_HIP;
#undef ENC2_CTRL_HNE
constexpr ENC2_Reg<&ENC_Layout::CTRL, 1, 12> ENC2_CTRL_HNE;
#undef ENC2_CTRL_SWIP
constexpr ENC2_Reg<&ENC_Layout::CTRL, 1, 11> ENC2_CTRL_SWIP;
#undef ENC2_CTRL_REV
constexpr ENC2_Reg<&ENC_Layout::CTRL, 1, 10> ENC2_CTRL_REV;
#undef ENC2_CTRL_PH1
constexpr ENC2_Reg<&ENC_Layout::CTRL, 1,  9> ENC2_CTRL_PH1;
#undef ENC2_CTRL_XIRQ
constexpr ENC2_Reg<&ENC_Layout::CTRL, 1,  8> ENC2_CTRL_XIRQ;
#undef ENC2_CTRL_XIE
constexpr ENC2_Reg<&ENC_Layout::CTRL, 1,  7> ENC2_CTRL_XIE;
#undef ENC2_CTRL_XIP
constexpr ENC2_Reg<&ENC_Layout::CTRL, 1,  6> ENC2_CTRL_XIP;
#undef ENC2_CTRL_XNE
constexpr ENC2_Reg<&ENC_Layout::CTRL, 1,  5> ENC2_CTRL_XNE;
#undef ENC2_CTRL_DIRQ
constexpr ENC2_Reg<&ENC_Layout::CTRL, 1,  4> ENC2_CTRL_DIRQ;
#undef ENC2_CTRL_DIE
constexpr ENC2_Reg<&ENC_Layout::CTRL, 1,  3> ENC2_CTRL_DIE;
#undef ENC2_CTRL_WDE
constexpr ENC2_Reg<&ENC_Layout::CTRL, 1,  2> ENC2_CTRL_WDE;
#undef ENC2_CTRL_CMPIRQ
constexpr ENC2_Reg<&ENC_Layout::CTRL, 1,  1> ENC2_CTRL_CMPIRQ;
#undef ENC2_CTRL_CMPIE
constexpr ENC2_Reg<&ENC_Layout::CTRL, 1,  0> ENC2_CTRL_CMPIE;

// ENC2 Input Filter Register
#undef ENC2_FILT_FILT_PRSC
constexpr ENC2_Reg<&ENC_Layout::FILT, 3, 13> ENC2_FILT_FILT_PRSC;
#undef ENC2_FILT_FILT_CNT
constexpr ENC2_Reg<&ENC_Layout::FILT, 3,  8> ENC2_FILT_FILT_CNT;
#undef ENC2_FILT_FILT_PER
constexpr ENC2_Reg<&ENC_Layout::FILT, 8,  0> ENC2_FILT_FILT_PER;

// ENC2 Input Monitor Register
#undef ENC2_IMR_FPHA
constexpr ENC2_Reg<&ENC_Layout::IMR, 1, 7> ENC2_IMR_FPHA;
#undef ENC2_IMR_FPHB
constexpr ENC2_Reg<&ENC_Layout::IMR, 1, 6> ENC2_IMR_FPHB;
#undef ENC2_IMR_FIND
constexpr ENC2_Reg<&ENC_Layout::IMR, 1, 5> ENC2_IMR_FIND;
#undef ENC2_IMR_FHOM
constexpr ENC2_Reg<&ENC_Layout::IMR, 1, 4> ENC2_IMR_FHOM;
#undef ENC2_IMR_PHA
constexpr ENC2_Reg<&ENC_Layout::IMR, 1, 3> ENC2_IMR_PHA;
#undef ENC2_IMR_PHB
constexpr ENC2_Reg<&ENC_Layout::IMR, 1, 2> ENC2_IMR_PHB;
#undef ENC2_IMR_INDEX
constexpr ENC2_Reg<&ENC_Layout::IMR, 1, 1> ENC2_IMR_INDEX;
#undef ENC2_IMR_HOME
constexpr ENC2_Reg<&ENC_Layout::IMR, 1, 0> ENC2_IMR_HOME;

// ENC2 Test Register
#undef ENC2_TST_TEN
constexpr ENC2_Reg<&ENC_Layout::TST, 1, 15> ENC2_TST_TEN;
#undef ENC2_TST_TCE
constexpr ENC2_Reg<&ENC_Layout::TST, 1, 14> ENC2_TST_TCE;
#undef ENC2_TST_QDN
constexpr ENC2_Reg<&ENC_Layout::TST, 1, 13> ENC2_TST_QDN;
#undef ENC2_TST_TEST_PERIOD
constexpr ENC2_Reg<&ENC_Layout::TST, 5,  8> ENC2_TST_TEST_PERIOD;
#undef ENC2_TST_TEST_COUNT
constexpr ENC2_Reg<&ENC_Layout::TST, 8,  0> ENC2_TST_TEST_COUNT;

// ENC2 Control 2 Register
#undef ENC2_CTRL2_OUTCTL
constexpr ENC2_Reg<&ENC_Layout::CTRL2, 1, 9> ENC2_CTRL2_OUTCTL;
#undef ENC2_CTRL2_REVMOD
constexpr ENC2_Reg<&ENC_Layout::CTRL2, 1, 8> ENC2_CTRL2_REVMOD;
#undef ENC2_CTRL2_ROIRQ
constexpr ENC2_Reg<&ENC_Layout::CTRL2, 1, 7> ENC2_CTRL2_ROIRQ;
#undef ENC2_CTRL2_ROIE
constexpr ENC2_Reg<&ENC_Layout::CTRL2, 1, 6> ENC2_CTRL2_ROIE;
#undef ENC2_CTRL2_RUIRQ
constexpr ENC2_Reg<&ENC_Layout::CTRL2, 1, 5> ENC2_CTRL2_RUIRQ;
#undef ENC2_CTRL2_RUIE
constexpr ENC2_Reg<&ENC_Layout::CTRL2, 1, 4> ENC2_CTRL2_RUIE;
#undef ENC2_CTRL2_DIR
constexpr ENC2_Reg<&ENC_Layout::CTRL2, 1, 3> ENC2_CTRL2_DIR;
#undef ENC2_CTRL2_MOD
constexpr ENC2_Reg<&ENC_Layout::CTRL2, 1, 2> ENC2_CTRL2_MOD;
#undef ENC2_CTRL2_UPDPOS
constexpr ENC2_Reg<&ENC_Layout::CTRL2, 1, 1> ENC2_CTRL2_UPDPOS;
#undef ENC2_CTRL2_UPDHLD
constexpr ENC2_Reg<&ENC_Layout::CTRL2, 1, 0> ENC2_CTRL2_UPDHLD;

// ENC3 Control Register
#undef ENC3_CTRL_HIRQ
constexpr ENC3_Reg<&ENC_Layout::CTRL, 1, 15> ENC3_CTRL_HIRQ;
#undef ENC3_CTRL_HIE
constexpr ENC3_Reg<&ENC_Layout::CTRL, 1, 14> ENC3_CTRL_HIE;
#undef ENC3_CTRL_HIP
constexpr ENC3_Reg<&ENC_Layout::CTRL, 1, 13> ENC3_CTRL_HIP;
#undef ENC3_CTRL_HNE
constexpr ENC3_Reg<&ENC_Layout::CTRL, 1, 12> ENC3_CTRL_HNE;
#undef ENC3_CTRL_SWIP
constexpr ENC3_Reg<&ENC_Layout::CTRL, 1, 11> ENC3_CTRL_SWIP;
#undef ENC3_CTRL_REV
constexpr ENC3_Reg<&ENC_Layout::CTRL, 1, 10> ENC3_CTRL_REV;
#undef ENC3_CTRL_PH1
constexpr ENC3_Reg<&ENC_Layout::CTRL, 1,  9> ENC3_CTRL_PH1;
#undef ENC3_CTRL_XIRQ
constexpr ENC3_Reg<&ENC_Layout::CTRL, 1,  8> ENC3_CTRL_XIRQ;
#undef ENC3_CTRL_XIE
constexpr ENC3_Reg<&ENC_Layout::CTRL, 1,  7> ENC3_CTRL_XIE;
#undef ENC3_CTRL_XIP
constexpr ENC3_Reg<&ENC_Layout::CTRL, 1,  6> ENC3_CTRL_XIP;
#undef ENC3_CTRL_XNE
constexpr ENC3_Reg<&ENC_Layout::CTRL, 1,  5> ENC3_CTRL_XNE;
#undef ENC3_CTRL_DIRQ
constexpr ENC3_Reg<&ENC_Layout::CTRL, 1,  4> ENC3_CTRL_DIRQ;
#undef ENC3_CTRL_DIE
constexpr ENC3_Reg<&ENC_Layout::CTRL, 1,  3> ENC3_CTRL_DIE;
#undef ENC3_CTRL_WDE
constexpr ENC3_Reg<&ENC_Layout::CTRL, 1,  2> ENC3_CTRL_WDE;
#undef ENC3_CTRL_CMPIRQ
constexpr ENC3_Reg<&ENC_Layout::CTRL, 1,  1> ENC3_CTRL_CMPIRQ;
#undef ENC3_CTRL_CMPIE
constexpr ENC3_Reg<&ENC_Layout::CTRL, 1,  0> ENC3_CTRL_CMPIE;

// ENC3 Input Filter Register
#undef ENC3_FILT_FILT_PRSC
constexpr ENC3_Reg<&ENC_Layout::FILT, 3, 13> ENC3_FILT_FILT_PRSC;
#undef ENC3_FILT_FILT_CNT
constexpr ENC3_Reg<&ENC_Layout::FILT, 3,  8> ENC3_FILT_FILT_CNT;
#undef ENC3_FILT_FILT_PER
constexpr ENC3_Reg<&ENC_Layout::FILT, 8,  0> ENC3_FILT_FILT_PER;

// ENC3 Input Monitor Register
#undef ENC3_IMR_FPHA
constexpr ENC3_Reg<&ENC_Layout::IMR, 1, 7> ENC3_IMR_FPHA;
#undef ENC3_IMR_FPHB
constexpr ENC3_Reg<&ENC_Layout::IMR, 1, 6> ENC3_IMR_FPHB;
#undef ENC3_IMR_FIND
constexpr ENC3_Reg<&ENC_Layout::IMR, 1, 5> ENC3_IMR_FIND;
#undef ENC3_IMR_FHOM
constexpr ENC3_Reg<&ENC_Layout::IMR, 1, 4> ENC3_IMR_FHOM;
#undef ENC3_IMR_PHA
constexpr ENC3_Reg<&ENC_Layout::IMR, 1, 3> ENC3_IMR_PHA;
#undef ENC3_IMR_PHB
constexpr ENC3_Reg<&ENC_Layout::IMR, 1, 2> ENC3_IMR_PHB;
#undef ENC3_IMR_INDEX
constexpr ENC3_Reg<&ENC_Layout::IMR, 1, 1> ENC3_IMR_INDEX;
#undef ENC3_IMR_HOME
constexpr ENC3_Reg<&ENC_Layout::IMR, 1, 0> ENC3_IMR_HOME;

// ENC3 Test Register
#undef ENC3_TST_TEN
constexpr ENC3_Reg<&ENC_Layout::TST, 1, 15> ENC3_TST_TEN;
#undef ENC3_TST_TCE
constexpr ENC3_Reg<&ENC_Layout::TST, 1, 14> ENC3_TST_TCE;
#undef ENC3_TST_QDN
constexpr ENC3_Reg<&ENC_Layout::TST, 1, 13> ENC3_TST_QDN;
#undef ENC3_TST_TEST_PERIOD
constexpr ENC3_Reg<&ENC_Layout::TST, 5,  8> ENC3_TST_TEST_PERIOD;
#undef ENC3_TST_TEST_COUNT
constexpr ENC3_Reg<&ENC_Layout::TST, 8,  0> ENC3_TST_TEST_COUNT;

// ENC3 Control 2 Register
#undef ENC3_CTRL2_OUTCTL
constexpr ENC3_Reg<&ENC_Layout::CTRL2, 1, 9> ENC3_CTRL2_OUTCTL;
#undef ENC3_CTRL2_REVMOD
constexpr ENC3_Reg<&ENC_Layout::CTRL2, 1, 8> ENC3_CTRL2_REVMOD;
#undef ENC3_CTRL2_ROIRQ
constexpr ENC3_Reg<&ENC_Layout::CTRL2, 1, 7> ENC3_CTRL2_ROIRQ;
#undef ENC3_CTRL2_ROIE
constexpr ENC3_Reg<&ENC_Layout::CTRL2, 1, 6> ENC3_CTRL2_ROIE;
#undef ENC3_CTRL2_RUIRQ
constexpr ENC3_Reg<&ENC_Layout::CTRL2, 1, 5> ENC3_CTRL2_RUIRQ;
#undef ENC3_CTRL2_RUIE
constexpr ENC3_Reg<&ENC_Layout::CTRL2, 1, 4> ENC3_CTRL2_RUIE;
#undef ENC3_CTRL2_DIR
constexpr ENC3_Reg<&ENC_Layout::CTRL2, 1, 3> ENC3_CTRL2_DIR;
#undef ENC3_CTRL2_MOD
constexpr ENC3_Reg<&ENC_Layout::CTRL2, 1, 2> ENC3_CTRL2_MOD;
#undef ENC3_CTRL2_UPDPOS
constexpr ENC3_Reg<&ENC_Layout::CTRL2, 1, 1> ENC3_CTRL2_UPDPOS;
#undef ENC3_CTRL2_UPDHLD
constexpr ENC3_Reg<&ENC_Layout::CTRL2, 1, 0> ENC3_CTRL2_UPDHLD;

// ENC4 Control Register
#undef ENC4_CTRL_HIRQ
constexpr ENC4_Reg<&ENC_Layout::CTRL, 1, 15> ENC4_CTRL_HIRQ;
#undef ENC4_CTRL_HIE
constexpr ENC4_Reg<&ENC_Layout::CTRL, 1, 14> ENC4_CTRL_HIE;
#undef ENC4_CTRL_HIP
constexpr ENC4_Reg<&ENC_Layout::CTRL, 1, 13> ENC4_CTRL_HIP;
#undef ENC4_CTRL_HNE
constexpr ENC4_Reg<&ENC_Layout::CTRL, 1, 12> ENC4_CTRL_HNE;
#undef ENC4_CTRL_SWIP
constexpr ENC4_Reg<&ENC_Layout::CTRL, 1, 11> ENC4_CTRL_SWIP;
#undef ENC4_CTRL_REV
constexpr ENC4_Reg<&ENC_Layout::CTRL, 1, 10> ENC4_CTRL_REV;
#undef ENC4_CTRL_PH1
constexpr ENC4_Reg<&ENC_Layout::CTRL, 1,  9> ENC4_CTRL_PH1;
#undef ENC4_CTRL_XIRQ
constexpr ENC4_Reg<&ENC_Layout::CTRL, 1,  8> ENC4_CTRL_XIRQ;
#undef ENC4_CTRL_XIE
constexpr ENC4_Reg<&ENC_Layout::CTRL, 1,  7> ENC4_CTRL_XIE;
#undef ENC4_CTRL_XIP
constexpr ENC4_Reg<&ENC_Layout::CTRL, 1,  6> ENC4_CTRL_XIP;
#undef ENC4_CTRL_XNE
constexpr ENC4_Reg<&ENC_Layout::CTRL, 1,  5> ENC4_CTRL_XNE;
#undef ENC4_CTRL_DIRQ
constexpr ENC4_Reg<&ENC_Layout::CTRL, 1,  4> ENC4_CTRL_DIRQ;
#undef ENC4_CTRL_DIE
constexpr ENC4_Reg<&ENC_Layout::CTRL, 1,  3> ENC4_CTRL_DIE;
#undef ENC4_CTRL_WDE
constexpr ENC4_Reg<&ENC_Layout::CTRL, 1,  2> ENC4_CTRL_WDE;
#undef ENC4_CTRL_CMPIRQ
constexpr ENC4_Reg<&ENC_Layout::CTRL, 1,  1> ENC4_CTRL_CMPIRQ;
#undef ENC4_CTRL_CMPIE
constexpr ENC4_Reg<&ENC_Layout::CTRL, 1,  0> ENC4_CTRL_CMPIE;

// ENC4 Input Filter Register
#undef ENC4_FILT_FILT_PRSC
constexpr ENC4_Reg<&ENC_Layout::FILT, 3, 13> ENC4_FILT_FILT_PRSC;
#undef ENC4_FILT_FILT_CNT
constexpr ENC4_Reg<&ENC_Layout::FILT, 3,  8> ENC4_FILT_FILT_CNT;
#undef ENC4_FILT_FILT_PER
constexpr ENC4_Reg<&ENC_Layout::FILT, 8,  0> ENC4_FILT_FILT_PER;

// ENC4 Input Monitor Register
#undef ENC4_IMR_FPHA
constexpr ENC4_Reg<&ENC_Layout::IMR, 1, 7> ENC4_IMR_FPHA;
#undef ENC4_IMR_FPHB
constexpr ENC4_Reg<&ENC_Layout::IMR, 1, 6> ENC4_IMR_FPHB;
#undef ENC4_IMR_FIND
constexpr ENC4_Reg<&ENC_Layout::IMR, 1, 5> ENC4_IMR_FIND;
#undef ENC4_IMR_FHOM
constexpr ENC4_Reg<&ENC_Layout::IMR, 1, 4> ENC4_IMR_FHOM;
#undef ENC4_IMR_PHA
constexpr ENC4_Reg<&ENC_Layout::IMR, 1, 3> ENC4_IMR_PHA;
#undef ENC4_IMR_PHB
constexpr ENC4_Reg<&ENC_Layout::IMR, 1, 2> ENC4_IMR_PHB;
#undef ENC4_IMR_INDEX
constexpr ENC4_Reg<&ENC_Layout::IMR, 1, 1> ENC4_IMR_INDEX;
#undef ENC4_IMR_HOME
constexpr ENC4_Reg<&ENC_Layout::IMR, 1, 0> ENC4_IMR_HOME;

// ENC4 Test Register
#undef ENC4_TST_TEN
constexpr ENC4_Reg<&ENC_Layout::TST, 1, 15> ENC4_TST_TEN;
#undef ENC4_TST_TCE
constexpr ENC4_Reg<&ENC_Layout::TST, 1, 14> ENC4_TST_TCE;
#undef ENC4_TST_QDN
constexpr ENC4_Reg<&ENC_Layout::TST, 1, 13> ENC4_TST_QDN;
#undef ENC4_TST_TEST_PERIOD
constexpr ENC4_Reg<&ENC_Layout::TST, 5,  8> ENC4_TST_TEST_PERIOD;
#undef ENC4_TST_TEST_COUNT
constexpr ENC4_Reg<&ENC_Layout::TST, 8,  0> ENC4_TST_TEST_COUNT;

// ENC4 Control 2 Register
#undef ENC4_CTRL2_OUTCTL
constexpr ENC4_Reg<&ENC_Layout::CTRL2, 1, 9> ENC4_CTRL2_OUTCTL;
#undef ENC4_CTRL2_REVMOD
constexpr ENC4_Reg<&ENC_Layout::CTRL2, 1, 8> ENC4_CTRL2_REVMOD;
#undef ENC4_CTRL2_ROIRQ
constexpr ENC4_Reg<&ENC_Layout::CTRL2, 1, 7> ENC4_CTRL2_ROIRQ;
#undef ENC4_CTRL2_ROIE
constexpr ENC4_Reg<&ENC_Layout::CTRL2, 1, 6> ENC4_CTRL2_ROIE;
#undef ENC4_CTRL2_RUIRQ
constexpr ENC4_Reg<&ENC_Layout::CTRL2, 1, 5> ENC4_CTRL2_RUIRQ;
#undef ENC4_CTRL2_RUIE
constexpr ENC4_Reg<&ENC_Layout::CTRL2, 1, 4> ENC4_CTRL2_RUIE;
#undef ENC4_CTRL2_DIR
constexpr ENC4_Reg<&ENC_Layout::CTRL2, 1, 3> ENC4_CTRL2_DIR;
#undef ENC4_CTRL2_MOD
constexpr ENC4_Reg<&ENC_Layout::CTRL2, 1, 2> ENC4_CTRL2_MOD;
#undef ENC4_CTRL2_UPDPOS
constexpr ENC4_Reg<&ENC_Layout::CTRL2, 1, 1> ENC4_CTRL2_UPDPOS;
#undef ENC4_CTRL2_UPDHLD
constexpr ENC4_Reg<&ENC_Layout::CTRL2, 1, 0> ENC4_CTRL2_UPDHLD;

}  // namespace teensy4
}  // namespace hardware
}  // namespace qindesign
