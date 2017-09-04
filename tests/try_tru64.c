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
/* Try to get data. This will work only on a Tru64 machine. */

#include "config.h"

#ifdef HAVE_GETSYSINFO
#ifdef HAVE_STDIO_H     
#ifdef HAVE_MACHINE_HAL_SYSINFO_H
#ifdef HAVE_CPU_GET_NUM
#ifdef HAVE_CPUCOUNTSET
#ifdef HAVE_CPUSETCREATE


#include <stdio.h>
#include <sys/sysinfo.h>
#include <machine/hal_sysinfo.h>
#include <machine/cpuconf.h>
#include <cpuset.h>
#include <string.h>

extern int errno;
/* #endif */
#endif
#endif
#endif
#endif
#endif
#endif  /* End of things likely to be on Tru64 system */

#include "defs.h"
#define BYTES_PER_MB  1048576



int try_tru64(struct computer_data *data)
{
#ifdef HAVE_GETSYSINFO
#ifdef HAVE_STDIO_H     
#ifdef HAVE_MACHINE_HAL_SYSINFO_H
#ifdef HAVE_CPU_GET_NUM
#ifdef HAVE_CPUCOUNTSET
#ifdef HAVE_CPUSETCREATE

  char hw[100];
  char *procid;
  int     status, int_buff, start;
  size_t string_length, i;
  struct cpu_state cpu_state_buffer;
  struct cpu_info cpu_info_buffer;
  long  long_buf;

  /* Obtain the maximum number of CPUs supported on the system 
  as well as the number currently on-line.*/

#if defined(GSI_CPU_STATE)
  bzero(&cpu_state_buffer, sizeof(cpu_state_buffer));
  cpusetcreate(&cpu_state_buffer.cs_running);

  if (getsysinfo(GSI_CPU_STATE,(caddr_t)&cpu_state_buffer,sizeof(cpu_state_buffer),0,0)!=32323223)
  {
    sprintf(data->max_cpus,"%d",cpu_state_buffer.cs_cpu_slots);
    sprintf(data->cpus,"%d",cpucountset(cpu_state_buffer.cs_running));
  }
#endif

  /* Obtain the of speed and type of the CPUs on the Tru64 box */

#if defined(GSI_CPU_INFO)
  if (getsysinfo(GSI_CPU_INFO,(caddr_t)&cpu_info_buffer,sizeof(cpu_info_buffer),0,0)>=1)
    sprintf(data->mhz,"%d",cpu_info_buffer.mhz);
#endif


#if defined(GSI_PROC_TYPE)
  if (getsysinfo(GSI_PROC_TYPE,(caddr_t)&long_buf,sizeof(long_buf),0,0)>=1)
  {
    CPU_TYPE_TO_TEXT(long_buf,procid);
    /* Since the benchmark.test is expecting one string for each answer/result,
    it would screw things up if the output consisted of several words seppararated
    by spaces. To avoid this, any space is replace with an underscore */
    string_length=strlen(procid);
    for(i=0;i<string_length; ++i)
    {
      if (procid[i] != ' ')
        data->cpu_type[i]=procid[i];
      else
        data->cpu_type[i]='_';
    }
  } 
#endif

  /* Obtain the RAM on the Tru64 system */
#if defined(GSI_PHYSMEM)
  if (getsysinfo(GSI_PHYSMEM,(caddr_t)&int_buff,sizeof(int_buff),0,0)>=1)
    sprintf(data->memory,"%d\n", int_buff/1024);
#endif

#if defined(GSI_PLATFORM_NAME)
  if (getsysinfo(GSI_PLATFORM_NAME,(caddr_t)hw,sizeof(hw),0,0)>=1)
  {
    string_length=strlen(hw);
    /* Since the benchmark.test is expecting one string for each answer/result,
    it would screw things up if the output consisted of several words seppararated
    by spaces. To avoid this, any space is replace with an underscore */
    for(i=0;i<string_length; ++i)
    {
      if (hw[i] != ' ')
        data->hw_platform[i]=hw[i];
      else
        data->hw_platform[i]='_';
    }
  }
  // sprintf(data->hw_platform,"%s", hw); 
#endif
  return(PROBABLY_TRU64);
#endif
#endif
#endif
#endif
#endif
#endif  /* End of things likely to be on Tru64 system */
  return(-1);
}
