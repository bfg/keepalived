/*
 * Soft:        Keepalived is a failover program for the LVS project
 *              <www.linuxvirtualserver.org>. It monitor & manipulate
 *              a loadbalanced server pool using multi-layer checks.
 *
 * Part:        Dynamic data structure definition.
 *
 * Version:     $Id: vrrp_data.h,v 1.0.3 2003/05/11 02:28:03 acassen Exp $
 *
 * Author:      Alexandre Cassen, <acassen@linux-vs.org>
 *
 *              This program is distributed in the hope that it will be useful,
 *              but WITHOUT ANY WARRANTY; without even the implied warranty of
 *              MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *              See the GNU General Public License for more details.
 *
 *              This program is free software; you can redistribute it and/or
 *              modify it under the terms of the GNU General Public License
 *              as published by the Free Software Foundation; either version
 *              2 of the License, or (at your option) any later version.
 */

#ifndef _VRRP_DATA_H
#define _VRRP_DATA_H

/* system includes */
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <syslog.h>
#include <arpa/inet.h>

/* local includes */
#include "list.h"
#include "vector.h"

/* Configuration data root */
typedef struct _vrrp_conf_data {
	list static_routes;
	list vrrp_sync_group;
	list vrrp;
} vrrp_conf_data;

/* prototypes */
extern void alloc_sroute(vector strvec);
extern void alloc_vrrp_sync_group(char *gname);
extern void alloc_vrrp(char *iname);
extern void alloc_vrrp_vip(vector strvec);
extern void alloc_vrrp_evip(vector strvec);
extern void alloc_vrrp_vroute(vector strvec);
extern vrrp_conf_data *alloc_vrrp_data(void);
extern void free_vrrp_data(vrrp_conf_data * data);
extern void dump_vrrp_data(vrrp_conf_data * data);

#endif