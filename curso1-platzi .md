# Curso de Introducción a la Terminal y Línea de Comandos

## Comandos de Visualización de Directorios

- `ls`  
  Muestra el contenido del directorio actual.

- `ls -l`  
  Lista el contenido de forma detallada, incluyendo permisos, propietario, tamaño y fecha de modificación.

- `ls -lh`  
  Muestra el tamaño de los archivos de manera legible (ej. KB, MB).

- `ls -la`  
  Muestra todos los archivos, incluyendo los ocultos.

- `ls -lS`  
  Ordena los archivos por tamaño.

- `ls -lR`  
  Lista el contenido en orden alfabético revertido.

- `tree`  
  Muestra todos los archivos y directorios en forma de árbol.

- `tree -L {número}`  
  Muestra los primeros n niveles en forma de árbol.

## Comandos para Navegar en la Terminal

- `cd {direccion}`  
  Cambia al directorio especificado (puede ser relativa o absoluta).

- `cd`  
  Regresa al directorio home.

- `cd ..`  
  Regresa al directorio anterior.

- `pwd`  
  Muestra la dirección absoluta del directorio actual.

- `clear`  
  Limpia la pantalla de la terminal.

## Comandos de Manipulación/Revisión de Archivos/Directorios

- `file {archivo}`  
  Muestra información sobre el tipo de archivo.

- `mkdir {nombre}`  
  Crea uno o más directorios en la ruta actual.

- `touch {nombre}`  
  Crea uno o más archivos en la ruta actual.

- `cat > {archivo}`  
  Crea o modifica un archivo.

- `cp {archivo} {nombre}`  
  Copia un archivo con un nuevo nombre.

- `mv {archivo} {direccion}`  
  Mueve un archivo a otro directorio.

- `mv {archivo/directorio} {nombre}`  
  Cambia el nombre de un archivo o directorio.

- `rm {archivo}`  
  Elimina un archivo.

- `rm -i {archivo}`  
  Pide confirmación antes de eliminar.

- `rm -r {directorio}`  
  Elimina un directorio y su contenido de forma recursiva.

- `head {archivo}`  
  Muestra las primeras 10 líneas de un archivo.

- `head {archivo} -n {número}`  
  Muestra las primeras n líneas de un archivo.

- `tail {archivo}`  
  Muestra las últimas 10 líneas de un archivo.

- `tail {archivo} -n {número}`  
  Muestra las últimas n líneas de un archivo.

- `less {archivo}`  
  Abre un archivo de forma interactiva (salir con `q`).

- `xdg-open {archivo}`  
  Abre un archivo con la aplicación predeterminada.

- `ln -s {ruta} {nombre}`  
  Crea un enlace simbólico.

## Comandos de Ayuda

- `type {comando}`  
  Indica el tipo de comando.

- `alias {palabra}="{comando}"`  
  Asigna un alias a un comando (no se guardan tras cerrar la terminal).

- `help {comando}`  
  Proporciona información sobre cómo usar un comando.

- `man {comando}`  
  Muestra el manual del usuario del comando.

- `info {comando}`  
  Proporciona información similar a `man`, pero con mejor interfaz.

- `whatis {comando}`  
  Proporciona una descripción corta del comando.

## Wildcards

- `ls *.txt`  
  Muestra todos los archivos que terminan en `.txt`.

- `ls datos*`  
  Muestra todos los archivos que comienzan con "datos".

- `ls datos???`  
  Muestra archivos que comienzan con "datos" y tienen 3 caracteres más.

- `ls [[:upper:]]*`  
  Muestra archivos/directorios que comienzan con mayúscula.

- `ls -d`  
  Muestra solo los directorios.

## Redirecciones

- `ls Pictures > archivo.txt`  
  Guarda la salida en un archivo (crea y sobrescribe).

- `ls download >> archivo.txt`  
  Añade la salida al final de un archivo existente.

