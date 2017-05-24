import pyvinecopulib as pvcl

assert [
  pvcl.clayton,
  pvcl.gumbel,
  pvcl.frank,
  pvcl.joe,
  pvcl.bb1,
  pvcl.bb6,
  pvcl.bb7,
  pvcl.bb8
] == pvcl.bicop_families.flip_by_rotation
