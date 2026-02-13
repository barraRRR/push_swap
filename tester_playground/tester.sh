#!/bin/bash

# --- CONFIGURACIÓN ---
PUSH_SWAP="../push_swap"
CHECKER="./checker_Mac" # Cambia a checker_Mac o linux
# ---------------------

if [ $# -ne 1 ]; then
    echo "Uso: $0 <cantidad_de_numeros>"
    exit 1
fi

# 1. Generar números aleatorios usando Python3 (sin duplicados)
ARG=$(python3 -c "import random; print(' '.join(map(str, random.sample(range(-5000, 5000), $1))))")

# 2. Comprobar si push_swap existe
if [ ! -f $PUSH_SWAP ]; then
    echo "Error: No encuentro el ejecutable en $PUSH_SWAP"
    echo "Asegúrate de haber hecho 'make' en la raíz."
    exit 1
fi

# 3. Ejecutar y contar
MOVES=$($PUSH_SWAP $ARG)
COUNT=$(echo "$MOVES" | wc -l | tr -d ' ')

echo "---------------------------------------"
echo "Test con $1 números"
echo "Movimientos totales: $COUNT"

# 4. Verificar con checker si existe
if [ -f $CHECKER ]; then
    RES=$(echo "$MOVES" | $CHECKER $ARG)
    echo "Resultado: $RES"
else
    echo "Resultado: (Checker no encontrado)"
fi
echo "---------------------------------------"