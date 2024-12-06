# Resumen del Proceso de Arranque en Linux

Cuando se enciende un ordenador, la **BIOS** se ejecuta y verifica que todos los componentes estén funcionando correctamente. Al finalizar el chequeo, busca la partición de arranque (**bootloader**). Este se encarga de cargar el sistema operativo en la RAM del ordenador. En el caso de Linux, **GRUB** es el bootloader más común.

Una vez que el bootloader ha cargado el sistema operativo, lo primero que se ejecuta es el **kernel**, que es el encargado de administrar los recursos del sistema. Cuando el kernel ha cargado, se ejecuta **Init**, que es el primer proceso que realiza el sistema operativo. Este se encarga de iniciar todos los procesos necesarios para el correcto funcionamiento del sistema operativo.

Luego, cuando el sistema operativo ha cargado sus procesos, se carga el entorno gráfico, que es la interfaz que los usuarios ven y con la que interactúan.

## Términos Clave

- **BIOS**: Basic Input/Output System
- **UEFI**: Unified Extensible Firmware Interface
- **MBR**: Master Boot Record
- **GRUB**: The Grand Unified Boot Loader

## Firmware y Bootloader

**Firmware**: Permite verificar que todo el hardware y los dispositivos estén funcionando correctamente. El bootloader nos permite seleccionar las opciones de arranque de nuestro sistema operativo. Una vez cargado, ejecuta el **kernel** para administrar los recursos del sistema. **La BIOS** es una pequeña parte del disco duro que tiene un peso no mayor de 512 KB, donde a través de una interfaz gráfica se pueden ver todos los dispositivos conectados. También permite hacer configuraciones de arranque, entre otras cosas. Finalmente, se cargará el entorno gráfico del sistema operativo, el cual observamos como resultado final para cada versión o distribución en la que estemos trabajando.

## Modo Recovery

En el contexto de Linux, el "modo de recuperación" (recovery mode en inglés) es una opción de arranque especial que proporciona un entorno de trabajo mínimo con privilegios de administrador (root) para solucionar problemas o realizar tareas de mantenimiento en un sistema Linux. También se conoce como "modo de emergencia" o "modo de rescate".

Cuando se inicia en el modo de recuperación, el sistema operativo Linux se inicia con un conjunto mínimo de servicios y controladores, permitiendo al usuario realizar diversas acciones, tales como:

- **Recuperación de contraseñas**: Modificar o restablecer contraseñas de usuarios.
- **Reparación del sistema de archivos**: Comprobar y reparar el sistema de archivos.
- **Modificación de configuraciones**: Editar archivos de configuración importantes.
- **Actualización de software**: Actualizar o instalar software adicional.
- **Resolución de problemas de red**: Realizar pruebas de conectividad de red.

Es importante tener en cuenta que el modo de recuperación proporciona acceso de nivel de administrador al sistema, por lo que se debe tener cuidado al realizar cambios.

## Usuario y Grupos en Linux

Los usuarios nos permiten separar las responsabilidades y permisos de acciones en el sistema. Dependiendo de los permisos, son las acciones que podrán ejecutar.

### Características de los Usuarios

- **UID**: Identificador único del sistema.
- **GIDs**: Uno o más IDs que los relacionan a un grupo.
- **Directorio Home**: Está en la ruta `/home/<username>`.
- **Archivos**:
  - `/etc/passwd`: Contiene información de nuestros usuarios en formato `name:password:UID:GID:GECOS:directory:shell`.
  - **GECOS**: Información extra.
  - **SHELL**: La shell de inicio.
  - `/etc/shadow`: Contraseña en forma cifrada. Un asterisco `*` significa que jamás tuvo una contraseña asignada; un símbolo de exclamación `!` indica que ha sido bloqueado.

### Grupos

Los grupos agrupan usuarios y conjuntos de permisos, utilizados frecuentemente por servicios como demonios, Docker, PostgreSQL, etc.

#### Comandos para Manejar Grupos

- **Verificar grupos existentes**:
  ```bash
  cat /etc/group
  ```

- **Crear un nuevo grupo**:
  ```bash
  sudo groupadd <nombre_del_grupo>
  ```

- **Agregar usuarios a un grupo**:
  ```bash
  sudo usermod -a -G <nombre_del_grupo> <nombre_de_usuario>
  ```

- **Verificar los usuarios de un grupo**:
  ```bash
  id <nombre_del_grupo>
  ```

- **Eliminar un grupo**:
  ```bash
  sudo groupdel <nombre_del_grupo>
  ```

- **Cambiar los permisos de un archivo o directorio para un grupo**:
  ```bash
  sudo chgrp <nombre_del_grupo> <ruta_al_archivo_o_directorio>
  sudo chmod g+<permisos> <ruta_al_archivo_o_directorio>
  ```

- **Cambiar el nombre de un grupo**:
  ```bash
  sudo groupmod -n <nuevo_nombre> <nombre_actual>
  ```

- **Verificar los permisos de un grupo**:
  ```bash
  sudo getfacl /ruta/al/archivo-o-directorio
  ```

- **Agregar usuarios a un grupo secundario**:
  ```bash
  sudo usermod -a -G <nombre_del_grupo_secundario> <nombre_de_usuario>
  ```

