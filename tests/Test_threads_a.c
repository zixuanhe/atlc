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

#ifdef HAVE_STDIO_H
#include <stdlib.h>
#endif

#ifdef ENABLE_POSIX_THREADS
#include <pthread.h>

void *increment_a(void *arg);
void *increment_b(void *arg);
int  finalise(int, int);

int r1 = 0, r2 = 0, r3 = 0;

pthread_mutex_t r3_mutex;

#endif /* ifdef ENABLE_POSIX_THREADS */

int main()
{
#ifdef ENABLE_POSIX_THREADS
  pthread_t       thread1, thread2;
  int counter=0, i;

  pthread_mutex_init(&r3_mutex, NULL);

  r3 = 4;

  for(i=1; i<10000; ++i)
  {
     if( pthread_create(&thread1, NULL, increment_a, (void *) &r1) != 0)
     {
        perror("Thread 1 not created properly");
        exit(1);
      }

     if( pthread_create(&thread2, NULL, increment_b, (void *) &r2) != 0)
     {
        perror("Thread 2 not created properly");
        exit(1);
      }
  
     if(pthread_join(thread1, NULL) != 0)
     {
       perror("Thread 1 did not join properly");
       exit (1);
     }
     if(pthread_join(thread2, NULL) != 0)
     {
       perror("Thread 2 did not join properly");
       exit (1);
     }

     counter+=finalise(r1, r2);
   }
   if (counter == 399960000)
     return 0;
   else
     return 1;
#else
     return 77;
#endif
}

#ifdef ENABLE_POSIX_THREADS
void *increment_a(void *arg)
{
  int  i,x;
  int *pnum_times=(int *) arg;
 
  if( pthread_mutex_lock(&r3_mutex) != 0)
  {
    perror("pthread_mutex_lock failed");
    exit(1);
  }
  if (r3 > 3) {
	x = r3;
        r3--;
  } else {
        x = 1;
  }
  if( pthread_mutex_unlock(&r3_mutex) != 0)
  {
    perror("pthread_mutex_unlock failed");
    exit(1);
  }
  for (i = 0;  i < 4; i++) {
    (*pnum_times)++;
  }
  return (NULL);
}

void *increment_b(void *arg)
{
  int i,x;
  int *pnum_times=(int *) arg;

  if( pthread_mutex_lock(&r3_mutex) != 0)
  {
    perror("pthread_mutex_lock failed");
    exit(1);
  }
  if (r3 > 3) {
        x = r3;
        r3--; 
  } else {
        x = 1;
  }
  if(pthread_mutex_unlock(&r3_mutex) != 0)
  {
    perror("pthread_mutex_unlock failed");
    exit(1);
  }
  for (i = 0;  i < 4; i++) {
    (*pnum_times)++;
  }
  return (NULL);
}

int  finalise(int one_times, int another_times)
{
  int total;

  total = one_times + another_times;
  return(total);
}
#endif
