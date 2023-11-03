// Array simple queue

class Queue {
  #size;
  #data;

  constructor(size) {
    this.#size = size;
    this.#data = [];
  }

  getSize() {
    return this.#size;
  }

  printData() {
    if (this.#data.length > 0) {
      this.#data.forEach((e, i) => {
        console.log(`${i}: ${e}`);
      });
    } else {
      console.log("Queue vazia");
    }
  }

  enqueue(data) {
    if (this.#data.length >= this.#size) {
      console.log("Queue cheia");
    } else {
      this.#data.push(data);
    }
  }

  dequeue() {
    if (this.#data.length === 0) {
      console.log("Queue já está vazia");
    } else {
      this.#data.shift();
    }
  }

  peek() {
    if (this.#data.length > 0) {
      console.log(this.#data[0]);
    } else {
      console.log("Queue vazia");
    }
  }
}

const q = new Queue(3);
q.enqueue(7);
q.enqueue(false);
q.printData();
q.dequeue();
console.log("Size:", q.getSize());
q.peek();
