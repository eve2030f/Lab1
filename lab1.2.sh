#! /bin/bash

# Paso 2: Limitar permisos de ejecución para el script
#Validacon de datos
echo "Usuario:"
read nuevo_usuario


# Comprobar si el usuario ya existe
if id "$nuevo_usuario" &>/dev/null; then
  echo "$nuevo_usuario ya existe."
else
  # Crear nuevo usuario
  sudo useradd "$nuevo_usuario"
  echo "Usuario $nuevo_usuario creado."
fi

echo "Grupo:"
read nuevo_grupo

# Comprobar si el grupo ya existe
if getent group "$nuevo_grupo" &>/dev/null; then
  echo "El grupo $nuevo_grupo ya existe."
else
# Crear nuevo grupo
  sudo groupadd "$nuevo_grupo"
  echo "El grupo $nuevo_grupo fue creado."
fi

# Agregar usuarios al grupo
sudo usermod -a -G "$nuevo_grupo" "$USER"
sudo usermod -a -G "$nuevo_grupo" "$nuevo_usuario"

# Asignar permisos de ejecución este script solo para miembros del grupo lab1.2
sudo chown :lab1 lab1.2.sh
chmod g+x lab1.2.sh

echo "El permiso de ejecución ha sido asignado solo a miembros del grupo $nuevo_grupo."


