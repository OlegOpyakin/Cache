#include <gtest/gtest.h>
#include "PerfectCache.h"
#include <LFU.h>
#include <random>
#include <ctime>

class PerfectTest : public ::testing::Test{
protected:
    PerfectCache* cache;
    PerfectCache* cache1;
    PerfectCache* cache2;
    PerfectCache* cache3;

    void SetUp() override {
        cache = new PerfectCache(3);
        cache1 = new PerfectCache(1);
        cache2= new PerfectCache(2);
        cache3 = new PerfectCache(1000);
    }

    void TearDown() override {
        delete cache;
        delete cache1;
        delete cache2;
        delete cache3;
    }
};

class LFUTest : public ::testing::Test {
protected:
    LFU<unsigned int>* lfu;
    LFU<unsigned int>* lfu1;
    LFU<int>* lfu2;
    LFU<int>* lfu3;

    void SetUp() override {
        lfu = new LFU<unsigned int>(3);
        lfu1 = new LFU<unsigned int>(1);
        lfu2 = new LFU<int>(2);
        lfu3 = new LFU<int>(1000);
    }

    void TearDown() override {
        delete lfu;
        delete lfu1;
        delete lfu2;
        delete lfu3;
    }
};

// ---------------------- Test for adding an element ----------------------

TEST_F(LFUTest, AddElement) {
    lfu->Put(1);
    EXPECT_TRUE(lfu->BoolFindKey(1));
}

// ---------------------- Frequency increase test ----------------------

TEST_F(PerfectTest, FrequencyIncrement) {
    std::vector<int> mas = {1, 1};
    cache->FillMas(mas);
    cache->Put();
    cache->Put();
    EXPECT_EQ(cache->ShowHits(), 1);
}

TEST_F(LFUTest, FrequencyIncrement) {
    lfu2->Put(1);
    lfu2->Put(1);
    lfu2->Put(2);
    lfu2->Put(2);
    lfu2->Put(3);
    EXPECT_EQ(lfu2->ReturnHits(), 2);
}

// ---------- Test for removing an element with a minimum frequency ----------

TEST_F(LFUTest, PopMinFreqElement) {
    lfu->Put(1);
    lfu->Put(2);
    lfu->Put(3);
    lfu->Put(4);
    EXPECT_FALSE(lfu->BoolFindKey(1)); // Проверяем, что элемент 1 был удален
}

// --------------------- Test for the counts of "hits" ---------------------- 

TEST_F(LFUTest, ReturnHits) {
    lfu->Put(1);
    lfu->Put(2);
    lfu->Put(1);
    EXPECT_EQ(lfu->ReturnHits(), 1);
}

TEST_F(PerfectTest, ReturnHits) {
    std::vector<int> mas = {1, 2, 1};
    cache->FillMas(mas);
    cache->Put();
    cache->Put();
    cache->Put();
    EXPECT_EQ(cache->ShowHits(), 1);
}

// ------------- Test for deletion when the cache size is exceeded -----------

TEST_F(LFUTest, ExceedCacheSize) {
    lfu->Put(1);
    lfu->Put(2);
    lfu->Put(3); 
    lfu->Put(4);

    EXPECT_FALSE(lfu->BoolFindKey(1)); // Check that element 1 has been deleted
    EXPECT_TRUE(lfu->BoolFindKey(2));  // Check that element 2 has been not deleted
}

// -------------------------- HARD test -------------------------- 

TEST_F(LFUTest, HardTest) {
    lfu1->Put(1);
    lfu1->Put(2);
    lfu1->Put(2);
    lfu1->Put(1);

    EXPECT_EQ(lfu1->ReturnHits(), 1); // Check that element 1 has been deleted
}

TEST_F(PerfectTest, HardTest) {
    std::vector<int> mas = {1, 2, 2, 1};
    cache1->FillMas(mas);
    cache1->Put();
    cache1->Put();
    cache1->Put();
    cache1->Put();

    EXPECT_EQ(cache1->ShowHits(), 1); // Check that element 1 has been deleted
}

// -------------------------- TeacherTest test --------------------------

TEST_F(LFUTest, TeacherTest) {
    lfu2->Put(1);
    lfu2->Put(2);
    lfu2->Put(1);
    lfu2->Put(2);
    lfu2->Put(1);
    lfu2->Put(2);

    EXPECT_EQ(lfu2->ReturnHits(), 4); // Check that element 1 has been deleted
}

TEST_F(PerfectTest, TeacherTest) {
    std::vector<int> mas = {1, 2, 1, 2, 1, 2};
    cache2->FillMas(mas);
    cache2->Put();
    cache2->Put();
    cache2->Put();
    cache2->Put();
    cache2->Put();
    cache2->Put();

    EXPECT_EQ(cache2->ShowHits(), 4); // Check that element 1 has been deleted
}

// ------------------- Time for Million Elements test -------------------

TEST_F(LFUTest, MillionElemsTimeTest) {
    std::random_device rd;   // non-deterministic generator
    std::mt19937 gen(rd());  // to seed mersenne twister.
    std::uniform_int_distribution<int> dist(1, 999); // distribute results between 1 and 6 inclusive.
    
    clock_t start = clock();
    for (int i = 0; i < 1000000; i++) {
        lfu3->Put(dist(gen));
    }
    clock_t end = clock();
    double seconds = ((double)(end - start))/CLOCKS_PER_SEC;
    ASSERT_TRUE(seconds <= 1.0);
}

TEST_F(PerfectTest, MillionElemsTimeTest) {
    std::random_device rd;   // non-deterministic generator
    std::mt19937 gen(rd());  // to seed mersenne twister.
    std::uniform_int_distribution<int> dist(1, 999); // distribute results between 1 and 6 inclusive.

    std::vector<int> mas;
    for (int i = 0; i < 1000000; i++) {
        mas.push_back(dist(gen));
    }
    cache3->FillMas(mas);

    clock_t start = clock();
    for (int i = 0; i < 1000000; i++) {
        cache3->Put();
    }
    clock_t end = clock();
    double seconds = ((double)(end - start))/CLOCKS_PER_SEC;
    ASSERT_TRUE(seconds <= 1.0);
}



int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
