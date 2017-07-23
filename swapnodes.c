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
    
    	void swapnodes(struct node **head_ptr,int x,int y){
    		
    		struct node* head=*head_ptr;
    	struct node*prev1=NULL;
    	struct node*prev=NULL;
    	struct node*prev2=NULL;
    	struct node*h=head;
    		
    	struct node*node1=NULL;
    	struct node*node2=NULL;
    	
    	
    	
    	while(h!=NULL){
    		if(h->data==x)
    		{
    			prev1=prev;
    			node1=h;
    		printf("prev1=%d",prev1);
    		}
    		
			
    		if(h->data==y)
    		{
    			node2=h;
    			prev2=prev;
    		}
    		prev=h;
    		h=h->next;
    		
    	
    	}
    if(prev1==NULL)
    {
    	if(node1==prev2)
    	{
    		struct node*temp=node2->next;
    	
    
    		node1->next=temp;
    		node2->next=node1;
    		*head_ptr=node2;
    	}
    	else 
    	if(prev2!=NULL||true){
    		
    
    	struct node*temp=node1->next;
    	
    	node1->next=node2->next;
    	
    	node2->next=temp;
    	
    	prev2->next=node1;
    	
    	*head_ptr=node2;
    	
    	*head_ptr=node2;
    	
    	}
    	
    	
    }
    	else
    	if(prev1->next==prev2)
    	{
    		struct node*temp=node2->next;
    	
    
    		node1->next=temp;
    		node2->next=node1;
    		prev1->next=node2;
    		
    		
    		
    	}
    	
    	else 
    	if(prev1!=NULL&&prev2!=NULL||true){
    		
    
    	struct node*temp=node1->next;
    	
    	node1->next=node2->next;
    	
    	node2->next=temp;
    	
    	prev2->next=node1;
    	
    	prev1->next=node2;
    	
    	}
    	
    		
    		
    	}
    	
    int main()
    {      
       
        struct node *head=NULL;
        insert(6,&head);
        insert(5,&head);
        insert(4,&head);
        insert(3,&head);
        insert(2,&head);
        insert(1,&head);
       
    //   	if(findKey(2,head))
    //   		printf("found");
  		// else 
  		// 	printf("not found");
  		print(head);
  		
  		swapnodes(&head,5,6);
  		print(head);
  		
    
        return 0;
    }
    
    



