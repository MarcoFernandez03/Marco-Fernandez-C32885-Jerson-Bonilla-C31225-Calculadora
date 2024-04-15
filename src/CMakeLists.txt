set(HEADER_LIST
"${Calculadora_SOURCE_DIR}/include/*.hh"
)
add_executable(Calculadora
calculadora.cc)
target_include_directories(Calculadora PUBLIC ../include)
