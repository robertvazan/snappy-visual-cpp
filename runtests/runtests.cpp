// runtests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

extern "C" int snappy_unittests(int argc, char** argv);

int main(int argc, char* argv[])
{
	return snappy_unittests(argc, argv);
}

