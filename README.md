# Minesweeper Matrix
 
## Introduction

Welcome to the Minesweeper Matrix github repository page! 
This project is one of the assignments I've tackled during my third year at the Faculty of Mathematics and Computer Science, University of Bucharest.
This project is inspired by the classic Minesweeper game that many of us have fond memories of. The idea for this project came about when I remembered how my brother used to play Minesweeper all the time when we were younger. I then knew this was the game I had to do for the assignment.

## Game Description

**Minesweeper Matrix** takes the classic Minesweeper gameplay and adds a new dimension with an 8x8 LED matrix. The objective remains the same: uncover all the safe cells without detonating any mines. The LED matrix enhances the gaming experience, making it more interactive and engaging, as well as more challenging. 


## Instructions on How to Play

1. **Start Screen:**
   - Upon starting the game, you'll be greeted with the main menu displayed on the LCD.
   - Navigate through the menu options using the joystick.

2. **Game Setup:**
   - Select "Play" and then one of the levels to start a new Minesweeper Matrix game.
   - The LED matrix will represent the Minesweeper grid, and mines will be randomly placed.

3. **Gameplay:**
   - Use the joystick to navigate the cursor on the LED matrix.
   - Use the joystick button to click on a cell to uncover it.
   - The impulses indicate the numbers on uncovered cells which provide information on the number of mines in adjacent cells.
   - Use the the auxiliary button to flag any cell you consider to be a mine.
   - If you uncover a mine, the game ends.

4. **Flagging:**
   - This helps you keep track of possible mine locations.

5. **Winning:**
   - Uncover all safe cells or correctly flag all and only the mines in order to win the game.
   - Celebrate your victory. Should it be a new time record, input a name and your score will be saved on the leaderboards, which you then can show off to your friends and family.

6. **Losing:**
   - If you uncover a mine, that's the end of that attempt.
   - Learn from your mistakes and try again!



## Technical Task Breakdown

After booting up, a greeting message is shown for a few moments, before entering the main menu.

### Menu Structure 

1. **Main Menu:**
- ***Play***: opens a level selection screen
- ***Highscore***: opens a level selection screen
- ***Settings***: opens the settings submenu
- ***About***: details about the the game and creator (and also a link to this github account :D)
- ***How to play***: short instruction on what you need to do to win

2. **Play:**
- ***Easy 8x8***: 8x8 map with 4 bombs => 1 in 16 chance to hit a mine
- ***Medium 8x8***: 8x8 map with 8 bombs => 1 in 8 chance to hit a mine
- ***Hard 8x8***: 8x8 map with 10 bombs => 1 in 6.4 chance to hit a mine
- ***Mega 16x16***: 16x16 map with 40 bombs => 1 in 6.4 chance to hit a mine

3. **Highscore:** Highscore leaderboard with a reset option at the end for each specific level
- ***Easy 8x8***
- ***Medium 8x8***
- ***Hard 8x8***
- ***Mega 16x16***

4. **Settings:** Selected options are then saved to EEPROM
- ***LCD Brightness***: opens a selection screen with 10 possible options
- ***Matrix Brightness***: opens a selection screen with 10 possible options
- ***Sound***: ON / OFF options


### Gameplay

After selecting a level to play, the control switched from the LCD menu to the matrix and relevant game information is then displayed on the LCD. 
After the game ends, an end message and the score is displayed on the LCD, before returning to the main menu with user input, or before going though a highscore registration menu sequence that requires the player to input a name, if a new highscore has been achieved.

### Sound

Every valid joystick and button action has a sound associated with it. (Sounds can be turned off from the settings should you be playing this in a quite place like a library)


## Electrical schematic
![Electrical Circuit Schematic](https://github.com/MariusAlexandru358/Minesweeper_Matrix-Project/blob/main/Minesweeper/MinesweeperElectrical.png)

## Hardware setup
![Setup Image](https://github.com/MariusAlexandru358/Minesweeper_Matrix-Project/blob/main/Minesweeper/Minesweeper.jpg)

## Video showcasing functionality
<a href="https://youtu.be/D7fRLBvE8KM" target="_blank">youtube link here</a>

