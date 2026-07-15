// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// CCM.h defines all the CCM registers.
// This file is part of the TeensyRegs library.

#pragma once

#include <cstddef>
#include <cstdint>

#include "hardware/regs/regs.h"

namespace qindesign {
namespace hardware {
namespace teensy4 {

constexpr size_t kENET_TXIC_count    = 1;
constexpr size_t kENET_RXIC_count    = 1;
constexpr size_t kENET_CHANNEL_count = 4;

// ENET layout. Comments are from BSD-3-licensed NXP SDK.
//
// See:
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/periph/PERI_ENET.h
// * https://github.com/nxp-mcuxpresso/legacy-mcux-sdk/blob/main/devices/MIMXRT1062/MIMXRT1062.h
struct ENET_Layout {
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[1];
  volatile uint32_t EIR;                               /**< Interrupt Event Register, offset: 0x4 */
  volatile uint32_t EIMR;                              /**< Interrupt Mask Register, offset: 0x8 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[1];
  volatile uint32_t RDAR;                              /**< Receive Descriptor Active Register - Ring 0, offset: 0x10 */
  volatile uint32_t TDAR;                              /**< Transmit Descriptor Active Register - Ring 0, offset: 0x14 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t ECR;                               /**< Ethernet Control Register, offset: 0x24 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[6];
  volatile uint32_t MMFR;                              /**< MII Management Frame Register, offset: 0x40 */
  volatile uint32_t MSCR;                              /**< MII Speed Control Register, offset: 0x44 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[7];
  volatile uint32_t MIBC;                              /**< MIB Control Register, offset: 0x64 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[7];
  volatile uint32_t RCR;                               /**< Receive Control Register, offset: 0x84 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[15];
  volatile uint32_t TCR;                               /**< Transmit Control Register, offset: 0xC4 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[7];
  volatile uint32_t PALR;                              /**< Physical Address Lower Register, offset: 0xE4 */
  volatile uint32_t PAUR;                              /**< Physical Address Upper Register, offset: 0xE8 */
  volatile uint32_t OPD;                               /**< Opcode/Pause Duration Register, offset: 0xEC */
  volatile uint32_t TXIC[kENET_TXIC_count];            /**< Transmit Interrupt Coalescing Register, array offset: 0xF0, array step: 0x4 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t RXIC[kENET_RXIC_count];            /**< Receive Interrupt Coalescing Register, array offset: 0x100, array step: 0x4 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[5];
  volatile uint32_t IAUR;                              /**< Descriptor Individual Upper Address Register, offset: 0x118 */
  volatile uint32_t IALR;                              /**< Descriptor Individual Lower Address Register, offset: 0x11C */
  volatile uint32_t GAUR;                              /**< Descriptor Group Upper Address Register, offset: 0x120 */
  volatile uint32_t GALR;                              /**< Descriptor Group Lower Address Register, offset: 0x124 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[7];
  volatile uint32_t TFWR;                              /**< Transmit FIFO Watermark Register, offset: 0x144 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[14];
  volatile uint32_t RDSR;                              /**< Receive Descriptor Ring 0 Start Register, offset: 0x180 */
  volatile uint32_t TDSR;                              /**< Transmit Buffer Descriptor Ring 0 Start Register, offset: 0x184 */
  volatile uint32_t MRBR;                              /**< Maximum Receive Buffer Size Register - Ring 0, offset: 0x188 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[1];
  volatile uint32_t RSFL;                              /**< Receive FIFO Section Full Threshold, offset: 0x190 */
  volatile uint32_t RSEM;                              /**< Receive FIFO Section Empty Threshold, offset: 0x194 */
  volatile uint32_t RAEM;                              /**< Receive FIFO Almost Empty Threshold, offset: 0x198 */
  volatile uint32_t RAFL;                              /**< Receive FIFO Almost Full Threshold, offset: 0x19C */
  volatile uint32_t TSEM;                              /**< Transmit FIFO Section Empty Threshold, offset: 0x1A0 */
  volatile uint32_t TAEM;                              /**< Transmit FIFO Almost Empty Threshold, offset: 0x1A4 */
  volatile uint32_t TAFL;                              /**< Transmit FIFO Almost Full Threshold, offset: 0x1A8 */
  volatile uint32_t TIPG;                              /**< Transmit Inter-Packet Gap, offset: 0x1AC */
  volatile uint32_t FTRL;                              /**< Frame Truncation Length, offset: 0x1B0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t TACC;                              /**< Transmit Accelerator Function Configuration, offset: 0x1C0 */
  volatile uint32_t RACC;                              /**< Receive Accelerator Function Configuration, offset: 0x1C4 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[15];
  const volatile uint32_t RMON_T_PACKETS;              /**< Tx Packet Count Statistic Register, offset: 0x204 */
  const volatile uint32_t RMON_T_BC_PKT;               /**< Tx Broadcast Packets Statistic Register, offset: 0x208 */
  const volatile uint32_t RMON_T_MC_PKT;               /**< Tx Multicast Packets Statistic Register, offset: 0x20C */
  const volatile uint32_t RMON_T_CRC_ALIGN;            /**< Tx Packets with CRC/Align Error Statistic Register, offset: 0x210 */
  const volatile uint32_t RMON_T_UNDERSIZE;            /**< Tx Packets Less Than Bytes and Good CRC Statistic Register, offset: 0x214 */
  const volatile uint32_t RMON_T_OVERSIZE;             /**< Tx Packets GT MAX_FL bytes and Good CRC Statistic Register, offset: 0x218 */
  const volatile uint32_t RMON_T_FRAG;                 /**< Tx Packets Less Than 64 Bytes and Bad CRC Statistic Register, offset: 0x21C */
  const volatile uint32_t RMON_T_JAB;                  /**< Tx Packets Greater Than MAX_FL bytes and Bad CRC Statistic Register, offset: 0x220 */
  const volatile uint32_t RMON_T_COL;                  /**< Tx Collision Count Statistic Register, offset: 0x224 */
  const volatile uint32_t RMON_T_P64;                  /**< Tx 64-Byte Packets Statistic Register, offset: 0x228 */
  const volatile uint32_t RMON_T_P65TO127;             /**< Tx 65- to 127-byte Packets Statistic Register, offset: 0x22C */
  const volatile uint32_t RMON_T_P128TO255;            /**< Tx 128- to 255-byte Packets Statistic Register, offset: 0x230 */
  const volatile uint32_t RMON_T_P256TO511;            /**< Tx 256- to 511-byte Packets Statistic Register, offset: 0x234 */
  const volatile uint32_t RMON_T_P512TO1023;           /**< Tx 512- to 1023-byte Packets Statistic Register, offset: 0x238 */
  const volatile uint32_t RMON_T_P1024TO2047;          /**< Tx 1024- to 2047-byte Packets Statistic Register, offset: 0x23C */
  const volatile uint32_t RMON_T_P_GTE2048;            /**< Tx Packets Greater Than 2048 Bytes Statistic Register, offset: 0x240 */
  const volatile uint32_t RMON_T_OCTETS;               /**< Tx Octets Statistic Register, offset: 0x244 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[1];
  const volatile uint32_t IEEE_T_FRAME_OK;             /**< Frames Transmitted OK Statistic Register, offset: 0x24C */
  const volatile uint32_t IEEE_T_1COL;                 /**< Frames Transmitted with Single Collision Statistic Register, offset: 0x250 */
  const volatile uint32_t IEEE_T_MCOL;                 /**< Frames Transmitted with Multiple Collisions Statistic Register, offset: 0x254 */
  const volatile uint32_t IEEE_T_DEF;                  /**< Frames Transmitted after Deferral Delay Statistic Register, offset: 0x258 */
  const volatile uint32_t IEEE_T_LCOL;                 /**< Frames Transmitted with Late Collision Statistic Register, offset: 0x25C */
  const volatile uint32_t IEEE_T_EXCOL;                /**< Frames Transmitted with Excessive Collisions Statistic Register, offset: 0x260 */
  const volatile uint32_t IEEE_T_MACERR;               /**< Frames Transmitted with Tx FIFO Underrun Statistic Register, offset: 0x264 */
  const volatile uint32_t IEEE_T_CSERR;                /**< Frames Transmitted with Carrier Sense Error Statistic Register, offset: 0x268 */
  const volatile uint32_t IEEE_T_SQE;                  /**< Reserved Statistic Register, offset: 0x26C */
  const volatile uint32_t IEEE_T_FDXFC;                /**< Flow Control Pause Frames Transmitted Statistic Register, offset: 0x270 */
  const volatile uint32_t IEEE_T_OCTETS_OK;            /**< Octet Count for Frames Transmitted w/o Error Statistic Register, offset: 0x274 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  const volatile uint32_t RMON_R_PACKETS;              /**< Rx Packet Count Statistic Register, offset: 0x284 */
  const volatile uint32_t RMON_R_BC_PKT;               /**< Rx Broadcast Packets Statistic Register, offset: 0x288 */
  const volatile uint32_t RMON_R_MC_PKT;               /**< Rx Multicast Packets Statistic Register, offset: 0x28C */
  const volatile uint32_t RMON_R_CRC_ALIGN;            /**< Rx Packets with CRC/Align Error Statistic Register, offset: 0x290 */
  const volatile uint32_t RMON_R_UNDERSIZE;            /**< Rx Packets with Less Than 64 Bytes and Good CRC Statistic Register, offset: 0x294 */
  const volatile uint32_t RMON_R_OVERSIZE;             /**< Rx Packets Greater Than MAX_FL and Good CRC Statistic Register, offset: 0x298 */
  const volatile uint32_t RMON_R_FRAG;                 /**< Rx Packets Less Than 64 Bytes and Bad CRC Statistic Register, offset: 0x29C */
  const volatile uint32_t RMON_R_JAB;                  /**< Rx Packets Greater Than MAX_FL Bytes and Bad CRC Statistic Register, offset: 0x2A0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[1];
  const volatile uint32_t RMON_R_P64;                  /**< Rx 64-Byte Packets Statistic Register, offset: 0x2A8 */
  const volatile uint32_t RMON_R_P65TO127;             /**< Rx 65- to 127-Byte Packets Statistic Register, offset: 0x2AC */
  const volatile uint32_t RMON_R_P128TO255;            /**< Rx 128- to 255-Byte Packets Statistic Register, offset: 0x2B0 */
  const volatile uint32_t RMON_R_P256TO511;            /**< Rx 256- to 511-Byte Packets Statistic Register, offset: 0x2B4 */
  const volatile uint32_t RMON_R_P512TO1023;           /**< Rx 512- to 1023-Byte Packets Statistic Register, offset: 0x2B8 */
  const volatile uint32_t RMON_R_P1024TO2047;          /**< Rx 1024- to 2047-Byte Packets Statistic Register, offset: 0x2BC */
  const volatile uint32_t RMON_R_P_GTE2048;            /**< Rx Packets Greater than 2048 Bytes Statistic Register, offset: 0x2C0 */
  const volatile uint32_t RMON_R_OCTETS;               /**< Rx Octets Statistic Register, offset: 0x2C4 */
  const volatile uint32_t IEEE_R_DROP;                 /**< Frames not Counted Correctly Statistic Register, offset: 0x2C8 */
  const volatile uint32_t IEEE_R_FRAME_OK;             /**< Frames Received OK Statistic Register, offset: 0x2CC */
  const volatile uint32_t IEEE_R_CRC;                  /**< Frames Received with CRC Error Statistic Register, offset: 0x2D0 */
  const volatile uint32_t IEEE_R_ALIGN;                /**< Frames Received with Alignment Error Statistic Register, offset: 0x2D4 */
  const volatile uint32_t IEEE_R_MACERR;               /**< Receive FIFO Overflow Count Statistic Register, offset: 0x2D8 */
  const volatile uint32_t IEEE_R_FDXFC;                /**< Flow Control Pause Frames Received Statistic Register, offset: 0x2DC */
  const volatile uint32_t IEEE_R_OCTETS_OK;            /**< Octet Count for Frames Received without Error Statistic Register, offset: 0x2E0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[71];
  volatile uint32_t ATCR;                              /**< Adjustable Timer Control Register, offset: 0x400 */
  volatile uint32_t ATVR;                              /**< Timer Value Register, offset: 0x404 */
  volatile uint32_t ATOFF;                             /**< Timer Offset Register, offset: 0x408 */
  volatile uint32_t ATPER;                             /**< Timer Period Register, offset: 0x40C */
  volatile uint32_t ATCOR;                             /**< Timer Correction Register, offset: 0x410 */
  volatile uint32_t ATINC;                             /**< Time-Stamping Clock Period Register, offset: 0x414 */
  const volatile uint32_t ATSTMP;                      /**< Timestamp of Last Transmitted Frame, offset: 0x418 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[122];
  volatile uint32_t TGSR;                              /**< Timer Global Status Register, offset: 0x604 */
  struct CHANNEL_Layout {                          /* offset: 0x608, array step: 0x8 */
    volatile uint32_t TCSR;                            /**< Timer Control Status Register, array offset: 0x608, array step: 0x8 */
    volatile uint32_t TCCR;                            /**< Timer Compare Capture Register, array offset: 0x60C, array step: 0x8 */
  } CHANNEL[kENET_CHANNEL_count];
};

constexpr size_t    kENET_size  = 0x628;
constexpr uintptr_t kENET_base  = 0x402D8000;
constexpr uintptr_t kENET2_base = 0x402D4000;

constexpr uintptr_t ChannelBase(const uintptr_t base, const size_t index) {
  return base + offsetof(ENET_Layout, CHANNEL) +
         index*sizeof(ENET_Layout::CHANNEL_Layout);
}

constexpr regs::RegGroup<ENET_Layout, kENET_size, kENET_base> ENET;
constexpr regs::RegGroup<ENET_Layout, kENET_size, kENET2_base> ENET2;

template <auto Member, size_t Bits, unsigned int Shift,
          bool DirectAssign = false>
using ENET_Reg = regs::Reg<uint32_t, kENET_base, ENET_Layout, Member, 0, Bits,
                           Shift, DirectAssign>;

template <auto Member, size_t Bits, unsigned int Shift,
          bool DirectAssign = false>
using ENET2_Reg = regs::Reg<uint32_t, kENET2_base, ENET_Layout, Member, 0, Bits,
                            Shift, DirectAssign>;

template <size_t Index, auto Member, size_t Bits, unsigned int Shift,
          bool DirectAssign = false>
using ENET_CHANNEL_Reg = regs::Reg<uint32_t, ChannelBase(kENET_base, Index),
                                   ENET_Layout::CHANNEL_Layout, Member, 0, Bits,
                                   Shift, DirectAssign>;

template <size_t Index, auto Member, size_t Bits, unsigned int Shift,
          bool DirectAssign = false>
using ENET2_CHANNEL_Reg = regs::Reg<uint32_t, ChannelBase(kENET2_base, Index),
                                    ENET_Layout::CHANNEL_Layout, Member, 0,
                                    Bits, Shift, DirectAssign>;

// Undefine anything defined by Teensyduino's imxrt.h

// Interrupt Event Register
#undef ENET_EIR_BABR
constexpr ENET_Reg<&ENET_Layout::EIR, 1, 30, true> ENET_EIR_BABR;      // Babbling Receive Error
#undef ENET_EIR_BABT
constexpr ENET_Reg<&ENET_Layout::EIR, 1, 29, true> ENET_EIR_BABT;      // Babbling Transmit Error
#undef ENET_EIR_GRA
constexpr ENET_Reg<&ENET_Layout::EIR, 1, 28, true> ENET_EIR_GRA;       // Graceful Stop Complete
#undef ENET_EIR_TXF
constexpr ENET_Reg<&ENET_Layout::EIR, 1, 27, true> ENET_EIR_TXF;       // Transmit Frame Interrupt
#undef ENET_EIR_TXB
constexpr ENET_Reg<&ENET_Layout::EIR, 1, 26, true> ENET_EIR_TXB;       // Transmit Buffer Interrupt
#undef ENET_EIR_RXF
constexpr ENET_Reg<&ENET_Layout::EIR, 1, 25, true> ENET_EIR_RXF;       // Receive Frame Interrupt
#undef ENET_EIR_RXB
constexpr ENET_Reg<&ENET_Layout::EIR, 1, 24, true> ENET_EIR_RXB;       // Receive Buffer Interrupt
#undef ENET_EIR_MII
constexpr ENET_Reg<&ENET_Layout::EIR, 1, 23, true> ENET_EIR_MII;       // MII Interrupt
#undef ENET_EIR_EBERR
constexpr ENET_Reg<&ENET_Layout::EIR, 1, 22, true> ENET_EIR_EBERR;     // Ethernet Bus Error
#undef ENET_EIR_LC
constexpr ENET_Reg<&ENET_Layout::EIR, 1, 21, true> ENET_EIR_LC;        // Late Collision
#undef ENET_EIR_RL
constexpr ENET_Reg<&ENET_Layout::EIR, 1, 20, true> ENET_EIR_RL;        // Collision Retry Limit
#undef ENET_EIR_UN
constexpr ENET_Reg<&ENET_Layout::EIR, 1, 19, true> ENET_EIR_UN;        // Transmit FIFO Underrun
#undef ENET_EIR_PLR
constexpr ENET_Reg<&ENET_Layout::EIR, 1, 18, true> ENET_EIR_PLR;       // Payload Receive Error
#undef ENET_EIR_WAKEUP
constexpr ENET_Reg<&ENET_Layout::EIR, 1, 17, true> ENET_EIR_WAKEUP;    // Node Wakeup Request Indication
#undef ENET_EIR_TS_AVAIL
constexpr ENET_Reg<&ENET_Layout::EIR, 1, 16, true> ENET_EIR_TS_AVAIL;  // Transmit Timestamp Available
#undef ENET_EIR_TS_TIMER
constexpr ENET_Reg<&ENET_Layout::EIR, 1, 15, true> ENET_EIR_TS_TIMER;  // Timestamp Timer

// Interrupt Mask Register
#undef ENET_EIMR_BABR
constexpr ENET_Reg<&ENET_Layout::EIMR, 1, 30> ENET_EIMR_BABR;      // BABR Interrupt Mask
    // 0b0..The corresponding interrupt source is masked.
    // 0b1..The corresponding interrupt source is not masked.
#undef ENET_EIMR_BABT
constexpr ENET_Reg<&ENET_Layout::EIMR, 1, 29> ENET_EIMR_BABT;      // BABT Interrupt Mask
    // 0b0..The corresponding interrupt source is masked.
    // 0b1..The corresponding interrupt source is not masked.
#undef ENET_EIMR_GRA
constexpr ENET_Reg<&ENET_Layout::EIMR, 1, 28> ENET_EIMR_GRA;       // GRA Interrupt Mask
    // 0b0..The corresponding interrupt source is masked.
    // 0b1..The corresponding interrupt source is not masked.
#undef ENET_EIMR_TXF
constexpr ENET_Reg<&ENET_Layout::EIMR, 1, 27> ENET_EIMR_TXF;       // TXF Interrupt Mask
    // 0b0..The corresponding interrupt source is masked.
    // 0b1..The corresponding interrupt source is not masked.
#undef ENET_EIMR_TXB
constexpr ENET_Reg<&ENET_Layout::EIMR, 1, 26> ENET_EIMR_TXB;       // TXB Interrupt Mask
    // 0b0..The corresponding interrupt source is masked.
    // 0b1..The corresponding interrupt source is not masked.
#undef ENET_EIMR_RXF
constexpr ENET_Reg<&ENET_Layout::EIMR, 1, 25> ENET_EIMR_RXF;       // RXF Interrupt Mask
    // 0b0..The corresponding interrupt source is masked.
    // 0b1..The corresponding interrupt source is not masked.
#undef ENET_EIMR_RXB
constexpr ENET_Reg<&ENET_Layout::EIMR, 1, 24> ENET_EIMR_RXB;       // RXB Interrupt Mask
    // 0b0..The corresponding interrupt source is masked.
    // 0b1..The corresponding interrupt source is not masked.
#undef ENET_EIMR_MII
constexpr ENET_Reg<&ENET_Layout::EIMR, 1, 23> ENET_EIMR_MII;       // MII Interrupt Mask
    // 0b0..The corresponding interrupt source is masked.
    // 0b1..The corresponding interrupt source is not masked.
#undef ENET_EIMR_EBERR
constexpr ENET_Reg<&ENET_Layout::EIMR, 1, 22> ENET_EIMR_EBERR;     // EBERR Interrupt Mask
    // 0b0..The corresponding interrupt source is masked.
    // 0b1..The corresponding interrupt source is not masked.
#undef ENET_EIMR_LC
constexpr ENET_Reg<&ENET_Layout::EIMR, 1, 21> ENET_EIMR_LC;        // LC Interrupt Mask
    // 0b0..The corresponding interrupt source is masked.
    // 0b1..The corresponding interrupt source is not masked.
#undef ENET_EIMR_RL
constexpr ENET_Reg<&ENET_Layout::EIMR, 1, 20> ENET_EIMR_RL;        // RL Interrupt Mask
    // 0b0..The corresponding interrupt source is masked.
    // 0b1..The corresponding interrupt source is not masked.
#undef ENET_EIMR_UN
constexpr ENET_Reg<&ENET_Layout::EIMR, 1, 19> ENET_EIMR_UN;        // UN Interrupt Mask
    // 0b0..The corresponding interrupt source is masked.
    // 0b1..The corresponding interrupt source is not masked.
#undef ENET_EIMR_PLR
constexpr ENET_Reg<&ENET_Layout::EIMR, 1, 18> ENET_EIMR_PLR;       // PLR Interrupt Mask
    // 0b0..The corresponding interrupt source is masked.
    // 0b1..The corresponding interrupt source is not masked.
#undef ENET_EIMR_WAKEUP
constexpr ENET_Reg<&ENET_Layout::EIMR, 1, 17> ENET_EIMR_WAKEUP;    // WAKEUP Interrupt Mask
    // 0b0..The corresponding interrupt source is masked.
    // 0b1..The corresponding interrupt source is not masked.
#undef ENET_EIMR_TS_AVAIL
constexpr ENET_Reg<&ENET_Layout::EIMR, 1, 16> ENET_EIMR_TS_AVAIL;  // TS_AVAIL Interrupt Mask
    // 0b0..The corresponding interrupt source is masked.
    // 0b1..The corresponding interrupt source is not masked.
#undef ENET_EIMR_TS_TIMER
constexpr ENET_Reg<&ENET_Layout::EIMR, 1, 15> ENET_EIMR_TS_TIMER;  // TS_TIMER Interrupt Mask
    // 0b0..The corresponding interrupt source is masked.
    // 0b1..The corresponding interrupt source is not masked.

// Receive Descriptor Active Register - Ring 0
#undef ENET_RDAR_RDAR
constexpr ENET_Reg<&ENET_Layout::RDAR, 1, 24> ENET_RDAR_RDAR;  // Receive Descriptor Active

// Transmit Descriptor Active Register - Ring 0
#undef ENET_TDAR_TDAR
constexpr ENET_Reg<&ENET_Layout::TDAR, 1, 24> ENET_TDAR_TDAR;  // Transmit Descriptor Active

// Ethernet Control Register
#undef ENET_ECR_DBSWP
constexpr ENET_Reg<&ENET_Layout::ECR, 1, 8> ENET_ECR_DBSWP;    // Descriptor Byte Swapping Enable
    // 0b0..The buffer descriptor bytes are not swapped to support big-endian devices.
    // 0b1..The buffer descriptor bytes are swapped to support little-endian devices.
#undef ENET_ECR_DBGEN
constexpr ENET_Reg<&ENET_Layout::ECR, 1, 6> ENET_ECR_DBGEN;    // Debug Enable
    // 0b0..MAC continues operation in debug mode.
    // 0b1..MAC enters hardware freeze mode when the processor is in debug mode.
#undef ENET_ECR_EN1588
constexpr ENET_Reg<&ENET_Layout::ECR, 1, 4> ENET_ECR_EN1588;   // EN1588 Enable
    // 0b0..Legacy FEC buffer descriptors and functions enabled.
    // 0b1..Enhanced frame time-stamping functions enabled. Has no effect within the MAC besides controlling the DMA control bit ena_1588.
#undef ENET_ECR_SLEEP
constexpr ENET_Reg<&ENET_Layout::ECR, 1, 3> ENET_ECR_SLEEP;    // Sleep Mode Enable
    // 0b0..Normal operating mode.
    // 0b1..Sleep mode.
#undef ENET_ECR_MAGICEN
constexpr ENET_Reg<&ENET_Layout::ECR, 1, 2> ENET_ECR_MAGICEN;  // Magic Packet Detection Enable
    // 0b0..Magic detection logic disabled.
    // 0b1..The MAC core detects magic packets and asserts EIR[WAKEUP] when a frame is detected.
#undef ENET_ECR_ETHEREN
constexpr ENET_Reg<&ENET_Layout::ECR, 1, 1> ENET_ECR_ETHEREN;  // Ethernet Enable
    // 0b0..Reception immediately stops and transmission stops after a bad CRC is appended to any currently transmitted frame.
    // 0b1..MAC is enabled, and reception and transmission are possible.
#undef ENET_ECR_RESET
constexpr ENET_Reg<&ENET_Layout::ECR, 1, 0> ENET_ECR_RESET;    // Ethernet MAC Reset

// MII Management Frame Register
#undef ENET_MMFR_ST
constexpr ENET_Reg<&ENET_Layout::MMFR,  2, 30> ENET_MMFR_ST;    // Start Of Frame Delimiter
#undef ENET_MMFR_OP
constexpr ENET_Reg<&ENET_Layout::MMFR,  2, 28> ENET_MMFR_OP;    // Operation Code
#undef ENET_MMFR_PA
constexpr ENET_Reg<&ENET_Layout::MMFR,  5, 23> ENET_MMFR_PA;    // PHY Address
#undef ENET_MMFR_RA
constexpr ENET_Reg<&ENET_Layout::MMFR,  5, 18> ENET_MMFR_RA;    // Register Address
#undef ENET_MMFR_TA
constexpr ENET_Reg<&ENET_Layout::MMFR,  2, 16> ENET_MMFR_TA;    // Turn Around
#undef ENET_MMFR_DATA
constexpr ENET_Reg<&ENET_Layout::MMFR, 16,  0> ENET_MMFR_DATA;  // Management Frame Data

// MII Speed Control Register
#undef ENET_MSCR_HOLDTIME
constexpr ENET_Reg<&ENET_Layout::MSCR, 3, 8> ENET_MSCR_HOLDTIME;   // Hold time On MDIO Output
    // 'value + 1' internal module clock cycles:
    // 0b000..1 internal module clock cycle
    // 0b001..2 internal module clock cycles
    // 0b010..3 internal module clock cycles
    // 0b111..8 internal module clock cycles
#undef ENET_MSCR_DIS_PRE
constexpr ENET_Reg<&ENET_Layout::MSCR, 1, 7> ENET_MSCR_DIS_PRE;    // Disable Preamble
    // 0b0..Preamble enabled.
    // 0b1..Preamble (32 ones) is not prepended to the MII management frame.
#undef ENET_MSCR_MII_SPEED
constexpr ENET_Reg<&ENET_Layout::MSCR, 6, 1> ENET_MSCR_MII_SPEED;  // MII Speed

// MIB Control Register
#undef ENET_MIBC_MIB_DIS
constexpr ENET_Reg<&ENET_Layout::MIBC, 1, 31> ENET_MIBC_MIB_DIS;    // Disable MIB Logic
    // 0b0..MIB logic is enabled.
    // 0b1..MIB logic is disabled. The MIB logic halts and does not update any MIB counters.
#undef ENET_MIBC_MIB_IDLE
constexpr ENET_Reg<&ENET_Layout::MIBC, 1, 30> ENET_MIBC_MIB_IDLE;   // MIB Idle
    // 0b0..The MIB block is updating MIB counters.
    // 0b1..The MIB block is not currently updating any MIB counters.
#undef ENET_MIBC_MIB_CLEAR
constexpr ENET_Reg<&ENET_Layout::MIBC, 1, 29> ENET_MIBC_MIB_CLEAR;  // MIB Clear
    // 0b0..See note above.
    // 0b1..All statistics counters are reset to 0.

// Receive Control Register
#undef ENET_RCR_GRS
constexpr ENET_Reg<&ENET_Layout::RCR,  1, 31> ENET_RCR_GRS;        // Graceful Receive Stopped
    // 0b0..Receive not stopped
    // 0b1..Receive stopped
#undef ENET_RCR_NLC
constexpr ENET_Reg<&ENET_Layout::RCR,  1, 30> ENET_RCR_NLC;        // Payload Length Check Disable
    // 0b0..The payload length check is disabled.
    // 0b1..The core checks the frame's payload length with the frame length/type field. Errors are indicated in the EIR[PLR] field.
#undef ENET_RCR_MAX_FL
constexpr ENET_Reg<&ENET_Layout::RCR, 14, 16> ENET_RCR_MAX_FL;     // Maximum Frame Length
#undef ENET_RCR_CFEN
constexpr ENET_Reg<&ENET_Layout::RCR,  1, 15> ENET_RCR_CFEN;       // MAC Control Frame Enable
    // 0b0..MAC control frames with any opcode other than 0x0001 (pause frame) are accepted and forwarded to the client interface.
    // 0b1..MAC control frames with any opcode other than 0x0001 (pause frame) are silently discarded.
#undef ENET_RCR_CRCFWD
constexpr ENET_Reg<&ENET_Layout::RCR,  1, 14> ENET_RCR_CRCFWD;     // Terminate/Forward Received CRC
    // 0b0..The CRC field of received frames is transmitted to the user application.
    // 0b1..The CRC field is stripped from the frame.
#undef ENET_RCR_PAUFWD
constexpr ENET_Reg<&ENET_Layout::RCR,  1, 13> ENET_RCR_PAUFWD;     // Terminate/Forward Pause Frames
    // 0b0..Pause frames are terminated and discarded in the MAC.
    // 0b1..Pause frames are forwarded to the user application.
#undef ENET_RCR_PADEN
constexpr ENET_Reg<&ENET_Layout::RCR,  1, 12> ENET_RCR_PADEN;      // Enable Frame Padding Remove On Receive
    // 0b0..No padding is removed on receive by the MAC.
    // 0b1..Padding is removed from received frames.
#undef ENET_RCR_RMII_10T
constexpr ENET_Reg<&ENET_Layout::RCR,  1,  9> ENET_RCR_RMII_10T;
    // 0b0..100-Mbit/s operation.
    // 0b1..10-Mbit/s operation.
#undef ENET_RCR_RMII_MODE
constexpr ENET_Reg<&ENET_Layout::RCR,  1,  8> ENET_RCR_RMII_MODE;  // RMII Mode Enable
    // 0b0..MAC configured for MII mode.
    // 0b1..MAC configured for RMII operation.
#undef ENET_RCR_FCE
constexpr ENET_Reg<&ENET_Layout::RCR,  1,  5> ENET_RCR_FCE;        // Flow Control Enable
    // 0b0..Disable flow control
    // 0b1..Enable flow control
#undef ENET_RCR_BC_REJ
constexpr ENET_Reg<&ENET_Layout::RCR,  1,  4> ENET_RCR_BC_REJ;     // Broadcast Frame Reject
    // 0b0..Will not reject frames as described above
    // 0b1..Will reject frames as described above
#undef ENET_RCR_PROM
constexpr ENET_Reg<&ENET_Layout::RCR,  1,  3> ENET_RCR_PROM;       // Promiscuous Mode
    // 0b0..Disabled.
    // 0b1..Enabled.
#undef ENET_RCR_MII_MODE
constexpr ENET_Reg<&ENET_Layout::RCR,  1,  2> ENET_RCR_MII_MODE;   // Media Independent Interface Mode
    // 0b0..Reserved.
    // 0b1..MII or RMII mode, as indicated by the RMII_MODE field.
#undef ENET_RCR_DRT
constexpr ENET_Reg<&ENET_Layout::RCR,  1,  1> ENET_RCR_DRT;        // Disable Receive On Transmit
    // 0b0..Receive path operates independently of transmit (i.e., full-duplex mode). Can also be used to monitor transmit activity in half-duplex mode.
    // 0b1..Disable reception of frames while transmitting. (Normally used for half-duplex mode.)
#undef ENET_RCR_LOOP
constexpr ENET_Reg<&ENET_Layout::RCR,  1,  0> ENET_RCR_LOOP;       // Internal Loopback
    // 0b0..Loopback disabled.
    // 0b1..Transmitted frames are looped back internal to the device and transmit MII output signals are not asserted. DRT must be cleared.

// Transmit Control Register
#undef ENET_TCR_CRCFWD
constexpr ENET_Reg<&ENET_Layout::TCR, 1, 9> ENET_TCR_CRCFWD;     // Forward Frame From Application With CRC
    // 0b0..TxBD[TC] controls whether the frame has a CRC from the application.
    // 0b1..The transmitter does not append any CRC to transmitted frames, as it is expecting a frame with CRC from the application.
#undef ENET_TCR_ADDINS
constexpr ENET_Reg<&ENET_Layout::TCR, 1, 8> ENET_TCR_ADDINS;     // Set MAC Address On Transmit
    // 0b0..The source MAC address is not modified by the MAC.
    // 0b1..The MAC overwrites the source MAC address with the programmed MAC address according to ADDSEL.
#undef ENET_TCR_ADDSEL
constexpr ENET_Reg<&ENET_Layout::TCR, 3, 5> ENET_TCR_ADDSEL;     // Source MAC Address Select On Transmit
    // 0b000..Node MAC address programmed on PADDR1/2 registers.
    // 0b100..Reserved.
    // 0b101..Reserved.
    // 0b110..Reserved.
#undef ENET_TCR_RFC_PAUSE
constexpr ENET_Reg<&ENET_Layout::TCR, 1, 4> ENET_TCR_RFC_PAUSE;  // Receive Frame Control Pause
#undef ENET_TCR_TFC_PAUSE
constexpr ENET_Reg<&ENET_Layout::TCR, 1, 3> ENET_TCR_TFC_PAUSE;  // Transmit Frame Control Pause
    // 0b0..No PAUSE frame transmitted.
    // 0b1..The MAC stops transmission of data frames after the current transmission is complete.
#undef ENET_TCR_FDEN
constexpr ENET_Reg<&ENET_Layout::TCR, 1, 2> ENET_TCR_FDEN;       // Full-Duplex Enable
    // 0b0..Disable full-duplex
    // 0b1..Enable full-duplex
#undef ENET_TCR_GTS
constexpr ENET_Reg<&ENET_Layout::TCR, 1, 0> ENET_TCR_GTS;        // Graceful Transmit Stop
    // 0b0..Disable graceful transmit stop
    // 0b1..Enable graceful transmit stop

// Physical Address Upper Register
#undef ENET_PAUR_PADDR2
constexpr ENET_Reg<&ENET_Layout::PAUR, 16, 16> ENET_PAUR_PADDR2;
#undef ENET_PAUR_TYPE
constexpr ENET_Reg<&ENET_Layout::PAUR, 16,  0> ENET_PAUR_TYPE;  // Type Field In PAUSE Frames

// Opcode/Pause Duration Register
#undef ENET_OPD_OPCODE
constexpr ENET_Reg<&ENET_Layout::OPD,   16, 16> ENET_OPD_OPCODE;     // Opcode Field In PAUSE Frames
#undef ENET_OPD_PAUSE_DUR
constexpr ENET_Reg<&ENET_Layout::OPD,   16,  0> ENET_OPD_PAUSE_DUR;  // Pause Duration

// Transmit Interrupt Coalescing Register
#undef ENET_TXIC_ICEN
constexpr ENET_Reg<&ENET_Layout::TXIC,   1, 31> ENET_TXIC_ICEN;  // Interrupt Coalescing Enable
    // 0b0..Disable Interrupt coalescing.
    // 0b1..Enable Interrupt coalescing.
#undef ENET_TXIC_ICCS
constexpr ENET_Reg<&ENET_Layout::TXIC,   1, 30> ENET_TXIC_ICCS;  // Interrupt Coalescing Timer Clock Source Select
    // 0b0..Use MII/GMII TX clocks.
    // 0b1..Use ENET system clock.
#undef ENET_TXIC_ICFT
constexpr ENET_Reg<&ENET_Layout::TXIC,   8, 20> ENET_TXIC_ICFT;  // Interrupt coalescing frame count threshold
#undef ENET_TXIC_ICTT
constexpr ENET_Reg<&ENET_Layout::TXIC,  16,  0> ENET_TXIC_ICTT;  // Interrupt coalescing timer threshold

// Receive Interrupt Coalescing Register
#undef ENET_RXIC_ICEN
constexpr ENET_Reg<&ENET_Layout::RXIC,   1, 31> ENET_RXIC_ICEN;  // Interrupt Coalescing Enable
    // 0b0..Disable Interrupt coalescing.
    // 0b1..Enable Interrupt coalescing.
#undef ENET_RXIC_ICCS
constexpr ENET_Reg<&ENET_Layout::RXIC,   1, 30> ENET_RXIC_ICCS;  // Interrupt Coalescing Timer Clock Source Select
    // 0b0..Use MII/GMII TX clocks.
    // 0b1..Use ENET system clock.
#undef ENET_RXIC_ICFT
constexpr ENET_Reg<&ENET_Layout::RXIC,   8, 20> ENET_RXIC_ICFT;  // Interrupt coalescing frame count threshold
#undef ENET_RXIC_ICTT
constexpr ENET_Reg<&ENET_Layout::RXIC,  16,  0> ENET_RXIC_ICTT;  // Interrupt coalescing timer threshold

// Transmit FIFO Watermark Register
#undef ENET_TFWR_STRFWD
constexpr ENET_Reg<&ENET_Layout::TFWR,   1,  8> ENET_TFWR_STRFWD;  // Store And Forward Enable
    // 0b0..Reset. The transmission start threshold is programmed in TFWR[TFWR].
    // 0b1..Enabled.
#undef ENET_TFWR_TFWR
constexpr ENET_Reg<&ENET_Layout::TFWR,   6,  0> ENET_TFWR_TFWR;  // Transmit FIFO Write
    // 0b000000..64 bytes written.
    // 0b000001..64 bytes written.
    // 0b000010..128 bytes written.
    // 0b000011..192 bytes written.
    // 0b011111..1984 bytes written.

// Receive Descriptor Ring 0 Start Register
#undef ENET_RDSR_R_DES_START
constexpr ENET_Reg<&ENET_Layout::RDSR,  29,  3> ENET_RDSR_R_DES_START;

// Transmit Buffer Descriptor Ring 0 Start Register
#undef ENET_TDSR_X_DES_START
constexpr ENET_Reg<&ENET_Layout::TDSR,  29,  3> ENET_TDSR_X_DES_START;

// Maximum Receive Buffer Size Register - Ring 0
#undef ENET_MRBR_R_BUF_SIZE
constexpr ENET_Reg<&ENET_Layout::MRBR,  10,  4> ENET_MRBR_R_BUF_SIZE;

// Receive FIFO Section Full Threshold
#undef ENET_RSFL_RX_SECTION_FULL
constexpr ENET_Reg<&ENET_Layout::RSFL,   8,  0> ENET_RSFL_RX_SECTION_FULL;  // Value Of Receive FIFO Section Full Threshold

// Receive FIFO Section Empty Threshold
#undef ENET_RSEM_STAT_SECTION_EMPTY
constexpr ENET_Reg<&ENET_Layout::RSEM,   5, 16> ENET_RSEM_STAT_SECTION_EMPTY;  // RX Status FIFO Section Empty Threshold
#undef ENET_RSEM_RX_SECTION_EMPTY
constexpr ENET_Reg<&ENET_Layout::RSEM,   8,  0> ENET_RSEM_RX_SECTION_EMPTY;    // Value Of The Receive FIFO Section Empty Threshold

// Receive FIFO Almost Empty Threshold
#undef ENET_RAEM_RX_ALMOST_EMPTY
constexpr ENET_Reg<&ENET_Layout::RAEM,   8,  0> ENET_RAEM_RX_ALMOST_EMPTY;  // Value Of The Receive FIFO Almost Empty Threshold

// Receive FIFO Almost Full Threshold
#undef ENET_RAFL_RX_ALMOST_FULL
constexpr ENET_Reg<&ENET_Layout::RAFL,   8,  0> ENET_RAFL_RX_ALMOST_FULL;  // Value Of The Receive FIFO Almost Full Threshold

// Transmit FIFO Section Empty Threshold
#undef ENET_TSEM_TX_SECTION_EMPTY
constexpr ENET_Reg<&ENET_Layout::TSEM,   8,  0> ENET_TSEM_TX_SECTION_EMPTY;  // Value Of The Transmit FIFO Section Empty Threshold

// Transmit FIFO Almost Empty Threshold
#undef ENET_TAEM_TX_ALMOST_EMPTY
constexpr ENET_Reg<&ENET_Layout::TAEM,   8,  0> ENET_TAEM_TX_ALMOST_EMPTY;  // Value of Transmit FIFO Almost Empty Threshold

// Transmit FIFO Almost Full Threshold
#undef ENET_TAFL_TX_ALMOST_FULL
constexpr ENET_Reg<&ENET_Layout::TAFL,   8,  0> ENET_TAFL_TX_ALMOST_FULL;  // Value Of The Transmit FIFO Almost Full Threshold

// Transmit Inter-Packet Gap
#undef ENET_TIPG_IPG
constexpr ENET_Reg<&ENET_Layout::TIPG,   5,  0> ENET_TIPG_IPG;  // Transmit Inter-Packet Gap

// Frame Truncation Length
#undef ENET_FTRL_TRUNC_FL
constexpr ENET_Reg<&ENET_Layout::FTRL,  14,  0> ENET_FTRL_TRUNC_FL;  // Frame Truncation Length

// Transmit Accelerator Function Configuration
#undef ENET_TACC_PROCHK
constexpr ENET_Reg<&ENET_Layout::TACC,   1,  4> ENET_TACC_PROCHK;
    // 0b0..Checksum not inserted.
    // 0b1..If an IP frame with a known protocol is transmitted, the checksum is inserted automatically into the
    //      frame. The checksum field must be cleared. The other frames are not modified.
#undef ENET_TACC_IPCHK
constexpr ENET_Reg<&ENET_Layout::TACC,   1,  3> ENET_TACC_IPCHK;
    // 0b0..Checksum is not inserted.
    // 0b1..If an IP frame is transmitted, the checksum is inserted automatically. The IP header checksum field must
    //      be cleared. If a non-IP frame is transmitted the frame is not modified.
#undef ENET_TACC_SHIFT16
constexpr ENET_Reg<&ENET_Layout::TACC,   1,  0> ENET_TACC_SHIFT16;  // TX FIFO Shift-16
    // 0b0..Disabled.
    // 0b1..Indicates to the transmit data FIFO that the written frames contain two additional octets before the
    //      frame data. This means the actual frame begins at bit 16 of the first word written into the FIFO. This
    //      function allows putting the frame payload on a 32-bit boundary in memory, as the 14-byte Ethernet header is
    //      extended to a 16-byte header.

// Receive Accelerator Function Configuration
#undef ENET_RACC_SHIFT16
constexpr ENET_Reg<&ENET_Layout::RACC,   1,  7> ENET_RACC_SHIFT16;  // RX FIFO Shift-16
    // 0b0..Disabled.
    // 0b1..Instructs the MAC to write two additional bytes in front of each frame received into the RX FIFO.
#undef ENET_RACC_LINEDIS
constexpr ENET_Reg<&ENET_Layout::RACC,   1,  6> ENET_RACC_LINEDIS;  // Enable Discard Of Frames With MAC Layer Errors
    // 0b0..Frames with errors are not discarded.
    // 0b1..Any frame received with a CRC, length, or PHY error is automatically discarded and not forwarded to the user application interface.
#undef ENET_RACC_PRODIS
constexpr ENET_Reg<&ENET_Layout::RACC,   1,  2> ENET_RACC_PRODIS;   // Enable Discard Of Frames With Wrong Protocol Checksum
    // 0b0..Frames with wrong checksum are not discarded.
    // 0b1..If a TCP/IP, UDP/IP, or ICMP/IP frame is received that has a wrong TCP, UDP, or ICMP checksum, the frame
    //      is discarded. Discarding is only available when the RX FIFO operates in store and forward mode (RSFL
    //      cleared).
#undef ENET_RACC_IPDIS
constexpr ENET_Reg<&ENET_Layout::RACC,   1,  1> ENET_RACC_IPDIS;    // Enable Discard Of Frames With Wrong IPv4 Header Checksum
    // 0b0..Frames with wrong IPv4 header checksum are not discarded.
    // 0b1..If an IPv4 frame is received with a mismatching header checksum, the frame is discarded. IPv6 has no
    //      header checksum and is not affected by this setting. Discarding is only available when the RX FIFO operates in
    //      store and forward mode (RSFL cleared).
#undef ENET_RACC_PADREM
constexpr ENET_Reg<&ENET_Layout::RACC,   1,  0> ENET_RACC_PADREM;  // Enable Padding Removal For Short IP Frames
    // 0b0..Padding not removed.
    // 0b1..Any bytes following the IP payload section of the frame are removed from the frame.

// Adjustable Timer Control Register
#undef ENET_ATCR_SLAVE
constexpr ENET_Reg<&ENET_Layout::ATCR,   1, 13> ENET_ATCR_SLAVE;    // Enable Timer Slave Mode
    // 0b0..The timer is active and all configuration fields in this register are relevant.
    // 0b1..The internal timer is disabled and the externally provided timer value is used. All other fields, except
    //      CAPTURE, in this register have no effect. CAPTURE can still be used to capture the current timer value.
#undef ENET_ATCR_CAPTURE
constexpr ENET_Reg<&ENET_Layout::ATCR,   1, 11> ENET_ATCR_CAPTURE;  // Capture Timer Value
    // 0b0..No effect.
    // 0b1..The current time is captured and can be read from the ATVR register.
#undef ENET_ATCR_RESTART
constexpr ENET_Reg<&ENET_Layout::ATCR,   1,  9> ENET_ATCR_RESTART;  // Reset Timer
#undef ENET_ATCR_PINPER
constexpr ENET_Reg<&ENET_Layout::ATCR,   1,  7> ENET_ATCR_PINPER;   // Enables event signal output external pin frc_evt_period assertion on period event
    // 0b0..Disable.
    // 0b1..Enable.
#undef ENET_ATCR_PEREN
constexpr ENET_Reg<&ENET_Layout::ATCR,   1,  4> ENET_ATCR_PEREN;    // Enable Periodical Event
    // 0b0..Disable.
    // 0b1..A period event interrupt can be generated (EIR[TS_TIMER]) and the event signal output is asserted when
    //      the timer wraps around according to the periodic setting ATPER. The timer period value must be set before
    //      setting this bit. Not all devices contain the event signal output. See the chip configuration details.
#undef ENET_ATCR_OFFRST
constexpr ENET_Reg<&ENET_Layout::ATCR,   1,  3> ENET_ATCR_OFFRST;   // Reset Timer On Offset Event
    // 0b0..The timer is not affected and no action occurs, besides clearing OFFEN, when the offset is reached.
    // 0b1..If OFFEN is set, the timer resets to zero when the offset setting is reached. The offset event does not cause a timer interrupt.
#undef ENET_ATCR_OFFEN
constexpr ENET_Reg<&ENET_Layout::ATCR,   1,  2> ENET_ATCR_OFFEN;    // Enable One-Shot Offset Event
    // 0b0..Disable.
    // 0b1..The timer can be reset to zero when the given offset time is reached (offset event). The field is cleared
    //      when the offset event is reached, so no further event occurs until the field is set again. The timer
    //      offset value must be set before setting this field.
#undef ENET_ATCR_EN
constexpr ENET_Reg<&ENET_Layout::ATCR,   1,  0> ENET_ATCR_EN;       // Enable Timer
    // 0b0..The timer stops at the current value.
    // 0b1..The timer starts incrementing.

// Timer Correction Register
#undef ENET_ATCOR_COR
constexpr ENET_Reg<&ENET_Layout::ATCOR, 31,  0> ENET_ATCOR_COR;  // Correction Counter Wrap-Around Value

// Time-Stamping Clock Period Register
#undef ENET_ATINC_INC_CORR
constexpr ENET_Reg<&ENET_Layout::ATINC,  7,  8> ENET_ATINC_INC_CORR;  // Correction Increment Value
#undef ENET_ATINC_INC
constexpr ENET_Reg<&ENET_Layout::ATINC,  7,  0> ENET_ATINC_INC;       // Clock Period Of The Timestamping Clock (ts_clk) In Nanoseconds

// Timer Global Status Register
#undef ENET_TGSR_TF3
constexpr ENET_Reg<&ENET_Layout::TGSR,   1,  3, true> ENET_TGSR_TF3;  // Copy Of Timer Flag For Channel 3
    // 0b0..Timer Flag for Channel 3 is clear
    // 0b1..Timer Flag for Channel 3 is set
#undef ENET_TGSR_TF2
constexpr ENET_Reg<&ENET_Layout::TGSR,   1,  2, true> ENET_TGSR_TF2;  // Copy Of Timer Flag For Channel 2
    // 0b0..Timer Flag for Channel 2 is clear
    // 0b1..Timer Flag for Channel 2 is set
#undef ENET_TGSR_TF1
constexpr ENET_Reg<&ENET_Layout::TGSR,   1,  1, true> ENET_TGSR_TF1;  // Copy Of Timer Flag For Channel 1
    // 0b0..Timer Flag for Channel 1 is clear
    // 0b1..Timer Flag for Channel 1 is set
#undef ENET_TGSR_TF0
constexpr ENET_Reg<&ENET_Layout::TGSR,   1,  0, true> ENET_TGSR_TF0;  // Copy Of Timer Flag For Channel 0
    // 0b0..Timer Flag for Channel 0 is clear
    // 0b1..Timer Flag for Channel 0 is set

// Timer Control Status Register
#undef ENET_TCSR0_TPWC
constexpr ENET_CHANNEL_Reg<0, &ENET_Layout::CHANNEL_Layout::TCSR, 5, 11> ENET_TCSR0_TPWC;   // Timer PulseWidth Control
    // 'value' + 1 1588-clock cycles:
    // 0b00000..Pulse width is one 1588-clock cycle.
    // 0b00001..Pulse width is two 1588-clock cycles.
    // 0b00010..Pulse width is three 1588-clock cycles.
    // 0b00011..Pulse width is four 1588-clock cycles.
    // 0b11111..Pulse width is 32 1588-clock cycles.
#undef ENET_TCSR0_TF
constexpr ENET_CHANNEL_Reg<0, &ENET_Layout::CHANNEL_Layout::TCSR, 1,  7> ENET_TCSR0_TF;     // Timer Flag
    // 0b0..Input Capture or Output Compare has not occurred.
    // 0b1..Input Capture or Output Compare has occurred.
#undef ENET_TCSR0_TIE
constexpr ENET_CHANNEL_Reg<0, &ENET_Layout::CHANNEL_Layout::TCSR, 1,  6> ENET_TCSR0_TIE;    // Timer Interrupt Enable
    // 0b0..Interrupt is disabled
    // 0b1..Interrupt is enabled
#undef ENET_TCSR0_TMODE
constexpr ENET_CHANNEL_Reg<0, &ENET_Layout::CHANNEL_Layout::TCSR, 4,  2> ENET_TCSR0_TMODE;  // Timer Mode
    // 0b0000..Timer Channel is disabled.
    // 0b0001..Timer Channel is configured for Input Capture on rising edge.
    // 0b0010..Timer Channel is configured for Input Capture on falling edge.
    // 0b0011..Timer Channel is configured for Input Capture on both edges.
    // 0b0100..Timer Channel is configured for Output Compare - software only.
    // 0b0101..Timer Channel is configured for Output Compare - toggle output on compare.
    // 0b0110..Timer Channel is configured for Output Compare - clear output on compare.
    // 0b0111..Timer Channel is configured for Output Compare - set output on compare.
    // 0b1000..Reserved
    // 0b1010..Timer Channel is configured for Output Compare - clear output on compare, set output on overflow.
    // 0b10x1..Timer Channel is configured for Output Compare - set output on compare, clear output on overflow.
    // 0b110x..Reserved
    // 0b1110..Timer Channel is configured for Output Compare - pulse output low on compare for 1 to 32 1588-clock cycles as specified by TPWC.
    // 0b1111..Timer Channel is configured for Output Compare - pulse output high on compare for 1 to 32 1588-clock cycles as specified by TPWC.
#undef ENET_TCSR0_TDRE
constexpr ENET_CHANNEL_Reg<0, &ENET_Layout::CHANNEL_Layout::TCSR, 1,  0> ENET_TCSR0_TDRE;   // Timer DMA Request Enable
    // 0b0..DMA request is disabled
    // 0b1..DMA request is enabled
#undef ENET_TCSR1_TPWC
constexpr ENET_CHANNEL_Reg<0, &ENET_Layout::CHANNEL_Layout::TCSR, 5, 11> ENET_TCSR1_TPWC;
#undef ENET_TCSR1_TF
constexpr ENET_CHANNEL_Reg<1, &ENET_Layout::CHANNEL_Layout::TCSR, 1,  7> ENET_TCSR1_TF;
#undef ENET_TCSR1_TIE
constexpr ENET_CHANNEL_Reg<1, &ENET_Layout::CHANNEL_Layout::TCSR, 1,  6> ENET_TCSR1_TIE;
#undef ENET_TCSR1_TMODE
constexpr ENET_CHANNEL_Reg<1, &ENET_Layout::CHANNEL_Layout::TCSR, 4,  2> ENET_TCSR1_TMODE;
#undef ENET_TCSR1_TDRE
constexpr ENET_CHANNEL_Reg<1, &ENET_Layout::CHANNEL_Layout::TCSR, 1,  0> ENET_TCSR1_TDRE;
#undef ENET_TCSR2_TPWC
constexpr ENET_CHANNEL_Reg<2, &ENET_Layout::CHANNEL_Layout::TCSR, 5, 11> ENET_TCSR2_TPWC;
#undef ENET_TCSR2_TF
constexpr ENET_CHANNEL_Reg<2, &ENET_Layout::CHANNEL_Layout::TCSR, 1,  7> ENET_TCSR2_TF;
#undef ENET_TCSR2_TIE
constexpr ENET_CHANNEL_Reg<2, &ENET_Layout::CHANNEL_Layout::TCSR, 1,  6> ENET_TCSR2_TIE;
#undef ENET_TCSR2_TMODE
constexpr ENET_CHANNEL_Reg<2, &ENET_Layout::CHANNEL_Layout::TCSR, 4,  2> ENET_TCSR2_TMODE;
#undef ENET_TCSR2_TDRE
constexpr ENET_CHANNEL_Reg<2, &ENET_Layout::CHANNEL_Layout::TCSR, 1,  0> ENET_TCSR2_TDRE;
#undef ENET_TCSR3_TPWC
constexpr ENET_CHANNEL_Reg<3, &ENET_Layout::CHANNEL_Layout::TCSR, 5, 11> ENET_TCSR3_TPWC;
#undef ENET_TCSR3_TF
constexpr ENET_CHANNEL_Reg<3, &ENET_Layout::CHANNEL_Layout::TCSR, 1,  7> ENET_TCSR3_TF;
#undef ENET_TCSR3_TIE
constexpr ENET_CHANNEL_Reg<3, &ENET_Layout::CHANNEL_Layout::TCSR, 1,  6> ENET_TCSR3_TIE;
#undef ENET_TCSR3_TMODE
constexpr ENET_CHANNEL_Reg<3, &ENET_Layout::CHANNEL_Layout::TCSR, 4,  2> ENET_TCSR3_TMODE;
#undef ENET_TCSR3_TDRE
constexpr ENET_CHANNEL_Reg<3, &ENET_Layout::CHANNEL_Layout::TCSR, 1,  0> ENET_TCSR3_TDRE;

#undef ENET2_EIR_BABR
constexpr ENET_Reg<&ENET_Layout::EIR,    1, 30, true> ENET2_EIR_BABR;
#undef ENET2_EIR_BABT
constexpr ENET2_Reg<&ENET_Layout::EIR,    1, 29, true> ENET2_EIR_BABT;
#undef ENET2_EIR_GRA
constexpr ENET2_Reg<&ENET_Layout::EIR,    1, 28, true> ENET2_EIR_GRA;
#undef ENET2_EIR_TXF
constexpr ENET2_Reg<&ENET_Layout::EIR,    1, 27, true> ENET2_EIR_TXF;
#undef ENET2_EIR_TXB
constexpr ENET2_Reg<&ENET_Layout::EIR,    1, 26, true> ENET2_EIR_TXB;
#undef ENET2_EIR_RXF
constexpr ENET2_Reg<&ENET_Layout::EIR,    1, 25, true> ENET2_EIR_RXF;
#undef ENET2_EIR_RXB
constexpr ENET2_Reg<&ENET_Layout::EIR,    1, 24, true> ENET2_EIR_RXB;
#undef ENET2_EIR_MII
constexpr ENET2_Reg<&ENET_Layout::EIR,    1, 23, true> ENET2_EIR_MII;
#undef ENET2_EIR_EBERR
constexpr ENET2_Reg<&ENET_Layout::EIR,    1, 22, true> ENET2_EIR_EBERR;
#undef ENET2_EIR_LC
constexpr ENET2_Reg<&ENET_Layout::EIR,    1, 21, true> ENET2_EIR_LC;
#undef ENET2_EIR_RL
constexpr ENET2_Reg<&ENET_Layout::EIR,    1, 20, true> ENET2_EIR_RL;
#undef ENET2_EIR_UN
constexpr ENET2_Reg<&ENET_Layout::EIR,    1, 19, true> ENET2_EIR_UN;
#undef ENET2_EIR_PLR
constexpr ENET2_Reg<&ENET_Layout::EIR,    1, 18, true> ENET2_EIR_PLR;
#undef ENET2_EIR_WAKEUP
constexpr ENET2_Reg<&ENET_Layout::EIR,    1, 17, true> ENET2_EIR_WAKEUP;
#undef ENET2_EIR_TS_AVAIL
constexpr ENET2_Reg<&ENET_Layout::EIR,    1, 16, true> ENET2_EIR_TS_AVAIL;
#undef ENET2_EIR_TS_TIMER
constexpr ENET2_Reg<&ENET_Layout::EIR,    1, 15, true> ENET2_EIR_TS_TIMER;
#undef ENET2_EIMR_BABR
constexpr ENET2_Reg<&ENET_Layout::EIMR,   1, 30> ENET2_EIMR_BABR;
#undef ENET2_EIMR_BABT
constexpr ENET2_Reg<&ENET_Layout::EIMR,   1, 29> ENET2_EIMR_BABT;
#undef ENET2_EIMR_GRA
constexpr ENET2_Reg<&ENET_Layout::EIMR,   1, 28> ENET2_EIMR_GRA;
#undef ENET2_EIMR_TXF
constexpr ENET2_Reg<&ENET_Layout::EIMR,   1, 27> ENET2_EIMR_TXF;
#undef ENET2_EIMR_TXB
constexpr ENET2_Reg<&ENET_Layout::EIMR,   1, 26> ENET2_EIMR_TXB;
#undef ENET2_EIMR_RXF
constexpr ENET2_Reg<&ENET_Layout::EIMR,   1, 25> ENET2_EIMR_RXF;
#undef ENET2_EIMR_RXB
constexpr ENET2_Reg<&ENET_Layout::EIMR,   1, 24> ENET2_EIMR_RXB;
#undef ENET2_EIMR_MII
constexpr ENET2_Reg<&ENET_Layout::EIMR,   1, 23> ENET2_EIMR_MII;
#undef ENET2_EIMR_EBERR
constexpr ENET2_Reg<&ENET_Layout::EIMR,   1, 22> ENET2_EIMR_EBERR;
#undef ENET2_EIMR_LC
constexpr ENET2_Reg<&ENET_Layout::EIMR,   1, 21> ENET2_EIMR_LC;
#undef ENET2_EIMR_RL
constexpr ENET2_Reg<&ENET_Layout::EIMR,   1, 20> ENET2_EIMR_RL;
#undef ENET2_EIMR_UN
constexpr ENET2_Reg<&ENET_Layout::EIMR,   1, 19> ENET2_EIMR_UN;
#undef ENET2_EIMR_PLR
constexpr ENET2_Reg<&ENET_Layout::EIMR,   1, 18> ENET2_EIMR_PLR;
#undef ENET2_EIMR_WAKEUP
constexpr ENET2_Reg<&ENET_Layout::EIMR,   1, 17> ENET2_EIMR_WAKEUP;
#undef ENET2_EIMR_TS_AVAIL
constexpr ENET2_Reg<&ENET_Layout::EIMR,   1, 16> ENET2_EIMR_TS_AVAIL;
#undef ENET2_EIMR_TS_TIMER
constexpr ENET2_Reg<&ENET_Layout::EIMR,   1, 15> ENET2_EIMR_TS_TIMER;
#undef ENET2_RDAR_RDAR
constexpr ENET2_Reg<&ENET_Layout::RDAR,   1, 24> ENET2_RDAR_RDAR;
#undef ENET2_TDAR_TDAR
constexpr ENET2_Reg<&ENET_Layout::TDAR,   1, 24> ENET2_TDAR_TDAR;
#undef ENET2_ECR_DBSWP
constexpr ENET2_Reg<&ENET_Layout::ECR,    1,  8> ENET2_ECR_DBSWP;
#undef ENET2_ECR_DBGEN
constexpr ENET2_Reg<&ENET_Layout::ECR,    1,  6> ENET2_ECR_DBGEN;
#undef ENET2_ECR_EN1588
constexpr ENET2_Reg<&ENET_Layout::ECR,    1,  4> ENET2_ECR_EN1588;
#undef ENET2_ECR_SLEEP
constexpr ENET2_Reg<&ENET_Layout::ECR,    1,  3> ENET2_ECR_SLEEP;
#undef ENET2_ECR_MAGICEN
constexpr ENET2_Reg<&ENET_Layout::ECR,    1,  2> ENET2_ECR_MAGICEN;
#undef ENET2_ECR_ETHEREN
constexpr ENET2_Reg<&ENET_Layout::ECR,    1,  1> ENET2_ECR_ETHEREN;
#undef ENET2_ECR_RESET
constexpr ENET2_Reg<&ENET_Layout::ECR,    1,  0> ENET2_ECR_RESET;
#undef ENET2_MMFR_ST
constexpr ENET2_Reg<&ENET_Layout::MMFR,   2, 30> ENET2_MMFR_ST;
#undef ENET2_MMFR_OP
constexpr ENET2_Reg<&ENET_Layout::MMFR,   2, 28> ENET2_MMFR_OP;
#undef ENET2_MMFR_PA
constexpr ENET2_Reg<&ENET_Layout::MMFR,   5, 23> ENET2_MMFR_PA;
#undef ENET2_MMFR_RA
constexpr ENET2_Reg<&ENET_Layout::MMFR,   5, 18> ENET2_MMFR_RA;
#undef ENET2_MMFR_TA
constexpr ENET2_Reg<&ENET_Layout::MMFR,   2, 16> ENET2_MMFR_TA;
#undef ENET2_MMFR_DATA
constexpr ENET2_Reg<&ENET_Layout::MMFR,  16,  0> ENET2_MMFR_DATA;
#undef ENET2_MSCR_HOLDTIME
constexpr ENET2_Reg<&ENET_Layout::MSCR,   3,  8> ENET2_MSCR_HOLDTIME;
#undef ENET2_MSCR_DIS_PRE
constexpr ENET2_Reg<&ENET_Layout::MSCR,   1,  7> ENET2_MSCR_DIS_PRE;
#undef ENET2_MSCR_MII_SPEED
constexpr ENET2_Reg<&ENET_Layout::MSCR,   6,  1> ENET2_MSCR_MII_SPEED;
#undef ENET2_RCR_GRS
constexpr ENET2_Reg<&ENET_Layout::RCR,    1, 31> ENET2_RCR_GRS;
#undef ENET2_RCR_NLC
constexpr ENET2_Reg<&ENET_Layout::RCR,    1, 30> ENET2_RCR_NLC;
#undef ENET2_RCR_MAX_FL
constexpr ENET2_Reg<&ENET_Layout::RCR,   14, 16> ENET2_RCR_MAX_FL;
#undef ENET2_RCR_CFEN
constexpr ENET2_Reg<&ENET_Layout::RCR,    1, 15> ENET2_RCR_CFEN;
#undef ENET2_RCR_CRCFWD
constexpr ENET2_Reg<&ENET_Layout::RCR,    1, 14> ENET2_RCR_CRCFWD;
#undef ENET2_RCR_PAUFWD
constexpr ENET2_Reg<&ENET_Layout::RCR,    1, 13> ENET2_RCR_PAUFWD;
#undef ENET2_RCR_PADEN
constexpr ENET2_Reg<&ENET_Layout::RCR,    1, 12> ENET2_RCR_PADEN;
#undef ENET2_RCR_RMII_10T
constexpr ENET2_Reg<&ENET_Layout::RCR,    1,  9> ENET2_RCR_RMII_10T;
#undef ENET2_RCR_RMII_MODE
constexpr ENET2_Reg<&ENET_Layout::RCR,    1,  8> ENET2_RCR_RMII_MODE;
#undef ENET2_RCR_FCE
constexpr ENET2_Reg<&ENET_Layout::RCR,    1,  5> ENET2_RCR_FCE;
#undef ENET2_RCR_BC_REG
constexpr ENET2_Reg<&ENET_Layout::RCR,    1,  4> ENET2_RCR_BC_REG;
#undef ENET2_RCR_PROM
constexpr ENET2_Reg<&ENET_Layout::RCR,    1,  3> ENET2_RCR_PROM;
#undef ENET2_RCR_MII_MODE
constexpr ENET2_Reg<&ENET_Layout::RCR,    1,  2> ENET2_RCR_MII_MODE;
#undef ENET2_RCR_DRT
constexpr ENET2_Reg<&ENET_Layout::RCR,    1,  1> ENET2_RCR_DRT;
#undef ENET2_RCR_LOOP
constexpr ENET2_Reg<&ENET_Layout::RCR,    1,  0> ENET2_RCR_LOOP;
#undef ENET2_TCR_CRCFWD
constexpr ENET2_Reg<&ENET_Layout::TCR,    1,  9> ENET2_TCR_CRCFWD;
#undef ENET2_TCR_ADDINS
constexpr ENET2_Reg<&ENET_Layout::TCR,    1,  8> ENET2_TCR_ADDINS;
#undef ENET2_TCR_ADDSEL
constexpr ENET2_Reg<&ENET_Layout::TCR,    3,  5> ENET2_TCR_ADDSEL;
#undef ENET2_TCR_RFC_PAUSE
constexpr ENET2_Reg<&ENET_Layout::TCR,    1,  4> ENET2_TCR_RFC_PAUSE;
#undef ENET2_TCR_TFC_PAUSE
constexpr ENET2_Reg<&ENET_Layout::TCR,    1,  3> ENET2_TCR_TFC_PAUSE;
#undef ENET2_TCR_FDEN
constexpr ENET2_Reg<&ENET_Layout::TCR,    1,  2> ENET2_TCR_FDEN;
#undef ENET2_TCR_GTS
constexpr ENET2_Reg<&ENET_Layout::TCR,    1,  0> ENET2_TCR_GTS;
#undef ENET2_OPD_OPCODE
constexpr ENET2_Reg<&ENET_Layout::OPD,   16, 16> ENET2_OPD_OPCODE;
#undef ENET2_OPD_PAUSE_DUR
constexpr ENET2_Reg<&ENET_Layout::OPD,   16,  0> ENET2_OPD_PAUSE_DUR;
#undef ENET2_TXIC0_ICEN
constexpr ENET2_Reg<&ENET_Layout::TXIC,   1, 31> ENET2_TXIC0_ICEN;
#undef ENET2_TXIC0_ICCS
constexpr ENET2_Reg<&ENET_Layout::TXIC,   1, 30> ENET2_TXIC0_ICCS;
#undef ENET2_TXIC0_ICFT
constexpr ENET2_Reg<&ENET_Layout::TXIC,   8, 20> ENET2_TXIC0_ICFT;
#undef ENET2_TXIC0_ICTT
constexpr ENET2_Reg<&ENET_Layout::TXIC,  16,  0> ENET2_TXIC0_ICTT;
#undef ENET2_RXIC0_ICEN
constexpr ENET2_Reg<&ENET_Layout::RXIC,   1, 31> ENET2_RXIC0_ICEN;
#undef ENET2_RXIC0_ICCS
constexpr ENET2_Reg<&ENET_Layout::RXIC,   1, 30> ENET2_RXIC0_ICCS;
#undef ENET2_RXIC0_ICFT
constexpr ENET2_Reg<&ENET_Layout::RXIC,   8, 20> ENET2_RXIC0_ICFT;
#undef ENET2_RXIC0_ICTT
constexpr ENET2_Reg<&ENET_Layout::RXIC,  16,  0> ENET2_RXIC0_ICTT;
#undef ENET2_TFWR_STRFWD
constexpr ENET2_Reg<&ENET_Layout::TFWR,   1,  8> ENET2_TFWR_STRFWD;
#undef ENET2_TFWR_TFWR
constexpr ENET2_Reg<&ENET_Layout::TFWR,   6,  0> ENET2_TFWR_TFWR;
#undef ENET2_RDSR_R_DES_START
constexpr ENET2_Reg<&ENET_Layout::RDSR,  29,  3> ENET2_RDSR_R_DES_START;
#undef ENET2_TDSR_X_DES_START
constexpr ENET2_Reg<&ENET_Layout::TDSR,  29,  3> ENET2_TDSR_X_DES_START;
#undef ENET2_MRBR_R_BUF_SIZE
constexpr ENET2_Reg<&ENET_Layout::MRBR,  10,  4> ENET2_MRBR_R_BUF_SIZE;
#undef ENET2_RSFL_RX_SECTION_FULL
constexpr ENET2_Reg<&ENET_Layout::RSFL,   8,  0> ENET2_RSFL_RX_SECTION_FULL;
#undef ENET2_RSEM_STAT_SECTION_EMPTY
constexpr ENET2_Reg<&ENET_Layout::RSEM,   5, 16> ENET2_RSEM_STAT_SECTION_EMPTY;
#undef ENET2_RSEM_RX_SECTION_EMPTY
constexpr ENET2_Reg<&ENET_Layout::RSEM,   8,  0> ENET2_RSEM_RX_SECTION_EMPTY;
#undef ENET2_RAEM_RX_ALMOST_EMPTY
constexpr ENET2_Reg<&ENET_Layout::RAEM,   8,  0> ENET2_RAEM_RX_ALMOST_EMPTY;
#undef ENET2_RAFL_RX_ALMOST_FULL
constexpr ENET2_Reg<&ENET_Layout::RAFL,   8,  0> ENET2_RAFL_RX_ALMOST_FULL;
#undef ENET2_TSEM_TX_SECTION_EMPTY
constexpr ENET2_Reg<&ENET_Layout::TSEM,   8,  0> ENET2_TSEM_TX_SECTION_EMPTY;
#undef ENET2_TAEM_TX_ALMOST_EMPTY
constexpr ENET2_Reg<&ENET_Layout::TAEM,   8,  0> ENET2_TAEM_TX_ALMOST_EMPTY;
#undef ENET2_TAFL_TX_ALMOST_FULL
constexpr ENET2_Reg<&ENET_Layout::TAFL,   8,  0> ENET2_TAFL_TX_ALMOST_FULL;
#undef ENET2_TIPG_IPG
constexpr ENET2_Reg<&ENET_Layout::TIPG,   5,  0> ENET2_TIPG_IPG;
#undef ENET2_FTRL_TRUNC_FL
constexpr ENET2_Reg<&ENET_Layout::FTRL,  14,  0> ENET2_FTRL_TRUNC_FL;
#undef ENET2_TACC_PROCHK
constexpr ENET2_Reg<&ENET_Layout::TACC,   1,  4> ENET2_TACC_PROCHK;
#undef ENET2_TACC_IPCHK
constexpr ENET2_Reg<&ENET_Layout::TACC,   1,  3> ENET2_TACC_IPCHK;
#undef ENET2_TACC_SHIFT16
constexpr ENET2_Reg<&ENET_Layout::TACC,   1,  0> ENET2_TACC_SHIFT16;
#undef ENET2_RACC_SHIFT16
constexpr ENET2_Reg<&ENET_Layout::RACC,   1,  7> ENET2_RACC_SHIFT16;
#undef ENET2_RACC_LINEDIS
constexpr ENET2_Reg<&ENET_Layout::RACC,   1,  6> ENET2_RACC_LINEDIS;
#undef ENET2_RACC_PRODIS
constexpr ENET2_Reg<&ENET_Layout::RACC,   1,  2> ENET2_RACC_PRODIS;
#undef ENET2_RACC_IPDIS
constexpr ENET2_Reg<&ENET_Layout::RACC,   1,  1> ENET2_RACC_IPDIS;
#undef ENET2_RACC_PADREM
constexpr ENET2_Reg<&ENET_Layout::RACC,   1,  0> ENET2_RACC_PADREM;

#undef ENET2_ATCR_SLAVE
constexpr ENET2_Reg<&ENET_Layout::ATCR,   1, 13> ENET2_ATCR_SLAVE;
#undef ENET2_ATCR_CAPTURE
constexpr ENET2_Reg<&ENET_Layout::ATCR,   1, 11> ENET2_ATCR_CAPTURE;
#undef ENET2_ATCR_RESTART
constexpr ENET2_Reg<&ENET_Layout::ATCR,   1,  9> ENET2_ATCR_RESTART;
#undef ENET2_ATCR_PINPER
constexpr ENET2_Reg<&ENET_Layout::ATCR,   1,  7> ENET2_ATCR_PINPER;
#undef ENET2_ATCR_PEREN
constexpr ENET2_Reg<&ENET_Layout::ATCR,   1,  4> ENET2_ATCR_PEREN;
#undef ENET2_ATCR_OFFRST
constexpr ENET2_Reg<&ENET_Layout::ATCR,   1,  3> ENET2_ATCR_OFFRST;
#undef ENET2_ATCR_OFFEN
constexpr ENET2_Reg<&ENET_Layout::ATCR,   1,  2> ENET2_ATCR_OFFEN;
#undef ENET2_ATCR_EN
constexpr ENET2_Reg<&ENET_Layout::ATCR,   1,  0> ENET2_ATCR_EN;
#undef ENET2_ATCOR_COR
constexpr ENET2_Reg<&ENET_Layout::ATCOR, 31,  0> ENET2_ATCOR_COR;
#undef ENET2_ATINC_INC_CORR
constexpr ENET2_Reg<&ENET_Layout::ATINC,  7,  8> ENET2_ATINC_INC_CORR;
#undef ENET2_ATINC_INC
constexpr ENET2_Reg<&ENET_Layout::ATINC,  7,  0> ENET2_ATINC_INC;

#undef ENET2_TGSR_TF3
constexpr ENET2_Reg<&ENET_Layout::TGSR,   1,  3, true> ENET2_TGSR_TF3;
#undef ENET2_TGSR_TF2
constexpr ENET2_Reg<&ENET_Layout::TGSR,   1,  2, true> ENET2_TGSR_TF2;
#undef ENET2_TGSR_TF1
constexpr ENET2_Reg<&ENET_Layout::TGSR,   1,  1, true> ENET2_TGSR_TF1;
#undef ENET2_TGSR_TF0
constexpr ENET2_Reg<&ENET_Layout::TGSR,   1,  0, true> ENET2_TGSR_TF0;

#undef ENET2_TCSR0_TPWC
constexpr ENET2_CHANNEL_Reg<0, &ENET_Layout::CHANNEL_Layout::TCSR, 5, 11> ENET2_TCSR0_TPWC;
#undef ENET2_TCSR0_TF
constexpr ENET2_CHANNEL_Reg<0, &ENET_Layout::CHANNEL_Layout::TCSR, 1,  7> ENET2_TCSR0_TF;
#undef ENET2_TCSR0_TIE
constexpr ENET2_CHANNEL_Reg<0, &ENET_Layout::CHANNEL_Layout::TCSR, 1,  6> ENET2_TCSR0_TIE;
#undef ENET2_TCSR0_TMODE
constexpr ENET2_CHANNEL_Reg<0, &ENET_Layout::CHANNEL_Layout::TCSR, 4,  2> ENET2_TCSR0_TMODE;
#undef ENET2_TCSR0_TDRE
constexpr ENET2_CHANNEL_Reg<0, &ENET_Layout::CHANNEL_Layout::TCSR, 1,  0> ENET2_TCSR0_TDRE;
#undef ENET2_TCSR1_TPWC
constexpr ENET2_CHANNEL_Reg<0, &ENET_Layout::CHANNEL_Layout::TCSR, 5, 11> ENET2_TCSR1_TPWC;
#undef ENET2_TCSR1_TF
constexpr ENET2_CHANNEL_Reg<1, &ENET_Layout::CHANNEL_Layout::TCSR, 1,  7> ENET2_TCSR1_TF;
#undef ENET2_TCSR1_TIE
constexpr ENET2_CHANNEL_Reg<1, &ENET_Layout::CHANNEL_Layout::TCSR, 1,  6> ENET2_TCSR1_TIE;
#undef ENET2_TCSR1_TMODE
constexpr ENET2_CHANNEL_Reg<1, &ENET_Layout::CHANNEL_Layout::TCSR, 4,  2> ENET2_TCSR1_TMODE;
#undef ENET2_TCSR1_TDRE
constexpr ENET2_CHANNEL_Reg<1, &ENET_Layout::CHANNEL_Layout::TCSR, 1,  0> ENET2_TCSR1_TDRE;
#undef ENET2_TCSR2_TPWC
constexpr ENET2_CHANNEL_Reg<2, &ENET_Layout::CHANNEL_Layout::TCSR, 5, 11> ENET2_TCSR2_TPWC;
#undef ENET2_TCSR2_TF
constexpr ENET2_CHANNEL_Reg<2, &ENET_Layout::CHANNEL_Layout::TCSR, 1,  7> ENET2_TCSR2_TF;
#undef ENET2_TCSR2_TIE
constexpr ENET2_CHANNEL_Reg<2, &ENET_Layout::CHANNEL_Layout::TCSR, 1,  6> ENET2_TCSR2_TIE;
#undef ENET2_TCSR2_TMODE
constexpr ENET2_CHANNEL_Reg<2, &ENET_Layout::CHANNEL_Layout::TCSR, 4,  2> ENET2_TCSR2_TMODE;
#undef ENET2_TCSR2_TDRE
constexpr ENET2_CHANNEL_Reg<2, &ENET_Layout::CHANNEL_Layout::TCSR, 1,  0> ENET2_TCSR2_TDRE;
#undef ENET2_TCSR3_TPWC
constexpr ENET2_CHANNEL_Reg<3, &ENET_Layout::CHANNEL_Layout::TCSR, 5, 11> ENET2_TCSR3_TPWC;
#undef ENET2_TCSR3_TF
constexpr ENET2_CHANNEL_Reg<3, &ENET_Layout::CHANNEL_Layout::TCSR, 1,  7> ENET2_TCSR3_TF;
#undef ENET2_TCSR3_TIE
constexpr ENET2_CHANNEL_Reg<3, &ENET_Layout::CHANNEL_Layout::TCSR, 1,  6> ENET2_TCSR3_TIE;
#undef ENET2_TCSR3_TMODE
constexpr ENET2_CHANNEL_Reg<3, &ENET_Layout::CHANNEL_Layout::TCSR, 4,  2> ENET2_TCSR3_TMODE;
#undef ENET2_TCSR3_TDRE
constexpr ENET2_CHANNEL_Reg<3, &ENET_Layout::CHANNEL_Layout::TCSR, 1,  0> ENET2_TCSR3_TDRE;

}  // namespace teensy4
}  // namespace hardware
}  // namespace qindesign
