
import sys

# Importing vtk initializes vtkPythonMap owned by vtkPythonUtil and prevent 
# call to vtkPythonUtil::GetObjectFromPointer() from segfaulting.
# PythonQt internally uses vtkPythonUtil to properly wrap/unwrap VTK objects
from vtk import *

t = _testWrappedVTKSlotInstance.getTable()
print t.GetClassName()

t2 = vtkTable()
_testWrappedVTKSlotInstance.setTable(t2)
if _testWrappedVTKSlotInstance.getTable() != t2:
  sys.exit(1)
  
sys.exit(0)
