#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
//#define CLRSCR system("clear");
int MAIN();
int CSEstd();
int firstyear();
int FirstyearV(int roll,int otpr);
int CSEVOTING(int roll,int otpr);
int countdigit(int n);
void Record_Voting();
int AG=0,NU=0,RS=0,MKS=0,MR=0,TS=0,CS=0,AKS=0;
                              //*****************************************
                              //* Function for CSE students(FUNCTION 1) *
                              //*****************************************
int CSEstd()
{
	int otp,otpr,next,ch,rollcse,i,n=0,cn=100;
	int arrcse[100];
	printf("\t\tThis election can vote only 100 peoples\n");
	for(i=0;i<cn;i++)
	{
	 if(i==20||i==40||i==60||i==80||i==90||i==95||i==99)
	 {
	  printf("\n\t\tOnly %d votes are left\n",100-i);
	 }
	printf("\t\tEnter the last 4 digits of your AADHAR NUMBER\n");
	scanf("%d",&arrcse[i]);
	n=countdigit(arrcse[i]);
	if(n==4)
	{
	 srand(time(NULL));
	 otp=(rand()%1000)+1000;              //Generates Random Number of Length 4
	 otpr=otp;
	 printf("\t\tYour generated OTP is %d\n",otp);
	 printf("\t\tPress 1 to continue\n");
	 scanf("%d",&ch);
	 if(ch==1)
	 {
	 rollcse=arrcse[i];                   //Storing Aadhar number in a variable
	 CSEVOTING(rollcse,otpr);             //Calling of Function For Voting;
	 }
	 else
	 {
	 printf("You have been disqualified as you have break the rules\n\n");
	 printf("\n\t\tPress 1 to continue for next vote for same year\n");
     printf("\n\t\tPress any other key to continue voting for other year:\n");
	 scanf("%d",&next);	
	 if(next==1)
	 {
	 CSEstd();
	 }
 	 else
	 {
	 MAIN();	
	 }
	 }	 	
	}
	 else
	 {
	 printf("\t\tPlease enter your valid AADHAR NUMBER as instructed above\n");
	 }
	}	
	return 0;
}
                            //****************************************
                            //* Fuction for cse students(FUNCTION 2) *
                            //****************************************
int CSEVOTING(int roll,int otpr)
{
	int rollno=roll;
	int hod,next,ran_num;
	FILE *CSEV;
	printf("\n\t\tPlease input your generated otp\n\n");
	scanf("%d",&ran_num);
	if(ran_num==otpr)        //Comparing generated otp with inputted number for executing further
	{
	printf("\n\n\t\t\t\t\t\t\t\t\tWelcome to HOD election\n");
	printf("\t\tCandidates for HOD position is:\n");
	printf("\n\t\tPress 1 to vote to Mr.Aditya Rajpoot\n\t\tPress 2 to vote to Mr.Rachit Gupta\n\t\tPress 3 to vote to Mr.Abhishek Pandey\nPress 4 for NOTA\n");
	scanf("\n%d",&hod);
if(hod==1)
{
     CSEV=fopen("votingsheet.txt","a+");        //***********************
	 putw(rollno,CSEV);	                        // Use of file handling *  
	 fputs("Mr.Aditya Rajpoot",CSEV);          //***********************
     fclose(CSEV);
     AG=AG+1;
     printf("\t\tYour vote is succesfully registered to Mr.Aditya Rajpoot\n");
	 printf("\n\t\tPress 1 to continue for next vote for same year\n");
     printf("\n\t\tPress any other key to continue voting for other year:\n");
	 scanf("%d",&next);	
	 if(next==1)
	 {
	 CSEstd();
	 }
 	 else
	 {
	 MAIN();	
	 }
}
else if(hod==2)
{
     CSEV=fopen("votingsheet.txt","a+");       //***********************
	 putw(rollno,CSEV);                        // Use of file handling *
	 fputs("Mr.Rachit Gupta",CSEV);            //***********************
	  fclose(CSEV);
	 NU=NU+1;
	 printf("\t\tYour voting is succesfully registered to Mr.Rachit Gupta\n");
	 printf("\t\tPress 1 to continue for next vote for same year\n");
     printf("\n\t\tPress any other key to continue voting for other year:\n");
	 scanf("%d",&next);
	if(next==1)
	{
	CSEstd();
	}
	else
	{
	 MAIN();	
	}	
}
else if(hod==3)
{
     CSEV=fopen("votingsheet.txt","a+");                 //***********************
     putw(rollno,CSEV);                                  // Use of file handling *
     fputs("Mr.Abhishek Pandey",CSEV);                   //***********************
     fclose(CSEV);
      RS=RS+1;
     printf("\t\tYour vote is succesfully registered to Mr.Abhishek Pandey\n");
     printf("\t\tPress 1 to continue for next vote for same year\n");
     printf("\n\t\tPress any other key to continue voting for other year:\n");
     scanf("%d",&next);
	  if(next==1)
	{
	CSEstd();
	}
	else
	{
	 MAIN();	
	}    	
}
else if(hod==4)
{
	printf("\t\tThank you\n\n");
	 printf("\t\tPress 1 to continue for next vote for same year\n");
     printf("\t\tPress any other key to continue voting for other year:\n");
	 scanf("%d",&next);	
	 if(next==1)
	 {
	 CSEstd();
	 }
 	 else
	 {
	 MAIN();	
	 }
}
else
{
    printf("\t\t\tYour are disqualified as you have selected wrong option\n");
    printf("\n\t\tPress 1 to continue for next vote for same year\n");
	printf("\t\tPress any other key to continue voting for other year:\n");
	scanf("%d",&next); 
	if(next==1)
	{
    CSEstd();
	}
	else
	{
	MAIN();	
	}
}
}
else
{
	printf("\n\t\tYou are disqualified as you have inputted wrong otp\n");
	printf("\n\t\tPress 1 to continue for next vote for same year\n");
	printf("\t\tPress any other key to continue voting for other year:\n");
	scanf("%d",&next); 
	if(next==1)
	{
    CSEstd();
	}
	else
	{
	MAIN();	
	}
}
	return 1;
}
                       //*********************************************
                       //*Function for firstyear students(FUNCTION 1)*
                       //*********************************************
