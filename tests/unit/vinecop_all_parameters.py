import pyvinecopulib as pvcl

model = pvcl.vinecop(3)

prms = model.all_parameters()

print len(prms)
