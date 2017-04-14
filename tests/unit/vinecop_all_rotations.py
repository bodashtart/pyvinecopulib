import pyvinecopulib as pvcl

model = pvcl.vinecop(3)

rots = model.all_rotations()

print len(rots)
