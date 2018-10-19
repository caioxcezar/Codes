#!/bin/bash 

if type dotnet &> /dev/null
then
    echo "Nome do Projeto"
    read nome
    mkdir $nome
    cd $nome
    dotnet new console
else
    echo "dot net core não instalado"
fi