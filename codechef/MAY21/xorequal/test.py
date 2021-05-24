import sys

n = int(input())
last = 2**n
res = 0
flag = False
print("-----")
for i in range(last):
    ans = i ^ (i+1) ^ (i+2) ^ (i+3)
    if(ans == 0):
        res += 1
        # print(i)
        if(i % 2 == 1):
            flag = True
print("-----")
# print(flag)
print('ans='+str(res))
