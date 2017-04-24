import pyvinecopulib as pvcl
import numpy as np

d = 5

vinecop = pvcl.vinecop(d)

u = np.array([
  [1.,2.,3.],
  [1.,2.,3.],
  [1.,2.,3.],
  [1.,2.,3.],
  [1.,2.,3.]
])

m = vinecop.inverse_rosenblatt(u)

assert len(m.shape) == 2
assert m.shape[0] == 5
assert m.shape[1] == 3
