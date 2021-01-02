#include <stdlib.h>
#include <string.h>
#include <memory>
#include "gtest/gtest.h"
#include "../LinkedList.h"
#include "TestFixtures.h"


TEST (ListTests, InitList) {
    char** list;
    StringListInit(&list);
    ASSERT_TRUE(list);
    ASSERT_FALSE(*list);
    ASSERT_FALSE(*(list+1));
    ASSERT_FALSE(*(list + 2));
    free(list);
}

TEST (ListTests, DeleteList) {
    char** list;
    StringListInit(&list);
    ASSERT_EQ(sizeof(list), sizeof(char**));
    StringListDestroy(&list);
    ASSERT_FALSE(list);
}

TEST (ListTests, AddItemToList) {
    char** list;
    StringListInit(&list);
    ASSERT_EQ(sizeof(list), sizeof(char**));
    StringListAdd(list, "new world");
    ASSERT_EQ(strcmp(*list, "new world"), 0);

    StringListAdd(list, "new hope");
    char** temp = (char**) *(list + 1);
    ASSERT_EQ(strcmp(*temp, "new hope"), 0);

    StringListAdd(list, "imagination");
    temp = (char**) *(temp + 1);
    ASSERT_EQ(strcmp(*temp, "imagination"), 0);

    StringListAdd(list, "exploring new world");
    temp = (char**) *(temp + 1);
    ASSERT_EQ(strcmp(*temp, "exploring new world"), 0);

    StringListDestroy(&list);
}

TEST_F (TestFixtures, RemoveNodesWithStr) {
    StringListAdd(list, "new world");
    StringListAdd(list, "burned people");
    StringListRemove(&list, "new world");

    ASSERT_EQ(strcmp(*list, "new hope"), 0);
    ASSERT_FALSE(*(list + 2));

    char** temp = (char**) *(list + 1);
    temp = (char**) *(temp + 1);
    ASSERT_EQ(strcmp(*temp, "burned people"), 0);
}

TEST_F (TestFixtures, ListSize) {
    int size = StringListSize(list);

    ASSERT_EQ(size, 3);
}

TEST_F (TestFixtures, IndexOfNode) {
    int index = StringListIndexOf(list, "new world");
    ASSERT_EQ(index, 0);

    index = StringListIndexOf(list, "imagination");
    ASSERT_EQ(index, 2);

    index = StringListIndexOf(list, "burned people");
    ASSERT_EQ(index, -1);
}

TEST_F (TestFixtures, RemoveDuplicates) {
    StringListAdd(list, "new world");
    StringListRemoveDuplicates(list);

    char** outer_temp = list;
    char** inner_temp;
    while (outer_temp) {
        inner_temp = (char**) *(outer_temp + 1);
        while (inner_temp) {
            ASSERT_TRUE(strcmp(*inner_temp, *outer_temp));
            inner_temp = (char**) *(inner_temp + 1);
        }
        outer_temp = (char**) *(outer_temp + 1);
    }
}

TEST_F (TestFixtures, ReplaceInString) {
    StringListAdd(list, "exploring new world");
    StringListAdd(list, "world new");
    StringListReplaceInStrings(list, "new", "old");

    ASSERT_EQ(strcmp(*list, "old world"), 0);

    char** temp = (char**) *(list + 1);
    ASSERT_EQ(strcmp(*temp, "old hope"), 0);

    temp = (char**) *(temp + 1);
    ASSERT_EQ(strcmp(*temp, "imagination"), 0);

    temp = (char**) *(temp + 1);
    ASSERT_EQ(strcmp(*temp, "exploring old world"), 0);

    temp = (char**) *(temp + 1);
    ASSERT_EQ(strcmp(*temp, "world old"), 0);
}

TEST_F (TestFixtures, SortStrings) {
    char** new_world_pointer = list;
    char** new_hope_pointer = (char**) *(list + 1);
    char** imagination_pointer = (char**) *(new_hope_pointer + 1);

    StringListSort(&list);

    ASSERT_EQ(strcmp(*list, "imagination"), 0);
    ASSERT_EQ(*(list + 1), (char*) new_hope_pointer);
    ASSERT_FALSE(*(list + 2));

    char** temp = (char**) *(list + 1);
    ASSERT_EQ(strcmp(*temp, "new hope"), 0);
    ASSERT_EQ(*(temp + 1), (char*) new_world_pointer);
    ASSERT_EQ(*(temp + 2), (char*) imagination_pointer);

    temp = (char**) *(temp + 1);
    ASSERT_EQ(strcmp(*temp, "new world"), 0);
    ASSERT_FALSE(*(temp + 1));
    ASSERT_EQ(*(temp + 2), (char*) new_hope_pointer);
}

int main(int args, char** argv) {
    testing::InitGoogleTest(&args, argv);
    return RUN_ALL_TESTS();
}
