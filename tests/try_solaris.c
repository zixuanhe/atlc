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
/* Try to get data. This will work only on a Solaris machine. */

#include "config.h"

#ifdef HAVE_SYS_PARAM_H     /* This looks for header files that should be     */
#ifdef HAVE_SYS_PROCESSOR_H /* present on Solaris. If they are all present    */
#ifdef HAVE_STDIO_H         /* it does ***not** necessarily mean it's Solaris */
#ifdef HAVE_STDLIB_H        /* but it will define some variables that we      */
#ifdef HAVE_SYS_TYPES_H     /* later check for, to confirm it's Solaris       */
#ifdef HAVE_STRING_H
#ifdef HAVE_SYS_UNISTD_H
#ifdef HAVE_UNISTD_H 
#ifdef HAVE_SYS_UTSNAME_H
#ifdef HAVE_SYS_SYSTEMINFO_H

#include <sys/param.h>    /* Include the header files */
#include <sys/processor.h>    /* Include the header files */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <sys/unistd.h>
#include <sys/utsname.h>
#include <sys/systeminfo.h>

#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif  
#endif
#endif  /* End of including header files likely to be on Solaris system */

#include "defs.h"

int try_solaris(struct computer_data *data)

{
#ifdef HAVE_SYS_SYSTEMINFO_H
#ifdef HAVE_SYS_PARAM_H     
#ifdef HAVE_SYS_PROCESSOR_H 
#ifdef HAVE_STDIO_H         
#ifdef HAVE_STDLIB_H       
#ifdef HAVE_SYS_TYPES_H   
#ifdef HAVE_STRING_H
#ifdef HAVE_SYS_UNISTD_H
#ifdef HAVE_UNISTD_H 
#ifdef HAVE_SYS_UTSNAME_H
#ifdef HAVE_SYSCONF

#ifdef _SC_AVPHYS_PAGES   

  int clock_speed_in_MHz;
#ifdef HAVE_PROCESSOR_INFO
  processor_info_t infop;
#endif

#ifdef _SC_NPROCESSORS_MAX
  long max_CPUs=0;

  /* Obtain the maximum number of CPUs supported on the Solaris system */
  max_CPUs=0;
  max_CPUs=(long) sysconf(_SC_NPROCESSORS_MAX);
  if(max_CPUs >=1 )
    sprintf(data->max_cpus,"%ld",max_CPUs);
#endif

#ifdef HAVE_PROCESSOR_INFO
  /* Obtain the of CPU and FPU on the Solaris box */
  if( processor_info((processorid_t) 0, &infop) == 0)
  {
    strcpy(data->cpu_type,infop.pi_processor_type);
    strcpy(data->fpu_type,infop.pi_fputypes);
    clock_speed_in_MHz=(int) infop.pi_clock;
    if(clock_speed_in_MHz > 1)
      sprintf(data->mhz,"%d",clock_speed_in_MHz);
  }
#endif

  /* Obtain the Platform */
#ifdef SI_PLATFORM
  sysinfo(SI_PLATFORM,data->hw_platform,MAX_SIZE);
#endif

  /* Obtain the manufacturer */
#ifdef SI_HW_PROVIDER
  sysinfo(SI_HW_PROVIDER,data->hw_provider,MAX_SIZE);
#endif

  return(PROBABLY_SOLARIS);

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
#else  
  return(-1);
#endif
}
