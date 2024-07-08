# -*- coding: utf-8 -*-
"""
Created on Mon Jun  3 16:54:34 2024

@author: cseweb
"""
n=int(input("Enter a number:"))
f1=0
f2=1
print(f1,end="->",sep="->")
print(f2,end="->",sep="->")
c=2
while c<n:
    f3=f1+f2
        
    print(f3,end="->",sep="->")
    f1=f2
    f2=f3
    c=c+1
     
