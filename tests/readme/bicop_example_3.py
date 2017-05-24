import pyvinecopulib as pvcl
import numpy as np

bicop = pvcl.bicop(pvcl.gaussian, 0, np.array([[0.5]]))

sim_data = bicop.simulate(100)

pdf = bicop.pdf(sim_data)

h1 = bicop.hfunc1(sim_data)
h2 = bicop.hfunc2(sim_data)

hi1 = bicop.hinv1(sim_data)
hi2 = bicop.hinv2(sim_data)

ll = bicop.loglik(sim_data)
aic = bicop.aic(sim_data)
bic = bicop.bic(sim_data)
