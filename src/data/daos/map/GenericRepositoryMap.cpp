#include "GenericRepositoryMap.h"


template<typename T>
const T *GenericRepositoryMap<T>::create(T *entity) {
    return ;
}

template<typename T>
optional<T *> GenericRepositoryMap<T>::readById(long id) {
    return ;
}

template<typename T>
const T *GenericRepositoryMap<T>::update(T *entity) {
    return ;
}

template<typename T>
void GenericRepositoryMap<T>::deleteById(long id) {
}


template<typename T>
list<T *> GenericRepositoryMap<T>::findAll() {
    return ;
}