#include <iostream>
#include <string>
template<typename T>

struct Stack{
    T* data;
    std::size_t capacity;
    std::size_t front;
    std::size_t size;
};

template<typename T>
void initializeStack(Stack<T>& s, std::size_t intialcapacity){
    s.data = new T[intialcapacity];
    s.front = 0;
    s.size = 0;
    s.capacity = intialcapacity;
}

template<typename T>

bool is_empty(const Stack<T>& stack){
    return stack.size == 0;
}

template<typename T>
bool is_full(const Stack<T>& stack){
    return stack.size == stack.capacity;
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
void add(Stack<T>& s, T value){
    if(is_full(s)){
        std::cerr << "The stack is full!" << std::endl;
    }
    s.data[s.front++] = value;
    ++s.size;
}

template<typename T>
void remove(Stack<T>& s){
    if(is_empty(s)){
        std::cerr << "The stack is empty!" << std::endl;
    }
    s.data[s.front--];
    --s.size;
}

template<typename T>
void displayStack(const Stack<T>& stack){
    for(std::size_t i = stack.front; i > 0; --i){
        std::cout << stack.data[i - 1] << " ";
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
    
    Stack<Process> myStack;
    initializeStack(myStack, 5);

    Process p1 = {8, true, "Main.exe"};
    Process p2 = {43, true, "Windows.dll"};
    Process p3 = {7754, false, "Discoed.exe"};
    Process p4 = {3241, true, "system32"};
    Process p5 = {654, true, "Steam.exe"};

    add(myStack, p1);
    add(myStack, p2);
    add(myStack, p3);
    add(myStack, p4);
    add(myStack, p5);

    displayStack(myStack);

    remove(myStack);
    remove(myStack);

    displayStack(myStack);

    return 0;
}