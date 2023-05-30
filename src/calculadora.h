/************************************************************************************************
Copyright (c) 2023, Guillermo Nicolás Brito <guillermonbrito@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
associated documentation files (the "Software"), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge, publish, distribute,
sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial
portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES
OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

SPDX-License-Identifier: MIT
*************************************************************************************************/

#ifndef CALCULADORA_H
#define CALCULADORA_H

/** \brief Declaraciones públicas del módulo calculadora
 **
 ** \addtogroup calculadora Calculadora
 ** \brief Módulo para el uso de la calculadora.
 ** @{ */

/* === Headers files inclusions ================================================================ */

#include <stdint.h>
#include <stdbool.h>

/* === Cabecera C++ ============================================================================ */

#ifdef __cplusplus
extern "C"
{
#endif

    /* === Public macros definitions =============================================================== */

    /* === Public data type declarations =========================================================== */
    /**
     * @brief Puntero a la etructura @ref calculadora_s
     *
     * Este puntero apunta a la estructura que describe a la calculadora.
     */
    typedef struct calculadora_s * calculadora_t;

    /**
     * @brief Puntero a funciones
     *
     * Este puntero apunta a una funcion del tipo int que recibe como parametros dos datos tipo int.
     */
    typedef int (*funciont_t)(int, int);

    /* === Public variable declarations ============================================================ */

    /* === Public function declarations ============================================================ */

    /**
     * @brief Función para crear una nueva calculadora.
     *
     * @return calculadora_t Puntero a la calculadora creada.
     */
    calculadora_t CrearCalculadora(void);

    /**
     * @brief Función para agregar una nueva operación a la calculadora.
     *
     * @param calculadora Puntero a la calculadora.
     * @param operador Operador de la operación.
     * @param funcion Puntero a la función que realiza la operación.
     * @return true La operación fue agregada.
     * @return false La operación no fue agregada.
     */
    bool AgregarOperacion(calculadora_t calculadora, char operador, funciont_t funcion);

    /**
     * @brief Calcula la operación ingresada.
     *
     * @param calculadora Puntero a la calculadora.
     * @param cadena Operación a calcular.
     * @return int Resultado de la operación.
     */
    int Calcular(calculadora_t calculadora, char * cadena);

    /* === End of documentation ==================================================================== */

#ifdef __cplusplus
}
#endif

/** @} End of module definition for doxygen */

#endif /* CALCULADORA_H */
