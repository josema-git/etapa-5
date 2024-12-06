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


# El procesador

Organizacion del procesador

CPU
Unidad de Control (UC)
Controla todos los componentes
Interpreta instrucciones
Decodifica y ejecuta instrucciones
Transforma instrucciones en órdenes a otros componentes
Puede ser programada por hardware (cableada) y "microprogramada" (varias microinstrucciones por instrucción)

Unidad Aritmética y Lógica
Realiza operaciones matemáticas y lógicas
Sumas, restas, multiplicaciones
Operaciones lógicas: And, Or, Xor

Registros
Tamaño fijo y almacenan datos binarios
Acceso rápido
De propósito general (programas) - Ax, Bx, Cx, Dx
Específicos, como Registros de Instrucción

los procesadores actuales no solo contienen los 3 componentes básicos del CPU (Unidad de Control, Unidad Aritmética y Lógica, y Registros), sino que también incluyen los siguientes elementos:

Unidades de ejecución SIMD: Unidades especializadas en la ejecución de instrucciones SIMD (Single Instruction, Multiple Data), que trabajan con estructuras de datos vectoriales, como por ejemplo instrucciones multimedia.

Memoria caché: Prácticamente todos los procesadores modernos incorporan dentro del propio chip del procesador algunos niveles de memoria caché.

Unidad de gestión de memoria (MMU): Gestiona el espacio de direcciones virtuales, traduciendo las direcciones de memoria virtual a direcciones de memoria física en tiempo de ejecución.

Unidad de punto flotante (FPU): Unidad especializada en hacer operaciones en punto flotante, que puede funcionar de manera autónoma ya que dispone de un conjunto de registros propio.

Estos componentes adicionales permiten a los procesadores actuales mejorar su rendimiento y eficiencia en diversas tareas, como el procesamiento multimedia, el cálculo numérico y la gestión de la memoria.

ALU
encargada de resolver todas las operaciones aritmeticas y logicas
las aritmeticas tanto con numeros enteros (Ca2) como con numeros reales ( IEEE754, simple, doble y hasta cuadruple representacion)
las operaciones logicas AND, OR, NOT, XOR, operaciones de desplazamiento y rotaciones de bits
las operaciones matematicas anterioemente se utilizaba un coporcosador matematico, ahora, con el avance en el desarrollo de los procesadores hizo que dicho co-procesador se encuentre dent4o del mismo micro

UC
Cerebro del computador: La UC se puede considerar el "cerebro" del computador, ya que está conectada a todos los demás componentes del sistema a través de señales de control, de manera similar al sistema nervioso.

Ejecución de instrucciones: La función básica de la UC es la ejecución de las instrucciones, es decir, coordinar y controlar la ejecución de las diferentes operaciones que realiza el computador.

Coordinación de elementos: Es imprescindible para coordinar los diferentes elementos que tiene la computadora y hacer un buen uso de ellos. La UC se encarga de esta labor de coordinación y control.

En resumen, la Unidad de Control es el componente central del CPU que se encarga de interpretar y ejecutar las instrucciones, así como de coordinar el funcionamiento de los demás elementos del computador para lograr un buen desempeño general.

Qué realiza la UC
Leer una instrucción
Leer los operandos fuente
Ejecutar una instrucción y almacenar los operandos en destino
Comprobar interrupciones
Cada una de estas operaciones implica una serie de microoperaciones, que son transformaciones y transferencias de información.

Tipos de microoperaciones
La UC realiza tres tipos principales de microoperaciones:

Transferencia interna: Transferencia entre registros internos del procesador.

Transferencia interna con transformación: Operaciones aritméticas y lógicas entre registros internos del procesador.

Transferencia externa: Transferencia entre registros internos del procesador y módulos o registros externos (bus o memoria principal).

Estas microoperaciones permiten a la UC ejecutar las instrucciones, acceder a los operandos y coordinar el funcionamiento del procesador.




  

























