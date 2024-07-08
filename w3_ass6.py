# -*- coding: utf-8 -*-
"""
Created on Mon Jun 10 15:46:28 2024

@author: cseweb
"""
m="mnbvcxzlkjhgfdsapoiuytrewq"
n=input("Enter a string:")
n=n.lower()
o=False
for i in m:
    if(i not in n):
        o=False
    else:
         o=True
if(o==True):
    print("string is a pangram")
else:
    print("String is not pangram")


    

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    