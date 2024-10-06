#include <iostream>
#include <string>

template <typename T>
struct Node{
    T data;
    Node* next;
};

template <typename T>
struct Set{
    Node<T>* head;
    std::size_t size;
};

template <typename T>
void initializeSet(Set<T>& set){
    set.head = nullptr;
    set.size = 0;
}

template <typename T>
void deleteSet(Set<T>& set){
    Node<T>* current = set.head;
    while(current){
        Node<T>* next = current->next;
        delete current;
        current = next;
    }
    set.head = nullptr;
    set.size = 0;
}

template <typename T>
bool is_empty(const Set<T>& set){
    return set.size == 0;
}

template <typename T>
bool contains(Set<T>& set, const T& value){
    Node<T>* current = set.head;
    while(current){
        if(current->data == value){
            return true;
        }
        current = current->next;
    }
    return false;
}

template <typename T>
void add(Set<T>* set, const T& value){
    if(contains(*set, value)){
        std::cerr << "Value already exists in set" << std::endl;
        return;
    }
    Node<T>* newNode = new Node<T>{value, set->head};
    set->head = newNode;
    ++set->size;
}

template <typename T>
void remove(Set<T>* set, const T& value){
    if(is_empty(*set)){
        std::cerr << "Set is empty" << std::endl;
        return;
    }
    Node<T>* current = set->head;
    Node<T>* prev = nullptr;
    while(current && current->data != value){
        prev = current;
        current = current->next;
    }
    if(!current){
        std::cerr << "Value not found in set" << std::endl;
        return;
    }
    if(!prev){
        set->head = current->next;
    } else {
        prev->next = current->next;
    }
    delete current;
    --set->size;
}

template <typename T>
void display(const Set<T>& set){
    if(is_empty(set)){
        std::cerr << "Set is empty" << std::endl;
        return;
    }
    Node<T>* current = set.head;
    while(current != nullptr){
        std::cout << current->data << std::endl;
        current = current->next;
    }
    std::cout << std::endl;
}

struct Pixel {
    int x, y;
    std::string color;
    bool working;
};

std::ostream& operator<<(std::ostream& os, const Pixel& p) {
    os << "X: " << p.x << ", Y: " << p.y << ", Is on: " << (p.working ? "Yes": "No" )  << ", Color: " << p.color;
    return os;
}

bool operator == (const Pixel& p1,const Pixel& p2) {
    return p1.x == p2.x && p1.y == p2.y && p1.color == p2.color && p1.working == p2.working;
}

bool operator!=(const Pixel& p1,const Pixel& p2) {
    return!(p1 == p2);
}


int main(){
    Set<Pixel> pixelSet;
    initializeSet(pixelSet);

    Pixel p1{1, 2, "Red", true};
    Pixel p2{3, 4, "Blue", false};
    Pixel p3{5, 6, "Green", true};
    Pixel p4{7, 8, "Yellow", false};
    Pixel p5{9, 10, "Purple", true};

    add(&pixelSet, p1);
    add(&pixelSet, p2);
    add(&pixelSet, p3);
    add(&pixelSet, p4);
    add(&pixelSet, p5);
    add(&pixelSet, p5);
    add(&pixelSet, p1);

    display(pixelSet);

    remove(&pixelSet, p2);
    remove(&pixelSet, p4);

    display(pixelSet);

    deleteSet(pixelSet);

    return 0;
}