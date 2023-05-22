from time import sleep
import os

texto_base = """/*
    * Função: 
    * Autor: Pedro Peixoto Viana de Oliveira
    * Data: 22/maio/2023
    * Observações: 
*/


#include <stdio.h>

int main() {
    


    return 0;
}
"""

qtd_arquivos = 9
lista = 3

print("Criando os arquivos...")
sleep(1)

for i in range(qtd_arquivos):
    porcentagem = ((i + 1) / qtd_arquivos) * 100
    print("{:.2f}% completo...".format(porcentagem))
    with open(f"Lista {lista}/questao0{i+1}.c", "w", encoding="utf-8") as arquivo:
        arquivo.write(texto_base)  
        arquivo.close()
    sleep(0.5)

print("Todos os arquivos foram criados com sucesso!")
