# Base de Sistemas Operativos

## 1. Requerimientos del Sistema Operativo para la Multiprogramación

### Introducción
- **Rol del Sistema Operativo (SO):**
  - Actúa como **administrador de recursos**.
  - Funciona como una **máquina ampliada** que simplifica la interacción entre hardware y aplicaciones.
- **Conceptos clave abordados:**
  - **Multiprogramación:** Permite que varios procesos compartan recursos del sistema.
  - **Planificación del CPU:** Asigna tiempo de ejecución a los procesos.
  - **Manejo de memoria:** Evita interferencias entre procesos.

### Funciones del SO
- **Gestión de recursos:**
  - Asigna **memoria** y **dispositivos** a múltiples procesos, evitando conflictos.
  - Controla el acceso a dispositivos mediante rutinas de entrada/salida.
  - Administra solicitudes de recursos, determinando si se pueden otorgar.
- **Intermediario entre hardware y aplicaciones:**
  - Proporciona una capa que simplifica la programación.
  - Ofrece servicios útiles para las aplicaciones, como acceso controlado al hardware.

---

## 2. Acceso Directo a Memoria (DMA)

### Concepto
- **DMA (Direct Memory Access):**
  - Permite la transferencia de datos entre dispositivos de entrada/salida y memoria sin intervención directa del CPU.
  - Optimiza el rendimiento al liberar al CPU para realizar otras tareas.

### Funcionamiento
- **Comunicación entre CPU, memoria y dispositivos:**
  - El **bus** conecta CPU, memoria y dispositivos para transferir datos.
  - El CPU da órdenes al controlador del dispositivo para realizar operaciones de lectura/escritura.
  - Durante la transferencia, el CPU puede ejecutar otras instrucciones.
  - El controlador notifica al CPU mediante una **interrupción** cuando la transferencia ha terminado.

---

## 3. Jerarquías de Memoria

### Definición
- **Jerarquía de memoria:**
  - Organiza diferentes tipos de memoria según su velocidad, costo y volatilidad.
  - La memoria más rápida (registros, caché) es más costosa y volátil.

### Niveles de memoria
1. **Registros del procesador:**
   - Memoria pequeña y rápida para datos esenciales.
2. **Memoria caché:**
   - Copia datos de la memoria principal para un acceso más rápido.
   - Tiene múltiples niveles (L1, L2, L3).
3. **Memoria principal (RAM):**
   - Almacena datos y programas en ejecución.
4. **Unidades de estado sólido (SSD):**
   - Actúan como almacenamiento intermedio.
5. **Discos magnéticos y nube:**
   - Almacenan grandes volúmenes de datos con menor velocidad de acceso.

### Caching
- **Concepto:**
  - Copiar datos a un nivel superior de la jerarquía para mejorar el acceso.
  - Ejemplo: Caché almacena bloques de memoria principal para optimizar el rendimiento.

---

## 4. Protección en Sistemas Operativos

### Modos de operación
- **Modo usuario:**
  - Programas con privilegios limitados.
- **Modo supervisor:**
  - Acceso completo al hardware y a instrucciones privilegiadas.

### Restricciones
- Los programas de usuario no pueden ejecutar instrucciones privilegiadas directamente.
- Se utilizan **llamadas al sistema** para interactuar con el SO y realizar operaciones como entrada/salida.

### Protección de memoria
- Uso de **registros base y límite**:
  - Definen el rango de direcciones de memoria accesibles para un programa.
  - Previenen accesos no autorizados.

---

## 5. Concepto de Proceso

### Definición
- Un **proceso** es un programa en ejecución que incluye el código, datos y estado actual.
- Estados principales de un proceso:
  1. **Nuevo:** Creación del proceso.
  2. **Listo:** Espera para ser ejecutado por el CPU.
  3. **Ejecución:** Instrucciones siendo procesadas.
  4. **Bloqueado:** Espera por un evento externo (ej. entrada/salida).
  5. **Salida:** Finalización del proceso.

### Gestión de procesos
- **Bloqueo y reanudación:**
  - Si un proceso requiere entrada/salida, se bloquea y el CPU ejecuta otro proceso.
  - Una vez completada la operación, el proceso vuelve a la cola de listos.
- **PCB (Process Control Block):**
  - Estructura de datos que almacena información del proceso:
    - Estado actual.
    - Contador de programa.
    - Registros.
    - Información de memoria.

---

## Resumen Final

### Rol del Sistema Operativo
- **Administrador de recursos:**
  - Gestiona CPU, memoria y dispositivos.
- **Máquina ampliada:**
  - Simplifica la interacción entre hardware y aplicaciones.

### Conceptos clave
1. **Multiprogramación:** Uso eficiente de recursos compartidos.
2. **DMA:** Transferencia de datos sin intervención directa del CPU.
3. **Jerarquías de memoria:** Organización de almacenamiento según velocidad y costo.
4. **Protección:** Restricciones de acceso para garantizar estabilidad y seguridad.
5. **Procesos:** Gestión de programas en ejecución mediante estados y estructuras como PCB.

---

# Planificación de Procesos

## 1. Introducción a la Planificación de Procesos

### Conceptos Básicos
- **Planificación de procesos:** Gestión de los estados de los procesos para optimizar la ejecución.
- **Estados de los procesos:**
  1. **Nuevo:** Proceso creado, esperando ser admitido.
  2. **Listo:** Proceso esperando tiempo de CPU.
  3. **Ejecución:** Proceso en ejecución en el CPU.
  4. **Bloqueado:** Proceso esperando un evento (ej. entrada/salida).
  5. **Finalizado:** Proceso completado.
- **Cambio de contexto:**
  - Guardar el estado actual del proceso en el **PSB** (Process State Block).
  - Restaurar el estado de otro proceso para continuar su ejecución.

---

## 2. Colas de Procesos y Distribución del Tiempo de CPU

### Colas de Procesos
- **Cola de listos:** Contiene procesos listos para ejecutarse.
- **Gestión FIFO (First In, First Out):**
  - Los procesos son atendidos en el orden en que llegan.
- **Interrupciones por temporizador:**
  - El temporizador genera interrupciones para cambiar entre procesos y garantizar un uso eficiente del CPU.

### Planificadores
1. **Planificador a largo plazo:**
   - Decide cuántos procesos admitir al sistema.
   - Considera la disponibilidad de recursos como memoria.
   - Se invoca con poca frecuencia.
2. **Planificador a corto plazo:**
   - Selecciona qué proceso se ejecutará a continuación.
   - Gestiona la cola de listos.
3. **Planificador a mediano plazo:**
   - Gestiona la memoria y el intercambio entre memoria principal y secundaria.
   - Puede suspender o reanudar procesos para optimizar recursos.

---

## 3. Cambio de Contexto y Suspensión de Procesos

### Cambio de Contexto
- **Definición:** Proceso de guardar el estado de un proceso y cargar el estado de otro.
- **Elementos guardados:**
  - Registros del CPU.
  - Contador de programa.
  - Estado del proceso.
- **Sobrecarga:** Durante el cambio de contexto, el CPU no realiza trabajo útil.

### Suspensión y Reanudación
- **Suspensión:** Un proceso se detiene temporalmente para permitir que otro utilice el CPU.
- **Reanudación:** El proceso suspendido se reactiva restaurando su contexto.

### Ejemplo Práctico
- Dos procesos comparten el CPU:
  - Proceso 1 es suspendido, se guarda su estado.
  - Proceso 2 se ejecuta y, al finalizar, se restaura el estado del Proceso 1.

