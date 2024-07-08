# -*- coding: utf-8 -*-
"""
Created on Mon Jun  3 16:45:15 2024

@author: cseweb
"""
import math
a=int(input("Enter a number:"))
b=int(input("Enter a number:"))
if(a%2!=0 and b%2!=0):
    if(a!=b):
        print("Before swapping")
        print("a=",a,"b=",b)
        a,b=b,a
        print("After swapping")
        print("a=",a,"b=",b)
elif(a%2==0 and b%2==0):
    if(a!=b):  
        if(a>b):
            print("A is larger number")
        else:
            print("B is larger number")
else:
    print("Factrioal of  A is=",math.factorial(a))
    print("Factrioal of  B is=",math.factorial(b))



            
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        