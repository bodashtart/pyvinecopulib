import pyvinecopulib as pvcl
import numpy as np

n = 100
d = 3
data = pvcl.simulate_uniform(n, d)

assert len(data.shape) == 2
assert data.shape[0] == d
assert data.shape[1] == n
assert np.amin(data) >= 0
assert np.amax(data) < 1
