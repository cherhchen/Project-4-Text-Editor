#include "CursorUp.hpp"
#include "EditorException.hpp"

CursorUp::CursorUp()
    : prevRow{1}, prevCol{1}
{
}

void CursorUp::execute(EditorModel& model)
{
    prevRow = model.cursorLine();
    prevCol = model.cursorColumn();
    unsigned int row = prevRow - 1;
    unsigned int col = prevCol;
    if (row < 1)
    {
        EditorException e{"Already at top"};
        throw e;
    }
    else if (model.line(row).size() < col)
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

void CursorUp::undo(EditorModel& model)
{
    model.setRow(prevRow);
    model.setCol(prevCol);
}