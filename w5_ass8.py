def ispoweroftwo(n):
    return (n and(not(n&(n-1))))
def check_thabit(n):
    n=n+1
    if(n%3==0):
        n=n//3
    else:
        return False
    if(ispoweroftwo(n)):
        return True
    else:
        return False
n=int(input("Enter a number:"))
if(check_thabit(n)):
    print(n,"is a thabit")
else:
    print(n,"is not a thabit")

    



    
