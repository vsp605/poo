# -*- coding: utf-8 -*-
"""
Created on Mon Jun  3 15:33:57 2024

@author: cseweb
"""

import cmath
a=int(input("Enter a value:"))
b=int(input("Enter b value:"))
c=int(input("Enter c value:"))
d=b*b-(4*a*c)
if d==0:
    root=-b/(2*a)
    print("Roots are equal",root)
elif d>0:
    root1=-b+(cmath.sqrt(d))/(2*a)
    root2=-b-(cmath.sqrt(d))/(2*a)
    print("Roots are real and different",root1,root2)
else:
    root3=-b+(cmath.sqrt(d))/(2*a)
    root4=-b-(cmath.sqrt(d))/(2*a)
    print("Root are imaginary",complex(root3),complex(root4))

