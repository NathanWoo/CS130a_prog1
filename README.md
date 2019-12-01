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
---------
I created a pair that stores the name of each student as the key, and stores all the corresponding score of that student as the value, I will call the pair `student`. And each student is stored in a vector called main vector. After finish reading the file, I loop through the main vector and use the `build_heap` on the score vector of each student, which gives me a max heap. And I'll take the average of the top k score as the `maxavg` of that student, and use that to compare with the `maxavg` of other students. Code implementation could be found at the [Prog1](./Prog1) folder 
