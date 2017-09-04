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
/* Times two commands entered on the command line, to make
sure the second takes less time than the first. */

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
#include <unistd.h> /* sleep on Solaris needs this */
#endif

#include "defs.h"


int main(int argc, char **argv)
{
  time_t start1, finished1;
  struct computer_data data;

  char *str;
  FILE *fp;

#ifdef ENABLE_POSIX_THREADS
  time_t start2, finished2;
  strcpy((char *) data.eff,"unknown");
#else
  strcpy((char *) data.eff,"N/A");
#endif /* ENABLE_POSIX_THREADS */

  strcpy((char *) data.mhz,"unknown");
  strcpy((char *) data.cpu_type,"unknown");
  strcpy((char *) data.fpu_type,"unknown");
  strcpy((char *) data.max_cpus,"unknown");
  strcpy((char *) data.cpus,"unknown");
  strcpy((char *) data.sysname,"unknown");
  strcpy((char *) data.nodename,"unknown");
  strcpy((char *) data.release,"unknown");
  strcpy((char *) data.version,"unknown");
  strcpy((char *) data.machine,"unknown");
  strcpy((char *) data.hw_provider,"unknown");
  strcpy((char *) data.hw_platform,"unknown");
  strcpy((char *) data.speedup,"N/A    ");
  strcpy((char *) data.t2,"N/A    ");
  strcpy((char *) data.L1data,"unknown");
  strcpy((char *) data.L1instruction,"unknown");
  strcpy((char *) data.L2,"unknown");

/* Trying to get information about the hardware is likely to break
on some platforms, as it is very platform specific. If the option 
--disble-hardware-info is given, the software will not try to obtain
such information. 

The information is useful, for benchmarking purposes and to 
obtain the efficiency of a multi-processor machine if the number
of CPUs can be found. */

#ifdef TRY_TO_GET_HARDWARE_INFO 
  try_portable(&data);  /* Use uname, which is platform independant */

  try_aix(&data);      /* Try to find if the system is AIX and if so get data */
  try_bsd(&data); 
  try_hpux(&data);
  try_irix(&data);
  try_linux(&data); 
  try_solaris(&data);
  try_tru64(&data); 
  try_unicos(&data); 
#endif


/* Whatever happens (single-threaded or multi-theraded, we will check that all the 
files (the executable atlc and bitmap are both present). */
  if(argc !=3 )
  {
    fprintf(stderr,"Usage: path_to_atlc path_to_bitmap\n");
    exit(1);
  }
  if( (str=malloc(2000)) == NULL) 
  {
    fprintf(stderr,"Memory allocation failure in benchmark.c\n");
    exit(1);
  }
  if ((fp=fopen(argv[1],"rb")) == NULL)
  {
    fprintf(stderr,"Can't open the binary file %s for reading\n",argv[1]);
    exit(2);
  }
  if ((fp=fopen(argv[2],"rb")) == NULL)
  {
    fprintf(stderr,"Can't open the bitmap %s for reading\n",argv[2]);
    exit(3);
  }
/* Assuming we have not exited due to a lack of suitable files present, 
run the benchmark at least once - but possibly twice if code is   
multi-threaded */

  sprintf(str,"%s -s -S -t0 %s > /dev/null 2> /dev/null \n", argv[1], argv[2]);
  time(&start1);
  pclose(popen(str, "w"));
  time(&finished1);
  sprintf(data.t1,"%d",(int) (finished1-start1));

/* If the code is multi-threaded, run the benchmark for a second time. We can
always calculate a speedup in these circumstances */

#ifdef ENABLE_POSIX_THREADS
  sprintf(str,"%s -s -S %s > /dev/null\n", argv[1], argv[2]);
  time(&start2);
  pclose(popen(str, "w"));
  time(&finished2);
  sprintf(data.t2,"%d",(int) (finished2-start2));
  sprintf(data.speedup,"%.3f\n",atof(data.t1)/atof(data.t2)); /* other N/A */

  /* Whether or not we can calculate the efficency depends on whether we have managed
  to obtain the number of processors present in the system. If the number of procesors
  found is zero (i.e. we have been unable to determine them, due to a lack of
  processor_information, or that not working properly, then we can't compute the efficiency,
  so will leave it at the default value of "unknown". */

  if(atoi(data.cpus) != 0)
    sprintf(data.eff,"%.3f",atof(data.speedup)/atoi(data.cpus)); /* otherwise unknown */
#endif
  printf("0 %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s\n",data.t1, data.t2, data.speedup, data.cpus, data.mhz, data.eff, data.cpu_type,data.fpu_type,data.max_cpus,data.sysname,data.nodename,data.release,data.version,data.machine,data.hw_provider, data.hw_platform, data.L1data, data.L1instruction, data.L2);
  return(0);
}


