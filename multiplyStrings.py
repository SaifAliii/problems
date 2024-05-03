class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        if "0" in [num1, num2]:
            return "0"
        num1Length = len(num1)
        num2Length = len(num2)
        result = [0] * (num1Length + num2Length)
        num1, num2 = num1[:: -1], num2[:: -1]
        for i in range(num1Length):
            for j in range(num2Length):
                answer = int(num1[i]) * int(num2[j])
                result[i + j] += answer % 10
                result[i + j + 1] += (answer) // 10
                if result[i + j] > 9:
                    digit = result[i + j]
                    result[i + j] = digit % 10
                    result[i + j + 1] += digit // 10
                #     if result[i + j + 1] > 9:
                #         result[i + j + 2] += result[i+ j + 1] // 10
        for i in range(num1Length + num2Length - 1, 0, -1):
            print(i)
            if (result[i] == 0):
                result.pop()
            else:
                break
        print(result)
        result = result[:: -1]
        stringList = ""
        for i in range(0, len(result)):
            stringList += str(result[i])
        result = ''.join(stringList)
        print(result)
        print(num1, num2)

