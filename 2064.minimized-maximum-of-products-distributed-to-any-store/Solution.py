class Solution:
    def minimizedMaximum(self, n: int, quantities: List[int]) -> int:
        b = 1
        e = sum(quantities)
        while b < e:
            mid = (b + e) // 2
            stores = 0
            for q in quantities:
                stores += (q + mid - 1) // mid
            
            if stores <= n:
                e = mid
            else:
                b = mid + 1
        return e
