#ifndef SOCIAL_PLANS_MANAGEMENT_GENERICREPOSITORYMAP_H
#define SOCIAL_PLANS_MANAGEMENT_GENERICREPOSITORYMAP_H


#include "../GenericRepository.h"

using namespace std;

#include <map>

template<typename T>
class GenericRepositoryMap : public GenericRepository<T> {
private:
    map<long, T*> repository;
public:
    const T* create(T *entity) override;

    optional<T*> readById(long id) override;

    const T* update(T *entity) override;

    void deleteById(long id) override;

    list<T*> findAll() override;

    virtual long getIdEntity(T *entity);

    virtual void setIdEntity(T *entity, long id);
};

#endif //SOCIAL_PLANS_MANAGEMENT_GENERICREPOSITORYMAP_H