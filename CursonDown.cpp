#include "CursorDown.hpp"
#include "EditorException.hpp"

CursorDown::CursorDown()
    : prevRow{1}, prevCol{1}
{
}

void CursorDown::execute(EditorModel& model)
{
    prevRow = model.cursorLine();
    prevCol = model.cursorColumn();
    unsigned int row = prevRow + 1;
    unsigned int col = prevCol;
    if (row > model.lineCount())
    {
        EditorException e{"Already at bottom"};
        throw e;
    }
    else if (col > model.line(row).size())
    {
        col = model.line(row).size()+1;
        model.setCol(col);
        model.setRow(row);
    }
    else
    {
        model.setRow(row);
    }
}

void CursorDown::undo(EditorModel& model)
{
    model.setRow(prevRow);
    model.setCol(prevCol);
}