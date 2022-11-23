class Solution:
    def numberOfPatterns(self, m: int, n: int) -> int:        
        mp = {(1, 3): 2, (1, 7): 4, (1, 9): 5, (2, 8): 5, (3, 7): 5, (3, 9): 6, (4, 6): 5, (7, 9): 8, \
              (3, 1): 2, (7, 1): 4, (9, 1): 5, (8, 2): 5, (7, 3): 5, (9, 3): 6, (6, 4): 5, (9, 7): 8}
        
        @cache
        def fn(x, mask):
            """Return number of unlock patterns."""
            ans = size = 0 
            for xx in range(1, 10): 
                if not mask & (1 << xx): 
                    if (x, xx) not in mp or mask & 1 << mp[x, xx]: 
                        ans += fn(xx, mask^(1<<xx))
                    size += 1
            size = 9 - size
            if m <= size <= n: ans += 1
            return ans 
        
        return fn(0, 0)