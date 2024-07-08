# -*- coding: utf-8 -*-
"""
Created on Mon May 27 15:45:52 2024

@author: cseweb
"""

a=int(input("Enter x co-ordinate point:"))
b=int(input("Enter y co-ordinate point:"))
if (a==0 & b==0):
    print("points are lies in a origin")
elif (a>0 & b>0):
    print("POints lies in first quadrent")
elif (a<0 & b>0):
    print("points lies in second quadrent")
elif (a<0 & b<0):
    print("points lies in third quadrent")
else:
    print("points lies in fourth quadrent")
print("END")
    


    