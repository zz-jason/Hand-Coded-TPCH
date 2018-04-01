#ifndef HCTH_UTIL_MEMORY_MANAGER_H
#define HCTH_UTIL_MEMORY_MANAGER_H

#include <assert.h>
#include <stddef.h>
#include <stdint.h>

namespace hctpch {
namespace util {

class MemoryManager {
public:
    MemoryManager();
    ~MemoryManager();
    char* Allocate(size_t bytes);
    char* AllocateAligned(size_t bytes);
    size_t GetTotal() const { return mTotal; }
    size_t GetUsed()  const { return mUsed; }

private:
    MemoryManager(const MemoryManager&);
    MemoryManager& operator =(const MemoryManager&);

    char* AllocateFallback(size_t bytes);
    char* AllocateNewBlock(size_t bytes);

private:
    struct BlockNode;

private:
    const static size_t BLOCK_SIZE = (4 << 10);

    size_t mTotal;
    size_t mUsed;

    BlockNode* mBlockNode;
    size_t mRemaining;
    char*  mAllocPtr;
};

struct MemoryManager::BlockNode {
    BlockNode() : mBlock(NULL), mNext(this), mPrev(this) {}
    BlockNode(size_t bytes) : mBlock(new char[bytes]), mNext(this), mPrev(this) {}
    ~BlockNode() { if (mBlock != NULL) delete[] mBlock; }

    char* mBlock;
    BlockNode* mNext;
    BlockNode* mPrev;
};

MemoryManager::MemoryManager() :
    mTotal(0), mUsed(0),
    mBlockNode(new BlockNode), mRemaining(0), mAllocPtr(NULL) {}

MemoryManager::~MemoryManager() {
    BlockNode* tail(mBlockNode->mPrev);
    for (BlockNode* i(mBlockNode); i != tail; ) {
        BlockNode* cur(i);
        i = i->mNext;
        delete cur;
    }
    delete tail;
}

char* MemoryManager::Allocate(size_t bytes) {
    assert(bytes > 0);
    if (bytes > mRemaining) {
        return AllocateFallback(bytes);
    }
    char* res(mAllocPtr);
    mUsed      += bytes;
    mAllocPtr  += bytes;
    mRemaining -= bytes;
    return res;
}

char* MemoryManager::AllocateAligned(size_t bytes) {
    const size_t align(sizeof(void*));
    assert((align & (align - 1)) == 0);

    size_t currMod(reinterpret_cast<uintptr_t>(mAllocPtr) & (align - 1));
    size_t slop(currMod == 0 ? 0 : align - currMod);

    size_t needed(bytes + slop);
    if (needed > mRemaining) {
        char* res = AllocateFallback(bytes);
        assert((reinterpret_cast<uintptr_t>(res) & (align - 1)) == 0);
        return res;
    }

    char* res = mAllocPtr + slop;
    mUsed      += needed;
    mAllocPtr  += needed;
    mRemaining -= needed;
    assert((reinterpret_cast<uintptr_t>(res) & (align - 1)) == 0);
    return res;
}

char* MemoryManager::AllocateFallback(size_t bytes) {
    if (bytes > BLOCK_SIZE / 4) {
        return AllocateNewBlock(bytes);
    }

    mAllocPtr = AllocateNewBlock(BLOCK_SIZE);
    mRemaining = BLOCK_SIZE;

    char* res(mAllocPtr);
    mUsed      += bytes;
    mAllocPtr  += bytes;
    mRemaining -= bytes;
    return res;
}

char* MemoryManager::AllocateNewBlock(size_t bytes) {
    mTotal += bytes;
    BlockNode* block(new BlockNode(bytes));
    block->mPrev = mBlockNode->mPrev;
    block->mNext = mBlockNode;
    mBlockNode->mPrev->mNext = block;
    mBlockNode->mPrev = block;
    return block->mBlock;
}

} // end of namespace util
} // end of namespace hctpch

#endif
