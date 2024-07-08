# -*- coding: utf-8 -*-
"""
Created on Mon Jun  3 16:17:33 2024

@author: cseweb
"""
m=int(input("Enter a number:"))
n=int(input("Enter a number:"))
ch=input("Enter a choice\n A-Arthamitic opperation\n B-Bitwise opperation\n")
if(ch=='A'):
    ch=input("Enter a choice\n + addition\n - substraction\n * multipliaction\n / division\n")
    if(ch=='+'):
        print("addition of two number is",m+n)
    elif(ch=='-'):
        print("substarction is",m-n)
    elif(ch=='*'):
        print("multiplication is",m*n)
    elif(ch=='/'):
        print("divison is",m/n)
else:
     ch=input("Enter a choice\n AND\n OR\n NOT\n XOR\n")
     if(ch=='AND'):
        print("bitwise and is",bin(m&n))
     elif(ch=='OR'):
        print("bitwise or is",bin(m|n))
     elif(ch=='NOT'):
        print("bitwise not is",bin(~n),bin(~m))
     elif(ch=='XOR'):
        print("bitwise xor is",bin(m^n))










        
