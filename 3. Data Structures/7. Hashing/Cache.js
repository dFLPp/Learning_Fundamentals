//usando maps para armazenar dados em cache

class Cache {
  constructor(maxSize) {
    this.maxSize = maxSize;
    this.cache = new Map(); //esse map é um hashmap (que é a msm coisa que hash table)
  }

  get(key) {
    if (this.cache.has(key)) {
      const value = this.cache.get(key);
      // Mover o item para o final para indicar que foi acessado recentemente
      this.cache.delete(key);
      this.cache.set(key, value);
      return value;
    }
    return null;
  }

  set(key, value) {
    if (this.cache.size >= this.maxSize) {
      // Remover o primeiro item (o mais antigo) quando o limite é atingido
      const oldestKey = this.cache.keys().next().value;
      this.cache.delete(oldestKey);
    }
    this.cache.set(key, value);
  }
}

const cache = new Cache(3); // Tamanho máximo do cache

cache.set("user1", { name: "Alice" });
cache.set("user2", { name: "Bob" });
cache.set("user3", { name: "Charlie" });

console.log(cache.get("user1")); // Retorna { name: "Alice" }

cache.set("user4", { name: "David" }); // Remove o item mais antigo ("user2") - repare que "user1" foi usado na operação anterior
console.log(cache.get("user2")); // Retorna null