---

## 4. Clasificación de Procesos

### Tipos de Procesos
1. **Procesos intensivos en entrada/salida:**
   - Requieren más tiempo de operaciones de E/S que de CPU.
2. **Procesos intensivos en CPU:**
   - Requieren más tiempo de CPU que de E/S.
3. **Procesos mixtos:**
   - Utilizan tanto CPU como E/S. Ejemplo: un reproductor de música.

### Tiempo de Retorno
- **Definición:** Tiempo total desde que un proceso llega hasta que finaliza.
- **Componentes:**
  - Tiempo de espera en la cola de listos.
  - Tiempo de ejecución en el CPU.
- **Ejemplo:**
  - Dos procesos comparten el CPU:
    - Proceso 1 tarda 3 segundos en ejecutarse.
    - Proceso 2 tarda 2 segundos.
    - Tiempo total de retorno: 5 segundos.

---

## 5. Planificación en Sistemas con Múltiples CPUs

### Balanceo de Carga
- **Definición:** Distribuir procesos entre múltiples CPUs para optimizar el uso de recursos.
- **Ejemplo:**
  - Dos CPUs ejecutan dos procesos simultáneamente.
  - Cuando un proceso finaliza, el CPU se libera para ejecutar otro proceso.

### Afinidad de Procesadores
- **Definición:** Asignar procesos a CPUs específicas para mejorar la eficiencia.
- **Ventajas:**
  - Reduce el cambio de procesos entre CPUs.
  - Mejora el rendimiento en sistemas con múltiples núcleos.

### Ejemplo Práctico
- **Escenario:** Tres procesos en dos CPUs.
  - CPU 0 ejecuta el Proceso 1.
  - CPU 1 ejecuta el Proceso 2.
  - Cuando el Proceso 1 finaliza, el Proceso 3 se reasigna al CPU 0.

---

## 6. Distribución del Tiempo de CPU

### Ejecución Simultánea
- Los procesos comparten el tiempo de CPU:
  - Proceso 1 utiliza el CPU mientras Proceso 2 realiza operaciones de E/S.
  - Cuando Proceso 1 finaliza, Proceso 2 utiliza el CPU.

### Cálculo del Tiempo Total
- **Ejemplo:**
  - Proceso 1: 3 segundos de CPU + 2 segundos de E/S.
  - Proceso 2: 2 segundos de CPU + 1 segundo de E/S.
  - Tiempo total: 6 segundos.

---

## Resumen Final de Planificación de Procesos

1. **Estados de los procesos:**
   - Nuevo, listo, ejecución, bloqueado y finalizado.
2. **Planificadores:**
   - Largo plazo: Decide la admisión de procesos.
   - Corto plazo: Selecciona el próximo proceso a ejecutar.
   - Mediano plazo: Gestiona la memoria y suspensiones.
3. **Cambio de contexto:**
   - Guarda y restaura el estado de los procesos.
4. **Clasificación de procesos:**
   - Entrada/salida, CPU intensivo y mixtos.
5. **Múltiples CPUs:**
   - Balanceo de carga y afinidad para mejorar la eficiencia.

---

# Operaciones con Procesos

## 1. Creación de Procesos y Relación Padre-Hijo

### Introducción
- **Relación jerárquica:**
  - La creación de procesos en sistemas operativos establece una relación **padre-hijo**.
  - El proceso padre utiliza la llamada al sistema `fork` para crear un proceso hijo.
- **Llamada al sistema `fork`:**
  - Duplica el proceso padre, creando un proceso hijo.
  - Ambos procesos comparten el mismo código, pero tienen datos y stack independientes.
  - Los valores devueltos por `fork`:
    - **0:** Proceso hijo.
    - **Valor positivo:** Proceso padre (ID del hijo).

### Ejecución Concurrente
- Los procesos padre e hijo inician su ejecución de manera separada tras el `fork`.
- **Ejemplo práctico:**
  - El proceso padre imprime un mensaje indicando su rol.
  - El proceso hijo imprime un mensaje diferente.
- **Ejecución de múltiples `forks`:**
  - Cada llamada adicional a `fork` duplica los procesos existentes.
  - Ejemplo: Dos llamadas a `fork` generan cuatro procesos.

---

## 2. Gestión de Memoria en Procesos

### Estructura de Memoria
- Cada proceso tiene:
  - **Segmento de código:** Compartido entre padre e hijo.
  - **Segmento de datos y stack:** Independientes para cada proceso.
- **Duplicación de memoria:**
  - `fork` crea copias de los segmentos de datos y stack para el proceso hijo.
  - El código permanece compartido, pero no puede ser modificado por ninguno de los procesos.

### Compartición de Recursos
- **Recursos no compartidos:**
  - Archivos abiertos.
  - Dispositivos en uso.
- **Recursos compartidos:**
  - Código del proceso.
- Para compartir recursos adicionales, se utilizan otras llamadas al sistema, como `clone`.

---

## 3. Sincronización y Finalización de Procesos

### Llamada al Sistema `wait`
- Permite que el proceso padre espere a que el proceso hijo termine su ejecución.
- **Flujo:**
  - El padre se bloquea hasta que el hijo finaliza.
  - El hijo devuelve un código de terminación al padre.

### Llamada al Sistema `exit`
- Utilizada por un proceso para finalizar su ejecución.
- **Código de terminación:**
  - **0:** Indica éxito.
  - **Otro valor:** Indica un error.
- El proceso padre recoge el código de terminación del hijo, liberando los recursos utilizados.

---

## 4. Ejecución de Programas en Procesos Hijos

### Llamada al Sistema `exec`
- Permite que un proceso hijo ejecute un programa diferente al del padre.
- **Funcionamiento:**
  - Reemplaza el espacio de memoria del proceso hijo con el nuevo programa.
  - El proceso hijo continúa ejecutándose con el nuevo código.

### Representación Jerárquica
- Los procesos se representan en un **árbol de procesos**:
  - El proceso raíz es el primero en el sistema operativo.
  - Los procesos hijos se crean a partir de procesos padres.
  - Ejemplo: Usuarios conectados generan procesos adicionales.

---

## 5. Comunicación entre Procesos

### Código de Terminación
- Los procesos hijos pueden informar al padre sobre el resultado de su ejecución mediante un código de terminación.
- **Ejemplo práctico:**
  - El padre delega una tarea al hijo.
  - El hijo finaliza y devuelve un código:
    - **0:** Tarea completada con éxito.
    - **Otro valor:** Error en la ejecución.

### Sincronización
- El proceso padre utiliza `wait` para recibir el código de terminación y manejar los resultados.
- Esto asegura que los recursos del hijo se liberen correctamente.

---

## 6. Resumen de Operaciones con Procesos

1. **Creación de procesos:**
   - `fork` duplica el proceso padre, creando un hijo con segmentos independientes de datos y stack.
2. **Gestión de memoria:**
   - Los procesos comparten el código, pero no los datos ni el stack.
3. **Sincronización:**
   - `wait` permite que el padre espere al hijo.
4. **Finalización:**
   - `exit` finaliza un proceso, devolviendo un código de terminación.
5. **Ejecución de nuevos programas:**
   - `exec` reemplaza el espacio de memoria del hijo con un nuevo programa.
6. **Comunicación:**
   - Los hijos informan al padre sobre el éxito o error mediante códigos de terminación.

---

