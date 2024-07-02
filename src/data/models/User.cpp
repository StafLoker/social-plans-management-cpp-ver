#include "User.h"
#include "exceptions/InvalidAttributeException.h"

User::User(string name, string mobile, const string &password, int age) : name(std::move(name)), mobile(std::move(mobile)){
    this->setPassword(password);
    this->setAge(age);
}

void User::setPassword(string password) {
    if (password.length() < MIN_LONG_PASSWORD) {
        throw InvalidAttributeException("The password must be at least 3 characters long");
    }
    this->password = std::move(password);
}

void User::setAge(int age) {
    if (age < MIN_AGE || age > MAX_AGE) {
        throw InvalidAttributeException(
                "The age must be in the range [" + to_string(MIN_AGE) + "," + to_string(MAX_AGE) + "] years: " +
                to_string(age));
    }
    this->age = age;
}

void User::setId(long id) {
    this->id = id;
}

long User::getId() const {
    return this->id;
}

const string &User::getName() const {
    return this->name;
}

const string &User::getMobile() const {
    return this->mobile;
}

const string &User::getPassword() const {
    return this->password;
}

int User::getAge() const {
    return this->age;
}

// operators

bool User::operator==(const User &rhs) const {
    return id == rhs.id;
}

bool User::operator!=(const User &rhs) const {
    return !(rhs == *this);
}
