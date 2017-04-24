import pyvinecopulib as pvcl

assert pvcl.get_family_name(pvcl.indep)    == "Independence"
assert pvcl.get_family_name(pvcl.gaussian) == "Gaussian"
assert pvcl.get_family_name(pvcl.student)  == "Student"
assert pvcl.get_family_name(pvcl.clayton)  == "Clayton"
assert pvcl.get_family_name(pvcl.gumbel)   == "Gumbel"
assert pvcl.get_family_name(pvcl.frank)    == "Frank"
assert pvcl.get_family_name(pvcl.joe)      == "Joe"
assert pvcl.get_family_name(pvcl.bb1)      == "BB1"
assert pvcl.get_family_name(pvcl.bb6)      == "BB6"
assert pvcl.get_family_name(pvcl.bb7)      == "BB7"
assert pvcl.get_family_name(pvcl.bb8)      == "BB8"
assert pvcl.get_family_name(pvcl.tll0)     == "TLL0"

try:
  pvcl.get_family_name(44)
  assert False
except Exception as ex:
  print ex