# Procesos Cooperantes y Comunicación entre Procesos

## 1. Procesos Cooperantes

### Definición
- **Procesos cooperantes:** Son procesos que trabajan juntos compartiendo recursos o información para lograr un objetivo común.
- **Ventajas de los procesos cooperantes:**
  - **Intercambio de información:** Permite que los procesos compartan datos de manera eficiente.
  - **Velocidad:** Divide las tareas entre procesos, reduciendo el tiempo de ejecución.
  - **Modularidad:** Facilita la resolución de problemas complejos dividiéndolos en partes más pequeñas y manejables.

### Ejemplo: Pintar una Habitación
- **Analogía de la pintura:**
  - Múltiples pintores trabajando juntos para pintar una habitación representan procesos cooperantes.
  - Para ser eficientes, los pintores deben **comunicarse y coordinarse** para evitar conflictos o redundancias.
- **Optimización del trabajo:**
  - Agregar más pintores (procesos) puede acelerar la tarea, pero requiere una adecuada sincronización.
  
### Problema Productor-Consumidor
- Ejemplo clásico de procesos cooperantes:
  - **Productor:** Genera elementos (datos, recursos, etc.).
  - **Consumidor:** Consume los elementos producidos.
- **Dinámica:** Ambos procesos deben coordinarse para evitar problemas como:
  - **Subproducción:** El consumidor espera porque no hay elementos.
  - **Sobreproducción:** El productor genera más elementos de los que el consumidor puede manejar.

---

## 2. Comunicación entre Procesos (IPC)

### Introducción
- **Comunicación entre procesos (IPC):** Mecanismos que permiten a los procesos intercambiar información y coordinarse.
- **Objetivo:** Lograr que los procesos trabajen juntos de manera eficiente y segura.

### Mecanismos de Comunicación
1. **Señales:**
   - Avisos que un proceso envía a otro para notificar un evento.
   - Ejemplo: Un proceso envía una señal para alertar a otro de que ha completado una tarea.

2. **Memoria Compartida:**
   - Espacio de memoria que varios procesos pueden usar simultáneamente.
   - **Ventajas:**
     - Velocidad en el intercambio de información.
     - Simplicidad en la implementación.
   - **Desafíos:**
     - Requiere sincronización para evitar conflictos en el acceso.
   - **Ejemplo:** Un proceso escribe datos en la memoria compartida, y otro los lee.

3. **Semáforos:**
   - Mecanismo de sincronización que regula el acceso a recursos compartidos.
   - **Funcionamiento:**
     - Los semáforos permiten que los procesos se ejecuten de forma **secuencial** y evitan condiciones de carrera.
   - **Ejemplo práctico:** Un semáforo asegura que solo un proceso acceda a un recurso crítico a la vez.

4. **Sistema de Mensajes:**
   - Los procesos se comunican enviando y recibiendo mensajes.
   - **Buzón de mensajes:** Espacio donde los procesos depositan y recuperan mensajes.
   - **Ventajas:**
     - No requiere memoria compartida.
     - Útil para sistemas distribuidos.
   - **Ejemplo:** Un proceso envía un mensaje a otro para indicarle que inicie una tarea.

---

## 3. Sincronización en Procesos Cooperantes

### Importancia de la Sincronización
- **Sincronización:** Proceso de coordinar la ejecución de procesos para evitar conflictos en el acceso a recursos compartidos.
- **Problemas comunes:**
  - **Condiciones de carrera:** Dos o más procesos acceden simultáneamente a un recurso compartido, causando resultados inconsistentes.
  - **Bloqueos mutuos (deadlocks):** Dos o más procesos esperan indefinidamente por recursos que están bloqueados por otros procesos.

### Herramientas de Sincronización
1. **Semáforos:**
   - Controlan el acceso a recursos compartidos mediante contadores.
   - **Ejemplo:** Un semáforo binario (0 o 1) permite que solo un proceso acceda a un recurso a la vez.

2. **Memoria Compartida:**
   - Requiere mecanismos adicionales (como semáforos) para evitar conflictos en el acceso concurrente.

3. **Sistema de Mensajes:**
   - Proporciona sincronización implícita al enviar y recibir mensajes.

---

## 4. Resumen de Procesos Cooperantes y Comunicación

### Procesos Cooperantes
- **Definición:** Procesos que trabajan juntos compartiendo información y recursos.
- **Ventajas:**
  - Velocidad, modularidad e intercambio de información.
- **Ejemplo práctico:** Pintar una habitación o el problema productor-consumidor.

### Comunicación entre Procesos
- **Mecanismos principales:**
  1. Señales: Notificaciones entre procesos.
  2. Memoria compartida: Espacio común para intercambiar datos.
  3. Semáforos: Sincronización y control de acceso a recursos.
  4. Sistema de mensajes: Intercambio de información mediante mensajes.

### Sincronización
- **Objetivo:** Evitar conflictos y garantizar la correcta ejecución de procesos cooperantes.
- **Herramientas:** Semáforos, memoria compartida y sistemas de mensajes.

---

# Hilos

## 1. Concepto de Hilos

### Definición
- Un **hilo** es una línea de ejecución dentro de un proceso.
- Un proceso puede tener **uno o varios hilos**, que comparten:
  - **Código**.
  - **Segmentos de datos**.
  - **Recursos del proceso**.
- Cada hilo tiene su propio **stack** y **contador de programa**.

### Relación entre Procesos e Hilos
- Un proceso comienza con un **hilo principal**, que puede crear otros hilos.
- Los hilos permiten dividir tareas dentro de un proceso, mejorando la eficiencia y el rendimiento.

### Ejecución de Hilos
- Los hilos se crean dinámicamente con funciones específicas (por ejemplo, `pthread_create` en POSIX).
- El programa principal debe esperar a que todos los hilos terminen antes de finalizar la ejecución.

---

## 2. Beneficios de los Hilos

### 2.1 Eficiencia y Paralelismo
- Los hilos permiten la ejecución **paralela** de tareas dentro de un proceso.
- Ejemplo:
  - Un hilo realiza operaciones de entrada/salida mientras otro procesa datos.

### 2.2 Optimización en Sistemas Multi-Core
- Los hilos aprovechan las capacidades de los procesadores multi-core:
  - Dividen tareas entre múltiples núcleos.
  - Mejoran el rendimiento al reducir el tiempo de ejecución.
- Ejemplo:
  - Aplicaciones como navegadores web y procesadores de texto utilizan múltiples hilos para manejar tareas como cargar imágenes, responder al teclado y realizar revisiones ortográficas.

### 2.3 Reducción de Costos
- Los hilos comparten recursos del proceso, lo que reduce el costo de creación y gestión en comparación con procesos independientes.

---

## 3. Modelos de Hilos

### 3.1 Hilos a Nivel Usuario
- **Definición:** Hilos gestionados en el espacio de usuario, invisibles para el sistema operativo.
- **Ventajas:**
  - Rápidos de crear y gestionar.
  - No requieren intervención del kernel.
- **Desventajas:**
  - Si un hilo se bloquea, todo el proceso se bloquea.

### 3.2 Hilos a Nivel Kernel
- **Definición:** Hilos gestionados directamente por el sistema operativo.
- **Ventajas:**
  - El kernel puede planificar hilos en diferentes CPUs.
  - Permiten aprovechar sistemas multi-core.
- **Desventajas:**
  - Mayor costo de creación y gestión.

