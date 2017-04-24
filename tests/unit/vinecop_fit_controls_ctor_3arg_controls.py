import pyvinecopulib as pvcl

bctrl = pvcl.bicop_fit_controls(pvcl.bicop_families.itau, "itau", 44, "aic", False)
vctrl = pvcl.vinecop_fit_controls(bctrl, 3, "rho")

assert vctrl.truncation_level == 3
assert vctrl.threshold == 0
assert vctrl.tree_criterion == "rho"
assert vctrl.show_trace == False

assert vctrl.family_set           == bctrl.family_set
assert vctrl.parametric_method    == bctrl.parametric_method
assert vctrl.nonparametric_mult   == bctrl.nonparametric_mult
assert vctrl.selection_criterion  == bctrl.selection_criterion
assert vctrl.preselect_families   == bctrl.preselect_families
