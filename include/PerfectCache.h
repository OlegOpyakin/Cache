#ifndef PERFECT_CACHE_H
#define PERFECT_CACHE_H

#include <vector>
#include <list>
#include <iostream>

class PerfectCache{
public:
    PerfectCache(const int cache_size): cache_size_(cache_size), 
                                        nums_in_cash_(0), 
                                        iterator_(0), 
                                        hits_(0) {}

    void Put(); // function to try to insert an element( mas[iterator_] ) from mas_ to cache_

    void FillMas(std::vector<int> &mas_); // just fill our massive

    unsigned int ShowHits(){ return hits_; }; // obvious, shows hits in cache
    void PrintCache(); // we want to show cache separatedly 


private:
    std::vector<int> cache_;
    std::vector<int> mas_;
    unsigned int cache_size_;
    unsigned int nums_in_cash_;
    unsigned int iterator_;
    unsigned int hits_;

    int FindLastFirstOccurrence(int element);// returns last occured element
                                            // in main mas from iterator_+1 to mas.size()
};

#endif