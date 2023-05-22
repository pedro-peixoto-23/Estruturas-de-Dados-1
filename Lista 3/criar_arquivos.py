from time import sleep

texto_base = """/*
    * Função: 
    * Autor: Pedro Peixoto Viana de Oliveira
    * Data: 22/maio/2023
    * Observações: 
*/"""

qtd_arquivos = 9
print("Criando os arquivos...")
sleep(1)
for i in range(qtd_arquivos):
    porcentagem = ((i + 1) / qtd_arquivos) * 100
    print("{:.2f}% completo...".format(porcentagem))
    arquivo = open(f"questao0{i+1}.c", "w", encoding="utf-8")
    arquivo.write(texto_base)
    arquivo.close()
    sleep(0.5)
print("Todos os arquivos foram criados com sucesso!")