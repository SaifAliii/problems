
def countPrimes(n: int) -> int:
    if (n == 0 or n == 1):
        return 0
    table = [True] * n
    table[0] = table[1] = False
    for i in range(2, n):
        if table[i] is True:
            j = i * 2
            while j < n:
                table[j] = False
                j = j + i
    return table.count(True)


print(countPrimes(10))
