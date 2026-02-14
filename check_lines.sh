#!/usr/bin/env bash

# Parámetro de entrada
N=$1

# Definición de colores
YELLOW='\033[0;33m'
NC='\033[0m' # No Color (Reset)

# Mensaje con color
echo -e "${YELLOW}Running tester for $N numbers...${NC}"

# Generar números, guardarlos y ejecutar push_swap
# Nota: Usamos $(cat arg.txt) con precaución por el límite de argumentos
shuf -i 0-9999 -n "$N" > arg.txt
./push_swap $(cat arg.txt) | wc -l