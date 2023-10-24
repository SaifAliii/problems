def mySqrt( x: int) -> int:
    if x == 0 or x == 1:
        return x
    start, end, root = 0, x, 0
    mid = 0
    while start <= end:
        mid = (start + end) // 2
        if mid * mid == x:
            return mid
        elif mid * mid < x:
            start = mid + 1
            root = mid
        else:
            end = mid - 1
    return root

print("The Square root is:", mySqrt(16))
