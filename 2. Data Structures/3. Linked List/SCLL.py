# Singly circular linked list

class Node():
    def __init__(self, data: type) -> None:
        self.data = data;
        self.next = None;

    def __repr__(self) -> str:
        return str(self.data);

class LinkedList():
    def __init__(self) -> None:
        self.head = None;
        self.size = 0;

    def __createNode(self, data: type) -> Node:
        return Node(data);


    def addAt(self, data: type, position: int = None) -> None:
        if position is None:
            position = self.size;

        if position <= 0 or position - self.size > 1:
            print("Posição inválida");
            return

        node = self.__createNode(data);
        node.next = self.head;

        if self.head is None:
            self.head = node;
        else:
            temp = self.head;
            for _ in range(position):
                temp = temp.next;
            temp.next = node;


        self.size += 1;

    def removeAt(self, position: int) -> None:
        t1 = self.head;
        t2 = t1;

        if position > self.size or position <= 0:
            print("Posição inválida");
            return;

        for _ in range(position):
            t2 = t1;
            t1 = t1.next;
        
        t2.next = t1.next;

    def __repr__(self) -> str:
        items = [];
        temp = self.head;
        
        while temp is not None:
            items.append(str(temp.data));
            temp = temp.next;
            
        return " -> ".join(items);
        
        
ll = LinkedList();
ll.addAt('a');
ll.addAt(3);

print(ll);