#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(char word[]);

int main(void)
{
    // Get input words from both players
    char word1[30];
    char word2[30];
    printf("Player 1: ");
    scanf("%s", word1);
    printf("Player 2: ");
    scanf("%s", word2);
    
    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
    	printf("Player 1 wins!\n");
    }
    else if ( score2 > score1)
    {
    	printf("Player 2 wins!\n");
    }
    else
    {
    	printf("Tie!\n");
    }
    
    return 0;
}

int compute_score(char word[])
{
    // TODO: Compute and return score for string
    int score = 0;
    char c;
    
    for (int i = 0,l = strlen(word); i < l; i++)
    {
    	c = tolower(word[i]);
    	// if c is not a small letter from a-z continue
    	if ( c < 97 || c > 122)
    	{
    		continue;
    	}
    	// else add the assined value to the score
    	score += POINTS[c%97];
    }
    
    return score;
}
