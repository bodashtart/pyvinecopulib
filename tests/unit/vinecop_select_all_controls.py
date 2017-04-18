import pyvinecopulib as pvcl

d = 5
data = pvcl.simulate_uniform(100, d)
model = pvcl.vinecop(d)
ctrl = pvcl.vinecop_fit_controls()
model.select_all(data, ctrl)
