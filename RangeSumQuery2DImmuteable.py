from typing import List


class NumMatrix:
    def __init__(self, matrix: List[List[int]]):
        rows = len(matrix[0][0]) + 1
        cols = len(matrix[0][0][0]) + 1
        self.colMatrix = []
        for i in range(rows):
            rowMatrix = [0] * cols
            self.colMatrix.append(rowMatrix)
        self.result = []
        self.result.append(None)
        for i in range((rows - 1)):
            for j in range((cols - 1)):
                self.colMatrix[i+1][j+1] = matrix[0][0][i][j] + self.colMatrix[i+1][j] + self.colMatrix[i][j+1] - self.colMatrix[i][j]
        for i in range(1, len(matrix)):
            self.result.append(self.sumRegion(matrix[i][0] + 1, matrix[i][1] + 1, matrix[i][2] + 1, matrix[i][3] + 1))

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        return self.colMatrix[row2][col2] - self.colMatrix[row1 - 1][col2] - self.colMatrix[row2][col1 - 1] + self.colMatrix[row1 - 1][col1 - 1]


matrix = NumMatrix([[[[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]]],[2,1,4,3],[1,1,2,2],[1,2,2,4]])
print(matrix.result)
