#include "stdafx.h"

#include "CSVInputFileReader.h"
#include "InputFileReaderCallback.h"
#include <fstream>
#include <vector>
#include <string>

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace	Microsoft::VisualStudio::TestTools::UnitTesting;

namespace gradescorestest
{
	class ReaderCallbackHandler : public InputFileReaderCallback
	{
	public:
		ReaderCallbackHandler() : b_BOFFired(false), b_EOFFired(false) {}

		void OnBOF(std::string _sFile)
		{
			vec_Tokens.clear();
			vec_RowData.clear();
			b_BOFFired = true;
		}
		
		void OnEOF(std::string _sFile)
		{
			b_EOFFired = true;
		}

		void OnRowStart(int _iRowNumber, const std::string & _sRowData)
		{
			vec_RowData.push_back(_sRowData);
			vec_Tokens.push_back(std::vector<std::pair<int, std::string> >());
		}

		void OnRowEnd(int _iRowNumber)
		{

		}

		void OnNewToken(int _iRowNumber, int _iTokenIndex, const std::string & _sTokenData)
		{
			vec_Tokens[_iRowNumber].push_back(std::make_pair(_iTokenIndex, _sTokenData));
		}

		std::vector<std::vector<std::pair<int,std::string> > > vec_Tokens;
		std::vector<std::string> vec_RowData;
		bool b_BOFFired;
		bool b_EOFFired;
	};

	[TestClass]
	public ref class UnitTestCSVInputFileReader
	{
	private:
		TestContext^ testContextInstance;
		CSVInputFileReader * p_CsvFileReader;

	public: 
		/// <summary>
		///Gets or sets the test context which provides
		///information about and functionality for the current test run.
		///</summary>
		property Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ TestContext
		{
			Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ get()
			{
				return testContextInstance;
			}
			System::Void set(Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ value)
			{
				testContextInstance = value;
			}
		};

		[ClassInitialize()]
		static void MyClassInitialize(Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ testContext) 
		{
			// create CSV file in CWD
			std::ofstream ofsOut("test_data.txt");
			if(ofsOut.is_open())
			{
				ofsOut << "TED, BUNDY, 88" << std::endl;
				ofsOut << "ALLAN, SMITH , 85" << std::endl;
				ofsOut << "MADISON , KING, 83" << std::endl;
				ofsOut << "FRANCIS, SMITH, 85" << std::endl;
				ofsOut << "ALLAN, JHON, 85" << std::endl;

				ofsOut.flush();
				ofsOut.close();
			}
		}

		[ClassCleanup()]
		static void MyClassCleanup() 
		{
			remove("test_data.txt");
		}

		[TestInitialize()]
		void TestCSVInputFileReaderSetup() 
		{
			p_CsvFileReader = new CSVInputFileReader("test_data.txt");
		}

		[TestCleanup()]
		void TestCSVInputFileReaderCleanup() 
		{
			if(p_CsvFileReader)
				delete p_CsvFileReader;
		}

		[TestMethod]
		void TestCallbacks()
		{
			ReaderCallbackHandler * pCallbackHandler = new ReaderCallbackHandler();
			p_CsvFileReader->ReadFile(pCallbackHandler);

			Assert::IsTrue(pCallbackHandler->b_BOFFired, "BOF Fired");
			Assert::IsTrue(pCallbackHandler->b_EOFFired, "EOF Fired");

			Assert::AreEqual<int>(pCallbackHandler->vec_RowData.size(), 5, "OnRowStart check");
			Assert::AreEqual<int>(pCallbackHandler->vec_Tokens.size(), 5, "OnRowStart check");
			
			Assert::AreEqual<int>(pCallbackHandler->vec_Tokens[0].size(), 3, "Column count check");
			Assert::AreEqual<int>(pCallbackHandler->vec_Tokens[3].size(), 3, "Column count check");
			Assert::AreEqual<int>(pCallbackHandler->vec_Tokens[4].size(), 3, "Column count check");
			
			Assert::AreEqual<int>(pCallbackHandler->vec_Tokens[0][0].first, 0, "Token data position check");
			Assert::AreEqual<int>(pCallbackHandler->vec_Tokens[3][2].first, 2, "Token data position check");
			Assert::AreEqual<int>(pCallbackHandler->vec_Tokens[2][1].first, 1, "Token data position check");
			Assert::AreEqual<int>(pCallbackHandler->vec_Tokens[4][0].first, 0, "Token data position check");

			Assert::IsTrue(pCallbackHandler->vec_Tokens[0][0].second.compare("TED") == 0, "Token data value check");
			Assert::IsTrue(pCallbackHandler->vec_Tokens[3][2].second.compare("85") == 0, "Token data value check");
			Assert::IsTrue(pCallbackHandler->vec_Tokens[2][1].second.compare("KING") == 0, "Token data value check");
			Assert::IsTrue(pCallbackHandler->vec_Tokens[4][0].second.compare("ALLAN") == 0, "Token data value check");
		};
	};
}
