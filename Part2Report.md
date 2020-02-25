Course: D0041D Student: Herman Åberg

# Part II: Determine palindrome using Stack and Queue

### Task
A palindrome is a string that reads the same forwards as backwards (ignoring spaces, punctuation, and the difference between upper- and lowercase letters). Create two functions that can determine whether or not the input is a palindrome or not. The functions are to use the data structures, respectively:
* Stacks only
* Stacks and Queues

Measure the running time of each implementation and determine which is more efficient.

### Data structures
* __Stack__

	Stack is a linear data structure that only allows elements to be inserted and removed from one side of the list, called the __top__. This follows the __LIFO__ (Last In, First Out) principle. To access any element bellow the top one you need to first remove the top element.
	
* __Queue__

	Queue is very similar to stack in that it is a linear data structure with only one in and one out. The difference is that elements can only be inserted from the __rear__ and only be deleted from the __front__. This follows the _FIFO (First In, First Out) principle.
	
### Algorithms and implementation
The handling of the strings and adding them to the stacks will not matter for this test and therefore we can instead create stacks that contain a random array of capital letters and then send that stack to both the functions and compare the time it took to determine if the stack contained a palindrome or not. Because the only difference between stack and queue are what they return when you call __Peek()__ and what is deleted when you call __Pop()__ you only need to have the stack class save the possition of the __rear__ element to have them be interchangable. This is usefull for the implementation using both stack and queue. Taking the __front__ (or __top__) element's position minus the __rear__ element's we can get the the number of elements in the stack/queue.
* __Stack only__

	The only way to know if a stack contains a palindrome is to compare the first half to the second half of the stack. Because we know the size of the string in the stack we can use a for-loop to add the first half of the word in opposite order in a new stack and then go throught each element in the original stack while comparing that to the new stack. If the characters aren't the same we know that it is not a palindrome.
	
* __Queue and stack__

	If we create a queue and copy the data from the stack we can the compare the __top__ and __front__ of the stack and queue respectively until we have compared the first half of the string with the second half.

### Benchmarking
The benchmarking is done by using a class that takes the time it was created and when it goes out of scope and then sends that information as well as it's name to a singleton class that then combines the total time for all timers with that name. The singleton class has a Print() method that prints out all the timers and thier duration.

In the below table we can see how the running time of the two functions compare:

| Word size | Number of words | Stack Only | Stack & Queue |
------------|-----------------|------------|----------|
| 32 | 1000000 | 970.206 ms | 170.917 ms |
| 64 | 1000000 | 1619.91 ms | 175.733 ms |
| 32 | 2000000 | 1957.01 ms | 342.609 ms |
| 64 | 2000000 | 3202.41 ms | 343.264 ms |

We can clearly see that with this implementation using stack and queue is a lot faster than only using stack. One interesting thing to note is that increasing the word size effects the running time of Stack Only almost linearly while Stack & Queue barely saw a increase in running time. Doubling the number of words increased the running time of Stack Only by more than double while Stack & Queue scaled linearly.
