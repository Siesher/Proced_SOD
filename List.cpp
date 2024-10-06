#include <iostream>
#include <string>

template<typename T>
struct List{
    T* data;
    std::size_t size;
    std::size_t N;
};

template<typename T>
void initializeList(List<T>& list, std::size_t N){
    list.data = new T[N];
    list.N = N;
}

template<typename T>
void deleteList(List<T>& list){
    delete[] list.data;
}

template<typename T>
bool is_empty(List<T>& list){
    return list.size == 0;
}

template<typename T>
bool is_full(List<T>& list){
    return list.size == list.N;
}

template<typename T>
void add(List<T>& list, const T& value, std::size_t index){
    if(is_full(list)){
        std::cerr << "List is full" << std::endl;
        return;
    }
    if(index >= list.N){
        std::cerr << "Invalid index" << std::endl;
        return;
    }
    for(std::size_t i = list.size; i > index; --i){
        list.data[i] = list.data[i - 1];
    }
    list.data[index] = value;
    ++list.size;
}

template<typename T>
void remove(List<T>& list, std::size_t index){
    if(is_empty(list)){
        std::cerr << "List is empty" << std::endl;
        return;
    }
    if(index >= list.size){
        std::cerr << "Invalid index" << std::endl;
        return;
    }
    for(std::size_t i = index; i < list.size - 1; ++i){
        list.data[i] = list.data[i + 1];
    }
    --list.size;
}

template<typename T>
void display(List<T>& list){
    if(is_empty(list)){
        std::cout << "List is empty" << std::endl;
        return;
    }
    for(std::size_t i = 0; i < list.size; ++i){
        std::cout << list.data[i] << " ";
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
    List<Process> processList;
    initializeList(processList, 10);

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

