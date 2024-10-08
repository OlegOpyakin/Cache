/*
*  Remarks
 *  1. Max Speed ~ 6.5m elems/sec
 *  2. LFU have template, so in LFU.tpp have not included LFU.h
 *  3. Include LFU.tpp in the end LFU.h.
 *  4. Sorry for my bad English)))
*/


template <typename T>
LFU<T>::LFU(unsigned int size): size(size) {
    next_key = first_key;
    hits = 0;
}

// Put checks for the presence of an item in the cache
// If there is one, it increases its frequency of occurrence by 1 and counts the "hit"
// If not, it adds with a frequency of 1
template <typename T>
void LFU<T>::Put(const T element){
    if (BoolFindKey(element) == true){
        FreqIncrement(value_key_map[element]);
        hits += 1;
    }
    else{
        if (hash_table.size()  == size){    // Checks if the cache is full
            PopMinFreqElement();
        }
        min_freq = start_freq;
        AddNewElement(element);
    }
}

// Checks for the presence of new_value in our Hash table
template <typename T>
bool LFU<T>::BoolFindKey(const T new_value) const {
    auto search = value_key_map.find(new_value);
    if (search != value_key_map.end()){
        return true;
    }
    return false;
}

// Increases the frequency of occurrence of an element by 1
template <typename T>
void LFU<T>::FreqIncrement(const unsigned int &key) {
    unsigned int new_freq_hash {hash_table[key].second + 1};
    T hash_value {hash_table[key].first};

    // delete key in list value in freq_keys_map (temp) and add front new
    freq_keys_map[hash_table[key].second + 1].push_front(key);

    // clear the old maps of more unused elements
    freq_keys_map[hash_table[key].second].remove(key);
    hash_table.erase(key);
    //value_key_map.erase(key);

    // will give them new elements
    hash_table[key] = std::make_pair(hash_value, new_freq_hash);

    if (freq_keys_map[min_freq].get_size() == 0) {
        min_freq += 1;
    }
}

// Deletes an element with the minimum occurrence frequency
template <typename T>
void LFU<T>::PopMinFreqElement(){
    unsigned int key = freq_keys_map[min_freq].get_last();
    T value = hash_table[key].first;
    value_key_map.erase(value);
    hash_table.erase(key);
    freq_keys_map[min_freq].remove(freq_keys_map[min_freq].get_last()); //delete last key;
}

// Adds a new item to the cache
template <typename T>
void LFU<T>::AddNewElement(const T new_value) {
    hash_table.insert({next_key,  std::make_pair(new_value, new_elem_freq)});
    DoubleLinkedList key_list;

    freq_keys_map.insert({new_elem_freq, key_list});
    freq_keys_map[new_elem_freq].push_front(next_key);

    value_key_map.insert({new_value, next_key});

    if (next_key < max_key){
        next_key++;
    }
    else {
        next_key = first_key;
    }
}

// Return hits
template <typename T>
unsigned int LFU<T>::ReturnHits() const {
    return hits;
}

// Destroyer
template <typename T>
LFU<T>::~LFU(){};
