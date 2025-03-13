#include <vscode.h>
#include "data_structures.h"

using namespace vscode;

static DataStructures* dataStructures = nullptr;
static size_t copyCount = 0;
static size_t pasteCount = 0;

void activate(ExtensionContext* context) {
    // Initialize data structures
    dataStructures = new DataStructures(3);

    // Register commands
    context->subscriptions.push_back(
        commands->registerCommand("advanced-copy-paste.copy", []() {
            if (!dataStructures) return;

            // Get selected text
            auto editor = window->activeTextEditor;
            if (!editor) return;

            auto selection = editor->selection;
            if (selection->isEmpty()) return;

            auto text = editor->document->getText(selection);
            dataStructures->copy(text);
            copyCount++;
        })
    );

    context->subscriptions.push_back(
        commands->registerCommand("advanced-copy-paste.paste", []() {
            if (!dataStructures) return;

            auto editor = window->activeTextEditor;
            if (!editor) return;

            auto text = dataStructures->paste();
            if (!text.empty()) {
                editor->edit(editBuilder => {
                    editBuilder->replace(editor->selection, text);
                });
            }
            pasteCount++;
        })
    );

    context->subscriptions.push_back(
        commands->registerCommand("advanced-copy-paste.displayContent", [](const CommandArgs& args) {
            if (!dataStructures) return;

            size_t index = 0;
            if (args.arguments && args.arguments->size() > 0) {
                index = args.arguments->at(0).as<size_t>();
            }

            auto content = dataStructures->getContentAtIndex(index);
            if (!content.empty()) {
                window->showInformationMessage(content);
            }
        })
    );

    context->subscriptions.push_back(
        commands->registerCommand("advanced-copy-paste.switchDataStructure", []() {
            if (!dataStructures) return;

            auto currentType = dataStructures->getCurrentType();
            DataStructureType newType;

            switch (currentType) {
                case DataStructureType::ARRAY:
                    newType = DataStructureType::STACK;
                    break;
                case DataStructureType::STACK:
                    newType = DataStructureType::QUEUE;
                    break;
                case DataStructureType::QUEUE:
                    newType = DataStructureType::ARRAY;
                    break;
                default:
                    newType = DataStructureType::ARRAY;
            }

            dataStructures->setDataStructureType(newType);
            window->showInformationMessage("Switched to new data structure");
        })
    );

    context->subscriptions.push_back(
        commands->registerCommand("advanced-copy-paste.clearContent", []() {
            if (!dataStructures) return;

            dataStructures->clear();
            window->showInformationMessage("Cleared all stored content");
        })
    );
}

void deactivate() {
    if (dataStructures) {
        delete dataStructures;
        dataStructures = nullptr;
    }
} 