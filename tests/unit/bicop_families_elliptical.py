import pyvinecopulib as pvcl

assert [
  pvcl.gaussian,
  pvcl.student,
] == pvcl.bicop_families.elliptical
