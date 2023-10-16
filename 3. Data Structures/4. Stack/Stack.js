//stack com array

class Stack {
  static MAX_SIZE = 1000;
  topIndex;
  items;

  constructor(size) {
    if (size > 0 && size <= Stack.MAX_SIZE) {
      this.topIndex = 0;
      this.items = Array(size).fill(0);
    } else {
      console.log("Tamanho inválido.");
    }
  }

  push(value) {
    if (this.topIndex >= this.items.length) {
      console.log("A pilha está cheia.");
      return;
    }
    if (typeof value === "undefined") {
      console.log("valor inválido.");
      return;
    }

    this.items[this.topIndex] = value;
    this.topIndex += 1;
  }

  pop() {
    if (this.topIndex > 0) {
      this.topIndex -= 1;
      this.items[this.topIndex] = 0;
    } else {
      console.log("A pilha está vazia.");
    }
  }

  peek() {
    if (this.isEmpty()) {
      console.log("A pilha está vazia.");
    } else {
      console.log("Top:", this.items[this.topIndex - 1]);
    }
  }

  print() {
    this.items.forEach((el, i) => {
      console.log(`${i}: ${el}`);
    });
  }

  isEmpty() {
    return this.topIndex === 0;
  }
}

let s1 = new Stack(3);

s1.push(1);
s1.push("a");
s1.peek();

s1.push({ bananas: true });
s1.push(false);

s1.print();
s1.pop();
s1.print();
