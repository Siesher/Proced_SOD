#include <iostream>
#include <string>

template<typename T>
struct Node{
    T data;
    Node* next;
};

template<typename T>
struct Stack{
    Node<T>* top;
    std::size_t size;
};

template<typename T>
void initializeStack(Stack<T>& s){
    s.top = nullptr;
    s.size = 0;
}

template<typename T>
bool is_empty(const Stack<T>& stack){
    return stack.top == nullptr;
}

template<typename T>
void push(Stack<T>& s, const T& value){
    Node<T>* newNode = new Node<T>{value, s.top};
    s.top = newNode;
    s.size++;
}

template<typename T>
void pop(Stack<T>& s){
    if(is_empty(s)){
        std::cerr << "The stack is empty!" << std::endl;
        return;
    }

    Node<T>* temp = s.top;
    s.top = s.top->next;
    delete temp;
    s.size--;
}

template<typename T>
T top(const Stack<T>& s){
    if(is_empty(s)){
        std::cerr << "The stack is empty!" << std::endl;
        throw std::runtime_error("Stack is empty");
    }
    return s.top->data;
}

template<typename T>
void displayStack(const Stack<T>& stack){
    Node<T>* current = stack.top;
    while(current){
        std::cout << current->data;
        current = current->next;
    }
    std::cout << std::endl;
}

template<typename T>
void freeStack(Stack<T>& s) {
    while (!is_empty(s)) {
        pop(s);
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


int main() {
    Stack<Process> myStack;
    initializeStack(myStack);

    Process p1 = {8, true, "Main.exe"};
    Process p2 = {43, true, "Windows.dll"};
    Process p3 = {7754, false, "Discord.exe"};
    Process p4 = {3241, true, "system32"};
    Process p5 = {654, true, "Steam.exe"};

    push(myStack, p1);
    push(myStack, p2);
    push(myStack, p3);
    push(myStack, p4);
    push(myStack, p5);

    displayStack(myStack);

    pop(myStack);
    pop(myStack);

    displayStack(myStack);

    return 0;
}