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

int main (int argc, char **argv)
{
  FILE *fp1, *fp2;
  unsigned char *mem1, *mem2;
  long length1, length2, i;

  if (argc != 3)
  {
    fprintf(stderr,"Usage file1 file2 - finds the difference between them\n");
    exit(1);
  }
  if( (fp1=fopen(argv[1],"rb")) == NULL)
  {
    fprintf(stderr,"Unable to open %s\n", argv[1]);
    exit(1);
  }
  if( (fp2=fopen(argv[2],"rb")) == NULL)
  {
    fprintf(stderr,"Unable to open %s\n", argv[2]);
    exit(1);
  }
  if( fseek(fp1,0,SEEK_END) == -1) 
  {
    fprintf(stderr,"fseek failure on fp1 in locatediff.c\n");
    exit(1);
  }
  if( fseek(fp2,0,SEEK_END) == -1) 
  {
    fprintf(stderr,"fseek failure on fp2 in locatediff.c\n");
    exit(1);
  }
  if ((length1=ftell(fp1)) == -1)
  {
    fprintf(stderr,"Unable to determine file pointer position with ftelll on fp1\n");
    exit(1);
  }
  if ((length2=ftell(fp2)) == -1)
  {
    fprintf(stderr,"Unable to determine file pointer position with ftelll on fp2\n");
    exit(1);
  }
  if(length1 != length2)
  {
    fprintf(stderr,"file1 and file2 are not of the same length\n");
    exit(2);
  }
  mem1=(unsigned char *) malloc((size_t)length1);
  if(mem1 == NULL)
  {
    fprintf(stderr,"Failed to allocate memory in locatediff #mem1\n");
    exit(1);
  }
  mem2=(unsigned char *) malloc((size_t)length2);
  if(mem2 == NULL)
  {
    fprintf(stderr,"Failed to allocate memory in locatediff #mem2\n");
    exit(1);
  }
  fseek(fp1,0,SEEK_SET);
  fseek(fp2,0,SEEK_SET);
  fread((void *) mem1,1,(size_t)length1, fp1);
  fread((void *) mem2,1,(size_t)length2, fp2);
  for(i=0; i<length1; ++i)
  {
    if(mem1[i] != mem2[i])
      printf("At offset= %ld file1 = %d file2 = %d difference=%d\n",i,(int) mem1[i],(int) mem2[i],(int) (mem1[i]-mem2[i]));
  }
  fclose(fp1);
  fclose(fp2);
  return(0);
}
