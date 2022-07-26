#include "Backspace.hpp"
#include "EditorException.hpp"

Backspace::Backspace()
    : prevRow{1}, prevCol{1}
{
}

void Backspace::execute(EditorModel& model)
{
    prevRow = model.cursorLine();
    prevCol = model.cursorColumn();
    prevText = model.line(prevRow);
    std::string text;
    if (prevCol == 1 && prevRow == 1)
    {
        EditorException e{"Already at beginning"};
        throw e;
    }
    else if (prevCol == 1)
    {
        unsigned int prevLineNum = prevRow - 1;
        model.setCol(model.line(prevLineNum).size()+1);
        model.setRow(prevLineNum);
        prevLineText = model.line(prevLineNum);
        text = model.line(prevLineNum) + prevText;
        model.setText(text, prevLineNum);
        model.deleteLine(prevRow);
    }
    else
    {
        text = prevText.substr(0, prevCol-2) + prevText.substr(prevCol-1, prevText.size());
        model.setText(text, prevRow);
        model.setCol(prevCol-1);
    }
}

void Backspace::undo(EditorModel& model)
{
    if (prevCol == 1)
    {
        model.createNewLine(prevText, prevRow-1);
        model.setText(prevLineText, prevRow-1);
        model.setText(prevText, prevRow);
    }
    else
    {
        model.setText(prevText, prevRow);
    }
    model.setCol(prevCol);
    model.setRow(prevRow);
}