#include<stdio.h>
#include<stdlib.h>
#include<process.h>// This is version 1.1.
#define MALLOC(p,type)\
p=(type*)malloc(sizeof(type));\
if(p==NULL)\
{\
                printf("Insufficient Memory");\
                exit(0);\
}
               
struct node
{
                int pin;
                char name[20];
                int accno;
                //int total;
                //float average;
                struct node *link;
};
typedef struct node* NODE;
NODE insert_front(NODE first)
{
				system("pause");	
                NODE temp;
				int i;
                MALLOC(temp,struct node);
		        printf("Enter the name of customer\n");
				fflush(stdin);//for flushing gets()
	            gets(temp->name);
	            printf("Enter the Account number of customer\n");
				scanf("%d",&temp->accno);				
                printf("Enter the pin");
                scanf("%d",&temp->pin);
                temp->link=first;
                return temp;
}
/*void display(NODE first)
{
                NODE temp;
                int i;
                //float average;
                if(first==NULL)
                {
                                printf("List is empty\n\n");
                                return;
                }
                printf("The contents of the list are\n");
                temp=first;
                printf("\t\t\t\t\tmarks\n");
                printf("Name\t\t|sub1\tsub2\tsub3\tsub4\tsub5\tsub6\ttotal\n");
                printf("-----------------------------------------\n");
                while(temp!=NULL)
                {
                                printf("%s\t\t|",temp->name);
                                fflush(stdout);
                                for(i=0;i<6;i++)
                                printf("%d\t",temp->accno);
                               // printf("%d\t",temp->marks[0]+temp->marks[1]+temp->marks[2]+temp->marks[3]+temp->marks[4]+temp->marks[5]);
                                printf("\n");
                                fflush(stdout);
                                temp=temp->link;
                }
                printf("\n");
}*/
NODE search(NODE first)
{
	int accno;
	printf("Enter the Account number");
	scanf("%d",&accno);
	NODE cur;
	if(first==NULL)
	return NULL;
	cur=first;
	while(cur!=NULL)
	{
		if(accno==cur->accno)
			{	
				printf("Found ya");
			
		}
		else 
		cur=cur->link;
	}
	return NULL;
}


int main()
{
    NODE first=NULL;
    NODE temp;
    //search(first);
    int choice,access,adminpass;
    logout:
    printf("To access ATM as customer press 1\nTo access ATM as administrator press 2\n");
    scanf("%d",&access);
    if(access==2)
    	{
            printf("Enter Administrator passcode");
            scanf("%d",&adminpass);
            if(adminpass==9999)
                {
                	for(;;)
                		{
                			printf("Press 1 to Insert\nPress 2 to search\nPress 3 to exit\n\n");
							scanf("%d",&choice);
							switch(choice)
                                {
                                    case 1:
									first=insert_front(first);
									break;
                                    case 2:
									temp=search(first);
                                    default:goto logout;
                                }
                        }
                }
                else
                    {
                    	return 0;
                    }
        }
    else
    {
        printf("You are logged in as customer");
    }
}
