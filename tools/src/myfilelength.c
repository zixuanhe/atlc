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

Dr. David Kirkby, e-mail drkirkby@gmail.com 

*/

#include "config.h"

#ifdef HAVE_STDIO_H
#include <stdio.h>
#endif

#ifdef HAVE_STDLIB_H
#include <stdlib.h>
#endif

#include "../../src/exit_codes.h"
#include "../../src/definitions.h"

int main(int argc, char **argv)
{
  FILE *fp;
  int length;

  if(argc!=2)
  {
    printf("-1\n"); /* Length is considered -1 */
    exit(1);
  }
  if ( (fp=fopen(argv[1],"rb")) == NULL)
  {
    printf("-1\n"); /* Length is considered -1 */
    exit(1);
  }
  fseek(fp,0,SEEK_END);
  length=ftell(fp);
  printf("%d\n",length);
  return(OKAY); 
}
