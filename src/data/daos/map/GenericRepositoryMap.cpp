#include "GenericRepositoryMap.h"


template<typename T>
const T *GenericRepositoryMap<T>::create(T *entity) {
    long id = this->repository.size() + 1;
    this->setIdEntity(entity, id);
    this->repository[id] = entity;
    return this->repository[id];
}

template<typename T>
optional<T *> GenericRepositoryMap<T>::readById(long id) {
    return make_optional(this->repository[id]);
}

template<typename T>
const T *GenericRepositoryMap<T>::update(T *entity) {
    long id = getIdEntity(entity);
    this->repository[id] = entity;
    return this->repository[id];
}

template<typename T>
void GenericRepositoryMap<T>::deleteById(long id) {
    this->repository.erase(id);
}


template<typename T>
list<T *> GenericRepositoryMap<T>::findAll() {
    list<T *> list;
    for (const auto &pair: this->repository) {
        list.push_back(pair.second);
    }
    return list;
}