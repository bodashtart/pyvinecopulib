import pyvinecopulib as pvcl
import numpy as np

mtx = np.array([
  [1, 2, 3],
  [1, 2, 3],
  [1, 2, 3],
], dtype=np.uint64)
vcp = pvcl.vinecop(mtx)

assert np.array_equal(mtx, vcp.matrix)
