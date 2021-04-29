# CS50

My solutions to the problem sets for [Harvard's CS50 course](https://www.edx.org/course/introduction-computer-science-harvardx-cs50x).

## Week 1: C

Week 1 of CS50 focused on learning the basics of C.

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
