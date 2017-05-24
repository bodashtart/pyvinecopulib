import pyvinecopulib as pvcl

model = pvcl.vinecop(5)
data = model.simulate(100)
ll = model.loglik(data)

assert type(ll) == float
