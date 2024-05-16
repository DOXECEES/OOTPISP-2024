# CMakeList.txt: проект CMake для CMakeProject4; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#

# Включение горячей перезагрузки для компиляторов MSVC, если поддерживается.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("test4")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (test4 "main.cpp" "Time.cpp" "Time.h" "Vector.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET test4 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
