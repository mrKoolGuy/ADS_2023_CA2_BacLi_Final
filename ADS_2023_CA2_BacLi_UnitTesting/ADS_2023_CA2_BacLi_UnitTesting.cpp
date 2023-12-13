#include "pch.h"
#include "CppUnitTest.h"
#include "../ADS_2023_CA2_BacLi/XML_Parser.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ADS2023CA2BacLiUnitTesting
{
	TEST_CLASS(ADS2023CA2BacLiUnitTesting)
	{

	public:
		
		/// <summary>
		/// ValidateXML() Unit Tests
		/// </summary>
		TEST_METHOD(testValidateXMLwithValidXML)
		{
			string testXML = "<root><dir><name>super</name><file><name>file1</name><length>1234</length><type>.exe</type></file><file><name>file2</name><length>1222</length><type>.png</type></file></dir></root>";
			XML_Parser xml(testXML);
			Assert::IsTrue(xml.ValidateXML());
		}
		TEST_METHOD(testValidateXMLwithInvalidXML)
		{
			string testXML = "<root> treeRoot <dir> <name>new name</name><file></dir></root>";
			XML_Parser xml(testXML);
			Assert::IsFalse(xml.ValidateXML());
		}
		TEST_METHOD(testValidateXMLwithEmptyXML)
		{
			string testXML = "  ";
			XML_Parser xml(testXML);
			Assert::IsFalse(xml.ValidateXML());
		}
		TEST_METHOD(testValidateXMLwithDuplicateTags)
		{
			string testXML = "<root> TreeRoot <dir> <name><name></name> </name> <file>i love you </file></dir></root>";
			XML_Parser xml(testXML);
			Assert::IsFalse(xml.ValidateXML());
		}
		TEST_METHOD(testValidateXMLwithIncorrectRoot)
		{
			string testXML = R"(
			<name>test</name>
				</dir>
			)";
			XML_Parser xml(testXML);
			Assert::IsFalse(xml.ValidateXML());				
		}

		//test the extra methods


		
	};
}
