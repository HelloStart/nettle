/* blowfish.h
 *
 * Blowfish block cipher.
 */

/* nettle, low-level cryptographics library
 *
 * Copyright (C) 1998, 2001 FSF, Ray Dassen, Niels M�ller
 *  
 * The nettle library is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or (at your
 * option) any later version.
 * 
 * The nettle library is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public
 * License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with the nettle library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston,
 * MA 02111-1307, USA.
 */
 
#ifndef NETTLE_BLOWFISH_H_INCLUDED
#define NETTLE_BLOWFISH_H_INCLUDED

#include <inttypes.h>

/* Name mangling */
#define blowfish_set_key nettle_blowfish_set_key
#define blowfish_encrypt nettle_blowfish_encrypt
#define blowfish_decrypt nettle_blowfish_decrypt

#define BLOWFISH_BLOCK_SIZE 8

/* Variable key size between 64 and 448 bits. */
#define BLOWFISH_MIN_KEY_SIZE 8
#define BLOWFISH_MAX_KEY_SIZE 56

/* Default to 128 bits */
#define BLOWFISH_KEY_SIZE 16

#define _BLOWFISH_ROUNDS 16

enum blowfish_error { BLOWFISH_OK, BLOWFISH_WEAK_KEY };

struct blowfish_ctx
{
  uint32_t s[4][256];
  uint32_t p[_BLOWFISH_ROUNDS+2];
  enum blowfish_error status;
};

/* On success, returns 1 and sets ctx->status to BLOWFISH_OK (zero).
 * On error, returns 0 and sets ctx->status to BLOWFISH_WEAK_KEY. */
int
blowfish_set_key(struct blowfish_ctx *ctx,
                 unsigned length, const uint8_t *key);

void
blowfish_encrypt(struct blowfish_ctx *ctx,
                 unsigned length, uint8_t *dst,
                 const uint8_t *src);
void
blowfish_decrypt(struct blowfish_ctx *ctx,
                 unsigned length, uint8_t *dst,
                 const uint8_t *src);

#endif /* NETTLE_BLOWFISH_H_INCLUDED */
