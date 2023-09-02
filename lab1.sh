#! /bin/bash

#Verifica que el usuario haya puesto algun argumento para ejecutar funcion
if [ $# -ne 1 ]; then
    echo "Debe proporcionar un argumento valido."
    exit 1
fi


file="$1"

#Verificar si existe archivo

if [ -e "$file" ]; then
	echo "El archivo '$file' ya existe."  #Si el archivo existe.
	permisos=$(stat -c "%A%" $file)  #Obtener permisos 1a
	get_permissions_verbose() {
		local permisos="$1"
		local usuario="${permisos:1:3}"
		local grupo="${permisos:4:3}"
 		local otros="${permisos:7:3}"

		echo "Permisos del usuario:"
		interpretar_permisos "$usuario"
		echo "Permisos del grupo:"
		interpretar_permisos "$grupo"
		echo "Permisos de otros:"
		interpretar_permisos "$otros"
	}
else
	echo "El archivo '$file_path' ya existe."
fi

# Función para interpretar los permisos
interpretar_permisos() {
  local permisos="$1"
  for ((i = 0; i < ${#permisos}; i++)); do
    case "${permisos:$i:1}" in
      "r")
        echo "  Lectura"
        ;;
      "w")
        echo "  Escritura"
        ;;
      "x")
        echo "  Ejecución"
        ;;
      "-")
        echo "  Sin permiso"
        ;;
      *)
        echo "  Permiso desconocido: ${permisos:$i:1}"
        ;;
    esac
  done
}

# Llamar a la función para mostrar los permisos de forma detallada
get_permissions_verbose "$permisos"
