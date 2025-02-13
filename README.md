# Threads-Project


There are 3 files in the repo that each work with threads differently.

osproj3a.c is the first part of this project. The objective was to create a timer that recorded the amount of time it took the program
to calculate pi given a number of random sample points in a square and while also given the amount of worker threads. The output is then 
outputed to a CSV file. **NOTE** osproj3a.c must be ran with parameters (int sample points, int thread_count)

osproj3b.cpp is the second part of this project. This program is fairly simple. It takes an input from the user that decides how many numbers of the fibonacci sequence will be generated. The program then creates a worker thread that will generate the sequence.

vowcons.cpp is the third and final part of this project. This program is designed to sort out words that start with vowels and words that start with constenants. What makes this program special is that it uses a thread to generate the vowels and a separate thread to generate constenants while keeping the spelling and the order of the words the same. This is accomplished by using mutex to establish exclusivity to the data that is being accessed by the threads and by using a global index so that both threads are able to keep track of the words together. Since they are running different functions on the same data at the same time, the functions needed to be able to use the same index.

The CSV file is my output from osproj3a.c

