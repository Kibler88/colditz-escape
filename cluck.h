/*
 *  Colditz Escape! - Rewritten Engine for "Escape From Colditz"
 *  copyright (C) 2008-2009 Aperture Software 
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 *  ---------------------------------------------------------------------------
 *  cluck.h: Chicken SFX
 *  ---------------------------------------------------------------------------
 */

#pragma once

#ifdef	__cplusplus
extern "C" {
#endif

//u32  cluck_sfx_size = 3450;
u8   cluck_sfx[] = {
0x80,0x82,0x82,0x83,0x85,0x84,0x84,0x85,0x83,0x82,0x82,0x81,0x7f,0x80,0x7e,
0x7c,0x7a,0x79,0x79,0x79,0x79,0x79,0x78,0x76,0x78,0x7a,0x79,0x7a,0x7c,0x7c,
0x7c,0x7c,0x7b,0x7c,0x7b,0x7c,0x7a,0x79,0x79,0x7a,0x77,0x79,0x7b,0x77,0x7b,
0x7a,0x75,0x73,0x70,0x6c,0x70,0x76,0x6e,0x72,0x66,0x5b,0x75,0x80,0x85,0x89,
0x8d,0x9a,0xa1,0xa0,0xa5,0xa4,0x9c,0x97,0x94,0x92,0x8e,0x86,0x80,0x86,0x85,
0x8a,0x91,0x8a,0x8f,0x8f,0x8f,0x92,0x93,0x93,0x91,0x90,0x89,0x83,0x80,0x7a,
0x72,0x70,0x78,0x74,0x76,0x74,0x6c,0x69,0x68,0x6f,0x77,0x7f,0x80,0x81,0x7b,
0x74,0x75,0x6f,0x71,0x77,0x7b,0x7d,0x7e,0x77,0x73,0x70,0x70,0x78,0x81,0x87,
0x8b,0x8f,0x8f,0x88,0x7f,0x74,0x6b,0x6a,0x6d,0x72,0x7a,0x80,0x87,0x8a,0x8c,
0x8d,0x8f,0x90,0x8f,0x8f,0x90,0x8f,0x8e,0x85,0x79,0x6d,0x63,0x62,0x66,0x6e,
0x73,0x79,0x7d,0x7f,0x82,0x86,0x8d,0x91,0x93,0x93,0x8f,0x8c,0x85,0x6d,0x56,
0x44,0x3e,0x53,0x74,0x9f,0xbb,0xbb,0xaf,0x8d,0x6c,0x5d,0x58,0x70,0x87,0xa5,
0xb8,0xae,0xa2,0x7f,0x65,0x56,0x56,0x60,0x5d,0x62,0x68,0x7b,0x87,0x95,0x9d,
0x9c,0x97,0x89,0x84,0x71,0x73,0x70,0x70,0x7a,0x79,0x83,0x83,0x85,0x7f,0x7b,
0x7d,0x76,0x78,0x86,0x8f,0x9c,0x95,0x90,0x83,0x75,0x6f,0x78,0x86,0x90,0x96,
0x8f,0x7f,0x71,0x6a,0x6a,0x70,0x7a,0x7c,0x7c,0x78,0x72,0x70,0x72,0x74,0x77,
0x7c,0x7b,0x7e,0x81,0x84,0x8a,0x88,0x81,0x7b,0x76,0x7a,0x7e,0x82,0x83,0x86,
0x7f,0x7a,0x7b,0x7c,0x86,0x87,0x87,0x83,0x7e,0x7d,0x80,0x85,0x89,0x8a,0x87,
0x81,0x79,0x7a,0x7c,0x81,0x84,0x85,0x7f,0x7c,0x78,0x78,0x7b,0x83,0x85,0x85,
0x81,0x7c,0x7e,0x7d,0x81,0x81,0x81,0x80,0x7d,0x7e,0x7e,0x83,0x81,0x80,0x7f,
0x7e,0x7d,0x82,0x85,0x85,0x81,0x7d,0x7e,0x80,0x84,0x84,0x84,0x7f,0x7c,0x7a,
0x7f,0x81,0x81,0x7f,0x7d,0x7a,0x7a,0x7d,0x7f,0x81,0x7f,0x7d,0x7b,0x7d,0x80,
0x80,0x81,0x7f,0x7d,0x7e,0x7e,0x7f,0x80,0x80,0x80,0x7f,0x7d,0x7f,0x80,0x80,
0x80,0x7f,0x7d,0x7f,0x81,0x80,0x80,0x80,0x80,0x7f,0x7f,0x80,0x80,0x81,0x7e,
0x7d,0x7d,0x7f,0x80,0x81,0x7f,0x7e,0x7e,0x7f,0x81,0x80,0x80,0x80,0x7f,0x7f,
0x80,0x80,0x81,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,
0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x7f,0x7e,
0x7e,0x7f,0x81,0x80,0x81,0x7f,0x7e,0x7e,0x7f,0x80,0x80,0x80,0x80,0x80,0x80,
0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,
0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x7f,0x7e,0x7e,
0x7f,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,
0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,
0x80,0x80,0x80,0x80,0x80,0x7f,0x7e,0x7e,0x7e,0x80,0x80,0x80,0x80,0x80,0x80,
0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,
0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,
0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,
0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,
0x80,0x80,0x80,0x7f,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,
0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,
0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,
0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,
0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,
0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,
0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,
0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,
0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,
0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,
0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,
0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x7f,0x7f,0x81,0x7e,0x7f,
0x80,0x80,0x7f,0x82,0x7d,0x79,0x82,0x81,0x82,0x7b,0x79,0x77,0x7b,0x7c,0x73,
0x75,0x7b,0x83,0x8b,0x8f,0x89,0x83,0x7e,0x81,0x85,0x96,0x74,0x5c,0x62,0x77,
0x9f,0x99,0x81,0x6a,0x69,0x7c,0x8f,0x93,0x84,0x77,0x76,0x83,0x86,0x88,0x88,
0x77,0x71,0x6c,0x72,0x81,0x8d,0x84,0x7f,0x82,0x94,0x88,0x73,0x70,0x72,0x82,
0x8a,0x90,0x88,0x7a,0x6a,0x66,0x6a,0x73,0x84,0x86,0x88,0x82,0x7c,0x7e,0x83,
0x8a,0x8f,0x8e,0x8a,0x8a,0x80,0x6b,0x60,0x5a,0x6e,0x8b,0x98,0x93,0x81,0x73,
0x7c,0x8c,0x9a,0x9a,0x9d,0x8e,0x5f,0x4c,0x3e,0x5f,0x99,0xb3,0xae,0x79,0x58,
0x60,0x85,0xae,0xb8,0xac,0x84,0x48,0x2e,0x31,0x6f,0xbb,0xce,0xa4,0x59,0x43,
0x67,0xa7,0xcf,0xbd,0x8e,0x4d,0x24,0x36,0x6b,0xb4,0xd2,0xaa,0x67,0x3c,0x54,
0x98,0xcb,0xd2,0xa1,0x51,0x10,0x22,0x62,0xbd,0xe3,0xb2,0x64,0x2f,0x4b,0xa5,
0xe5,0xe6,0x9a,0x22,0x01,0x23,0x8b,0xf9,0xeb,0x98,0x2e,0x1b,0x5f,0xc5,0xf6,
0xe4,0x79,0x0b,0x09,0x30,0xb8,0xfd,0xe6,0x78,0x0b,0x21,0x72,0xe3,0xfb,0xca,
0x4a,0x00,0x10,0x4f,0xe4,0xfa,0xc1,0x55,0x0c,0x2e,0x96,0xeb,0xfe,0xad,0x11,
0x01,0x0a,0x9c,0xff,0xf3,0xa2,0x13,0x0d,0x56,0xc8,0xfe,0xdf,0x3f,0x00,0x0a,
0x65,0xf3,0xf6,0xbf,0x42,0x18,0x3a,0x9c,0xf0,0xf0,0x66,0x06,0x0a,0x56,0xe3,
0xfa,0xc4,0x55,0x22,0x36,0x8f,0xe9,0xe8,0x5f,0x03,0x0c,0x68,0xe9,0xf1,0xb3,
0x58,0x39,0x45,0x91,0xe9,0xc5,0x2d,0x00,0x1e,0x9a,0xe5,0xd4,0x9b,0x50,0x4e,
0x60,0xa9,0xdf,0x71,0x0d,0x11,0x5d,0xd0,0xd2,0xae,0x6c,0x57,0x63,0x83,0xd4,
0xa8,0x25,0x0a,0x3c,0xb5,0xdd,0xb5,0x83,0x53,0x5d,0x70,0xba,0xcb,0x45,0x01,
0x25,0x8e,0xe1,0xc1,0x9b,0x60,0x56,0x64,0x9a,0xd4,0x66,0x0f,0x2a,0x78,0xd6,
0xc5,0xa0,0x72,0x5d,0x68,0x7d,0xc7,0x8e,0x17,0x22,0x5c,0xbf,0xcc,0xa5,0x8c,
0x5e,0x66,0x73,0xc4,0x9d,0x2e,0x1e,0x4d,0xb0,0xc9,0x9c,0x8c,0x65,0x69,0x71,
0xb9,0xad,0x28,0x1a,0x4e,0xb4,0xd2,0xa2,0x91,0x6a,0x67,0x6c,0xa3,0xbb,0x34,
0x14,0x51,0xa4,0xd7,0xa5,0x8f,0x6a,0x6d,0x68,0x98,0xbe,0x53,0x1f,0x48,0x93,
0xcb,0xa4,0x95,0x7a,0x67,0x67,0x93,0xc9,0x54,0x1e,0x43,0x89,0xc0,0xa5,0x9c,
0x7f,0x68,0x69,0x8d,0xba,0x4f,0x22,0x53,0x92,0xc4,0xa9,0x98,0x79,0x6b,0x6a,
0x90,0xb6,0x63,0x1d,0x41,0x89,0xcb,0xab,0x98,0x86,0x67,0x60,0x89,0xc8,0x59,
0x0f,0x4d,0x8e,0xc9,0xa4,0x95,0x85,0x70,0x68,0x84,0xbf,0x71,0x25,0x42,0x82,
0xbb,0xa4,0x96,0x8e,0x6f,0x5f,0x73,0xc0,0x82,0x2b,0x33,0x76,0xb9,0xb1,0x94,
0x98,0x79,0x65,0x6b,0xbd,0x9e,0x2f,0x2e,0x5c,0xa6,0xb7,0xa1,0x9c,0x79,0x62,
0x62,0xaa,0xb0,0x2f,0x27,0x67,0x9d,0xb3,0x99,0xa0,0x87,0x74,0x63,0x9e,0xaa,
0x4e,0x2c,0x52,0x95,0xb3,0x98,0x9e,0x88,0x6a,0x60,0x9a,0xb8,0x59,0x29,0x4c,
0x97,0xba,0x95,0x9d,0x8c,0x73,0x64,0x92,0xbc,0x5b,0x2a,0x55,0x93,0xb9,0x9a,
0x9d,0x92,0x73,0x60,0x81,0xc1,0x6f,0x24,0x51,0x8c,0xb7,0x98,0xa1,0x9e,0x6a,
0x68,0x7f,0xb7,0x77,0x32,0x49,0x85,0xb7,0x9f,0x91,0x9b,0x7d,0x71,0x6e,0xc1,
0x9a,0x35,0x36,0x62,0xa3,0xae,0x90,0x9f,0x84,0x63,0x66,0xaf,0xb9,0x4c,0x20,
0x5a,0x9b,0xad,0x95,0xa1,0x92,0x68,0x59,0x8f,0xbf,0x72,0x2a,0x46,0x91,0xac,
0x99,0x9a,0x9c,0x77,0x5f,0x76,0xb6,0x93,0x44,0x37,0x67,0xa1,0xa2,0x90,0xa4,
0x82,0x65,0x6a,0xa4,0xab,0x4c,0x32,0x5b,0x95,0xa4,0x92,0xa2,0x89,0x6a,0x66,
0x91,0xb4,0x71,0x35,0x4d,0x8d,0xa8,0x99,0x9a,0x99,0x73,0x5f,0x7d,0xb4,0x93,
0x3f,0x3d,0x77,0xa1,0x9e,0x96,0xa2,0x82,0x64,0x6d,0x9f,0x9f,0x5a,0x3d,0x5f,
0x8e,0x9d,0x93,0x9d,0x8c,0x6f,0x65,0x8c,0xb1,0x7a,0x47,0x4b,0x81,0x9b,0x96,
0x98,0x9a,0x78,0x67,0x79,0xa6,0x8f,0x5d,0x49,0x6c,0x96,0x97,0x91,0x9b,0x86,
0x68,0x6e,0x97,0x99,0x6d,0x50,0x5c,0x8b,0x95,0x94,0x97,0x8e,0x77,0x70,0x86,
0x96,0x70,0x55,0x5c,0x87,0x9c,0x94,0x94,0x8f,0x7a,0x75,0x8a,0x96,0x6f,0x54,
0x5c,0x84,0x98,0x93,0x94,0x8c,0x7b,0x74,0x8e,0x8f,0x63,0x52,0x63,0x8f,0x98,
0x8f,0x94,0x8a,0x7a,0x77,0x91,0x84,0x5d,0x56,0x6c,0x95,0x94,0x94,0x93,0x86,
0x7b,0x7c,0x8b,0x6b,0x50,0x61,0x88,0x9b,0x92,0x90,0x8c,0x7c,0x7a,0x8c,0x88,
0x5f,0x54,0x6b,0x92,0x99,0x96,0x91,0x83,0x76,0x7f,0x88,0x6d,0x5f,0x67,0x84,
0x96,0x90,0x95,0x8b,0x83,0x85,0x83,0x68,0x52,0x65,0x8b,0x98,0x96,0x98,0x87,
0x7f,0x83,0x80,0x65,0x50,0x6f,0x91,0x98,0x96,0x93,0x87,0x83,0x88,0x7b,0x52,
0x4e,0x78,0x8f,0x9c,0x9a,0x8f,0x85,0x83,0x87,0x70,0x4c,0x5a,0x86,0x99,0x9d,
0x97,0x8a,0x80,0x85,0x80,0x65,0x51,0x69,0x8b,0x95,0x9d,0x93,0x87,0x85,0x82,
0x72,0x57,0x58,0x7a,0x94,0x98,0x9a,0x8c,0x84,0x8b,0x80,0x67,0x4f,0x60,0x89,
0x94,0x9e,0x98,0x87,0x89,0x85,0x70,0x54,0x54,0x7d,0x93,0x99,0x9c,0x8c,0x86,
0x88,0x7c,0x63,0x4e,0x6d,0x8c,0x92,0x9f,0x94,0x8c,0x8a,0x7f,0x67,0x51,0x63,
0x87,0x92,0x9d,0x98,0x84,0x8a,0x89,0x6e,0x56,0x59,0x81,0x90,0x96,0x99,0x88,
0x8a,0x8b,0x70,0x59,0x55,0x7c,0x8f,0x93,0x9f,0x8f,0x8a,0x86,0x72,0x59,0x53,
0x7e,0x90,0x96,0x9a,0x8a,0x8c,0x8b,0x72,0x5b,0x51,0x78,0x90,0x94,0x9d,0x8b,
0x8b,0x8a,0x75,0x5a,0x53,0x79,0x93,0x95,0x9e,0x8a,0x89,0x8b,0x72,0x59,0x57,
0x7c,0x93,0x95,0x9a,0x8c,0x89,0x8a,0x71,0x58,0x57,0x82,0x92,0x96,0x9b,0x86,
0x8a,0x85,0x6f,0x55,0x5d,0x82,0x91,0x97,0x98,0x89,0x8b,0x85,0x6f,0x53,0x60,
0x88,0x91,0x98,0x98,0x87,0x89,0x84,0x6a,0x50,0x5f,0x8a,0x94,0x9a,0x95,0x86,
0x89,0x82,0x68,0x53,0x64,0x8b,0x94,0x99,0x96,0x85,0x8a,0x80,0x64,0x50,0x69,
0x8f,0x93,0x9c,0x98,0x86,0x8a,0x78,0x5d,0x53,0x72,0x91,0x97,0x9a,0x8d,0x87,
0x87,0x73,0x58,0x57,0x7a,0x95,0x98,0x9b,0x8a,0x8a,0x87,0x68,0x51,0x5a,0x88,
0x97,0x9a,0x99,0x84,0x8a,0x82,0x62,0x53,0x67,0x91,0x94,0x9e,0x97,0x86,0x8b,
0x7b,0x5e,0x4d,0x73,0x91,0x97,0x9e,0x8e,0x84,0x8b,0x7a,0x59,0x4e,0x7a,0x94,
0x98,0x9e,0x8d,0x84,0x8c,0x77,0x55,0x50,0x7a,0x94,0x98,0x9d,0x8b,0x85,0x86,
0x78,0x52,0x50,0x84,0x91,0x94,0x9e,0x8c,0x83,0x8b,0x78,0x52,0x54,0x82,0x92,
0x97,0x9f,0x8a,0x85,0x86,0x72,0x51,0x59,0x85,0x96,0x99,0x9a,0x87,0x85,0x89,
0x6c,0x4b,0x5c,0x8a,0x98,0x9e,0x9b,0x87,0x88,0x89,0x65,0x48,0x63,0x8d,0x96,
0x9e,0x99,0x87,0x86,0x80,0x62,0x4a,0x6c,0x8e,0x9a,0x9c,0x97,0x83,0x87,0x83,
0x5f,0x4f,0x6d,0x8e,0x98,0x9c,0x91,0x86,0x89,0x7d,0x5a,0x4d,0x72,0x91,0x98,
0x9b,0x91,0x84,0x8c,0x7d,0x53,0x4b,0x7c,0x94,0x99,0x9d,0x8c,0x85,0x89,0x74,
0x4b,0x55,0x7f,0x99,0x99,0x9b,0x88,0x83,0x8c,0x71,0x47,0x5b,0x85,0x9a,0x9d,
0x9b,0x89,0x83,0x8c,0x69,0x46,0x58,0x87,0x9b,0x9a,0x99,0x86,0x81,0x87,0x63,
0x45,0x66,0x8d,0x97,0x98,0x98,0x84,0x87,0x85,0x60,0x4e,0x6a,0x8e,0x9b,0x9d,
0x94,0x86,0x8a,0x7d,0x59,0x4c,0x70,0x92,0x99,0x9d,0x92,0x82,0x89,0x7e,0x56,
0x52,0x73,0x94,0x98,0x9a,0x92,0x84,0x8c,0x78,0x54,0x4f,0x79,0x94,0x98,0x9d,
0x8e,0x84,0x8b,0x75,0x4c,0x51,0x79,0x9a,0x9e,0x9c,0x8a,0x86,0x85,0x6e,0x4c,
0x59,0x84,0x98,0x9e,0x97,0x89,0x8c,0x85,0x67,0x48,0x5d,0x8b,0x98,0x9f,0x9a,
0x87,0x8a,0x81,0x5c,0x48,0x65,0x8e,0x9c,0xa2,0x96,0x85,0x8b,0x7e,0x5c,0x45,
0x6e,0x94,0x98,0xa2,0x8f,0x84,0x8d,0x7c,0x5a,0x4b,0x73,0x94,0x9c,0x9e,0x8d,
0x86,0x88,0x78,0x52,0x4e,0x74,0x93,0x9e,0xa0,0x8d,0x86,0x88,0x74,0x52,0x4d,
0x7a,0x99,0x99,0x9f,0x8d,0x8a,0x87,0x6f,0x4f,0x50,0x81,0x97,0xa1,0x9a,0x87,
0x8b,0x84,0x6d,0x4e,0x56,0x82,0x95,0xa0,0x98,0x87,0x8a,0x84,0x68,0x48,0x59,
0x89,0x98,0xa0,0x99,0x88,0x8b,0x7e,0x63,0x48,0x61,0x8e,0x9d,0xa2,0x94,0x87,
0x8b,0x7d,0x5c,0x44,0x6a,0x92,0x9b,0xa1,0x90,0x86,0x8a,0x7c,0x5d,0x49,0x6d,
0x92,0x9c,0xa0,0x91,0x89,0x8a,0x77,0x57,0x4a,0x73,0x93,0x9e,0xa3,0x8f,0x87,
0x84,0x76,0x56,0x48,0x75,0x95,0xa0,0x9d,0x8c,0x8a,0x89,0x75,0x4d,0x4d,0x78,
0x97,0xa1,0x9e,0x8c,0x88,0x86,0x70,0x4e,0x4e,0x7f,0x97,0xa1,0xa2,0x8c,0x88,
0x83,0x6b,0x49,0x58,0x83,0x99,0xa2,0x9c,0x8a,0x88,0x85,0x67,0x42,0x59,0x85,
0x9c,0xa4,0x98,0x8c,0x8a,0x7b,0x5c,0x40,0x63,0x91,0xa0,0xa5,0x93,0x88,0x89,
0x7c,0x58,0x44,0x6b,0x94,0xa2,0xa2,0x91,0x89,0x88,0x76,0x51,0x4a,0x76,0x9a,
0xa6,0xa0,0x8f,0x88,0x88,0x6e,0x45,0x4c,0x7d,0x9d,0xa3,0x9f,0x8c,0x88,0x86,
0x64,0x44,0x56,0x8b,0xa2,0xa2,0x9a,0x8a,0x89,0x82,0x58,0x40,0x61,0x93,0xa4,
0xa3,0x96,0x89,0x8b,0x78,0x49,0x47,0x76,0x9a,0xa4,0xa1,0x90,0x88,0x8a,0x6d,
0x45,0x4d,0x7c,0xa0,0xa5,0x9b,0x8a,0x8a,0x85,0x5a,0x41,0x5c,0x8f,0xa3,0xa4,
0x99,0x88,0x8d,0x7c,0x4f,0x40,0x6c,0x9a,0xa4,0xa2,0x92,0x86,0x8a,0x6b,0x44,
0x4c,0x7d,0xa2,0xa6,0x9e,0x8b,0x85,0x88,0x60,0x41,0x59,0x8b,0xa4,0xa1,0x9b,
0x83,0x8b,0x7d,0x54,0x42,0x68,0x99,0xa4,0xa5,0x93,0x85,0x8e,0x6e,0x48,0x48,
0x79,0xa4,0xa5,0xa3,0x8f,0x8b,0x87,0x54,0x3d,0x56,0x92,0xaa,0xa5,0x9b,0x84,
0x89,0x79,0x47,0x40,0x6f,0x9d,0xa6,0xa2,0x92,0x85,0x8e,0x67,0x39,0x4a,0x85,
0xa5,0xa2,0xa1,0x8b,0x87,0x88,0x56,0x3d,0x5a,0x93,0xa6,0xa3,0x9b,0x86,0x8f,
0x74,0x47,0x46,0x71,0xa3,0xa7,0xa4,0x8f,0x87,0x8f,0x60,0x3b,0x53,0x8a,0xa4,
0xa6,0x9f,0x87,0x8b,0x78,0x3d,0x3c,0x71,0xa2,0xa6,0xa2,0x93,0x85,0x8e,0x61,
0x38,0x4e,0x88,0xa6,0xa4,0xa0,0x8b,0x8c,0x7d,0x44,0x3f,0x6c,0xa2,0xa4,0xa1,
0x9a,0x87,0x8f,0x64,0x3e,0x54,0x88,0xa6,0xa2,0x9f,0x8c,0x8e,0x7a,0x40,0x40,
0x72,0xa6,0xa4,0x9c,0x92,0x84,0x97,0x65,0x35,0x55,0x86,0xa7,0xa1,0x9c,0x8c,
0x8e,0x7f,0x3d,0x34,0x69,0xa8,0xab,0xa1,0x95,0x83,0x91,0x60,0x2f,0x54,0x8d,
0xaa,0xa1,0x9d,0x8c,0x8c,0x7d,0x3d,0x42,0x76,0xa5,0xa8,0x9b,0x98,0x87,0x95,
0x59,0x2d,0x5a,0x8c,0xaf,0x9d,0xa0,0x8d,0x8d,0x88,0x31,0x3e,0x7b,0xa0,0xaa,
0x9c,0x97,0x82,0x96,0x5c,0x29,0x5c,0x91,0xac,0x9e,0x9f,0x8a,0x91,0x7b,0x35,
0x44,0x7a,0xa6,0xa7,0x9c,0x95,0x88,0x8f,0x46,0x32,0x68,0x9f,0xaf,0x9d,0x98,
0x86,0x96,0x71,0x2b,0x4f,0x8a,0xa8,0xa5,0x9b,0x8c,0x8c,0x84,0x3a,0x3d,0x78,
0xa0,0xa8,0x9b,0x95,0x8a,0x92,0x59,0x2b,0x61,0x94,0xae,0xa4,0x97,0x89,0x94,
0x6b,0x34,0x49,0x86,0xb4,0x9f,0x9e,0x8b,0x89,0x80,0x41,0x3a,0x70,0xa6,0xae,
0xa3,0x8d,0x85,0x95,0x4d,0x2d,0x71,0x94,0xae,0xa5,0x9a,0x82,0x95,0x74,0x1c,
0x57,0x8a,0xa4,0xa8,0x9d,0x8a,0x8a,0x86,0x2f,0x3f,0x7a,0xab,0xae,0x98,0x94,
0x80,0x93,0x45,0x2d,0x6f,0xa2,0xb8,0x96,0x98,0x83,0x93,0x5e,0x29,0x5d,0x9b,
0xb9,0x92,0xa2,0x8d,0x92,0x7c,0x13,0x4e,0x8d,0xab,0xa4,0x91,0x87,0x88,0x7f,
0x26,0x4c,0x89,0xab,0xa5,0x95,0x8f,0x82,0x94,0x48,0x36,0x7a,0x9c,0xaa,0x99,
0x94,0x8c,0x99,0x60,0x2e,0x6e,0x9b,0xb3,0x9f,0x9b,0x7f,0x97,0x6a,0x10,0x5b,
0x94,0xae,0x9f,0x92,0x86,0x88,0x88,0x20,0x46,0x8a,0xa1,0xa6,0x93,0x95,0x85,
0x9c,0x44,0x39,0x72,0x9b,0xab,0x9c,0x96,0x80,0x9b,0x53,0x23,0x76,0x91,0xaf,
0x98,0x8e,0x79,0x95,0x69,0x17,0x6c,0x8a,0xa3,0x96,0x94,0x8b,0x91,0x7c,0x2e,
0x5e,0x88,0xa3,0xa5,0x94,0x8f,0x87,0x9a,0x41,0x4b,0x87,0x98,0xa9,0x97,0x8f,
0x81,0x9c,0x50,0x2f,0x83,0x93,0xb0,0x95,0x9d,0x7e,0x9e,0x70,0x24,0x74,0x92,
0xab,0x95,0x94,0x84,0x8d,0x81,0x2e,0x60,0x85,0x9f,0x9c,0x93,0x8d,0x89,0x95,
0x39,0x4f,0x85,0x94,0xa4,0x98,0x95,0x81,0x9c,0x54,0x1f,0x75,0x91,0xb0,0x99,
0x8e,0x7a,0x96,0x89,0x22,0x5b,0x89,0x95,0xa0,0x94,0x89,0x7e,0xa2,0x4e,0x31,
0x7b,0x8f,0xa7,0x93,0x8f,0x80,0x96,0x82,0x32,0x63,0x83,0x9b,0x99,0x97,0x94,
0x7f,0x9f,0x50,0x47,0x7c,0x89,0x9f,0x8d,0x97,0x80,0x97,0x81,0x3b,0x56,0x7d,
0xae,0x9f,0x8e,0x8f,0x7d,0x9c,0x63,0x41,0x69,0x7e,0xa0,0x94,0x9a,0x87,0x82,
0xa4,0x54,0x41,0x73,0x85,0xa1,0x94,0x99,0x80,0x81,0x9e,0x5a,0x4c,0x6a,0x80,
0x9a,0x94,0x98,0x83,0x7d,0xa1,0x7d,0x4b,0x57,0x70,0x97,0x9b,0x98,0x8b,0x77,
0x84,0x9e,0x64,0x44,0x64,0x7d,0x9c,0x99,0x9a,0x87,0x7d,0x80,0x9b,0x63,0x51,
0x65,0x75,0xa1,0x98,0x9d,0x84,0x75,0x83,0x8b,0x5a,0x5b,0x6d,0x86,0x99,0x92,
0x98,0x82,0x78,0x85,0x94,0x63,0x59,0x61,0x83,0xa0,0x95,0x96,0x85,0x75,0x82,
0x8c,0x61,0x65,0x65,0x87,0x99,0x90,0x93,0x7b,0x7b,0x83,0x99,0x63,0x5b,0x5d,
0x7b,0x9e,0x90,0x9b,0x7f,0x7a,0x7e,0x94,0x6a,0x5f,0x69,0x74,0x9f,0x92,0xa1,
0x86,0x7d,0x79,0x90,0x81,0x58,0x6c,0x68,0x94,0x94,0x96,0x8a,0x77,0x79,0x86,
0x8e,0x60,0x6a,0x6b,0x8a,0x99,0x91,0x95,0x78,0x77,0x7c,0x95,0x79,0x5e,0x69,
0x73,0x94,0x94,0x94,0x84,0x77,0x77,0x87,0x92,0x66,0x5f,0x69,0x7d,0x98,0x93,
0x8e,0x80,0x77,0x79,0x8a,0x8a,0x70,0x68,0x6e,0x82,0x93,0x95,0x8c,0x7b,0x75,
0x78,0x8a,0x8d,0x74,0x68,0x6b,0x7f,0x91,0x92,0x8b,0x7e,0x74,0x76,0x83,0x93,
0x85,0x73,0x68,0x6d,0x86,0x93,0x94,0x85,0x76,0x71,0x79,0x8e,0x95,0x84,0x6e,
0x67,0x6f,0x88,0x96,0x93,0x83,0x73,0x6f,0x7c,0x8c,0x93,0x82,0x71,0x6b,0x75,
0x87,0x93,0x91,0x82,0x75,0x73,0x7b,0x87,0x8b,0x85,0x7c,0x76,0x75,0x81,0x89,
0x8a,0x82,0x7a,0x75,0x79,0x80,0x87,0x87,0x80,0x7a,0x77,0x7b,0x81,0x86,0x87,
0x80,0x78,0x78,0x80,0x83,0x84,0x83,0x7e,0x7b,0x7e,0x82,0x84,0x84,0x81,0x7e,
0x7b,0x7e,0x80,0x82,0x83,0x81,0x7f,0x7d,0x7d,0x82,0x84,0x85,0x83,0x89,0x72,
0x76,0x81,0x7e,0x86,0x7d,0x80,0x75,0x7e,0x7e,0x84,0x84,0x80,0x81,0x7c,0x7e,
0x7f,0x81,0x82,0x80,0x7f,0x7d,0x7d,0x80,0x81,0x81,0x80,0x81,0x82,0x7c,0x7b,
0x7f,0x7f,0x82,0x83,0x82,0x7f,0x7f,0x81,0x80,0x80,0x7f,0x7e,0x7f,0x81,0x7f,
0x80,0x82,0x80,0x80,0x82,0x81,0x78,0x7d,0x7c,0x80,0x81,0x7e,0x7f,0x7e,0x82,
0x80,0x84,0x85,0x82,0x81,0x7e,0x7a,0x7c,0x81,0x85,0x83,0x82,0x7b,0x77,0x7c,
0x7e,0x82,0x81,0x81,0x7d,0x7e,0x80,0x7d,0x80,0x81,0x80,0x7d,0x80,0x80,0x82,
0x81,0x81,0x80,0x7d,0x7f,0x7f,0x82,0x83,0x81,0x7b,0x7d,0x7d,0x80,0x82,0x80,
0x7f,0x7e,0x80,0x81,0x83,0x80,0x7e,0x7d,0x7d,0x83,0x82,0x82,0x7d,0x7d,0x7f,
0x7f,0x81,0x80,0x7f,0x7e,0x7e,0x7f,0x81,0x7f,0x81,0x7f,0x7e,0x7e,0x80,0x81,
0x81,0x7f,0x7e,0x7e,0x7f,0x81,0x80,0x81,0x80,0x81,0x80,0x80,0x80,0x81,0x7f,
0x7e,0x7e,0x80,0x81,0x80,0x81,0x7f,0x7e,0x7f,0x81,0x80,0x80,0x80,0x80,0x80,
0x80,0x80,0x80,0x80,0x7f,0x7e,0x7f,0x81,0x80,0x80,0x7f,0x7d,0x7f,0x81,0x81,
0x80,0x80,0x80,0x81,0x7f,0x7f,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x7f,
0x7f,0x81,0x80,0x80,0x80,0x80,0x80,0x81,0x7f,0x7d,0x7f,0x81,0x80,0x80,0x80,
0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x7f,0x7d,0x7f,
0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x81,0x7f,0x7f,0x81,0x80,0x80,0x80,
0x7f,0x7e,0x7f,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,
0x80,0x80,0x80,0x80,0x80,0x81,0x7f,0x7f,0x81,0x80,0x80,0x80,0x81,0x7f,0x7f,
0x81,0x80,0x81,0x7f,0x7f,0x81,0x7f,0x81,0x7e,0x80,0x7f,0x7f,0x81,0x80,0x80,
0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x7f,0x7e,0x80,0x80,0x80,0x80,0x7f,0x7d,
0x80,0x80,0x80,0x80,0x81,0x7f,0x7f,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,
0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x7f,0x7f,0x7f,0x7f,0x81,0x7f,0x81,
0x7e,0x80,0x7f,0x7f,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x81,0x7f,
0x7f,0x80,0x80,0x80,0x80,0x7f,0x7f,0x80,0x7f,0x80,0x80,0x81,0x7e,0x7f,0x80,
0x80,0x80,0x80,0x80,0x7e,0x7f,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,
0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x7e,0x7f,0x80,0x80,0x80,0x80,0x80,
0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,
0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x7f,0x7f,0x80,0x7f,0x80,0x80,0x80};

#ifdef	__cplusplus
}
#endif
