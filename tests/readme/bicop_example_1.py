import pyvinecopulib as pvcl
import numpy as np

bicop = pvcl.bicop(pvcl.gaussian, 0, np.array([[.5]]))
data = bicop.simulate(1000)

fitted = pvcl.bicop(pvcl.gaussian)
fitted.fit(data)

print("estimated parameter: ")
print(fitted.parameters)

fitted = pvcl.bicop(pvcl.student)
fitted.fit(data)

print("estimated parameter: ")
print(fitted.parameters)

fitted.select(data)
print("family: ")
print(fitted.family)
print("rotation: ")
print(fitted.rotation)
