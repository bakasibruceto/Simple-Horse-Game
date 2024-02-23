/************************************************************


This update enhances the game experience such as
renewing the game UI, adding form of mechanics;

- Sprint Algorithm where guesses in random number
return specific sprint value for horses

- Shuffle the sequence in array after one loop



@July 18, 2023
@Rokhai

***************************************************************/


#include <iostream>
#include <conio.h>
#include <windows.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

// colors
enum Color {
    BLACK = 0,
    DARKBLUE = FOREGROUND_BLUE,
    DARKGREEN = FOREGROUND_GREEN,
    DARKCYAN = FOREGROUND_GREEN | FOREGROUND_BLUE,
    DARKRED = FOREGROUND_RED,
    DARKMAGENTA = FOREGROUND_RED | FOREGROUND_BLUE,
    DARKYELLOW = FOREGROUND_RED | FOREGROUND_GREEN,
    DARKGRAY = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
    GRAY = FOREGROUND_INTENSITY,
    BLUE = FOREGROUND_INTENSITY | FOREGROUND_BLUE,
    GREEN = FOREGROUND_INTENSITY | FOREGROUND_GREEN,
    CYAN = FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE,
    RED = FOREGROUND_INTENSITY | FOREGROUND_RED,
    MAGENTA = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE,
    YELLOW = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN,
    WHITE = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
    BACKDARKBLUE = BACKGROUND_BLUE,
    BACKDARKGREEN = BACKGROUND_GREEN,
    BACKDARKCYAN = BACKGROUND_GREEN | BACKGROUND_BLUE,
    BACKDARKRED = BACKGROUND_RED,
    BACKDARKMAGENTA = BACKGROUND_RED | BACKGROUND_BLUE,
    BACKDARKYELLOW = BACKGROUND_RED | BACKGROUND_GREEN,
    BACKDARKGRAY = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE,
    BACKGRAY = BACKGROUND_INTENSITY,
    BACKBLUE = BACKGROUND_INTENSITY | BACKGROUND_BLUE,
    BACKGREEN = BACKGROUND_INTENSITY | BACKGROUND_GREEN,
    BACKCYAN = BACKGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_BLUE,
    BACKRED = BACKGROUND_INTENSITY | BACKGROUND_RED,
    BACKMAGENTA = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_BLUE,
    BACKYELLOW = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN,
    BACKWHITE = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE,
    CYANMAGENTA = CYAN | BACKMAGENTA
};



// Function Declaration
void ShowCursor(bool visible);
void SetPosition(int x, int y);
void SetColor(int ForgC);
void SetWindowSize(int width, int height);
void Refresh();
void cPrint();
void sPrint();
void cColoredPrint(char c, int x, int y, Color color);
void sColoredPrint(char* s, int x, int y, Color color);

void drawRect(int x, int y, int width, int height);

void Setup(int width, int height);
void Update();
void Play();

// Universal entity	
class Entity {

        Color color;
        char c;
        int x;
        int y;

    public:

        Entity(Color color, char c, int x, int y){
            this->color = color;
            this->c = c;
            this->x = x;
            this->y = y;
        }

		void setX(int x) {
			this->x = x;
		
		}
		
		void setY(int y) {
			this->y = y;
		}
		
		void setColor(Color color) {
			this->color = color;
		}

		int getX() {
			return this->x;
		}
		
		int getY() {
			return this->y;
		}
		
		char getC() {
			return this->c;
		}
		
		Color getColor() {
			return this->color;
		}
		
		void me(int numberToGuess) {
			
			int result = 0;
			
			int guess = rand() % this->x + 1;
			// identify the sprint will take
			if (guess == numberToGuess) result = 5;
			else if ((guess % numberToGuess) == 0) result = 3;
			else result = 2;
			
			cColoredPrint(this->c, this->x, this->y, this->color);
			for (int i = 0; i < result; i++) {		
					cColoredPrint('-', this->x, this->y, this->color);
				this->setX(this->getX() - 1);
				
			
			}
			
			// delay execution
			for (int i = 1000000 * numberToGuess; i > 0; i--) ;
		}
      
};


void createRunway(int x, int y, int width, int height = 2) {
	// Runways
	drawRect(x, y, width, height);
	
}

