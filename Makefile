gameLoop:
	g++ gameLoop.cpp gameLoopTest.cpp Library/player.cpp Library/Planet.cpp Library/army.cpp battle.cpp -g -o loopTest

interface:
	g++ gameLoop.cpp Library/player.cpp Library/Planet.cpp Library/army.cpp battle.cpp Interface.cpp -g -o interfaceTest
