#bus 
def bus_revenued(d,p):
    ticket_amount=p*80
    fuel_qty=d/10
    fuel_price=fuel_qty*70
    if ticket_amount>fuel_price:
        return(ticket_amount-fuel_price)
    else:return-1
dist=float(input("enter distance"))
passanger=int(input('enter no of passangers"))
        