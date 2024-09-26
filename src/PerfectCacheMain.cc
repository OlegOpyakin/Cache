#include "PerfectCache.h"
#include <algorithm>
#include <random>

int main(){
    unsigned int size;
    unsigned int elems_count;
    std::vector<int> mas;
    int elem;

    std::cin >> size >> elems_count;

    for (int i = 0; i < elems_count; i++) {
        std::cin >> elem;
        mas.push_back(elem);
    }

    PerfectCache cache(size);
    cache.FillMas(mas);

    for (unsigned int i = 0; i < elems_count; i++) {
        cache.Put();
    }
    std::cout << "hits: " << cache.ShowHits() << "\n";

    return 0;
}
