# -*- coding: utf-8 -*-
"""
Created on Mon Jun 10 14:56:59 2024

@author: cseweb
"""

n=input("Enter a string:")
f1=False
f2=False
for i in n:
    if i.isalpha():
        f1=True
    if i.isdigit():
        f2=True
if(f1==True and f2==True):
   print("String contain both the letters and numbers:") 
else:
    print("String not contain both the letters and numbers:")
    


        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
    