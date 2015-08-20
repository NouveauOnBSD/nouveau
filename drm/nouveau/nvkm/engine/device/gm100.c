/*
 * Copyright 2012 Red Hat Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE COPYRIGHT HOLDER(S) OR AUTHOR(S) BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * Authors: Ben Skeggs
 */
#include "priv.h"

int
gm100_identify(struct nvkm_device *device)
{
	switch (device->chipset) {
	case 0x117:
		device->oclass[NVDEV_SUBDEV_I2C    ] =  gf110_i2c_oclass;
		device->oclass[NVDEV_SUBDEV_THERM  ] = &gm107_therm_oclass;
		device->oclass[NVDEV_SUBDEV_MXM    ] = &nv50_mxm_oclass;
		device->oclass[NVDEV_SUBDEV_MC     ] =  gk20a_mc_oclass;
		device->oclass[NVDEV_SUBDEV_TIMER  ] = &gk20a_timer_oclass;
		device->oclass[NVDEV_SUBDEV_LTC    ] =  gm107_ltc_oclass;
		device->oclass[NVDEV_SUBDEV_IBUS   ] = &gk104_ibus_oclass;
		device->oclass[NVDEV_SUBDEV_INSTMEM] =  nv50_instmem_oclass;
		device->oclass[NVDEV_SUBDEV_MMU    ] = &gf100_mmu_oclass;
		device->oclass[NVDEV_SUBDEV_PMU    ] =  gk208_pmu_oclass;

#if 0
		device->oclass[NVDEV_SUBDEV_VOLT   ] = &nv40_volt_oclass;
#endif
		device->oclass[NVDEV_ENGINE_DMAOBJ ] =  gf110_dmaeng_oclass;
		device->oclass[NVDEV_ENGINE_FIFO   ] =  gk208_fifo_oclass;
		device->oclass[NVDEV_ENGINE_SW     ] =  gf100_sw_oclass;
		device->oclass[NVDEV_ENGINE_GR     ] =  gm107_gr_oclass;
		device->oclass[NVDEV_ENGINE_DISP   ] =  gm107_disp_oclass;
		device->oclass[NVDEV_ENGINE_CE0    ] = &gk104_ce0_oclass;
#if 0
		device->oclass[NVDEV_ENGINE_CE1    ] = &gk104_ce1_oclass;
#endif
		device->oclass[NVDEV_ENGINE_CE2    ] = &gk104_ce2_oclass;
#if 0
		device->oclass[NVDEV_ENGINE_MSVLD  ] = &gk104_msvld_oclass;
		device->oclass[NVDEV_ENGINE_MSPDEC ] = &gk104_mspdec_oclass;
		device->oclass[NVDEV_ENGINE_MSPPP  ] = &gf100_msppp_oclass;
#endif
		break;
	case 0x124:
		device->oclass[NVDEV_SUBDEV_I2C    ] =  gm204_i2c_oclass;
#if 0
		/* looks to be some non-trivial changes */
		/* priv ring says no to 0x10eb14 writes */
		device->oclass[NVDEV_SUBDEV_THERM  ] = &gm107_therm_oclass;
#endif
		device->oclass[NVDEV_SUBDEV_MXM    ] = &nv50_mxm_oclass;
		device->oclass[NVDEV_SUBDEV_MC     ] =  gk20a_mc_oclass;
		device->oclass[NVDEV_SUBDEV_TIMER  ] = &gk20a_timer_oclass;
		device->oclass[NVDEV_SUBDEV_LTC    ] =  gm107_ltc_oclass;
		device->oclass[NVDEV_SUBDEV_IBUS   ] = &gk104_ibus_oclass;
		device->oclass[NVDEV_SUBDEV_INSTMEM] =  nv50_instmem_oclass;
		device->oclass[NVDEV_SUBDEV_MMU    ] = &gf100_mmu_oclass;
		device->oclass[NVDEV_SUBDEV_PMU    ] =  gk208_pmu_oclass;
#if 0
		device->oclass[NVDEV_SUBDEV_VOLT   ] = &nv40_volt_oclass;
#endif
		device->oclass[NVDEV_ENGINE_DMAOBJ ] =  gf110_dmaeng_oclass;
		device->oclass[NVDEV_ENGINE_FIFO   ] =  gm204_fifo_oclass;
		device->oclass[NVDEV_ENGINE_SW     ] =  gf100_sw_oclass;
		device->oclass[NVDEV_ENGINE_GR     ] =  gm204_gr_oclass;
		device->oclass[NVDEV_ENGINE_DISP   ] =  gm204_disp_oclass;
		device->oclass[NVDEV_ENGINE_CE0    ] = &gm204_ce0_oclass;
		device->oclass[NVDEV_ENGINE_CE1    ] = &gm204_ce1_oclass;
		device->oclass[NVDEV_ENGINE_CE2    ] = &gm204_ce2_oclass;
#if 0
		device->oclass[NVDEV_ENGINE_MSVLD  ] = &gk104_msvld_oclass;
		device->oclass[NVDEV_ENGINE_MSPDEC ] = &gk104_mspdec_oclass;
		device->oclass[NVDEV_ENGINE_MSPPP  ] = &gf100_msppp_oclass;
#endif
		break;
	case 0x126:
		device->oclass[NVDEV_SUBDEV_I2C    ] =  gm204_i2c_oclass;
#if 0
		/* looks to be some non-trivial changes */
		/* priv ring says no to 0x10eb14 writes */
		device->oclass[NVDEV_SUBDEV_THERM  ] = &gm107_therm_oclass;
#endif
		device->oclass[NVDEV_SUBDEV_MXM    ] = &nv50_mxm_oclass;
		device->oclass[NVDEV_SUBDEV_MC     ] =  gk20a_mc_oclass;
		device->oclass[NVDEV_SUBDEV_TIMER  ] = &gk20a_timer_oclass;
		device->oclass[NVDEV_SUBDEV_LTC    ] =  gm107_ltc_oclass;
		device->oclass[NVDEV_SUBDEV_IBUS   ] = &gk104_ibus_oclass;
		device->oclass[NVDEV_SUBDEV_INSTMEM] =  nv50_instmem_oclass;
		device->oclass[NVDEV_SUBDEV_MMU    ] = &gf100_mmu_oclass;
		device->oclass[NVDEV_SUBDEV_PMU    ] =  gk208_pmu_oclass;
#if 0
		device->oclass[NVDEV_SUBDEV_VOLT   ] = &nv40_volt_oclass;
#endif
		device->oclass[NVDEV_ENGINE_DMAOBJ ] =  gf110_dmaeng_oclass;
		device->oclass[NVDEV_ENGINE_FIFO   ] =  gm204_fifo_oclass;
		device->oclass[NVDEV_ENGINE_SW     ] =  gf100_sw_oclass;
		device->oclass[NVDEV_ENGINE_GR     ] =  gm206_gr_oclass;
		device->oclass[NVDEV_ENGINE_DISP   ] =  gm204_disp_oclass;
		device->oclass[NVDEV_ENGINE_CE0    ] = &gm204_ce0_oclass;
		device->oclass[NVDEV_ENGINE_CE1    ] = &gm204_ce1_oclass;
		device->oclass[NVDEV_ENGINE_CE2    ] = &gm204_ce2_oclass;
#if 0
		device->oclass[NVDEV_ENGINE_MSVLD  ] = &gk104_msvld_oclass;
		device->oclass[NVDEV_ENGINE_MSPDEC ] = &gk104_mspdec_oclass;
		device->oclass[NVDEV_ENGINE_MSPPP  ] = &gf100_msppp_oclass;
#endif
		break;
	case 0x12b:

		device->oclass[NVDEV_SUBDEV_MC     ] =  gk20a_mc_oclass;
		device->oclass[NVDEV_SUBDEV_MMU    ] = &gf100_mmu_oclass;
		device->oclass[NVDEV_SUBDEV_TIMER  ] = &gk20a_timer_oclass;
		device->oclass[NVDEV_SUBDEV_LTC    ] =  gm107_ltc_oclass;
		device->oclass[NVDEV_SUBDEV_IBUS   ] = &gk20a_ibus_oclass;
		device->oclass[NVDEV_SUBDEV_INSTMEM] = gk20a_instmem_oclass;
		device->oclass[NVDEV_SUBDEV_MMU    ] = &gf100_mmu_oclass;
		device->oclass[NVDEV_ENGINE_DMAOBJ ] =  gf110_dmaeng_oclass;
		device->oclass[NVDEV_ENGINE_FIFO   ] =  gm20b_fifo_oclass;
		device->oclass[NVDEV_ENGINE_SW     ] =  gf100_sw_oclass;
		device->oclass[NVDEV_ENGINE_GR     ] =  gm20b_gr_oclass;
		device->oclass[NVDEV_ENGINE_CE2    ] = &gm204_ce2_oclass;
		break;
	default:
		return -EINVAL;
	}

	return 0;
}
