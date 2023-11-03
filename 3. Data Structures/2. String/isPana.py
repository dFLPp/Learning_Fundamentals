# Checa se palavra é panagrama (tem todos os caracteres pelo menos uma vez)

def is_pangram(s):
    alphabet = "abcdefghijklmnopqrstuvwxyz"
    s = s.lower()

    for char in alphabet:
        if char not in s:
            return False

    return True

string = "The quick brown fox jumps over the lazy dog"
if is_pangram(string):
    print(f"'{string}' é um pangrama.")
else:
    print(f"'{string}' não é um pangrama.")