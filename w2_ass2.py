# -*- coding: utf-8 -*-
"""
Created on Mon Jun  3 15:20:18 2024

@author: cseweb
"""

from datetime import datetime
now=datetime.now()
year=now.year
month=now.strftime("%B")
day=now.day
print(day,month,year)
print(month)
year=int(input("Enter a year:"))
if (year%4==0):
    if(year%100==0):
        if(year%400==0):
            print("It is a leaf year")
        else:
         print("It is not a leap year")
    else:
        print("It is a leap year")
else:
    print("It is not a leaf year")
         


            
    
    