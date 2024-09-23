#include <iostream>
#include "LFU_modded.h"

int main() {
    unsigned int size = 0;
    unsigned int elems_count = 0;

    std::cin >> size >> elems_count;
    LFU<int> lfu(size);

    for (unsigned int i = 0; i < elems_count; i++) {
        int value;
        std::cin >> value;
        lfu.Put(value);
    }

    std::cout << lfu.ReturnHits() << std::endl;
}