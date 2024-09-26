#include "PerfectCache.h"

void PerfectCache::Put(){
    if(iterator_ == mas_.size()) return; //condition for mas end

    for(auto it: cache_){ // check if we hit our cache 
        if(it == mas_[iterator_]){
            hits_++;
            iterator_++;
            return;
        }
    }

    if (nums_in_cash_ < cache_size_) { // if cache is not full
        cache_.push_back(mas_[iterator_]);
        nums_in_cash_ += 1;
        iterator_++;
        return;
    }

    int odd_elem = FindLastFirstOccurrence(mas_[iterator_]); // we get odd elem from private func

    if (odd_elem == mas_[iterator_]){
        iterator_++;
        return;
    }

    for (int i = 0; i < cache_size_; i++){
        if(cache_[i] == odd_elem){
            cache_[i] = mas_[iterator_];
                break;
            }
        }
        
    iterator_++;
    return;
}

void PerfectCache::FillMas(std::vector<int> &mas){
    for(int i = 0; i < mas.size(); i++){
        mas_.push_back(mas[i]);
    }
}

void PerfectCache::PrintCache() { // we want to show cache separatedly 
    std::cout << "\ncache: ";

    for(auto i : cache_){
        std::cout << i << " ";
    }

    std::cout << "\n\n";
}

int PerfectCache::FindLastFirstOccurrence(int element) { // returns last occured element
                                                         // in main mas from iterator_+1 to mas.size()
    std::list<int> values;

    for (int i = 0; i < cache_size_; i++){
        values.push_back(cache_[i]);
    }
    values.push_back(element);

    int lastIndex = -1;
    int iterator_1 = iterator_ + 1;

    while((values.size() > 1) and (iterator_1 != mas_.size())){
        for(auto it: values){
            if(it == mas_[iterator_1]){
                values.remove(it);
                break;
            }
        }
        iterator_1 ++;
    }

    lastIndex = values.front();
    return lastIndex;
}