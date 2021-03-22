#include "SetIterator.h"
#include "Set.h"
#include <exception>


SetIterator::SetIterator(const Set& m) : set(m)
{
    this->current = 0;
}
// Theta(1)


void SetIterator::first() {
    this->current = 0;
}
// Theta(1)


void SetIterator::next() {
    if(this->current == this->set.nr_Elems){
        throw std::exception();
    }
    else{
        this->current = this->current + 1;
    }
}
// Theta(1)


TElem SetIterator::getCurrent()
{
    if(this->current == this->set.nr_Elems){
        throw std::exception();
    }
    return this->set.data[this->current];
}
// Theta(1)


bool SetIterator::valid() const {
    if(this->current < this->set.nr_Elems){
        return true;
    }
    return false;
}
// Theta(1)

