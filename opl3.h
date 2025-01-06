/*
 * SPDX-License-Identifier: LGPL-2.1-or-later
 *
 * Copyright (C) 2013-2021  Nuke.YKT
 *
 * This file is part of Nuked OPL3.
 *
 * Nuked OPL3 is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation, either version 2.1
 * of the License, or (at your option) any later version.
 *
 * Nuked OPL3 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Nuked OPL3. If not, see <https://www.gnu.org/licenses/>.

 *  Nuked OPL3 emulator.
 *  Thanks:
 *      MAME Development Team(Jarek Burczynski, Tatsuyuki Satoh):
 *          Feedback and Rhythm part calculation information.
 *      forums.submarine.org.uk(carbon14, opl3):
 *          Tremolo and phase generator calculation information.
 *      OPLx decapsulated(Matthew Gambrell, Olli Niemitalo):
 *          OPL2 ROMs.
 *      siliconpr0n.org(John McMaster, digshadow):
 *          YMF262 and VRC VII decaps and die shots.
 *
 * version: 1.8
 */

#ifndef OPL_OPL3_H
#define OPL_OPL3_H

#include <export.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct opl3_chip opl3_chip;

OPL_EXPORT void OPL3_Generate(opl3_chip *chip, int16_t *buf);
OPL_EXPORT void OPL3_GenerateResampled(opl3_chip *chip, int16_t *buf);
OPL_EXPORT void OPL3_Reset(opl3_chip *chip, uint32_t samplerate);
OPL_EXPORT void OPL3_WriteReg(opl3_chip *chip, uint16_t reg, uint8_t v);
OPL_EXPORT void OPL3_WriteRegBuffered(opl3_chip *chip, uint16_t reg, uint8_t v);
OPL_EXPORT void OPL3_WriteRegDelayed(opl3_chip *chip, uint16_t reg, uint8_t v, uint64_t delay);
OPL_EXPORT void OPL3_GenerateStream(opl3_chip *chip, int16_t *sndptr, uint32_t numsamples);

OPL_EXPORT void OPL3_Generate4Ch(opl3_chip *chip, int16_t *buf4);
OPL_EXPORT void OPL3_Generate4ChResampled(opl3_chip *chip, int16_t *buf4);
OPL_EXPORT void OPL3_Generate4ChStream(opl3_chip *chip, int16_t *sndptr1, int16_t *sndptr2, uint32_t numsamples);

#ifdef __cplusplus
}
#endif

#endif
