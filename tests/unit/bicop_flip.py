import pyvinecopulib as pvcl

bicop = pvcl.bicop(pvcl.clayton)

bicop.rotation = 90
bicop.flip()
assert bicop.rotation == 270
