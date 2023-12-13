#include "pch.h"
#include "CppUnitTest.h"
#include "../ADS_2023_CA2_BacLi/XML_Parser.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ADS2023CA2BacLiUnitTesting
{
	TEST_CLASS(ADS2023CA2BacLiUnitTesting)
	{

	public:
		//Couldn't load a File into Unit Test Project, so I used valid & Invalid Strings

		/// <summary>
		/// ValidateXML() Unit Tests
		/// </summary>
		TEST_METHOD(testValidateXMLwithValidXML)
		{
			string testXML2 = "<dir><name>super</name><file><name>file1</name><length>1234</length><type>.exe</type></file><file><name>file2</name><length>1222</length><type>.png</type></file><dir><name>gaming</name><file><name>newFIle</name><length>1234</length><type>.exe</type></file><dir><name>empty</name></dir></dir></dir>";
			XML_Parser xml(testXML2);
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

		//test the extra methods
		TEST_METHOD(testCreateTree) 
		{
			string testXML2 = "<dir><name>super</name><file><name>file1</name><length>1234</length><type>.exe</type></file><file><name>file2</name><length>1222</length><type>.png</type></file><dir><name>gaming</name><file><name>newFIle</name><length>1234</length><type>.exe</type></file><dir><name>empty</name></dir></dir></dir>";
			XML_Parser xml(testXML2);

			Tree<string>* root = nullptr;
			xml.CreateTree(root);

			Assert::IsNotNull(root);
		}
		TEST_METHOD(testCountItems)
		{
			string testXML2 = "<dir><name>super</name><file><name>file1</name><length>1234</length><type>.exe</type></file><file><name>file2</name><length>1222</length><type>.png</type></file><dir><name>gaming</name><file><name>newFIle</name><length>1234</length><type>.exe</type></file><dir><name>empty</name></dir></dir></dir>";
			XML_Parser xml(testXML2);

			Tree<string>* root = nullptr;
			xml.CreateTree(root);

			Assert::AreEqual(6, xml.CountItems(*root));
		}
		TEST_METHOD(testCalcMemory)
		{
			string testXML2 = "<dir><name>super</name><file><name>file1</name><length>1234</length><type>.exe</type></file><file><name>file2</name><length>1222</length><type>.png</type></file><dir><name>gaming</name><file><name>newFIle</name><length>1234</length><type>.exe</type></file><dir><name>empty</name></dir></dir></dir>";
			XML_Parser xml(testXML2);

			Tree<string>* root = nullptr;
			xml.CreateTree(root);

			Assert::AreEqual(3690, xml.CalcMemory(*root));
		}
		TEST_METHOD(testRemoveEmptyFolders)
		{
			string testXML2 = "<dir><name>super</name><file><name>file1</name><length>1234</length><type>.exe</type></file><file><name>file2</name><length>1222</length><type>.png</type></file><dir><name>gaming</name><file><name>newFIle</name><length>1234</length><type>.exe</type></file><dir><name>empty</name></dir></dir></dir>";
			XML_Parser xml(testXML2);

			Tree<string>* root = nullptr;
			xml.CreateTree(root);

			Assert::AreEqual(6, xml.CountItems(*root));
			xml.RemoveEmptyFolders(root);
			Assert::AreEqual(5, xml.CountItems(*root));
		}		
	};
}
