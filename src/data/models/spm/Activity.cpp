#include "Activity.h"

#include <utility>

#include "../exceptions/InvalidAttributeException.h"

Activity::Activity(string name, string description, int duration, float price) : name(std::move(name)),
                                                                                  description(std::move(
                                                                                          description)),
                                                                                  duration(duration), price(price) {}

Activity::Activity(string name, string description, int duration, float price,
                   int capacity) : name(std::move(name)), description(std::move(description)),
                                   duration(duration),
                                   price(price) {
    this->setCapacity(capacity);
}

float Activity::getPrice(int age) const {
    return this->price;
}

// getters & setters

void Activity::setId(long id) {
    Activity::id = id;
}

void Activity::setCapacity(int capacity) {
    if (capacity < MIN_CAPACITY) {
        throw InvalidAttributeException(
                string("Minimum capacity is") + to_string(MIN_CAPACITY) + ": " + to_string(capacity));
    }
    Activity::capacity = capacity;
}

long Activity::getId() const {
    return this->id;
}

const string &Activity::getName() const {
    return this->name;
}

const string &Activity::getDescription() const {
    return this->description;
}

int Activity::getDuration() const {
    return this->duration;
}

float Activity::getPrice() const {
    return this->price;
}

const optional<int> &Activity::getCapacity() const {
    return this->capacity;
}

// operators

bool Activity::operator==(const Activity &rhs) const {
    return id == rhs.id;
}

bool Activity::operator!=(const Activity &rhs) const {
    return !(rhs == *this);
}
