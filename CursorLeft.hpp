#ifndef CURSORLEFT_HPP
#define CURSORLEFT_HPP

#include "Command.hpp"
#include "EditorModel.hpp"

class CursorLeft : public Command
{
public:
    CursorLeft();

    void execute(EditorModel& model) override;

    void undo(EditorModel& model) override;

private:
    unsigned int prevCol;
    unsigned int prevRow;
};

#endif