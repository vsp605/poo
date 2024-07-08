# -*- coding: utf-8 -*-
"""
Created on Mon Jun 10 15:45:42 2024

@author: cseweb
"""

n=input("Enter a 4 digit binary number string:").split(",")
div_5=[]
for i in n:
    dec=int(i,2)
    if(dec%5==0):
        div_5.append(i)
print("division by five are",div_5)        










































