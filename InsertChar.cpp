#include "InsertChar.hpp"

InsertChar::InsertChar(char c)
    : character{c}, prevCol{1}, prevRow{1}
{
}

void InsertChar::execute(EditorModel& model)
{
    prevRow = model.cursorLine();
    prevCol = model.cursorColumn();
    std::string prevText = model.line(prevRow);
    std::string text;
    if (prevCol == model.line(prevRow).size()+1)
    {
        text = prevText + character;
    }
    else
    {
        text = prevText.substr(0, prevCol-1) + character + prevText.substr(prevCol-1);
    }
    model.setText(text, prevRow);
    model.setCol(prevCol+1);
}

void InsertChar::undo(EditorModel& model)
{
    std::string prevText = model.line(prevRow).substr(0, prevCol-1) + model.line(prevRow).substr(prevCol);
    model.setText(prevText, prevRow);
    model.setCol(prevCol);
}