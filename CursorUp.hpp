#ifndef CURSORUP_HPP
#define CURSORUP_HPP

#include "Command.hpp"
#include "EditorModel.hpp"

class CursorUp : public Command
{
public:
    CursorUp();

    void execute(EditorModel& model) override;

    void undo(EditorModel& model) override;

private:
    unsigned int prevRow;
    unsigned int prevCol;

};

#endif