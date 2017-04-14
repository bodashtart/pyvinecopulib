import pyvinecopulib as pvcl

model = pvcl.vinecop(5)
data = model.simulate(100)
bic = model.bic(data)

assert type(bic) == float
