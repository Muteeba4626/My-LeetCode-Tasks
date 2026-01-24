class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices:
            return 0
        
        # Initialize states
        # buy1 and buy2 are negative because they represent spending money
        buy1, buy2 = -float('inf'), -float('inf')
        sell1, sell2 = 0, 0
        
        for price in prices:
            # First transaction: maximize profit
            buy1 = max(buy1, -price)          # Least cost to buy
            sell1 = max(sell1, buy1 + price)   # Max profit after selling first stock
            
            # Second transaction: utilize profit from first transaction
            buy2 = max(buy2, sell1 - price)    # Max money left after buying second stock
            sell2 = max(sell2, buy2 + price)   # Max total profit after selling second stock
            
        return sell2