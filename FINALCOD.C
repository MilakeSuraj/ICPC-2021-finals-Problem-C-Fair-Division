#include<stdio.h>
void displayOutput(int p,int q,int rounds)
   { printf(" \t\t\t%d %d\n\t\t\tRounds = %d",p,q,rounds);
     printf("\n-----------------------------------------------");
   }
void outputImpossible()
   {     printf("\t\t\tImpossible\n\n-----------------------------------------------");
   }
void calculate(long int n,long long int m)
   {  int p,q,s,round1,rounds,flag=0;
      float f,sum=0;
      for(q=2;q<n;q++)
	{  for(p=q-1;p<q;p++)
	    {  f=(float)p/q;
	       for(s=0,sum=0;s<n;s++)
		   sum+=f;
	       round1=sum;
	       if(sum-round1==0)
		 {   if(m%round1==0)
		      { rounds=m/round1;
			displayOutput(p,q,rounds);
			flag=1;
			break;
		      }
		 }
	       else
		 {  sum*=2;
		    round1=sum;
		    if(sum-round1==0)
		       {  if(m%round1==0)
			   {  rounds=(m/round1)*2;
			      displayOutput(p,q,rounds);
			      flag=1;
			      break;
			   }
		       }
		  }
	   }
	  if(flag==1)
	     break;
	}
      if(flag==0)
	 outputImpossible();
   }
void getInput(long int *n,long long int *m)
   {   long int pirates;
       long long int loot;
       printf("\n Input number of pirates and value of loot ");
       printf("\n-----------------------------------------------\n\n");
       scanf("%ld%lld",&pirates,&loot);
       if((pirates>=6 && pirates<1000000) && (loot>=1 && loot<1000000000000000000))
	   {   *n=pirates;
	       *m=loot;
	   }
       else
	  outputImpossible();
   }
int main()
   {   long int n=0;
       long long int m;
       //clrscr();
       getInput(&n,&m);
       if(n!=0)
	  calculate(n,m);
       //getch();
	   return 0;
   }