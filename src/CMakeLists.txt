FILE (GLOB_RECURSE project_SRCS *.cpp *.cxx *.cc *.C *.c *.h *.hpp)

FILE (GLOB_RECURSE project_LIB_SRCS *.cpp *.cxx *.cc *.C *.c *.h *.hpp)
LIST (REMOVE_ITEM project_LIB_SRCS ${PROJECT_SOURCE_DIR}/src/main.cpp)
LIST (REMOVE_ITEM project_LIB_SRCS ${PROJECT_SOURCE_DIR}/src/app.cpp)
LIST (REMOVE_ITEM project_LIB_SRCS ${PROJECT_SOURCE_DIR}/src/app.h)

SET (project_MOC_HEADERS app.h)
SET (project_LIBS ${Boost_LIBRARIES})
SET (project_BIN ${PROJECT_NAME})

# uncomment to use qt4
#QT4_WRAP_CPP(project_MOC_SRCS_GENERATED ${project_MOC_HEADERS})

ADD_LIBRARY(${PROJECT_NAME}-testing ${project_LIB_SRCS})
ADD_EXECUTABLE(${project_BIN} ${project_SRCS} ${project_MOC_SRCS_GENERATED})
TARGET_LINK_LIBRARIES(${project_BIN} ${project_LIBS})
SET_TARGET_PROPERTIES(${project_BIN} PROPERTIES VERSION "${APPLICATION_VERSION_MAJOR}.${APPLICATION_VERSION_MINOR}" OUTPUT_NAME ${project_BIN} CLEAN_DIRECT_OUTPUT 1)

INSTALL(TARGETS ${project_BIN} DESTINATION bin)
