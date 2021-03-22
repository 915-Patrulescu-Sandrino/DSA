#include "Set.h"
#include "SetIterator.h"

Set::Set() {
    this->capacity = 10;
    this->nr_Elems = 0;
    this->data = new TElem[this->capacity];
}
// Theta(1)


bool Set::add(TElem elem) {
    int index = 0;
    while(index < this->nr_Elems){
        if(elem == this->data[index]){
            return false;
        }
        index = index + 1;
    }
    if(this->nr_Elems == this->capacity){
        //the dynamic array is full, we need to resize it
        this->capacity = 2 * this->capacity;
        TElem* new_data = new TElem[this->capacity];
        for(index = 0; index < this->nr_Elems; index = index + 1){
            new_data[index] = this->data[index];
        }
        delete[] this->data;
        this->data = new_data;
    }
    this->data[this->nr_Elems] = elem;
    this->nr_Elems = this->nr_Elems + 1;
    return true;
}
// Worst case: Theta(this->nr_Elems)
// Best case: Theta(1)
// Average case: Theta(this->nr_Elems)
// Total Complexity: Theta(this->nr_Elems)


bool Set::remove(TElem elem) {
    int index = 0;
    bool found = false;
    while(index < this->nr_Elems){
        if(elem == this->data[index]){
            found = true;
            break;
        }
        index = index + 1;
    }
    if(!found){ // without 'found' variable: if(index < this->nr_Elems)
        return false;
    }
    this->data[index] = this->data[this->nr_Elems - 1];
    this->nr_Elems = this->nr_Elems - 1;
    if(this->nr_Elems <= this->capacity / 4){
        // the array is resized if it contains too many empty positions (too many means 3/4 or more of the array is empty)
        this->capacity = this->capacity / 2;
        TElem* new_data = new TElem[this->capacity];
        for(index = 0; index < this->nr_Elems; index = index + 1){
            new_data[index] = this->data[index];
        }
        delete[] this->data;
        this->data = new_data;
    }
    return true;
}
// Worst case: Theta(this->nr_Elems)
// Best case: Theta(1)
// Average case: Theta(this->nr_Elems)
// Total Complexity: Theta(this->nr_Elems)


bool Set::search(TElem elem) const {
    int index = 0;
    while(index < this->nr_Elems){
        if(elem == this->data[index]){
            return true;
        }
        index = index + 1;
    }
    return false;
}
// Worst case: Theta(this->nr_Elems)
// Best case: Theta(1)
// Average case: Theta(this->nr_Elems)
// Total Complexity: O(this->nr_Elems)


int Set::size() const {
    return this->nr_Elems;
}
// Theta(1)


bool Set::isEmpty() const {
    return (this->nr_Elems == 0);
}
// Theta(1)


Set::~Set() {
    this->capacity = 0;
    this->nr_Elems = 0;
    delete[] this->data;
}
// Theta(1)


SetIterator Set::iterator() const {
    return SetIterator(*this);
}
// Theta(1)

int Set::getRange() const {
    if(this->nr_Elems == 0){
        return  -1;
    }
    else{
        int index = 0;
        TElem max = this->data[index], min = this->data[index];
        while(index < this->nr_Elems){
            if(this->data[index] > max){
                max = this->data[index];
            }
            if(this->data[index] < min){
                min = this->data[index];
            }
            index = index + 1;
        }
        return max - min;
    }
}
// Best case: Theta(this->nr_Elems)
// Worst case: Theta(this->nr_Elems)
// Average case: Theta(this->nr_Elems)
// Total complexity: O(this->nr_Elems)

