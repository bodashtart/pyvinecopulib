import pyvinecopulib as pvcl

vcop = pvcl.vinecop(3)

try:
  vcop.pair_copula(0,0) = pvcl.bicop()
except Exception as ex:
  print ex

try:
  vcop.family(0,0) = pvcl.gaussian
except Exception as ex:
  print ex

try:
  vcop.rotation(0,0) = 180
except Exception as ex:
  print ex

try:
  vcop.parameters = None
except Exception as ex:
  print ex

try:
  vcop.matrix = None
except Exception as ex:
  print ex
