def sum_na(n):
    if n==0 or n==1:
        return n
    else:
        return n+sum_na(n-1)
n=int(input("Enter a number:"))
print(n,"Natrural number sum is ",sum_na(n))   