#include <graphics.h>
#include "functions.h"      // include some functions
#include <iostream>
using namespace std;

int main()
{
     cout<<"\n\n\n\n\n\n\n\n\n\n\tTIC-TAC-TOE GAME BY HARSHIT SHARMA\n\n\n\n\n";
     DWORD Width = GetSystemMetrics(SM_CXSCREEN);
     DWORD Height = GetSystemMetrics(SM_CYSCREEN);
     initwindow (Width , Height , "TIC-TAC-TOE" , -2 , -3);

     LOADING();

     cleardevice();
     readimagefile("res/FRONT.jpg",150,50,1100,600);
     delay(4000);

     MENU();

     return EXIT_SUCCESS;
}
