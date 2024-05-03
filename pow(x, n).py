class Solution:
    def myPow(self, x: float, n: int) -> float:
        def helper(x: float, n: int) -> float:
            if x == 0:
                return 0
            if n == 1:
                return x
            res = helper(x, n//2)
            res = res * res
            if n % 2 != 0:
                res *= x
            return res
        res = helper(x, abs(n))
        if n <= 0:
            return res
        else:
            return 1 / res


print(pow(2.10000, 3))
