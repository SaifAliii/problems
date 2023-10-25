def climbStairs( n: int) -> int:
    if n == 1 or n == 2:
        return n
    first = 1
    second = 2
    temp = 0
    i = 2
    while i < n:
        temp = first
        first = second
        second = temp + second
        i = i + 1 
    return second
 
print("the Unique ways too climb stairs: ", climbStairs(5))