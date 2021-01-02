#include <iostream>
#include "helpers.h"

enum class Options {
    InitializeList,
    AddNewItem,
    RemoveAllNodesWithString,
    ListSize,
    IndexPosition,
    RemoveDuplicates,
    Replace,
    Sort,
    Destroy,
    Exit
};

int main() {
    char** list = NULL;
    Options option;
    std::string choice;
    bool condition{true};
    while (condition) {
        std::cout << "0 - Create new list \n" \
                     "1 - Add a new node \n" \
                     "2 - Remove all occurrences of string in the list\n" \
                     "3 - Return the number of items in the list\n" \
                     "4 - Return the index position of the string\n" \
                     "5 - Removes duplicates from the list\n" \
                     "6 - Replace the part of the string\n" \
                     "7 - Sort the list\n" \
                     "8 - Destroy list\n" \
                     "9 - Exit\n";

        std::cout << "Please, enter your choice: ";
        getline(std::cin, choice);
        option  = static_cast<Options>(std::stoi(choice));

        switch (option) {
            case Options::InitializeList: StringInitListHelper(&list); break;
            case Options::AddNewItem: StringListAddHelper(list); break;
            case Options::RemoveAllNodesWithString: StringListRemoveHelper(&list); break;
            case Options::ListSize: StringListSizeHelper(list); break;
            case Options::IndexPosition: StringListIndexOfHelper(list); break;
            case Options::RemoveDuplicates: StringListRemoveDuplicatesHelper(list); break;
            case Options::Replace: StringListReplaceInStringsHelper(list); break;
            case Options::Sort: StringListSortHelper(&list); break;
            case Options::Destroy: StringListDestroyHelper(&list); break;
            case Options::Exit: condition = false; break;
            default: std::cout << "Wrong option! Please try again\n"; break;
        }
    }

    return 0;
}