#include<stdio.h>
#include<stdlib.h>
struct node
{
        int data;
        struct node*link;
};
        struct node*start=NULL;

void insert(int item)
{
        struct node*temp;
        temp=(struct node*)malloc(sizeof(struct node));
        temp->data=item;
        temp->link=NULL;

        if(start==NULL)
                start=temp;
        else
        {
                struct node*p;
                p=start;
                while(p->link!=NULL)
                {
                        p=p->link;
                }
                        p->link=temp;
        }
}
void main()
{
        int a;
        for(int  i=0; i<3; i++)
        {
                printf("enter the no.");
                scanf("%d", &a);

                int i=a;
                while(i>0)
                {
                        int j=i%10;
                        insert(j);
                        i=i/10;
                }
        }
        struct node*temp=start;
        while(temp!=NULL)
            {
                printf("%d, ",temp->data);
                temp=temp->link;
            }

}


