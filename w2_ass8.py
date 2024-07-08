# -*- coding: utf-8 -*-
"""
Created on Mon Jun 10 17:26:51 2024

@author: cseweb
"""

n=int(input("Entere a number:"))
for i in range(0,100,1):
    print(n,end=" ")
    a=int(input("Enbter a number:"))
    if(a>n):
        n,a=a,0
    else:
         print("Stops")
         break