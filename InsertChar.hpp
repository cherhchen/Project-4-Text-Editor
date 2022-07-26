#ifndef INSERTCHAR_HPP
#define INSERTCHAR_HPP

#include "Command.hpp"
#include "EditorModel.hpp"
#include <string>

class InsertChar : public Command
{
public:
    InsertChar(char c);

    void execute(EditorModel& model) override;

    void undo(EditorModel& model) override;

private:
    char character;
    unsigned int prevCol;
    unsigned int prevRow;
};

#endif