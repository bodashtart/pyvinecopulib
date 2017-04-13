import pyvinecopulib as pvcl

n = 100

model = pvcl.bicop()
data = model.simulate(n);

assert len(data.shape) == 2
assert data.shape[0] == 2
assert data.shape[1] == n