### 3.3 Modelos Multihilos
1. **Muchos a Uno:**
   - Múltiples hilos de usuario se mapean a un solo hilo a nivel kernel.
   - Limitado por la incapacidad de aprovechar múltiples CPUs.
2. **Uno a Uno:**
   - Cada hilo de usuario se asocia directamente con un hilo a nivel kernel.
   - Permite la ejecución paralela en múltiples CPUs.
3. **Muchos a Muchos:**
   - Múltiples hilos de usuario se mapean a varios hilos a nivel kernel.
   - Combina las ventajas de los modelos anteriores.

---

## 4. Gestión de Hilos en Sistemas Operativos

### 4.1 Creación y Ejecución
- Los hilos se crean dinámicamente utilizando librerías como **POSIX Threads (pthreads)**.
- Ejemplo de funciones:
  - `pthread_create`: Crea un nuevo hilo.
  - `pthread_join`: Espera a que un hilo termine su ejecución.

### 4.2 Sincronización
- Es crucial para evitar conflictos en el acceso a recursos compartidos.
- Mecanismos de sincronización:
  - **Mutexes:** Bloqueos mutuos para garantizar acceso exclusivo.
  - **Semáforos:** Controlan el acceso a recursos compartidos.
  - **Condiciones:** Permiten que un hilo espere hasta que otro complete una tarea.

### 4.3 Finalización
- El hilo principal debe esperar a que todos los hilos secundarios terminen antes de finalizar el programa.
- Si no se espera, el programa puede finalizar prematuramente, causando errores.

---

## 5. Hilos en Arquitecturas Multicore

### Evolución de los Procesadores
- En la década de 1990, los procesadores aumentaban la frecuencia del reloj para mejorar el rendimiento.
- Limites:
  - A partir de frecuencias de 3 GHz, el aumento de potencia requerida se volvió insostenible.
- Solución:
  - Introducción de procesadores multi-core, que permiten dividir tareas entre múltiples núcleos.

### Uso de Hilos en Sistemas Multi-Core
- Los hilos permiten aprovechar el paralelismo inherente de los sistemas multi-core.
- Ejemplo:
  - Una aplicación serial no puede aprovechar múltiples CPUs.
  - Al dividir la aplicación en múltiples hilos, se puede ejecutar en diferentes núcleos, mejorando el rendimiento.

---

## 6. Resumen de Conceptos Clave

1. **Hilos:**
   - Son líneas de ejecución dentro de un proceso.
   - Comparten recursos, pero tienen su propio stack y contador de programa.

2. **Beneficios:**
   - Mejoran la eficiencia y el rendimiento.
   - Aprovechan sistemas multi-core para ejecutar tareas en paralelo.

3. **Modelos Multihilos:**
   - Muchos a Uno, Uno a Uno, Muchos a Muchos.

4. **Gestión:**
   - Creación dinámica con librerías como POSIX (pthreads).
   - Sincronización mediante mutexes, semáforos y condiciones.

5. **Arquitecturas Multicore:**
   - Los hilos permiten aprovechar el paralelismo para mejorar el rendimiento en sistemas modernos.

---

¡Claro! A continuación, te proporcionaré una explicación más extensa sobre cada algoritmo de planificación, junto con la tabla comparativa que se verá bien en formato `.md`. Además, agregaré una explicación detallada por separado para cada algoritmo, para que puedas entenderlos a fondo.

---

# Planificación del CPU

La planificación del CPU es un componente fundamental de los sistemas operativos. Su objetivo principal es gestionar cómo los procesos acceden al CPU de manera eficiente, maximizando el rendimiento del sistema y minimizando los tiempos de espera y retorno.

---

## **Tabla Comparativa de Algoritmos de Planificación**

Aquí tienes una tabla en formato Markdown que se verá bien al renderizarse en cualquier visor compatible:

| **Algoritmo**         | **Tipo**          | **Ventajas**                                     | **Desventajas**                                |
|------------------------|-------------------|-------------------------------------------------|-----------------------------------------------|
| FCFS                  | No Expropiativo   | Fácil de implementar.                           | Largas esperas para procesos cortos.          |
| SPF                   | No Expropiativo   | Minimiza tiempos de retorno promedio.           | Inanición de procesos largos.                 |
| HRRN                  | No Expropiativo   | Evita inanición de procesos largos.             | Más complejo de implementar.                  |
| Round Robin           | Expropiativo      | Ideal para sistemas interactivos.               | Ineficiente si el quantum es muy grande/pequeño. |
| Colas de Realimentación | Expropiativo     | Flexibilidad para ajustar prioridades.          | Inanición de procesos largos (si no se ajusta el quantum). |
| EDF                   | Tiempo Real       | Cumple deadlines dinámicos.                     | Sobrecarga en el recalculo de prioridades.    |
| Rate Monotonic (RM)   | Tiempo Real       | Prioridades fijas, simple.                      | No garantiza el cumplimiento de deadlines.    |

---

## **Explicación Individual de Cada Algoritmo**

### **1. FCFS (First-Come, First-Served)**

#### **Descripción:**
- Es uno de los algoritmos más simples de implementar.
- Los procesos se ejecutan en el orden en que llegan a la cola de listos.
- No permite interrupciones: un proceso debe terminar antes de que otro comience.

#### **Ventajas:**
- Fácil de entender e implementar.
- Adecuado para sistemas donde los procesos tienen tiempos de ejecución similares.

#### **Desventajas:**
- **Problema de convoy:** Si un proceso largo está al principio de la cola, los procesos cortos deben esperar mucho tiempo (efecto dominó).
- No es adecuado para sistemas interactivos.

#### **Ejemplo:**
Si tres procesos llegan en este orden:
- P1: Tiempo de ejecución = 8
- P2: Tiempo de ejecución = 4
- P3: Tiempo de ejecución = 2

El tiempo de espera para cada proceso sería:
- P1 = 0, P2 = 8, P3 = 12.
- **Tiempo promedio de espera:** (0 + 8 + 12) / 3 = 6.67 unidades.

---

### **2. SPF (Shortest Process First)**

#### **Descripción:**
- Prioriza los procesos con menor tiempo de ejecución.
- Es no expropiativo, lo que significa que una vez que un proceso comienza, no puede ser interrumpido.

#### **Ventajas:**
- Minimiza el tiempo promedio de retorno.
- Ideal para sistemas donde los tiempos de ejecución son conocidos de antemano.

#### **Desventajas:**
- Puede causar inanición de procesos largos si siempre llegan procesos cortos.
- Requiere conocer los tiempos de ejecución de los procesos, lo cual no siempre es posible.

#### **Ejemplo:**
Si los procesos tienen estos tiempos de ejecución:
- P1 = 6, P2 = 8, P3 = 2, P4 = 4.

El orden de ejecución sería: P3 → P4 → P1 → P2.

---

### **3. HRRN (Highest Response Ratio Next)**

#### **Descripción:**
- Calcula una prioridad dinámica para cada proceso basada en su tiempo de espera y tiempo de ejecución.
- Fórmula:  
  **Ratio de Respuesta = (Tiempo de Espera + Tiempo de Ejecución) / Tiempo de Ejecución**

#### **Ventajas:**
- Evita la inanición de procesos largos.
- Es más justo que SPF.

#### **Desventajas:**
- Más complejo de implementar debido al cálculo continuo del ratio de respuesta.

