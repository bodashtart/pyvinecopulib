import pyvinecopulib as pvcl

d = 5
n = 100

model = pvcl.vinecop(d)
data = model.simulate(n)

assert len(data.shape) == 2
assert data.shape[0] == d
assert data.shape[1] == n
