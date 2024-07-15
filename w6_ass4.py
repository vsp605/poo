f=open("11th.txt", "r")
lines=f.readlines()
f1= open("k.txt", "w")
for i in range(len(lines)):
    if i%2!=0:
        f1.write(lines[i])
