import pyvinecopulib as pvcl
import numpy as np

m = np.array([[1, 2]], dtype=np.uint64)

vcp = pvcl.vinecop([[pvcl.bicop(pvcl.indep)]], m)
assert vcp.calculate_npars() == 0

vcp = pvcl.vinecop([[pvcl.bicop(pvcl.gaussian)]], m)
assert vcp.calculate_npars() != 0
