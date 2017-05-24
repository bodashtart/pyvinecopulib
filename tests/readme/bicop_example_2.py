import pyvinecopulib as pvcl
import numpy as np

model = pvcl.bicop(pvcl.gaussian, 0, np.array([[0.5]]));             
data = model.simulate(100);

best_archimedean = pvcl.bicop(data, pvcl.bicop_fit_controls(pvcl.bicop_families.archimedean))

best_itau = pvcl.bicop(data, pvcl.bicop_fit_controls(pvcl.bicop_families.itau, "itau", 1.0, "aic"))
