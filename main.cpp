#include <iostream>
#include "helpers.h"

enum Options {
    Exit,
    InitializeList,
    AddNewItem,
    RemoveAllNodesWithString,
    ListSize,
    IndexPosition,
    RemoveDuplicates,
    Replace,
    Sort,
    Destroy
};

int main() {
    char** list = NULL;
    bool condition{true};
    std::string choice;
    int option{0};
    while (condition) {
        std::cout << "1 - Create new list \n" \
                     "2 - Add a new node \n" \
                     "3 - Remove all occurrences of string in the list\n" \
                     "4 - Return the number of items in the list\n" \
                     "5 - Return the index position of the string\n" \
                     "6 - Removes duplicates from the list\n" \
                     "7 - Replace the part of the string\n" \
                     "8 - Sort the list\n" \
                     "9 - Destroy list\n" \
                     "0 - Exit\n";

        std::cout << "Please, enter your choice: ";
        getline(std::cin, choice);
        option = std::stoi(choice);

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
