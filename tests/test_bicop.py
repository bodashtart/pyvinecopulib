import pyvinecopulib as pvcl
import numpy as np

bicop = pvcl.bicop()
print(bicop.family)


bicop = pvcl.bicop(pvcl.bb8)
assert bicop.family == pvcl.bb8

bicop = pvcl.bicop(pvcl.bb8, 90)
assert bicop.family == pvcl.bb8
assert bicop.rotation == 90

bicop = pvcl.bicop(pvcl.gaussian, 0, np.zeros((1,1),dtype=np.double)+1e-3)
data = bicop.simulate(100)

#bicop = pvcl.bicop(pvcl.BicopFamily.gaussian, 90, [1])
#assert bicop.family == pvcl.BicopFamily.gaussian
#assert len(bicop.parameters) == 1 
#assert bicop.parameters[0] == 1
#assert bicop.rotation == 90