int firstyear()
{
	int otp,otpr,ch,i,roll,next;
	int n=0;
	int cn=100;
	int arrd[100];
	printf("\t\tThis election can vote only 100 peoples\n");
	for(i=0;i<cn;i++)
	{
	 if(i==20||i==40||i==60||i==80||i==90||i==95||i==99)
	 {
	  printf("\n\t\tOnly %d votes are left\n",100-i);
	 }
	printf("\t\tEnter last 4 digit of your AADHAR NUMBER\n");
	scanf("%d",&arrd[i]);	                                        
	n=countdigit(arrd[i]);           //Function calling;
	if(n==4)
	{
	srand(time(NULL));           
	otp=(rand()%1000)+1000;         // Generating random Number
	otpr=otp;                       //Storing OTP in variable
	printf("\t\tYour generated OTP is %d\n",otp);
	printf("\t\tPress 1 to continue\n");
	scanf("%d",&ch);
	if(ch==1)
	{
	roll=arrd[i];                  //Storing Aadhar Number in a variable
	FirstyearV(roll,otpr);         //Calling of Function For 1st Year Voting
    }
    else
	 {
	 printf("You have been disqualified as you have break the rules\n\n");
	 printf("\n\t\tPress 1 to continue for next vote for same year\n");
     printf("\t\tPress any other key to continue voting for other year:\n");
	 scanf("%d",&next);	
	 if(next==1)
	 {
	 CSEstd();
	 }
 	 else
	 {
	 MAIN();	
	 }
	 }	 	
    }
    else
    {
   	printf("\t\tPlease enter your valid AADHAR NUMBER as instructed above\n");
	}
    }
	return 0;	
}
                             //**********************************************
                             //*Function for first year students(FUNCTION 2)*
                             //**********************************************
