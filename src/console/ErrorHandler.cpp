#include "ErrorHandler.h"
#include "../services/exceptions/SecurityProhibitionException.h"

void ErrorHandler::runErrorManager() {
    bool exit = false;
    while (!exit) {
        try {
            exit = this->commandLineInterface->runCommands();
        } catch (SecurityProhibitionException securityProhibitionException) {
            this->view->showErrorWithComment("Oops...", securityProhibitionException.what());
        } catch (ConstraintViolationException constraintViolationException) {
            for (ConstraintViolation< ?> violation :
            constraintViolationException.getConstraintViolations()) {
                this->view->showErrorWithComment("ERROR", violation.getMessage());
            }
        } catch (exception e) {
            this->view->showErrorWithComment("ERROR", e.what());
        }
    }
    this->view->show("Goodbye!");
}
