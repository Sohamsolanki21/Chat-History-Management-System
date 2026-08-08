*Project Overview:
The Chat History Management System is a console-based C application that demonstrates the practical application of a Doubly Linked List, which is a linear data structure.
The system simulates the management of messages in a chat history. It allows users to add, display, search, delete, and navigate through messages in both forward and backward directions.
The project demonstrates important Data Structures concepts such as structures, pointers, dynamic memory allocation, insertion, deletion, traversal, searching, and memory deallocation.


*Problem Statement
Chat applications need to store and manage a sequence of messages efficiently. A chat history should allow users to:

Add new messages
View chat history
Navigate to the next message
Navigate to the previous message
Search for messages
Delete messages
Clear the complete chat history

This project uses a Doubly Linked List to represent and manage the sequential chat history.


Objectives:
To implement a real-life application using a linear data structure.
To implement a Doubly Linked List in C.
To dynamically store chat messages.
To perform insertion and deletion operations.
To implement forward and backward traversal.
To search messages using linear search.
To demonstrate dynamic memory allocation and deallocation.
To analyze the time and space complexity of the implemented operations


Data Structure Used
Doubly Linked List
Each chat message is stored as a node containing:
┌────────────┬────────────────────┬────────────┐
│    PREV    │      MESSAGE       │    NEXT    │
└────────────┴────────────────────┴────────────┘
The nodes are connected in both directions:
NULL ⇄ [Message 1] ⇄ [Message 2] ⇄ [Message 3] ⇄ NULL
                              ↑
                           CURRENT

                          
Why Doubly Linked List?
A Doubly Linked List is suitable because:
It supports forward and backward traversal.
Messages can be dynamically added.
Nodes can be deleted without shifting other elements.
Memory is allocated dynamically as required.
The prev and next pointers make message navigation simple.

Features:
Option	Feature	Description
1	Send Message	Adds a new message to the chat
2	Display Chat History	Displays all stored messages
3	Search Message	Searches for a message using linear search
4	Delete Message	Deletes a message using its position
5	Next Message	Moves to the next message
6	Previous Message	Moves to the previous message
7	Count Messages	Displays the total number of messages
8	Show Current Message	Displays the currently selected message
9	Clear Chat	Deletes all messages and frees memory
10	Exit	Clears allocated memory and exits

Algorithms:
Add Message
Create a new node using dynamic memory allocation.
Store the message in the node.
If the list is empty, make the node head, tail, and current.
Otherwise, connect the new node after tail.
Update tail.
Display successful insertion.

Delete Message
Read the position of the message.
Traverse the list to the required node.
Update the previous node's next pointer.
Update the next node's prev pointer.
Update head, tail, or current if required.
Free the deleted node.

Search Message
Start from head.
Traverse each node.
Compare the entered text with the stored message.
Display the position if a match is found.
Continue searching for additional matches.

Next / Previous
Next: Move current to current->next.
Previous: Move current to current->prev.

Complexity Analysis:
Let n be the number of messages.

Operation	Time Complexity:
Send Message	O(1)
Display Chat History	O(n)
Search Message	O(n)
Delete Message	O(n)
Next Message	O(1)
Previous Message	O(1)
Count Messages	O(n)
Show Current Message	O(1)
Clear Chat	O(n)

Space Complexity
O(n)

Each message requires one dynamically allocated node containing:
Message data
Previous pointer
Next pointer

Technologies Used:
Programming Language: C
Data Structure: Doubly Linked List
Memory Management: malloc() and free()
Compiler: Standard C Compiler
Development Environment: Online C Compiler

Real-Life Applications:
The concept demonstrated by this project can be applied to systems that manage sequential data requiring forward and backward navigation, such as:
Chat history interfaces
Music playlist navigation
Image gallery viewers
Browser navigation
Document/page navigation
Undo/Redo systems
This project is a DSA-based simulation and does not claim that these applications necessarily implement their internal systems using a Doubly Linked List.

Advantages:
Dynamic memory allocation
Supports bidirectional traversal
Efficient insertion at the end
Efficient navigation to next and previous nodes
No fixed-size array limitation
Demonstrates practical pointer manipulation

Limitations:
Requires extra memory for prev and next pointers.
Searching requires O(n) time.
Does not provide direct/random access like an array.
The project is a console-based simulation and does not provide real-time messaging or network communication.

Future Scope:
The project can be extended with:
User/contact management
Message timestamps
Sender information
Message editing
Sorting messages by time
File and media message simulation
Persistent storage using files
Graphical user interface
Database integration

References:
Reema Thareja, Data Structures Using C, Oxford University Press.
Yashavant Kanetkar, Data Structures Through C.
Ellis Horowitz, Sartaj Sahni, and Susan Anderson-Freed, Fundamentals of Data Structures in C.
GeeksforGeeks – Linked List and Doubly Linked List concepts.
C Standard Library documentation – malloc(), free(), strcpy(), and string handling.
