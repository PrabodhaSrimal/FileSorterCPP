#include "stdafx.h"

#include "StudentRecord.h"
#include <string>
#include <sstream>

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace	Microsoft::VisualStudio::TestTools::UnitTesting;

namespace gradescorestest
{
	[TestClass]
	public ref class UnitTestStudentRecord
	{
	private:
		TestContext^ testContextInstance;

		StudentRecord * pStdRec;

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

		[TestInitialize()]
		void TestStudentRecordInitialize() 
		{
			pStdRec = new StudentRecord();
			pStdRec->SetFirstName("FirstName");
			pStdRec->SetSurname("Surname");
			pStdRec->SetScore(10);
		}

		[TestCleanup()]
		void TestStudentRecordCleanup() 
		{
			if(pStdRec)
				delete pStdRec;
		}

		[TestMethod]
		void TestStudentRecordCreation()
		{
			Assert::IsTrue(pStdRec->GetFirstName().compare("FirstName") == 0, "FirstName Getter/Setter");
			Assert::IsTrue(pStdRec->GetSurname().compare("Surname") == 0, "Surname Getter/Setter");
			Assert::IsTrue(pStdRec->GetScore() == 10, "Score Getter/Setter");
		};

		[TestMethod]
		void TestStudentRecordInterface()
		{
			Record * pRec = pStdRec;

			std::stringstream ssRec;
			std::stringstream ssStdRec;
			pRec->Print(ssRec);
			pStdRec->Print(ssStdRec);
			Assert::IsTrue(ssRec.str().compare(ssStdRec.str()) == 0, "Interface match");
		}
	};
}
