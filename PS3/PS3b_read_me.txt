/**********************************************************************
 *                                                  
 *  PS3b: StringSound implementation and SFML audio output 
 **********************************************************************/

Name: Eric Kumar

Hours to complete assignment : 20

/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/
I completed the whole assignment. I know both my StringSound and CircularBuffer classes are working becase I implemented boost unit tests in test.cpp for every function and exception needed. 
IF you run the command ./Unit_Test all of my tests should pass. I know my KSGuitarSim program is running for two reasons 1 because I first tested that I can play sounds when A and C are pressed from the starter code in sslite.cpp
and secondly after making a simmilar program to sslite.cpp to make a vector of 37 sounds when tested on visual studios 19 plays different sounds for all 37 keys

/**********************************************************************
 *  Did you attempt the extra credit parts? Which one(s)?
 *  Successfully or not?  As a pair, or individually?
 **********************************************************************/


/**********************************************************************
 *  Did you implement exseptions to check your StringSound 
 *	implementation?
 *  Indicate yes or no, and explain how you did it.
 **********************************************************************/
Yes

I implemented exceptions mainly in the two constructors in StringSound they work the same as the ones used in my CircularBuffer constructor. I tested if the size of the vector or the inputted frequency is a positive number >0
if not will throw a invalid argument. I didnt need to implent exceptions for the other functions in the class because one that would normally need one (tic and pluck, and sample) call functions in the Circualr Buffer class that would check for the same exact things if I wrote them in StringSound
example I dont need to throw an exception in tic() if my StringSound is empty becuase when I call dequeue() my circularbuffer will throw an runtime error if the stringsound is empty.
/**********************************************************************
 *  List whatever help (if any) you received from TAs,
 *  classmates, or anyone else.
 **********************************************************************/



/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
 my circular buffer on its own in ps3a worked fine with smaller capacities but when i used it in stringsound (requires massive circualr buffers) it would never properly store any data and was having major issues with memory allocation. i dont know why but it worked after I changed the data in circular buffer from a *int16_t to a vector<int16_t>

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/