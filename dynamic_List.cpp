#include <iostream>
#include <string>

template<typename T>
struct Node {
    T data;
    Node* next;
};

template<typename T>
struct List {
    Node<T>* head;
    std::size_t size;
};

template<typename T>
void initializeList(List<T>& list) {
    list.head = nullptr;
    list.size = 0;
}

template<typename T>
void deleteList(List<T>& list) {
    Node<T>* current = list.head;
    while (current != nullptr) {
        Node<T>* next = current->next;
        delete current;
        current = next;
    }
    list.head = nullptr;
    list.size = 0;
}

template<typename T>
bool is_empty(const List<T>& list) {
    return list.size == 0;
}

template<typename T>
void add(List<T>& list, const T& value, std::size_t index) {
    if (index > list.size) {
        std::cerr << "Invalid index" << std::endl;
        return;
    }

    Node<T>* newNode = new Node<T>{value, nullptr};

    if (index == 0) {
        newNode->next = list.head;
        list.head = newNode;
    } else {
        Node<T>* current = list.head;
        for (std::size_t i = 0; i < index - 1; ++i) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    ++list.size;
}

template<typename T>
void remove(List<T>& list, std::size_t index) {
    if (is_empty(list)) {
        std::cerr << "List is empty" << std::endl;
        return;
    }
    if (index >= list.size) {
        std::cerr << "Invalid index" << std::endl;
        return;
    }

    Node<T>* toDelete = nullptr;

    if (index == 0) {
        toDelete = list.head;
        list.head = list.head->next;
    } else {
        Node<T>* current = list.head;
        for (std::size_t i = 0; i < index - 1; ++i) {
            current = current->next;
        }
        toDelete = current->next;
        current->next = toDelete->next;
    }

    delete toDelete;
    --list.size;
}

template<typename T>
void display(const List<T>& list) {
    if (is_empty(list)) {
        std::cout << "List is empty" << std::endl;
        return;
    }

    Node<T>* current = list.head;
    while (current != nullptr) {
        std::cout << current->data << std::endl;
        current = current->next;
    }
    std::cout << std::endl;
}

struct Process {
    int id;
    bool status;
    std::string name;
};

std::ostream& operator<<(std::ostream& os, const Process& p) {
    os << "ID: " << p.id << ", Status: " << (p.status ? "Running" : "Stopped") << ", Name: " << p.name;
    return os;
}

int main() {
    List<Process> processList;
    initializeList(processList);

    Process p1 = {1, true, "Process 1"};
    Process p2 = {2, false, "Process 2"};
    Process p3 = {3, true, "Process 3"};
    Process p4 = {4, false, "Process 4"};
    Process p5 = {5, true, "Process 5"};

    add(processList, p1, 0);
    add(processList, p2, 1);
    add(processList, p3, 2);
    add(processList, p4, 3);
    add(processList, p5, 4);

    add(processList, p1, 3);
    add(processList, p2, 4);

    display(processList);

    remove(processList, 2);
    remove(processList, 5);

    display(processList);

    deleteList(processList);

    return 0;
}
