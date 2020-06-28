## Shell-v2

A simple shell application written in C and compiled on Ubuntu 18.04 using GCC version 9.3.

### Installation

Using Ubuntu 18.04, or 20.04, open a terminal and clone the repo.  Navigate to the `shell-v2` directory and run `make` to compile the program.  After compilation, just run the `hsh` executable.
```
$ git clone https://github.com/MatthewPlemmons/shell-v2.git
$ cd shell-v2
$ make
$ ./hsh
```
Running `hsh` will display the command prompt, denoted by `>`, and from there commands can be entered.

### Usage
Available built-in commands:
- `cd` changes the current working directory within the shell.
- `env` prints out a list of environment variables.
- `exit` exits the shell.

Additionally, the shell uses `execve` to execute any program within directories listed by the `PATH` evnironment variable.
