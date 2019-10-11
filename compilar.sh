#!/bin/bash
gcc -c calculadora_clnt.c
gcc -c calculadora_svc.c

gcc -c servidor.c
gcc -c client.c

gcc -o client calculadora_clnt.o client.o
gcc -o server calculadora_svc.o servidor.o

mv client ./compilados/
mv server ./compilados/