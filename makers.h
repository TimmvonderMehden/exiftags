/*
 * Copyright (c) 2001, 2002, Eric M. Johnston <emj@postal.net>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *      This product includes software developed by Eric M. Johnston.
 * 4. Neither the name of the author nor the names of any co-contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * $Id: makers.h,v 1.1 2002/07/01 08:31:18 ejohnst Exp $
 */

/*
 * Maker note module definitions.
 *
 * When adding a new module, include a #define, a property function,
 * and, if applicable, an IFD reading function.  These need to be included
 * in the makers table found in tagdefs.c.
 */


#ifndef _MAKERS_H
#define _MAKERS_H

#include "exifint.h"


/* Maker note function table. */

struct makerfun {
	int val;
	const char *name;
	void (*propfun)();		/* Function to parse properties. */
	struct ifd *(*ifdfun)();	/* Function to read IFD. */
};
extern struct makerfun makers[];


/* Maker note defines. */

#define EXIF_MKR_CANON		0
#define EXIF_MKR_OLYMPUS	1
#define EXIF_MKR_NIKON		2
#define EXIF_MKR_UNKNOWN	-1


/* Maker note functions. */

extern void canon_prop(struct exifprop *prop, struct exiftags *t);
extern void olympus_prop(struct exifprop *prop, struct exiftags *t);
extern struct ifd *olympus_ifd(u_int32_t offset, struct exiftags *t);
extern void nikon_prop(struct exifprop *prop, struct exiftags *t);

#endif
