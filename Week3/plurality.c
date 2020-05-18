#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }
    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // TODO
    for (int i = 0; i < candidate_count; i++) //loop through candidates name and attribute a vote if a name matches, else return false
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes++;
            return true;
        }

    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // TODO
    int tempVote;
    string tempName;

    for (int i = 0; i < candidate_count; i++)  //first sort the candidates array with bubble sort, but in descending order
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            if (candidates[i].votes < candidates[j].votes)
            {
                tempVote = candidates[j].votes;
                tempName = candidates[j].name;
                candidates[j].name = candidates[i].name;
                candidates[j].votes = candidates[i].votes;
                candidates[i].name = tempName;
                candidates[i].votes = tempVote;
            }
        }
    }

    printf("%s", candidates[0].name); //always print the first name as it has the highest vote count
    for (int i = 0; i < candidate_count - 1; i++)//loop through the array to see if there are more candidates with same vote count as the first one (maximum)
    {
        if (candidates[i].votes == candidates[i + 1].votes) //if there are, print their names on a new line
        {
            printf("\n%s", candidates[i + 1].name);
        }
        else //on the first occurence of lower vote count, print new line and return to stop checking
        {
            printf("\n");
            return;
        }
    }
    printf("\n");
    return;
}


