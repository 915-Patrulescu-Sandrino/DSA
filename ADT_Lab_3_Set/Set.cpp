#include "Set.h"
#include "SetITerator.h"

Set::Set() {
	this->capacity = 10;
	this->size = 0;
	this->data = new TElem[capacity];
}


bool Set::add(TElem elem) {
	int index = 0;
	while(index < this->size){
	    if(elem == this->data[index]){
            return false;
	    }
	    index = index + 1;
	}
	if(this->size == this->capacity){
	    this->capacity = 2 * this->capacity;
	    TElem* new_data = new TElem[this->capacity];
	    for(index = 0; index < this->size; index = index + 1){
	        new_data[index] = this->data[index];
	    }
	    delete[] this->data;
	    this->data = new_data;
	}
	this->data[this->size] = elem;
	this->size = this->size + 1;
	return true;
}


bool Set::remove(TElem elem) {
	int index=0;
	bool found = false;
	while(index < this->size){
	    if(elem == this->data[index]){
	        found = true;
	        break;
	    }
	    index = index + 1;
	}
	if(found == false){ // without 'found': if(index < this->size)
	    return false;
	}
	this->data[index] = this->data[this->size - 1];
	this->size = this->size - 1;
	if(this->size <= this->capacity / 4){
	    TElem* new_data = new TElem[this->capacity / 2];
	    for(index = 0; index < this->size; index = index + 1){
	        new_data[index] = this->data[index];
	    }
	    delete[] this->data;
	    this->data = new_data;
	}
	return true;
}


bool Set::search(TElem elem) const {
	int index = 0;
	while(index < this->size){
	    if(elem == this->data[index]){
	        return true;
	    }
	    index = index + 1;
	}

}
//Worst Case: Theta(n)
//Best Case: Theta(1)
//Average Case: Theta(n)
//Overall: O(n)


int Set::size() const {
	return this->size;
}
//Best Case <=> Worst Case : Theta(1)


bool Set::isEmpty() const {
	return (this->size == 0);
}
//Best Case <=> Worst Case : Theta(1)


Set::~Set() {
    this->capacity = 0;
    this->size = 0;
	delete[] this->data;
}


SetIterator Set::iterator() const {
	return SetIterator(*this);
}


