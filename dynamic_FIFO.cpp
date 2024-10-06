#include <iostream>
#include <string>
template<typename T>
struct Node{
    T data;
    Node* next;
};

template<typename T>
struct Queue{
    Node<T>* front;
    Node<T>* rear;
    std::size_t size;
};

template<typename T>
void initializeQueue(Queue<T>& q){
    q.front = nullptr;
    q.rear = nullptr;
    q.size = 0;
}

template<typename T>

bool is_empty(const Queue<T>& queue){
    return queue.front == nullptr;
}

template<typename T>
void enqueue(Queue<T>& q, const T& value){
    Node<T>* newNode = new Node<T>{value, nullptr};
    if(is_empty(q)){
        q.front = newNode;
        q.rear = newNode;
    } else {
        q.rear->next = newNode;
        q.rear = newNode;
    }
    q.size++;
}

template<typename T>
void dequeue(Queue<T>& q){

    if(is_empty(q)){
        std::cerr << "The queue is empty!" << std::endl;
    }

    Node<T>* temp = q.front;
    T val = temp->data;
    q.front = q.front->next;

    if(q.front == nullptr){
        q.rear = nullptr;
    }

    delete temp;
    q.size--;
}

template<typename T>
void displayQueue(const Queue<T>& queue){
    Node<T>* current = queue.front;
    while(current){
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

template<typename T>
void freeQueue(Queue<T>& q) {
    while (!is_empty(q)) {
        dequeue(q);
    }
}

struct Process {
    int id;
    bool status;
    std::string name;
};

std::ostream& operator<<(std::ostream& os, const Process& p) {
    os << "ID: " << p.id << ", Status: " << (p.status ? "Running" : "Stopped") << ", Name: " << p.name << std::endl;
    return os;
}


int main(){
    
    Queue<Process> myQueue;
    initializeQueue(myQueue);

    Process p1 = {8, true, "Main.exe"};
    Process p2 = {43, true, "Windows.dll"};
    Process p3 = {7754, false, "Discoed.exe"};
    Process p4 = {3241, true, "system32"};
    Process p5 = {654, true, "Steam.exe"};

    enqueue(myQueue, p1);
    enqueue(myQueue, p2);
    enqueue(myQueue, p3);
    enqueue(myQueue, p4);
    enqueue(myQueue, p5);

    displayQueue(myQueue);

    dequeue(myQueue);
    dequeue(myQueue);

    displayQueue(myQueue);

    return 0;
}