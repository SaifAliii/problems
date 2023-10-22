def lengthOfLastWord(s: str) -> int:
    index = len(s) - 1
    count = 0
    flag = False
    if s[index] == ' ':
        while s[index] == ' ' and  index > 0:
            index = index - 1
    while s[index] != ' ' and  index >= 0:
        index = index - 1
        count = count + 1
    return count

print("The length of last world: ", lengthOfLastWord("Hello moon       "))