#include "memory-manager-test.h"
#include "util/memory-manager.h"
#include "util/common-macros.h"

#include <iostream>

namespace hctpch {
namespace util {

MemoryManagerTest::MemoryManagerTest() {
    mMemManager = new MemoryManager;
}

MemoryManagerTest::~MemoryManagerTest() {
    SAFE_DELETE(mMemManager);
}

TEST_F(MemoryManagerTest, TestAllocate) {
    mMemManager->Allocate(10);
    EXPECT_EQ(mMemManager->GetUsed(), 10);
    EXPECT_EQ(mMemManager->GetTotal(), 4096);
}

} // end of namespace util
} // end of namespace hctpch
