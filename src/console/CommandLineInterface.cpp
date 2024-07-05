#include "CommandLineInterface.h"

#include "exceptions/UnsupportedCommandException.h"

void CommandLineInterface::add(Command *command) {
    this->commands[command->value()] = command;
}

bool CommandLineInterface::runCommands() {
    bool exit = false;
    while (!exit) {
        exit = runCommand();
    }
    return true;
}

bool CommandLineInterface::runCommand() {
    this->view->showCommand(this->session->getLoggedUser().has_value() ? "-" + this->session->getLoggedUser().value()->getName() : "");
    string input[] = this->view->enterCommand();
    bool exit = false;

    if (VALUE_HELP == (input[0])) {
        this->showHelp();
    } else if (VALUE_EXIT == (input[0])) {
        exit = true;
    } else {
        if (this->commands.contains(input[0])) {
            this->commands[input[0]]->execute(&input[1]);
        } else {
            throw UnsupportedCommandException("Command '" + input[0] + "' does not exist.");
        }
    }

    return exit;
}

void CommandLineInterface::showHelp() {
    this->view->showHelp(this->classifyByType());
}

map<string, list<string>> CommandLineInterface::classifyByType() {
    map<string, list<string>> categorizedCommands;
    categorizedCommands["user"] = {};
    categorizedCommands["plan"] = {};
    categorizedCommands["activity"] = {};

    for (const auto &commandPair: this->commands) {
        const auto command = commandPair.second;
        if (command->value().find("user") != std::string::npos || command->value().find("login") != std::string::npos ||
            command->value().find("logout") != std::string::npos) {
            categorizedCommands["user"].push_back({command->value(), command->helpParameters(), command->helpComment()});
        } else if (command->value().find("plan") != std::string::npos) {
            categorizedCommands["plan"].push_back({command->value(), command->helpParameters(), command->helpComment()});
        } else {
            categorizedCommands["activity"].push_back({command->value(), command->helpParameters(), command->helpComment()});
        }
    }

    categorizedCommands["general"] = {
            {VALUE_HELP, HELP_PARAMETERS_HELP, HELP_COMMENT_HELP},
            {VALUE_EXIT, HELP_PARAMETERS_EXIT, HELP_COMMENT_EXIT}
    };

    return categorizedCommands;
}