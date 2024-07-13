#ifndef SOCIAL_PLANS_MANAGEMENT_VIEWCONSOLE_H
#define SOCIAL_PLANS_MANAGEMENT_VIEWCONSOLE_H


#include "View.h"

class ViewConsole : public View {
    vector<string> *enterCommand() override;

    void showWelcome() override;

    void showCommand(const string &message) override;

    void showHelp(map<string, vector<array<string, 3>>> *commandCategories) override;

    void showErrorWithComment(const string &errorMessage, const string &comment) override;

    void showResult(const string &message) override;

    void show(const string &message) override;

    void showUser(long id, const string &username, const string &password, int age, const string &mobile) override;

    void
    showPlan(long id, const string &name, const string &ownerName, chrono::system_clock::time_point date, const string &meetingPlace,
             int capacity, int availableSpots,
             list<string &> activitiesNames, list<string &> subscribersNames) override;

    void
    showPlanForList(long id, const string &name, const string &ownerName, chrono::system_clock::time_point date, const string &meetingPlace,
                    int capacity,
                    int availableSpots, list<string &> activitiesNames, list<string &> subscribersNames) override;

    void showActivity(long id, const string &name, const string &description, const string &type, int duration, int capacity,
                      float price) override;

};


#endif //SOCIAL_PLANS_MANAGEMENT_VIEWCONSOLE_H
