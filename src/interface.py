class Exchange:
    # implement this!

    def __init__(self, initialBalance):
        """Initial Balance is the amount that each account should start with."""
        self.balance = initialBalance
        self.trades = []
        self.portfolio = 0


    def add_trade(self, trade):
        """Adds a trade to the exchange (validation required)
        and returns a match if required. It is up to you on how you will
        handle representing trades. """
        self.trades.append(trade)
        trade_cost = trade.quantity * trade.price

        if trade.buy:
            if trade_cost > self.balance:
                print("sell your soul first")
            else:
                self.balance -= trade_cost
                self.portfolio += trade.quantity
        else:
            if self.portfolio < trade.quantity:
                print("retail therapy")
            else:
                self.balance += trade_cost
                self.portfolio -= trade.quantity


