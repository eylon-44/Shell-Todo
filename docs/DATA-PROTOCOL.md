# Shell-Todo Data Protocol
___

### Data to be saved
- Todo string (e.g "read pages 34-56")
- Todo priority (e.g 2)

### Saving a todo
Using the command as:

> \$ todo add Pet the cat!
> Select a priority level from 1 (highest) to 5(lowest)
> $ 2

- Todo string = "Pet the cat!"
- Todo priority = 2

will create single new line in the data text file, such that the string follows the priotiry number.

$ Data.txt $
> 4 The first todo in the list
> 5 This is the second todo in the list
> 2 Pet the cat!

### Removing a todo
Simply entering todo will display the _sorted_ (by priority) todo list.

> $ todo
> Todo:
> 1\. [2] Pet the cat
> 2\. [4] This is the second todo in the list
> 3\. [5] This is the first todo in the list

Using the index of each todo the user can choose which one to remove.
> $ todo remove 3

The selected line will be deleted from the file.

$ Data.txt $
> 4 This is the second todo in the list
> 2 Pet the cat!