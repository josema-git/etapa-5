# Arquitectura Von Neumann y arquitectura Harvard

## Ley de Moore

La **Ley de Moore** establece que el número de transistores en un chip se duplica aproximadamente cada dos años, lo que lleva a un aumento exponencial en la potencia de procesamiento. Esto implica que:

- La velocidad de procesamiento se duplica cada 12 meses.
- El costo del chip no cambia significativamente.
- Cada 18 meses, se duplica la potencia de cálculo sin modificar el costo.

## Rendimiento

El rendimiento de un sistema informático está determinado por la velocidad del procesador y de la memoria. Sin embargo, la velocidad de la memoria siempre estará rezagada respecto a la velocidad del procesador, lo que puede causar cuellos de botella en el rendimiento.

## Funcionamiento de la Computadora

### Evolución de la Programación

En los primeros días de la computación, los sistemas eran cableados, y las tareas se programaban mediante hardware. Para cambiar una tarea, era necesario modificar físicamente el hardware. Hoy en día, la programación se realiza mediante software, utilizando transistores para dar órdenes a través de secuencias de funciones lógicas.

## Arquitectura Von Neumann

La arquitectura Von Neumann se basa en un modelo donde los datos y los programas se almacenan en una única memoria de lectura-escritura. Esta arquitectura consta de tres componentes principales:

1. **Unidad Central de Procesamiento (CPU)**:
   - **Unidad de Control (UC)**: Coordina las operaciones del sistema.
   - **Unidad Aritmética Lógica (ALU)**: Realiza operaciones matemáticas y lógicas.
   - **Registros**: Almacenan temporalmente datos e instrucciones.

2. **Memoria Principal**:
   - Almacena tanto instrucciones como datos.
   - Los contenidos se acceden indicando su posición, sin importar su tipo.

3. **Módulo de Entrada/Salida**:
   - Incluye dispositivos como discos duros, placas de video, etc.

### Modelo de Von Neumann

- **Programa Almacenado**: La separación de la memoria y la CPU permite que los programas se almacenen en la memoria, lo que se conoce como el concepto de programa almacenado.
- **Cuello de Botella de Neumann**: Este problema se refiere a la discrepancia entre la velocidad de la CPU y la velocidad de la memoria, lo que puede hacer que la CPU permanezca ociosa mientras espera datos.

### Interconexiones en el Modelo Von Neumann

Todos los componentes se comunican a través de un sistema de **buses**:

- **Bus del Sistema**: Conecta la CPU, la memoria y los dispositivos de entrada/salida.
- **Arbitraje del Bus**: Si dos o más dispositivos intentan transmitir simultáneamente, puede haber distorsión de señales. Se implementa un sistema de arbitraje para decidir quién usa el bus.

### Ciclo de Instrucción

La CPU ejecuta instrucciones a través de un ciclo denominado **ciclo de instrucción**, que incluye:

1. **Fetch (Captura)**: Obtiene la próxima instrucción de la memoria y la coloca en el registro de instrucción (IR).
2. **Decode (Decodificación)**: La instrucción se traduce a un lenguaje que entienda la ALU.
3. **Execute (Ejecución)**: La ALU ejecuta la operación y almacena el resultado en registros o memoria.

### Ejemplo de Ciclo de Instrucción

1. Cálculo de la dirección de la instrucción.
2. Captación de la instrucción.
3. Decodificación de la operación de la instrucción.
4. Cálculo de la dirección del operando.
5. Captación del operando.
6. Operación con datos.
7. Almacenamiento del operando.

## Arquitectura Harvard

La arquitectura Harvard, en contraste con la Von Neumann, utiliza dispositivos de almacenamiento físicamente separados para las instrucciones y los datos. Esto permite un acceso más rápido y eficiente.

### Componentes de la Arquitectura Harvard

1. **CPU**:
   - Similar a la arquitectura Von Neumann, contiene una unidad de control y una unidad aritmética lógica.

2. **Memoria de Instrucciones**:
   - Almacena las instrucciones del programa y utiliza memorias no volátiles (ROM, PROM, EPROM, EEPROM, flash).

3. **Memoria de Datos**:
   - Utiliza memoria RAM para almacenar datos que cambian continuamente, a menudo implementada como SRAM.

### Ventajas de la Arquitectura Harvard

- **Rendimiento Mejorado**: Al tener cachés separadas para instrucciones y datos, se mejora el rendimiento, ya que ambos pueden ser accedidos simultáneamente.
- **Uso en Microcontroladores**: Esta arquitectura se utiliza comúnmente en microcontroladores (PICs) para productos de propósito específico, como electrodomésticos y sistemas de telecomunicaciones.

### Desventajas

- **División de Caché**: La necesidad de dividir la caché entre instrucciones y datos puede ser un inconveniente si la frecuencia de acceso a ambos no es similar.


# El Procesador

## Organización del Procesador

