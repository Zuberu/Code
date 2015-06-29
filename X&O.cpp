#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

struct XO
{
    short field[3][3];
    short W, x, y;

    void Prep()
    {
        W=0;
        for(int i=0; i<3; i++)
            for(int j=0; j<3; j++)
                field[i][j] = 0;
    }

    void InFieldP()
    {
        cout << "Enter your mark on axis (x y): ";
        cin >> x >> y;
        x--;
        y--;

        while(x < 0 || x > 2)
        {
            cout << "You have entered the wrong value of x! Enter again (1-3): ";
            cin >> x;
            x--;
        }

        while(y < 0 || y > 2)
        {
            cout << "You have entered the wrong value of y! Enter again (1-3): ";
            cin >> y;
            y--;
        }

        if(field[x][y] != 0)
        {
            cout << "This area is already filled! Try again!\n";
            InFieldP();
        }


        field[x][y] = 1;
    }

    void InFieldAI()
    {
        x = rand() % (2 + 1 - 0) + 0;
        y = rand() % (2 + 1 - 0) + 0;

        while(field[x][y] != 0)
        {
            x = rand() % (2 + 1 - 0) + 0;
            y = rand() % (2 + 1 - 0) + 0;
        }

        field[x][y] = 2;
    }

    void OutField()
    {
        system("cls");
        cout << "X and O\n\n";

        cout << "  1 2 3"  << endl;
        cout << " +-+-+-+"  << endl;
        for(int i=0; i<3; i++)
        {
            cout << i+1 << '|';
            for(int j=0; j<3; j++)
            {
                switch(field[i][j])
                {
                    case 0:
                        cout << ' ' << '|';
                        break;
                    case 1:
                        cout << 'X' << '|';
                        break;
                    case 2:
                        cout << 'O' << '|';
                        break;
                    case 3:
                        cout << '*' << '|';
                        break;
                    default:
                        cout << field[i][j] << '|';
                        break;
                }
            }
            cout << "\n +-+-+-+"  << endl;
        }
        cout << endl;
    }

    void FieldCheck()
    {
        for(int i=0; i<3; i++)
            if(field[i][0] !=0 && field[i][0] == field[i][1] && field[i][1] == field[i][2])
            {
                W = field[i][i];
                field[i][0] = 3;
                field[i][1] = 3;
                field[i][2] = 3;
                break;
            }

        for(int i=0; i<3; i++)
            if(field[0][i] !=0 && field[0][i] == field[1][i] && field[1][i] == field[2][i])
            {
                W = field[i][i];
                field[0][i] = 3;
                field[1][i] = 3;
                field[2][i] = 3;
                break;
            }
    }

    void TheWinner()
    {
        switch(W)
        {
            case 1:
                cout << "THE WINNER IS HUMAN!" << endl;
                break;
            case 2:
                cout << "THE WINNER IS COMPUTER!" << endl;
                break;
        }
    }
};

int main()
{
    srand(time(NULL));
    XO Game;

    Game.Prep();
    while(Game.W == false)
    {
        Game.OutField();
        Game.InFieldP();
        Game.InFieldAI();
        Game.FieldCheck();
    }

    Game.OutField();
    Game.TheWinner();

    system("pause");
    return 0;
}
