# Explain my idea

Main idea is to use array to accumulate the overall tired day,

If hour > 8, +1, -1, otherwise.  
  
  
If array[i] > 0 -> means it must legal, just update the ans with i+1.

If array[i] <= 0 -> check if the array[i] - 1  comes up before, here we use the dictionary  to do this job.
(check.setdefault(array[i], i) always return the first time where array[i] comes up)



# Complexity

Time Complexity : O(n)

Space Complexity : O(n)