El procesador, o Unidad Central de Procesamiento (CPU), es el corazón de la computadora. Se encarga de ejecutar instrucciones y procesar datos. A continuación, se describen sus componentes clave:

### Componentes Principales del Procesador

1. **Unidad de Control (UC)**:
   - **Función**: Controla todos los componentes del sistema, interpreta instrucciones y coordina su ejecución.
   - **Microprogramación**: Puede ser programada mediante hardware (cableada) o "microprogramada", utilizando múltiples microinstrucciones por cada instrucción.

2. **Unidad Aritmética y Lógica (ALU)**:
   - **Función**: Realiza operaciones matemáticas y lógicas.
   - **Operaciones**: Incluye sumas, restas, multiplicaciones y operaciones lógicas como AND, OR y XOR.

3. **Registros**:
   - **Características**: Memorias de tamaño fijo que almacenan datos binarios de manera temporal.
   - **Tipos**:
     - **Propósito General**: Utilizados en operaciones de programas (Ej: Ax, Bx, Cx, Dx).
     - **Específicos**: Como el Registro de Instrucción (IR) y el Contador de Programa (PC).

### Componentes Adicionales en Procesadores Modernos

Los procesadores actuales incluyen elementos adicionales que mejoran el rendimiento:

- **Unidades de Ejecución SIMD**: Especializadas en ejecutar instrucciones que operan sobre múltiples datos simultáneamente.
- **Memoria Caché**: Niveles de memoria rápida integrados en el chip para almacenar datos frecuentemente utilizados.
- **Unidad de Gestión de Memoria (MMU)**: Traduce direcciones de memoria virtual a física, optimizando el acceso a la memoria.
- **Unidad de Punto Flotante (FPU)**: Realiza operaciones de punto flotante de manera autónoma.

## Funciones de la Unidad de Control (UC)

La UC actúa como el "cerebro" del computador, realizando las siguientes funciones:

- **Leer Instrucciones**: Obtiene la instrucción a ejecutar.
- **Leer Operandos Fuente**: Accede a los datos necesarios para la ejecución.
- **Ejecutar Instrucciones**: Coordina la ejecución y almacena los resultados.
- **Comprobar Interrupciones**: Maneja interrupciones para asegurar un funcionamiento fluido.

### Microoperaciones

La UC realiza tres tipos de microoperaciones:

1. **Transferencia Interna**: Movimiento de datos entre registros internos.
2. **Transferencia Interna con Transformación**: Operaciones aritméticas y lógicas entre registros.
3. **Transferencia Externa**: Movimiento de datos entre registros internos y módulos externos, como la memoria principal.

## Qué es un Programa

Un programa es una secuencia de pasos que ejecuta operaciones lógicas o matemáticas. Cada operación requiere un conjunto específico de señales de control.

- **Generación de Direcciones**: La CPU genera direcciones mientras la memoria las recibe.
- **Traducción de Lenguajes**: El usuario escribe en un lenguaje de alto nivel, que se traduce a lenguaje ensamblador y luego a lenguaje de máquina.

## Ciclo de Ejecución

El ciclo de ejecución se compone de varias etapas:

1. **Fetch (Captura)**: La UC obtiene la próxima instrucción de la memoria y la coloca en el registro IR.
2. **Incremento del PC**: Se incrementa el contador de programa.
3. **Decodificación**: La instrucción se traduce a un formato que entienda la ALU.
4. **Obtención de Operandos**: Se accede a la memoria para obtener los operandos requeridos.
5. **Ejecución**: La ALU ejecuta la instrucción y almacena los resultados en registros o memoria.
6. **Verificación de Interrupciones**: Se comprueban las interrupciones antes de volver al paso 1.

## Segmentación de Instrucciones (Pipeline)

La segmentación divide el ciclo de ejecución en etapas, permitiendo que múltiples instrucciones se procesen simultáneamente. Esto mejora el rendimiento general del procesador.

## Instrucciones en Bajo Nivel

### Lenguaje de Máquina y Ensamblador

- **Lenguaje de Máquina**: Comprendido por el hardware, se representa en binario.
- **Lenguaje de Ensamblador**: Proporciona una representación más intuitiva de las instrucciones, utilizando mnemotécnicos.

### Ciclo de Extracción y Ejecución

1. **Ciclo de Extracción**:
   - El PC contiene la dirección de la próxima instrucción.
   - La dirección se mueve al registro de direcciones.
   - Se solicita la lectura de memoria y se coloca el resultado en el registro de instrucciones (IR).

2. **Ciclo de Ejecución**:
   - Dependiendo de la instrucción, puede implicar transferencias de datos entre registros, lectura/escritura en memoria o uso de la ALU.

## Ejemplo de Ciclo de Ejecución

1. **Carga en AC**: La instrucción carga un dato desde la memoria al acumulador.
2. **Suma**: Se suma el contenido de una posición de memoria al acumulador.
3. **Almacenamiento**: El resultado se almacena de nuevo en la memoria.

