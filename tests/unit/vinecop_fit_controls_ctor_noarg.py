import pyvinecopulib as pvcl

ctrl = pvcl.vinecop_fit_controls()

assert ctrl.truncation_level > 1000
assert ctrl.threshold == 0
assert ctrl.tree_criterion == "tau"
assert ctrl.show_trace == False

bicop_ctrl = pvcl.bicop_fit_controls()
assert ctrl.family_set           == bicop_ctrl.family_set
assert ctrl.parametric_method    == bicop_ctrl.parametric_method
assert ctrl.nonparametric_mult   == bicop_ctrl.nonparametric_mult
assert ctrl.selection_criterion  == bicop_ctrl.selection_criterion
assert ctrl.preselect_families   == bicop_ctrl.preselect_families