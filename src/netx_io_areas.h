
#ifndef __NETX_IO_AREAS_H__
#define __NETX_IO_AREAS_H__

#define DO_CONCAT(a,b,c) a##_##b##_##c
#define CONCAT(a,b,c) DO_CONCAT(a,b,c)

#if ASIC_TYP==500
#       define HOST NX500
#       define HOSTNAME "netx500"
#       include "netx500/netx500_io_areas.h"
#elif ASIC_TYP==50
#       define HOST NX50
#       define HOSTNAME "netx50"
#       include "netx50/netx50_io_areas.h"
#elif ASIC_TYP==56
#       define HOST NX56
#       define HOSTNAME "netx56"
#       include "netx56/netx56_io_areas.h"
#elif ASIC_TYP==10
#       define HOST NX10
#       define HOSTNAME "netx10"
#       include "netx10/netx10_io_areas.h"
#else
#       error "no host define set!"
#endif

#define HOSTDEF(a)  CONCAT(HOST,DEF,a)
#define HOSTADR(a)  CONCAT(Adr,HOST,a)
#define HOSTADDR(a) CONCAT(Addr,HOST,a)
#define HOSTMSK(a)  CONCAT(MSK,HOST,a)
#define HOSTSRT(a)  CONCAT(SRT,HOST,a)
#define HOSTADEF(a) CONCAT(HOST,a,AREA_T)
#define HOSTDFLT(a) CONCAT(DFLT_VAL,HOST,a)

#endif  /* __NETX_IO_AREAS_H__ */
