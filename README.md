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
