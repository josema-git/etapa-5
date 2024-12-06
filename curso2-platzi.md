# Curso de Introducción a la Administración de Servidores Linux

## ¿Qué es un Servidor?

Un servidor es un conjunto de recursos tecnológicos (software y hardware) que cumplen uno o varios propósitos. Generalmente, un servidor recibe peticiones de un cliente y otorga una respuesta. Los servidores pueden desempeñar múltiples roles, como servidores web, servidores de correo, servidores de archivos, entre otros.

## Arquitectura Mainframe-Terminal

La arquitectura mainframe-terminal consiste en una computadora central (mainframe) con abundantes recursos, a la que se conectan pequeñas terminales conocidas como *dumb-terminals*. Estas terminales dependían del mainframe para realizar tareas y procesar información.

En la actualidad, utilizamos un modelo similar a través de Internet, donde nuestras *dumb-terminals* son más como clientes, y los mainframes son representados por servidores que manejan solicitudes y respuestas.

## Arquitectura de un Sistema UNIX/Linux

Un sistema Linux se organiza en varias capas:

1. **Hardware**  
   Todos los dispositivos físicos conectados al sistema.

2. **Kernel**  
   Es el software central que controla el hardware y gestiona las interacciones entre el hardware y las capas superiores.

3. **Shell**  
   Interfaz entre el kernel y el usuario. Permite al usuario enviar instrucciones al kernel, que luego se comunica con el hardware, devolviendo la información a la capa superior.

4. **Aplicaciones**  
   Capa donde interactúa el usuario, que incluye la mayoría de los softwares y herramientas que utilizamos.

## Cuatro Libertades del Software Libre

1. **Libertad de ejecutar el programa**  
   El usuario puede usar el software para cualquier propósito.

2. **Libertad de estudiar el funcionamiento del programa y modificarlo**  
   Se puede acceder al código fuente para entender su funcionamiento y realizar modificaciones.

3. **Libertad de redistribuir**  
   Permite compartir copias del software con otros.

4. **Libertad de distribuir copias de sus versiones modificadas**  
   Permite compartir las modificaciones realizadas a otras personas.

## Tipos de Distribuciones Linux

- **LTS (Long Term Support)**  
  Distribuciones que ofrecen al menos 5 años de soporte y mantenimiento, ideales para entornos de producción.

- **Non-free-repositories**  
  Distribuciones que no cumplen con los lineamientos de Debian Free Software, incluyendo software propietario.

- **Rolling Release**  
  Actualizaciones que se publican de manera continua a medida que se desarrollan, sin versiones fijas.

- **Fixed Release**  
  Actualizaciones que son probadas y posteriormente publicadas en versiones específicas, garantizando estabilidad.

## ¿Dónde Viven Nuestros Servidores?

- **On Premise**: Todo el hardware y software del servidor es alojado y mantenido por la organización.

- **Cloud**: Puede ser pública o privada; una empresa ofrece infraestructura y arquitectura, y el usuario solo se encarga de administrarlo.

- **Híbrida**: Combinación de servicios on premise y cloud.

## Formas de Montar un Servidor

1. **Instalación Directa**: Se realiza a través de hardware o red, instalando una copia o un archivo del sistema de archivos, ocupando el 100% de los recursos dedicados.

2. **Virtualización**: Se instala un software (hypervisor) que sirve como host, administrando los recursos para crear múltiples *guests*.
   - **Tipo 1 (Bare-metal)**: Se monta el hypervisor directamente sobre el hardware, sin necesidad de un sistema operativo.
   - **Tipo 2 (Hosted)**: Se monta un sistema operativo sobre el hardware, y sobre este se utiliza un hypervisor para gestionar las máquinas virtuales.

3. **Contenedores**: Una forma de virtualización que se utiliza en sistemas que corren sobre Docker.

4. **Máquinas Virtuales**: Tienen sus propios recursos físicos.

## Sistemas Operativos Más Famosos de Servidores

