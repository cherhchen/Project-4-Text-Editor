#include "CursorHome.hpp"

CursorHome::CursorHome()
    : prevCol{1}
{
}

void CursorHome::execute(EditorModel& model)
{
    prevCol = model.cursorColumn();
    model.setCol(1);
}

void CursorHome::undo(EditorModel& model)
{
    model.setCol(prevCol);
}