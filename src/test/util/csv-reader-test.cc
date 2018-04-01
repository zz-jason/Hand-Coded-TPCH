#include "csv-reader-test.h"
#include "util/csv-reader.h"
#include "util/common-macros.h"

namespace hctpch {
namespace util {

CSVReaderTest::CSVReaderTest() {
    mInput = reinterpret_cast<char*>(malloc(255));
}

CSVReaderTest::~CSVReaderTest() {
    SAFE_DELETE(mInput);
}

void CSVReaderTest::SetUp() {
}

void CSVReaderTest::TearDown() {
}

TEST_F(CSVReaderTest, TestCutBigint) {
    char* input;
    int32_t result;

    for (char i = '0'; i < '9'; ++i) {
        mInput[0] = i;
        mInput[1] = '|';

        input = mInput;
        CutOneField(&input, &result, NULL);
        EXPECT_EQ(result, i - '0');
    }

    for (char i = '0'; i < '9'; ++i) {
        for (char j = '0'; j < '9'; ++j) {
            mInput[0] = i;
            mInput[1] = j;
            mInput[2] = '|';

            input = mInput;
            CutOneField(&input, &result, NULL);
            EXPECT_EQ(result, (i - '0') * 10 + (j - '0'));
        }
    }
}

TEST_F(CSVReaderTest, TestCutDouble) {
    char* input;
    double result;

    for (char i = '0'; i < '9'; ++i) {
        mInput[0] = '0';
        mInput[1] = '.';
        mInput[2] = i;
        mInput[3] = '|';

        input = mInput;
        CutOneField(&input, &result, NULL);
        EXPECT_DOUBLE_EQ(result, (i - '0') * 0.1);
    }

    for (char i = '0'; i < '9'; ++i) {
        for (char j = '0'; j < '9'; ++j) {
            mInput[0] = i;
            mInput[1] = j;
            mInput[2] = '|';

            input = mInput;
            CutOneField(&input, &result, NULL);
            EXPECT_DOUBLE_EQ(result, (i - '0') * 10 + (j - '0'));
        }
    }
}

} // end of namespace util
} // end of namespace hctpch
