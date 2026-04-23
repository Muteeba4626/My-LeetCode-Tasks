class Solution:
    def isNumber(self, s: str) -> bool:
        digit = False
        dot = False
        exp = False
        
        for i, ch in enumerate(s):
            
            if ch.isdigit():
                digit = True
            
            elif ch in ['+', '-']:
                
                if i > 0 and s[i-1] not in ['e', 'E']:
                    return False
            
            elif ch == '.':
                
                if dot or exp:
                    return False
                dot = True
            
            elif ch in ['e', 'E']:
                
                if exp or not digit:
                    return False
                exp = True
                digit = False   
            else:
                return False
        
        return digit