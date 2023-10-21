from typing import List
def searchInsert(nums: List[int], target: int) -> int:
    for index, elem in enumerate(nums):
        if elem >= target:
            return index
    
    if nums[len(nums) - 1] < target:
        return len(nums)

    return -1
        

print(searchInsert([1, 2, 3, 4, 5], 6))