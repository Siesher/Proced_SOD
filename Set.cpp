#include <iostream>
#include <string>

template<typename T>
struct Set{
    std::size_t size;
    T* data;
    std::size_t N;
};

template<typename T>
void initializeSet(Set<T>& set, std::size_t N){
    set.data = new T[N];
    set.size = 0;
    set.N = N;
}

template<typename T>
void deleteSet(Set<T>& set){
    delete[] set.data;
}

template<typename T>
bool is_empty(const Set<T>& set){
    return set.size == 0;
}

template<typename T>
bool is_full(Set<T>& set){
    return set.size == set.N;
}

template<typename T>
bool contains(Set<T>& set, const T& value){
    for(std::size_t i = 0; i != set.size; ++i){
        if(set.data[i] == value) return true;
    }
    return false;
}

template<typename T>
void add(Set<T>& set, const T& value){
    if(is_full(set)){
        std::cerr << "Set is full!" << std::endl;
        return;
    }
    if(contains(set, value)){
        std::cerr << "Value already exists in the set!" << std::endl;
        return;
    }
    set.data[set.size++] = value;
}

template<typename T>
void remove(Set<T>& set, const T& value) {
    if (is_empty(set)) {
        std::cerr << "Set is empty" << std::endl;
        return;
    }
    for (std::size_t i = 0; i < set.size; ++i) {
        if (set.data[i] == value) {
            for (std::size_t j = i; j < set.size - 1; ++j) {
                set.data[j] = set.data[j + 1];
            }
            --set.size;
            return;
        }
    }
    std::cerr << "Value not found in the set" << std::endl;
}


template<typename T>
void display(const Set<T>& set){
    if(is_empty(set)){
        std::cout << "Set is empty!" << std::endl;
        return;
    }
    for(std::size_t i = set.size; i != 0; --i){
        std::cout << set.data[i - 1] << std::endl;
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


int main(){
    Set<Pixel> pixelSet;
    initializeSet(pixelSet, 10);

    Pixel p1{1, 2, "Red", true};
    Pixel p2{3, 4, "Blue", false};
    Pixel p3{5, 6, "Green", true};
    Pixel p4{7, 8, "Yellow", false};
    Pixel p5{9, 10, "Purple", true};

    add(pixelSet, p1);
    add(pixelSet, p2);
    add(pixelSet, p3);
    add(pixelSet, p4);
    add(pixelSet, p5);
    add(pixelSet, p5);
    add(pixelSet, p1);

    display(pixelSet);

    remove(pixelSet, p2);
    remove(pixelSet, p4);

    display(pixelSet);

    deleteSet(pixelSet);

    return 0;
}