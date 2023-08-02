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

# IF YOU ARE USING TERMUX ON ANDROID, MODIFY THIS FILE TO: 'CLEAR'
# THE CODE IN THIS FILE SHOULD LOOK LIKE:
#
# #!/bin/bash
# clear
#
# END OF CODE
