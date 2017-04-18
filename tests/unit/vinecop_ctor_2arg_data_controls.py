import pyvinecopulib as pvcl
import numpy as np

data = np.array([[1., 2., 3.]])
ctrl = pvcl.vinecop_fit_controls()
vcp = pvcl.vinecop(data, ctrl)

