//consider two non-empty linked lists representing two non-negative integers. the digits are in reverse order,
//and each of thier nodes contains a single digit. write a program to add thw two no. & return the as a linked-list
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *insert(struct node *head, int item)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=item;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        struct node*p;
        p=head;
        while(p->next!=NULL)
            p=p->next;
            p->next=temp;
    }
    return head;
}
void display(struct node *head)
{
    struct node *p;
    p=head;
    while(p!=NULL)
    {
        printf("%d",p->data);
        p=p->next;
    }
    printf("\n");
}
struct node *reverse(struct node *head)
{
    int i, j;
    struct node*temp=NULL;
    struct node*p;
    for(i=3; i>0; i--)
    {
        p=head;
        for(j=i; j>1; j--)
            p=p->next;
        temp=insert(temp, p->data);
    }
    return temp;
}
void main()
{
    int n, m, i, sum, carry=0;
    printf("enter two 3-digit numbers: ");
    scanf("%d%d", &n,&m);
    struct node *head1=NULL;
    struct node *head2=NULL;
    struct node *head3=NULL;
    for(int i=0; i<3; i++)
    {
        head1=insert(head1,n%10);
            n=n/10;
        head2=insert(head2,m%10);
            m=m/10;
    }
    display(head1);
    display(head2);
    struct node*p1;
    struct node*p2;
    for(int i=3;i>0;i--)
    {
        p1=head1;
        p2=head2;
        for(int j=i; j>1; j--)
        {
            p1=p1->next;
            p2=p2->next;
        }
        sum=p1->data + p2->data + carry;
        if(sum>9)
        {
            carry=1;
            if(i>1)
            sum=sum%10;
        }
        else
            carry=0;
        head3=insert(head3, sum);
    }
    head3=reverse(head3);
    printf("sum= ");
    display(head3);
}