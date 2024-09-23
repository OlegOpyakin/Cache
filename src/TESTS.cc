#include <gtest/gtest.h>
#include <LFU_modded.h>

class LFUTest : public ::testing::Test {
protected:
    LFU<unsigned int>* lfu;
    LFU<unsigned int>* lfu1;
    LFU<int>* lfu2;

    void SetUp() override {
        lfu = new LFU<unsigned int>(3);
        lfu1 = new LFU<unsigned int>(1);
        lfu2 = new LFU<int>(2);
    }

    void TearDown() override {
        delete lfu;
        delete lfu1;
        delete lfu2;
    }
};

// Test for adding an element
TEST_F(LFUTest, AddElement) {
    lfu->Put(1);
    EXPECT_TRUE(lfu->BoolFindKey(1));
}

// Frequency increase test
TEST_F(LFUTest, FrequencyIncrement) {
    lfu->Put(1);
    lfu->Put(1);
    EXPECT_EQ(lfu->ReturnHits(), 1);
}

// Test for removing an element with a minimum frequency
TEST_F(LFUTest, PopMinFreqElement) {
    lfu->Put(1);
    lfu->Put(2);
    lfu->Put(3);
    lfu->Put(4);

    EXPECT_FALSE(lfu->BoolFindKey(1)); // Проверяем, что элемент 1 был удален
}

// Test for the counts of "hits"
TEST_F(LFUTest, ReturnHits) {
    lfu->Put(1);
    lfu->Put(2);
    lfu->Put(1);
    EXPECT_EQ(lfu->ReturnHits(), 1);
}

// Test for deletion when the cache size is exceeded
TEST_F(LFUTest, ExceedCacheSize) {
    lfu->Put(1);
    lfu->Put(2);
    lfu->Put(3);
    lfu->Put(4);

    EXPECT_FALSE(lfu->BoolFindKey(1)); // Check that element 1 has been deleted
    EXPECT_TRUE(lfu->BoolFindKey(2));  // Check that element 2 has been not deleted
}

// HARD test
TEST_F(LFUTest, HardTest) {
    lfu1->Put(1);
    lfu1->Put(2);
    lfu1->Put(2);
    lfu1->Put(1);

    EXPECT_EQ(lfu1->ReturnHits(), 1); // Check that element 1 has been deleted
}

// TeacherTest test
TEST_F(LFUTest, TeacherTest) {
    lfu2->Put(1);
    lfu2->Put(2);
    lfu2->Put(1);
    lfu2->Put(2);
    lfu2->Put(1);
    lfu2->Put(2);

    EXPECT_EQ(lfu2->ReturnHits(), 4); // Check that element 1 has been deleted
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
