# Trabajo Práctivo Número 5

## Intrucciones para la compilación del programa
- Para compilar el proyecto se debe ejecutar el comando `make` por consola.
- Para correr el programa se debe ejecutar el comando `./build/bin/app.elf`
- Con el comando `make clean` se elimina la carpeta build.
- Con el comando `make docs` se genera la documentación.

## Intrucciones de uso

### Agregar operacion

1. Declarar la función que realizará la operación en la sección `Private function declarations`.
2. Implementa la función en la sección `Private function implementation`.
3. Utilizar la función `AgregarOperacion` para cargar la operación en la calculadora, para esto se debe pasar el puntero a la calculadora, el operador y el nombre de la funcion.

### Realizar un cálculo

1. Usar la función `Calcular`, se debe pasar el puntero a la calculadora y una cadena de caracteres con la operación a realizar, nos devolvera el resultado de la operación.
2. Mostrar por pantalla el resultado obtenido con la función `printf`.

## Autor

Apellido y nombre: Brito, Guillermo Nicolás

Asignatura: Sistemas Embebidos

Carrera: Ing. Electrónica