#include "ViewConsole.h"

string *ViewConsole::enterCommand() {

}

void ViewConsole::showWelcome() {

}

void ViewConsole::showCommand(const string &message) {

}

void showHelp(map<string, vector<array<string, 3>>> *commandCategories) {

}

void ViewConsole::showErrorWithComment(const string &errorMessage, const string &comment) {

}

void ViewConsole::showResult(const string &message) {

}

void ViewConsole::show(const string &message) {

}

void ViewConsole::showUser(long id, const string &username, const string &password, int age, const string &mobile) {

}

void ViewConsole::showPlan(long id, const string &name, const string &ownerName, chrono::system_clock::time_point date,
                           const string &meetingPlace, int capacity, int availableSpots, list<string &> activitiesNames,
                           list<string &> subscribersNames) {

}

void ViewConsole::showPlanForList(long id, const string &name, const string &ownerName, chrono::system_clock::time_point date,
                                  const string &meetingPlace, int capacity, int availableSpots, list<string &> activitiesNames,
                                  list<string &> subscribersNames) {

}

void ViewConsole::showActivity(long id, const string &name, const string &description, const string &type, int duration, int capacity,
                               float price) {

}
