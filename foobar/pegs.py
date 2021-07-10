def solution(pegs):
    diff = []
    net = 0
    for i in range(1, len(pegs)):
        diff.append(pegs[i] - pegs[i - 1])
        if i % 2:
            net += pegs[i] - pegs[i - 1]
        else:
            net -= pegs[i] - pegs[i - 1]

    if len(diff) % 2:
        ans = 2 * net / 3
        a = 2 * net
        b = 3
        if a % b == 0:
            a //= 3
            b //= 3
            
        if ans > 0:
            return [a, b]
        else:
            return [-1, -1]
    else:
        ans = 2 * net
        if ans > 0:
            return [ans, 1]
        else:
            return [-1, -1]


n=int(input("Enter the number of pegs: "))
pegs=[]
for i in range(n):
    pegs.append(int(input("")))

print(solution(pegs))