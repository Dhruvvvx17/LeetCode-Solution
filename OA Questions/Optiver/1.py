
price_dict = {}
trade_dict = {}
pnl_dict = {}


def compute_pnl(txn):
    txn_id = txn[1]
    name = txn[2]
    action = txn[3]
    trade_price = int(txn[4])
    qty = txn[5]

    original_price = price_dict[name]

    if(action == "SELL"):
        curr_pnl = trade_price - original_price
    else:
        curr_pnl = original_price - trade_price
    
    if(name in pnl_dict):
        prev_id = pnl_dict[name][0]
        prev_pnl = pnl_dict[name][1]

        if(curr_pnl < prev_pnl):
            pnl_dict[name] = [txn_id, curr_pnl]
        else:
            pnl_dict[name] = [prev_id, prev_pnl]
    
    else:
        pnl_dict[name] = [txn_id, curr_pnl]

    # print(f"New compute: {pnl_dict}")

def solve(txns):
    for txn in txns:

        txn = txn.split(" ")

        # setting price
        if(len(txn) == 3):
            name = txn[1]
            price = int(txn[2])

            # overwrite price
            price_dict[name] = price

            # print(f"Price: {price_dict}")

            # recompute transaction for previous trades
            for key, txn in trade_dict.items():
                tname, tid = key.split("_")
                if(tname == name):
                    compute_pnl(txn)
            
        # trade
        elif(len(txn) == 6):
            txn_id = txn[1]
            name = txn[2]
            action = txn[3]
            trade_price = txn[4]
            qty = txn[5]
            
            key = str(name) + "_" + str(txn_id)
            payload = ["TRADE", txn_id, name, action, trade_price, qty]
            trade_dict[key] = payload

            compute_pnl(txn)

        # worst trade
        elif(len(txn) == 2):
            name = txn[1]
            res = pnl_dict[name][0]
            val = pnl_dict[name][1]
            if(val == 0):
                print("NO BAD TRADES")
            else:
                print(res)

        # print("TXN complete\n")

if __name__ == "__main__":

    n = int(input("Enter number of transactions: "))
    txns = []

    for i in range(n):
        t = input("Enter next txn: ")
        txns.append(t)

    solve(txns)