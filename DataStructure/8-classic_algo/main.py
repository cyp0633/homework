m, n = input().split()
m = int(m)
n = int(n)
dp = []
for i in range(21):
    dp.append(0)
dp[1] = 1
for i in range(1, m+1):
    for j in range(1, n+1):
        if i == j and i == 1:
            continue
        dp[j] = dp[j]+dp[j-1]
print(dp[n])
