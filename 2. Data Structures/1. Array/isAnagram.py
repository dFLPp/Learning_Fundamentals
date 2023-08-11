# Anagrama de uma palavra com arrays
# Anagrama e

def is_anagram(str1, str2):
    str1 = str1.replace(" ", "").lower()
    str2 = str2.replace(" ", "").lower()

    if len(str1) != len(str2):
        return False

    char_count = [0] * 26  # Um array para contar as ocorrências de cada caractere

    for char in str1:
        char_count[ord(char) - ord('a')] += 1

    for char in str2:
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
