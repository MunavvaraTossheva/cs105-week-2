#include <ctype.h>
#include <stdio.h>
int compute_score(const char word[]);
int main(void)
{
    char word1[100];
    char word2[100];

    printf("Player 1: ");
    scanf("%99s", word1);

    printf("Player 2: ");
    scanf("%99s", word2);

    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    if (score1 > score2)
    {
        printf("Player 1 winner!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 winner!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}
int compute_score(const char word[])
{
    const int pints[26] = {
        1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3,
        1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10
    };
    int count = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        if (isalpha(word[i]))
        {
            count += pints[tolower(word[i]) - 'a'];
        }
    }
    return count;
}                                          
