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
/* Try to get data. This should work on just about any 
system going. However, the amount of data collected 
is not very much, so other C files, that try to 
get more information are about. */

#include "config.h"


#ifdef HAVE_STRING_H
#include <string.h>
#endif  

#ifdef HAVE_STDIO_H
#include <stdio.h>
#endif

#ifdef HAVE_STDLIB_H
#include <stdlib.h>
#endif

#ifdef HAVE_SYS_UTSNAME_H
#include <sys/utsname.h>
#endif

#ifdef HAVE_ERRNO_H
#include <errno.h>
#endif

#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

#include "defs.h"

extern int errno;
#define BYTES_PER_MB  1048576

int try_portable(struct computer_data *data)
{

/* Check for both uname and sysconf. Any UNIX system should 
have both, but since someone has done a Windows port, I  
will start by assming neither sysconf or uname exist */

#ifdef _SC_PHYS_PAGES
#ifdef _SC_PAGESIZE
#ifdef HAVE_SYSCONF  /* Most UNIX systems have it */
  double ram;
#endif
#endif
#endif

#ifdef HAVE_UNAME /* Most if not all UNIX system have it */
  int ret, i, string_length;
  struct utsname operating_system;

  ret=uname(&operating_system);
  if (ret == -1)
  {
#ifdef HAVE_ERRNO_H
    fprintf(stderr,"failure in call to uname in try_portable.c errno=%d\n", errno);
#else
    fprintf(stderr,"failure in call to uname in try_portable.c\n");
#endif /* #ifdef HAVE_ERRNO_H */
    return(ret);
  }
  else  /* the call to uname succeesed */
  {
    /* There is a distint posibility that some data in the operating
    system structure will have spaces in it. This will screw things
    up, since benchmark.test is expect a fixed number of arguments.
    Hence to avoid this, any spaces are replaced by underscores */

    strcpy(data->sysname,operating_system.sysname);
    string_length=strlen(data->sysname);
    for(i=0;i<string_length; ++i)
    {
      if (data->sysname[i] == ' ')
        data->sysname[i]='_';
    }

    /* nodename should be safe, but I'll take no chances */
    strcpy(data->nodename,operating_system.nodename);
    string_length=strlen(data->nodename);
    for(i=0;i<string_length; ++i)
    {
      if (data->nodename[i] == ' ')
        data->nodename[i]='_';
    }

    /* not so with release */
    strcpy(data->release,operating_system.release);
    string_length=strlen(data->release);
    for(i=0;i<string_length; ++i)
    {
      if (data->release[i] == ' ')
        data->release[i]='_';
    }

    /* or version */
    strcpy(data->version,operating_system.version);
    string_length=strlen(data->version);
    for(i=0;i<string_length; ++i)
    {
      if (data->version[i] == ' ')
        data->version[i]='_';
    }

    strcpy(data->machine,operating_system.machine);
    string_length=strlen(data->machine);
    for(i=0;i<string_length; ++i)
    {
      if (data->machine[i] == ' ')
        data->machine[i]='_';
    }
  } /* end of code executed if uname() passed */
#endif /* End of #ifdef HAVE_UNAME */

/* Try to get the number of processors online. This seems to be 
at least semi portable, as its used by both AIX and Solaris.
*/

#ifdef HAVE_SYSCONF  /* many systems seem to have sysconf(), 
which takes an integer argument and returns a long. The 
arugment detemines what gets returned. */

#ifdef _SC_NPROCESSORS_ONLN  /* Get the CPUs online */
    if(sysconf(_SC_NPROCESSORS_ONLN) >= 1)
      sprintf(data->cpus,"%ld",sysconf(_SC_NPROCESSORS_ONLN));
#endif

#endif /* End of #ifdef HAVE_SYSCONF */
  return(0);
}
