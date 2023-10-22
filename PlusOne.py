from typing import List
def plusOne( digits: List[int]) -> List[int]:
    length = len(digits) - 1
    if digits[length] == 9:
        while digits[length] == 9 and length >= 0:
            digits[length] = 0
            length = length - 1
        if length < 0:
            digits[0] = 1
            digits.append(0)
        else:
            digits[length] += 1
    else:
        digits[length] += 1
    return digits

print(plusOne([9, 9, 9, 9, 9]))



        