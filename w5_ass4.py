d1=['s001','s002','s003','s004']
d2=['aaa','bbb','ccc','ddd']
d3=[1,2,3,4]
di={}
sd={}
for i in range(len(d1)):
    sd={d2[i]:d3[i]}
    di[d1[i]]=sd
print(di)    