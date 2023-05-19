import keyword
operators=["+","<",">",";","-","*","/","%","(",")","=","{",":","}","[","]","&","|",",","<","!"]
identifiers=[]
comments=[]
literals=[]
numbers=[]
pre=[]
op=[]
kl=keyword.kwlist+["int","void","include"]
keywords=[]
with open("3.txt","r") as file:
        while(p:=file.readline()):
                p=p[:-1]
                p=p.strip()
                i=0
                s=""
                while i<len(p):
                        if p[i:i+2]=="//":
                                s=s+p[i:].replace(" ","")
                                break
                        elif p[i] in operators:
                                s=s+f" {p[i]} "
                        elif p[i]=="\"":
                                k=i+p[i+1:].index("\"")+1
                                s=s+" "+p[i:k+1].replace(" ","")+" "
                                i=k
                        else:
                                s=s+p[i]
                        i+=1
                if(s[0]!="#"):
                    s=s.split(" ")
                    for i in s:
                            if len(i)==0:
                                    continue
                            if i[0:2]=="//":
                                    comments.append(i)
                            elif i in operators:
                                    op.append(i)
                            elif (i[0]=="\"" and len(i)!=2):
                                    literals.append(i)
                            elif i[0] in "1234567890":
                                    numbers.append(i)
                            elif i in kl :
                                    keywords.append(i)
                            elif i not in operators and i[0] not in "1234567890":
                                    identifiers.append(i)
                else:
                    pre.append(s)
print("Comments: ")
for i in set(comments):
        print(i,end=" , ")
print("\n\nKeywords: ")
for i in set(keywords):
        print(i,end=" , ")
print("\n\nIdentifiers: ")
for i in set(identifiers):
        print(i,end=" , ")
print("\n\nLiterals: ")
for i in set(literals):
        print(i,end=" , ")
print("\n\nNumbers: ")
for i in set(numbers):
        print(i,end=" , ")
print("\n\nOperators: ")
for i in set(op):
        print(i,end=" ")
print()




