#ifndef SOCIAL_PLANS_MANAGEMENT_COMMANDLINEINTERFACE_H
#define SOCIAL_PLANS_MANAGEMENT_COMMANDLINEINTERFACE_H

#include "map"
#include "list"

#include "commands/Command.h"
#include "../services/Session.h"
#include "View.h"

class CommandLineInterface {
private:
    const string VALUE_HELP = "help";
    const string HELP_PARAMETERS_HELP;
    const string HELP_COMMENT_HELP = "Shows help";

    const string VALUE_EXIT = "exit";
    const string HELP_PARAMETERS_EXIT;
    const string HELP_COMMENT_EXIT = "Terminates execution";

    map<string, Command *> commands;
    Session *session;
    View *view;

public:
    CommandLineInterface(Session *session, View *view) : session(session), view(view) {}

    void add(Command *command);

    bool runCommands();

private:
    bool runCommand();

    void showHelp();

    map<string, list<string>> classifyByType();
};


#endif //SOCIAL_PLANS_MANAGEMENT_COMMANDLINEINTERFACE_H
