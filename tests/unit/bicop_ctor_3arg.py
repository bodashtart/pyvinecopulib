import pyvinecopulib as pvcl
import numpy as np

params = np.array([[44.]])
bicop = pvcl.bicop(pvcl.joe, 180, params)

assert bicop.family == pvcl.joe
assert bicop.family_name == pvcl.get_family_name(pvcl.joe)
assert bicop.rotation == 180
assert len(bicop.parameters) == 1
assert bicop.parameters[0] == 44

try:
  bicop = pvcl.bicop(pvcl.joe, 90., np.array([[44]]))
  assert False
except Exception as ex:
  print(ex)

try:
  bicop = pvcl.bicop(pvcl.joe, 90., np.array([[666]]))
  assert False
except Exception as ex:
  print(ex)

try:
  bicop = pvcl.bicop(90, 90, 90)
  assert False
except Exception as ex:
  print(ex)
