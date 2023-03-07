Everett Reynolds

The DList class has the attributes of both a length and a head that are set to 0 and NULL respectively at the beginning of an object's instantiation. 
These templates are allowed for the use of the creation of a linked list data structure, as a head is needed for linked list positioning and a length is needed to keep track of the number of nodes.
Dlist has a constructor which creates objects of DList and a destructor which deallocates memory resources from the objects when the program ends.
makeEmpty is an operation within the dList class that delete the head attribute, deleting reference to an object of DList, and recreates the list entirely.
PrintMenu is a list of cout statements which shows the user how to use the MoveFront algorithm program.
HeadInsert creates a new node in a linked list , gives it a value, and positions it at the front of the linked list in front of all other nodes.
TailInsert creates a new node in a linked list, gives it a value selected by the user, and puts the new node at the back of the linked list behind all others.
AccessItem is the basis for the MoveFront algorithm. 
It takes a user requested number, checks to see if it exists in the linked list first. 
Then, if it does, it finds the position of the number, deletes it, and adds it back to the front of the linked list, giving the illusion that it was moved when it was actually moved and recreated.
Delete takes a user requested number and looks to see if it's in the list. If it is, it goes to the position of the number and deletes it from the linked list.
PrintList takes the entire linked list and prints out the info contained within each data node.
PrintLength is a method which goes through every node in the linked list and increments a length attribute within DList and returns it to show the user the length of the linked list.
The Move To The Front Algorithm has it's main role when in use with user choice driven applications. 
Users want to find frequently used data the quickest, and this algorithm solves that issue by taking user accessed data and storing it in the front of a linked list, while infrequently used data and pushed farther backwards in the list.
In main, I have the creation of an object of the class and char variable. 
this char variable is used in a switch statement which cycles through all the operations of the DList.cpp class until the user decides their finished
When the user is done, they type in char = 'Q' to end the program entirely.
Each method in the client file has the same basic design where an int is created and the user is prompted for a number.
Each method calls it's related functions, or functions that combine to do a function similar to the header of the client method.
Most of the methods also do not allow for duplicates or notify the user if there is some sort of error with their request such as duplicates or an item not existing in the linked list.