- `ls NAN 2> error.txt`  
  Guarda el mensaje de error en un archivo.

- `ls NAN > output.txt 2>&1`  
  Guarda la salida o el error en un archivo.

## Redirecciones y Pipe Operator

- `echo {mensaje}`  
  Envía un mensaje por la salida de la terminal.

- `cat {archivo}`  
  Muestra el contenido de un archivo en la terminal.

- `ls | tee output.txt`  
  Guarda la salida en un archivo.

- `ls -lh | tee output.txt | less`  
  Redirige el comando a `tee` y luego a `less`.

- `ls -lh | sort | tee output.txt`  
  Guarda la salida ordenada.

## Encadenando Comandos

- `ls; mkdir dir; cal`  
  Ejecuta los comandos uno a uno.

- `ls & mkdir dir & cal`  
  Ejecuta todos los comandos simultáneamente.

- `mkdir dir && cd dir`  
  Ejecuta el segundo comando solo si el primero tuvo éxito.

- `mkdir dir || cd dir`  
  Ejecuta ambos comandos.

## Manejo de Permisos

### Tipos de Archivos

- `-` Archivo normal  
- `d` Directorio  
- `l` Enlace simbólico  
- `b` Archivo de bloque especial  

### Modificación de Permisos

- `chmod 755 {archivo}`  
  Cambia permisos en formato octal.

- `chmod u-(+)(=)r {archivo}`  
  Modifica permisos de lectura para el usuario.

- `whoami`  
  Muestra el usuario actual.

- `id`  
  Muestra el UID y otros IDs.

- `su root`  
  Cambia a usuario administrador.

- `sudo {comando}`  
  Ejecuta un comando con permisos de nivel root.

## Variables de Entorno

- `printenv`  
  Muestra todas las variables de entorno.

- `echo $HOME`  
  Imprime la variable de entorno HOME.

- `echo $PATH`  
  Muestra las rutas de binarios.

- `.bashrc`  
  Archivo de configuración para alias y variables de entorno.

## Comandos de Búsqueda

- `which {binario}`  
  Muestra la ruta de un binario.

- `find {ruta} -name {nombre}`  
  Busca archivos por nombre.

- `find {ruta} -type f/d -name {nombre}`  
  Busca archivos o directorios por nombre.

- `grep {palabra} {archivo}`  
  Busca coincidencias en un archivo.

- `grep -i {palabra} {archivo}`  
  Ignora mayúsculas y minúsculas.

- `grep -c {palabra} {archivo}`  
  Cuenta las ocurrencias.

- `wc {archivo}`  
  Muestra la cantidad de líneas, palabras y bytes en un archivo.

## Utilidades de Red

- `ifconfig`  
  Muestra información de la red.

- `ping {dirección}`  
  Verifica si una página está activa.

- `curl {dirección}`  
  Descarga un archivo a través de la red.

- `wget {dirección}`  
  Descarga un archivo directamente.

- `traceroute {dirección}`  
  Muestra el camino de red hacia una dirección.

- `netstat -i`  
  Muestra dispositivos de red de forma amigable.

## Comprimir Archivos

- `tar -cvzf {nombre}.tar.gz {directorio}`  
  Comprime una carpeta en formato `.tar.gz`.

- `tar -xzvf {archivo comprimido}`  
  Descomprime un archivo `.tar.gz`.

- `zip -r {nombre}.zip {directorio}`  
  Comprime una carpeta en formato `.zip`.

- `unzip {archivo.zip}`  
  Descomprime un archivo `.zip`.

## Gestión de Procesos

- `ps`  
  Muestra todos los procesos actuales.

- `kill {PID}`  
  Mata el proceso por PID.

- `top`  
  Muestra los procesos más costosos en ejecución.

## Editores de Texto en la Terminal

- `vim {archivo}`  
  Abre un archivo para editar. Salir con `:q`.

- Cambiar a modo inserción con `i`, buscar con `/{palabra}`, y guardar con `:w`.