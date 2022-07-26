// InteractionProcessor.cpp
//
// ICS 45C Spring 2022
// Project #4: People Just Love to Play with Words
//
// Implementation of the InteractionProcessor class

#include "InteractionProcessor.hpp"
#include "EditorException.hpp"
#include "Interaction.hpp"
#include <vector>


// This function implements command execution, but does not handle "undo"
// and "redo"; you'll need to add that handling.

void InteractionProcessor::run()
{
    std::vector<Command*> allComs;
    std::vector<Command*> undoComs;

    view.refresh();

    while (true)
    {
        Interaction interaction = interactionReader.nextInteraction();

        if (interaction.type() == InteractionType::quit)
        {
            for (Command* com : allComs)
            {
                delete com;
            }

            for (Command* com : undoComs)
            {
                delete com;
            }
            break;
        }
        else if (interaction.type() == InteractionType::undo)
        {
            if (allComs.size() > 0)
            {
                Command* command = allComs[allComs.size()-1];
                undoComs.push_back(command);
                command->undo(model);
                allComs.pop_back();
                model.clearErrorMessage();
                view.refresh();
            }
        }
        else if (interaction.type() == InteractionType::redo)
        {
            if (undoComs.size() > 0)
            {
                Command* command = undoComs[undoComs.size()-1];
                allComs.push_back(command);
                command->execute(model);
                undoComs.pop_back();
                model.clearErrorMessage();
                view.refresh();
            }
        }
        else if (interaction.type() == InteractionType::command)
        {
            Command* command = interaction.command();

            try
            {
                command->execute(model);
                model.clearErrorMessage();
                allComs.push_back(command);
                for (Command* com : undoComs)
                {
                    delete com;
                }
                undoComs.clear();
            }
            catch (EditorException& e)
            {
                model.setErrorMessage(e.getReason());
                delete command;
            }
            view.refresh();

            // Note that you'll want to be more careful about when you delete
            // commands once you implement undo and redo.  For now, since
            // neither is implemented, I've just deleted it immediately
            // after executing it.  You'll need to wait to delete it until
            // you don't need it anymore.
            // delete command;
        }
    }
}

