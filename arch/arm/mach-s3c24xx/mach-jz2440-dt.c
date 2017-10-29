/*
 * Samsung's jz2440 flattened device tree enabled machine
 *
 * Copyright (c) 2012 Heiko Stuebner <heiko@sntech.de>
 *
 * based on mach-exynos/mach-exynos4-dt.c
 *
 * Copyright (c) 2010-2011 Samsung Electronics Co., Ltd.
 *		http://www.samsung.com
 * Copyright (c) 2010-2011 Linaro Ltd.
 *		www.linaro.org
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
*/

#include <linux/clocksource.h>
#include <linux/irqchip.h>
#include <linux/serial_s3c.h>

#include <asm/mach/arch.h>
#include <mach/map.h>

#include <plat/cpu.h>
#include <plat/pm.h>

#include "common.h"

static void __init jz2440_dt_map_io(void)
{
	s3c24xx_init_io(NULL, 0);
}

static void __init jz2440_dt_machine_init(void)
{
	s3c_pm_init();
}

static const char *const jz2440_dt_compat[] __initconst = {
	"samsung,jz2440",
	"samsung,tq2440",
	NULL
};

DT_MACHINE_START(jz2440_DT, "Samsung jz2440 (Flattened Device Tree)")
	/* Maintainer: Heiko Stuebner <heiko@sntech.de> */
	.dt_compat	= jz2440_dt_compat,
	.map_io		= jz2440_dt_map_io,
	.init_irq	= irqchip_init,
	.init_machine	= jz2440_dt_machine_init,
MACHINE_END