- **Ubuntu**
- **Red Hat**

Se pueden utilizar hypervisores como VirtualBox y otros.

## Comandos Útiles de Servidores

- `systemctl status sshd`: Ver el estado del daemon de SSH.
- `ip address`: Muestra la interfaz de red de la computadora, hosteando máquinas virtuales.
- `ssh {usuario}@{ip-address}`: Ingreso remoto al servidor.

## ¿Qué son los Sistemas de Archivos?

Un sistema de archivos permite almacenar, mover, eliminar y buscar archivos. Puede ser compatible o no entre diferentes sistemas operativos, y define cómo los discos duros manejan la información. 

### Tipos de Sistemas de Archivos Comunes

- **FAT/FAT32**: Compatibilidad amplia, pero limitaciones en el tamaño de archivos.
- **NTFS**: Soporta archivos grandes y características avanzadas, pero no es completamente compatible con Linux.
- **EXT4**: Común en Linux, soporta archivos grandes y es eficiente.
- **XFS**: Diseñado para manejar grandes archivos y sistemas de archivos.
- **BtrFS**: Sistema de archivos avanzado con características de snapshot y gestión de volúmenes.
- **ZFS**: Ofrece alta capacidad y características avanzadas de gestión de datos.

## Particiones de un Servidor Linux

- `df`: Muestra el espacio en cada disco.
- `df -Th`: Presenta la información de forma más legible.
- `lsblk -f`: Lista cómo está particionado el disco.
- `sudo fdisk`: Permite ver y modificar particiones.
- `sudo fdisk -l`: Lista las particiones de los discos.

### Comandos Más Usados

| Comando        | Descripción                                                    |
|----------------|---------------------------------------------------------------|
| `lsblk`        | Lista los dispositivos de bloques y las particiones en el sistema |
| `fdisk`        | Herramienta para administrar particiones de disco            |
| `parted`       | Herramienta para crear y administrar particiones de disco    |
| `mkfs`         | Formatea una partición con un sistema de archivos            |
| `mount`        | Monta un sistema de archivos en una partición o un directorio |
| `umount`       | Desmonta un sistema de archivos                               |
| `df`           | Muestra el espacio libre y utilizado en las particiones montadas |
| `du`           | Muestra el tamaño de un archivo o directorio                 |
| `resize2fs`    | Ajusta el tamaño de un sistema de archivos ext2, ext3 o ext4 |
| `lvcreate`     | Crea un volumen lógico en un grupo de volúmenes LVM         |
| `lvextend`     | Amplía el tamaño de un volumen lógico                         |
| `lvresize`     | Ajusta el tamaño de un volumen lógico                         |
| `lvremove`     | Elimina un volumen lógico                                     |
| `vgcreate`     | Crea un grupo de volúmenes LVM                               |
| `vgextend`     | Amplía un grupo de volúmenes LVM                             |
| `vgreduce`     | Reduce un grupo de volúmenes LVM                             |
| `pvcreate`     | Crea un volumen físico LVM en una partición o dispositivo    |
| `pvextend`     | Amplía un volumen físico LVM                                  |
| `pvresize`     | Ajusta el tamaño de un volumen físico LVM                    |
| `pvremove`     | Elimina un volumen físico LVM                                 |

- `free -h`: Muestra la memoria RAM disponible.

### Creación de Memoria Swap

1. Mover al ROOT:
   ```bash
   cd /
   ```

2. Confirmar si hay un archivo swap:
   ```bash
   ls -lh
   ```

3. Ver la cantidad de memoria disponible:
   ```bash
   free -h
   ```

4. Verificar espacio en disco:
   ```bash
   df -h
   ```

5. Crear un archivo especial para la memoria swap:
   ```bash
   sudo fallocate -l 2G /swapfile
   ```

6. Configurar permisos:
   ```bash
   sudo chmod 600 /swapfile
   ```

7. Confirmar que el archivo swap esté creado:
   ```bash
   ls -lh
   ```

