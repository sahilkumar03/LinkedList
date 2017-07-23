    #include <stdio.h>
    #include<stdlib.h>
    #include<stdbool.h>
    struct node{
      int data;
      struct node *next;
    };
bool findKey(int key,struct node*head)
		{
			if(head==NULL)
			return false;
			
			if(head->data==key)
			return true;
			
			return findKey(key,head->next);
		}
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
    
    void insertAt(int pos,int data,struct node *head,struct node **head_ptr){
   
     int count=1;
        struct node *prev=head;
        
        while(prev!=NULL){
           
            if(count == pos)
            {
                struct node *temp=(struct node*)malloc(sizeof(struct node));
                temp->data=data;
                
                temp->next=head;
                if(count==1)
                { 
                    *head_ptr=temp;
                    break;
                }
                 prev->next=temp;
                
            }
            
             prev=head;
            head=head->next;     
            count++;
            if(count==pos&&head==NULL){
                struct node *temp=(struct node*)malloc(sizeof(struct node));
                temp->data=data;
                temp->next=NULL;
                prev->next=temp;
                break;
            }
        }   
        
    }

    void print(struct node* head){
        int count=1;
        struct node *temp=head;
        while(temp!=NULL){
            printf("\nnode-%d data=%d\n",count,temp->data);
            count++;
            temp=temp->next;
        }
    }
    
    void delete(int key,struct node** head_ptr)
    {
        struct node *head;
        head=(*head_ptr);
        struct node *prev=NULL; 
          while(head!=NULL)
          {
              
              if(head->data==key)
              {
                  if(prev==NULL)
                  {
                      *head_ptr=head->next;
                      
                      break;
                  }
                  prev->next=head->next;
                  free(head);
                  break;
              }
              prev=head;
              head=head->next;
          }
    }
    
    
    int deleteAt(int pos,struct node **head_ptr){
        struct node *head;
        struct node *prev=NULL;
        head=*head_ptr;
        
        while(pos>1)
        {
            prev=head;
            head=head->next;
            pos--;
        }
        
                  if(prev==NULL)
                  {
                      *head_ptr=head->next;
                  }
                  else
                    prev->next=head->next;
        free(head);
        int x=head->data;
        return x;
    }
    
    int findendnthnode(int n,struct node **head_ptr)
    {
        
        struct node *head,*temp;
        head=*head_ptr;
        temp=*head_ptr;
        int count=0;
        while(head!=NULL){
            temp=head;
            count=0;
            while(temp!=NULL)
            {
                temp=temp->next;
            count++;
            }
            if(count==n)
            {
                printf("match found data=%d",head->data);
                break;
            }
            
            head=head->next;
        }
        
        
        
        return 0;
    }
    
    
    int printLength(struct node *head){
    	int count=0;
    	while(head!=NULL)
    	{
    		head=head->next;
    		count++;
    	}
    return count;
    }
    
    int printLengthR(int n,struct node *head){
    	if(head==NULL)
    	return n;
    return printLengthR(n++,head);
    }
    
    
    int main()
    {      
       
        struct node *head=NULL;
      //   clrscr();
        insert(6,&head);
        insert(5,&head);
        insert(4,&head);
        insert(3,&head);
        insert(2,&head);
        insert(1,&head);
//        insertAt(6,6,head,&head);
    //    deleteAt(1,&head);
    
        //print(head);
    	printf("linked list length = %d",printLength(head));
    	printf("linked list length = %d",printLengthR(0,head));

      //  findendnthnode(4,&head);

        return 0;
    }
    
    




