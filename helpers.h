#ifndef TASK1_HELPERS_H
#define TASK1_HELPERS_H

// Checks that list doesn't exists and if it is, alert a user
void StringInitListHelper(char*** list);

// Checks that list exits and the create a new node. In the opposite way suggest to create a new list;
void StringListAddHelper(char** list);

/* Checks that list exits and then delete all occurrences of the string. In the opposite way,
 * suggest to create a new list */
void StringListRemoveHelper(char*** list);

/* Checks that list exists and return a number of elements. In the opposite way, inform that list is not initialized */
void StringListSizeHelper(char** list);

/* Checks that list exists and return an index of an element.
 * If the element doesn't exist informs user about that.
 * If list doesn't exists, informs user about that */
void StringListIndexOfHelper(char** list);

/* Checks that list exits and then removes all duplicates. If list doesn't exists, informs user about that */
void StringListRemoveDuplicatesHelper(char** list);

/*Checks that list exits and then replaces a part of a string. If list doesn't exists, informs user about that */
void StringListReplaceInStringsHelper(char** list);

/* Checks that list exists and then sort it */
void StringListSortHelper(char*** list);

/* Checks that list exists and then destroy it */
void StringListDestroyHelper(char*** list);

#endif //TASK1_HELPERS_H
