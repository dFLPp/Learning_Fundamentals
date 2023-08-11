// Linked list Simple Queue
// Como n quero re-implementar um Llist aq vou usar cpp pq ja vem pronto
// Alem disso, tipo, em C dá pra "relevar" pq são structs e tals
// mas em cpp n existe desculpa para vc fazer n separar os arquivos em .h e .cpp
// mas vou fazer msm assim =)

#include <iostream>
#include <list>
using namespace std;

class Queue
{
private:
    list<int> data;

public:
    void enqueue(int value)
    {
        this->data.push_back(value);
    }

    void dequeue()
    {
        if (!this->data.empty())
        {
            this->data.pop_front();
        }
    }

    int peek()
    {
        if (!this->data.empty())
        {
            return this->data.front();
        }
        return -1;
    }

    void printQ()
    {
        for (int item : this->data)
        {
            cout << item << endl;
        }
    }
};

int main()
{
    Queue q;
    q.enqueue(1);
    q.enqueue(-3);
    q.dequeue();
    cout << q.peek() << endl;
    q.enqueue(0);
    q.printQ();

    return 0;
}