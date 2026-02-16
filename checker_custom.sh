#!/usr/bin/env bash

# Parámetro de entrada
N=$1
FLAG=$2

# Definición de colores
YELLOW='\033[0;33m'
NC='\033[0m' # No Color (Reset)

# Mensaje con color
echo -e "${YELLOW}Running tester for $N numbers...${NC}"

shuf -i 0-9999 -n "$N" > arg.txt ; ./push_swap $FLAG $(cat arg.txt) | ./checker_linux $(cat arg.txt)
valgrind ./push_swap $(cat arg.txt) $FLAG --bench 

rm arg.txt