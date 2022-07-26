#ifndef CURSORRIGHT_HPP
#define CURSORRIGHT_HPP

#include "Command.hpp"
#include "EditorModel.hpp"

class CursorRight : public Command
{
public:
    CursorRight();

    void execute(EditorModel& model) override;

    void undo(EditorModel& model) override;

private:
    unsigned int prevCol;
    unsigned int prevRow;
};

#endif