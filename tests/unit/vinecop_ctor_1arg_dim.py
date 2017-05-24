import pyvinecopulib as pvcl
import numpy as np

d = 4
vcop = pvcl.vinecop(d)
assert np.array_equal(vcop.matrix, np.array([
 [3, 2, 1, 4],
 [2, 1, 3, 0],
 [1, 2, 0, 0],
 [1, 0, 0, 0]
]))
