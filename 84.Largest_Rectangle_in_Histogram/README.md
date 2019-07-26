# Explain the idea

We can consider the input sequence into two situation between two numbers.

It's either acending or decending order, and we try to maintain a monotonically increasing order.


# In decending part 
The current value is obiviously smaller than previous one, so the area it cover will be height(current_value) * width(current_index - first index in input which current_index is greater - 1(because index start with 0))

# In increasing part
The current value is obviously greater than previous one, so the area it cover will be height(current_value) * width(current_index - first index in input which current_index is smaller - 1(because index start with 0))


So, first we focus on decending part, to find first index in input which current_index is greater, we maintain the a stack.
 
Index can be push into it, only because the input[stack.top()] < input[current]. 

if we met a smallest height h, then we pop stack.item() all, push h in, every time we face the decending situation, we calculate the area with method mention above.

After above step, item in stack refer to the acending order index, the apply the acending order method to calculate.


# Complexity
Time Complexity : O(n)

Space Complexity : O(n)

# Reference:
https://www.youtube.com/watch?v=u7L_9REdiv4
