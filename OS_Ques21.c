/*
Ques. 21. Consider a scenario of demand paged memory. Page table is held in registers. 
It takes 8 milliseconds to service a page fault if an empty page is available or the 
replaced page is not modified and 20 milliseconds if the replaced page is modified. 
Memory access time is 100 nanoseconds. Assume that the page to be replaced is 
modified 70 percent of the time. Generate a solution to find maximum acceptable 
page-fault rate for access time that is not more than 200 nanosecond.


Sol: We know how to find an effective access time (EAT) for a given page-fault rate (p).
Here, we have to find 'p' for given 'EAT' so we set up the following equation and solve for 'p':
(Note: 1 millisecond = 1,000,000 nanoseconds = 1e6 nanoseconds)

      EAT = (1-p)*(100) + (p)*(100 + (1-.7)*(8msec) + (.7)*(20msec))   
	  = 100 - 100p + 100p + (2.4e6)*p + (14e6)*p
	  = 100 + (16.4e6)*p
      200 = 100 + (16.4e6)*p
      p = 100/16.4e6 = 0.000006
*/

#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<dos.h>
int main()
{
	double pgf_notModi, pgf_Modi, MAT, percentage_Modi, EAT,pgf_Rate;
	printf("\n\n\t\t\t\t<-------- CALCULATION OF PAGE FAULT RATE -------->\n\n");
	printf(" ** Enter the time for Page Fault not modified (in milliseconds) : ");
	scanf("%lf",&pgf_notModi);
	pgf_notModi *=pow(10,-3);      //converting in seconds
	
	printf("\n ** Enter the time for Page Fault modified (in milliseconds) : ");
	scanf("%lf",&pgf_Modi); 
	pgf_Modi *=pow(10,-3);			//converting in seconds
	
	printf("\n ** Enter the time for Memory Access (in nano-seconds) :  ");
	scanf("%lf",&MAT);
	MAT *=pow(10,-9); 				//converting in seconds
	
	printf("\n ** Enter the modified percentage : ");
	scanf("%lf",&percentage_Modi);
	percentage_Modi = percentage_Modi/100;			
	
	printf("\n ** Enter the time for Efficiency Access (in nano-seconds) : ");
	scanf("%lf",&EAT);
	EAT *=pow(10,-9); 				//converting in seconds
	
	printf("\n\t\t\t\t\t\tCalculating ");
	printf("...");
	sleep(1);
	printf("...");
	sleep(1);
	printf("...");
	sleep(1);
	printf("...");
	sleep(1);
	printf("\n\n\n\t\t\t\t <------ PAGE FAULT RATE : ------>  ");
	pgf_Rate = (EAT-MAT)/(percentage_Modi*pgf_Modi + (1-percentage_Modi)*pgf_notModi - MAT);   //formula for calculating Page Fault Rate
	printf("| %lf |",pgf_Rate);
	
	getch();
}
