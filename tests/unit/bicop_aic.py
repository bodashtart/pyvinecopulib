import pyvinecopulib as pvcl
import numpy as np
import math

bcp = pvcl.bicop(pvcl.gaussian, 0, np.array([[0.5]]));

sdt = bcp.simulate(100)

aic  = bcp.aic(sdt);

assert type(aic) == float
assert not math.isinf(aic)
assert not math.isnan(aic)
assert aic != bcp.bic(sdt)
