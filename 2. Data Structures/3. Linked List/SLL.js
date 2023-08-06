class Node {
  constructor(data) {
    this.data = data;
    this.next = null;
  }
}

class SLL {
  constructor() {
    this.head = null;
    this.nNodes = 0;
  }

  #createNode(data) {
    return new Node(data);
  }

  addNode(data) {
    if (this.head == null) this.head = this.#createNode(data);
    else {
      let lastNode = this.head;
      while (lastNode.next != null) {
        lastNode = lastNode.next;
      }

      lastNode.next = this.#createNode(data);
    }
    this.nNodes++;
  }

  removeNodeAt(position) {
    if (position <= 0 || position > this.nNodes)
      return console.log("Não existem dados nessa posição");
    else {
      let t1 = this.head;
      let t2 = t1;

      if (position === 1) {
        this.head = t1.next;
      } else {
        for (let i = 1; i < position; i++) {
          t2 = t1;
          t1 = t1.next;
        }

        t2.next = t1.next;
      }
      this.nNodes--;
    }
  }

  printList() {
    let temp = this.head;
    let str = "";
    while (temp.next != null) {
      str += temp.data;
      str += "->";
      temp = temp.next;
    }
    str += temp.data;
    console.log(str);
  }
}

let myList = new SLL();
myList.addNode(10);
myList.addNode(20);
myList.addNode(30);
myList.printList();

myList.removeNodeAt(-1);
myList.removeNodeAt(500);
myList.removeNodeAt(3);
myList.printList();