int FirstyearV(int roll,int otpr)
{
	int next,dean,ran_num;
	int n=roll;
	FILE *FY;
	printf("\t\tPlease input your otp\n");
	scanf("%d",&ran_num);
	if(ran_num==otpr)                //comparing generated otp with inputted number for further execution
	{
	printf("\n\n\t\t\t\t\t\t\t\t\tWelcome to DEAN election\n");
	printf("\t\tCandidates for Dean`s position is:\n\n");
	printf("\t\tPress 1 to vote to Mr.Prakhar Tiwari\n\t\tPress 2 to vote to Mr.Vikas Yadav\n\t\tPress 3 to vote to Mr.Prateek Dubey\n\t\tPress 4 to vote to Mr.Anshu Sharma\n\t\tPress 5 to vote to Mr.Anubhav Kumar\nPress 6 for NOTA\n");
	scanf("\n%d",&dean);
if(dean==1)
{
     FY=fopen("votingsheet.txt","a+");                     //***********************
     putw(n,FY);                                           // Use of file handling *
     fputs("Mr.Prakhar Tiwari",FY);                        //***********************    
	 fclose(FY);
	 MKS=MKS+1;	  
     printf("\t\tYour vote is succesfully registered to Mr.Prakhar Tiwari\n");
	 printf("\n\t\tPress 1 to continue for next vote for same year\n");
	 printf("\t\tPress any other key to continue voting for other year:\n");
	 scanf("%d",&next); 
	if(next==1)
	{
	firstyear();
	}
	else
	{
	 MAIN();	
	}
}	
else if(dean==2)
{
   	 FY=fopen("votingsheet.txt","a+");                     //***********************
     putw(n,FY);                                           // Use of file handling *
     fputs("Mr.Vikas Yadav",FY);                           //***********************
	 fclose(FY);
	 MR=MR+1;	
     printf("\t\tYour vote is succesfully registered to Mr.Vikas Yadav\n");
     printf("\n\t\tPress 1 to continue for next vote for same year\n");
     printf("\t\tPress any other key to continue voting for other year:\n");
     scanf("%d",&next); 
    if(next==1)
	{
	firstyear();
	}
	else
	{
	 MAIN();	
	}
}
else if(dean==3)
{
     FY=fopen("votingsheet.txt","a+");                //***********************
     putw(n,FY);                                      // Use of file handling *
     fputs("Mr.Prateek Dubey",FY);                    //***********************
	 fclose(FY);
	 TS=TS+1;	
     printf("\t\tYour vote is succesfully registered Mr.Prateek Dubey\n");
  	 printf("\n\t\tPress 1 to continue for next vote for same year\n");
	 printf("\t\tPress any other key to continue voting for other year:\n");
	 scanf("%d",&next);
	 if(next==1)
	{
	firstyear();
	}
	else
	{
	 MAIN();	
	} 
}
else if(dean==4)
{
     FY=fopen("votingsheet.txt","a+");                //***********************
     putw(n,FY);                                      // Use of file handling *
     fputs("Mr.Anshu Sharma",FY);                      //**********************
	 fclose(FY);
	 CS=CS+1;	
     printf("\t\tYour vote is succesfully registered to Mr.Anshu Sharma\n");
	 printf("\n\t\tPress 1 to continue for next vote for same year\n");
	 printf("\t\tPress any other key to continue voting for other year:\n");
	 scanf("%d",&next);
	 if(next==1)
	{
	firstyear();
	}
	else
	{
	 MAIN();	
	} 
}
else if(dean==5)
{
     FY=fopen("votingsheet.txt","a+");                  //***********************
     putw(n,FY);                                        // Use of file handling *
     fputs("Mr.Anubhav Kumar",FY);                      //***********************
	 fclose(FY);
	 AKS=AKS+1;	
     printf("\t\tYour vote is succesfully registered to Mr.Anubhav Kumar\n");
	 printf("\n\t\tPress 1 to continue for next vote for same year\n");
	 printf("\t\tPress any other key to continue voting for other year:\n");
	  scanf("%d",&next); 
	  if(next==1)
	 {
     firstyear();
	 }
	 else
	 {
	  MAIN();	
	 }
}
else if(dean==6)
{
	printf("\t\tThank you\n\n");
	printf("\t\tPress 1 to continue for next vote for same year\n");
	 printf("\t\tPress any other key to continue voting for other year:\n");
	 scanf("%d",&next); 
	if(next==1)
	{
	firstyear();
	}
	else
	{
	 MAIN();	
	}
}
else
{
	printf("\n\t\tYour vote has been disqualified as you have selected wrong candidate\n");
	printf("\n\t\tPress 1 to continue for next vote for same year\n");
	printf("\t\tPress any other key to continue voting for other year:\n");
	scanf("%d",&next); 
	if(next==1)
	{
    firstyear();
	}
	else
	{
    MAIN();	
	}
}
}
else
{
	printf("\nYour vote has been disqualified as you have inputted wrong otp\n");
	printf("\n\t\tPress 1 to continue for next vote for same year\n");
	printf("\t\tPress any other key to continue voting for other year:\n");
	scanf("%d",&next); 
	if(next==1)
	{
    firstyear();
	}
	else
	{
    MAIN();	
    }	
}
return 1;
}
                            //*******************************************************
                            // Function for counting integers in a list of integers *
                            //*******************************************************
