import pyvinecopulib as pvcl

assert [
  pvcl.indep,
  pvcl.gaussian,
  pvcl.student,
  pvcl.clayton,
  pvcl.gumbel,
  pvcl.frank,
  pvcl.joe,
  pvcl.bb1,
  pvcl.bb6,
  pvcl.bb7,
  pvcl.bb8,
  pvcl.tll0
] == pvcl.bicop_families.all
