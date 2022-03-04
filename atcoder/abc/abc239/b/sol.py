s=input()

if(len(s)==1):
    print(0)
    exit()
if len(s)==2 and s[0]=="-":
    print(-1)
    exit()
    
s2=int(s)
s=int(s[:-1])
if(s<0 and s2%10!=0):
    s-=1
print(s)