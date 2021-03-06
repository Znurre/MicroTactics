#include <QTest>

#include "PlayerTests.h"
#include "KeyInputHandlerTests.h"
#include "PlayerTurnHandlerTests.h"
#include "PlayerHandlerTests.h"

template<class T>
void runTest()
{
	T test;

	QTest::qExec(&test);
}

int main()
{
	runTest<PlayerTests>();
	runTest<KeyInputHandlerTests>();
	runTest<PlayerTurnHandlerTests>();
	runTest<PlayerHandlerTests>();
}
