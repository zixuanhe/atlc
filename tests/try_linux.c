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
/* Try to get data. This will work only on a Linux machine. */

#include "config.h"

#ifdef HAVE_STDIO_H         /* it does ***not** necessarily mean it's Linux */
#ifdef HAVE_STDLIB_H        /* but it will define some variables that we      */
#ifdef HAVE_SYS_TYPES_H     /* later check for, to confirm it's Linux       */
#ifdef HAVE_SYS_UTSNAME_H   /* later check for, to confirm it's Linux       */
#ifdef HAVE_UNISTD_H 
#ifdef HAVE_STRING_H
#ifdef HAVE_SYS_SYSINFO_H
#ifdef HAVE_LINUX_IP_H      /* I don't want to include this, but it is proof 
			       that the system is Linux */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/utsname.h>
#include <unistd.h>
#include <string.h>
#include <sys/sysinfo.h>

#ifdef HAVE_ERRNO_H
#include <errno.h>
#endif


#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif  /* End of including header files likely to be on Linux system */

#include "defs.h"
#define BYTES_PER_MB  1048576

int try_linux(struct computer_data *data)
{
#ifdef HAVE_STDIO_H         /* it does ***not** necessarily mean it's Linux */
#ifdef HAVE_STDLIB_H        /* but it will define some variables that we      */
#ifdef HAVE_SYS_TYPES_H     /* later check for, to confirm it's Linux       */
#ifdef HAVE_SYS_UTSNAME_H   /* later check for, to confirm it's Linux       */
#ifdef HAVE_UNISTD_H 
#ifdef HAVE_STRING_H
#ifdef HAVE_SYS_SYSINFO_H
#ifdef HAVE_LINUX_IP_H      /* I don't want to include this, but it is proof 
			       that the system is Linux */

  /* Obtain the maximum number of CPUs supported on the Linux system */

  /* Obtain the number of CPUs online on the Linux system */

#ifdef _SC_NPROCESSORS_CONF
  if( sysconf(_SC_NPROCESSORS_CONF) >= 1)
    sprintf(data->cpus,"%d", sysconf( _SC_NPROCESSORS_CONF));
#endif

  /* Obtain the of CPU and FPU on the Linux box */

  /* Obtain the RAM on the Linux system if possible. Currently this is 
  done in try_portable.c, but is not 100% accurate on Linux */

  /* Obtain operating system informaton */

  /* Obtain the manufacturer - I don't think this will be too possible,
   but it might be, but clearly some boxes are going to be generic. */

  /* Obtain the Platform */

  return(PROBABLY_LINUX);

#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
  return(-1);
}
