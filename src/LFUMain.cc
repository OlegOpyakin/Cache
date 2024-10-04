#include <iostream>
#include "LFU.h"
#include <ctime>

int main() {
    unsigned int size = 0;
    unsigned int elems_count = 0;

    std::cin >> size >> elems_count;
    clock_t start = clock();
    LFU<int> lfu(size);

    for (unsigned int i = 0; i < elems_count; i++) {
        int value;
        std::cin >> value;
        lfu.Put(value);
    }
    clock_t end = clock();
    double seconds = ((double)(end - start))/CLOCKS_PER_SEC;
    std::cout << "hits: " << lfu.ReturnHits() << std::endl;
    std::cout << "time: " << seconds << std::endl;
}