#to find amount to be paid
price_list={"pen":10,"notebook":50,"book":100}
items_purchased={}
n=int(input("enter the no of items purchased:"))
for i in range(n):
    print(price_list)
    item=input("enter the name of the item{}:".format(i+1))
    quantity=int(input("enter the quantity of item{}:".format(i+1)))
    items_purchased[item]=quantity
amt_to_be_paid=0
print("=====purchase details=====")
for item,quantity in items_purchased.items():
    if item in price_list:
        price=price_list[item]
        amt_to_be_paid+=price*quantity
        print(item,price,quantity)
print("amount to be paid=Rs.",amt_to_be_paid)
