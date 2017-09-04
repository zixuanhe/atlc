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

Dr. David Kirkby, e-mail drkirkby at gmail.com 

*/

#include "config.h"

#ifdef HAVE_STDIO_H
#include <stdio.h>
#endif

#ifdef HAVE_STDLIB_H
#include <stdlib.h>
#endif

void usage_coax(){
    fprintf(stderr,"coax version %s. Find properties of a coaxial cable\n\n",PACKAGE_VERSION);

    fprintf(stderr,"Usage: coax [-O offset] d  D Er\n");
    fprintf(stderr,"coax %s: arguments are:\n",PACKAGE_VERSION);
    fprintf(stderr,"       'd'       is the diameter of the inner conductor\n"); 
    fprintf(stderr,"       'D'       is the internal diameter of the outer conductor\n"); 
    fprintf(stderr,"       'Er'      is the permittivity of the dielectric\n"); 
    fprintf(stderr,"       'offset'  (if supplied as an option) is the offset between the\n"); 
    fprintf(stderr,"                 centres of the conductors in an eccentric coaxial structure.\n"); 
    exit(1);
}
