#ifndef SOCIAL_PLANS_MANAGEMENT_GENERICREPOSITORY_H
#define SOCIAL_PLANS_MANAGEMENT_GENERICREPOSITORY_H

#include <optional>
#include <list>

using namespace std;

template <typename T>
class GenericRepository {
public:
    virtual const T* create(T *entity);

    virtual optional<T*> readById(long id);

    virtual const T* update(T *entity);

    virtual void deleteById(long id);

    virtual list<T*> findAll();
};

#endif //SOCIAL_PLANS_MANAGEMENT_GENERICREPOSITORY_H
