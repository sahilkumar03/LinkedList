    #include <stdio.h>
    #include<stdlib.h>
    #include<stdbool.h>
   static struct node *headr=NULL;
    struct node *head=NULL;

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

    void print(struct node * head){
        int count=1;
        struct node *temp=head;
        while(temp!=NULL){
            printf("\nnode-%d data=%d add=%d next=%d",count,temp->data,temp,temp->next);
            count++;
            temp=temp->next;
        }
          printf("\n");

    }

		 bool findKey(int key,struct node *head)
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


    void printnthelementfromendR(struct node *head,int n)
    {
    	static int i=0;
    	if(head==NULL)
    	return;

    	printnthelementfromendR(head->next,n);
    	if(++i==n)
    	printf("nth data=%d",head->data);

    }
    void printnthelementfromend(struct node *head,int n)
    {
    	static int i;

    	while(head!=NULL){
    		i=n;
    		while(i=i-1>=0)
    		{
    		head=head->next;
    		}
    	}
    }

    void merge(struct node *head1,struct node *head2)
    {
        if(head1==NULL&&head2==NULL)
    	{

    		head->next=NULL;
    		head2=head1=NULL;
    		return;
    	}
    	if(head1==NULL)
    		{

    			head->next=head2;
    			head=head->next;
    			head2=head2->next;
    			merge(NULL,head2);
    			return;

    		}
    	else if(head2==NULL)
    		{
    			head->next=head1;
    			head=head->next;
    			head1=head1->next;
    			merge(head1,NULL);
    			return;
    		}

    		else if(head1->data<=head2->data)
    	{
    			if(headr==NULL)
    			{
    				head=headr=head1;

    			}
    		else
    		{

    			head->next=head1;
    		head=head->next;
    		}
   			head1=head1->next;

    	}else{
    		if(headr==NULL)
    			{
    				head=headr=head2;

    			}
    		else
    		{head->next=head2;
    		head=head->next;
    		}
    		head2=head2->next;

    	}
    	if(head1!=NULL||head2!=NULL)
    		merge(head1,head2);
    }






    int main()
    {

        struct node *head=NULL;
        insert(6,&head);
        insert(55,&head);
        insert(45,&head);
        insert(35,&head);
        insert(25,&head);
        insert(15,&head);

        struct node *head1=NULL;
        //insert(50,&head1);
        //insert(40,&head1);
        insert(30,&head1);
        insert(18,&head1);
        insert(10,&head1);


    //   	if(findKey(2,head))
    //   		printf("found");
  		// else
  		// 	printf("not found");
  		print(head);

  	//	swapnodes(&head,5,6);
  		//print(head);
  		//printmiddle(head);
    	printf("helo");
    	merge(head,head1);
    	print(headr);
    	//printnthelementfromendR(head,2);

        return 0;
    }





