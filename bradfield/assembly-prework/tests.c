#include "vendor/unity.h"

extern int sum_to_n(int n);
extern int binary_convert(char *bits);
extern int pangram(char *phrase);

void setUp(void) {
}

void tearDown(void) {
}

void test_sum_to_0(void) { TEST_ASSERT_EQUAL(0, sum_to_n(0)); }
void test_sum_to_1(void) { TEST_ASSERT_EQUAL(1, sum_to_n(1)); }
void test_sum_to_3(void) { TEST_ASSERT_EQUAL(6, sum_to_n(3)); }
void test_sum_to_10(void) { TEST_ASSERT_EQUAL(55, sum_to_n(10)); }
void test_sum_to_1000(void) { TEST_ASSERT_EQUAL(500500, sum_to_n(1000)); }

void test_convert_0(void) { TEST_ASSERT_EQUAL(0, binary_convert("0")); }
void test_convert_1(void) { TEST_ASSERT_EQUAL(1, binary_convert("1")); }
void test_convert_110(void) { TEST_ASSERT_EQUAL(6, binary_convert("110")); }
void test_convert_1111(void) { TEST_ASSERT_EQUAL(15, binary_convert("1111")); }
void test_convert_10101101(void) {
  TEST_ASSERT_EQUAL(173, binary_convert("10101101"));
}

void test_pangram_empty(void) { TEST_ASSERT_FALSE(pangram("")); }
void test_pangram_alpha(void) {
  TEST_ASSERT_TRUE(pangram("abcdefghijklmnopqrstuvwxyz"));
}
void test_pangram_punctuated(void) {
  TEST_ASSERT_TRUE(pangram("abc, def! ghi... jkl25; mnopqrstuvwxyz"));
}
void test_pangram_incomplete(void) {
  TEST_ASSERT_FALSE(pangram("abcdefghijklmnopqrstuvwxy"));
}
void test_pangram_mixed_case(void) {
  TEST_ASSERT_TRUE(pangram("ABCdefGHIjklMNOpqrSTUvwxYZ"));
}
void test_pangram_phrase(void) {
  TEST_ASSERT_TRUE(pangram("the quick brown fox jumps over teh lazy dog"));
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_sum_to_0);
    RUN_TEST(test_sum_to_1);
    RUN_TEST(test_sum_to_3);
    RUN_TEST(test_sum_to_10);
    RUN_TEST(test_sum_to_1000);

    RUN_TEST(test_convert_0);
    RUN_TEST(test_convert_1);
    RUN_TEST(test_convert_110);
    RUN_TEST(test_convert_1111);
    RUN_TEST(test_convert_10101101);

    RUN_TEST(test_pangram_empty);
    RUN_TEST(test_pangram_alpha);
    RUN_TEST(test_pangram_punctuated);
    RUN_TEST(test_pangram_incomplete);
    RUN_TEST(test_pangram_mixed_case);
    RUN_TEST(test_pangram_phrase);

    return UNITY_END();
}
