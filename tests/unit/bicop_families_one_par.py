import pyvinecopulib as pvcl

assert [
  pvcl.gaussian,
  pvcl.clayton,
  pvcl.gumbel,
  pvcl.frank,
  pvcl.joe,
] == pvcl.bicop_families.one_par
