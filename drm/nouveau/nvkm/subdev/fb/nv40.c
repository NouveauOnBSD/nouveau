/*
 * Copyright (C) 2010 Francisco Jerez.
 * All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice (including the
 * next paragraph) shall be included in all copies or substantial
 * portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE COPYRIGHT OWNER(S) AND/OR ITS SUPPLIERS BE
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */
#include "nv04.h"
#include "ram.h"

void
nv40_fb_tile_comp(struct nvkm_fb *fb, int i, u32 size, u32 flags,
		  struct nvkm_fb_tile *tile)
{
	u32 tiles = DIV_ROUND_UP(size, 0x80);
	u32 tags  = round_up(tiles / fb->ram->parts, 0x100);
	if ( (flags & 2) &&
	    !nvkm_mm_head(&fb->ram->tags, 0, 1, tags, tags, 1, &tile->tag)) {
		tile->zcomp  = 0x28000000; /* Z24S8_SPLIT_GRAD */
		tile->zcomp |= ((tile->tag->offset           ) >> 8);
		tile->zcomp |= ((tile->tag->offset + tags - 1) >> 8) << 13;
#ifdef __BIG_ENDIAN
		tile->zcomp |= 0x40000000;
#endif
	}
}

static int
nv40_fb_init(struct nvkm_object *object)
{
	struct nvkm_fb *fb = (void *)object;
	struct nvkm_device *device = fb->subdev.device;
	int ret;

	ret = nvkm_fb_init(fb);
	if (ret)
		return ret;

	nvkm_mask(device, 0x10033c, 0x00008000, 0x00000000);
	return 0;
}

struct nvkm_oclass *
nv40_fb_oclass = &(struct nv04_fb_impl) {
	.base.base.handle = NV_SUBDEV(FB, 0x40),
	.base.base.ofuncs = &(struct nvkm_ofuncs) {
		.ctor = nv04_fb_ctor,
		.dtor = _nvkm_fb_dtor,
		.init = nv40_fb_init,
		.fini = _nvkm_fb_fini,
	},
	.base.memtype = nv04_fb_memtype_valid,
	.base.ram_new = nv40_ram_new,
	.tile.regions = 8,
	.tile.init = nv30_fb_tile_init,
	.tile.comp = nv40_fb_tile_comp,
	.tile.fini = nv20_fb_tile_fini,
	.tile.prog = nv20_fb_tile_prog,
}.base.base;
