import pyvinecopulib as pvcl

ctrl = pvcl.bicop_fit_controls(44.)

assert ctrl.family_set == pvcl.bicop_families.all

assert ctrl.parametric_method == "mle"

assert ctrl.nonparametric_mult == 44.0

assert ctrl.selection_criterion == "bic"

assert ctrl.preselect_families == True
