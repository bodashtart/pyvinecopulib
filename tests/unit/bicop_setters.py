import pyvinecopulib as pvcl
import numpy as np

bicop = pvcl.bicop(pvcl.bb8)

assert bicop.rotation != 180
bicop.rotation = 180
assert bicop.rotation == 180

params = np.array([[44.,.44]])
assert not np.array_equal(params, bicop.parameters)
bicop.parameters = params
assert np.array_equal(params, bicop.parameters)