## Ciclo de Interrupción

Cuando ocurre una interrupción:

1. Se guarda el contenido del PC para saber dónde regresar.
2. Se carga la dirección de la rutina de interrupción.
3. Se inicia un nuevo ciclo de extracción para atender la interrupción.



# RISC y CISC (Arquitecturas de Procesadores)

## Introducción a las Arquitecturas

### Arquitectura x86

- **Tipo**: Conjunto de instrucciones complejas (CISC).
- **Compatibilidad**: Evoluciona manteniendo compatibilidad con versiones anteriores.
- **Ejemplo**: 
  - **8086 (1978)**: 5 MHz, 29,000 transistores.
  - **Core i7 EE 4960X**: 6 núcleos, 4 GHz, 1,860 millones de transistores.

### Sistemas Embebidos

- **Definición**: Electrónica y software integrados en productos específicos, a diferencia de computadoras de uso general.
- **Ejemplos**: Teléfonos celulares, cámaras digitales, microondas, sistemas de seguridad, automóviles, entre otros.
- **Internet de las Cosas**: Ejemplos claros de sistemas embebidos interconectados.

### Arquitectura ARM

- **Nombre Completo**: Acorn RISC Machine.
- **Tipo**: Microprocesadores y microcontroladores basados en conjunto de instrucciones reducidos (RISC).
- **Características**: Alta velocidad, pequeño tamaño y bajo consumo de energía.
- **Uso**: Dispositivos como iPods, iPhones y teléfonos inteligentes Android, además de placas de video como NVIDIA.

## Conjuntos de Instrucciones: RISC vs. CISC

### Definición de ISA (Instruction Set Architecture)

Al definir la arquitectura de un conjunto de instrucciones, se deben considerar:

- **Tipos de Datos**: ¿Qué tipos de datos maneja nativamente?
- **Almacenamiento y Acceso**: ¿Cómo se almacenan y acceden los datos?
- **Operaciones Ejecutables**: ¿Qué operaciones puede realizar?
- **Codificación**: ¿Cómo se codifican estas operaciones?

### RISC (Reduced Instruction Set Computer)

- **Instrucciones**: Generalmente de longitud fija.
- **Operaciones**: Se centra en un conjunto reducido de instrucciones simples.
- **Ejemplo**: Instrucciones Load/Store para acceso a memoria.

### CISC (Complex Instruction Set Computer)

- **Instrucciones**: Longitudes variables, permitiendo más complejidad.
- **Operaciones**: Incluye una variedad de instrucciones complejas y de manejo de memoria.
- **Ejemplo**: Instrucciones para operaciones aritméticas y lógicas.

## Comparación: x86 vs. ARM

### Tipos de Datos

- **Arquitectura x86**:
  - Maneja datos de 8, 16, 32, 64 y 128 bits.
  - Enteros con signo: complemento a 2.
  - Almacenamiento: Little Endian.

- **Arquitectura ARM**:
  - Soporta 8, 16 y 32 bits.
  - Enteros con signo: complemento a 2 de 16, 32 o 64 bits.
  - Almacenamiento: Little Endian y Big Endian.

### Tipos de Operaciones

- **x86**:
  - Instrucciones de longitud variable.
  - Instrucciones de procesamiento de datos, manejo de memoria y SIMD (MMX).
  
- **ARM**:
  - Instrucciones de longitud fija.
  - Solo instrucciones Load/Store para acceder a memoria.
  - Instrucciones aritméticas y lógicas.

## Modos de Direccionamiento

### Arquitectura x86

- **Registros de Segmento**: Seis registros que contienen direcciones de inicio de segmentos.
- **Construcción de Direcciones**: Segmento + Desplazamiento.

### Arquitectura ARM

- **Modos Simples**: Conjunto simple de modos de direccionamiento.
- **LOAD/STORE**: Solo estas instrucciones hacen referencia a la memoria.

## Endianness

- **Little Endian**: Utilizado en arquitecturas CISC, el byte menos significativo está en la posición de memoria más baja.
- **Big Endian**: Utilizado en arquitecturas RISC, el byte más significativo está en la posición de memoria más baja.

## Conclusiones

- **Evolución de Procesadores**: La arquitectura CISC ha tendido a incorporar más instrucciones y modos de direccionamiento.
- **Aparición de RISC**: Ha llevado a comparaciones sobre tamaño y velocidad de ejecución de programas.
- **Desafíos en Comparaciones**: No existen máquinas RISC y CISC directamente comparables en términos de costo, tecnología y soporte.
- **Convergencia de Tecnologías**: La controversia entre RISC y CISC ha disminuido debido a una gradual convergencia en el diseño y características.

A medida que la complejidad de los chips y la velocidad aumentan, los sistemas RISC se han vuelto más complejos, mientras que los diseños CISC han adoptado características asociadas tradicionalmente con RISC.

