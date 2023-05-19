class Node:
        def __init__(self,d,n=None):
                self.data=d
                self.next=n
class LinkedList:
        def __init__(self):
                self.head=None
        def insert(self,data,index):
                if index==0:
                        p=Node(data)
                        p.next=self.head
                        self.head=p
                else:
                        p=Node(data)
                        t=0
                        temp=self.head
                        while temp!=None and t<index-1:
                                temp=temp.next
                                t+=1
                        p.next=temp.next
                        temp.next=p
        def delete(self,index):
                temp=self.head
                i=0
                while temp!=None and i<index-1:
                        temp=temp.next
                        i+=1
                if(temp!=None):
                        temp.next=temp.next.next
        def list_to_ll(self,a):
                for i in a:
                        p=Node(int(i))
                        if self.head==None:
                                self.head=p
                        else:
                                t.next=p
                        t=p
        def display(self):
                temp=self.head
                while temp!=None:
                        print(temp.data," ",end="")
                        temp=temp.next
                print()
k=int(input("Enter no of lists: "))
arr=[]
for i in range(0,k):
        b=input(f"Enter List {i+1} seperated by commas: ")
        b=b.split(",")
        c=LinkedList()
        c.list_to_ll(b)
        print(f"List {i+1} :",end="")
        c.display()
        print()
        arr.append(c)

sorted=LinkedList()
sorted.head=arr[0].head
p=sorted.head
for j in range(1,len(arr)):
        while(p.next!=None):
                p=p.next
        p.next=arr[j].head
p=sorted.head
d=0

while(p!=None):
        j=p.next
        k=p
        insi=d
        deli=d
        s=0
        while(j!=None):
                s+=1
                if(k.data>j.data):
                        k=j
                        deli=deli+s
                        s=0
                j=j.next
        if(insi!=deli):
                sorted.insert(p.data,deli)
                sorted.insert(k.data,insi)
                sorted.delete(deli+2)
                sorted.delete(insi+1)
        d+=1
        p=p.next
sorted.display()

#sorted.head=arr[0].head
#for i in range(1,k):
#       temp=arr[i].head
#       p=sorted.head
#       d=0
#       while(temp!=None):
#               while(p!=None and p.data<temp.data):
#                       d+=1
#                       p=p.next
#               sorted.insert(temp.data,d)
#               d+=1
#               temp=temp.next
#print("Sorted List: ",end="")
#sorted.display()





