import pyvinecopulib as pvcl
import numpy as np

d = 4

data = pvcl.simulate_uniform(100, d)

best_vine = pvcl.vinecop(data)

M = np.array([
    [1, 1, 1, 1],
    [2, 2, 2, 0],
    [3, 3, 0, 0],
    [4, 0, 0, 0],
], dtype=np.uint64)

custom_vine = pvcl.vinecop(data, M, pvcl.vinecop_fit_controls(pvcl.bicop_families.itau, "itau", 1.0, 2))
