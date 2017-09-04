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


/* dualcoax attempts to find the properties of a coaxial cable with two
concentric dielectrics between the inner and outer conductors, and so
can be used as a useful test for atlc */

#include "config.h"

#ifdef HAVE_STDIO_H
#include <stdio.h>
#endif

#ifdef HAVE_STDLIB_H
#include <stdlib.h>
#endif

#ifdef HAVE_MATH_H
#include <math.h>
#endif

#define MU_0 4*M_PI*1e-7
#define EPSILON_0 8.854187817e-12 /* Data taken from NPL */


int main (int argc, char **argv)
{
  double velocity, velocity_factor, r0, r1, r2, er1, er2, c, l, zo;

  if (argc != 6)
  {
    fprintf(stderr,"Find properties of a coaxial cable with two different concentric dielectrics.\n\n");
    fprintf(stderr,"Usage: dualcoax D1 D2 D3 Er1 Er2\n");
    fprintf(stderr,"dualcoax %s: arguments are:\n",PACKAGE_VERSION);
    fprintf(stderr,"       D1 is the diameter of the inner conductor\n"); 
    fprintf(stderr,"       D2 is the outer diameter of the inner dielectic\n"); 
    fprintf(stderr,"       D3 is the inner diameter of the outer conductor\n"); 
    fprintf(stderr,"       Er1 is the permittivity of the inner dielectric\n"); 
    fprintf(stderr,"       Er2 is the permittivity of the outer dielectric\n"); 
    exit(1);
  }
  r0=atof(argv[1])/2.0;
  r1=atof(argv[2])/2.0;
  r2=atof(argv[3])/2.0;
  er1=atof(argv[4]);
  er2=atof(argv[5]);
  if ( r0 >= r1){
    fprintf(stderr,"Sorry, the diameter of the inner conductor (d0) must be\n");
    fprintf(stderr,"less than the outer diameter of the inner dielectic (d1)\n");
    exit(1);
  }
  if ( r1 >= r2){
    fprintf(stderr,"Sorry, the diameter of the inner dielectric (d1) must be\n");
    fprintf(stderr,"less than the inner diameter of the outer conductor (d2)\n");
    exit(1);
  }
  if (er1 < 1.0 ){
    fprintf(stderr,"Sorry, the permittivity of the inner dielectric Er1 must be >=1");
    exit(1);
  }
  if (er2 < 1.0 ){
    fprintf(stderr,"Sorry, the permittivity of the outer dielectric Er2 must be >=1");
    exit(1);
  }
  c=2*M_PI*er1*er2*EPSILON_0/(er1*log(r2/r1)+er2*log(r1/r0));
  l=MU_0*log(r2/r0)/(2*M_PI);
  zo=sqrt(l/c);
  velocity_factor=(er1*er2*log(r2/r1))/(er1*log(r2/r1)+er2*log(r1/r0));
  velocity=1.0/(velocity_factor*sqrt(MU_0 * EPSILON_0));
  printf("Zo = %8.3f Ohms C= %8.3f pF/m L= %8.3f nH/m v= %g m/s v_f= %8.3f\n", zo,c*1e12,l*1e9, velocity, velocity_factor);
  return(0);

}
