#include "pch.h"
#include "CppUnitTest.h"
#include "../Red-Black tree.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestMap
{
	TEST_CLASS(UnitTestMap)
	{
	public:

		TEST_METHOD(Testinsert)
		{
			RBtree<int, int> testMap;
			testMap.insert(14, 9);
			Assert::IsTrue(testMap.find(14)->value == 9);
			Assert::IsTrue(testMap.find(14)->color == 0);

			testMap.insert(10, 10);
			testMap.insert(19, 4);
			Assert::IsTrue(testMap.find(14)->color == 0);
			Assert::IsTrue(testMap.find(10)->color == 1);
			Assert::IsTrue(testMap.find(19)->color == 1);

			testMap.insert(15, 70);
			Assert::IsTrue(testMap.find(14)->color == 0);
			Assert::IsTrue(testMap.find(10)->color == 0);
			Assert::IsTrue(testMap.find(19)->color == 0);
			Assert::IsTrue(testMap.find(15)->color == 1);

		}

		TEST_METHOD(Testremove)
		{
			RBtree<int, int> testMap;
			testMap.insert(14, 9);
			testMap.insert(10, 10);
			testMap.insert(19, 4);
			try {
				testMap.remove(5);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("There is no element with this key in the map\n", error.what());
			}
			Assert::IsTrue(testMap.find(14)->color == 0);
			Assert::IsTrue(testMap.find(10)->color == 1);
			Assert::IsTrue(testMap.find(19)->color == 1);
			testMap.insert(15, 70);

			try {
				testMap.remove(19);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("There is no element with this key in the map\n", error.what());
			}
			
			Assert::IsTrue(testMap.find(14)->color == 0);
			Assert::IsTrue(testMap.find(10)->color == 0);
			Assert::IsTrue(testMap.find(15)->color == 1);
		}

		TEST_METHOD(Testfind)
		{
			RBtree<int, int> testMap;
			testMap.insert(14, 9);
			testMap.insert(10, 10);
			testMap.insert(19, 4);
			try {
				testMap.find(5);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("There is no element with this key in the map\n", error.what());
			}
			Assert::IsTrue(testMap.find(14)->color == 0);
			Assert::IsTrue(testMap.find(10)->color == 1);
			Assert::IsTrue(testMap.find(19)->color == 1);
			Assert::IsTrue(testMap.find(14)->value == 9);

		}

		TEST_METHOD(Testclear)
		{
			RBtree<int, int> testMap;
			testMap.insert(14, 9);
			testMap.insert(10, 10);
			testMap.insert(19, 4);
			testMap.clear();
			try {
				testMap.find(14);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("There is no element with this key in the map\n", error.what());
			}
			try {
				testMap.find(10);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("There is no element with this key in the map\n", error.what());
			}
			try {
				testMap.find(19);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("There is no element with this key in the map\n", error.what());
			}
			
		}

		TEST_METHOD(Testget_keysExeption)
		{
			RBtree<int, int> testMap;
			try {
				testMap.get_keys();
			}
			catch (const out_of_range error) {
				Assert::AreEqual("Map is empty\n", error.what());
			}	
		}

		TEST_METHOD(Testget_valuesExeption)
		{
			RBtree<int, int> testMap;
			try {
				testMap.get_values();
			}
			catch (const out_of_range error) {
				Assert::AreEqual("Map is empty\n", error.what());
			}
		}
		
		TEST_METHOD(TestprintExeption)
		{
			RBtree<int, int> testMap;
			try {
				testMap.print();
			}
			catch (const out_of_range error) {
				Assert::AreEqual("Map is empty\n", error.what());
			}

		}
	};
}
