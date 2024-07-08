# -*- coding: utf-8 -*-
"""
Created on Mon Jun  3 16:00:28 2024

@author: cseweb
"""
s=input("Enter a string:")
if(s.isalpha()):
    if(s==s.upper()):
        print("String contain upper case letters")
    else:
         print("string contain lower case letters")
elif(s.isdigit()):
    sum=0
    for i in s:
        sum+=int(i)
    print(sum)
elif(s.isalnum()):
    print("String conatin number or spcial charcter")
else:
    c=0
    for i in s:
        if(not i.isalpha() and not i.isdigit()):
            c=c+1     
    print("cont of secial character is",c)



        


    
        