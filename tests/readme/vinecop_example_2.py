import pyvinecopulib as pvcl
import numpy as np

d = 5

data = pvcl.simulate_uniform(100, d)

model = pvcl.vinecop(d)
model.select_families(data)

model.select_all(data)
