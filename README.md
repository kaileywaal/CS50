# CS50

My solutions to the problem sets for [Harvard's CS50 course](https://www.edx.org/course/introduction-computer-science-harvardx-cs50x).

## Week 1: C

### Mario

Inspired by old Super Mario games, the first problem challenged us to recreate adjacent pyramids of bricks using hashes. It takes a height input from the user and outputs two pyramids of bricks at that height.

Below is an example of how the code works if the user inputs 8.

```
$ ./mario
Height: 8
       #  #
      ##  ##
     ###  ###
    ####  ####
   #####  #####
  ######  ######
 #######  #######
########  ########
```

### Cash

This problem asked a simple question: how many coins are required to make change for a given input? It takes an float input from the user, then uses a greedy algorithm to calculate and print how many coins the user would recieve in change.

```
$ ./cash
Change owed: 0.41
4
```

## Week 2: Arrays

### Readability

Readability is an app that calculates the reading level of an input text based on the Coleman-Liau index.

```
$ ./readability
Text: As the average number of letters and words per sentence increases, the Coleman-Liau index gives the text a higher reading level. If you were to take this paragraph, for instance, which has longer words and sentences than either of the prior two examples, the formula would give the text an eleventh grade reading level.
Grade 11
```

### Substitution

When running substitution, users must provide a key of 26 letters as an input. The program then asks for text, which it encrypts using the encryption key.

```
$ ./substitution VCHPRZGJNTLSKFBDQWAXEUYMOI
plaintext:  hello, world
ciphertext: jrssb, ybwsp
```

## Week 3: Algorithms

### Plurality

This program runs a plurality election, meaning each voter gets one vote and the winner is determined by which candidate receives the most votes.

```
$ ./plurality Alice Bob
Number of voters: 3
Vote: Alice
Vote: Bob
Vote: Alice
Alice
```

### Tideman

This program runs a Tideman election and determines the winner. A Tideman election is a ranked-choice voting system where every voter ranks the candidates in order of preference. The winner is the candidate who would win the most head to head matchups if only two candidates exist.

As explained in the problem set, the Tideman voting method consists of three parts:

1. Tally: Once all of the voters have indicated all of their preferences, determine, for each pair of candidates, who the preferred candidate is and by what margin they are preferred.
2. Sort: Sort the pairs of candidates in decreasing order of strength of victory, where strength of victory is defined to be the number of voters who prefer the preferred candidate.
3. Lock: Starting with the strongest pair, go through the pairs of candidates in order and “lock in” each pair to the candidate graph, so long as locking in that pair does not create a cycle in the graph.

The program runs as follows:

```
./tideman Alice Bob Charlie
Number of voters: 5
Rank 1: Alice
Rank 2: Charlie
Rank 3: Bob

Rank 1: Alice
Rank 2: Charlie
Rank 3: Bob

Rank 1: Bob
Rank 2: Charlie
Rank 3: Alice

Rank 1: Bob
Rank 2: Charlie
Rank 3: Alice

Rank 1: Charlie
Rank 2: Alice
Rank 3: Bob

Charlie
```
