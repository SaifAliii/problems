from typing import List


def productExceptSelf(nums: List[int]) -> List[int]:
    result = []
    result.append(1)
    rightSum = 1
    i = 0
    j = len(nums) - 1
    while (i < len(nums) - 1):
        result.append(nums[i] * result[i])
        i += 1
    while (j >= 0):
        result[j] = result[j] * rightSum
        rightSum = rightSum * nums[j]
        j -= 1
    return result


nums = [-1, 1, 0,  3, -3]
print(productExceptSelf(nums))
