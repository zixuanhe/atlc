#include <stdio.h> /* ATLC - Arbitrary Transmission Line Calculator. ver 1.0 */
#include <math.h>        /* By D. Kirkby G8WRB.  Compiles okay with          */
#include <stdlib.h>      /* Microsoft  Quick C, version 2.0 and GNU C.       */
#define Imax 126         /* Voltage array size will be 0..Imax               */
#define Jmax 126         /* ie v[0..Imax][[0..Jmax]                          */
float v[Imax+1][Jmax+1]; /* Declare an array to hold the voltages            */
void arbitrary_transmission_line(int W, int H, int w, int h, int t);

void main(int argc, char **argv) /* Read parameters from command line here   */
{
         int W, H, w, h, t; /* integers for number of grid squares to use. */
         if((argc!=6) ) /* Check the number of command line arguments are correct */
         {
                   printf("Usage: %s W(shield) H(shield) width height thickness\n", argv[0]);
                   exit(1); /* Exit - program called with wrong number of arguments */
         }
         W=atoi(argv[1]); /* Read shield width (in grid points) from command line.    */
         H=atoi(argv[2]); /* Read shield height (in grid points) from command line.   */
         w=atoi(argv[3]); /* Read strip width (in grid points) from command line.     */
         h=atoi(argv[4]); /* Read strip height (in grid points) from command line.    */
         t=atoi(argv[5]); /* Read strip thickness (in grid points) from command line. */
         if((W>Imax)||(H>Jmax)||(h+t>H-1)||(w>W-2)||(h<0)||(t<0)||(W<0)||(H<0)) /* Basic checks */
         {
                    printf("Sorry - one of the arguments is silly - too big, too small ?\n");
                    exit(2);
         }
         arbitrary_transmission_line(W,H,w,h,t); /* Calculate L, C and Zo     */
}

void arbitrary_transmission_line(int W, int H, int w, int h, int t)
{
         double Eo=8.854e-12, Er=1.0, mu=12.57e-7, c, l, Zo, vnew,r=1.5, c_old;
         int i, j, k=0, done=0; 
         for(i=0;i<=W;i=i+1)    /* Zero the voltage array. Its essential that the  */
                   for(j=0;j<=H;j=j+1) /* outer is at 0V, but desirable for everywhere to */
                            v[i][j]=0.0;     /* start at 0 V. */
         for(i=(W-w)/2;i<=(W-w)/2+w;i=i+1) /* Put stripline in centre of x axis, */
                   for(j=h;j<=h+t;j=j+1)          /* and between h and h+t on the y axis,*/
                            v[i][j]=1.0;                /* then set stripline there to 1 V */
         do{ /* Set up a relaxation loop, to find the voltage at every point */
                   k=k+1; /* increment the counter used to count the iterations */   
                   for(i=1;i<=W-1;i=i+1) /* Data at i=0 must stay fixed at v=0 */
                            for(j=1;j<=H-1;j=j+1) /* as this is a 'boundary condition' */
                                      if(v[i][j]!=1.0) /*ie. don't do this where the stripline is */
                                      {
                                         vnew=r*(v[i+1][j]+v[i-1][j]+v[i][j+1]+v[i][j-1])/4+(1-r)*v[i][j];
                                               v[i][j]=vnew; /* New voltage is calculated */
                                      }
                   if(k%10==0) /* Now we have v distribution we find C every 10 iterations */
                   {
                            c_old=c; c=0.0; 
                            for(i=0;i<=W-1;i=i+1) /* Sum v over cross-section to get C, which  */
                                  for(j=0;j<=H-1;j=j+1) /* is easy for a rectangular cross section */
                                       c=c+pow(v[i][j]-v[i+1][j+1],2.0)+pow(v[i+1][j]-v[i][j+1],2.0);
                            c=c*Eo/2.0; /* Find capacitance - only correct if air-spaced */
                            l=mu*Eo/c;  /* Calculate the line inductance - always correct */
                            c=c*Er;          /* Correct the capacitance if line has a dielectric */
                            Zo=sqrt(l/c);    /* Calculate the characteristic impedance */
                            printf("%5d c=%.2lfpF/m l=%.2lfnH/m Zo=%lf Ohms\n",k,c*1e12,l*1e9,Zo);
                            if(fabs(c_old-c)/c < 0.00001) /* Until they differ by < 0.001 % */
                                      done=1;  /* Little change in calculated value of C - so we finish*/
                            else
                                      done=0; /* Large change in calculated value of C - lets continue */
                   }
         }while(done==0); /* Repeat for until the capacitance has converged */
} /* End line of program - line 66 */
