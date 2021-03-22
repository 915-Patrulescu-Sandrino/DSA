#include "FixedCapBiMap.h"
#include "FixedCapBiMapIterator.h"
#include <exception>
using namespace  std;

FixedCapBiMap::FixedCapBiMap(int capacity) {
	if(capacity <= 0)
    {
	    throw exception();
    }
	this->capacity = capacity;
	this->nrPairs = 0;
	this->elements = new TElem[capacity];
}
//Theta(1)

FixedCapBiMap::~FixedCapBiMap() {
	delete[] this->elements;
}
//Theta(1)

bool FixedCapBiMap::add(TKey c, TValue v){
	if(this->capacity == this->nrPairs)
	    throw exception();
	int index = 0;
	int count = 0;
	while(index < this->nrPairs && count < 2)
    {
	    if(this->elements[index].first == c)
        {
	        count++;
        }
	    index++;
    }
	if(count == 2)
	    return false;
	else
    {
	    this->elements[this->nrPairs].first = c;
	    this->elements[this->nrPairs].second = v;
	    this->nrPairs++;
	    return true;
    }
}
//Best Case: Theta(1)
//Worst Case: Theta(nrPairs)
//=> Total Complexity: O(nrPairs)

ValuePair FixedCapBiMap::search(TKey c) const{
    ValuePair returnedValue;
    returnedValue.first = NULL_TVALUE;
    returnedValue.second = NULL_TVALUE;

    int count = 0;
	int index = 0;
	while(index < this->nrPairs && count < 2)
    {
	    if(this->elements[index].first == c)
        {
            if(count == 0)
            {
                returnedValue.first = this->elements[index].second;
                count++;
            }
            else
            {
                returnedValue.second = this->elements[index].second;
                count++;
            }
        }
	    index++;
    }
	return returnedValue;
}
//Best case: Theta(1)
//Worst case: Theta(nrPairs)
//=> Total Complexity: O(nrPairs)


bool FixedCapBiMap::remove(TKey c, TValue v){
	int index = 0;
	bool found = false;
	while(index < this->nrPairs)
    {
	    if(this->elements[index].first == c && this->elements[index].second == v)
        {
            found = true;
	        break;
        }
	    else
        {
            index++;
        }
    }
    if(!found)
        return false;
    else
    {
        this->elements[index] = this->elements[this->nrPairs - 1];
        this->nrPairs--;
        return true;
    }
}
//Best case: Theta(1)
//Worst case: Theta(nrPairs)
//=> Total complexity: O(nrPairs)


int FixedCapBiMap::size() const {
	return this->nrPairs;
}
//Theta(1)

bool FixedCapBiMap::isEmpty() const{
	return (this->nrPairs == 0);
}
//Theta(1)

bool FixedCapBiMap::isFull() const {
	return (this->nrPairs == this->capacity);
}
//Theta(1)

FixedCapBiMapIterator FixedCapBiMap::iterator() const {
	return FixedCapBiMapIterator(*this);
}
//Theta(1)

ValuePair FixedCapBiMap::removeKey(TKey k) {
    ValuePair returnedValue;
    returnedValue.first = NULL_TVALUE;
    returnedValue.second = NULL_TVALUE;

    int count = 0;
    int index = 0;
    while(index < this->nrPairs && count < 2)
    {
        if(this->elements[index].first == k)
        {
            if(count == 0)
            {
                returnedValue.first = this->elements[index].second;
                count++;
                this->elements[index] = this->elements[this->nrPairs - 1];
                index--;
                this->nrPairs--;
            }
            else
            {
                returnedValue.second = this->elements[index].second;
                count++;
                this->elements[index] = this->elements[this->nrPairs - 1];
                index--;
                this->nrPairs--;
            }
        }
        index++;
    }
    return ValuePair();
}

