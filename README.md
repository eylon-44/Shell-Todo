
<h1 align="center">
  Shell-Todo
</h1>

___

### Description
Shell-Todo is a linux terminal util to manage local tasks.
The program saves tasks for each directory and sort them by their priority when listed.

### Compile, Run & Install
Compile the program by navigating to the project's root directory and typing:
```
$ make
```
Run, by using make:
```
$ make run ARGS="[enter your arguments here]"
```
or, locate the file in the bin directory and run it:
```
$ ./bin/shell-todo.bin [enter your arguments here]
```
You can also install the program in the system's path (/usr/bin/) for easy access of the command from anywhere in the terminal:
```
$ make add_to_path
[sudo] password: ****
> Program added to path, use "td" to call it.
$ td [enter your arguments here]
```
if you want to remove it from path you can always use:
```
$ sudo rm -f /usr/bin/td
```

### Usage
Adding a todo will create a _".todo"_ file in the working directory. Deleting the file will delete the tasks you added for that specific directory.
```
$ td help
> Usage: td [command] [arguments]
Commands:
	-help              -> show this text
	-add [text]        -> add a task into the todo list
	-rem [index]       -> remove a task from the todo list
	-[no command]/list -> display the todo list

```