#### **Ejemplo:**
Para tres procesos:
- P1: Llegada = 0, Tiempo de ejecución = 3.
- P2: Llegada = 1, Tiempo de ejecución = 5.
- P3: Llegada = 2, Tiempo de ejecución = 2.

El algoritmo selecciona el proceso con el mayor ratio de respuesta en cada momento.

---

### **4. Round Robin**

#### **Descripción:**
- Cada proceso recibe un quantum de tiempo fijo para ejecutarse.
- Si un proceso no termina dentro de su quantum, regresa a la cola de listos.

#### **Ventajas:**
- Ideal para sistemas interactivos.
- Garantiza que todos los procesos reciban tiempo de CPU.

#### **Desventajas:**
- Si el quantum es muy pequeño, aumenta la sobrecarga del sistema.
- Si el quantum es muy grande, se comporta como FCFS.

#### **Ejemplo:**
Con un quantum de 2 unidades y 3 procesos:
- P1 = 5, P2 = 8, P3 = 3.
El orden de ejecución sería: P1 (2) → P2 (2) → P3 (2) → P1 (3) → P2 (2) → P2 (2).

---

### **5. Colas de Realimentación**

#### **Descripción:**
- Los procesos se organizan en múltiples colas con diferentes prioridades.
- Los procesos largos pueden ser degradados a colas de menor prioridad.

#### **Ventajas:**
- Flexible y ajustable según las necesidades del sistema.
- Permite manejar procesos interactivos y en segundo plano.

#### **Desventajas:**
- Los procesos largos pueden sufrir inanición si no se ajusta el quantum.

#### **Ejemplo:**
Un proceso comienza en la cola de mayor prioridad con un quantum de 2. Si no termina, desciende a una cola con un quantum mayor (por ejemplo, 4).

---

### **6. EDF (Earliest Deadline First)**

#### **Descripción:**
- Prioriza procesos con deadlines más cercanos.
- Utiliza prioridades dinámicas que cambian con el tiempo.

#### **Ventajas:**
- Ideal para sistemas en tiempo real.
- Garantiza el cumplimiento de deadlines si las tareas son viables.

#### **Desventajas:**
- Alta sobrecarga debido al recalculo constante de prioridades.

---

### **7. Rate Monotonic (RM)**

#### **Descripción:**
- Asigna prioridades fijas basadas en los periodos de las tareas.
- Las tareas con periodos más cortos tienen mayor prioridad.

#### **Ventajas:**
- Simple y predecible.
- Adecuado para sistemas con tareas periódicas.

#### **Desventajas:**
- No garantiza el cumplimiento de deadlines si la utilización del procesador supera ciertos límites.

---

¡Claro! Aquí tienes una explicación detallada sobre la planificación **SMP (Symmetric Multi-Processing)** en sistemas operativos, basada en el video mencionado. Este tema es esencial para comprender cómo los sistemas operativos modernos manejan múltiples procesadores de manera eficiente.

---

## **Planificación SMP en Sistemas Operativos**

### **¿Qué es SMP?**
SMP (Symmetric Multi-Processing) es un modelo de procesamiento en el que varios procesadores comparten la misma memoria física y tienen acceso equitativo a los recursos del sistema. Es común en sistemas multiprocesador modernos, donde el objetivo principal es maximizar el rendimiento distribuyendo las tareas entre todos los procesadores disponibles.

En un entorno SMP:
- Todos los procesadores tienen el mismo nivel de acceso a los recursos del sistema.
- Los procesos pueden ejecutarse en cualquier procesador disponible.
- Se requiere un planificador eficiente para distribuir las tareas y mantener el sistema balanceado.

---

### **Aspectos Clave de la Planificación SMP**

1. **Eficiencia:**
   - El objetivo principal es evitar que los procesadores queden inactivos. Esto se logra distribuyendo las tareas de manera uniforme entre todos los procesadores.
   - La planificación debe minimizar el tiempo de espera de los procesos y maximizar el uso del CPU.

2. **Escalabilidad:**
   - A medida que se agregan más procesadores, el sistema debe ser capaz de manejar la carga adicional sin degradar el rendimiento.
   - Un buen planificador SMP debe ser escalable, asegurando que la adición de procesadores realmente aumente el rendimiento general.

3. **Afinidad de Procesos:**
   - **Afinidad** significa que un proceso tiende a ejecutarse en el mismo procesador donde fue asignado previamente.
   - Esto es importante porque los datos de un proceso suelen estar almacenados en la caché del procesador que lo ejecutó. Si el proceso se mueve a otro procesador, se pierde esta ventaja, y es necesario recargar esos datos en la nueva caché, lo que genera un costo adicional.
   - La afinidad ayuda a reducir la sobrecarga de la memoria caché y mejora el rendimiento.

---

### **Cómo se Implementa SMP en Linux**

El video explica cómo el sistema operativo Linux gestiona la planificación SMP en diferentes versiones:

#### **Linux 2.4:**
- Utiliza una **cola de procesos compartida** para todos los procesadores.
- Cualquier procesador puede tomar un proceso de esta cola y ejecutarlo.
- **Problema:** Este enfoque no considera la afinidad de los procesos, lo que puede generar una alta tasa de fallos en la memoria caché (cache misses) y afectar el rendimiento.

#### **Linux 2.6:**
- Introduce **colas de procesos separadas por procesador**.
- Cada procesador tiene su propia cola de procesos listos, lo que mejora la afinidad de los procesos.
- Si un proceso ya fue ejecutado en un procesador, es más probable que continúe ejecutándose en el mismo procesador.
- **Balanceador de carga:** Aunque cada procesador tiene su propia cola, si un procesador está inactivo y otro está sobrecargado, el balanceador de carga puede mover procesos entre colas para equilibrar la carga.

---

### **Problemas y Soluciones en SMP**

1. **Balanceo de Carga:**
   - En un sistema SMP, es posible que algunos procesadores estén inactivos mientras otros están sobrecargados.
   - El balanceador de carga redistribuye los procesos entre los procesadores para evitar este problema.
   - Sin embargo, mover procesos entre procesadores puede generar problemas de afinidad y aumentar los fallos en la caché.

2. **Cache Hot:**
   - Este concepto se refiere a los datos que están actualmente almacenados en la memoria caché de un procesador.
   - Si un proceso se mueve a otro procesador, los datos en la caché del procesador original ya no son útiles, lo que genera una pérdida de rendimiento.
   - Por eso, los sistemas modernos intentan mantener los procesos en el mismo procesador siempre que sea posible.

3. **Colas Compartidas vs. Colas Separadas:**
   - **Colas Compartidas:** Todos los procesadores toman procesos de una única cola. Esto es simple, pero no optimiza la afinidad ni la utilización de la caché.
   - **Colas Separadas:** Cada procesador tiene su propia cola, lo que mejora la afinidad y reduce los fallos en la caché. Sin embargo, requiere un balanceador de carga eficiente para evitar que algunos procesadores queden inactivos.

---

### **Resumen del Funcionamiento del SMP**

1. **Cola de Procesos Compartida (Linux 2.4):**
   - Todos los procesadores eligen procesos de una única cola.
   - Es simple, pero no considera la afinidad ni optimiza el uso de la caché.

2. **Colas de Procesos Separadas (Linux 2.6):**
   - Cada procesador tiene su propia cola, lo que mejora la afinidad.
   - El balanceador de carga redistribuye los procesos entre procesadores si es necesario.

3. **Afinidad y Balanceo:**
   - Mantener la afinidad es crucial para aprovechar la caché.
   - El balanceo de carga es necesario para evitar que algunos procesadores queden ociosos.

