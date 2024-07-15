import re
n=input("Enter a ip adresss:")
k=r'^((25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.){3}(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$'
m=re.search(k, n)
if m:
    print("Valid ip address")
else:
    print("Not a valid ip address")