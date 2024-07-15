f=open("f.txt","r")
f1=open("vowel.txt","w")
for i in f:
    words=i.split(' ')
    for w in words:
        if w[0] in 'aeiou':
            f1.write(i)
            break
        break
f.close()
f1.close()            
    