int countdigit(int n)
{
	int c=0;
	while(n!=0)
	{
		n=n/10;
		c=c+1;
	}
	return c;
}
                              //*****************************************************
                              // Function for counting and printing of Final votes  *
                              //*****************************************************
void Record_Voting()
{
	int n,csewin=0,firstwin=0;
	printf("\n\t\t\tThe Record of voting is\n");                //*******************************************************
    printf("\n\t\t\tFOR CSE DEPARTMENT\n");                     // Printing Number of votes goes to the specific person *
	printf("\n\t\tVOTES GOES TO Mr.Aditya Rajpoot is %d",AG);   //*******************************************************
	printf("\n\t\tVOTES GOES TO Mr.Rachit Gupta is %d",NU);
	printf("\n\t\tVOTES GOES TO Mr.Abhishek Pandey is %d",RS);
	printf("\n\n\t\t\tFOR 1st YEAR DEPARTMENT\n");
	printf("\n\t\tVOTES GOES TO Mr.Prakhar Tiwari is %d",MKS);
	printf("\n\t\tVOTES GOES TO Mr.Vikas Yadav is %d",MR);
	printf("\n\t\tVOTES GOES TO Mr.Prateek Dubey is %d",TS);
	printf("\n\t\tVOTES GOES TO Mr.Anshu Sharma is %d",CS);
	printf("\n\t\tVOTES GOES TO Mr.Anubhav Kumar is %d\n\n",AKS);
	
	printf("\n\t\tWinner from the CSE Department is ");
	if(AG>NU && AG>RS)
	{
	 printf("Mr.Aditya Rajpoot with %d votes\n",AG);
	}
	else if(NU>AG && NU>RS)
	{
		printf("Mr.Rachit Gupta with %d votes\n",NU);
	}
	else if(RS>AG && RS>NU)
	{
		printf("Mr.Abhishek Pandey with %d votes\n",RS);
	}
	else
	{
		printf("None");
	}
	printf("\t\tWinner from the 1st year department is ");
	if(MKS>MR && MKS>TS && MKS>CS && MKS>AKS)
	{
		printf("Mr.Prakhar Tiwari with %d votes\n",MKS);
	}
	else if(MR>MKS && MR>TS && MR>CS && MR>AKS)
	{
		printf("Mr.Vikas Yadav with %d votes\n",MR);
	}
	else if(TS>MKS && TS>MR && TS>CS && TS>AKS)
	{
		printf("Mr.Prateek Dubey with %d votes\n",TS);
	}
	else if(CS>MKS && CS>MR && CS>TS && CS>AKS)
	{
		printf("Mr.Anshu Sharma with %d votes\n",CS);
	}
	else if(AKS>MKS && AKS>MR && AKS>TS && AKS>CS)
	{
		printf("Mr.Anubhav Kumar with %d votes\n",AKS);
	}
	else
	{
		printf("None");
	}
	printf("\n\t\t\tPress 1 to go to main\n");
	scanf("%d",&n);
	while(1)
	{
	if(n==1)
	{
		MAIN();
	}
	else
	{
		printf("\n\t\tInput valid number\n");
	}
    }
}
                              //***********************************************************************
                              // Initial Function of Program used to switch the year                  *
						      // Find the final record of voting and also exit from Program if want`s *
						      //***********************************************************************
int MAIN()
{
	int n,year;
	while(1)
	{
	printf("\t\tPress 1 for 1st Year student\n");
    printf("\t\tPress 2 for CSE students other then 1st Year\n");
    printf("\t\tPress 3 to find Record of Voting\n\n");
    printf("\t\tPress 4 to exit from PROJECT\n");
    printf("\t\tEnter your Choice\n");
    scanf("%d",&year);
    switch(year)
    {
    	case 1:
   		{
    	  firstyear();
		  break;		
		}
		case 2:
		{
		 CSEstd();
		  break;
		}
		case 3:
		{
		Record_Voting();
		break;
		}
		case 4:
		{
		exit(0);
		}
		default:
		{
		printf("\nPlease input valid number\n\n");
		break;
	   }
	}
    }
    
}
                                    //***********************************************
                                    // Main Function of program(PREDEFINED FUNCTION *
                                    //***********************************************
int main()
{
	    system("color 0b");
		printf("\n\n\t\t\t\t\t\t\t\t\tWelcome to IMSEC Election Voting\n\n");
		MAIN();
		return 1;
}
