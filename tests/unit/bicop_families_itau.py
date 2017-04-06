import pyvinecopulib as pvcl

assert [
  pvcl.indep,
  pvcl.gaussian,
  pvcl.student,
  pvcl.clayton,
  pvcl.gumbel,
  pvcl.frank,
  pvcl.joe
] == pvcl.bicop_families.itau
