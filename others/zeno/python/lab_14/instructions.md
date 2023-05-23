Lab 14
======

Basic String Operations
-----------------------

**Objective:** To write two+ functions while learning some basic things about strings.

**Assignment:** You are challenged with writing two distinct features. One will count the number of spaces in a semtence, the second will detect double letters in a word, then as an extra if you choose, you will simulate a basic form of compression.

**Functions to Write:**

-   `spaces(sentence)`: Sentences use spaces to separate words. For example, the previous sentence has 5 spaces in it, that occur at the following index locations: 9, 13, 20, 23 and 32.

Write a function that takes a string argument and iterates through it. While iterating it should output (print) the index of each space as you encounter it, and keep count of the total number of spaces to return when the function ends. Your function should then RETURN the total number of spaces only.

-   `double_letter(word)`: Some words have adjacent repeating letters. For example, the word "tomorrow" has a double 'r'. In comparison, the two u's in the word "future" do not count as double letters because they are not adjacent.

Write a function that takes a string argument `word` and prints the word. Your function should then RETURN "yes" or "no" depending on whether the word contains any double letters. Check the sample run below to see how this should be formatted.

**Bonus:**

`compression(word)`: Geography nerds are unhappy with the time it takes for them to send a map over the network. They need a way to make it faster, and after much research they decided that compression is the solution. You are the lucky person they have chosen to implement it! This form of compression is rather simple, but it is quite effective. The way it works is to find repetitions of characters and then just output the number of repetitions and then the character. The input will be uppercase letters only.

For example, before compression a string of characters would look like "AAAABBBBB" and after compression, it would look like "4A 5B".

Write function compression that takes a string argument and RETURNS a new compressed string.

Sample Run
----------

`

The sentence you entered is: This is where you will write the main components of your program

The spaces are at index(es) [4,7,13,17,22,28,32,37,48,51,56]

There are 11 spaces in that sentence.

The sentence you entered is: It's no use going back to yesterday, because I was a different person then.

The spaces are at index(es) [4,7,11,17,22,25,36,44,46,50,52,62,69]

There are 13 spaces in that sentence.

The word you entered is: testing

Result: no

The word you entered is: programming

Result: yes

The string you entered is: AAABBBBDD3KYAC

Result: 3A 4B 2D 13 1K 1Y 1A 1C

The string you entered is: JJJJJJJJJJJJJJJJJJJJ

Result: 20J

`

**Extra bonus only if you have time** In the 'compression(word)' funtion: have it work when the input is a mix of uppercase and lowercase, but the result should remain upper case only.

**For full credit you must pass the matching tests!**

**Some important notes:**

-   If you're confused about what the function should print and what it should return, read over the code in the main() function that has been provided for you.

-   Read over the sample run to see how your answer should be formatted. It must pass the test to match the formatting.

-   NO lists or list methods. We have not learned this tool yet. Any code written with a list will be graded as a 0.

-   Remember to check the string methods that we learned in class for methods that might help you.

-   Hint: You will need loops in all of the functions in your answers.