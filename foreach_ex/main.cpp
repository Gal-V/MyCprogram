#include <iostream>

int main()
{
    const int numStudents = 7;
    int studentScores[numStudents] = { 45, 88, 55, 66, 10};
    int maxScore(0);
    for (auto &score : studentScores)
    {
        if (score > maxScore)
        {
            maxScore = score;
        }
    }
    std::cout << "Best = " << maxScore << std::endl;

    return 0;
}