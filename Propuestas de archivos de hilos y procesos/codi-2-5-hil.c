#include <stdio.h>
#include <pthread.h>
#include <unistd.h> // Para sleep()

// Funci�n para imprimir recordatorios de reuniones
void* imprimirRecordatorios(void* arg) {
    for (int i = 1; i <= 3; ++i) {
        printf("Hilo 1: Recordatorio de reuni�n #%d\n", i);
        sleep(1); // Simula el tiempo entre recordatorios
    }
    return NULL;
}

// Funci�n para imprimir mensajes de bienvenida
void* imprimirBienvenida(void* arg) {
    printf("Hilo 2: Bienvenido al equipo, nuevo empleado!\n");
    return NULL;
}

// Funci�n para imprimir la lista de tareas del d�a
void* imprimirTareas(void* arg) {
    printf("Hilo 3: Lista de tareas del d�a:\n");
    printf("1. Revisar correos\n");
    printf("2. Preparar informe\n");
    printf("3. Asistir a la reuni�n\n");
    return NULL;
}

// Funci�n para imprimir actualizaciones de proyectos
void* imprimirActualizaciones(void* arg) {
    printf("Hilo 4: Actualizaciones del proyecto:\n");
    printf("Proyecto A: En progreso\n");
    printf("Proyecto B: Completado\n");
    return NULL;
}

// Funci�n para imprimir el estado de los pedidos
void* imprimirPedidos(void* arg) {
    printf("Hilo 5: Estado de los pedidos:\n");
    printf("Pedido 123: Enviado\n");
    printf("Pedido 456: En preparaci�n\n");
    return NULL;
}

int main() {
    pthread_t hilos[5];

    // Crear hilos para cada tarea
    pthread_create(&hilos[0], NULL, imprimirRecordatorios, NULL);
    pthread_create(&hilos[1], NULL, imprimirBienvenida, NULL);
    pthread_create(&hilos[2], NULL, imprimirTareas, NULL);
    pthread_create(&hilos[3], NULL, imprimirActualizaciones, NULL);
    pthread_create(&hilos[4], NULL, imprimirPedidos, NULL);

    // Esperar a que todos los hilos terminen
    for (int i = 0; i < 5; ++i) {
        pthread_join(hilos[i], NULL);
    }

    printf("Programa principal: Todas las tareas han sido impresas.\n");

����return�0;
}

