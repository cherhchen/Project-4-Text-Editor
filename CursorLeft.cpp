#include "CursorLeft.hpp"
#include "EditorException.hpp"

CursorLeft::CursorLeft()
    : prevCol{1}, prevRow{1}
{
}

void CursorLeft::execute(EditorModel& model)
{
    prevCol = model.cursorColumn();
    prevRow = model.cursorLine();
    unsigned int col = prevCol - 1;
    unsigned int row = prevRow;
    if (row == 1 && col < 1)
    {
        EditorException e{"Already at beginning"};
        throw e;
    }
    else if (col < 1)
    {
        row -= 1;
        col = model.line(row).size()+1;
        model.setRow(row);
        model.setCol(col);
    }
    else
    {
        model.setCol(col);
    }
}

void CursorLeft::undo(EditorModel& model)
{
    model.setCol(prevCol);
    model.setRow(prevRow);
}