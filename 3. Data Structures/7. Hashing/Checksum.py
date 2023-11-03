# Unsando hashing para verificar a Integridade
# isso é usado para verificar se os arquivos que vc baixa pela internet vieram realmente do site que vc clicou
# Pq pode ser que alguem intercepte os packets do site (veja 1. Internet) e mande alguns maliciosos. 

import hashlib

# Função para criar um hash MD5
def calculate_md5(data):
    md5_hash = hashlib.md5()
    md5_hash.update(data.encode('utf-8'))
    return md5_hash.hexdigest()

# Dados originais
original_data = "Hello, world!"

# Dados alterados
modified_data = "Hello, world?!"

original_hash = calculate_md5(original_data)
modified_hash = calculate_md5(modified_data)

print(f"Original Hash: {original_hash}")
print(f"Modified Hash: {modified_hash}")

if original_hash == modified_hash:
    print("Os dados estão íntegros.")
else:
    print("Os dados foram alterados.")
