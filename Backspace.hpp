#ifndef BACKSPACE_HPP
#define BACKSPACE_HPP

#include "Command.hpp"
#include "EditorModel.hpp"
#include <string>

class Backspace : public Command
{
public:
    Backspace();

    void execute(EditorModel& model) override;

    void undo(EditorModel& model) override;

private:
    unsigned int prevRow;
    unsigned int prevCol;
    std::string prevText;
    std::string prevLineText;
};

#endif