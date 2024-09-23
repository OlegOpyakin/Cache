#ifndef LFU_MODDED_H
#define LFU_MODDED_H

#include <iostream>
#include <unordered_map>
#include <list>

template <typename T>

class LFU {
public:
    LFU(unsigned int size);

    // Put checks for the presence of an item in the cache
    // If there is one, it increases its frequency of occurrence by 1 and counts the "hit"
    // If not, it adds with a frequency of 1
    void Put(const T element);

    // Checks for the presence of new_value in our Hash table
    bool BoolFindKey(T new_value) const;

    // Increases the frequency of occurrence of an element by 1
    void FreqIncrement(const unsigned int key);

    // Deletes an element with the minimum occurrence frequency
    void PopMinFreqElement();

    // Adds a new item to the cache
    void AddNewElement(T new_value);

    // Return hits
    unsigned int ReturnHits() const;

    // destroy LFU
    ~LFU();

private:
    const unsigned int new_elem_freq = 1;
    const unsigned int start_freq = 1;
    const unsigned int first_key = 0;
    const unsigned int max_key = 4294967295;
    const unsigned int mas_size = 1000000;

    std::unordered_map<unsigned int, std::pair<T, unsigned int>> hash_table;    // hash table: key - info(value, freq)
    std::unordered_map<unsigned int, std::list<unsigned int>> freq_keys_map;    // freq - keys_with_this_freq

    // Костыль
    std::unordered_map<T, unsigned int> value_key_map;

    unsigned int next_key;
    unsigned int hits;
    unsigned int min_freq;
    const unsigned int size; //size hash table

};
#include "LFU_modded.tpp"
#endif