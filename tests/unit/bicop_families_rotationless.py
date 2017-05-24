import pyvinecopulib as pvcl

assert [
  pvcl.indep,
  pvcl.gaussian,
  pvcl.student,
  pvcl.frank,
  pvcl.tll0
] == pvcl.bicop_families.rotationless
