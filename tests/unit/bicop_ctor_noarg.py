import pyvinecopulib as pvcl

bicop = pvcl.bicop()

assert bicop.family == pvcl.indep
assert bicop.family_name == "Independence"
assert bicop.rotation == 0
assert bicop.parameters == None
