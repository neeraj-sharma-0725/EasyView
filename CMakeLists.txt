cmake_minimum_required(VERSION 3.22)

project(easyview VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)   # to process .ui files
set(CMAKE_AUTOMOC ON)   # to process .moc(Meta-Object Compiler) files
set(CMAKE_AUTORCC ON)   # to process .qrc(Qt Resource) files

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_PREFIX_PATH "/opt/Qt/6.5.3/gcc_64")  # allow CMake to find qt libraries


find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)  # find either Qt5 or Qt6 and, based on the major version
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets) # load Widgets module 


set(PROJECT_CURRENT_HEADER_PATH ${CMAKE_CURRENT_SOURCE_DIR})
set(PROJECT_CURRENT_SOURCE_PATH ${CMAKE_CURRENT_SOURCE_DIR})

set(PROJECT_SOURCES
  main.cpp
)

add_subdirectory(src build)

# message(STATUS ${PROJECT_SOURCES})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(${PROJECT_NAME}
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
  add_executable(${PROJECT_NAME}
    ${PROJECT_SOURCES}
  )
endif()


#specify resources path
set(RESOURCES_SOURCE_DIR ${CMAKE_SOURCE_DIR}/resources)
set(RESOURCES_DEST_DIR ${CMAKE_BINARY_DIR}/resources)

#copy resources to out directory
add_custom_command(
  TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory ${RESOURCES_SOURCE_DIR} ${RESOURCES_DEST_DIR}
  COMMENT "Copying resources folder to the build directory"
)

target_link_libraries(
  ${PROJECT_NAME} 
  PUBLIC 
  Qt${QT_VERSION_MAJOR}::Widgets
)

include(GNUInstallDirs)
install(TARGETS ${PROJECT_NAME}
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(${PROJECT_NAME})
endif()
