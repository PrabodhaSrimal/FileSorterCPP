// grade-scores.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Application.h"

int main(int argc, char * argv[])
{
	if(argc != 2)
	{
		DEBUG_LOG << "Usage: grade-scores <input-file-name>";
		return -1;
	}

	Application mApp(argv[1]);
	mApp.Run();

	return 0;
}

