## Stack com linked list

class Elem:
    def __init__(self, value:int) -> None:
        self.value = value;
        self.next = None;

    def __repr__(self) -> str:
        return str(self.value);

class Stack:
    def __init__(self) -> None:
        self.top = None;
        self.size = 0;

    def push(self, value:int) -> None:
        el:Elem = Elem(value);
        el.next = self.top;
        self.top = el;
        self.size += 1;

    def pop(self) -> None:
        if self.size <= 0: return
        self.top = self.top.next;
        self.size -= 1;

    def peek(self) -> None:
        print(f"Top: {self.top.value}");

    def __repr__(self) -> str:
        l:list = [];
        curr:Elem = self.top
        while curr is not None:
            l.append(str(curr.value))
            curr = curr.next
        return ", ".join(l)

s1:Stack = Stack();
s1.push(1);
s1.push(-3);
s1.pop();
s1.peek();
s1.push(4);
print(s1);