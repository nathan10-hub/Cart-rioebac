#!/bin/bash

echo "Calculadora simples"

echo "Digite o primeiro número:"
read num1

echo "Digite o segundo número:"
read num2

echo "Escolha a operação:"
echo "1 - Soma"
echo "2 - Subtração"
echo "3 - Multiplicação"
echo "4 - Divisão"

read operacao

if [ $operacao -eq 1 ]
then
    resultado=$((num1 + num2))
    echo "Resultado: $resultado"
elif [ $operacao -eq 2 ]
then
    resultado=$((num1 - num2))
    echo "Resultado: $resultado"
elif [ $operacao -eq 3 ]
then
    resultado=$((num1 * num2))
    echo "Resultado: $resultado"
elif [ $operacao -eq 4 ]
then
    resultado=$((num1 / num2))
    echo "Resultado: $resultado"
else
    echo "Operação inválida"
fi
