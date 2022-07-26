#include "NewLine.hpp"

NewLine::NewLine()
    : prevRow{1}, prevCol{1}
{
}

void NewLine::execute(EditorModel& model)
{
    prevRow = model.cursorLine();
    prevCol = model.cursorColumn();
    prevText = model.line(prevRow);
    std::string afterText = prevText.substr(prevCol-1);
    model.createNewLine(afterText, prevRow);
    std::string beforeText = prevText.substr(0, prevCol-1);
    model.setText(beforeText, prevRow);
    model.setCol(1);
    model.setRow(prevRow+1);
}

void NewLine::undo(EditorModel& model)
{
    model.setCol(prevCol);
    model.setRow(prevRow);
    model.setText(prevText, prevRow);
    model.deleteLine(prevRow+1);
}