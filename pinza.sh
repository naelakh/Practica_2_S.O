#!/bin/bash

#Compile the C++ program 
g++ -o pinza pinza.cpp

if [ $? -ne 0 ]; then
    echo "Error: la compilacion fallo"
    exit 1
fi

echo "Compilacion bien "

sh -c "./pinza" &
PID=$!
echo "Proceso lanzado en segundo plano con PID: $PID"

#Esperar para que el proceso termina 
wait $PID
echo "El proceso ha terminado"

#asegurar si if is still running
if kill -0 $PID 2>/dev/null; then
    echo "El proceso sigue activo. Finalizando..."
    kill $PID
    echo "Proceso $PID terminado manualmente"
else
    echo "El proceso ya habia terminado correctamente"
fi
