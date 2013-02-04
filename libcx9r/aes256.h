/* Cryptkeyper is
 *
 *     Copyright (C) 2013 Jonas Hagmar (jonas.hagmar@gmail.com)
 *
 * This file is part of cryptkeyper.
 *
 * Cryptkeyper is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 * Cryptkeyper is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with cryptkeyper. If not, see <http://www.gnu.org/licenses/>.
 */

// This a wrapper for libraries containing AES256 implementations.
// Currently only libgcrypt supported.
#ifndef CX9R_AES256_H
#define CX9R_AES256_H

#include "../config.h"

#define CX9R_AES256_KEY_LENGTH 32
#define CX9R_AES256_BLOCK_LENGTH 16

#ifdef GCRYPT_WITH_AES
#   include <gcrypt.h>
    typedef gcry_cipher_hd_t cx9r_aes256_ecb_ctx;
    typedef gcry_cipher_hd_t cx9r_aes256_cbc_ctx;
#else
#error No libgcrypt support for aes256
#endif

#include <stdint.h>

void cx9r_aes256_ecb_init(cx9r_aes256_ecb_ctx *ctx, uint8_t *key);
void cx9r_aes256_ecb_encrypt(cx9r_aes256_ecb_ctx *ctx, uint8_t *block);
void cx9r_aes256_ecb_close(cx9r_aes256_ecb_ctx *ctx);

void cx9r_aes256_cbc_init(cx9r_aes256_ecb_ctx *ctx, uint8_t *key, uint8_t *iv);
void cx9r_aes256_cbc_decrypt(cx9r_aes256_ecb_ctx *ctx, uint8_t *buffer, size_t length);
void cx9r_aes256_cbc_close(cx9r_aes256_ecb_ctx *ctx);


#endif

