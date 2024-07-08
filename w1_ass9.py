a=int(input("Enter a number:"))
fact=1
if a==0:
    print("factrorial of number is 1")
for i in range(a,0,-1):
    fact=fact*i
print(fact)
    
    