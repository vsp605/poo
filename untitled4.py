# -*- coding: utf-8 -*-
"""
Created on Mon Jul  8 15:32:04 2024

@author: cseweb
"""

s = {1: 10, 2: 10, 3: 40, 4: 20, 5: 70, 6: 80, 9: 40, 10: 20}
count_10 = 0

for value in s.values():
    if value == 10:
        count_10 += 1

print("Frequency of value 10:", count_10)
