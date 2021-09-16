# covid
Project Description: During the COVID pandemic, many states reported the 7 day rolling average for covid cases.  It is smoother than tracking the cases for each day and provides a better indication of trends in COVID infections.  In Utah (Links to an external site.), they computed the average for 7 days, plotted that point, then shifted over one day to compute the average for the next 7 days. 


1. You should write a program that uses a STL queue (Links to an external site.) to compute the rolling average over a configurable number of days.  Your program should take as command line parameters a file name and the number of days for the average.  You should be able to run the program by typing

./covid cases.txt 7
to calculate the 7 day rolling average for the daily values in cases.txt

2.  Your program should output a comma delimited list of the rolling average of each window in the data.

Example:

Assume you have the following values in your cases.txt file

12
23
9
4
12
6
7
5
4
8
34
When you run the following command, you should get the given output

./covid cases.txt 7
Using Data from cases.txt with a 7 day rolling average
12,23,9,4,12,6,7,
Average 10
23,9,4,12,6,7,5,
Average 9
9,4,12,6,7,5,4,
Average 6
4,12,6,7,5,4,8,
Average 6
12,6,7,5,4,8,34,
Average 10
Lets look at this example in a little more detail

The first thing you should do is to insert the first 7 integers from the file into a queue<int>.

12,23,9,4,12,6,7,
You should create functions to print out your queue and to compute the average of values in the queue.  You can pass the queue by value to these functions so that your code will not destroy the original when popping the values to print them out or compute the average.  You can also assign a temporary queue<int> variable to the queue and then pop the values out of the temporary queue to compute the average.  The average for this first 7 integers is 10.

Then pop the first element off of the queue and push the next element from the file onto the queue and repeat until there are no more elements in the file.

The next 7 daily covid case values would be

23,9,4,12,6,7,5,
With an average of 9.

The next 7 daily covid case values would be

9,4,12,6,7,5,4,
with an average of 6.

The next 7 daily covid case values would be 

4,12,6,7,5,4,8,
with an average of 6.

The next 7 daily covid case values would be 

12,6,7,5,4,8,34,
with an average of 10.

Submission:

Submit a zip file with all of your code and a Makefile.  The TA should be able to unzip your submission, type "make" and then run your program.  You can create a submission file from the command line using the command:

zip main.zip main.cpp Makefile
You can also create a zip file in repl.it by going to the three dots to the right of "Files" and selecting "Download as zip".  Make sure you try unzipping the file to insure that it includes all of the files necessary to successfully make and run your program.

Grading:

The TAs will be grading your lab after the due date, so you probably ought to have another student in the class test your code to make sure it works.  The following rubric will be used:

+10 points: If your program prints out the name of the file and the number of days in the rolling average on the command-line
+40 points: If your program prints out the contents of the queue for each stage of the rolling average
+50 points: If your program correctly prints out the average values
