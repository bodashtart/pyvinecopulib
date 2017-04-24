import pyvinecopulib as pvcl

bicop = pvcl.bicop(pvcl.joe, 90)

assert bicop.family == pvcl.joe
assert bicop.family_name == pvcl.get_family_name(pvcl.joe)
assert bicop.rotation == 90
print bicop.parameters #TODO!
#assert len(bicop.parameters) == 1
#assert bicop.parameters[0] == 0

try:
  bicop = pvcl.bicop(pvcl.joe, 90.)
  assert False
except Exception as ex:
  print(ex)

try:
  bicop = pvcl.bicop(90, 90)
  assert False
except Exception as ex:
  print(ex)
