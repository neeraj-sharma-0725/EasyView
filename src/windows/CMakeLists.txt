set(PROJECT_CURRENT_HEADER_PATH "${PROJECT_CURRENT_HEADER_PATH}/windows")
set(PROJECT_CURRENT_SOURCE_PATH "${PROJECT_CURRENT_SOURCE_PATH}/windows")

list(APPEND MENU_SOURCES MainWindow)

foreach(file IN LISTS MENU_SOURCES)
  list(APPEND PROJECT_SOURCES ${PROJECT_CURRENT_HEADER_PATH}/${file}.h)
  list(APPEND PROJECT_SOURCES ${PROJECT_CURRENT_SOURCE_PATH}/${file}.cpp)
endforeach()

set(PROJECT_SOURCES "${PROJECT_SOURCES}" PARENT_SCOPE)
