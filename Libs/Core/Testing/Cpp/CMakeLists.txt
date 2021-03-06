# Dummy plugin used by ctkAbstractPluginFactoryTest1
ADD_DEFINITIONS( -DCTKDummyPlugin)
ctkMacroBuildLib(
  NAME "CTKDummyPlugin"
  EXPORT_DIRECTIVE "CTK_DUMMY_EXPORT"
  SRCS ctkDummyPlugin.h ctkDummyPlugin.cpp
  MOC_SRCS "ctkDummyPlugin.h"
  TARGET_LIBRARIES ${CTK_BASE_LIBRARIES}
  LIBRARY_TYPE "SHARED"
  DISABLE_WRAP_PYTHONQT
  )
GET_TARGET_PROPERTY(ctkDummyPluginPATH "CTKDummyPlugin" LOCATION)
REMOVE_DEFINITIONS(-DCTKDummyPlugin)



SET(KIT ${PROJECT_NAME})

#
# Test sources
#
SET(KITTests_SRCS
  ctkAbstractFactoryTest1.cpp
  ctkAbstractLibraryFactoryTest1.cpp
  ctkAbstractObjectFactoryTest1.cpp
  ctkAbstractPluginFactoryTest1.cpp
  ctkAbstractQObjectFactoryTest1.cpp
  ctkCommandLineParserTest1.cpp
  ctkModelTesterTest1.cpp
  ctkUtilsTest1.cpp
  ctkUtilsTest2.cpp
  ctkDependencyGraphTest1.cpp
  ctkDependencyGraphTest2.cpp
  ctkPimplTest1.cpp
  ctkSingletonTest1.cpp
  ctkWorkflowTest1.cpp
  ctkWorkflowTest2.cpp
  ctkWorkflowTest3.cpp
  )

IF(HAVE_BFD)
  LIST(APPEND KITTests_SRCS
    ctkBinaryFileDescriptorTest1.cpp
    )
ENDIF()

CREATE_TEST_SOURCELIST(Tests ${KIT}CppTests.cpp
  ${KITTests_SRCS}
  #EXTRA_INCLUDE TestingMacros.h
  )

SET (TestsToRun ${Tests})
REMOVE (TestsToRun ${KIT}CppTests.cpp)

SET(LIBRARY_NAME ${PROJECT_NAME})

#
# Tests Helpers sources
#
SET(Tests_Helpers_SRCS
  ctkBranchingWorkflowStep.h
  ctkExampleDerivedWorkflowStep.cpp
  ctkExampleDerivedWorkflowStep.h
  ctkExampleWorkflowStepUsingSignalsAndSlots.cpp
  ctkExampleWorkflowStepUsingSignalsAndSlots.h
  ctkSingletonTestHelper.cpp
  ctkSingletonTestHelper.h
  )

SET(Tests_Helpers_MOC_SRCS
  ctkExampleWorkflowStepUsingSignalsAndSlots.h
  )

SET(Tests_Helpers_MOC_CPP)
QT4_WRAP_CPP(Tests_Helpers_MOC_CPP ${Tests_Helpers_MOC_SRCS})

IF(HAVE_BFD)
  ADD_EXECUTABLE(ctkBinaryFileDescriptorTestHelper ctkBinaryFileDescriptorTestHelper.cpp)
ENDIF()

#
# Test executable
#
ADD_EXECUTABLE(${KIT}CppTests ${Tests} ${Tests_Helpers_SRCS} ${Tests_Helpers_MOC_CPP})
TARGET_LINK_LIBRARIES(${KIT}CppTests ${LIBRARY_NAME} ${CTK_BASE_LIBRARIES} CTKDummyPlugin)

SET( KIT_TESTS ${CPP_TEST_PATH}/${KIT}CppTests)

MACRO( SIMPLE_TEST  TESTNAME )
  ADD_TEST( ${TESTNAME} ${KIT_TESTS} ${TESTNAME} )
  SET_PROPERTY(TEST ${TESTNAME} PROPERTY LABELS ${PROJECT_NAME})
ENDMACRO( SIMPLE_TEST  )

#
# Add Tests
#

SIMPLE_TEST( ctkAbstractFactoryTest1 )
ADD_TEST( ctkAbstractLibraryFactoryTest1 ${KIT_TESTS} ctkAbstractLibraryFactoryTest1 ${ctkDummyPluginPATH})
SET_PROPERTY(TEST ctkAbstractLibraryFactoryTest1 PROPERTY LABELS ${PROJECT_NAME})
SIMPLE_TEST( ctkAbstractObjectFactoryTest1 )
ADD_TEST( ctkAbstractPluginFactoryTest1 ${KIT_TESTS} ctkAbstractPluginFactoryTest1 ${ctkDummyPluginPATH})
SET_PROPERTY(TEST ctkAbstractPluginFactoryTest1 PROPERTY LABELS ${PROJECT_NAME})
SIMPLE_TEST( ctkAbstractQObjectFactoryTest1 )
IF(HAVE_BFD)
  ADD_TEST(NAME ctkBinaryFileDescriptorTest1 COMMAND ${KIT_TESTS} ctkBinaryFileDescriptorTest1 $<TARGET_FILE:ctkBinaryFileDescriptorTestHelper>)
  SET_PROPERTY(TEST ctkBinaryFileDescriptorTest1 PROPERTY LABELS ${PROJECT_NAME})
ENDIF()
SIMPLE_TEST( ctkCommandLineParserTest1 )
SIMPLE_TEST( ctkDependencyGraphTest1 )
SIMPLE_TEST( ctkDependencyGraphTest2 )
SIMPLE_TEST( ctkModelTesterTest1 )
SIMPLE_TEST( ctkPimplTest1 )
SIMPLE_TEST( ctkSingletonTest1 )
SIMPLE_TEST( ctkUtilsTest1 )
SIMPLE_TEST( ctkUtilsTest2 )
SIMPLE_TEST( ctkWorkflowTest1 )
SIMPLE_TEST( ctkWorkflowTest2 )
SIMPLE_TEST( ctkWorkflowTest3 )
