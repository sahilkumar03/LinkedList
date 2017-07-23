    #include <stdio.h>
    #include<stdlib.h>
    #include<stdbool.h>
    
    struct node{
      int data;
      struct node *next;
    };
    void insert(int data,struct node **head_ptr){
        if(*head_ptr==NULL)
        {
            struct node *temp=(struct node*)malloc(sizeof(struct node));
            temp->data=data;
            temp->next=NULL;
            *head_ptr=temp; 
             //printf("\ninserted data=%d successfully",temp->data);

        }
        else
        {
            struct node * temp=(struct node*)malloc(sizeof(struct node));
            temp->data=data;
            temp->next=*head_ptr;
            *head_ptr=temp;
            //printf("\ninserted data=%d successfully",temp->data);
        }
    }
    
    void print(struct node* head){
        int count=1;
        struct node *temp=head;
        while(temp!=NULL){
            printf("\nnode-%d data=%d add=%d next=%d",count,temp->data,temp,temp->next);
            count++;
            temp=temp->next;
        }
          printf("\n");
          
    }
    
		 bool findKey(int key,struct node*head)
		{
			if(head==NULL)
			return false;
			
			if(head->data==key)
			return true;
			
			return findKey(key,head->next);
		}  
    
    void printmiddle(struct node *head){
    	struct node *slow,*fast;
    	fast=slow=head;
    	
    	while(fast!=NULL&&fast->next!=NULL)
    	{
    		fast=fast->next->next;
    		slow=slow->next;
    	}
    	printf("middle ele=%d",slow->data);
    }
    	
    int main()
    {      
       
        struct node *head=NULL;
        //insert(6,&head);
        insert(5,&head);
        insert(4,&head);
        insert(3,&head);
        insert(2,&head);
        insert(1,&head);
       
  
  		print(head);
  	printmiddle(head);	
    
        return 0;
    }
    
    



