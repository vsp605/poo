# -*- coding: utf-8 -*-
"""
Created on Mon May 27 17:00:29 2024

@author: cseweb
"""

a=int(input("Enter a number:"))
if a<1:
   print("number is not prime")
else:
    for i in range(2,a//2+1):
        if(a%i==0):
            print("number is not prime")
            break
    else:
         print("number is prime")
        



    