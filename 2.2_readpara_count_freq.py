operators=["+","-","*","/","%","(",")","=","{",":","}","[","]","&","|","\"",",",".","<"]
operands=[]
op_count={}
pres_op=[]
pres_count={}
delimiters=[]
with open("2.txt","r") as file:
        while(p:=file.readline()):
                p=p[:-1]
                p=p.strip()
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
                i=0
                while i <len(s):
                        if s[i] in operators:
                                if i!=0 and s[i-1] not in operators:
                                        if s[i] not in pres_op:
                                                pres_op.append(s[i])
                                                pres_count[s[i]]=1
                                        else:
                                                pres_count[s[i]]+=1
                        elif s[i]!='':
                                if s[i] not in operands:
                                        operands.append(s[i])
                                        op_count[s[i]]=1
                                else:
                                        op_count[s[i]]+=1
                        i+=1
        for j in op_count:
                print(j,"-",op_count[j])
        for j in pres_count:
                print(j,"-",pres_count[j])




