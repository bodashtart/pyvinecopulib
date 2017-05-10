import pyvinecopulib as pvcl

bcp = pvcl.bicop(pvcl.clayton)
prm = bcp.tau_to_parameters(.44)

tau = bcp.parameters_to_tau(prm)

