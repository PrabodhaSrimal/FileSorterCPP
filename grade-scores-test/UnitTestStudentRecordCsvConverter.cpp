#include "stdafx.h"

#include "StudentRecordCsvConverter.h"
#include "Record.h"
#include "StudentRecord.h"
#include <string>

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace	Microsoft::VisualStudio::TestTools::UnitTesting;

namespace gradescorestest
{
	class CustomRecord : public Record
	{
	public:
		CustomRecord() {}

		void Print(std::stringstream & _ssBuf) { _ssBuf << "Test!!!"; }
	};

	[TestClass]
	public ref class UnitTestStudentRecordCsvConverter
	{
	private:
		TestContext^ testContextInstance;

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

		[TestMethod]
		void TestStudentRecordCsvConverter()
		{
			StudentRecordCsvConverter * pConv = new StudentRecordCsvConverter();

			StudentRecord * pStdRec = new StudentRecord();
			pStdRec->SetFirstName("FirstName");
			pStdRec->SetSurname("Surname");
			pStdRec->SetScore(10);

			std::string sRet = pConv->Convert(pStdRec);
			Assert::IsTrue(sRet.compare("Surname,FirstName,10") == 0);

			delete pStdRec;
			delete pConv;
		};
	};
}
