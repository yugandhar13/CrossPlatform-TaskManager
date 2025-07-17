#include <gtest/gtest.h>
#include "TaskManager.hpp"

TEST(TaskManager, CanRefreshTasks) {
    TaskManager tm;
    EXPECT_NO_THROW(tm.refreshTasks()); // Should not crash
}
