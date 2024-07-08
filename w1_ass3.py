# -*- coding: utf-8 -*-
"""
Created on Mon May 27 15:21:28 2024

@author: cseweb
"""

x=int(input("Enter a number:"))
y=int(input("Enter a number:"))
z=int(input("Enter a number:"))
if x>y&y>z:
    print("Largest number is:",x)
elif y>z:
    print("Largest number is:",y)
else:
    print("Largest number is:",z)
print("END")
    
     

    
    