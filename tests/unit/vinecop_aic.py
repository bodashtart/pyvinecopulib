import pyvinecopulib as pvcl

model = pvcl.vinecop(5)
data = model.simulate(100)
aic = model.aic(data)

assert type(aic) == float
