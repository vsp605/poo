f=open("fr1.txt", "r") 
f1= open("d11.txt", "w")
df= {}
for line in f:
    words = line.split()
    for word in words:
                if word in df:
                    df[word] += 1
                else:
                    df[word] = 1
for word, freq in df.items():
            if freq >= 3:
                f1.write(f"{word}: {freq}\n")
