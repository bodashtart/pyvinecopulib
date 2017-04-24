import pyvinecopulib as pvcl

d = 5
data = pvcl.simulate_uniform(100, d)
model = pvcl.vinecop(d)
model.select_all(data)
