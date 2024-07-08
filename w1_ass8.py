# -*- coding: utf-8 -*-
"""
Created on Mon May 27 16:25:28 2024

@author: cseweb
"""
import math as m
a=int(input("Enter a value:"))
b=int(input("Enter b value:"))
c=int(input("Enter c value:"))
d=b*b-(4*a*c)
if d==0:
    root=-b/(2*a)
    print("Roots are equal",root)
elif d>0:
    root1=-b+(m.sqrt(d))/(2*a)
    root2=-b-(m.sqrt(d))/(2*a)
    print("Roots are real and different",root1,root2)
else:
    print("Roots are imaginary")



    
    
    
    