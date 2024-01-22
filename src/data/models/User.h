#ifndef SOCIAL_PLANS_MANAGEMENT_USER_H
#define SOCIAL_PLANS_MANAGEMENT_USER_H

#include <string>
#include <utility>

using namespace std;

class User {
    static const int MIN_AGE = 14;
    static const int MAX_AGE = 100;
    static const int MIN_LONG_PASSWORD = 3;

    int id{};
    string name, mobile, password;
    int age;

public:
    User(string name, string mobile, const string &password, int age) : name(std::move(name)), mobile(std::move(mobile)){
        this->setPassword(password);
        this->setAge(age);
    }

    void setPassword(string password);

    void setAge(int age);

    int getId() const;

    const string &getName() const;

    const string &getMobile() const;

    const string &getPassword() const;

    int getAge() const;

    void setId(int id);
};


#endif //SOCIAL_PLANS_MANAGEMENT_USER_H