- **Eliminar usuarios de un grupo**:
  ```bash
  sudo gpasswd -d <nombre_de_usuario> <nombre_del_grupo>
  ```

- **Verificar los grupos de un usuario**:
  ```bash
  groups <nombre_de_usuario>
  ```

## Control de Acceso en Linux

El control de acceso en Linux se refiere al conjunto de medidas y configuraciones utilizadas para gestionar y regular el acceso a recursos y funciones del sistema operativo. Los principales mecanismos incluyen:

- **Permisos de archivos**: Basados en usuarios, grupos y otros.
- **Control de usuarios**: Administración de cuentas de usuario.
- **Control de grupos**: Organización y administración de usuarios con características y permisos similares.
- **Directivas de seguridad**: Implementación de SELinux o AppArmor.
- **Firewall**: Herramientas como iptables o nftables.
- **Autenticación y autorización**: Verificación de identidad de usuarios.

## Root vs Administrador

### Root

- **Definición**: Superusuario con control total sobre el sistema.
- **Privilegios**: Puede instalar software, modificar archivos del sistema, crear usuarios, etc.
- **Responsabilidad**: Su uso incorrecto puede causar daños irreparables al sistema.

### Administrador

- **Definición**: Usuario con privilegios elevados, pero no tiene el control absoluto como Root.
- **Privilegios**: Puede administrar usuarios, instalar software, configurar servicios, etc.
- **Responsabilidad**: Menos riesgoso que el uso de Root.

## Niveles de RAID

Los niveles de RAID definen diferentes formas en las que los discos pueden combinarse y organizarse para lograr ciertos objetivos. Aquí están los niveles de RAID más comunes:

### RAID 0 (Striping)

- **Distribución de datos**: Sin redundancia, datos distribuidos en bloques.
- **Rendimiento**: Mejora el rendimiento en lectura y escritura.
- **Tolerancia a fallos**: No proporciona tolerancia a fallos.
- **Capacidad efectiva**: Suma de los discos individuales.

### RAID 1 (Mirroring)

- **Distribución de datos**: Duplicación exacta en dos o más discos.
- **Rendimiento**: Mejora en lectura.
- **Tolerancia a fallos**: Alta tolerancia a fallos.
- **Capacidad efectiva**: Mitad de la capacidad de los discos.

### RAID 5 (Striping with Parity)

- **Distribución de datos**: Striping a nivel de bloque con paridad distribuida.
- **Rendimiento**: Buen rendimiento de lectura.
- **Tolerancia a fallos**: Puede tolerar la falla de un disco.
- **Capacidad efectiva**: Suma de los discos menos la capacidad de un disco para paridad.

### RAID 10 (Striping and Mirroring)

- **Distribución de datos**: Combina striping y mirroring.
- **Rendimiento**: Buen rendimiento en lectura y escritura.
- **Tolerancia a fallos**: Puede tolerar la falla de uno o más discos.
- **Capacidad efectiva**: Mitad de la capacidad de los discos.

## Creación de LVM sobre RAID1

1. **Instalar el paquete**:
   ```bash
   apt install lvm2
   ```

2. **Crear el PV (Physical Volume)**:
   ```bash
   pvcreate /dev/md0
   ```

3. **Validar que se haya creado el PV**:
   ```bash
   pvdisplay
   ```

4. **Crear el grupo de volúmenes (VG)**:
   ```bash
   vgcreate volumegroup /dev/md0
   ```

5. **Validar que se haya creado el VG**:
   ```bash
   vgdisplay
   ```

6. **Crear particiones más pequeñas**:
   ```bash
   lvcreate --name newname1 --size 1Gb volumegroupname1
   lvcreate --name newname2 --size 1Gb volumegroupname2
   ```

7. **Validar las particiones**:
   ```bash
   lvdisplay
   ```

## Agregando el Sistema a fstab

Una vez creados los RAID y los volúmenes lógicos, podemos montarlos en nuestro sistema.

### Pasos:

1. **Formatear a EXT4**:
   ```bash
   mkfs.ext4 /dev/volumegroup/public
   ```

2. **Confirmar con**:
   ```bash
   lsblk
   ```

3. **Montar en el sistema**:
   ```bash
   cd /  # Vamos al directorio principal
   ls -la  # Listamos
   mkdir public && mkdir private  # Creamos las carpetas
   sudo mount /dev/volumegroup/public /public  # Montamos la unidad
   touch /public/new_file.txt  # Creamos un archivo de prueba
   ls /public  # Listamos el contenido
   ```

4. **Añadir al archivo fstab**:
   ```bash
   vim /etc/fstab
   ```
   En el archivo de configuración, añadimos:
   ```
   /dev/volumegroup/private /private ext4 defaults 0 0
   /dev/volumegroup/public /public ext4 defaults 0 0
   ```

## Proyecto 2: Recuperar GRUB

Cuando nuestro GRUB se desconfigura, debemos ser capaces de restaurarlo. Para ello, seguimos las siguientes indicaciones:

1. **Ubicación del archivo de configuración**: `/boot/grub/grub.cfg`

2. **Romper el GRUB**:
   ```bash
   sudo mv /boot/grub/grub.cfg.bck  # Cambia el nombre del archivo original de grub.cfg
   ```

3. **Reiniciar el sistema** para que se inicie en modo de recuperación y podamos repararlo.