#include <iostream>
#include <fstream>
#include <cstdlib>
#include <termios.h>
#include <cstdio>

using namespace std;

static struct termios old, newa;

/* Initialize new terminal i/o settings */
void initTermios(int echo) 
{
  tcgetattr(0, &old); /* grab old terminal i/o settings */
  newa = old; /* make new settings same as old settings */
  newa.c_lflag &= ~ICANON; /* disable buffered i/o */
  if (echo) {
      newa.c_lflag |= ECHO; /* set echo mode */
  } else {
      newa.c_lflag &= ~ECHO; /* set no echo mode */
  }
  tcsetattr(0, TCSANOW, &newa); /* use these new terminal i/o settings now */
}

/* Restore old terminal i/o settings */
void resetTermios(void) 
{
  tcsetattr(0, TCSANOW, &old);
}

/* Read 1 character - echo defines echo mode */
char getch_(int echo) 
{
  char ch;
  initTermios(echo);
  ch = getchar();
  resetTermios();
  return ch;
}

/* Read 1 character without echo */
char getch(void) 
{
  return getch_(0);
}

void write(string pathFile) {
	ifstream file;
	file.open(pathFile.c_str());
	string text, t;
	while(file >> t) {
		text += t + ' ';
	}
	cout << text;
	while(1) {
		text += getch();
		system("clear");
		cout << text << endl;
	}
}