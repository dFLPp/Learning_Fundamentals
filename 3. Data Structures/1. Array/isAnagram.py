# Anagrama de uma palavra

def is_anagram(str1, str2):
    str1 = str1.replace(" ", "").lower()
    str2 = str2.replace(" ", "").lower()

    if len(str1) != len(str2):
        return False

    char_count = [0] * 26  # Cada posição representa uma letra do alfabeto

    for char in str1:
        if 'a' <= char <= 'z':  # lidando com caract especiais
            char_count[ord(char) - ord('a')] += 1 # decidindo qual a posição com base no valor unicode

    for char in str2:
        if 'a' <= char <= 'z':
            char_count[ord(char) - ord('a')] -= 1

    for count in char_count:
        if count != 0:
            return False

    return True

string1 = "listen"
string2 = "silent"
if is_anagram(string1, string2):
    print(f"'{string1}' e '{string2}' são anagramas.")
else:
    print(f"'{string1}' e '{string2}' não são anagramas.")
