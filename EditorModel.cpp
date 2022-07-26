// EditorModel.cpp
//
// ICS 45C Spring 2022
// Project #4: People Just Love to Play with Words
//
// Implementation of the EditorModel class

#include "EditorModel.hpp"
#include "EditorException.hpp"


EditorModel::EditorModel()
    : row{1}, col{1}
{
    totalLines.push_back("");
}


int EditorModel::cursorLine() const
{
    return row;
}


int EditorModel::cursorColumn() const
{
    return col;
}


int EditorModel::lineCount() const
{
    return totalLines.size();
}


const std::string& EditorModel::line(int lineNumber) const
{
    return totalLines[lineNumber-1];
}


const std::string& EditorModel::currentErrorMessage() const
{
    return errormessage;
}


void EditorModel::setErrorMessage(const std::string& errorMessage)
{
    errormessage = errorMessage;
}


void EditorModel::clearErrorMessage()
{
    errormessage = "";
}

void EditorModel::setCol(unsigned int newCol)
{
    col = newCol;
}

void EditorModel::setRow(unsigned int newRow)
{
    row = newRow;
}

void EditorModel::setText(std::string& newText, unsigned int row)
{
    totalLines[row-1] = newText;
}

void EditorModel::createNewLine(std::string& text, unsigned int row)
{
    auto iterator = totalLines.begin() + row;
    totalLines.insert(iterator, text);
}

void EditorModel::deleteLine(unsigned int row)
{
    totalLines.erase(totalLines.begin() + row-1);
}