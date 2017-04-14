import pyvinecopulib as pvcl
import numpy as np

n = 100

bcp = pvcl.bicop(pvcl.gaussian, 0, np.array([[.5]]))
sim_data = bcp.simulate(n)
h2 = bcp.hfunc1(sim_data)

assert len(h2) == n
