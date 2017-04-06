import pyvinecopulib as pvcl

ctrl = pvcl.bicop_fit_controls(
  pvcl.bicop_families.itau,
  "itau"
)

assert ctrl.parametric_method == "itau"
assert ctrl.family_set == pvcl.bicop_families.itau

assert ctrl.nonparametric_mult == 1.0
assert ctrl.selection_criterion == "bic"
assert ctrl.preselect_families == True
