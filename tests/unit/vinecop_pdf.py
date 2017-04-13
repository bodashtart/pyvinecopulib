import pyvinecopulib as pvcl

d = 5
n = 100

model = pvcl.vinecop(d)
data = model.simulate(n)

pdf = model.pdf(data)

assert len(pdf) == n
