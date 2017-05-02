# TCGS : Taking Chances on a Galactic Scale

Group: Matthew Dyer, Michael Lee, Sam Wiles, Paige Thomas, Zachary Baldwin, Alexis Martin, and Adugna G Mariam

Open Source font file Xolonium-Regular.ttf found at:
	https://fontlibrary.org/en/font/xolonium#Xolonium-Regular
	
All images are from Wikimedia Commons and are licensed under Creative Commons or Public Domain:
	https://commons.wikimedia.org/

This is the final project for Longwood University's CMSC-461:Senior Seminar class. We were tasked with building a
game over the course of a semester, and this is what we have developed.

Our game is akin to the traditional board game RISK, but it has a bit of a twist. Instead of taking place
on a simple world map, we have a plethora of different planet configurations for players to enjoy. It also
reduces the runtime of a traditional RISK game because it gets rid of the need for repeated dice rolling.
A simple User Manual is featured below.

------------------------------------------------------------------------------------------------

Table of Contents
---------------------------
I.Note from the Development Team
II.Requirements
III.Quick Start
IV.Set up
V.Game Play
VI.Troubleshooting


Section I: Note
---------------------------
Thank you for purchasing the Alpha version of Taking Chances on a Galactic Scale (TCGS). This game is a digital version of the classic game RISK, by Hasbro Games, with some new twists and a highly decreased chance of losing your game pieces. The game is playable on any Unix based based operating system with 2 to 6 players. We hope you look forward to future updates and downloadable content from the CS ‘Я’ US development team.

Section II: Requirements
---------------------------
This game has the following requirements in order to play:
 -Unix Based Operating System
 -Graphics display system (Allegro Compatible)
 -2-6 Players
 -14 Megabytes of Free Space
 -Standard Keyboard
 
Section III: Quick Start
---------------------------
1.Open ‘TCGS’ folder in terminal window
2.Type ‘./run’ to run game
3.Choose number of players and confirm
4.Choose player order
5.Select desired species and confirm
6.Enter desired name
7.Repeat steps 5 and 6 for each player
8.Select Map and confirm
9.Distribute additional units for each player
10.Your game is ready to play!

Section IV: Setup
---------------------------
In order to play the game you will need to request Alpha access by emailing csrus@longwood.edu. You will need to download the attached directory and store it on a Unix based system or it can be stored on a USB flash drive for portability. You may also access the game by making a clone of the git repository located at the following URL: https://github.com/DaedricMD/TCGS
After downloading, open the TCGS directory in a terminal window and install Allegro 5.2.2 on your computer. Once this has been done you can create the run file by going inside the TCGS directory and typing ‘make’. This will create the interface run file and you will only need to do this once per computer.
Then, you will be able to run the game by entering “./run” into the command line. This should start the game and allow you to play, it should also initiate the graphical components and create a second window once game setup is complete. This second screen will display a live map that updates as you play.


Section V: Gameplay
---------------------------
After installation and initial setup this section can be referred to for game play mechanics and general instructions The following is a list of in game commands.
    
-“attack”
   --Attack an opponent's planet using a specified number of units. Can be used once per turn.
-“move” 
   --Move a specified number of units from one of your planets to another.
-“end”
   --Ends the current turn
-“help”
   --Lists commands in game
-“view”
   --Shows a list of planets, their owner, and the number of units currently on placed
-“quit”
   --Closes the game instance
-(Y/N)
   --Case sensitive confirmation 

Commands are entered into the command line in your terminal, however, the planets are displayed graphically in a separate window that will launch upon selecting your map. This map is currently not enabled to control the game and just displays a live version on the game map, but this may be a feature in later patches. Green planets belong to the current player and orange planets belong to the opponent.



Section VI: Troubleshooting
---------------------------
If you run into complications while playing TCGS please reference this troubleshooting guide. Please take note that this is the Alpha release and bugs may pop up from time to time. Bug reports may be submitted to csrus@longwood.edu.

-The most common issue comes from incorrect user input, please be careful to enter commands as given by the prompts
-All commands are case sensitive, please be cautious of your CAPS lock key!
-If you are having trouble during initial unit distribution during setup remember to use this format: <planet>_<units> (“H 4”)
-During gameplay type “help” to see a list of usable commands
-At any point during the game a player can enter the command “quit” in order to exit the game
-For emergency shutdown type ‘CTRL+C’
-Join the CS ‘Я’ US mailing list for news on updates and patches!

