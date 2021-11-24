/* Copyright 2021 Jasper Chan
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

/* Send up to 4 key press events per scan */
#define QMK_KEYS_PER_SCAN 4

/* Set debounce time to 10ms from 5ms -- double input issue [SPACE] 
   from ../../../gmmk/pro/config.h */
/* Set debounce time to 5ms */
#define DEBOUNCE 16

/* Force NKRO on boot up regardless of the setting saved in the EEPROM (uncomment to enable it) */
#define FORCE_NKRO

// number of milliseconds to wait until rgb automatically turns off
#define RGB_DISABLE_TIMEOUT 300000

// debug scan rate
#ifdef CONSOLE_ENABLE
	#define DEBUG_MATRIX_SCAN_RATE
#endif
