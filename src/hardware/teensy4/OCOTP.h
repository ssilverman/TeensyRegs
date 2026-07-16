// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// SNVS.h defines all the SNVS registers.
// This file is part of the TeensyRegs library.

#pragma once

#include <cstddef>
#include <cstdint>

#include "hardware/regs/regs.h"

namespace qindesign {
namespace hardware {
namespace teensy4 {

// OCOTP layout. Comments are from BSD-3-licensed NXP SDK.
//
// See:
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/periph/PERI_OCOTP.h
// * https://github.com/nxp-mcuxpresso/legacy-mcux-sdk/blob/main/devices/MIMXRT1062/MIMXRT1062.h

struct OCOTP_Layout {
  volatile uint32_t CTRL;                              /**< OTP Controller Control and Status Register, offset: 0x0 */
  volatile uint32_t CTRL_SET;                          /**< OTP Controller Control and Status Register, offset: 0x4 */
  volatile uint32_t CTRL_CLR;                          /**< OTP Controller Control and Status Register, offset: 0x8 */
  volatile uint32_t CTRL_TOG;                          /**< OTP Controller Control and Status Register, offset: 0xC */
  volatile uint32_t TIMING;                            /**< OTP Controller Timing Register, offset: 0x10 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t DATA;                              /**< OTP Controller Write Data Register, offset: 0x20 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t READ_CTRL;                         /**< OTP Controller Write Data Register, offset: 0x30 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t READ_FUSE_DATA;                    /**< OTP Controller Read Data Register, offset: 0x40 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t SW_STICKY;                         /**< Sticky bit Register, offset: 0x50 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t SCS;                               /**< Software Controllable Signals Register, offset: 0x60 */
  volatile uint32_t SCS_SET;                           /**< Software Controllable Signals Register, offset: 0x64 */
  volatile uint32_t SCS_CLR;                           /**< Software Controllable Signals Register, offset: 0x68 */
  volatile uint32_t SCS_TOG;                           /**< Software Controllable Signals Register, offset: 0x6C */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[8];
  const volatile uint32_t VERSION;                     /**< OTP Controller Version Register, offset: 0x90 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[27];
  volatile uint32_t TIMING2;                           /**< OTP Controller Timing Register 2, offset: 0x100 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[191];
  volatile uint32_t LOCK;                              /**< Value of OTP Bank0 Word0 (Lock controls), offset: 0x400 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t CFG0;                              /**< Value of OTP Bank0 Word1 (Configuration and Manufacturing Info.), offset: 0x410 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t CFG1;                              /**< Value of OTP Bank0 Word2 (Configuration and Manufacturing Info.), offset: 0x420 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t CFG2;                              /**< Value of OTP Bank0 Word3 (Configuration and Manufacturing Info.), offset: 0x430 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t CFG3;                              /**< Value of OTP Bank0 Word4 (Configuration and Manufacturing Info.), offset: 0x440 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t CFG4;                              /**< Value of OTP Bank0 Word5 (Configuration and Manufacturing Info.), offset: 0x450 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t CFG5;                              /**< Value of OTP Bank0 Word6 (Configuration and Manufacturing Info.), offset: 0x460 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t CFG6;                              /**< Value of OTP Bank0 Word7 (Configuration and Manufacturing Info.), offset: 0x470 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t MEM0;                              /**< Value of OTP Bank1 Word0 (Memory Related Info.), offset: 0x480 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t MEM1;                              /**< Value of OTP Bank1 Word1 (Memory Related Info.), offset: 0x490 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t MEM2;                              /**< Value of OTP Bank1 Word2 (Memory Related Info.), offset: 0x4A0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t MEM3;                              /**< Value of OTP Bank1 Word3 (Memory Related Info.), offset: 0x4B0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t MEM4;                              /**< Value of OTP Bank1 Word4 (Memory Related Info.), offset: 0x4C0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t ANA0;                              /**< Value of OTP Bank1 Word5 (Analog Info.), offset: 0x4D0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t ANA1;                              /**< Value of OTP Bank1 Word6 (Analog Info.), offset: 0x4E0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t ANA2;                              /**< Value of OTP Bank1 Word7 (Analog Info.), offset: 0x4F0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[35];
  volatile uint32_t SRK0;                              /**< Shadow Register for OTP Bank3 Word0 (SRK Hash), offset: 0x580 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t SRK1;                              /**< Shadow Register for OTP Bank3 Word1 (SRK Hash), offset: 0x590 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t SRK2;                              /**< Shadow Register for OTP Bank3 Word2 (SRK Hash), offset: 0x5A0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t SRK3;                              /**< Shadow Register for OTP Bank3 Word3 (SRK Hash), offset: 0x5B0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t SRK4;                              /**< Shadow Register for OTP Bank3 Word4 (SRK Hash), offset: 0x5C0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t SRK5;                              /**< Shadow Register for OTP Bank3 Word5 (SRK Hash), offset: 0x5D0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t SRK6;                              /**< Shadow Register for OTP Bank3 Word6 (SRK Hash), offset: 0x5E0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t SRK7;                              /**< Shadow Register for OTP Bank3 Word7 (SRK Hash), offset: 0x5F0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t SJC_RESP0;                         /**< Value of OTP Bank4 Word0 (Secure JTAG Response Field), offset: 0x600 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t SJC_RESP1;                         /**< Value of OTP Bank4 Word1 (Secure JTAG Response Field), offset: 0x610 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t MAC0;                              /**< Value of OTP Bank4 Word2 (MAC Address), offset: 0x620 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t MAC1;                              /**< Value of OTP Bank4 Word3 (MAC Address), offset: 0x630 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t MAC2;                              /**< Value of OTP Bank4 Word4 (MAC2 Address), offset: 0x640 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[7];
  volatile uint32_t GP1;                               /**< Value of OTP Bank4 Word6 (General Purpose Customer Defined Info), offset: 0x660 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t GP2;                               /**< Value of OTP Bank4 Word7 (General Purpose Customer Defined Info), offset: 0x670 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t SW_GP1;                            /**< Value of OTP Bank5 Word0 (SW GP1), offset: 0x680 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t SW_GP20;                           /**< Value of OTP Bank5 Word1 (SW GP2), offset: 0x690 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t SW_GP21;                           /**< Value of OTP Bank5 Word2 (SW GP2), offset: 0x6A0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t SW_GP22;                           /**< Value of OTP Bank5 Word3 (SW GP2), offset: 0x6B0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t SW_GP23;                           /**< Value of OTP Bank5 Word4 (SW GP2), offset: 0x6C0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t MISC_CONF0;                        /**< Value of OTP Bank5 Word5 (Misc Conf), offset: 0x6D0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t MISC_CONF1;                        /**< Value of OTP Bank5 Word6 (Misc Conf), offset: 0x6E0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t SRK_REVOKE;                        /**< Value of OTP Bank5 Word7 (SRK Revoke), offset: 0x6F0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[99];
  volatile uint32_t GP30;                              /**< Value of OTP Bank7 Word0 (GP3), offset: 0x880 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t GP31;                              /**< Value of OTP Bank7 Word1 (GP3), offset: 0x890 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t GP32;                              /**< Value of OTP Bank7 Word2 (GP3), offset: 0x8A0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t GP33;                              /**< Value of OTP Bank7 Word3 (GP3), offset: 0x8B0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t GP40;                              /**< Value of OTP Bank7 Word4 (GP4), offset: 0x8C0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t GP41;                              /**< Value of OTP Bank7 Word5 (GP4), offset: 0x8D0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t GP42;                              /**< Value of OTP Bank7 Word6 (GP4), offset: 0x8E0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t GP43;                              /**< Value of OTP Bank7 Word7 (GP4), offset: 0x8F0 */
};

constexpr size_t    kOCOTP_size = 0x8F4;
constexpr uintptr_t kOCOTP_base = 0x401F4000;

constexpr regs::RegGroup<OCOTP_Layout, kOCOTP_size, kOCOTP_base> OCOTP;

template <auto Member, size_t Bits, unsigned int Shift,
          bool DirectAssign = false>
using OCOTP_Reg = regs::Reg32<kOCOTP_base, OCOTP_Layout, Member, 0, Bits, Shift,
                              DirectAssign>;

// Undefine anything defined by Teensyduino's imxrt.h

// OTP Controller Control and Status Register
#undef OCOTP_CTRL_WR_UNLOCK
constexpr OCOTP_Reg<&OCOTP_Layout::CTRL, 16, 16> OCOTP_CTRL_WR_UNLOCK;       // Write Unlock
    // 0b0000000000000000..OTP write access is locked.
    // 0b0011111001110111..OTP write access is unlocked.
#undef OCOTP_CTRL_RELOAD_SHADOWS
constexpr OCOTP_Reg<&OCOTP_Layout::CTRL,  1, 10> OCOTP_CTRL_RELOAD_SHADOWS;  // Reload Shadow Registers
    // 0b0..Do not force shadow register re-load.
    // 0b1..Force shadow register re-load. This bit is cleared automatically after shadow registers are re-loaded.
#undef OCOTP_CTRL_ERROR
constexpr OCOTP_Reg<&OCOTP_Layout::CTRL,  1,  9> OCOTP_CTRL_ERROR;           // Locked Region Access Error
    // 0b0..No error.
    // 0b1..Error - access to a locked region requested.
#undef OCOTP_CTRL_BUSY
constexpr OCOTP_Reg<&OCOTP_Layout::CTRL,  1,  8> OCOTP_CTRL_BUSY;            // OTP controller status bit
    // 0b0..No write or read access to OTP started.
    // 0b1..Write or read access to OTP started.
#undef OCOTP_CTRL_ADDR
constexpr OCOTP_Reg<&OCOTP_Layout::CTRL,  6,  0> OCOTP_CTRL_ADDR;            // OTP write and read access address register

// OTP Controller Control and Status Register
#undef OCOTP_CTRL_SET_WR_UNLOCK
constexpr OCOTP_Reg<&OCOTP_Layout::CTRL_SET, 16, 16, true> OCOTP_CTRL_SET_WR_UNLOCK;
#undef OCOTP_CTRL_SET_RELOAD_SHADOWS
constexpr OCOTP_Reg<&OCOTP_Layout::CTRL_SET,  1, 10, true> OCOTP_CTRL_SET_RELOAD_SHADOWS;
#undef OCOTP_CTRL_SET_ERROR
constexpr OCOTP_Reg<&OCOTP_Layout::CTRL_SET,  1,  9, true> OCOTP_CTRL_SET_ERROR;
#undef OCOTP_CTRL_SET_BUSY
constexpr OCOTP_Reg<&OCOTP_Layout::CTRL_SET,  1,  8, true> OCOTP_CTRL_SET_BUSY;
#undef OCOTP_CTRL_SET_ADDR
constexpr OCOTP_Reg<&OCOTP_Layout::CTRL_SET,  6,  0, true> OCOTP_CTRL_SET_ADDR;

// OTP Controller Control and Status Register
#undef OCOTP_CTRL_CLR_WR_UNLOCK
constexpr OCOTP_Reg<&OCOTP_Layout::CTRL_CLR, 16, 16, true> OCOTP_CTRL_CLR_WR_UNLOCK;
#undef OCOTP_CTRL_CLR_RELOAD_SHADOWS
constexpr OCOTP_Reg<&OCOTP_Layout::CTRL_CLR,  1, 10, true> OCOTP_CTRL_CLR_RELOAD_SHADOWS;
#undef OCOTP_CTRL_CLR_ERROR
constexpr OCOTP_Reg<&OCOTP_Layout::CTRL_CLR,  1,  9, true> OCOTP_CTRL_CLR_ERROR;
#undef OCOTP_CTRL_CLR_BUSY
constexpr OCOTP_Reg<&OCOTP_Layout::CTRL_CLR,  1,  8, true> OCOTP_CTRL_CLR_BUSY;
#undef OCOTP_CTRL_CLR_ADDR
constexpr OCOTP_Reg<&OCOTP_Layout::CTRL_CLR,  6,  0, true> OCOTP_CTRL_CLR_ADDR;

// OTP Controller Control and Status Register
#undef OCOTP_CTRL_TOG_WR_UNLOCK
constexpr OCOTP_Reg<&OCOTP_Layout::CTRL_TOG, 16, 16, true> OCOTP_CTRL_TOG_WR_UNLOCK;
#undef OCOTP_CTRL_TOG_RELOAD_SHADOWS
constexpr OCOTP_Reg<&OCOTP_Layout::CTRL_TOG,  1, 10, true> OCOTP_CTRL_TOG_RELOAD_SHADOWS;
#undef OCOTP_CTRL_TOG_ERROR
constexpr OCOTP_Reg<&OCOTP_Layout::CTRL_TOG,  1,  9, true> OCOTP_CTRL_TOG_ERROR;
#undef OCOTP_CTRL_TOG_BUSY
constexpr OCOTP_Reg<&OCOTP_Layout::CTRL_TOG,  1,  8, true> OCOTP_CTRL_TOG_BUSY;
#undef OCOTP_CTRL_TOG_ADDR
constexpr OCOTP_Reg<&OCOTP_Layout::CTRL_TOG,  6,  0, true> OCOTP_CTRL_TOG_ADDR;

// OTP Controller Timing Register
#undef OCOTP_TIMING_WAIT
constexpr OCOTP_Reg<&OCOTP_Layout::TIMING,  6, 22> OCOTP_TIMING_WAIT;         // Wait Interval
#undef OCOTP_TIMING_STROBE_READ
constexpr OCOTP_Reg<&OCOTP_Layout::TIMING,  6, 16> OCOTP_TIMING_STROBE_READ;  // Read Strobe Period
#undef OCOTP_TIMING_RELAX
constexpr OCOTP_Reg<&OCOTP_Layout::TIMING,  4, 12> OCOTP_TIMING_RELAX;        // Relax Count Value
#undef OCOTP_TIMING_STROBE_PROG
constexpr OCOTP_Reg<&OCOTP_Layout::TIMING, 12,  0> OCOTP_TIMING_STROBE_PROG;  // Write Strobe Period

// OTP Controller Write Data Register
#undef OCOTP_READ_CTRL_READ_FUSE
constexpr OCOTP_Reg<&OCOTP_Layout::READ_CTRL, 1, 0> OCOTP_READ_CTRL_READ_FUSE;

// Sticky bit Register
#undef OCOTP_SW_STICKY_FIELD_RETURN_LOCK
constexpr OCOTP_Reg<&OCOTP_Layout::SW_STICKY, 1, 2> OCOTP_SW_STICKY_FIELD_RETURN_LOCK;  // Field Return Lock
    // 0b0..Writing to this region's shadow register and OTP fuse word are not blocked.
    // 0b1..Writing to this region's shadow register and OTP fuse word are blocked. Once this bit is set, it is always high unless a POR is issued.
#undef OCOTP_SW_STICKY_SRK_REVOKE_LOCK
constexpr OCOTP_Reg<&OCOTP_Layout::SW_STICKY, 1, 1> OCOTP_SW_STICKY_SRK_REVOKE_LOCK;    // SRK Revoke Lock
    // 0b0..The writing of this region's shadow register and OTP fuse word are not blocked.
    // 0b1..The writing of this region's shadow register and OTP fuse word are blocked. Once this bit is set, it is always high unless a POR is issued.

// Software Controllable Signals Register
#undef OCOTP_SCS_LOCK
constexpr OCOTP_Reg<&OCOTP_Layout::SCS,  1, 31> OCOTP_SCS_LOCK;
    // 0b0..Bits in this register are unlocked.
    // 0b1..Bits in this register are locked. When set, all of the bits in this register are locked and can not be
    //      changed through SW programming. After this bit is set, it can only be cleared by a POR.
#undef OCOTP_SCS_SPARE
constexpr OCOTP_Reg<&OCOTP_Layout::SCS, 30,  1> OCOTP_SCS_SPARE;
#undef OCOTP_SCS_HAB_JDE
constexpr OCOTP_Reg<&OCOTP_Layout::SCS,  1,  0> OCOTP_SCS_HAB_JDE;  // HAB JTAG Debug Enable
    // 0b0..JTAG debugging is not enabled by the HAB (it may still be enabled by other mechanisms).
    // 0b1..JTAG debugging is enabled by the HAB (though this signal may be gated off).

// Software Controllable Signals Register
#undef OCOTP_SCS_SET_LOCK
constexpr OCOTP_Reg<&OCOTP_Layout::SCS_SET,  1, 31, true> OCOTP_SCS_SET_LOCK;
#undef OCOTP_SCS_SET_SPARE
constexpr OCOTP_Reg<&OCOTP_Layout::SCS_SET, 30,  1, true> OCOTP_SCS_SET_SPARE;
#undef OCOTP_SCS_SET_HAB_JDE
constexpr OCOTP_Reg<&OCOTP_Layout::SCS_SET,  1,  0, true> OCOTP_SCS_SET_HAB_JDE;

// Software Controllable Signals Register
#undef OCOTP_SCS_CLR_LOCK
constexpr OCOTP_Reg<&OCOTP_Layout::SCS_CLR,  1, 31, true> OCOTP_SCS_CLR_LOCK;
#undef OCOTP_SCS_CLR_SPARE
constexpr OCOTP_Reg<&OCOTP_Layout::SCS_CLR, 30,  1, true> OCOTP_SCS_CLR_SPARE;
#undef OCOTP_SCS_CLR_HAB_JDE
constexpr OCOTP_Reg<&OCOTP_Layout::SCS_CLR,  1,  0, true> OCOTP_SCS_CLR_HAB_JDE;

// Software Controllable Signals Register
#undef OCOTP_SCS_TOG_LOCK
constexpr OCOTP_Reg<&OCOTP_Layout::SCS_TOG,  1, 31, true> OCOTP_SCS_TOG_LOCK;
#undef OCOTP_SCS_TOG_SPARE
constexpr OCOTP_Reg<&OCOTP_Layout::SCS_TOG, 30,  1, true> OCOTP_SCS_TOG_SPARE;
#undef OCOTP_SCS_TOG_HAB_JDE
constexpr OCOTP_Reg<&OCOTP_Layout::SCS_TOG,  1,  0, true> OCOTP_SCS_TOG_HAB_JDE;

// OTP Controller Version Register
#undef OCOTP_VERSION_MAJOR
constexpr OCOTP_Reg<&OCOTP_Layout::VERSION,  8, 24> OCOTP_VERSION_MAJOR;
#undef OCOTP_VERSION_MINOR
constexpr OCOTP_Reg<&OCOTP_Layout::VERSION,  8, 16> OCOTP_VERSION_MINOR;
#undef OCOTP_VERSION_STEP
constexpr OCOTP_Reg<&OCOTP_Layout::VERSION, 16,  0> OCOTP_VERSION_STEP;

// OTP Controller Timing Register 2
#undef OCOTP_TIMING2_RELAX_READ
constexpr OCOTP_Reg<&OCOTP_Layout::TIMING2,  6, 16> OCOTP_TIMING2_RELAX_READ;  // Relax Read count value
#undef OCOTP_TIMING2_RELAX_PROG
constexpr OCOTP_Reg<&OCOTP_Layout::TIMING2, 12,  0> OCOTP_TIMING2_RELAX_PROG;  // Relax Prog. count value

// Value of OTP Bank0 Word0 (Lock controls)
#undef OCOTP_LOCK_FIELD_RETURN
constexpr OCOTP_Reg<&OCOTP_Layout::LOCK, 1, 31> OCOTP_LOCK_FIELD_RETURN;  // FIELD RETURN Status
    // 0b0..The device is a functional part.
    // 0b1..The device is a field returned part.
#undef OCOTP_LOCK_GP3
constexpr OCOTP_Reg<&OCOTP_Layout::LOCK, 2, 26> OCOTP_LOCK_GP3;           // GP3 Write Lock Status
#undef OCOTP_LOCK_GP4
constexpr OCOTP_Reg<&OCOTP_Layout::LOCK, 2, 24> OCOTP_LOCK_GP4;           // GP4 Write Lock Status
#undef OCOTP_LOCK_SW_GP2_RLOCK
constexpr OCOTP_Reg<&OCOTP_Layout::LOCK, 1, 23> OCOTP_LOCK_SW_GP2_RLOCK;  // SW_GP2 Read Lock Status
    // 0b0..The reading of this region's shadow register and OTP fuse word are not blocked.
    // 0b1..When set, the reading of this region's shadow register and OTP fuse word are blocked.
#undef OCOTP_LOCK_MISC_CONF
constexpr OCOTP_Reg<&OCOTP_Layout::LOCK, 1, 22> OCOTP_LOCK_MISC_CONF;     // MISC_CONF Write Lock Status
    // 0b0..Writing of this region's shadow register and OTP fuse word are not blocked.
    // 0b1..When set, the writing of this region's shadow register and OTP fuse word are blocked.
#undef OCOTP_LOCK_SW_GP2_LOCK
constexpr OCOTP_Reg<&OCOTP_Layout::LOCK, 1, 21> OCOTP_LOCK_SW_GP2_LOCK;   // SW_GP2 Write Lock Status
    // 0b0..Writing of this region's shadow register and OTP fuse word are not blocked.
    // 0b1..When set, the writing of this region's shadow register and OTP fuse word are blocked.
#undef OCOTP_LOCK_ANALOG
constexpr OCOTP_Reg<&OCOTP_Layout::LOCK, 2, 18> OCOTP_LOCK_ANALOG;        // ANALOG Write Lock Status
#undef OCOTP_LOCK_SW_GP1
constexpr OCOTP_Reg<&OCOTP_Layout::LOCK, 1, 16> OCOTP_LOCK_SW_GP1;        // SW_GP1 Write Lock Status
    // 0b0..Writing of this region's shadow register and OTP fuse word are not blocked.
    // 0b1..When set, the writing of this region's shadow register and OTP fuse word are blocked.
#undef OCOTP_LOCK_GP2
constexpr OCOTP_Reg<&OCOTP_Layout::LOCK, 2, 12> OCOTP_LOCK_GP2;           // GP2 Write Lock Status
#undef OCOTP_LOCK_GP1
constexpr OCOTP_Reg<&OCOTP_Layout::LOCK, 2, 10> OCOTP_LOCK_GP1;           // GP1 Write Lock Status
#undef OCOTP_LOCK_MAC_ADDR
constexpr OCOTP_Reg<&OCOTP_Layout::LOCK, 2,  8> OCOTP_LOCK_MAC_ADDR;      // MAC_ADDR Write Lock Status
#undef OCOTP_LOCK_GP4_RLOCK
constexpr OCOTP_Reg<&OCOTP_Layout::LOCK, 1,  7> OCOTP_LOCK_GP4_RLOCK;     // GP4 Read Lock Status
    // 0b0..Reading of this region's shadow register and OTP fuse word are not blocked.
    // 0b1..When set, the reading of this region's shadow register and OTP fuse word are blocked.
#undef OCOTP_LOCK_SJC_RESP
constexpr OCOTP_Reg<&OCOTP_Layout::LOCK, 1,  6> OCOTP_LOCK_SJC_RESP;      // SJC_RESP Lock Status
    // 0b0..The writing or reading of this region's shadow register and OTP fuse word are not blocked.
    // 0b1..When set, the writing of this region's shadow register and OTP fuse word are blocked. The read of this
    //      region's shadow register and OTP fuse word are also blocked
#undef OCOTP_LOCK_BOOT_CFG
constexpr OCOTP_Reg<&OCOTP_Layout::LOCK, 2,  2> OCOTP_LOCK_BOOT_CFG;      // BOOT_CFG Write Lock Status

}  // namespace teensy4
}  // namespace hardware
}  // namespace qindesign
