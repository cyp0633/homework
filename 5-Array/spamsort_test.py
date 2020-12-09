#奇数是spam，偶数不是 先非再是
for i in range(887,16004):
    a=i
    a=a*10+3
    a=a*6+1
    a=a*9+9
    a=a*5+5
    a=a*8+7
    a=a*2+7
    if a%2==0:
        print("No")
    else:
        print("Yes")