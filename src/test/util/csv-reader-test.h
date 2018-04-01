#ifndef HCTH_TEST_UTIL_CSV_READER_TEST_H
#define HCTH_TEST_UTIL_CSV_READER_TEST_H

#include "gtest/gtest.h"

namespace hctpch {
namespace util {

class CSVReaderTest: public testing::Test {
public:
    char* mInput;

protected:
    CSVReaderTest();
    virtual ~CSVReaderTest();

    virtual void SetUp();
    virtual void TearDown();
};

} // end of namespace util
} // end of namespace hctpch

#endif
