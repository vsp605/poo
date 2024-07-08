#linear search
l=[]
sum=0
n=int(input('enter size of list'))
for i in range(n):
    x=int(input('enter value'))
    l.append(x)
    print('in list form',l)
    key=int(input('search element')
    flag=0
    for i in range(0,n):
        if l[i]==key:
            flag=1
            break=1
            if flag==1:
                print('element is present')
            else:
                print('element not found')