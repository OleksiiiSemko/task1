#ifndef GOOGLE_TESTS_TESTFIXTURES_H
#define GOOGLE_TESTS_TESTFIXTURES_H
#include <gtest/gtest.h>
#include "../LinkedList.h"


class TestFixtures : public testing::Test {
public:
    void InitializationFixture() {
        StringListInit(&list);
        StringListAdd(list, "new world");
        StringListAdd(list, "new hope");
        StringListAdd(list, "imagination");
    };
    void SetUp() override {
        InitializationFixture();
    };
    void TearDown() override {
        StringListDestroy(&list);
    };
protected:
    char** list;
};


#endif //GOOGLE_TESTS_TESTFIXTURES_H
