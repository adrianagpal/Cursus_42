import numpy as np
import random

class MazeGenerator():
    def __init__(self, size: tuple[int, int], seed: int = 42):
        self.size = size
        self.seed = seed

    def generate(self, entry, exit_coord):
        np.random.seed(self.seed)

        # Creates a matrix of zeros
        mat = np.zeros(self.size, dtype=int)
        #mat[entry[0], entry[1]] = 16
        #mat[exit_coord[0], exit_coord[1]] = 17
        
        #pad_mat = np.pad(mat, pad_width=1, mode='constant', constant_values=15)

        return mat
    
    def paint_42(self, mat):
        n_blocks = 3
        space = 1
        n_width = n_blocks * 2 + space
        n_height = n_width - n_blocks + 1

        start = int(self.size[0]/3), int(self.size[1]/3)

        for i in range(0, n_blocks):
            mat[start[0] + i][start[1]] = 15
            mat[start[0] + n_blocks - 1][start[1] + i] = 15
            mat[start[0] + n_blocks + i - 1][start[1] + n_blocks - 1] = 15
        
        for j in range(0, n_blocks):
            mat[start[0]][start[1] + n_blocks + j + space] = 15
            mat[start[0] + j][start[1] + 2 * n_blocks] = 15
            mat[start[0] + n_blocks - 1][start[1] + n_blocks + space + j] = 15
            mat[start[0] + n_blocks + j - 1][start[1] + n_blocks + space] = 15
            mat[start[0] + 2 * n_blocks - 2][start[1] + n_blocks + space + j] = 15         

        return mat
