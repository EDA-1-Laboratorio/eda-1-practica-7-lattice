#ifndef ARRAKIS_H
#define ARRAKIS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NOMBRE 30
#define SOLDADOS_INICIAL 500
#define SOLDADOS_MIN 50       /* Umbral para ser consumida por el desierto */
#define DANIO_PORCENTAJE 20   /* Porcentaje de soldados devorados */
#define ESPECIA_COSECHA 10    /* Especia ganada por turno (si no fue atacada) */
#define ESPECIA_REFUERZOS 200 /* Especia para llamar refuerzos */

typedef struct casa {
    char nombre[MAX_NOMBRE];
    int soldados;
    int especia;
    struct casa *siguiente;
} Casa;

/* =====================================================================
 * FUNCIONES PROPORCIONADAS
 * =====================================================================*/

/*
 * Crea un nodo Casa con el nombre dado, soldados iniciales y especia = 0.
 * El puntero siguiente se inicializa a NULL.
 */
Casa *crear_casa(const char *nombre, int soldados);

/*
 * Lanza un dado de 1 a 6.
 */
int lanzar_dado(void);

/*
 * Imprime el estado del anillo completo a partir de un nodo cualquiera.
 * Recorre la lista circular una sola vez.
 */
void mostrar_anillo(Casa *cualquiera);

/*
 * Libera toda la memoria del anillo circular.
 */
void liberar_anillo(Casa *cualquiera);

/*
 * Cuenta cuantas casas hay en el anillo.
 */
int contar_casas(Casa *cualquiera);

/* =====================================================================
 * FUNCIONES QUE EL ESTUDIANTE DEBE IMPLEMENTAR
 * =====================================================================*/

/*
 * Inserta una nueva casa al final del anillo circular.
 * Si el anillo esta vacio (*anillo == NULL), el nuevo nodo apunta a si mismo.
 * Si ya hay nodos, inserta el nuevo justo antes del nodo apuntado por *anillo,
 * de modo que *anillo sigue apuntando al mismo nodo original.
 * Retorna: no retorna nada, modifica *anillo solo si estaba vacio.
 */
void insertar_casa(Casa **anillo, Casa *nueva);

/*
 * Avanza el puntero del gusano 'pasos' posiciones en la lista circular.
 * Retorna el nodo donde se detiene.
 */
Casa *avanzar_gusano(Casa *actual, int pasos);

/*
 * Aplica el ataque del gusano a la casa actual:
 *   - Reduce el 20% de los soldados de la casa atacada.
 *   - Todas las demas casas del anillo ganan +10 de especia.
 *   - Si la casa atacada queda con menos de 50 soldados, se elimina
 *     del anillo y se libera su memoria.
 *
 * Parametros:
 *   gusano  - puntero al puntero del nodo actual del gusano
 *   anillo  - puntero al puntero ancla del anillo (puede cambiar si
 *             se elimina el nodo ancla)
 *
 * Retorna: 1 si la casa fue eliminada, 0 si sobrevive.
 */
int atacar_asentamiento(Casa **gusano, Casa **anillo);

/*
 * (Boss Final) Si la casa actual tiene >= 200 de especia, inserta
 * un nuevo asentamiento con el mismo nombre (+ " II") justo ANTES
 * del nodo actual en el anillo. El nuevo nodo tiene 250 soldados
 * y 0 especia. Se descuenta toda la especia de la casa que invoco
 * los refuerzos.
 *
 * Retorna: 1 si se invocaron refuerzos, 0 si no.
 */
int invocar_refuerzos(Casa *actual, Casa **anillo);

#endif
