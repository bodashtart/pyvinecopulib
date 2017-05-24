import pyvinecopulib as pvcl

pm = "itau"
mult = 11.
trunc = 3
families = pvcl.bicop_families.two_par
ctrl = pvcl.vinecop_fit_controls(families, pm, mult, trunc)

assert ctrl.truncation_level == trunc
assert ctrl.threshold == 0
assert ctrl.tree_criterion == "tau"
assert ctrl.show_trace == False
assert ctrl.family_set == families

bicop_ctrl = pvcl.bicop_fit_controls()
assert ctrl.parametric_method    == pm
assert ctrl.nonparametric_mult   == mult
assert ctrl.selection_criterion  == bicop_ctrl.selection_criterion
assert ctrl.preselect_families   == bicop_ctrl.preselect_families