---

### **Ejemplo Práctico del SMP**

Imagina un sistema con dos procesadores (CPU1 y CPU2) y una serie de procesos (P1, P2, P3, P4):

1. **Cola Compartida:**
   - Todos los procesos están en una única cola.
   - CPU1 toma P1, CPU2 toma P2.
   - Si P3 y P4 llegan mientras P1 y P2 están en ejecución, cualquiera de las dos CPUs puede tomarlos.
   - **Problema:** Si P1 ya había cargado datos en la caché de CPU1, pero ahora es ejecutado por CPU2, los datos deben recargarse, lo que genera un costo adicional.

2. **Colas Separadas:**
   - P1 y P3 se asignan a la cola de CPU1, mientras que P2 y P4 se asignan a la cola de CPU2.
   - Cada CPU ejecuta los procesos de su propia cola, manteniendo la afinidad.
   - Si CPU2 está inactiva y CPU1 está sobrecargada, el balanceador de carga puede mover P3 a CPU2.

---

# Problemas de Concurrencia en Sistemas Operativos

## **Parte 1: Introducción y Algoritmos Iniciales**

### **1. Introducción al Problema de Concurrencia**

#### **¿Qué es la concurrencia?**
La concurrencia ocurre cuando varios procesos se ejecutan de manera simultánea o intercalada en un sistema operativo y comparten recursos, como memoria, archivos o dispositivos de entrada/salida. Aunque esto mejora la eficiencia del sistema, también introduce problemas que deben ser resueltos para garantizar que los datos no se corrompan y que los procesos se ejecuten correctamente.

#### **Problemas principales de la concurrencia:**
1. **Condiciones de carrera:** Ocurren cuando dos o más procesos acceden y modifican datos compartidos al mismo tiempo, y el resultado depende del orden en que se ejecutan.
   - **Ejemplo:** Dos clientes intentan retirar dinero de la misma cuenta bancaria al mismo tiempo. Sin control, ambos podrían retirar dinero, causando un saldo negativo.
   
2. **Bloqueos mutuos (deadlock):** Ocurren cuando dos o más procesos esperan indefinidamente porque cada uno está bloqueado por el otro.
   - **Ejemplo:** Dos personas intentan pasar por un pasillo estrecho al mismo tiempo y ninguna cede el paso.

3. **Inanición (starvation):** Un proceso nunca obtiene acceso a un recurso porque otros procesos lo acaparan continuamente.

4. **Inconsistencia de datos:** Si no se controla el acceso a los recursos compartidos, los datos pueden quedar en un estado incorrecto o inconsistente.

#### **Conceptos clave para manejar la concurrencia:**
1. **Exclusión mutua:** Garantizar que solo un proceso pueda acceder a una sección crítica (parte del código donde se manipulan recursos compartidos) a la vez.
2. **Progreso:** Si varios procesos desean acceder a la sección crítica, el sistema debe garantizar que uno de ellos pueda avanzar.
3. **Espera limitada:** Ningún proceso debe esperar indefinidamente para acceder a la sección crítica.

#### **Ejemplos prácticos:**
- **Uso de un baño limitado:** Imagina un baño público con un solo cubículo. Si varias personas intentan entrar al mismo tiempo, se necesita un mecanismo para decidir quién entra primero y evitar conflictos.
- **Transacciones bancarias:** Dos clientes intentan retirar dinero de la misma cuenta bancaria simultáneamente. Sin control, ambos podrían acceder al saldo antes de que se actualice, causando inconsistencias.

---

### **2. Primeros Intentos de Solución**

#### **Intento 1: Uso de una bandera**
- Cada proceso tiene una bandera que indica si está en la sección crítica.
- **Funcionamiento:**
  - Antes de entrar a la sección crítica, un proceso verifica si la bandera del otro proceso está activa.
  - Si la bandera del otro proceso está activa, espera; de lo contrario, entra a la sección crítica.
- **Problema:** Si ambos procesos activan sus banderas al mismo tiempo, ambos podrían entrar a la sección crítica simultáneamente, violando la exclusión mutua.

#### **Intento 2: Uso de dos banderas**
- Cada proceso verifica la bandera del otro antes de entrar a la sección crítica.
- **Funcionamiento:**
  - Un proceso solo entra a la sección crítica si la bandera del otro proceso está inactiva.
- **Problema:** Si ambos procesos activan sus banderas al mismo tiempo, ambos se quedan esperando indefinidamente, causando un **bloqueo mutuo (deadlock).**

#### **Intento 3: Cambiar el orden de las instrucciones**
- Se modifica el orden en que los procesos activan sus banderas y verifican las banderas del otro.
- **Problema:** Esto puede llevar a una **espera indefinida (starvation)**, donde un proceso nunca obtiene acceso a la sección crítica porque el otro siempre lo bloquea.

#### **Intento 4: Introducción del concepto de "life block"**
- Este intento aborda el problema de sincronización mediante una analogía:
  - **Ejemplo:** Dos personas en un pasillo estrecho intentan pasar al mismo tiempo. Si ninguna cede el paso, ambas quedan bloqueadas.
  - **Problema:** Aunque este enfoque intenta resolver el deadlock, no garantiza progreso ni exclusión mutua en todos los casos.

---

### **3. Algoritmos Correctos por Software**

#### **Algoritmo de Dekker**
- Este es uno de los primeros algoritmos correctos para resolver el problema de exclusión mutua.
- **Funcionamiento:**
  - Cada proceso tiene una bandera y una variable de turno.
  - Un proceso solo entra a la sección crítica si su bandera está activa y es su turno.
  - Después de salir de la sección crítica, el proceso cede el turno al otro proceso.
- **Ventajas:**
  - Garantiza exclusión mutua.
  - Evita deadlocks y starvation.
- **Problema:** Aunque es correcto, el algoritmo es complejo y difícil de implementar en sistemas con múltiples procesos.

#### **Algoritmo de Peterson**
- Es una mejora del algoritmo de Dekker, más simple y eficiente.
- **Funcionamiento:**
  - Cada proceso tiene una bandera y una variable de turno.
  - Un proceso establece su bandera en verdadero y cede el turno al otro proceso.
  - Si el otro proceso no desea entrar a la sección crítica, el primer proceso puede proceder.
- **Ventajas:**
  - Más sencillo que el algoritmo de Dekker.
  - Garantiza exclusión mutua, progreso y espera limitada.

#### **Algoritmo de la Panadería**
- Diseñado para manejar múltiples procesos.
- **Funcionamiento:**
  - Los procesos toman un "boleto" numerado para acceder a la sección crítica.
  - El proceso con el número más bajo entra primero.
  - Si dos procesos tienen el mismo número, se desempata utilizando sus identificadores.
- **Ventajas:**
  - Funciona para cualquier número de procesos.
  - Garantiza exclusión mutua, progreso y espera limitada.

---

### **4. Problemas de Espera y Soluciones Iniciales**

#### **Espera ocupada**
- **Problema:** En los intentos iniciales, los procesos que no pueden acceder a la sección crítica permanecen en un bucle activo, consumiendo tiempo del CPU innecesariamente.
- **Propuesta de solución:** En lugar de usar espera activa, los procesos deben pasar al estado de bloqueado hasta que puedan acceder a la sección crítica.

