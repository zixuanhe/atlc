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

/* This test program starts by puttting 10 into a 100x1000 array
then incrments it by 5 and decrements it by 2, one thousand 
times. The incrment and decrement operations are prevented from
operlapping by a mutex variable. */

/* If we #define DISABLE_MUTEX, there is no locking
on the array and so any thread can overwrite at any time
so we would expect jibberish output */

#include "config.h"

#ifdef HAVE_STDIO_H
#include <stdio.h>
#endif

#ifdef HAVE_STDIO_H
#include <stdlib.h>
#endif

#ifdef ENABLE_POSIX_THREADS
#include <pthread.h>

void *increment(void *y);
void *decrement(void *z);

int  check_array();

int r1 = 0, r2 = 0;

pthread_mutex_t array_mutex;

int array[1000][1000];

#endif /* ifdef ENABLE_POSIX_THREADS */

int main()
{
#ifdef ENABLE_POSIX_THREADS
  pthread_t       thread1, thread2;
  int i, j, ret;
  /* Put 10 in each array element */
  for(i=0; i<1000; ++i)
    for(j=0; j<1000; ++j)
      array[i][j]=10;

  pthread_mutex_init(&array_mutex, NULL);
#ifdef ENABLE_POSIX_THREADS
#ifdef HAVE_PTHREAD_SETCONCURRENCY     
  pthread_setconcurrency(6);
#endif 
#endif 
  for(i=1; i<=100; ++i)
  {
     if( pthread_create(&thread1, NULL, increment, (void *) &r1) != 0)
     {
        perror("Thread 1 not created properly");
        exit(1);
      }

     if( pthread_create(&thread2, NULL, decrement, (void *) &r2) != 0)
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
   }
   ret=check_array(); /* Returns 0 or 1 */
   return(ret); 
#else
     return 77;
#endif
  exit(0);
}

#ifdef ENABLE_POSIX_THREADS
void *increment(void *pnum_times)
{
  int i, j;
  if( pthread_mutex_lock(&array_mutex) != 0)
  {
    perror("pthread_mutex_lock failed");
    exit(1);
  }
  /* Increment each value in the array by 5, so 
  we can check the values later. */
  for(i=0; i<1000; ++i)
    for(j=0; j<1000; ++j)
      array[i][j]+=5;
  if( pthread_mutex_unlock(&array_mutex) != 0)
  {
    perror("pthread_mutex_unlock failed");
    exit(1);
  }
  return(0);

}

void *decrement(void *pnum_times)
{
  int i,j;


#ifndef DISABLE_MUTEX 
  if( pthread_mutex_lock(&array_mutex) != 0)
  {
    perror("pthread_mutex_lock failed");
    exit(1);
  }
#endif

  /* Decrement each value in the array by 2, so 
  we can check the values later. */
  for(i=0; i<1000; ++i)
    for(j=0; j<1000; ++j)
      array[i][j]-=2;

#ifndef DISABLE_MUTEX 
  if(pthread_mutex_unlock(&array_mutex) != 0)
  {
    perror("pthread_mutex_unlock failed");
    exit(1);
  }
#endif
  return 0;
}

int check_array()
{
  int i,j;
  for(i=0; i<1000; ++i)
  {
    for(j=0; j<1000; ++j)
    {
      /* Numers start at 10, but get incremented by 
      5 by 2, which is 3 . Loop runs 2000 times,
      so resuls should be 2000*(5-2) + 10 = 6010 */

      if (array[i][j] != 310)
      {
	fprintf(stderr,"array[%d][%d]=%d\n",i,j,array[i][j]);
	return(1);
      }
    }
  }
  return(0);
}
#endif
