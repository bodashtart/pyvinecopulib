import pyvinecopulib as pvcl

model = pvcl.vinecop(3)

fams = model.all_families()

print len(fams)
