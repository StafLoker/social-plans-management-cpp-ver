#ifndef SOCIAL_PLANS_MANAGEMENT_VIEW_H
#define SOCIAL_PLANS_MANAGEMENT_VIEW_H

using namespace std;

#include <list>
#include "chrono"

class View {
    /**
    * @return [0] ~ command , [i>=1] - parameters
    */
    virtual string *enterCommand();

    virtual void showWelcome();

    virtual void showCommand(const string &message);

    virtual void showHelp(Map <String, List<String[]>> *commandCategories);

    virtual void showErrorWithComment(const string &errorMessage, const string &comment);

    virtual void showResult(const string &message);

    virtual void show(const string &message);

    virtual void showUser(long id, const string &username, const string &password, int age, const string &mobile);

    virtual void
    showPlan(long id, const string &name, const string &ownerName, chrono::system_clock::time_point date, const string &meetingPlace,
             int capacity, int availableSpots,
             list<string &> activitiesNames, list<string &> subscribersNames);

    virtual void
    showPlanForList(long id, const string &name, const string &ownerName, chrono::system_clock::time_point date, const string &meetingPlace,
                    int capacity,
                    int availableSpots, list<string &> activitiesNames, list<string &> subscribersNames);

    virtual void showActivity(long id, const string & name, const string & description, const string & type, int duration, int capacity, float price);
};

#endif //SOCIAL_PLANS_MANAGEMENT_VIEW_H
