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


/* coax finds the properties of a standard coaxial cable - useful as a test for atlc */

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


#ifndef PI
#define PI 3.141592653589793238462643383279502884197169399375105
#endif

extern int my_optind; 
extern char *my_optarg;

int get_options(int argc, char **argv, const char *opts);
void usage_coax();


int main (int argc, char **argv)
{
  double d, D, er, zo, x;
  double offset=0.0;
  int q;


  while((q=get_options(argc,argv,"O:")) != -1)
  switch (q) {
   case 'O':
     offset=atof(my_optarg);
   break;
   case '?':
    usage_coax();
   break;
  }
  if(argc-my_optind != 3)
    usage_coax();
  d=atof(argv[my_optind]);
  D=atof(argv[my_optind+1]);
  er=atof(argv[my_optind+2]);
  if ( d  >=  D){
    fprintf(stderr,"Sorry, the diameter of the inner conductor (d) must be\n");
    fprintf(stderr,"less than the inner diameter of the outer conductor (D)\n");
    exit(1);
  }
  if (er < 1.0 ){
    fprintf(stderr,"Sorry, the permittivity of the dielectric Er must be >=1");
    exit(1);
  }
  if(D/2.0 <= d/2 + offset){
    fprintf(stderr,"The offset between the inner and outer conductors is too large; the\n");
    fprintf(stderr,"inner and outer conductors will touch!!\n");
    exit(1);
  }

  x=(double) (d*d+D*D-4*offset*offset)/(2*D*d);
  zo=(1/(2*PI))*sqrt(MU_0)*log(x+sqrt(x*x-1))/sqrt(EPSILON_0*er);
  printf("Zo = %16f Ohms\n", zo);
  return(0);

}
