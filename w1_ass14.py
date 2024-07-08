# -*- coding: utf-8 -*-
"""
Created on Mon Jun 10 16:18:46 2024

@author: cseweb
"""

t=int(input("Enter temp:"))
print("type c if celsius,f if farenhit,k if kelvin")
ty=input("enter type of temp:")
if ty=='c':
    f=(t*9/5)+32
    k=t+273
    print(t,"in farehiet",f)
    print(t,"in kelvin",k)
elif ty=='f':
    c=(t*5/9)-32
    k=c+273
    print(t,"in farehiet",c)
    print(t,"in kelvin",k)
else:
     c=t-273
     f=(c*9/5)+32
     print(t,"in farehiet",f)
     print(t,"in celsius",c)
    
    