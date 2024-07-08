# -*- coding: utf-8 -*-
"""
Created on Mon Jun 10 15:07:06 2024

@author: cseweb
"""

n=input("Enter a string:")
re=""
for i in n:
    if(i==","):
        i="."
    elif(i=="."):
        i=","
    else:
        i=i
    re=re+i
print(re)      
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    