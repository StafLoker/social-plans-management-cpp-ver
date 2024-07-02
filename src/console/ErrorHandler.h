#ifndef SOCIAL_PLANS_MANAGEMENT_ERRORHANDLER_H
#define SOCIAL_PLANS_MANAGEMENT_ERRORHANDLER_H


#include "CommandLineInterface.h"
#include "View.h"

class ErrorHandler {
private:
    CommandLineInterface *commandLineInterface;
    View *view;
public:
    ErrorHandler(CommandLineInterface *commandLineInterface, View *view) : commandLineInterface(commandLineInterface), view(view) {}

    void runErrorManager();
};


#endif //SOCIAL_PLANS_MANAGEMENT_ERRORHANDLER_H