8. Convertir el archivo en un swap válido:
   ```bash
   sudo mkswap /swapfile
   ```

9. Configurar el fstab:
   ```bash
   sudo vim /etc/fstab
   ```
   Agregar la línea:
   ```
   /swapfile swap swap defaults 0 0
   ```
   Salir de vim con `ESC`, luego `:wq` y presionar `ENTER`.

10. Comprobar cambios:
    ```bash
    cat /etc/fstab
    ```

11. Activar el archivo swap:
    ```bash
    sudo swapon /swapfile
    ```

12. Desactivar el archivo swap:
    ```bash
    sudo swapoff /swapfile
    ```

## Estructura del Árbol de Directorios en Linux

El árbol de directorios en Linux es una estructura jerárquica que organiza y almacena datos, comenzando en el directorio raíz `/` y extendiéndose a través de subdirectorios. Algunos directorios importantes son:

- `/bin`: Archivos binarios ejecutables esenciales.
- `/boot`: Archivos necesarios para arrancar el sistema.
- `/dev`: Archivos de dispositivos que representan hardware.
- `/etc`: Archivos de configuración del sistema.
- `/home`: Directorios personales de usuarios.
- `/lib`: Bibliotecas compartidas necesarias para programas.
- `/media`: Puntos de montaje para dispositivos extraíbles.
- `/mnt`: Puntos de montaje para sistemas de archivos temporales o permanentes.
- `/opt`: Programas y archivos adicionales.
- `/proc`: Información en tiempo real sobre el sistema.
- `/root`: Directorio personal del usuario "root".
- `/run`: Archivos de estado del sistema.
- `/sbin`: Archivos binarios esenciales para el sistema.
- `/srv`: Datos de servicio para servidores web.
- `/sys`: Archivos de dispositivos virtuales.
- `/tmp`: Archivos temporales.
- `/usr`: Programas no esenciales.
- `/var`: Datos variables del sistema.

## Diferentes Tipos de Archivos

- **Archivos Regulares**: Contienen datos en formato de texto o binario.
- **Directorios**: Contienen información sobre otros archivos y subdirectorios.
- **Archivos de Dispositivos**: Representan dispositivos físicos o virtuales.
- **Enlaces Simbólicos**: Apuntan a otros archivos o directorios.
- **Sockets**: Permiten la comunicación entre procesos.
- **Tuberías**: Usadas para enviar datos entre procesos.
- **Archivos de Bloque**: Interactúan con dispositivos de bloque.
- **Archivos de Caracteres**: Interactúan con dispositivos de caracteres.

## Repositorios y Paquetes

Un paquete es un conjunto de archivos que permiten la ejecución de un software, facilitando el proceso de instalación al incluir todos los binarios y dependencias necesarias.

### Tipos de Paquetes

- **.deb**: Para sistemas basados en Debian, se usa con `dpkg`.
- **.rpm**: Para sistemas basados en Red Hat, se usa con `rpm`.

### Manejadores de Paquetes

- **APT**: Usado en distribuciones basadas en Debian (Ubuntu, Linux Mint).
- **YUM/DNF**: Usado en distribuciones basadas en Red Hat (Fedora, CentOS).

#### Comandos Comunes de APT

- `sudo apt update`: Actualiza la lista de paquetes.
- `sudo apt install <nombre_del_paquete>`: Instala un paquete.
- `sudo apt upgrade`: Actualiza todos los paquetes.
- `sudo apt remove <nombre_del_paquete>`: Elimina un paquete.
- `apt search <nombre_del_paquete>`: Busca un paquete.

#### Comandos Comunes de DNF

- `sudo dnf update`: Actualiza la lista de paquetes.
- `sudo dnf install <nombre_del_paquete>`: Instala un paquete.
- `sudo dnf upgrade`: Actualiza todos los paquetes.
- `sudo dnf remove <nombre_del_paquete>`: Elimina un paquete.
- `sudo dnf search <nombre_del_paquete>`: Busca un paquete.

