import pyvinecopulib as pvcl

bicop = pvcl.bicop(pvcl.gaussian)

assert bicop.family == pvcl.gaussian
assert bicop.family_name == pvcl.get_family_name(pvcl.gaussian)
assert bicop.rotation == 0
assert len(bicop.parameters) == 1
assert bicop.parameters[0] == 0

try:
  bicop = pvcl.bicop(44)
  assert False
except Exception as ex:
  print(ex)
