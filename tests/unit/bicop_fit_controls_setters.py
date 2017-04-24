import pyvinecopulib as pvcl

ctrl = pvcl.bicop_fit_controls()

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
