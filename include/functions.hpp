#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void BORDER(int);
void LOADING(void);
void MENU(void);
void CREDITS(void);
void EXIT(void);
void STARTED(void);
int CHECKWIN(void);
void RESET_P(void);

/********************************************************************************************/
struct POS
{
       int a,b,c,d,visibility;
       char sym;
};

POS P[9]={  {450,180,545,275,0,'1'},
            {555,180,645,275,0,'2'},
            {655,180,750,275,0,'3'},
            {450,285,545,375,0,'4'},
            {555,285,645,375,0,'5'},
            {655,285,750,375,0,'6'},
            {450,385,545,480,0,'7'},
            {555,385,645,480,0,'8'},
            {655,385,750,480,0,'9'}  };

/********************************************************************************************/
void RESET_P()
{
     int i;
     char c;
     for (i=0,c='1' ; i<9 ; i++,c++)
     {
         P[i].visibility = 0;
         P[i].sym = c;
     }
}


/********************************************************************************************/
void BORDER(int col)
{
     setcolor(col);
     for (int i=0 ; i<=10 ; i++)
     {
         rectangle(150+i , 50+i , 1100-i , 600-i);
     }
}


/********************************************************************************************/
inline void LOADING()
{
     setbkcolor(WHITE);

     cleardevice();

     BORDER(BLUE);

     setcolor(GREEN);
     settextstyle(BOLD_FONT , HORIZ_DIR , 8);
     outtextxy(350 , 200 , "LOADING ...");

     setcolor(BLACK);
     rectangle(350 , 300 , 850 , 350);
     rectangle(348 , 298 , 852 , 352);
     delay(300);

     setfillstyle(INTERLEAVE_FILL , RED);
     for (int i=0,a=0 ; i<101 ; i++,a+=5)
     {
         bar(352 , 302 , 352+a , 348);
         delay(15);
     }
}


/********************************************************************************************/
void MENU()
{
     POINT cursorPos;
     int mx , my;
     res_menu :
     setbkcolor(WHITE);
     cleardevice();
     readimagefile("res/menu.jpg",150,50,1100,600);
     readimagefile("res/me0.jpg",600,300,850,550);
     RESET_P();
     while(1)
     {
             GetCursorPos(&cursorPos);
             mx=cursorPos.x;
             my=cursorPos.y;
             if (mx>600 && mx<850 && my>300 && my<400)
             {
                             readimagefile("res/me1.jpg",600,300,850,550);
                             if (GetAsyncKeyState(VK_LBUTTON))  { delay(200);  STARTED();  goto res_menu; }
             }

             else if (mx>600 && mx<850 && my>400 && my<525)
             {
                             readimagefile("res/me2.jpg",600,300,850,550);
                             if(GetAsyncKeyState(VK_LBUTTON))  { CREDITS(); goto res_menu; }
             }
             else if (mx>600 && mx<850 && my>525 && my<600)
             {
                             readimagefile("res/me3.jpg",600,300,850,550);
                             if(GetAsyncKeyState(VK_LBUTTON))  { EXIT(); goto res_menu; }
             }
             else
             {
                             readimagefile("res/me0.jpg",600,300,850,550);
                             if(GetAsyncKeyState(VK_LBUTTON)) {}
             }
             delay(10);
     }
}


/********************************************************************************************/
void CREDITS()
{
     int x,y;
     POINT cp;
     cleardevice();
     readimagefile("res/CREDITS.jpg",150,50,1100,600);

     while(1)
     {
             GetCursorPos(&cp);
             x=cp.x;
             y=cp.y;


             if (x>0 && y>0 && x<200 && y<100)
                       {
                         readimagefile("res/back1.jpg",5,5,200,50);
                         if(GetAsyncKeyState(VK_LBUTTON)) break;
                       }
             else
                       { readimagefile("res/back2.jpg",5,5,200,50);
                         if(GetAsyncKeyState(VK_LBUTTON)) {}
                       }

             delay(10);

     }
}


