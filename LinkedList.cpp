#include <stdlib.h>
#include <string.h>

void StringListInit(char*** list);
void StringListDestroy(char*** list);
void StringListAdd(char** list, char* str);
void StringListRemove(char*** list, char* str);
int StringListSize(char** list);
int StringListIndexOf(char** list, char* str);
void StringListRemoveDuplicates(char** list);
void StringListReplaceInStrings(char** list, char* before, char* after);
void StringListSort(char*** list);

void StringListInit(char*** list) {
    *list = (char**)malloc(3*sizeof(char*));
    **list = NULL;
    *(*list + 1) = NULL; // pointer to the next node
    *(*list + 2) = NULL; // pointer to the previous node
}

void StringListDestroy(char*** list) {
    char **temp;
    if(*list) {
        while(*(*list + 1)) {
            temp = (char**) *(*list + 1);
            free(**list);
            free(*list);
            *list = temp;
        }
        free(**list);
    }
    free(*list);
    *list = NULL;
}

void StringListAdd(char** list, char* str) {
    char** temp = list;
    if(!(*list)) {
        *list = (char*)malloc(sizeof(char) * (strlen(str) + 1));
        strcpy(*list, str);
    }
    else {
        while(*(temp+1)) {
            temp = (char**) *(temp + 1);
        }

        char** node = (char**)malloc(3 * sizeof(char*));
        *node = (char*)malloc(sizeof(char) * (strlen(str) + 1));
        strcpy(*node, str);
        *(node + 1) = NULL; // pointer to the next node
        *(node + 2) = (char*)temp; // pointer to the previous node
        *(temp + 1) = (char*)node; // pointer to the next node of the current node, points to the new node
    }
}

void StringListRemove(char*** list, char* str) {
    char** temp = *list;
    char** nextNode = (char**) *(*list + 1);
    char** prevNode = (char**) *(*list + 2);

    while(temp && *temp) {
        if(!strcmp(*temp, str)) {
            if (nextNode) {
                *(nextNode + 2) = (char *) *(temp + 2);
            }

            if (prevNode) {
                *(prevNode + 1) = (char*) nextNode;
            }

            free(*temp);
            free(temp);
        }
        temp = nextNode;
        prevNode = temp ? (char**) *(temp + 2) : NULL;
        nextNode = nextNode ? (char**) *(nextNode + 1) : NULL;

        // If removed node header, list will point to the next node
        if(temp && !(*(temp + 2))) {
            *list = temp;
        }
    }
}

int StringListSize(char** list) {
    int count = 0;

    while(list) {
        count++;
        list = (char**) *(list + 1);
    }

    return count;
}

int StringListIndexOf(char** list, char* str) {
    int count = 0;
    while(list) {
        if(!strcmp(*list, str)) {
            return count;
        }

        list = (char**) *(list + 1);
        count++;
    }
    return -1; // if string is not presented in list
}

void StringListRemoveDuplicates(char** list) {
    char** nextNode;
    char** prevNode;
    char** temp;

    while(list) {
        temp = (char**) *(list + 1);
        while(temp) {
            nextNode = (char **) *(temp + 1);
            prevNode = (char **) *(temp + 2);

            if(!strcmp(*list, *temp)) {
                *(prevNode + 1) = (char*) nextNode;
                if(nextNode) {
                    *(nextNode + 2) = (char*) prevNode;
                }
                free(*temp);
                free(temp);
            }
            temp = nextNode;
        }
        list = (char**) *(list + 1);
    }
}

void StringListReplaceInStrings(char** list, char* before, char* after) {
    char* substring;
    char* new_string;
    int before_length{int(strlen(before))};
    int after_length{int(strlen(after))};
    int current_str_length;
    int substring_length;
    int diff;
    int new_string_length;
    while(list) {
        substring = strstr(*list, before);
        if (substring) {
            current_str_length = strlen(*list);
            substring_length = strlen(substring);
            diff = current_str_length - substring_length;
            new_string_length = current_str_length - before_length + after_length;

            new_string = (char*) malloc(sizeof(char) * new_string_length);
            strcpy(new_string, "");
            strncpy(new_string, *list, diff);
            strcat(new_string, after);

            if(substring_length != before_length) {
                strcat(new_string, substring + before_length);
            }
            *list = (char*) realloc(*list, sizeof(char) * new_string_length);
            strcpy(*list, new_string);

            free(new_string);
        }
        list = (char**) *(list + 1);
    }
}

void StringListSort(char*** list) {
    char** nextNode;
    char** prevNode;
    char** temp;
    char** forwardNode;

    for (int i = 0; i < StringListSize(*list) - 1; i++) {
        temp = *list;
        nextNode = (char**) *(*list + 1);
        prevNode = (char**) *(*list + 2);

        while (nextNode) {
            if (strcmp(*temp, *nextNode) > 0) {
                forwardNode = (char**) *(nextNode + 1);

                if (forwardNode) {
                    *(forwardNode + 2) = (char*) temp;
                }

                *(temp + 1) = *(nextNode + 1);
                *(temp + 2) = (char *) nextNode;

                if (temp == *list) {
                    *list = nextNode;
                    *(*list + 1) = (char *) temp;
                    *(*list + 2) = NULL;
                } else {
                    *(nextNode + 1) = (char *) temp;
                    *(nextNode + 2) = (char *) prevNode;
                    *(prevNode + 1) = (char *) nextNode;
                }
            } else {
                temp = (char **) nextNode;
            }
            nextNode = (char **) *(temp + 1);
            prevNode = (char **) *(temp + 2);
        }
    }
}