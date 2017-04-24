import pyvinecopulib as pvcl
import numpy as np

n = 100

model = pvcl.bicop(pvcl.gaussian, 0, np.array([[.5]]))
data = model.simulate(n)
pdf = model.pdf(data)

assert len(pdf) == n
