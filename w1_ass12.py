# -*- coding: utf-8 -*-
"""
Created on Mon Jun  3 17:28:05 2024

@author: cseweb
"""

a=int(input("enter first subject marks"))
b=int(input("enter second subject marks"))
c=int(input("enter third subject marks"))
d=int(input("enter fourth subject marks"))
e=int(input("enter fifth subject marks"))
per=((a+b+c+d+e)/500)*100
if per>=90 and per<=100:
    print("grade is S")
elif per>=80 and per<=89:
    print("grade is A")
elif per>=70 and per<=79:
    print("grade is B")
elif per>=60 and per<=69:
    print("grade is C")
elif per>=50 and per<=59:
    print("grade is D")
else:
    print("grade is F")
    

    
     
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    