#!/bin/bash
echo "Do you want to restart or continue the last game? (restart/continue)"
read choice
if [ "$choice" == "restart" ]
then
    rm memory.txt
    touch memory.txt
fi
./main
