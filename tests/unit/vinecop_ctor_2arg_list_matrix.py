import pyvinecopulib as pvcl
import numpy as np

mtx = np.array([
  [1, 2, 3],
  [1, 2, 3],
  [1, 2, 3],
], dtype=np.uint64)

pcs = pvcl.vinecop.make_pair_copula_store(3)

vcp = pvcl.vinecop(pcs, mtx)

assert np.array_equal(mtx, vcp.matrix)
