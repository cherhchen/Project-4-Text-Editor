#include "DeleteLine.hpp"
#include "EditorException.hpp"

DeleteLine::DeleteLine()
    : prevRow{1}, prevCol{1}
{
}


void DeleteLine::execute(EditorModel& model)
{
    prevRow = model.cursorLine();
    prevCol = model.cursorColumn();
    prevText = model.line(prevRow);
    if (model.lineCount() == 1 && model.line(prevRow) == "")
    {
        EditorException e{"Already empty"};
        throw e;
    }
    unsigned int prevLineNum = prevRow - 1;
    if (prevRow == 1)
    {
        if (model.lineCount() == 1)
        {
            std::string empty = "";
            model.setText(empty, prevRow);
            model.setCol(1);
        }
        else
        {
            if (prevCol > model.line(prevRow+1).size())
            {
                model.setCol(model.line(prevRow+1).size()+1);
            }
            model.deleteLine(prevRow);
        }
    }
    else if (prevRow == model.lineCount())
    {
        if (prevCol > model.line(prevLineNum).size())
        {
            model.setCol(model.line(prevLineNum).size()+1);
        }
        model.deleteLine(prevRow);
        model.setRow(prevLineNum);
    }
    else
    {
        if (prevCol > model.line(prevRow+1).size())
        {
            model.setCol(model.line(prevRow+1).size()+1);
        }
        model.deleteLine(prevRow);
    }
}


void DeleteLine::undo(EditorModel& model)
{
    model.setRow(prevRow);
    model.setCol(prevCol);
    model.createNewLine(prevText, prevRow-1);
}

