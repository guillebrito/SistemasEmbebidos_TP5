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

/** \brief Brief description of the file
 **
 ** Full file description
 **
 ** \addtogroup name Module denomination
 ** \brief Brief description of the module
 ** @{ */

/* === Headers files inclusions =============================================================== */

#include "calculadora.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* === Macros definitions ====================================================================== */

#ifndef OPERACIONES
#define OPERACIONES 4
#endif

/* === Private data type declarations ========================================================== */

typedef struct operacion_s
{
    char operador;
    funciont_t funcion;
} * operacion_t;

/* === Private variable declarations =========================================================== */

struct calculadora_s
{
    struct operacion_s operaciones[OPERACIONES];
};

/* === Private function declarations =========================================================== */

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

operacion_t BuscarOperacion(calculadora_t calculadora, char operador)
{
    operacion_t operacion = NULL;

    for (int i = 0; i < OPERACIONES; i++)
    {
        if (calculadora->operaciones[i].operador == operador)
        {
            operacion = &calculadora->operaciones[i];
            break;
        }
    }
}

/* === Private function implementation ========================================================= */

calculadora_t CrearCalculadora(void)
{
    calculadora_t calculadora = malloc(sizeof(struct calculadora_s));

    if (calculadora)
    {
        memset(calculadora, 0, sizeof(struct calculadora_s));
    }

    return calculadora;
}

bool AgregarOperacion(calculadora_t calculadora, char operador, funciont_t funcion)
{
    operacion_t operacion = BuscarOperacion(calculadora, 0);

    if ((operacion) && !BuscarOperacion(calculadora, operador))
    {
        operacion->operador = operador;
        operacion->funcion = funcion;
    }

    return (operacion != NULL);
}

int Calcular(calculadora_t calculadora, char * cadena)
{
    int a, b;
    char operador;
    int resultado = 0;

    for (int i = 0; i < strlen(cadena); i++)
    {
        if (cadena[i] < '0')
        {
            a = atoi(cadena);
            operador = cadena[i];
            b = atoi(cadena + i + 1);
        }
    }

    operacion_t operacion = BuscarOperacion(calculadora, operador);

    if (operacion)
    {
        resultado = operacion->funcion(a, b);
    }

    return resultado;
}

/* === Public function implementation ========================================================== */

/* === End of documentation ==================================================================== */

/** @} End of module definition for doxygen */
