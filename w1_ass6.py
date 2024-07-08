# -*- coding: utf-8 -*-
"""
Created on Mon May 27 16:02:58 2024

@author: cseweb
"""

p=int(input("Enter a principle amount:"))
r=float(input("Enter rate of intrest:"))
t=int(input("Enter a time period in months:"))
si=(p*t*r)/100
print("simple intrest is:",si)
a=p*(pow(1+(r/100),t))
print("compund interst is=",a-p)