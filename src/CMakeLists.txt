set(PROJECT_CURRENT_HEADER_PATH "${PROJECT_CURRENT_HEADER_PATH}/include")
set(PROJECT_CURRENT_SOURCE_PATH "${PROJECT_CURRENT_SOURCE_PATH}/src")

add_subdirectory(windows)
add_subdirectory(menus)
add_subdirectory(bars)
add_subdirectory(buttons)

list(APPEND WINDOW_SOURCES Application)

foreach(file IN LISTS WINDOW_SOURCES)
  list(APPEND PROJECT_SOURCES ${PROJECT_CURRENT_HEADER_PATH}/${file}.h)
  list(APPEND PROJECT_SOURCES ${PROJECT_CURRENT_SOURCE_PATH}/${file}.cpp)
endforeach()

set(PROJECT_SOURCES "${PROJECT_SOURCES}" PARENT_SCOPE)
