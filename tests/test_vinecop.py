import pyvinecopulib as pvcl
import numpy as np

# no-arg ctor
vinecop = pvcl.vinecop()

# 1-arg ctor
vinecop = pvcl.vinecop(10)

# 2-arg ctor
vinecop = pvcl.vinecop([
  [pvcl.bicop(pvcl.BicopFamily.clayton, 90), pvcl.bicop(pvcl.student,              0), pvcl.bicop(pvcl.BicopFamily.clayton, 270) ],
  [pvcl.bicop(pvcl.BicopFamily.student    ), pvcl.bicop(pvcl.BicopFamily.gaussian, 0)                          ],
  [pvcl.bicop(pvcl.BicopFamily.gaussian   )                                                     ]
], np.array([
  [1,1,1,1],
  [1,1,1,0],
  [1,1,0,0],
  [1,0,0,0]
], dtype=np.uint64))

# accessors
print(vinecop.rotation(1,1))
#print(vinecop.all_rotations)
print(vinecop.parameters(0,1))
print(vinecop.family(0,0))
#print(vinecop.all_families)
print(vinecop.matrix)
#print(vinecop.pair_copula(0,0)) 

# simulate
#data = vinecop.simulate(100)

# inverse_rosenblatt
#data = vinecop.inverse_rosenblatt(np.array([
#  [ 1, 2, 3], 
#  [ 4, 5, 6], 
#  [ 7, 8, 9], 
#  [10,11,12]
#], dtype=np.double));

#
#vinecop.select_all(np.array([
#  [ 1, 2, 3], 
#  [ 4, 5, 6], 
#  [ 7, 8, 9], 
#  [10,11,12]
#],dtype=np.double))
