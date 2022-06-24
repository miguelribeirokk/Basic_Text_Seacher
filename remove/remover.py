arquivo = open("remove/add.txt", "r")
for linha in arquivo:
    palavra = linha.split()
    for palavra in palavra:
        palavra = ''.join(filter(str.isalnum, palavra))
        arquivo2 = open("remove/novo.txt", "a")
        arquivo2.write(palavra + " ")
        arquivo2.close()
    arquivo2 = open("remove/novo.txt", "a")
    arquivo2.write("\n")
    arquivo2.close()
arquivo.close()

