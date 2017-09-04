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

#include "config.h"

#ifdef HAVE_STDIO_H
#include <stdio.h>
#endif

#ifdef HAVE_STDLIB_H
#include <stdlib.h>
#endif

#ifdef HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif

#ifdef HAVE_TIME_H
#include <time.h>
#endif  

#ifdef HAVE_STRING_H
#include <string.h>
#endif  

#ifdef HAVE_UNISTD_H
#include <unistd.h> 
#endif

#include "defs.h"


int main()
{
  struct computer_data data;

  strcpy((char *) data.mhz,"unknown");
  strcpy((char *) data.cpu_type,"unknown");
  strcpy((char *) data.fpu_type,"unknown");
  strcpy((char *) data.max_cpus,"unknown");
  strcpy((char *) data.cpus,"unknown");
  strcpy((char *) data.memory,"unknown");
  strcpy((char *) data.sysname,"unknown");
  strcpy((char *) data.nodename,"unknown");
  strcpy((char *) data.release,"unknown");
  strcpy((char *) data.version,"unknown");
  strcpy((char *) data.machine,"unknown");
  strcpy((char *) data.hw_provider,"unknown");
  strcpy((char *) data.hw_platform,"unknown");
  strcpy((char *) data.L1data,"unknown");
  strcpy((char *) data.L1instruction,"unknown");
  strcpy((char *) data.L2,"unknown");

#ifdef TRY_TO_GET_HARDWARE_INFO 
  try_portable(&data);
  try_aix(&data); 
  try_bsd(&data); 
  try_hpux(&data);
  try_irix(&data);
  try_linux(&data); 
  try_solaris(&data);
  try_tru64(&data); 
  try_unicos(&data); 
#endif
  printf("Hardware provider:    %s\n", data.hw_provider);
  printf("Hardware platform:    %s\n",data.hw_platform);
  printf("Machine:              %s\n",data.machine);
  printf("Sysname:              %s\n",data.sysname);
  printf("Release:              %s\n",data.release);
  printf("Version:              %s\n",data.version);
  printf("Nodename:             %s\n",data.nodename);
  printf("#CPUs supported:      %s\n",data.max_cpus);
  printf("#CPUs online:         %s\n",data.cpus);
  printf("CPU type:             %s\n",data.cpu_type);
  printf("FPU type:             %s\n",data.fpu_type);
  printf("Speed:                %s MHz\n",data.mhz);
  printf("L1 data cache         %s kb\n",data.L1data);
  printf("L1 instruction cache: %s kb\n",data.L1instruction);
  printf("L2 cache:             %s kb\n",data.L2);
  return(0);
}

