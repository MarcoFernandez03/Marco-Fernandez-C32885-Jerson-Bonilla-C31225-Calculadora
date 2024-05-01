# Quickstart CMake taken from:
# https://google.github.io/googletest/quickstart-cmake.html
# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
include(FetchContent)
FetchContent_Declare(
googletest
URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()
# Se define un ejecutable de pruebas "calculadora_test",
# que requiere los siguientes archivos .cc para ser compilado.
add_executable(calculadora_test
token_test.cc
${Calculadora_SOURCE_DIR}/src/token.cc
tokenizer_test.cc
${Calculadora_SOURCE_DIR}/src/tokenizer.cc
ShuntingYard_test.cc
${Calculadora_SOURCE_DIR}/src/ShuntingYard.cc
PostFix_test.cc
${Calculadora_SOURCE_DIR}/src/PostFix.cc
tokenizer_and_shuntingYard_test.cc

ShuntingYard_and_PostFix_test.cc
)
# Además, se añaden los archivos de encabezados
target_include_directories(calculadora_test
PUBLIC
"${Calculadora_SOURCE_DIR}/include"
)
# Finalmente, enlazamos con la biblioteca de Google Test
target_link_libraries(calculadora_test
GTest::gtest_main
)
include(GoogleTest)
# Añadan esto para permitir que ctest pueda descubrir las pruebas automáticamente
gtest_discover_tests(calculadora_test)
