import pyvinecopulib as pvcl
import numpy as np

model = pvcl.vinecop(5)

data = model.simulate(100)

pdf = model.pdf(data)

ll = model.loglik(data)

aic = model.aic(data)

bic = model.bic(data)
