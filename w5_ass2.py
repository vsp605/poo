def fib(n):
    if n==0:
        return 0
    elif n==1 or n==2:
        return 1
    else:
        return fib(n-1)+fib(n-2)
d={}
while True:
    n=int(input("Enter a number:(-1 for exit)"))
    if n==-1:
        break
    else:
        l=[]
        fib(n)
        for i in range(n):
            l.append(fib(i))
            d[n]=l
print(d)    
    