#### **Deshabilitar interrupciones**
- **Funcionamiento:**
  - El sistema desactiva las interrupciones del procesador mientras un proceso está en la sección crítica, asegurando que ningún otro proceso pueda interrumpirlo.
- **Problema:** Esto monopoliza el procesador, afectando el rendimiento del sistema y causando inanición en otros procesos.

---

### **5. Introducción a Soluciones por Hardware**

#### **Instrucción `test&set`**
- Es una solución por hardware que utiliza una instrucción atómica para garantizar exclusión mutua.
- **Funcionamiento:**
  - La instrucción verifica y modifica una variable compartida en una sola operación.
  - Si la variable está disponible, el proceso puede acceder a la sección crítica; de lo contrario, espera.
- **Ventajas:**
  - Garantiza exclusión mutua incluso en sistemas con múltiples CPUs.
- **Problema:** Aunque elimina las condiciones de carrera, aún puede causar espera ocupada.

#### **Instrucción `xchg`**
- Similar a `test&set`, esta instrucción intercambia valores entre una variable local y una global de manera atómica.
- **Funcionamiento:**
  - Un proceso utiliza la instrucción para verificar y modificar el estado de una variable compartida.
  - Si el intercambio es exitoso, el proceso entra a la sección crítica.
- **Ventajas:**
  - Garantiza exclusión mutua.
- **Problema:** También puede causar espera ocupada si muchos procesos intentan acceder al mismo tiempo.

---
## **Parte 2: Semáforos y Sincronización**

### **1. Introducción a los Semáforos**

Los semáforos son mecanismos de sincronización que permiten resolver problemas de concurrencia y exclusión mutua sin necesidad de usar espera ocupada. Son estructuras de datos que incluyen:
- **Un contador:** Indica el estado del recurso o la cantidad de procesos que pueden acceder a la sección crítica.
- **Una cola de procesos bloqueados:** Almacena los procesos que no pueden continuar porque el recurso está ocupado.

#### **Operaciones principales:**
1. **`wait` (o `down`):**
  - Decrementa el contador del semáforo.
  - Si el contador es menor que 0, el proceso se bloquea y se coloca en la cola del semáforo.
2. **`signal` (o `up`):**
  - Incrementa el contador del semáforo.
  - Si hay procesos en la cola, despierta a uno de ellos para que continúe.

#### **Tipos de semáforos:**
1. **Semáforos binarios:**
  - Solo tienen dos valores: 0 (recurso ocupado) y 1 (recurso libre).
  - Se utilizan principalmente para garantizar la exclusión mutua en secciones críticas.
2. **Semáforos generales:**
  - Pueden tener valores positivos o negativos.
  - Se usan para gestionar múltiples procesos que comparten un recurso con capacidad limitada (por ejemplo, un buffer).

---

### **2. Semáforos Binarios**

Los semáforos binarios son una herramienta básica para resolver problemas de exclusión mutua. Su funcionamiento se explica a través de ejemplos prácticos:

#### **Funcionamiento:**
- Un semáforo binario comienza con un valor inicial de 1 (recurso disponible).
- Cuando un proceso quiere acceder a la sección crítica, ejecuta la operación `wait`:
  - Si el valor es 1, el semáforo se decrementa a 0 y el proceso entra a la sección crítica.
  - Si el valor es 0, el proceso se bloquea hasta que otro proceso ejecute `signal`.
- Al salir de la sección crítica, el proceso ejecuta `signal`, incrementando el semáforo a 1 y permitiendo que otro proceso acceda.

#### **Ejemplo práctico: El baño**
- Imagina un baño con una sola cabina (recurso compartido):
  - Si está libre (semáforo = 1), una persona puede entrar y bloquearlo (`wait`).
  - Si está ocupado (semáforo = 0), las demás personas deben esperar en cola.
  - Cuando la persona sale, libera el baño (`signal`), permitiendo que otra persona entre.

#### **Importancia de operaciones atómicas:**
Las operaciones `wait` y `signal` deben ser atómicas, es decir, no pueden ser interrumpidas. Esto evita condiciones de carrera donde múltiples procesos intenten modificar el semáforo al mismo tiempo.

---

### **3. Semáforos Generales**

Los semáforos generales amplían las capacidades de los binarios al permitir valores mayores a 1. Esto es útil para gestionar recursos con capacidad limitada o para coordinar la ejecución de procesos.

#### **Funcionamiento:**
- El contador del semáforo indica cuántos procesos pueden acceder simultáneamente al recurso.
- Si el contador es positivo, los procesos pueden ejecutar `wait` y acceder al recurso.
- Si el contador es negativo, los procesos se bloquean en la cola.

#### **Ejemplo práctico: Buffer compartido**
- Un buffer con capacidad para almacenar 5 elementos:
  - El semáforo comienza con un valor de 5 (espacios disponibles).
  - Cada vez que un productor añade un elemento, el semáforo se decrementa (`wait`).
  - Cada vez que un consumidor retira un elemento, el semáforo se incrementa (`signal`).
  - Si el buffer está lleno (semáforo = 0), el productor se bloquea hasta que el consumidor libere espacio.

---

### **4. Sincronización con Semáforos: Problema del Productor-Consumidor**

El problema del productor-consumidor es un caso clásico de concurrencia donde un productor genera datos que un consumidor utiliza. Ambos comparten un buffer limitado, lo que requiere sincronización para evitar conflictos.

#### **Problemas comunes:**
1. **Buffer lleno:** El productor debe esperar hasta que el consumidor libere espacio.
2. **Buffer vacío:** El consumidor debe esperar hasta que el productor añada datos.

#### **Solución con semáforos:**
- **Semáforo `empty`:** Indica cuántos espacios libres hay en el buffer. Inicializado con el tamaño del buffer.
- **Semáforo `full`:** Indica cuántos elementos hay disponibles para consumir. Inicializado en 0.
- **Semáforo `mutex`:** Garantiza exclusión mutua al acceder al buffer.

##### **Flujo del productor:**
1. Ejecuta `wait(empty)` para verificar si hay espacio disponible.
2. Ejecuta `wait(mutex)` para acceder al buffer de manera exclusiva.
3. Añade un elemento al buffer.
4. Ejecuta `signal(mutex)` para liberar el acceso al buffer.
5. Ejecuta `signal(full)` para notificar al consumidor que hay un nuevo elemento.

##### **Flujo del consumidor:**
1. Ejecuta `wait(full)` para verificar si hay elementos disponibles.
2. Ejecuta `wait(mutex)` para acceder al buffer de manera exclusiva.
3. Retira un elemento del buffer.
4. Ejecuta `signal(mutex)` para liberar el acceso al buffer.
5. Ejecuta `signal(empty)` para notificar al productor que hay espacio disponible.

---

### **5. Problema de la Barbería**

El problema de la barbería ilustra cómo gestionar recursos limitados y sincronizar procesos en un entorno con múltiples clientes y barberos.

#### **Escenario:**
- Una barbería tiene un número limitado de sillas para esperar y sillas para atender.
- Los clientes llegan de manera concurrente, y los barberos trabajan en paralelo.
- Si la barbería está llena, los clientes deben esperar afuera.

#### **Solución con semáforos:**
- **Semáforo `waiting_chairs`:** Controla el número de clientes que pueden esperar en las sillas.
- **Semáforo `barber_chairs`:** Controla el número de barberos disponibles.
- **Semáforo `mutex`:** Protege el acceso a variables compartidas, como el número de clientes atendidos.

