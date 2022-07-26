#include "CursorRight.hpp"
#include "EditorException.hpp"

CursorRight::CursorRight()
    : prevCol{1}, prevRow{1}
{
}

void CursorRight::execute(EditorModel& model)
{
    prevCol = model.cursorColumn();
    prevRow = model.cursorLine();
    unsigned int col = prevCol + 1;
    unsigned int row = prevRow;
    if (row == model.lineCount() && col > model.line(row).size()+1)
    {
        EditorException e{"Already at end"};
        throw e;
    }
    else if (col > model.line(row).size()+1)
    {
        row += 1;
        col = 1;
        model.setRow(row);
        model.setCol(col);
    }
    else
    {
        model.setCol(col);
    }
}

void CursorRight::undo(EditorModel& model)
{
    model.setCol(prevCol);
    model.setRow(prevRow);
}