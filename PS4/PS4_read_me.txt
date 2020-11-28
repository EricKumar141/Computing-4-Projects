/**********************************************************************
 *  readme 
 *  DNA Sequence Alignment
 **********************************************************************/

Name: Eric Kumar

Hours to complete assignment: 4 hours

/**********************************************************************
 * Explain which approach you decided to use when implementing
 * (either recursive with memoization, recursive without memoization,
 * dynamic programming or Hirschberg�s algorithm). Also describe why
 * you chose this approach and what its pros and cons are.
 **********************************************************************/
The method I used for this assigment was with dynamic programming using the Needleman-Wunsch method.
I used this method because for me it was alot easier to implement the edit distance function by filling out a matrix in multiple forloops
instead of using recursion. Dynamic Programming is also more efficiant than recusion becuase I can calculate the sub solutions to edit distance of the
strings before calculating the true solution. Also since I store the sub edit distances on the matrix, my program doesnt have to recaculate the same
edit distances which would be the case if I used recursion. The only cons I can think of to my approach is that the Needleman-Wunsch method needs more space than
if I used the Hirschberg's algorithm for this assignment. (Hirschberg's algorithm uses O(min(m,n) space compared to Needleman-Wunsch needing (O(n*m)) space.



/**********************************************************************
 * Does your code work correctly with the endgaps7.txt test file? 
 * 
 * This example should require you to insert a gap at the beginning
 * of the Y string and the end of the X string.
 **********************************************************************/
Input: atattat tattata

Expected output: 

edit Distance = 4

a - 2
t t 0
a a 0
t t 0
t t 0
a a 0
t t 0
- a 2

What happened: works as intented

edit Distance = 4

a - 2
t t 0
a a 0
t t 0
t t 0
a a 0
t t 0
- a 2

/**********************************************************************
 * Look at your computer�s specs in the settings. 
 * How much RAM does your computer have and explain what this means? 
 **********************************************************************/
I have 16 GB (15.8 GB useable) on my pc. RAM is a short term temporary memory storage that allows programs
that are currently running to rapidly read and change memory as needed to function. deletes the memory when application closes or pc turns off

/**********************************************************************
 *  For this question assume M=N. Look at your code and determine
 *  approximately how much memory it uses in bytes, as a function of 
 *  N. Give an answer of the form a * N^b for some constants a 
 *  and b, where b is an integer. Note chars are 2 bytes long, and 
 *  ints are 4 bytes long.
 *
 *  Provide a brief explanation.
 *
 *  What is the largest N that your program can handle if it is
 *  limited to 8GB (billion bytes) of memory?
 **********************************************************************/
explaination : since string lengths are the same a 2d vector needs 4*n^2 and both strings need 2*n^2 sum = 6n^2 bytes needed
a = 6
b = 2
largest N = 1billion/6*n^2 = largest N = sqrt{50000000/3} bytes

/**********************************************************************
 * Run valgrind if you can and attach the output file to your submission. 
 * If you cannot run it, explain why, and list all errors you�re seeing. 
 * If you can run it successfully, does the memory usage nearly match that 
 * found in the question above? 
 * Explain why or why not. 
/**********************************************************************
from using ecoli5000.txt the memory used is 100.363392 mb = 100363392 b

(file is called ecoli5000.massif.out.7138)

100.363392 = 6n^2 -> n = about 4100

im roughly 80% correct with my aN^b function about for the space my program uses.
/**********************************************************************
 *  For each data file, fill in the edit distance computed by your
 *  program and the amount of time it takes to compute it.
 *
 *  If you get segmentation fault when allocating memory for the last
 *  two test cases (N=20000 and N=28284), note this, and skip filling
 *  out the last rows of the table.
 **********************************************************************/

data file           distance       time (seconds)     memory (MB)
------------------------------------------------------------------
ecoli2500.txt       118                5.41342        25.243768
ecoli5000.txt 	    160	               21.5768        100.363392
ecoli7000.txt       194                41.5874        196.471392
ecoli10000.txt      223                86.0076        400.648768
ecoli20000.txt     segmation fault
ecoli28284.txt     segmation fault

/*************************************************************************
 *  Here are sample outputs from a run on a different machine for 
 *  comparison.
 ************************************************************************/

data file           distance       time (seconds)
-------------------------------------------------
ecoli2500.txt          118             0.171
ecoli5000.txt          160             0.529
ecoli7000.txt          194             0.990
ecoli10000.txt         223             1.972
ecoli20000.txt         3135            7.730



/**********************************************************************
 *  For this question assume M=N (which is true for the sample files 
 *  above). By applying the doubling method to the data points that you
 *  obtained, estimate the running time of your program in seconds as a 
 *  polynomial function a * N^b of N, where b is an integer.
 *  (If your data seems not to work, describe what went wrong and use 
 *  the sample data instead.)
 *
 *  Provide a brief justification/explanation of how you applied the
 *  doubling method.
 * 
 *  What is the largest N your program can handle if it is limited to 1
 *  day of computation? Assume you have as much main memory as you need.
 **********************************************************************/
explaination: time for constructor = 0(N^2) for resizing table, for Needleman-Wunsch = O(n^2). 
current time = 2*n^2. # loops = 8 so time = 2n^2 * 2^-8 = 2^-7 * n^2

a = 2^-7
b = 2
largest N = 1 day = 86400 seconds = 2^9 * n^2 -> n = 3325.53 mb

/
**********************************************************************
 *  Did you use the lambda expression in your assignment? If yes, where 
 * (describe a method or provide a lines numbers)
 **********************************************************************/
I used lambda expression in my constructor on line 13 in ED.cpp

ED::ED(std::string a, std::string b) : first(a), second(b) {

// first and second are strings makes them = to respective parameter

**********************************************************************
 *  List whatever help (if any) you received from the course TAs,
 *  instructor, classmates, or anyone else.
 **********************************************************************/



/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/



/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
