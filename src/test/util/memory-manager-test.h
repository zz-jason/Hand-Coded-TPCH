#ifndef HCTH_TEST_UTIL_MEMORU_MANAGER_TEST_H
#define HCTH_TEST_UTIL_MEMORU_MANAGER_TEST_H

#include "gtest/gtest.h"

namespace hctpch {
namespace util {

class MemoryManager;

class MemoryManagerTest: public testing::Test {
public:
    MemoryManager* mMemManager;

protected:
    MemoryManagerTest();
    virtual ~MemoryManagerTest();

    virtual void SetUp() {}
    virtual void TearDown() {}
};

} // end of namespace util
} // end of namespace hctpch

#endif
