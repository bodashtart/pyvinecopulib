import pyvinecopulib as pvcl

n = 111

model = pvcl.bicop()
data = model.simulate(n)


fitted = pvcl.bicop()
ctrl = pvcl.bicop_fit_controls()
fitted.select(data, ctrl)

assert len(data.shape) == 2
assert data.shape[0] == 2
assert data.shape[1] == n
