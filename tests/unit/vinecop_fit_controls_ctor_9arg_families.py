import pyvinecopulib as pvcl

pm = "itau"
mult = 11.
trunc = 3
tcrit = "rho"
thrsh = .44
scrit = "bic"
preselect = False
trace = True
families = pvcl.bicop_families.two_par
ctrl = pvcl.vinecop_fit_controls(families, pm, mult, trunc, tcrit, thrsh, scrit, preselect, trace)

assert ctrl.truncation_level == trunc
assert ctrl.threshold == thrsh
assert ctrl.tree_criterion == tcrit
assert ctrl.show_trace == trace
assert ctrl.family_set == families

bicop_ctrl = pvcl.bicop_fit_controls()
assert ctrl.parametric_method    == pm
assert ctrl.nonparametric_mult   == mult
assert ctrl.selection_criterion  == scrit
assert ctrl.preselect_families   == preselect
