#!/bin/bash

if [[ "$OSTYPE" == "linux-gnu" ]]; then
    clear
elif [[ "$OSTYPE" == "darwin"* ]]; then
    clear
elif [[ "$OSTYPE" == "cygwin" ]]; then
    clear
elif [[ "$OSTYPE" == "msys" ]]; then
    cls
else
    echo "No se pudo limpiar la pantalla. Comando no soportado en este sistema."
fi