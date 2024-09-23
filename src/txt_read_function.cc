#include <iostream>
#include <fstream>
#include <cstdlib>

std::string Read() {
    std::ifstream file("input.txt");
    std::string str;
    if (!file.is_open()) {
        std::cerr << "Unable to open file" << std::endl;
        exit(1);
    }
    else {
        std::getline(file, str);
    }
    return str;
}

template <typename T>
T find_elem(std::string &str) {
    std::string new_str = "";
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == ' ' and new_str.size() != 0) {
            str.erase(0, i+1);
            unsigned int elem = std::stoi(new_str);
            return elem;
        }
        else {
            new_str += str[i];
        }
    }
    if (new_str.size() != 0 and new_str != " ") {
        str.erase(0, new_str.size());
        unsigned int elem = std::stoi(new_str);
        return elem;
    }
    std::cerr << "Not found elements" << std::endl;
    exit(1);
}

template <typename T>
void find_elements_massive(std::string &str, T *massive, unsigned int max_size) {
    unsigned int i = 0;
    while (str.size() != 0 and str != " ") {
        massive[i] = find_elem<T>(str);
        i += 1;
        if (i > max_size) {
            std::cerr << "Mas size < element count" << std::endl;
            exit(1);
        }
    }
}


int main(){
    std::string str = Read();
    unsigned int size = find_elem<unsigned int>(str);
    unsigned int elems = find_elem<unsigned int>(str);
    const unsigned int mas_size = 1000000;
    unsigned int mas[mas_size];
    find_elements_massive<unsigned int>(str, mas, mas_size);
    return 0;
}
