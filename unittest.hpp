#include <iostream>
#include <gtest/gtest.h>


TEST(MainTestCase, DummyTest)
{
	std::cout << "Hello world!" << std::endl;
	EXPECT_EQ(true, true);
}

int main(int, char*[]);
