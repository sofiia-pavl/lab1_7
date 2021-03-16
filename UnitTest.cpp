#include "pch.h"
#include "CppUnitTest.h"
#include "../lab1.7/Payment.h"
#include "../lab1.7/Date.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Payment P1;
			P1.SetName("a");
			string name = "a";
			Assert::AreEqual(name, P1.GetName());
		}
	};
}
