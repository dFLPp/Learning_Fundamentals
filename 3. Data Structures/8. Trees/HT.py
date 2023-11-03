# Heap tree
## Vou ser completamente sincero, n faço a mín ideia de como isso funciona. N pq é dificil, mas pq parece ser chato
## Se vc for/quer ser um Chad, tem que aguentar aprender coisas difíceis que não apresentam utilidade imediata.
## BTW, antes de olhar isso aq, tenha domínio/conhecimento de como level-order traversal funciona

class MinHeap:
    def __init__(self):
        self.heap = []

    def push(self, val):
        self.heap.append(val)
        self._heapify_up()

    def pop(self):
        if len(self.heap) == 0:
            return None
        if len(self.heap) == 1:
            return self.heap.pop()
        root = self.heap[0]
        self.heap[0] = self.heap.pop()
        self._heapify_down(0)
        return root

    def _heapify_up(self):
        index = len(self.heap) - 1
        while index > 0:
            parent_index = (index - 1) // 2
            if self.heap[index] < self.heap[parent_index]:
                self.heap[index], self.heap[parent_index] = self.heap[parent_index], self.heap[index]
                index = parent_index
            else:
                break

    def _heapify_down(self, index):
        left_child_index = 2 * index + 1
        right_child_index = 2 * index + 2
        smallest = index

        if (
            left_child_index < len(self.heap)
            and self.heap[left_child_index] < self.heap[smallest]
        ):
            smallest = left_child_index

        if (
            right_child_index < len(self.heap)
            and self.heap[right_child_index] < self.heap[smallest]
        ):
            smallest = right_child_index

        if smallest != index:
            self.heap[index], self.heap[smallest] = self.heap[smallest], self.heap[index]
            self._heapify_down(smallest)

# Example usage:
heap = MinHeap()
heap.push(3)
heap.push(1)
heap.push(4)
heap.push(2)

print(heap.pop())  # Output: 1
print(heap.pop())  # Output: 2