##### **Flujo del cliente:**
1. Verifica si hay espacio en la barbería (`wait(waiting_chairs)`).
2. Si hay espacio, se sienta en una silla y espera su turno.
3. Cuando un barbero está disponible (`wait(barber_chairs)`), se sienta para el corte.
4. Al terminar, libera la silla del barbero (signal(barber_chairs)) y la silla de espera (signal(waiting_chairs)).

##### **Flujo del barbero:
1. Si no hay clientes, el barbero se duerme (wait(barber_chairs)).
2. Cuando un cliente llega, lo atiende.
3. Al terminar, notifica que está disponible (signal(barber_chairs)).

#### **Barbería Equitativa
En una barbería equitativa, se busca garantizar que los clientes sean atendidos en el orden de llegada, evitando que algunos sean favorecidos por tiempos de atención más cortos.

##### **Solución con semáforos:
- Cada cliente recibe un número único al llegar.
- Se utiliza un semáforo individual para cada cliente, asegurando que sea atendido en su turno.
- Un semáforo global protege el acceso a variables compartidas, como el número actual de turno.

## **Parte 3: Monitores, Paso de Mensajes y Lectores-Escritores**

### **1. Monitores**

Los **monitores** son estructuras de programación orientadas a objetos diseñadas para resolver problemas de concurrencia. Ofrecen una forma más sencilla y segura que los semáforos para manejar exclusión mutua y sincronización. 

#### **¿Qué son los monitores?**
- Un monitor es una **clase o módulo** que encapsula:
  - **Variables compartidas**: Accedidas exclusivamente a través de métodos del monitor.
  - **Métodos sincronizados**: Solo un proceso puede ejecutarlos a la vez.
  - **Colas de condición**: Permiten que los procesos esperen hasta que se cumpla una condición específica.

#### **Ventajas sobre los semáforos:**
- Simplifican la programación concurrente al manejar automáticamente la exclusión mutua.
- Reducen errores como condiciones de carrera o bloqueos.

#### **Monitores con señales:**
- Utilizan la operación **`signal`** para despertar a un proceso bloqueado en una cola de condición.
- Ejemplo: **Problema del productor-consumidor**
  - El productor añade elementos a un buffer y el consumidor los retira.
  - Si el buffer está lleno, el productor se bloquea; si está vacío, el consumidor espera.
  - El monitor asegura que solo un proceso (productor o consumidor) acceda al buffer a la vez.

#### **Monitores con notificación:**
- Reemplazan **`signal`** con **`notify`** para mejorar la sincronización.
- En lenguajes como Java, se implementan con métodos sincronizados (`synchronized`) y condiciones (`wait`, `notify`, `notifyAll`).
- Ejemplo práctico:
  - Un productor utiliza `wait` si el buffer está lleno.
  - Cuando el consumidor retira un elemento, usa `notify` para despertar al productor.

---

### **2. Paso de Mensajes**

El **paso de mensajes** es un mecanismo de comunicación entre procesos que no comparten memoria. Es útil tanto en sistemas distribuidos como en sistemas con memoria compartida, y permite sincronizar procesos mediante el intercambio de información.

#### **¿Cómo funciona?**
- Los mensajes se envían de un proceso a otro utilizando primitivas como:
  - **`send` (enviar):** El proceso emisor envía un mensaje.
  - **`receive` (recibir):** El proceso receptor espera y recoge el mensaje.

#### **Sincronización en el paso de mensajes:**
1. **Bloqueante:** 
   - El proceso emisor/receptor se detiene hasta que el mensaje sea enviado/recibido.
   - Ejemplo: Un chat donde el receptor no puede avanzar hasta recibir un mensaje.
2. **No bloqueante:**
   - El proceso continúa su ejecución sin esperar.
   - Ejemplo: Un buzón de correo donde los mensajes se almacenan hasta que el receptor los revise.

#### **Direccionamiento:**
1. **Directo:**
   - El emisor especifica directamente el receptor del mensaje.
   - Ejemplo: Una llamada telefónica, donde ambos interlocutores deben estar disponibles.
2. **Indirecto:**
   - Los mensajes se envían a un **buzón** (mailbox), que los almacena hasta que el receptor los recoja.
   - Ejemplo: Un mensaje de WhatsApp que puedes leer más tarde.

#### **Formato y disciplina de colas:**
- **Formato del mensaje:**
  - Incluye una cabecera (con información como remitente, destinatario y prioridad) y un cuerpo (contenido del mensaje).
- **Disciplina de colas:**
  - Los mensajes pueden procesarse en orden de llegada (FIFO) o según prioridad (urgencia o importancia del emisor).

#### **Ejemplo práctico:**
- **Productor-consumidor con buzones:**
  - El productor envía mensajes (productos) a un buzón.
  - El consumidor recibe mensajes del buzón y los procesa.
  - Si el buzón está lleno, el productor espera; si está vacío, el consumidor se bloquea.

---

### **3. Problema de Lectores y Escritores**

El problema de **lectores-escritores** surge cuando múltiples procesos necesitan leer y escribir en un recurso compartido, como una base de datos. La solución debe garantizar que:
1. Los **lectores** puedan leer simultáneamente si no hay escritores activos.
2. Los **escritores** tengan acceso exclusivo al recurso.

#### **Prioridad a los lectores:**
- **Reglas:**
  - Múltiples lectores pueden acceder al recurso al mismo tiempo.
  - Si un escritor quiere escribir, debe esperar a que todos los lectores terminen.
- **Problema:** Si llegan nuevos lectores constantemente, los escritores podrían quedar bloqueados indefinidamente.
- **Solución con semáforos:**
  - Un contador rastrea el número de lectores activos.
  - Los escritores esperan hasta que el contador sea 0.

#### **Prioridad a los escritores:**
- **Reglas:**
  - Un escritor tiene prioridad sobre los lectores.
  - Los lectores deben esperar si hay un escritor esperando o escribiendo.
- **Problema:** Los lectores podrían experimentar retrasos si hay muchos escritores.
- **Solución con semáforos:**
  - Se utiliza un semáforo para bloquear a los lectores mientras un escritor tiene acceso.
  - Un contador rastrea el número de escritores activos.

#### **Lectores y escritores con paso de mensajes:**
- En lugar de semáforos, se utilizan buzones para gestionar las solicitudes de lectura y escritura.
- **Funcionamiento:**
  - Los lectores envían solicitudes al buzón y esperan una respuesta del controlador.
  - Los escritores envían solicitudes similares, pero tienen prioridad.
  - El controlador maneja las solicitudes de forma ordenada, garantizando que los escritores no se bloqueen innecesariamente.

---

### **Resumen de Conceptos Clave**

1. **Monitores:**
   - Simplifican la exclusión mutua y la sincronización.
   - Utilizan colas de condición para manejar procesos bloqueados.
   - Ejemplo: Problema del productor-consumidor.

2. **Paso de Mensajes:**
   - Mecanismo de comunicación entre procesos sin memoria compartida.
   - Puede ser bloqueante o no bloqueante.
   - Ejemplo: Uso de buzones para sincronizar productor y consumidor.

3. **Lectores y Escritores:**
   - Solución con prioridad a lectores:
     - Los lectores tienen acceso simultáneo mientras no haya escritores.
   - Solución con prioridad a escritores:
     - Los escritores tienen acceso exclusivo y prioridad sobre los lectores.
   - Implementación con mensajes:
     - Buzones gestionan las solicitudes de lectura y escritura, priorizando a los escritores.