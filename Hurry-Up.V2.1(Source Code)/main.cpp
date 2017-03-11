#include <stdio.h>
#include <iostream>
#include <graphics.h>
#include <string.h>
#include <math.h>
#include <windows.h>
#include <dos.h>
#include <time.h>
#include "game.h"
#include "startgrap.h"
using namespace std;

int main( )
{ 
    sstartScreenFunc();
      
    while( !kbhit() )
    delay(500);
    
	//closegraph(startscreen);
    
	return( 0 );
}