/********************************************************************************************/
void EXIT()
{
     POINT p;
     while(1)
     {
          GetCursorPos(&p);
          readimagefile("res/exit_c.jpg",450,250,800,400);

          if (p.x>450 && p.y>320 && p.x<550 && p.y<400)
          {
                      readimagefile("res/exit_c2.jpg",470,330,780,370);
                      if (GetAsyncKeyState(VK_LBUTTON)) { closegraph(); exit(0); }
          }
          else if (p.x>700 && p.y>320 && p.x<800 && p.y<400)
          {
                      readimagefile("res/exit_c3.jpg",470,330,780,370);
                      if (GetAsyncKeyState(VK_LBUTTON)) { break; }
          }

          else
          {
                      readimagefile("res/exit_c1.jpg",470,330,780,370);
                      if(GetAsyncKeyState(VK_LBUTTON)) {}
          }
          delay(200);

     }
}

/********************************************************************************************/
void STARTED()
{
     POINT cp;
     int x,y,turn=1,i,check;
     cleardevice();
     readimagefile("res/started.jpg",150,70,1100,600);
     readimagefile("res/board.jpg",450,180,750,480);
     while(1)
     {
             GetCursorPos(&cp);
             x=cp.x;
             y=cp.y;
             if (x>0 && y>0 && x<200 && y<100)
                       {
                         readimagefile("res/back1.jpg",5,5,200,50);
                         if(GetAsyncKeyState(VK_LBUTTON)) break;
                       }
             else
                       { readimagefile("res/back2.jpg",5,5,200,50);
                         if(GetAsyncKeyState(VK_LBUTTON)) {}
                       }

             if (x>P[0].a && y>P[0].b && x<P[0].c  && y<P[0].d && P[0].visibility == 0)
                       {
                             if (GetAsyncKeyState(VK_LBUTTON))
                             {
                                                 if (turn==1)  {P[0].sym='x';}
                                                 else          {P[0].sym='o';}
                                                 P[0].visibility = 1;
                                                 turn=(turn%2)?2:1;
                             }
                       }
             else if (x>P[1].a && y>P[1].b && x<P[1].c  && y<P[1].d && P[1].visibility == 0)
                       {
                             if (GetAsyncKeyState(VK_LBUTTON))
                             {
                                                 if (turn==1)  {P[1].sym='x';}
                                                 else          {P[1].sym='o';}
                                                 P[1].visibility = 1;
                                                 turn=(turn%2)?2:1;
                             }
                       }
             else if (x>P[2].a && y>P[2].b && x<P[2].c  && y<P[2].d && P[2].visibility == 0)
                       {
                             if (GetAsyncKeyState(VK_LBUTTON))
                             {
                                                 if (turn==1)  {P[2].sym='x';}
                                                 else          {P[2].sym='o';}
                                                 P[2].visibility = 1;
                                                 turn=(turn%2)?2:1;
                             }
                       }
             else if (x>P[3].a && y>P[3].b && x<P[3].c  && y<P[3].d && P[3].visibility == 0)
                       {
                             if (GetAsyncKeyState(VK_LBUTTON))
                             {
                                                 if (turn==1)  {P[3].sym='x';}
                                                 else          {P[3].sym='o';}
                                                 P[3].visibility = 1;
                                                 turn=(turn%2)?2:1;
                             }
                       }
             else if (x>P[4].a && y>P[4].b && x<P[4].c  && y<P[4].d && P[4].visibility == 0)
                       {
                             if (GetAsyncKeyState(VK_LBUTTON))
                             {
                                                 if (turn==1)  {P[4].sym='x';}
                                                 else          {P[4].sym='o';}
                                                 P[4].visibility = 1;
                                                 turn=(turn%2)?2:1;
                             }
                       }
             else if (x>P[5].a && y>P[5].b && x<P[5].c  && y<P[5].d && P[5].visibility == 0)
                       {
                             if (GetAsyncKeyState(VK_LBUTTON))
                             {
                                                 if (turn==1)  {P[5].sym='x';}
                                                 else          {P[5].sym='o';}
                                                 P[5].visibility = 1;
                                                 turn=(turn%2)?2:1;
                             }
                       }
             else if (x>P[6].a && y>P[6].b && x<P[6].c  && y<P[6].d && P[6].visibility == 0)
                       {
                             if (GetAsyncKeyState(VK_LBUTTON))
                             {
                                                 if (turn==1)  {P[6].sym='x';}
                                                 else          {P[6].sym='o';}
                                                 P[6].visibility = 1;
                                                 turn=(turn%2)?2:1;
                             }
                       }
             else if (x>P[7].a && y>P[7].b && x<P[7].c  && y<P[7].d && P[7].visibility == 0)
                       {
                             if (GetAsyncKeyState(VK_LBUTTON))
                             {
                                                 if (turn==1)  {P[7].sym='x';}
                                                 else          {P[7].sym='o';}
                                                 P[7].visibility = 1;
                                                 turn=(turn%2)?2:1;
                             }
                       }
             else if (x>P[8].a && y>P[8].b && x<P[8].c  && y<P[8].d && P[8].visibility == 0)
                       {
                             if (GetAsyncKeyState(VK_LBUTTON))
                             {
                                                 if (turn==1)  {P[8].sym='x';}
                                                 else          {P[8].sym='o';}
                                                 P[8].visibility = 1;
                                                 turn=(turn%2)?2:1;
                             }
                       }


             for (i=0 ; i<9 ; i++)
             {
                 if (P[i].visibility == 1)
                 {
                       if (P[i].sym == 'x')
                                    readimagefile("res/x.jpg",P[i].a,P[i].b,P[i].c,P[i].d);
                       else
                                    readimagefile("res/o.jpg",P[i].a,P[i].b,P[i].c,P[i].d);
                 }
             }

             check = CHECKWIN();
             if (check == 1)
             {
                       turn=(turn%2)?2:1;
                       if (turn == 1)
                       {
                                setcolor(LIGHTBLUE);
                                settextstyle(COMPLEX_FONT , HORIZ_DIR , 6);
                                outtextxy(300 , 610 , "PLAYER 1 (X) WINS !!");
                                settextstyle(COMPLEX_FONT , HORIZ_DIR , 4);
                                outtextxy(500 , 650 , "PRESS ANY KEY");
                                getch();
                                return;
                       }
                       else
                       {
                                setcolor(LIGHTBLUE);
                                settextstyle(COMPLEX_FONT , HORIZ_DIR , 6);
                                outtextxy(300 , 610 , "PLAYER 2 (O) WINS !!");
                                settextstyle(COMPLEX_FONT , HORIZ_DIR , 4);
                                outtextxy(500 , 650 , "PRESS ANY KEY");
                                getch();
                                return;
                       }
             }
             else if (check == 0)
             {
                                settextstyle(COMPLEX_FONT , HORIZ_DIR , 8);
                                outtextxy(100 , 600 , "GAME DRAW");
                                getch();
                                return;
             }
             delay(50);
     }
}


/********************************************************************************************/
int CHECKWIN()
{
    if (P[0].sym == P[1].sym && P[1].sym == P[2].sym)
       return 1;

    else if (P[3].sym == P[4].sym && P[4].sym == P[5].sym)
       return 1;

    else if (P[6].sym == P[7].sym && P[7].sym == P[8].sym)
       return 1;

    else if (P[0].sym == P[3].sym && P[3].sym == P[6].sym)
       return 1;

    else if (P[1].sym == P[4].sym && P[4].sym == P[7].sym)
       return 1;

    else if (P[2].sym == P[5].sym && P[5].sym == P[8].sym)
       return 1;

    else if (P[0].sym == P[4].sym && P[4].sym == P[8].sym)
       return 1;

    else if (P[2].sym == P[4].sym && P[4].sym == P[6].sym)
       return 1;

    else if (P[0].sym != '1' && P[1].sym != '2' && P[2].sym != '3' && P[3].sym != '4' && P[4].sym != '5'
                       && P[5].sym != '6' && P[6].sym != '7' && P[7].sym != '8'
                                    && P[8].sym != '9')
       return 0;

    else
        return -1;
}


#endif
