import numpy as np
import random

class MazeGenerator():
    def __init__(self, size: tuple[int, int], seed: int = 42):
        self.size = size
        self.seed = seed

    def generate(self):
        np.random.seed(self.seed)

        # Creates a matrix of zeros
        mat = np.zeros(self.size, dtype=int)
        pad_mat = np.pad(mat, pad_width=1, mode='constant', constant_values=15)
        return pad_mat