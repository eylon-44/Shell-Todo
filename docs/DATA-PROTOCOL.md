# Shell-Todo Data Protocol
___

### Data to be saved
- Todo string (e.g "read pages 34-56")
- Todo priority (e.g 2)

The data will be saved and read from the working directory in a file named $.todo$.

<small>Note that the _.todo_ file is local, such that each directory will have its own todo list.</small>

### Saving a todo
Using the command as:

> \$ todo add Pet the cat!
> Select a priority level from 1 (highest) to 5(lowest)
> $ 2

- Todo string = "Pet the cat!"
- Todo priority = 2

will create single new line in the data file, such that the string follows the priotiry number.

$ .todo $
> 4The first todo in the list
> 5This is the second todo in the list
> 2Pet the cat!

### Removing a todo
Simply entering todo will display the _sorted_ (by priority) todo list.

> $ todo
Todo:
1\. [2] Pet the cat
2\. [4] This is the second todo in the list
3\. [5] This is the first todo in the list

Using the index of each todo the user can now choose which task to remove.
> $ todo remove 3

The selected line will be deleted from the file.

$ .todo $
> 4This is the second todo in the list
2Pet the cat!



<small>_Note that the index showed in the console might not be the same one as in the actual data file due to the list sorting._</small>