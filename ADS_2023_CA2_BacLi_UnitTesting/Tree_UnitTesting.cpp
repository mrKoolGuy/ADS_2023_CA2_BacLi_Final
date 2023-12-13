#include "pch.h"
#include "CppUnitTest.h"
#include "../ADS_2023_CA2_BacLi/Tree.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ADS2023CA2BacLiUnitTesting
{
	TEST_CLASS(TestTree)
	{

	public:

		/// <summary>
		/// Testing if the basics of the Tree Class work
		/// </summary>

		TEST_METHOD(testFolderConstructor) 
		{
			string folderName = "directory";
			string emptyString = "";
			Tree<string> tree(folderName);
			Assert::AreEqual(folderName, tree.name);
			Assert::AreEqual(0, tree.length);
			Assert::AreEqual(emptyString, tree.type);
			Assert::IsNotNull(tree.children);
			Assert::AreEqual(0, tree.children->size());
			Assert::IsNull(tree.parent);
		}
		TEST_METHOD(testFileConstructor)
		{
			string fileName = "file";
			int itemSize = 100;
			string fileType = ".exe";
			Tree<string> tree(fileName, itemSize, fileType);
			Assert::AreEqual(fileName, tree.name);
			Assert::AreEqual(itemSize, tree.length);
			Assert::AreEqual(fileType, tree.type);
			Assert::IsNull(tree.parent);
		}

	};
}
