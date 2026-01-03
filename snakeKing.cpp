#include<iostream>
#include<conio.h>
#include<windows.h>

using namespace std;

enum Direction{STOP = 0, LEFT, RIGHT, UP, DOWN};
Direction dir;
bool gameOver;
const int height = 20, width = 20;
int headX, headY, fruitX, fruitY, score;
int tailX[100], tailY[100];
int tail_length;

void setup();
void draw();
void input();
void logic();

int main(){
    char start;
    cout<<"\t---------------------------------"<<endl;
    cout<<"\t\t  :Snake King:"<<endl;
    cout<<"\t---------------------------------"<<endl;
    cout<<"Press 's' to start: ";
    cin>>start;
    if (start == 's')
    {
        setup();
        while (!gameOver)
        {
            draw();
            input();
            logic();
            Sleep(100);
            system("cls");
        }
        
    }
    
}

void setup()
{
    gameOver = false;
    dir = STOP;
    headX = width/2;
    headY = height/2;
    fruitX = rand()%width;
    fruitY = rand()%height;
    score = 0;
}
void draw()
{
    system("cls");
    //Upper Border
    cout<<"\t\t";
    for (int i = 0; i < width-8; i++)
    {
        cout<< "||";
    }
    cout<<endl;

    // Snake, fruit, spaces and side borders

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //left border
            if (j == 0)
            {
                cout<<"\t\t||";
            }
            
            //snake head
            if (j == headX && i == headY)
            {
                cout<<"O";
            }
            
            // fruit
            else if (j == fruitX && i == fruitY)
            {
                cout<<"*";
            }
            
            // snake tail
            else
            {
                bool print = false;
                // tail
                for (int k = 0; k < tail_length; k++)
                {
                    //tail
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        cout<<"o";
                        print = true;
                    }
                    
                }
                // space
                if (!print)
                {
                    cout<<" ";
                }
                
            }
            //right border
            if (j == width-1)
            {
                cout<<"||";
            }
        }
        cout<<endl;
    }
    // Lower Border
    cout << "\t\t";
    for(int i = 0; i < width-8; i++){
        cout << "||";
    }
    cout << endl;
    cout<<"\t\t\tScore: " <<score<<endl;     
}
void input()
{
    if (_kbhit())
    {
        switch (getch())
        {
            case 'a':
                dir = LEFT;
                break;
    
            case 'd':
                dir = RIGHT;
                break;
    
            case 'w':
                dir = UP;
                break;
    
            case 's':
                dir = DOWN;
                break;
    
            default:
                break;
        }
    }
    
}
void logic()
{
    // tail
    int prevX = tailX[0], prevY = tailY[0];
    int prevX2, prevY2;
    tailX[0] = headX;
    tailY[0] = headY;
    for (int i = 1; i < tail_length; i++)
    {
        prevX2 = tailX[i];
        prevY2 = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prevX2;
        prevY = prevY2;
    }

    // direction
    switch (dir)
    {
    case LEFT:
        headX--;
        break;
    
    case RIGHT:
        headX++;
        break;
    
    case UP:
        headY--;
        break;
    
    case DOWN:
        headY++;
        break;
    
    default:
        break;
    }

    // touch walls
    if (headX >= width)
    {
        headX = 0;
    }
    
    if (headX < 0)
    {
        headX = width - 1;
    }
    
    if (headY >= height)
    {
        headY = 0;
    }
    
    if (headY < 0)
    {
        headY = height - 1;
    }
    
    // snake bites itself
    for (int i = 0; i < tail_length; i++)
    {
        if (tailX[i] == headX && tailY[i] == headY)
        {
            gameOver = true;
        }
        
    }
    
    // snake eats fruit

    if (headX == fruitX && headY == fruitY)
    {
        score += 10;
        fruitX = rand()%width;
        fruitY = rand()%height;
        tail_length++;
    }
    

}





















