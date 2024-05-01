# Marco-Fernandez-C32885-Jerson-Bonilla-C31225-Calculadora
# Proyecto: Calculadora postfija.
El objetivo del proyecto es crear una calculadora de expresiones postfijas usando el algoritmo shunting yard.
Se utilizará el siguiente proceso para esto
1. Recibir una expresión del usuario en notación infija.
2. Separar la expresión en tokens.
3. Convertir la expresión en notación postfija, usando el algoritmo shunting yard.
4. Evaluar dicha expresión usando una calculadora postfija.
5. Imprimir el resultado de la expresión.

# Pasos para correr el programa
## Compilar el programa:
Dentro de la carpeta del proyecto en la consola de comandos de wsl ejecutar el comando `cmake --build build`.
## Correr el programa:
Ejecutando el comando `./build/src/Calculadora` en la consola de comandos.
### Correr pruebas:
Similar a correr el programa, ejecutando `./build/test/calculadora_test`

# Funcionamiento del programa
El usuario ingresa una expresión mátematica en notación infija, por ejemplo `2+4*(9-1)`. El programa convierte esta expresión en notación postifija antes de calcular su resultado e imprimirlo. El proceso anterior falla si la expresión fuera incorrecta.

Este proceso se repite hasta que el usuario ingrese `Salir`.
### Expresiones incorrectas:
1. División entre 0.
2. Logaritmo de 10.
3. Operador faltante.
4. Operando faltante.
5. Variables en la expresión.
6. Distintos paréntesis emparejados. Ej: `(2+1]`
7. Paréntesis sin pareja.
## Funcionalidades soportadas:
1. Suma y resta.
2. Multiplicación y división.
3. Raíz enésima.
4. Logaritmos.
## Funcionalidades no soportadas:
1. Imprimir el árbol de la función.
2. Números negativos.
3. Valor absoluto.
### Caracteristicas no funcionales que no fueron implementadas
1. Mutation testing.
2. Pruebas estilo QuickCheck.

