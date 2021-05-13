#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
void check_cycle(int winner, int loser, bool *creates_cycle);
bool is_winner(int test);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
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
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // find candidate's index in candidate string
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i], name) == 0)
        {
            // add index to rank array in rank position
            ranks[rank] = i;
            return true;
        }
    }

    // If ranks is not successfully updated, return false
    return false;
}


// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // loop through ranks
    for (int i = 0; i < candidate_count - 1; i++)
    {
        // add one to preferences[i][j] for all votes where i beats j
        for (int j = i + 1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]]++;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // Loop through all possible pairs to determine if one candidate is preferred over another
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            // check which candidate people preferred over the other
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
            }
            if (preferences[j][i] > preferences[i][j])
            {
                pairs[pair_count].winner = j;
                pairs[pair_count].loser = i;
                pair_count++;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // Keep track of whether any swaps were necessary to determine when to finish sorting
    bool made_swap;
    do
    {
        // initialize made_swap to false
        made_swap = false;

        // Loop through pairs
        for (int i = 0; i < pair_count - 1; i++)
        {
            // Choose two pairs and store their values in case swap is necessary
            pair pair1 = pairs[i];
            pair pair2 = pairs[i + 1];

            // Store margin of victory for each pair
            int pair1_margin = preferences[pair1.winner][pair1.loser];
            int pair2_margin = preferences[pair2.winner][pair2.loser];

            // Compare the two pairs' margin of victory
            if (pair1_margin < pair2_margin)
            {
                // Swap pairs if lower value comes first
                pairs[i] = pair2;
                pairs[i + 1] = pair1;

                // Set made_swap to true so function will continue to run
                made_swap = true;
            }
        }
    }
    while (made_swap == true);

    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    bool creates_cycle;
    // Loop through the pairs of winners and losers
    for (int i = 0; i < pair_count; i++)
    {
        // Store the values of winners and losers of pair
        int winner = pairs[i].winner;
        int loser = pairs[i].loser;

        // Check to see if it creates a cycle
        creates_cycle = false;
        // Pass reference of creates_cycle, not copy (&creates_cycle)
        check_cycle(winner, loser, &creates_cycle);

        // If it doesn't create a cycle, lock the pair
        if (creates_cycle == false)
        {
            locked[winner][loser] = true;
        }
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    for (int i = 0; i < pair_count; i++)
    {
        //check if i is the winner
        if (is_winner(i))
        {
            // Print the name of the winner
            printf("%s\n", candidates[i]);
        }

    }
    return;
}


// Check to see if locking pair creates cycle
// * passes by reference instead of creating a copy
void check_cycle(int winner, int loser, bool *creates_cycle)
{
    // Loop through candidates to see if loser beat anyone else
    for (int i = 0; i < pair_count; i++)
    {
        // Check to see if loser beat anyone
        if (locked[loser][i])
        {
            // If you encounter winner along path, this means it created a loop
            if (i == winner)
            {
                *creates_cycle = true;
                return;
            }
            else
            {
                check_cycle(winner, i, creates_cycle);
            }
        }
    }

    // If all candidates are checked and no cycle is created, return false
    return;
}

bool is_winner(int test)
{
    for (int j = 0; j < pair_count; j++)
    {
        // Check if any values in column are locked; if so, i is not the winner
        if (locked[j][test])
        {
            return false;
        }
    }
    return true;
}