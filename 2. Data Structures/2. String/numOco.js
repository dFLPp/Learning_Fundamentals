// Numero de ocorrencias de palavras em uma frase:

function countWordOccurrences(text) {
  //regex básico para separar a string em array para cada espaço
  const words = text.toLowerCase().split(/\s+/);
  const wordCount = {};

  words.forEach((word) => {
    if (word in wordCount) {
      wordCount[word]++;
    } else {
      wordCount[word] = 1;
    }
  });

  return wordCount;
}

const text =
  "Esta é uma frase de teste. Teste esta frase para contar o número de vezes que as palavras aparecem.";
const wordOccurrences = countWordOccurrences(text);
console.log("Ocorrências de palavras:", wordOccurrences);
