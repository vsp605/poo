import re
p=input("Enter a passport number: ")
k=r'[A-Z]{1}[1-9]{1}[0-9]{1}[0-9]{4}[1-9]{1}'
m=re.search(k, p)
if m:
    print("Valid passport number")
else:
    print("Not a valid passport number")
