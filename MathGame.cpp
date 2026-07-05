#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
enum EnOpType
{
    Add = 1,
    Sub = 2,
    Mul = 3,
    Dev = 4,
    MixType = 5
};
enum EnDifficulty
{
    Easy = 1,
    Mid = 2,
    Hard = 3,
    MixLvl = 4
};
struct StQuestions
{
    EnDifficulty lvl;
    EnDifficulty actualLvl;
    EnOpType type;
    EnOpType actualType;
    int HowManyQuestions = 1;
    int N1 = 0;
    int N2 = 0;
    int Ans = 0;
    int RightAns = 0;
    int WrongAns = 0;
};
string OpType(short NumberType)
{
    string Op[] = {"", "+", "-", "*", "/"};
    return Op[NumberType];
}
string Difficulty(short NumberDifficulty)
{
    string Diff[] = {"", "Easy", "Mid", "Hard", "Mixed"};
    return Diff[NumberDifficulty];
}
int RandomNumber(int From, int To)
{

    int random = rand() % (To - From + 1) + From;
    return random;
}
short ReadHowManyQuestion()
{
    short Question = 0;
    do
    {
        cout << "How Many Question You Want To Play (Enter Positive Number)\n";
        cin >> Question;
    } while (!(Question > 0));
    return Question;
}
int ReadingTheGameRounds()
{
    StQuestions Questions;
    Questions.HowManyQuestions = ReadHowManyQuestion();
    return Questions.HowManyQuestions;
}
EnDifficulty ReadingTheGameLvl()
{
    StQuestions Questions;
    int lvl;
    cout << "Enter Question level [1] Easy, [2] Med, [3] Hard, [4] Mix ?\n";
    cin >> lvl;
    Questions.lvl = EnDifficulty(lvl);
    return Questions.lvl;
}
EnOpType ReadingTheGameType()
{
    StQuestions Questions;
    int type;
    cout << "Enter Question Type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix ?\n";
    cin >> type;
    Questions.type = EnOpType(type);
    return Questions.type;
}
EnDifficulty GetActualDifficulty(StQuestions &Questions)
{
    if (Questions.lvl == EnDifficulty::MixLvl)
    {
        Questions.actualLvl = EnDifficulty(RandomNumber(1, 3));
    }
    else
    {
        Questions.actualLvl = Questions.lvl;
    }
    return Questions.actualLvl;
}
int QuestionsLvls(StQuestions &Questions)
{
    int Number;
    EnDifficulty actualLvl = GetActualDifficulty(Questions);

    if (actualLvl == EnDifficulty::Easy)
    {
        Number = RandomNumber(1, 10);
    }
    else if (actualLvl == EnDifficulty::Mid)
    {
        Number = RandomNumber(11, 50);
    }
    else if (actualLvl == EnDifficulty::Hard)
    {
        Number = RandomNumber(50, 100);
    }

    return Number;
}
EnOpType GetActualOpType(StQuestions &Questions)
{
    if (Questions.type == EnOpType::MixType)
    {
        Questions.actualType = EnOpType(RandomNumber(1, 4));
    }
    else
    {
        Questions.actualType = Questions.type;
    }
    return Questions.actualType;
}
int QuestionType(StQuestions &Questions)
{
    EnOpType actualType = GetActualOpType(Questions);

    if (actualType == EnOpType::Add)
    {
        return Questions.Ans = Questions.N1 + Questions.N2;
    }
    else if (actualType == EnOpType::Sub)
    {

        return Questions.Ans = Questions.N1 - Questions.N2;
    }
    else if (actualType == EnOpType::Mul)
    {
        return Questions.Ans = Questions.N1 * Questions.N2;
    }
    else if (actualType == EnOpType::Dev)
    {
        if (Questions.N2 == 0)
            Questions.N2 = 1;

        return Questions.Ans = Questions.N1 / Questions.N2;
    }
    return Questions.Ans;
}
void GameResult(StQuestions Questions)
{
    cout << "\n\n\n______________________________\n";
    if (Questions.RightAns > Questions.WrongAns)
    {
        system("color 20");
        cout << "\nThe Final Result Is Pass" << endl;
    }

    else
    {
        Beep(750, 300);
        system("color 4F");
        cout << "\nThe Final Result Is Fail" << endl;
    }
    cout << "______________________________\n";
    cout << "The Number Of Question Is : " << Questions.HowManyQuestions << endl;
    cout << "Question level : " << Difficulty(Questions.lvl) << endl;
    cout << "OpType : " << OpType(Questions.actualType) << endl;
    cout << "Number Of Right Answer : " << Questions.RightAns << endl;
    cout << "Number Of Right Wrong : " << Questions.WrongAns << endl;
    cout << "______________________________\n";
}
char GameRestart()
{
    char Restart;
    cout << "Do You Want To Play Again Y/N : ";
    cin >> Restart;
    if (Restart == 'Y' || Restart == 'y')
    {
        system("cls");
        system("color 07");
    }
    return Restart;
}
void MathGame()
{

    char Restart = 'Y';
    do
    {

        StQuestions Questions;
        Questions.HowManyQuestions = ReadingTheGameRounds();
        Questions.lvl = ReadingTheGameLvl();
        Questions.type = ReadingTheGameType();
        for (int i = 1; i <= Questions.HowManyQuestions; i++)
        {

            Questions.N1 = QuestionsLvls(Questions);
            Questions.N2 = QuestionsLvls(Questions);
            Questions.Ans = QuestionType(Questions);
            int PlayerAns = 0;
            cout << "Questions  " << "[" << i << "/" << Questions.HowManyQuestions << "]" << endl;
            cout << Questions.N1 << endl;
            cout << Questions.N2 << " " << OpType(Questions.actualType);
            cout << "\n____________\n";

            cin >> PlayerAns;
            if (PlayerAns == Questions.Ans)
            {
                system("color 20");
                cout << "\nRight Answer :-)\n";
                Questions.RightAns++;
            }
            else
            {
                Beep(750, 300);
                system("color 4F");
                cout << "Wrong Answer :-(\n";
                cout << Questions.Ans << endl;
                Questions.WrongAns++;
            }
        }
        GameResult(Questions);
        Restart = GameRestart();
    } while (Restart == 'Y' || Restart == 'y');
}
int main()
{
    srand((unsigned)time(NULL));
    MathGame();
}
