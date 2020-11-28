/**********************************************************************
 *  readme.txt template                                                   
 *  Markov Model
 **********************************************************************/

Name: Eric Kumar

Hours to complete assignment: 6
/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
The assignment was to build a markov model and use it to generate text based on the file it read from. 

This was achomplished by caluculating the frequency of the kgram (part of the inputted text)
and the frequency of the kgram following all possible characters to make a probabilly of a certain character to be generated.
then the krand function will pick a char to generate based on the probabillity calculated. 
Lastly the generate function makes new text based on the krand funciton and constantly updates the kgram to be the old kgram - the 1st char + krand char.
The user can then run my Textgenerator to produce text based on any input text file



  /**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/
A key data structure to this assignment was implementing a map. my map contains a kgram as the key that is paired with each char that has freq(kgram, char) >= 1. with that frequency.

I filled the map by using 2 for loops. the first one is to traverse the inputted text and go through each ascii value checking if freq(kgram, char) >= 1 and if so then add it to the map. 


my second for loop was for kgrams that used characters from both the end and the beggining of the text and also checked that freq(kgram, char) >= 1 and if so added to the map

If the korder = 0. I made a seperate loop to added the frequencies > 0 of every char in the text

to print my map when I overloaded the << operator I used two auto forloops to print every key (kgram) with its coorsponding characters and frequencies.


/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Include code excerpts.
 **********************************************************************/
 	Constructor:
 	
 My constructor set the values of korder, text and inital kgram. I used all of this to make a map desribed in the previous question:
 
 -------------------------------------------------------------------------
	Freq(kgram) and Freq(kgram, char):

both freq functions use practically the same for loops to find the frequencies only difference is size of substring/s. My first loop went from index 0 to index textsize -1 - kgram.size checking if the substring matches kgram (and possibly + char) if so incement count.

for (i = 0; i+korder-1 < size; i++) {
    if (my_text.substr(i, korder) == kgram) {
      count++;
    }

my second for loop used 2 substrings 1 from the end of my text and 1 from the beggining and checking if substrings matches the kgram (and possibly + char) if so increment count.

while (i != 0) {  // loop to check some text from beggining of string
    if (my_text.substr(i, size - i) + my_text.substr(0, korder-j) == kgram) {
      count++;
    }
    if (i >= size-1) {
      i = 0;
    } else {
      i++;
      j--;
    }
  }
 --------------------------------------------------------------------------

	KRand Function:

My KRand function made a vector that looped through every ascii value from 0 - 127 and push_back a char for each frequency. example: if freq(kgram, a) == 2 then I called push_back(a) twice. then I returned the char from vector.at(random number % freq(kgram)) to accuratelty simmulate the probabillities the next letter is.

std::vector <char> kgram_char;
  int char_frequency;
  for (int i = 0; i < 127; i++) {
    char_frequency = freq(kgram, static_cast<char>(i));
    if (char_frequency > 0) {
      for (int j = 0; j < char_frequency; j++) {
      kgram_char.push_back(static_cast<char>(i));
      }
    }
  }
  int char_to_return = rand(); // NOLINT
  return kgram_char.at(char_to_return % frequency);
--------------------------------------------------------------------------
	Generate(kgram, L):
	
	my function looped L times and added L krand(kgram) characters to an output string I then updated the kgram to remove the 1st char and add the new char to the kgram.
	
	int size = kgram.size();
  for (int i = 0; i < L; i++) {
    added = kRand(kgram);
    generated += added;
    if (size == 1) {
      kgram = added;
    } else {
      kgram = kgram.substr(1, size-1) + static_cast<std::string>(added);
    }
    
 
	
/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/
I completed the whole assignment. All required parts of the assingment work for 2 reasons. 1 I made a test.cpp file that checks that all of my functions and exceptions in my MModel class work as intended. Lastly, my Text Generator mirrors both the sample outputs and runs with the same command ./TextGenerator k L < input.txt.



/**********************************************************************
 *  Does your implementation pass the unit tests?
 *  Indicate yes or no, and explain how you know that it does or does not.
 **********************************************************************/
Yes My implementation passes my unit tests. The command to run my unit tests is : ./Unit_Test

All of the boost tests I made passed checking various functionallites and exceptions in my MModel class such as throwing a runtime error when it should or freq(nullstring, char) returns the number of times that char is in the text.



 /**********************************************************************
 *  Describe where you used exceptions. 
 *  Provide files and lines of the code.
 ***********************************************************************/
All of my exceptions I implemented are in my MModel.cpp file

Lines 14-17 : 
       int test_size = text.size(); // in constructor
       if (k > test_size) {
          throw std::invalid_argument("k does not equal to length of text");
        }
-----------------------------------------------------------------------
Lines 61-64 : //in freq(kgram)
        int test_size = kgram.size();
	if (test_size != korder) {
    	throw std::runtime_error("k does not equal to the length of inputted string"); // NOLINT
  	}
-------------------------------------------------------------------------
Lines 96-99 : // in freq(kgram, char)
  	int test_size = kgram.size();
  	if (test_size != korder) {
    	throw std::runtime_error("k does not equal to the length of inputted string"); // NOLINT
  	}
-------------------------------------------------------------------------
Lines 130-137 : // in Krand(kgram)
	int test_size = kgram.size();
  	if (test_size != korder) {
    	throw std::runtime_error("k does not equal to the length of inputted string"); // NOLINT
  	}
  	int frequency = freq(kgram);
  	if (frequency <= 0) {
    	throw std::runtime_error("kgram not found"); // NOLINT
  	}
--------------------------------------------------------------------------
Lines 152-155 : // In generate(kgram, L)
	int test_size = kgram.size();
  	if (test_size != korder) {
    	throw std::runtime_error("korder does not equal to the length of kgram"); // NOLINT
  	}
  	
 /**********************************************************************
 *  Describe where you used lambda expression if any
 *  Provide files and lines of the code.
 ***********************************************************************/
Yes in MModel.cpp

Lines 104-108: // in freq(kgram, char)

    if (test_size == 0) {  // order = 0
    auto sum = [](std::string text, char a) {  // lambda expression
    return std::count(text.begin(), text.end(), a); // NOLINT
    };
    return sum(my_text, c);


/**********************************************************************
 *  List whatever help (if any) you received from lab TAs,
 *  classmates, or anyone else.
 **********************************************************************/



/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/



/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
