#include <iostream>
#include <string>
template<typename T>

struct Queue{
    T* data;
    std::size_t capacity;
    std::size_t front;
    std::size_t rear;
};

template<typename T>
void initializeQueue(Queue<T>& q, std::size_t intialcapacity){
    q.data = new T[intialcapacity];
    q.front = 0;
    q.rear = 0;
    q.capacity = intialcapacity;
}

template<typename T>

bool is_empty(const Queue<T>& queue){
    return queue.front == queue.rear;
}

template<typename T>
bool is_full(const Queue<T>& queue){
    return queue.rear == queue.capacity;
}

/*template<typename T>
void resizeQueue(Queue<T>& q, std::size_t newcapacity){
    T* newData = new T[newcapacity];
    for(std::size_t i = 0; i < q.capacity; ++i){
        newData[i] = q.data[i];
    }
    free(q.data);
    q.data = newData;
    q.capacity = newcapacity;
}*/

template<typename T>
void enqueue(Queue<T>& q, T value){
    if(is_full(q)){
        std::cerr << "The queue is full!" << std::endl;
    }
    q.data[q.rear++] = value;
}

template<typename T>
void dequeue(Queue<T>& q){
    if(is_empty(q)){
        std::cerr << "The queue is empty!" << std::endl;
    }
    q.data[q.front++];
}

template<typename T>
void displayQueue(const Queue<T>& queue){
    for(std::size_t i = queue.front; i < queue.rear; ++i){
        std::cout << queue.data[i] << " ";
    }
    std::cout << std::endl;
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
    initializeQueue(myQueue, 5);

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