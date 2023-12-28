from typing import List
def minCostClimbingStairs(cost: List[int]) -> int:
    previous1 = cost[0]
    previous2 = cost[1]
    index = 2
    min = 0
    length = len(cost)
    while index < length:
        if (previous1 + cost[index]) < previous2:
            min = min + previous1 + cost[index]
        elif (previous2 + cost[index]) < previous1:
            min = min + previous2 + cost[index]
        

        if index + 1 < length:
            previous1 = cost[index + 1]
        if index + 2 < length:
            previous2 = cost[index + 2]
        index = index + 1
    return min

print("The min cost for climbing stairs: ", [10, 15, 20])