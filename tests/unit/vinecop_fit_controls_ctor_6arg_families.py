import pyvinecopulib as pvcl

pm = "itau"
mult = 11.
trunc = 3
tcrit = "rho"
thrsh = .44
families = pvcl.bicop_families.two_par
ctrl = pvcl.vinecop_fit_controls(families, pm, mult, trunc, tcrit, thrsh)

assert ctrl.truncation_level == trunc
assert ctrl.threshold == thrsh
assert ctrl.tree_criterion == tcrit
assert ctrl.show_trace == False
assert ctrl.family_set == families

bicop_ctrl = pvcl.bicop_fit_controls()
assert ctrl.parametric_method    == pm
assert ctrl.nonparametric_mult   == mult
assert ctrl.selection_criterion  == bicop_ctrl.selection_criterion
assert ctrl.preselect_families   == bicop_ctrl.preselect_families
