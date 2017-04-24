import pyvinecopulib as pvcl

n = 9

model = pvcl.vinecop(n)

pcs = model.all_pair_copulas

assert len(pcs) == n-1
