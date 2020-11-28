/**********************************************************************
 *  readme.txt template                                                   
 *  PS6 Kronos 
 **********************************************************************/

Name: Eric Kumar


Hours to complete assignment: 4


/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/
I completed the whole assignment. 

The regular expressions and boost date/time implementations in my program work as intended

Secondly, I know my output is correct because in my device5_intouch.log.rpt file the number of (log.c.166) server started, number of successfull bootups and the elasped times match the sample device5_intouch.log.rpt.



/**********************************************************************
 *  Copy here all regex's you created for parsing the file, 
 *  and explain individually what each ones does.
 **********************************************************************/
boost::regex start("[(]log[.]c[.]166[)] server started");

- checks for exact expression (log.c.166) server started
- only boot startups have that exact string

boost::regex end("oejs[.]AbstractConnector:Started SelectChannelConnector");

- checks for exact expression oejs.AbstractConnector:Started SelectChannelConnector
- only boot completions have that exact string

/**********************************************************************
 *  Describe your overall approach for solving the problem.
 *  100-200 words.
 **********************************************************************/
The first thing I did was make 2 regular expressions and used strings in main instead of the log file to test with trial and error.

then I made sure I could open the device[1-6]_intouch.log file and output it with .rpt

then I made sure I can correctly read each line from log file and check with both of my regular expressions

then I made boost date and times to calculate the elasped time for successful startups

lastly I made correct outputs to the created .rpt file

/**********************************************************************
 *  Did you use lambda expression? If yes describe there.
 **********************************************************************/





/**********************************************************************
 *  List whatever help (if any) you received from TAs,
 *  classmates, or anyone else.
 **********************************************************************/



/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/



/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/

