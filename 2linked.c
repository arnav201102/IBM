#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
};
struct node *start;
void create()
{ 	
	char ch;
	do{
		struct node *new_node,*current;
		new_node=(struct node *)malloc(sizeof(struct node));
  		printf("\nEnter the data : ");         
  		scanf("%d",&new_node->data);
  		new_node->next=NULL;
  		if(start==NULL)        
  		{   
			start=new_node;     
      		current=new_node;  
		}
		else 
		{  
		current->next=new_node;
    	current=new_node;   
		}
 		printf("Do you want to create another : ");
 		ch=getche();
 	}while(ch!='n');
}
void display()
{
	struct node *new_node;
 	printf("The Linked List : ");
 	new_node=start;
 	while(new_node!=NULL)
  	{
   		printf("%d--->",new_node->data);
   		new_node=new_node->next;
   	}	
  	printf("NULL");
}
void del_beg(){
	struct node *temp;
	temp=start;
	start=start->next;
	free(temp);
	printf("\n Deletion Succesful");
}
void del_last(){
	struct node *temp,*prev;
	if(start==NULL){
		printf("\n NOT POSSIBLE");
	}
	prev=NULL;
	temp=start;
	while(temp->next!=NULL){
		prev=temp;
		temp=temp->next;
	}
	if(prev==NULL){
		start=NULL;
	}
	else{
		prev->next=NULL;
	}
	free(temp);
	printf("\n Deletion Succesful");
}
void del_mid(int index){
	int i;
	struct node *p= start;
	struct node *q= start->next;
	for(i=0;i<index-2;i++){
		p=p->next;
		q=q->next;
	}
	p->next=q->next;
	free(q);
	printf("\n Deletion Succesful");
}
void main()
{
	int choice;
	create();
    printf("\n\t DELETION IN LINKED LIST");
    printf("\n\t--------------------------------");
    printf("\n\t 1.START\n\t 2.END\n\t 3.MIDDLE\n\t 4.DISPLAY\n\t 5.EXIT");
    do
    {
        printf("\n Enter the Choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                del_beg();
                break;
            }
            case 2:
            {
                del_last();
                break;
            }
            case 3:
            {
            	int p;
            	printf("\n Enter position: ");
            	scanf("%d",&p);
                del_mid(p);
                break;
            }
            case 4:
            {
                display();
                break;
            }
            case 5:
            {
                printf("\n\t EXIT POINT ");
                exit(0);
            }
            default:
            {
                printf ("\n\t Please Enter a Valid Choice(1/2/3/4/5)");
            }                
        }
    }
    while(choice!=5);
}
/*
Include Header Files

declare structure node
	int data;
	struct node *next;
end structure
declare struct object *start

begin procedure create: void
	declare character ch
	do
		struct node *new_node,*current
		new_node=(struct node *)malloc(sizeof(struct node))	
		Enter Data &new_node->data
		new_node->next=NULL
		if(start==NULL)
			start=new_node
			current=new_node
		end if
		else
			current->next=new_node
			current=new_node
		end else
		ch=getche()
	end do while(ch!='n')
end procedure

begin procedure display: void
	struct node *new_node;
	Print Linked List :-
	new_node=start
	while(new_node!=NULL)
		Print new_node->data
		new_node=new_node->next
	end while
end procedure

begin procedure del_beg()
	struct node *temp
	temp=start
	start=start->next
	free(temp)
	Print Deletion Succesful
end procedure

begin del_last()
	struct node *temp,*prev
	if(start==NULL)
		Print NOT POSSIBLE
	end if
	prev=NULL
	temp=start
	while(temp->next!=NULL)
		prev=temp
		temp=temp->next
	end while
	if(prev==NULL)
		start=NULL
	end if
	else
		prev->next=NULL
	end else
	free(temp)
end procedure

begin procedure del_mid: int index
	Declare i
	struct node *p=start	
	struct node *p=start->next
	for(i=0;i<index-2;i++)
		p=p->next
		q=q->next
	end for
	p->next=q->next
	free(q)
end procedure

begin void main
	Declare choice
	create()
	Print Menu
	do
	Input choice
	switch(choice)
		case 1
			del_beg()
			break
		end case 1
		case 2
			del_last()
			break
		end case 2
		case 3
			declare p
			Enter position p
			del_mid(p)
			break
		end case 3
		case 4
			display()
			break
		end case 4
		case 5
			exit(0)
		end case 5
		default
			Print Enter a valid choice
		end default
	end switch
	end do while(choice!=5)
end main		
*/
