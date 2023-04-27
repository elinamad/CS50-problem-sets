#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    //loop through all of the candidates
    for (int i = 0; i < candidate_count; i++)
    {
        //if the name inputed by voter matches any of the candidates
        if (strcmp(candidates[i].name, name) == 0 )
        {
            //add the voter to the global array
            preferences[voter][rank] = i;
            return true;

        }
    }
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    //loop through all voters
    for (int i = 0; i < voter_count; i++)
    {
        //loop through candidates
        for (int j = 0; j < candidate_count; j++)
        {
            //if candidate is not eliminated yet
            if (candidates[preferences[i][j]].eliminated == false)
            {
                //add a vote
                candidates[preferences[i][j]].votes++;
                break;
            }


        }
    }
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    //loop through candidates
    for (int i = 0; i < candidate_count; i++)
    {
        //if any candidate has a vote count higher than half of total votes the candidate wins
        if (candidates[i].votes > voter_count / 2)
        {
            //print the winner
            printf("the winner is %s\n", candidates[i].name);
            return true;
        }

    }
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    //set the base minimum as the highest possible votes
    int min = voter_count;
    //loop through candidates
    for (int i = 0; i < candidate_count; i++)
    {
        //if candidate is not eliminated
        if (candidates[i].eliminated == false)
        {
            //if candidates votes is less than the current minimum
            if (candidates[i].votes < min)
            {
                //update the minimum
                min = candidates[i].votes;
            }
        }
    }
    //return the minimum value
    return min;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{

    int remaining = 0;
    int count = 0;
//loop through the candidates
    for (int i = 0; i < candidate_count; i++)
    {
        //count the candidates not yet eliminated
        if (candidates[i].eliminated == false)
        {

            remaining++;
        }
        //count candidates with a vote thats equal to minimum
        if (candidates[i].votes == min)
        {
            count++;
        }
    }

    //compare the remaining candidates and the number of candidates with minimum vote, if equal, it means it is a tie.
    if (remaining == count)
    {
        return true;
    }

    return false;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    //loop through candidates and eliminate those who have min amount of votes
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }
    return;
}