## Instalación de Repositorios Extra

### Activación de Repositorios en Ubuntu

```bash
sudo add-apt-repository universe
sudo add-apt-repository multiverse
sudo apt update
```

### Activación de Repositorios en RHEL

```bash
dnf repolist
sudo dnf install --nogpgcheck https://dl.fedoraproject.org/pub/epel/epel-release-latest-$(rpm -E %rhel).noarch.rpm
sudo dnf update
```

## Daemon (Demonio)

En Linux, un demonio (daemon) es un programa que se ejecuta en segundo plano para realizar tareas que no requieren la intervención del usuario o que se deben realizar de forma continua, como la gestión del sistema, el monitoreo de servicios o la automatización de tareas.

### Ejemplos Comunes

- Servidores web
- Servidores de bases de datos
- Servicios de correo electrónico

## Procesos en Linux

Un proceso en Linux es un programa en ejecución en el sistema operativo. Cada proceso es identificado por un número único llamado ID de proceso (PID). El sistema operativo asigna un PID a cada proceso en ejecución y lo utiliza para realizar un seguimiento de su estado y recursos.

Cada proceso tiene su propio espacio de memoria y puede ejecutar de forma independiente. El sistema operativo controla los procesos, asegurándose de que no interfieran entre sí y de que se asignen los recursos adecuados a cada uno.

Los procesos se crean y se destruyen constantemente en un sistema Linux. Algunos procesos son iniciados por el sistema operativo, mientras que otros son iniciados por el usuario. En general, cada tarea que se realiza en un sistema Linux se ejecuta como un proceso.

Puedes ver los procesos en ejecución en tu sistema Linux utilizando el comando `ps`, que muestra información sobre los procesos activos en ese momento. También puedes utilizar el comando `top` para ver una lista en tiempo real de los procesos que consumen más recursos en tu sistema.

### Herramientas para Monitoreo de Procesos

1. **ps**: El comando `ps` (procesos) te permite obtener información sobre los procesos en ejecución. Puedes utilizar diversas opciones para filtrar la salida y obtener detalles específicos. Por ejemplo, `ps aux` muestra una lista detallada de todos los procesos del sistema.

2. **top**: El comando `top` muestra una lista en tiempo real de los procesos en ejecución, actualizando la información periódicamente. Proporciona detalles como el uso de CPU, memoria, PID (identificador de proceso), entre otros. Puedes ordenar los procesos por diferentes criterios y enviar señales a procesos individuales desde la interfaz de `top`.

3. **htop**: Similar a `top`, `htop` es una herramienta de monitoreo de procesos interactiva que muestra una lista en tiempo real de los procesos. Proporciona una interfaz más amigable y gráfica que `top`, permitiendo navegar y gestionar los procesos utilizando teclas de función.

4. **pstree**: El comando `pstree` muestra una representación jerárquica de los procesos en ejecución. Puedes visualizar la relación entre los procesos padre e hijo en forma de árbol, lo que facilita la comprensión de la estructura del sistema.

5. **lsof**: El comando `lsof` (list open files) muestra los archivos abiertos por los procesos en el sistema. También puedes utilizarlo para obtener información sobre los sockets de red y otros recursos abiertos por los procesos.

Estas son solo algunas de las herramientas disponibles en Linux para el escaneo y monitoreo de procesos. Cada una tiene sus propias características y opciones adicionales, por lo que puedes explorar más sobre ellas consultando sus respectivas páginas de manual (`man ps`, `man top`, `man htop`, etc.) para obtener más detalles y aprender cómo utilizarlas eficientemente.

## Estados de los Procesos en Linux

- **Running o Runnable (R)**: Activado cuando el proceso está consumiendo recursos de CPU o memoria. Si no está consumiendo recursos, entra en estado de espera ("sleep").

