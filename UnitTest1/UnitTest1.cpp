#include "pch.h"
#include "CppUnitTest.h"
#include "../PKR 5.2A/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			Student s[2];
			ifstream stream("test");
			int q = 0;
			char* FileName = 0;
			if (stream.is_open())
			{
				q = ProsPhysik(FileName, s, 0);
				stream.close();
			}
			Assert::AreEqual(q, 0);
		}
	};
}