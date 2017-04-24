import pyvinecopulib as pvcl
import numpy as np

param = .5

model = pvcl.bicop(pvcl.gaussian, 0, np.array([[param]]))
data = model.simulate(1000);

fitted = pvcl.bicop(pvcl.gaussian)
ctrl = pvcl.bicop_fit_controls()
fitted.fit(data, ctrl);

print abs(fitted.parameters[0][0] - param) / param < .01
