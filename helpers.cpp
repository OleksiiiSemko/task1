#include <iostream>
#include <string>
#include <string.h>
#include "LinkedList.h"

void waiter();

void StringInitListHelper(char*** list) {
    if (*list) {
        std::cout << "The list already exist. Do you want to delete it and create a new one y/n:";
        char choice;
        choice = getchar();

        if (choice == 'y') {
            StringListDestroy(list);
            StringListInit(list);
            std::cout << "The list has been initialized\n";
        }
    } else {
        StringListInit(list);
        std::cout << "The list has been initialized\n";
    }
    waiter();
}

void StringListAddHelper(char** list) {
    if (list) {
        std::string temp_str;
        std::cout << "Please enter a string: ";
        getline(std::cin, temp_str);
        char* str = (char*) malloc(temp_str.length() + 1);
        strcpy(str, temp_str.c_str());

        StringListAdd(list, str);
        std::cout << "A new element has been created\n";
        free(str);
    } else {
        std::cout << "You should firstly initialize a list\n";
    }
    waiter();
}

void StringListRemoveHelper(char*** list) {
    if (*list) {
        std::string temp_str;
        std::cout << "Please enter a string: ";
        getline(std::cin, temp_str);
        char* str = (char*) malloc(temp_str.length() + 1);
        strcpy(str, temp_str.c_str());
        StringListRemove(list, str);
        std::cout << "\""<< str << "\"" << "has been removed from the list\n";
        free(str);
    } else {
        std::cout << "You should firstly initialize a list\n";
    }
    waiter();
}

void StringListSizeHelper(char** list) {
    if (list) {
        std::cout << "The size of the list is - " << StringListSize(list) << std::endl;
    } else {
        std::cout << "The list is not initialized\n";
    }
    waiter();
}

void StringListIndexOfHelper(char** list) {
    if (list) {
        std::string temp_str;
        std::cout << "Please, enter a string to find: ";
        getline(std::cin, temp_str);
        char* str = (char*) malloc(temp_str.length() + 1);
        strcpy(str, temp_str.c_str());
        int index{StringListIndexOf(list, str)};
        free(str);

        if (index >=0) {
            std::cout << "The index of the string is - " << index << std::endl;
        } else {
            std::cout << "The string doesn't exist in the list\n";
        }
    } else {
        std::cout << "The list is not initialized\n";
    }
    waiter();
}

void StringListRemoveDuplicatesHelper(char** list) {
    if (list) {
        StringListRemoveDuplicates(list);
        std::cout << "All duplicates have been removed\n";
    } else {
        std::cout << "The list is not initialized\n";
    }
    waiter();
}

void StringListReplaceInStringsHelper(char** list) {
    if (list) {
        std::string before_temp;
        std::string after_temp;

        std::cout << "Please enter a part of the string to replace: ";
        getline(std::cin, before_temp);

        std::cout << "Please, enter a new part: ";
        getline(std::cin, after_temp);

        char* before = (char*) malloc(before_temp.length());
        strcpy(before, before_temp.c_str());
        char* after = (char*) malloc(after_temp.length());
        strcpy(after, after_temp.c_str());

        StringListReplaceInStrings(list, before, after);
        std::cout << "\"" << before << "\" " << "has been replaced on " << "\"" << after << "\"\n";
        free(before);
        free(after);
    } else {
        std::cout << "The list is not initialized\n";
    }
    waiter();
}

void StringListSortHelper(char*** list) {
    if (*list) {
        StringListSort(list);
        std::cout << "The list has been sorted";
    } else {
        std::cout << "The list is not initialized\n";
    }
    waiter();
}

void StringListDestroyHelper(char*** list) {
    if (*list) {
        StringListDestroy(list);
        std::cout << "The list has been destroyed\n";
    } else {
        std::cout << "The list is not initialized\n";
    }
    waiter();
}

void waiter() {
    std::cout << "Press Enter to continue";
    getchar();
}