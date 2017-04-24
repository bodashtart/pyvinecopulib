import pyvinecopulib as pvcl

bcp = pvcl.bicop(pvcl.clayton)
prm = bcp.tau_to_parameters(.44)

assert len(prm) == 1
