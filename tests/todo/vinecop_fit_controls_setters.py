import pyvinecopulib as pvcl

ctrl = pvcl.vinecop_fit_controls()

tl = 3
assert ctrl.truncation_level != tl
ctrl.truncation_level = tl
assert ctrl.truncation_level == tl

tc = "rho"
assert ctrl.tree_criterion != tc
ctrl.tree_criterion = tc
assert ctrl.tree_criterion == tc

th = .44
assert ctrl.threshold != th
ctrl.threshold = th
assert ctrl.threshold == th

st = True
assert ctrl.show_trace != st
ctrl.show_trace = st
assert ctrl.show_trace == st

fset = [pvcl.gaussian, pvcl.bb8]
assert len(fset) != len(ctrl.family_set)
ctrl.family_set = fset
assert fset == ctrl.family_set

parametric_method = "itau"
assert ctrl.parametric_method != parametric_method
ctrl.parametric_method = parametric_method
assert ctrl.parametric_method == parametric_method

nonparametric_mult = 2.
assert ctrl.nonparametric_mult != nonparametric_mult
ctrl.nonparametric_mult = nonparametric_mult
assert ctrl.nonparametric_mult == nonparametric_mult

selection_criterion = "aic"
assert ctrl.selection_criterion != selection_criterion
ctrl.selection_criterion = selection_criterion
assert ctrl.selection_criterion == selection_criterion

preselect_families = False
assert ctrl.preselect_families != preselect_families
ctrl.preselect_families = preselect_families
assert ctrl.preselect_families == preselect_families


assert ctrl.fit_controls_bicop.parametric_method == parametric_method
assert ctrl.fit_controls_bicop.nonparametric_mult == nonparametric_mult
assert ctrl.fit_controls_bicop.selection_criterion == selection_criterion
assert ctrl.fit_controls_bicop.preselect_families == preselect_families

bicop = pvcl.fit_controls_bicop()

assert ctrl.fit_controls_bicop.parametric_method != parametric_method
assert ctrl.fit_controls_bicop.nonparametric_mult != nonparametric_mult
assert ctrl.fit_controls_bicop.selection_criterion != selection_criterion
assert ctrl.fit_controls_bicop.preselect_families != preselect_families