int main() {
	
	srand(time(NULL));
	// window terminal size
	SetWindowSize(140, 40);
	
	// Game Variables
    bool isGame = true;
	
	int runwayPosX = 10;
	int runwayPosY = 5;
	int runwayWidth = runwayPosX * 10;

	int totalHorses = 5;
	char horsesName[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
	Color colorHorses[9] = {RED, GREEN, BLUE, YELLOW, CYAN, MAGENTA, DARKYELLOW, DARKRED, DARKCYAN};
	
	Entity horses[totalHorses] = Entity(WHITE, '@', 0, 0);
	ShowCursor(false);
	
	// Title
	sColoredPrint("- Horse Race -", runwayWidth/2, runwayPosY, WHITE);
		
	// Horse runway 
	for (int i = 1; i <= totalHorses; i++) {
		// Label
		cColoredPrint(horsesName[i-1], runwayPosX-1, runwayPosY+(i*2)+1, colorHorses[i-1]);
		// Runway
		createRunway(runwayPosX, runwayPosY+(i*2), runwayWidth);
	}
	
	//Horse Object init
	for (int i = 0; i < totalHorses; i++) {
		horses[i].setColor(colorHorses[i]);
		horses[i].setX(runwayWidth+9);
		horses[i].setY(runwayPosY+(i*2)+3);
	}
    
//    isGame=false;

    // Race Loop
    while (isGame) {
    	int numberToGuess;
    	int sprint;
    	
    	
    	
    	for (int i = 0; i < totalHorses; i++) {
    		
    		// Number to guess in every horse objects
			int numberToGuess = rand() % horses[i].getX() + 1;
			horses[i].me(numberToGuess);
			
			// display the current location of a horse
	    	cColoredPrint('@', horses[i].getX(), horses[i].getY(), horses[i].getColor());
	    
	    	// If horse landed or crossed in the finish line
	    	// game loop will terminate
			if (horses[i].getX() <= runwayPosX) {
				
	    		isGame = false;
	    		sColoredPrint("Horse @  Won!", (runwayWidth/2) + 2, 20, horses[i].getColor());
	    		break;
	    		    
			} 
		}
		
		// randomize the sequence of turns
		for (int i = 0; i < totalHorses; i++) {
			int r = rand() % totalHorses;
			// swap the horses in array
			swap(horses[i], horses[r]);
		}
	}

	// Pause before continuing
	sColoredPrint("Press enter to play again...", (runwayWidth/2)-5, 23, WHITE);
	char choice = getch();
	Refresh();
	
	// if enter button clicked
	// this will call main again
	if (choice == '\r')
	 	main();
	
	// terminate the program
	exit(true);
}


void ShowCursor(bool visible) {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.bVisible = visible;
    SetConsoleCursorInfo(consoleHandle, &info);
}

void SetPosition(int x, int y) {
    HANDLE Screen;
    Screen = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(Screen, coordinates);
}

void SetColor(int ForgC) {
    WORD wColor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(hStdOut, &csbi)) {
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
}

void SetWindowSize(int width, int height) {
	COORD coord = {width, height};
	SMALL_RECT rmin = {0,0,1,1};
	SMALL_RECT rect = {0,0,width-1, height-1};
	
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleWindowInfo(handle, true, &rmin);
	SetConsoleScreenBufferSize(handle, coord);
	SetConsoleWindowInfo(handle, true, &rect);
}

void cColoredPrint(char c, int x, int y, Color color) {
	SetColor(color);
	SetPosition(x,y);
	cout << c;
	SetColor(WHITE);
}

void sColoredPrint(char* s, int x, int y, Color color) {
	SetColor(color);
	SetPosition(x,y);
	cout << s;
	SetColor(WHITE);
}


void drawRect(int x, int y, int width, int height) {
	
	// Vertical
    for (int i = 0; i < height; i++) {
    	cColoredPrint('#', x, y+i, WHITE); // left line
    	cColoredPrint('#', x+width, y+i, WHITE); // right line
	}
	
	// Horizontal
    for (int i = 0; i < width; i++) {
        cColoredPrint('#', x+i, y, WHITE); // top line
        cColoredPrint('#', x+i, y+height, WHITE); // bottom line
        
    }
    
    // last corner
	cColoredPrint('#', x+width, y+height, WHITE);
    
}

void Refresh() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
