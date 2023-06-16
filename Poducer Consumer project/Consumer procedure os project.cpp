#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<conio.h>


struct Assignment 
{
	char ChapNumber[256];
	char SubmissionDate[256];
};


struct Quiz
{
		char TopicName[256];
	char DateOfQuiz[256];
};


struct ClassTask 
{
	char TopicName[256];
	char SessionNumber[256];
};


int assign_count=0,quiz_count=0,ClassTask_count=0;

int N_Assignment=5,N_Quiz=2,N_CT=0;

int main()
{
	
	
	int in_Ass=0,in_Quiz=0,in_CT=0;
	int out_Ass=0,out_Quiz=0,out_CT=0;
	
	struct Assignment assign[N_Assignment];
	struct Quiz quiz_[N_Quiz];
	struct ClassTask *classtask;
	classtask  = (struct ClassTask *)malloc(100*sizeof(struct ClassTask));
	int ch1,choice;
	char buffer[512];
	
	
	while(ch1!=3)
	 {
	 	
	//	system("cls");
	    printf("\t \t \t =============================\t \t \t");
		printf("\n \t \t \t PRODUCER AND CONSUMER PROBLEM \t \t \t \n \n");
	    printf("");
	    printf("\t \t \t 1) 12671 Muhammad Anas \n");
	    printf("\t \t \t 2) 12682 Amna Iqbal \n");
	    printf("\t \t \t 3) 13193 Arisha Nasir \n");
	    printf("\t \t \t 3) 13198 Ailshba Amin \n");
	    printf("\t \t \t =============================\t \t \t");
	    printf("\n");
	    printf("\n");
	    
		printf("\t1. Teacher \n\t2. Std \n\t3. EXIT \n \n \tYOUR CHOICE HERE : ");
		scanf("%d",&ch1);
		
		
		if(ch1==1) 
		{
			
			choice=0;
			
			/////////////////////Teacher Start////////////////////
			
			while(choice != 4)
			 {
			//	system("cls");
		    	printf("\n");
				printf("\t\t1. Assignment \n\t\t2. Quiz \n\t\t3. Class Task \n\t\t4. EXIT \n \n \t \t YOUR CHOICE HERE : ");
				scanf("%d",&choice);
				
				switch(choice) 		
				{
					
					
					case 1:
						if( assign_count == N_Assignment)
						 {
						 		printf("\n");
							printf("\nYou cannot Add more Assignments untill pervious one are utilized\n");
							break;
						}
						
						printf("Enter Chap Number :");
						scanf("%s",&buffer);
						strcpy(assign[in_Ass].ChapNumber,buffer);
						printf("Enter submission date :");
						scanf("%s",&buffer);
						strcpy(assign[in_Ass].SubmissionDate,buffer);
						
						in_Ass=(in_Ass+1)%N_Assignment;
						assign_count = assign_count +1;
						break;
						
						
						
					case 2:
						
						if( quiz_count == N_Quiz) 
						{
								printf("\n");
							printf("\nYou cannot give more Quizs untill pervious one are Taken\n");
							break;
						}
						printf("Enter Topic Name :");
						scanf("%s",&buffer);
						strcpy(quiz_[in_Quiz].TopicName,buffer);
						printf("Enter Quiz date :");
						scanf("%s",&buffer);
						strcpy(quiz_[in_Quiz].DateOfQuiz,buffer);
						
						in_Quiz=(in_Quiz+1)%N_Assignment;
						quiz_count = quiz_count +1;
						break;
						
						
						
					case 3:
						
					
						printf("Enter Topic Name :");
						scanf("%s",&buffer);
						strcpy((classtask + in_CT)->TopicName,buffer);
						
						printf("Enter Session number :");
						scanf("%s",&buffer);
						strcpy((classtask + in_CT)->SessionNumber,buffer);
						
						in_CT++;
						ClassTask_count = ClassTask_count +1;
						N_CT++;
						break;
						
						
					case 4:
						
						
						break;
						
						
					default:
						printf("\nSelect valid option\n");
						break;
					}
				}
				
				/////////////////////Teacher End////////////////////
				
				
			}
			else if(ch1==2)
			{
				choice=0;
				system("cls");
				/////////////////////Student Start////////////////////
				
				while(choice != 4) 
				{
				//	system("cls");
					printf("\n");
				printf("\t\t1. Assignment \n\t\t2. Quiz \n\t\t3. Class Task \n\t\t4. EXIT \n\t\tYOUR CHOICE HERE : ");
				scanf("%d",&choice);
				
				switch(choice)
				 {
				 	
					case 1:
						
						if( assign_count == 0) 
						{
								printf("\n");
							printf("\nGood News No more Assignments\n");
							break;
						}
						
						
						printf("\nChap Number : %s, \t\tSubmission Date: %s\n",assign[out_Ass].ChapNumber,assign[out_Ass].SubmissionDate);
						out_Ass=(out_Ass+1)%N_Assignment;
						assign_count = assign_count -1;
						break;
						
						
					case 2:
						
						if( quiz_count == 0)
						 {
						 		printf("\n");
							printf("\nGood News Not Any Quiz\n");
							break;
						}
							printf("\n");
						printf("\nTopic Name : %s, \t\tQuiz date : %s\n",quiz_[out_Quiz].TopicName,quiz_[out_Quiz].DateOfQuiz);
						out_Quiz=(out_Quiz+1)%N_Assignment;
						quiz_count = quiz_count -1;
						break;
						
						
						
					case 3:
						
						if( ClassTask_count == 0) 
						{
								printf("\n");
							printf("\nGood News No Class Task pending now\n");
							break;
						}
							printf("\n");
						printf("\nTopic Name : %s, \t\t Quiz date : %s\n",(classtask + out_CT)->TopicName,(classtask + out_CT)->SessionNumber);
						out_CT++;
						ClassTask_count = ClassTask_count -1;
						break;
						
					case 4:
						
						break;
						
					default:
						
						printf("\nSelect valid option\n");
						break;
					}
				}
				
				
				
				/////////////////////student end////////////////////
			}
		}
		
	return 0;
	
}

