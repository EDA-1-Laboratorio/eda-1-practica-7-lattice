#ifndef ERROR_LOG_H
#define ERROR_LOG_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ID 16
#define UMBRAL_CRITICO 'E'  /* A-E son errores criticos */

typedef struct error_log {
    char id[MAX_ID];         /* ID del error, inicia con una letra */
    float prioridad;         /* Prioridad numerica dentro de su categoria */
    int es_critico;          /* 1 si la letra inicial es A-E, 0 en otro caso */
    struct error_log *sig;
} ErrorLog;

/*
 * Genera un error aleatorio con:
 *   - Un ID que comienza con una letra mayuscula (A-Z) seguida de digitos
 *   - Una prioridad float entre 0.0 y 10.0
 * Retorna un puntero a un nuevo nodo ErrorLog.
 */
ErrorLog *generar_error_aleatorio(void);

/*
 * Imprime la lista completa de errores.
 */
void imprimir_lista(ErrorLog *cabeza);

/*
 * Libera toda la memoria de la lista.
 */
void liberar_lista(ErrorLog *cabeza);

/* =====================================================================
 * FUNCIONES QUE EL ESTUDIANTE DEBE IMPLEMENTAR
 * =====================================================================*/

/*
 * Inserta un nodo en la lista de forma ordenada.
 * Criterio de orden:
 *   1. Primero por letra inicial del ID (orden alfabetico ascendente).
 *   2. Si dos errores tienen la misma letra inicial, se ordena por
 *      prioridad numerica de mayor a menor (mas prioritario primero).
 *
 * Parametros:
 *   cabeza   - puntero al puntero de la cabeza de la lista
 *   nuevo    - nodo a insertar
 */
void insertar_ordenado(ErrorLog **cabeza, ErrorLog *nuevo);

/*
 * Cuenta cuantos errores criticos (letra A-E) hay en la lista.
 */
int contar_criticos(ErrorLog *cabeza);

/*
 * Cuenta cuantos errores no criticos (letra F-Z) hay en la lista.
 */
int contar_no_criticos(ErrorLog *cabeza);

/*
 * Elimina de la lista todos los errores cuya prioridad sea menor
 * estricta que el umbral dado. Libera la memoria de los nodos eliminados.
 * Retorna la nueva cabeza de la lista.
 */
ErrorLog *eliminar_por_prioridad(ErrorLog *cabeza, float umbral);

/*
 * Conserva todos los errores criticos y solamente el error no critico
 * de mayor prioridad. Elimina y libera todos los demas errores no criticos.
 * Retorna la nueva cabeza de la lista.
 */
ErrorLog *conservar_mayor_no_critico(ErrorLog *cabeza);

#endif
