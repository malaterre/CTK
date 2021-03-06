
SET(KIT_TESTS ${CPP_TEST_PATH}/ctkSimplePythonShell)

SET(SCRIPTS
  wrappedQInvokableTest.py
  wrappedQPropertyTest.py
  wrappedSlotTest.py
  )

# Since QTimer is part of QtCore and is used in both 'ctkWidgetsTest.py' and 'derivedQWidgetTest.py', 
# these two tests should be included only if CTK_LIB_Scripting/Python/Core_PYTHONQT_WRAP_QTCORE is ON

IF(CTK_LIB_Widgets AND CTK_LIB_Scripting/Python/Core_PYTHONQT_WRAP_QTCORE)
  LIST(APPEND SCRIPTS ctkWidgetsTest.py)
ENDIF()

IF(CTK_LIB_Scripting/Python/Core_PYTHONQT_WRAP_QTCORE AND CTK_LIB_Scripting/Python/Core_PYTHONQT_WRAP_QTGUI)
  LIST(APPEND SCRIPTS derivedQWidgetTest.py)
ENDIF()

IF(CTK_LIB_Scripting/Python/Core_PYTHONQT_USE_VTK)
  LIST(APPEND SCRIPTS
    vtkPythonSmoke.py
    wrappedVTKQInvokableTest.py
    wrappedVTKSlotTest.py
    )
ENDIF()


MACRO(SIMPLE_TEST_WITH_SCRIPT SCRIPT)
  GET_FILENAME_COMPONENT(TESTNAME ${SCRIPT} NAME_WE)
  ADD_TEST(ctkSimplePythonShell_${TESTNAME} ${KIT_TESTS} ${CMAKE_CURRENT_SOURCE_DIR}/${SCRIPT})
ENDMACRO()

FOREACH(s ${SCRIPTS})
  SIMPLE_TEST_WITH_SCRIPT(${s})
ENDFOREACH()
