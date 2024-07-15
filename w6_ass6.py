import re
pan=input("Enter a pan card number: ")
k=r'[A-Z]{5}[0-9]{4}[A-Z]{1}'
m=re.search(k, pan)
if m:
    print("Valid pan card number")
else:
    print("Not a valid pan card number")
