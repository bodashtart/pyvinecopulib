import pyvinecopulib as pvcl
import numpy as np

data = np.array([[1., 2., 3.]])

mtx = np.array([
  [1, 2, 3],
  [1, 2, 3],
  [1, 2, 3],
], dtype=np.uint64)

ctrl = pvcl.vinecop_fit_controls()

vcp = pvcl.vinecop(data, mtx, ctrl)

assert np.array_equal(mtx, vcp.matrix)
