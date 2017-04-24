import pyvinecopulib as pvcl
import numpy as np

d = 3

default_model = pvcl.vinecop(d)

pair_copulas = pvcl.vinecop.make_pair_copula_store(d)

par = np.array([[3.]])
for tree in pair_copulas:
    for idx in xrange(len(tree)):
        tree[idx] = pvcl.bicop(pvcl.clayton, 270, par)

mat = np.array([
    [1, 1, 1],
    [2, 2, 0],
    [3, 0, 0]
], dtype=np.uint64)

custom_model = pvcl.vinecop(pair_copulas, mat)
