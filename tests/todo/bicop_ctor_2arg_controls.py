import pyvinecopulib as pvcl
import numpy as np

data = pvcl.simulate_uniform(100, 2)
bicop = pvcl.bicop(data, pvcl.bicop_fit_controls())
assert bicop.family == pvcl.indep
assert bicop.rotation == 0
assert bicop.parameters == None

try:
  bicop = pvcl.bicop(pvcl.joe, pvcl.bicop_fit_controls())
  assert False
except Exception as ex:
  print(ex)

try:
  bicop = pvcl.bicop(np.array([1,2,3]), pvcl.bicop_fit_controls())
  assert False
except Exception as ex:
  print(ex)

try:
  bicop = pvcl.bicop(np.array([1.,2,3]), pvcl.bicop_fit_controls())
  assert False
except Exception as ex:
  print(ex)
