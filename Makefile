interface:
	g++ gameLoop.cpp Library/player.cpp Library/Planet.cpp Library/army.cpp battle.cpp Interface.cpp -g -lallegro -lallegro_primitives -lallegro_font -lallegro_ttf -lallegro_image -lpthread -o run

safe::
	g++ mySafeLoop.cpp Library/player.cpp Library/Planet.cpp Library/army.cpp battle.cpp Interface.cpp -g -lallegro -lallegro_primitives -lallegro_font -lallegro_ttf -lallegro_image -lpthread -o run
gameLoop:
	g++ gameLoop.cpp gameLoopTest.cpp Library/player.cpp Library/Planet.cpp Library/army.cpp battle.cpp -lpthread -g -o loopTest

clean:
	rm run
	rm interfaceTest 
	rm loopTest
