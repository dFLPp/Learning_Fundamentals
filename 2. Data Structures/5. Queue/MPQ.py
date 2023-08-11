# Max priority queue
# Uma priority queue boladona usa heaps (arvorés binárias frufru) 
# como ainda não chegamos lá vamos com uma versão básica/simples

class MaxPriorityQueue:
    def __init__(self):
        self.queue = []

    def push(self, item):
        self.queue.append(item)
        self.queue.sort(reverse=True)

    def pop(self):
        return self.queue.pop(0)

    def peek(self):
        return self.queue[0]

    def size(self):
        return len(self.queue)

max_pq = MaxPriorityQueue()
max_pq.push(5)
max_pq.push(2)
max_pq.push(8)

print("Tamanho:", max_pq.size())
print("Topo:", max_pq.peek())

# basicamente a ordem de inserção não importa 
# uma vez que o algoritimo interno de prioridade vai reordenar a lista
# nesse caso o maior elemento sempre fica no inicio da fila