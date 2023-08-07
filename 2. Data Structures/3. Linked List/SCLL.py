# Singly circular linked list

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

    def __repr__(self):
        return str(self.data)


class SCLL:
    def __init__(self):
        self.head = None
        self.size = 0

    def add(self, data, position=None):
        if position is None:
            position = self.size + 1

        if position <= 0 or position > self.size + 1:
            print("Posição inválida")
            return

        new_node = Node(data)

        if self.head is None:
            self.head = new_node
            self.head.next = self.head
        else:
            if position == 1:
                new_node.next = self.head
                temp = self.head
                while temp.next != self.head:
                    temp = temp.next
                temp.next = new_node
                self.head = new_node
            else:
                temp = self.head
                for _ in range(position - 2):
                    temp = temp.next
                new_node.next = temp.next
                temp.next = new_node

        self.size += 1

    def remove_at(self, position):
        if position > self.size or position <= 0:
            print("Posição inválida")
            return

        if position == 1:
            if self.size == 1:
                self.head = None
            else:
                temp = self.head
                while temp.next != self.head:
                    temp = temp.next
                temp.next = self.head.next
                self.head = self.head.next
        else:
            curr = self.head
            prev = curr

            for _ in range(position - 1):
                prev = curr
                curr = curr.next

            prev.next = curr.next

        self.size -= 1

    def __repr__(self):
        items = []
        temp = self.head

        while True:
            items.append(str(temp.data))
            temp = temp.next

            if temp == self.head:
                break

        return " -> ".join(items)


ll = SCLL()
ll.add('a')
ll.add(3)
ll.add(-1)
ll.add(5)
ll.add('b', 1)
print(ll)

ll.remove_at(1)
ll.remove_at(-1)
ll.remove_at(5)

print(ll)