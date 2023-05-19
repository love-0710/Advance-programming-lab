with open("exp.txt","r") as f:
        p=f.readline()[:-1]
operators=["+","-","*","/","%","(",")","="]
operands=[]
pres_op=[]
delimiters=[]
k=0
f=0
i=0
s=""
while i<len(p):
        if p[i] in operators:
                s=s+f" {p[i]} " 
        else:
                s=s+p[i]
        i+=1
s=s.split(" ")
#print(s)
for i in s:
        if i =="":
                f=1
                break
if f==0:
        i=0
        while i <len(s):
                #if "\\" in s[i]:
                #       q=s[i].split("\\")
                #       q[1]=f"\\q[1]"
                #       s=s+q
                #       s.pop(i)
                #       print("hi")
                #       continue
                #el
                if s[i] in operators:
                        if i!=0 and s[i-1] not in operators:
                                if s[i] not in pres_op:
                                        pres_op.append(s[i])
                        else:
                                f=1
                                break
                else:
                        if i!=0 and s[i-1] not in operators:
                                f=1
                                break
                        if s[i] not in operands:
                                operands.append(s[i])
                i+=1
#i=0
#while i<len(p):
#
#               if (p[i]== '\\'):
#                       if p[
if f==0:
        print("Operands: ",operands)
        print("Operators: ",pres_op)
#       print("Delimiters:",delimiters)
else:
        print("Invalid Input")



