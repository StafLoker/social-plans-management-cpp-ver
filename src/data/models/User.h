#ifndef SOCIAL_PLANS_MANAGEMENT_USER_H
#define SOCIAL_PLANS_MANAGEMENT_USER_H

#include <string>
#include <utility>

using namespace std;

class User {
private:
    static const int MIN_AGE = 14;
    static const int MAX_AGE = 100;
    static const int MIN_LONG_PASSWORD = 3;

    long id{};
    string name, mobile, password;
    int age;

public:
    User() = default;

    User(string name, string mobile, const string &password, int age);

    void setPassword(string password);

    void setAge(int age);

    void setId(long id);

    long getId() const;

    const string &getName() const;

    const string &getMobile() const;

    const string &getPassword() const;

    int getAge() const;

    // operators

    bool operator==(const User &rhs) const;

    bool operator!=(const User &rhs) const;
};


#endif //SOCIAL_PLANS_MANAGEMENT_USER_H
