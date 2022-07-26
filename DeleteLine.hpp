#ifndef DELETELINE_HPP
#define DELETELINE_HPP

#include "Command.hpp"
#include "EditorModel.hpp"

class DeleteLine : public Command
{
public:
    DeleteLine();

    void execute(EditorModel& model) override;

    void undo(EditorModel& model) override;

private:
    unsigned int prevRow;
    unsigned int prevCol;
    std::string prevText;
};

#endif