#include "pch.h"
#include "CppUnitTest.h"
#include "../ADS_2023_CA2_BacLi/Stack.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ADS2023CA2BacLiUnitTesting
{
	TEST_CLASS(TestStack)
	{

	public:

		/// <summary>
		/// Testing if the basics of the Stack Class works
		/// </summary>
		
		TEST_METHOD(testPush) 
		{
			int validStackCap = 10;
			MyStack<string> stack("", validStackCap);
			string test1 = "string 1";
			Assert::IsTrue(stack.push(test1));

			Assert::AreEqual(stack.top(), test1);
		}
		TEST_METHOD(testPushWithFullCapacity)
		{
			int validStackCap = 1;
			MyStack<string> stack("", validStackCap);
			string test1 = "string 1";

			Assert::IsTrue(stack.push(test1));
			string test2 = "string 2";
			Assert::IsFalse(stack.push(test2));
		}
		TEST_METHOD(testTop) 
		{
			int validStackCap = 10;
			MyStack<string> stack("", validStackCap);
			string test1 = "string 1";
			string test2 = "string 2";

			stack.push(test1);
			stack.push(test2);
			Assert::AreEqual(stack.top(), test2);
		}
		TEST_METHOD(testTopWithEmptyStack)
		{
			int validStackCap = 10;
			MyStack<string> stack("", validStackCap);
			string emptyString = "";
			Assert::AreEqual(stack.top(), emptyString);
		}
		TEST_METHOD(testPop)
		{
			int validStackCap = 10;
			MyStack<string> stack("", validStackCap);
			string test1 = "string 1";
			string test2 = "string 2";

			stack.push(test1);
			stack.push(test2);
			stack.pop();
			Assert::AreEqual(stack.top(), test1);
		}
		TEST_METHOD(testPopWithEmptyStack) 
		{
			int validStackCap = 10;
			MyStack<string> stack("", validStackCap);
			
			stack.pop();
			Assert::IsTrue(stack.isEmpty());
		}
	};
}
