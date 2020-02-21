Course: D0041D
Student: Herman Åberg


# Part I: Student database using lists
### Introduction
This report goes over the result of the benchmarking of two student databases, one using array-baseds list and the other using linked lists. It will also cover what differences there are between array-based and linked lists and how they should theoretically perform and then compare that to how they performed in my implementation.
### Lists used
* #### Array-based list
	Array-based lists is a data structure that is used to store data in a single array, meaning that all the elements are stored sequentially in memory.
	
	The big advantage of array-based lists is that you can access a point of data using index, meaning that you have constant time access to every element in the array. This makes array-based lists great for when you want to access an element when you know the index of it.
	
	The drawbacks of using an array-based list is that it is not very dynamic. Adding or removing an element near the middle of the list requires a huge portion of the array to be moved to make space for the new element or fill in the gap created by the deleted element. This means that the time it takes to add or delete an element is dependent on what index and how big the array is.
	
	Arrays can also not expand or shrink. If the amount of element would exceed the size of the array then it need to create a new array with a bigger size and then copy all of the data over to it before removing itself. This equates to it being an expensive operation.
	
	In testing we should see that the database using array-based lists should have:
	* Good performance when searching for a student or course.
	* Not the best performance when adding a student or course in a large set of data.
	* Bad performance when deleting a student or a course in a large set of data.
	
* #### Linked list
	Linked lists consists of nodes. Each node stores data and also points towards the next node in the list, with the linked list pointing towards the "head" of the nodes, the first node in the list.
	
	Because the nodes in a linked list are not sequentially stored in memory you need to go through each node before the one you searched for. This equates to worse performance the more elements you have before the one you search for.
	
	The big advantage of using linked lists is that they are really fast at removing nodes from the list. The only action needed before removing the node is setting what the previous node points towards to the node that the one to be deleted points towards. This is a really quick operation relative to array-based lists.
	
	Adding new nodes can be really quick depending on if you need to add the new node to a specific point in the list. If you don't need to add it to a specific point you can easily replace the head of the list with the new node and make it point towards the old head. This should be a quick operation depending on implementation.
	
	In testing we should see that the database using linked lists should have:
	* Great or good performance when adding a new student or course.
	* Great performance when deleting a student or course in a large set of data.
	* Not so great performance when searching for a student or course.
### Performance analysis
For benchmarking I did three runs. Each run constists of four parts, each part is repeated the same number of times. Students are searched for by index.
	
Amount of actions | List Type | Adding Students | Adding Courses | Deleting Courses | Deleting Students | Total Time |
----------------- | --------- | ---------- | --------- | ------------ | ------------- | ---------- |
1000 | Linked | 2ms | 1ms | 2ms | 1ms | 6ms |
1000 | Array | 6ms | 0ms | 1ms | 122ms | 131ms |
10000 | Linked | 13ms | 311ms | 315ms | 175ms | 816ms |
10000 | Array | 69ms | 11ms | 2ms | 13081ms | 13163ms |
100000 | Linked | 134ms | 11941ms | 12525ms | 13644ms | 38247ms |
100000 | Array | 729ms | 96ms | 25ms | * | * |

_*took too long_
### Reflection
Even though my methodology isn't perfect we can still clearly see that the biggest determiner of whether Array or Linked is faster is the time Array takes to delete students. We can also see that the time it takes to delete students grows exponentially with the amount of students. This also shows why testing using a large data set is important.

One thing that might seem weird at first is that Array is way faster when it comes to deleting courses. The reason is because the amount of courses added is the same as the amount of students in the database, so the likelihood of a student having a large amount of courses is very low or they might not have any at all. So the biggest deciding factor is the time it takes to access the student, and we know that Array should be faster at that.

The biggest improvements I could do is change the benchmarking to something a represents the workload of a real database of students. An example would be benchmarking the time it takes to just search for information of a student. Another thing would be doing some actions more or less than others, for example adding more courses than students.

Overall I am happy with the results and believe it agrees with the previus statements of how the lists should theoretically perform.
