f=open("dt.txt", "r") 
f1=open("unique.txt", "w") 
unique_words = set() 
for line in f:
    words = line.split()  
    for word in words:
        unique_words.add(word)      
for word in sorted(unique_words):
        f1.write(f"{word}\n")