- **Sleep**: 
  - Interrumpible: El proceso puede ser pausado y retomado.
  - No interrumpible (D): No puede ser terminado fácilmente. Se usa la señal "SIGKILL" para terminarlo.

- **Stopped (T)**: El proceso está pausado y no se reanudará hasta que se le indique, independientemente de la disponibilidad de recursos.

- **Zombie (Z)**: El proceso ha terminado, pero aún no ha sido recogido por su proceso padre.

## Uso de la Terminal para Gestionar Procesos

### Enviar un Proceso a Background

- **Ejecutar un Comando en Background**:
  ```bash
  less espera.txt &
  ```

- **Listar Procesos en Background**:
  ```bash
  jobs -l
  ```

- **Traer un Proceso a Foreground**:
  ```bash
  fg %1
  ```

### Estados y Control de Procesos

- **Enviar a Background con Control+Z**: Pausa el proceso actual y lo envía a background.
- **Verificar el Estado con htop**: Utiliza `htop` para ver los procesos y su estado. Buscar con F3 y ver el estado "stopped" o "sleep".

### Terminar Procesos

- **Matar un Proceso por su PID**:
  ```bash
  kill 1402
  ```

- **Matar un Proceso en Background**:
  ```bash
  kill -s SIGKILL 1478
  ```

### Usar htop para Terminar Procesos

- **Ejecutar htop**:
  ```bash
  sudo htop
  ```

- **Buscar el Proceso y Terminarlo**: 
  - Buscar con F3.
  - Terminar con F9 y elegir la señal apropiada (15 para SIGTERM, 9 para SIGKILL).

### Comandos Adicionales

- **Matar Todos los Procesos Asociados a un Nombre**:
  ```bash
  killall less
  ```

## Creación y Manejo de Demonios

Es un proceso de Linux que da un comportamiento de servicio a un programa: es decir, que se ejecuta en segundo plano sin la interacción de un usuario.

- **systemd**: Crea los demonios.
- **Buscar el Proceso y Terminarlo**:
  - Buscar con `F3`.
  - Terminar con `F9` y elegir la señal apropiada (15 para SIGTERM, 9 para SIGKILL).

### Comandos Adicionales

- **Matar Todos los Procesos Asociados a un Nombre**:
  ```bash
  killall less
  ```

## Creación y Manejo de Demonios

Un demonio es un proceso de Linux que da un comportamiento de servicio a un programa: es decir, que se ejecuta en segundo plano sin la interacción de un usuario.

### Herramientas para Gestionar Demonios

- **systemd**: Crea los demonios.
- **systemctl**: Gestiona los demonios.

### Pasos para Crear un Demonio

1. **Crear el Script o Unit File**: Usa Python u otro lenguaje de scripting para crear el archivo que usará de base tu demonio.

2. **Crear la Carpeta**: Crea el folder donde se alojará el unit file a nivel de root, de esta manera estará disponible para todos los usuarios.

3. **Crear la Carpeta para la Información**: Crea la carpeta donde se alojará la información generada por tu unit file.

4. **Ir a `/etc/systemd/system`**: Crea el script que beberá del primero para poder correr el demonio.

5. **Reiniciar los Demonios**:
   ```bash
   systemctl daemon-reload
   ```

6. **Habilitar el Demonio**:
   ```bash
   systemctl enable loggerpython.service
   ```

7. **Activar el Demonio**:
   ```bash
   systemctl start loggerpython.service
   ```

## Automatización de Procesos con Cron Job

Para automatizar procesos con cron job, debemos:

1. **Validar la Disponibilidad del Demonio de Cron**:
   ```bash
   systemctl status cron
   ```

2. **Crear un Nuevo Cron Job**:
   ```bash
   crontab -e
   ```
   Elige cuál editor de archivos manejar y luego ingresa el minuto, la hora, el día del mes, mes, día de la semana y el comando.

3. **Observar Todos los Archivos de Crontab**: Para ver todos los cron jobs existentes para todos los usuarios, puedes usar:
   ```bash
   crontab -l
   ```