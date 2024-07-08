
"""from collections import Counter
s={1:10,2:10,3:40,4:20,5:70,6:80,9:40,10:20}
value_counts=Counter(s.values())
for value, count in value_counts.items():
    print(f"{value}: {count}")
"""
def fr_count(n):
    d2={}
    for value in n.values():
        if value not in d2:
            d2[value]=1
        else:
            d2[value]+=1
    return d2    
n={1:10,2:10,3:40,4:20,5:70,6:80,9:40,10:20}
print(fr_count(n))            