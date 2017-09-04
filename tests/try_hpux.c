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
/* Try to get data. This will work only on a HP-UX machine. */

#include "config.h"


#ifdef HAVE_SYS_PARAM_H   /* This looks for header files that should be  */
#ifdef HAVE_SYS_PSTAT_H   /* present on HP-UX. If they are all present */
#ifdef HAVE_STDIO_H       /* it does ***not** necessarily mean it's HP-UX */
#ifdef HAVE_STDLIB_H      /* but it will define some variables that we */
#ifdef HAVE_SYS_TYPES_H   /* later check for, to confirm it's HP-UX */
#ifdef HAVE_STRING_H
#ifdef HAVE_UNISTD_H 
#ifdef HAVE_SYS_UTSNAME_H

#include <sys/param.h>    /* Include the header files */
#include <sys/pstat.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <sys/unistd.h>
#include <sys/utsname.h>

extern long _CPU_REVISION;
extern long _FPU_MODEL;

#endif
#endif
#endif
#endif
#endif  
#endif
#endif
#endif  /* End of including header files likely to be on HP-UX system */

#define BYTES_PER_MB  1048576

#include "defs.h"
int try_hpux(struct computer_data *data)
{

#ifdef HAVE_SYS_PARAM_H 
#ifdef HAVE_SYS_PSTAT_H
#ifdef HAVE_STDIO_H
#ifdef HAVE_STDLIB_H
#ifdef HAVE_SYS_TYPES_H
#ifdef HAVE_STRING_H
#ifdef HAVE_UNISTD_H 
#ifdef HAVE_SYS_UTSNAME_H


#ifdef HAVE_PSTAT_GETDYNAMIC /* Check for some HP-UX specific bits now */
#ifdef HAVE_PSTAT_GETPROCESSOR
#ifdef HAVE_PSTAT

  long max_CPUs=0, CPUs_online=0;
  double clock_speed_in_Hz, ram, scclktick;

  struct pst_dynamic dynamic_hpux;
  struct pst_static  static_hpux;
  struct pst_processor psp;

  /* Obtain the maximum number of CPUs supported on the HP-UX system */

  pstat_getdynamic(&dynamic_hpux,(size_t) sizeof(dynamic_hpux),1,0);
  max_CPUs=(long) dynamic_hpux.psd_max_proc_cnt;
  if(max_CPUs >=1 )
    sprintf(data->max_cpus,"%ld",max_CPUs);

  /* Obtain the number of CPUs online on the HP-UXs system */
  CPUs_online=(long) dynamic_hpux.psd_proc_cnt; ;
  if( CPUs_online >= 1 )
    sprintf(data->cpus,"%ld",CPUs_online);

  /* Obtain the of CPU and FPU on the HP-UX box */
  
  sprintf(data->cpu_type,"%ld",_CPU_REVISION);
  sprintf(data->fpu_type,"%ld",_FPU_MODEL);

  /* Obtain the RAM on the HP-UX system */

  pstat_getstatic(&static_hpux,(size_t) sizeof(static_hpux),1,0);
  ram=(double) static_hpux.physical_memory;
  ram*=(double) static_hpux.page_size;
  ram=ram/(double) BYTES_PER_MB;
  sprintf(data->memory,"%ld",(long) (0.5+ram));


  /* Obtain the processor speed */
  pstat_getprocessor(&psp, sizeof(psp), 1, 0);
  scclktick=(double) sysconf(_SC_CLK_TCK);
  clock_speed_in_Hz = ((double) psp.psp_iticksperclktick) * scclktick;
  if(clock_speed_in_Hz > 1)
    sprintf(data->mhz,"%.1f",clock_speed_in_Hz/1000000);
  return(0);
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
  return(1);
}
