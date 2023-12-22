#include "pch.h"
#include "checker.h"

TEST(Test, Test1) {
	EXPECT_EQ(checker("???.###", "113"), 1);
}
TEST(Test, Test2) {
	EXPECT_EQ(checker(".??..??...?##.", "113"), 4);
}

TEST(Test, Test3) {
	EXPECT_EQ(checker("?#?#?#?#?#?#?#?", "1316"), 1);
}
TEST(Test, Test4) {
	EXPECT_EQ(checker("????.#...#...", "411"), 1);
}


TEST(Test, Test5) {
	EXPECT_EQ(checker("????.######..#####.","165"), 4);
}
TEST(Test, Test6) {
	EXPECT_EQ(checker("?###????????", "321"), 10);
}

//TEST(Test, Test7) {
//	EXPECT_EQ(checker("?#?#?#?#?#?#?#?", "1316"), 1);
//}
//TEST(Test, Test8) {
//	EXPECT_EQ(checker("????.#...#...", "411"), 1);
//}
