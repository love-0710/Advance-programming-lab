//consider an array of k-linked lists, each linked-list is sorted in ascending order. WAP to merge all the linked lists
//into  one sorted linked-list and return it.


#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node * insert(struct node *head, int val)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = val;
    temp->next = NULL;
    if(head==NULL)
        head = temp;
    else
    {
        struct node *p;
        p = head;
        while(p->next!=NULL)
            p = p->next;
        p->next = temp;
    }
    return head;
}

void display(struct node *head)
{
    struct node *p;
    p = head;
    while(p!=NULL)
    {
        printf("%d\t",p->data);
        p = p->next;
    }
    printf("\n");
}

struct node * merge(struct node *head1,struct node *head2)
{
    struct node *p1, *p2, *mhead=NULL;
    p1 = head1;
    p2 = head2;
    while(p1!=NULL && p2!=NULL)
    {
        if(p1->data < p2->data)
        {
            mhead = insert(mhead,p1->data);
            if(p1->next==NULL)
            {
                while(p2!=NULL)
                {
                    mhead = insert(mhead,p2->data);
                    p2 = p2->next;
                }
            }
            p1 = p1->next;
        }
        else
        {
            mhead = insert(mhead,p2->data);
            if(p2->next==NULL)
            {
                while(p1!=NULL)
                {
                    mhead = insert(mhead,p1->data);
                    p1 = p1->next;
                }
            }
            p2 = p2->next;
        }
    }
    return mhead;
}

void main()
{
    int k,n,val;
    printf("Enter no. of lists: ");
    scanf("%d",&k);
    struct node *head[k];
    for(int i =0;i<k;i++)
        head[i]=NULL;
    printf("Enter no. of elements in each list: ");
    scanf("%d",&n);
    for(int i =0;i<k;i++)
    {
        printf("Enter elements in list %d\n",i+1);
        for(int j=0;j<n;j++)
        {
            scanf("%d",&val);
            head[i] = insert(head[i],val);
        }
    }
    struct node *mhead=NULL;
    mhead = merge(head[0],head[1]);
    for(int i=2;i<k;i++)
        mhead = merge(mhead,head[i]);
    printf("Given lists:\n");
    for(int i=0;i<k;i++)
        display(head[i]);
    printf("Merged list:\n");
    display(mhead);
}