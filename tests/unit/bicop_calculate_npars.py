import pyvinecopulib as pvcl

bcp = pvcl.bicop(pvcl.indep)
assert bcp.calculate_npars() == 0

bcp = pvcl.bicop(pvcl.gaussian)
assert bcp.calculate_npars() != 0
