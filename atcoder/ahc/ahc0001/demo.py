def rectangle_intersect(x1,x2):
    a1=x1[0]
    a2=x2[0]
    b1=x1[1]
    b2=x2[1]
    c1=x1[2]
    c2=x2[2]
    d1 = x1[3]
    d2 = x2[3]
    if((c1>=a2 or c2<a1)and (d1>=b2 or b1>=d2)):
        return 0
    return 1

x1=[0,1,1,0]
x2=[0.5,1.5,1.5,0.5]
print(rectangle_intersect(x2,x1))

