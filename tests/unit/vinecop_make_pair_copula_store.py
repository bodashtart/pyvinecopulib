import pyvinecopulib as pvcl

pcs = pvcl.vinecop.make_pair_copula_store(4)
assert len(pcs) == 3
assert len(pcs[0]) == 3
assert len(pcs[1]) == 2
assert len(pcs[2]) == 1

try:
  pvcl.vinecop.make_pair_copula_store()
  assert False
except Exception as ex:
  print ex
