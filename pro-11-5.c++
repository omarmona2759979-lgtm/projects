#include <iostream>
using namespace std;
enum enPlyingchoice
{
    rock = 1,
    paper = 2,
    scissors = 3
};
enum enWinner
{
    playerwin = 1,
    computerwin = 2,
    nowinner = 3
};
struct stroundinfo
{
    int roundnumber = 0;
    enPlyingchoice playerchoice;

    enPlyingchoice computerchoice;
    enWinner roundwinner;
    string roundwinnername;
};
struct stGameresults
{
    int Gamecount = 0;
    int playerwintimes = 0;
    int computerwintimes = 0;
    int nowinnertimes = 0;
    enWinner gamewinner;
    string gamewinnername;
};
int randomnumber(int from, int to)
{
    int randomnumber = rand() % (to - from + 1) + from;
    return randomnumber;
}

enPlyingchoice computerchoice1()
{
    return (enPlyingchoice)randomnumber(1, 3);
}

enWinner thewinneroftheround(stroundinfo Roundinfo)
{
    if (Roundinfo.playerchoice == Roundinfo.computerchoice)
    {
        return enWinner::nowinner;
    }
    switch (Roundinfo.playerchoice)
    {
    case enPlyingchoice::rock:
        if (Roundinfo.computerchoice == enPlyingchoice::paper)
        {
            return enWinner::computerwin;
        }
        break;
    case enPlyingchoice::paper:
        if (Roundinfo.computerchoice == enPlyingchoice::scissors)
        {
            return enWinner::computerwin;
        }
        break;

    case enPlyingchoice::scissors:
        if (Roundinfo.computerchoice == enPlyingchoice::rock)
        {
            return enWinner::computerwin;
        }
        break;
    }
    return enWinner::playerwin;
}

enWinner thewinnerofthegame(int playerwintimes, int computerwintimes)
{
    if (playerwintimes > computerwintimes)
    {
        return enWinner::playerwin;
    }

    else if (playerwintimes < computerwintimes)
    {
        return enWinner::computerwin;
    }
    else
    {
        return enWinner::nowinner;
    }
}
enPlyingchoice playerchoice1()
{
    int playerchoice2;
    do
    {
        cout << endl
             << "enter your choice: stone(1),paper(2),scissor(3): ";
        cin >> playerchoice2;
    } while (playerchoice2 < 1 || playerchoice2 > 3);

    return (enPlyingchoice)playerchoice2;
}
string choicename(enPlyingchoice choice)
{
    string arr[3] = {"rock", "paper", "scissor"};
    return arr[choice - 1];
}
string WinnerName(enWinner Winner)
{
    string arrWinnerName[3] = {"Player1", "Computer", "No Winner (Draw)"};
    return arrWinnerName[Winner - 1];
}

void PrintRoundResults(stroundinfo RoundInfo)
{
    cout << "\n____________ Round [" << RoundInfo.roundnumber << "] ____________\n\n";
    cout << "Player1 Choice: " << choicename(RoundInfo.playerchoice) << endl;
    cout << "Computer Choice: " << choicename(RoundInfo.computerchoice) << endl;
    cout << "Round Winner   : [" << WinnerName(RoundInfo.roundwinner) << "]\n";
    cout << "_________________________________________\n"
         << endl;
}

stGameresults playGame(int numberofrounds)
{

    cin >> numberofrounds;
    stroundinfo Roundinfo;
    int playerwintimes = 0, computerwintimes = 0, nowinnertimes = 0;

    for (int i = 1; i <= numberofrounds; i++)
    {

        Roundinfo.roundnumber = i;
        Roundinfo.playerchoice = playerchoice1();
        Roundinfo.computerchoice = computerchoice1();

        Roundinfo.roundwinner = thewinneroftheround(Roundinfo);

        if (Roundinfo.roundwinner == enWinner::playerwin)
        {
            playerwintimes++;
        }
        else if (Roundinfo.roundwinner == enWinner::computerwin)
        {
            computerwintimes++;
        }
        else
        {
            nowinnertimes++;
        }
        PrintRoundResults(Roundinfo);
    }
    return {numberofrounds, playerwintimes, computerwintimes, nowinnertimes, thewinnerofthegame(playerwintimes, computerwintimes), WinnerName(thewinnerofthegame(playerwintimes, computerwintimes))};
}

void StartGame()
{
    char PlayAgain = 'Y';

    do
    {
        system("cls");                           // Clear the screen before starting a new game.
        stGameresults GameResults = playGame(3); // Play 3 rounds.
        cout << "\nGame Over! Winner: " << GameResults.gamewinnername << endl;

        cout << "\nDo you want to play again? (Y/N): ";
        cin >> PlayAgain;

    } while (PlayAgain == 'Y' || PlayAgain == 'y');
}

int main()

{
    srand((unsigned)time(NULL)); // Seed the random number generator.
    StartGame();

    return 0;
}
