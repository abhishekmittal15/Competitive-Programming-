import sys 

points = []
rectangles = []


def rectangle_intersect(x1, x2):
    a1 = x1[0]
    a2 = x2[0]
    b1 = x1[1]
    b2 = x2[1]
    c1 = x1[2]
    c2 = x2[2]
    d1 = x1[3]
    d2 = x2[3]
    if(a2 >= c1 or c2 <= a1 or b2 >= d1 or d2 <= b1):
        return 0
    return 1


def not_within(x, y):
    a = x[0]
    b = x[1]
    c = x[2]
    d = x[3]
    if(y[0] < c and y[0] > a and y[1] > b and y[1] < d):
        return 0
    return 1


def area(x):
    a = x[0]
    b = x[1]
    c = x[2]
    d = x[3]
    return (abs(d-b)*abs(a-c))


def happiness_check():
    p = 0
    for i in range(n):
        if(not_within(rectangles[i], points[i])):
            break
        ar = area(rectangles[i])
        score = 1-(1-min(points[i][2], ar)/max(points[i][2], ar))**2
        p = p+score
    return p


sys.stdin=open('inp.txt')
n=int(input())
for i in range(n):
    points.append(input().split())
    points[i]=[int(point) for point in points[i]]
    points[i][0]+=0.5
    points[i][1] += 0.5

sys.stdin=open('out.txt')
for i in range(n):
    rectangles.append(input().split())
    rectangles[i]=[int(x) for x in rectangles[i]]

flag1 = False
for i in range(n):
    for j in range(i+1, n):
        x1 = rectangles[i]
        x2 = rectangles[j]
        if(rectangle_intersect(x1, x2)):
            flag1 = True
            print(f"{i}th rectangle {x1} intersects with {j}th rectangle {x2}")

if(flag1):
    print("The co-ordinates are invalid as they lead to intersection")

ans = happiness_check()
ans = int(ans*1e9/n)
print(f"Your happiness score is {ans}")
