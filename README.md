Program 1
=========

Problem Overview
--------

Student test scores are streamed on stdin. The first line is a number (k). Each subsequent line consists of a student ID, which is an alphanumeric string without spaces, and an integer between \[0-1000\]. The input is terminated with 2 newlines. Write a program which takes this input containing test scores and returns the student who has the maximum score averaged across his/her top k tests, followed by a newline. If the student has fewer than k test scores, ignore that student.

For this assignment, you must implement your own heap along with the `percolate_up`, `percolate_down`, and `build_heap` methods. Don't feel obligated to change your naming convention to match this; `camelCase` is fine, you don't have to use `snake_case`.

Sample Input
------------

2
bob14 7  
steve92 998  
bob14 999  
skip 1000  
steve92 998  
bob14 999
   
     
   
    
(end of file was two empty lines)

Sample Output
-------------

bob14


Solution 
----------
I created a max heap that 