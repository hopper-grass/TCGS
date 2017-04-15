interface:
	g++ gameLoop.cpp Library/player.cpp Library/Planet.cpp Library/army.cpp battle.cpp Interface.cpp -g -lallegro -lallegro_primitives -lallegro_font -lallegro_ttf -lallegro_image -o interfaceTest

gameLoop:
	g++ gameLoop.cpp gameLoopTest.cpp Library/player.cpp Library/Planet.cpp Library/army.cpp battle.cpp -g -o loopTest

clean:
	rm interfaceTest 
	rm loopTest
