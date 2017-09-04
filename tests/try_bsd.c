/*
atlc - arbitrary transmission line calculator, for the analysis of
transmission lines are directional couplers. 

Copyright (C) 2002. Dr. David Kirkby, PhD (G8WRB).

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either package_version 2
of the License, or (at your option) any later package_version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307,
USA.

Dr. David Kirkby, e-mail drkirkby@ntlworld.com 

*/
/* Try to get data. This will work only on a IRIX machine. */

#include "config.h"

#ifdef HAVE_STDIO_H
#ifdef HAVE_STDLIB_H
#ifdef HAVE_SYS_TYPES_H
#ifdef HAVE_SYS_SYSCTL_H
#ifdef HAVE_SYSCTL

#include <stdio.h>
#include <stdlib.h>

/* On BSD 3.2 for SPARC, NGROUPS don't seem to be defined, but
it is on other systems. To be safe, the relavant header files
will only be included if NGROUPS is not defined */

#ifndef NGROUPS

#ifdef HAVE_SYS_PARAM_H
#include <sys/param.h>
#endif

#ifdef HAVE_SYS_SYSLIMITS_H
#include <sys/syslimits.h>
#endif

#endif /* End of ifndef NGROUPS */

#include <sys/types.h>
#include <sys/sysctl.h>

#endif
#endif
#endif
#endif
#endif

#include "defs.h"

int try_bsd(struct computer_data *data)
{
#ifdef HAVE_STDIO_H
#ifdef HAVE_STDLIB_H
#ifdef HAVE_SYS_TYPES_H
#ifdef HAVE_SYS_SYSCTL_H
#ifdef HAVE_SYSCTL
#ifdef CTL_HW 

  int cpus, ram, mib[2], ret;
  size_t len;

  /* Obtain the maximum number of CPUs supported on the BSD system */

  /* Obtain the number of CPUs online on the BSD system */

#ifdef HW_NCPU
  mib[0]=CTL_HW;
  mib[1]=HW_NCPU;
  len=sizeof(cpus);
  ret=sysctl(mib, 2, &cpus, &len, NULL, 0);
  if (cpus>= 1 && ret==0)
    sprintf(data->cpus,"%d ",  cpus);
#endif

  /* Obtain the CPU speed in MHz - as a double */

  /* Obtain the of CPU and FPU on the ???? box */

  /* Obtain the RAM, cache etc on the BSD system. */

#ifdef HW_PHYSMEM
  mib[0]=CTL_HW;
  mib[1]=HW_PHYSMEM;
  ret=sysctl(mib, 2, &ram , &len, NULL, 0);
  if( ram > 0 && ret ==0 )
    sprintf(data->memory,"%d", ram/(1024*1024));
#endif


  /* Obtain the manufacturer */

  /* sprintf(data->hw_provider,"SGI"); */
  return(PROBABLY_BSD);
#endif
#endif
#endif
#endif
#endif
#endif
  return(-1);
}
