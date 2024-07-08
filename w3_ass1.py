# -*- coding: utf-8 -*-
"""
Created on Mon Jun 10 14:41:04 2024

@author: cseweb
"""
n=input("Enter a string:")
m=['a','e','i','o','u','A','E','I','O','U']
re=""
for i in range(len(n)):
    if n[i] not in m:
        re=re+n[i]
print("aftrer Deleted vowels now string are:",re,end=" ")        