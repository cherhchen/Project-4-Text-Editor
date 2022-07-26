#include "CursorEnd.hpp"

CursorEnd::CursorEnd()
    : prevCol{1}, currentRow{1}
{
}

void CursorEnd::execute(EditorModel& model)
{
    prevCol = model.cursorColumn();
    currentRow = model.cursorLine();
    model.setCol(model.line(currentRow).size()+1);
}

void CursorEnd::undo(EditorModel& model)
{
    model.setCol(prevCol);
}