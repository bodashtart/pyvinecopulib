import pyvinecopulib as pvcl
import numpy as np

n = 100

bcp = pvcl.bicop(pvcl.gaussian, 0, np.array([[.5]]))
sim_data = bcp.simulate(n)
ll = bcp.loglik(sim_data)

assert type(ll) == float
