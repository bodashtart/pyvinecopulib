import pyvinecopulib as pvcl
import numpy as np
import math

bcp = pvcl.bicop(pvcl.gaussian, 0, np.array([[0.5]]));

sdt = bcp.simulate(100)

bic  = bcp.bic(sdt);

assert type(bic) == float
assert not math.isinf(bic)
assert not math.isnan(bic)
assert bic != bcp.aic(sdt)
