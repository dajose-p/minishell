# 🐚 Minishell

A lightweight shell implementation in C, recreating core functionality of bash as part of the 42 curriculum.

```
███╗   ███╗██╗███╗   ██╗██╗███████╗██╗  ██╗███████╗██╗     ██╗     
████╗ ████║██║████╗  ██║██║██╔════╝██║  ██║██╔════╝██║     ██║     
██╔████╔██║██║██╔██╗ ██║██║███████╗███████║█████╗  ██║     ██║     
██║╚██╔╝██║██║██║╚██╗██║██║╚════██║██╔══██║██╔══╝  ██║     ██║     
██║ ╚═╝ ██║██║██║ ╚████║██║███████║██║  ██║███████╗███████╗███████╗
╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝
```

## 📋 Table of Contents

- [About](#about)
- [Features](#features)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Built-in Commands](#built-in-commands)
- [Project Structure](#project-structure)
- [Technical Implementation](#technical-implementation)
- [Current Limitations](#current-limitations)
- [Learning Outcomes](#learning-outcomes)
- [Authors](#authors)

## 🎯 About

Minishell is a simplified Unix shell implementation that provides basic command-line interface functionality. This project explores fundamental concepts of process management, file descriptors, system calls, and command parsing.

**Why build a shell?**
- Understanding how terminals work under the hood
- Learning process creation and management (fork, exec, wait)
- Mastering string parsing and tokenization
- Working with environment variables
- Implementing built-in commands vs external programs

## ✨ Features

### Currently Implemented

- ✅ **Interactive Prompt**: Custom colored prompt showing user and current directory
- ✅ **Command History**: Navigate through previous commands using readline
- ✅ **Environment Variables**: Copy and maintain shell environment
- ✅ **Built-in Commands**:
  - `echo` - Display text (basic functionality)
  - `cd` - Change directory
  - `pwd` - Print working directory
  - `exit` - Exit the shell
- ✅ **Custom libft**: Extended library with ft_printf and get_next_line

### In Progress

- 🔨 Command parsing and tokenization
- 🔨 Pipe implementation (`|`)
- 🔨 Redirections (`<`, `>`, `>>`, `<<`)
- 🔨 `export` - Set environment variables
- 🔨 `unset` - Remove environment variables
- 🔨 `env` - Display environment variables
- 🔨 Signal handling (Ctrl+C, Ctrl+D, Ctrl+\\)
- 🔨 Quote handling (single and double quotes)
- 🔨 Environment variable expansion (`$VAR`)

## 🔧 Requirements

- **OS**: Linux or macOS
- **Compiler**: GCC or Clang with C99 support
- **Libraries**: 
  - readline (`libreadline-dev` on Ubuntu/Debian)
  - Standard C library

### Installing readline

**On Ubuntu/Debian:**
```bash
sudo apt-get install libreadline-dev
```

**On macOS:**
```bash
brew install readline
```

## 🚀 Installation

1. **Clone the repository:**
```bash
git clone https://github.com/yourusername/minishell.git
cd minishell
```

2. **Build the project:**
```bash
make
```

3. **Run minishell:**
```bash
./minishell
```

### Makefile Targets

- `make` or `make all` - Compile the project
- `make clean` - Remove object files
- `make fclean` - Remove object files and binary
- `make re` - Rebuild everything from scratch
- `make run` - Build and run the program
- `make debug` - Build with debug flags and address sanitizer
- `make norm` - Check code against norminette (42 standard)

## 💻 Usage

### Starting Minishell

```bash
$ ./minishell
user@minishell: /current/path$
```

### Example Commands

```bash
# Display text
user@minishell: ~$ echo Hello World
Hello World

# Show current directory
user@minishell: ~$ pwd
/home/user

# Change directory
user@minishell: ~$ cd /tmp
user@minishell: /tmp$ pwd
/tmp

# Exit the shell
user@minishell: /tmp$ exit
```

## 🛠 Built-in Commands

### echo
Prints arguments to standard output.

```bash
echo Hello World
# Output: Hello World
```

**Current Implementation:**
- ✅ Basic string output
- ✅ Multiple arguments with spaces
- ❌ `-n` flag (no newline) - not yet implemented
- ❌ Escape sequences - not yet implemented

### cd
Changes the current working directory.

```bash
cd /path/to/directory
cd ..              # Go up one directory
cd                 # Go to home directory (not implemented)
```

**Current Implementation:**
- ✅ Change to absolute paths
- ✅ Change to relative paths
- ❌ `cd` without arguments (home directory)
- ❌ `cd -` (previous directory)
- ⚠️ Error handling needs improvement

### pwd
Prints the current working directory.

```bash
pwd
# Output: /current/working/directory
```

**Current Implementation:**
- ✅ Displays full path to current directory
- ✅ Uses `getcwd()` system call

### exit
Exits the minishell.

```bash
exit
```

**Current Implementation:**
- ✅ Basic exit functionality
- ❌ Exit with status code
- ❌ Proper cleanup of resources

## 📁 Project Structure

```
minishell/
├── builtins/           # Built-in command implementations
│   ├── builtins.h      # Built-in commands header
│   ├── cd.c            # Change directory
│   ├── echo.c          # Echo command
│   ├── exit.c          # Exit command
│   ├── pwd.c           # Print working directory
│   └── main_func.c     # Built-in dispatcher
├── srcs/               # Main source files
│   ├── main.c          # Entry point and main loop
│   ├── checks.c        # Command type checking
│   └── lst_ops.c       # Linked list operations for env
├── libft/              # Custom C library
│   ├── ft_*.c          # String, memory, list functions
│   ├── ft_printf.*     # Custom printf implementation
│   ├── get_next_line.* # Read line from file descriptor
│   └── libft.h         # Library header
├── minishell.h         # Main project header
├── Makefile            # Build configuration
└── README.md           # This file
```

## 🔬 Technical Implementation

### Environment Variables

The shell maintains its own copy of environment variables using a linked list structure:

```c
typedef struct s_env
{
    char         *key;      // Variable name (e.g., "PATH")
    char         *value;    // Variable value
    struct s_env *next;     // Next variable in list
} t_env;
```

**Why a linked list?**
- Dynamic size (can add/remove variables easily)
- Efficient for the typical small number of environment variables
- Good practice with dynamic memory management

### Command Flow

1. **Read**: Readline gets user input
2. **Check**: Determine if command is built-in or external
3. **Execute**: 
   - Built-ins: Call function directly
   - External: Fork process and exec (not yet implemented)
4. **Display**: Show output and return to prompt

### Memory Management

- All malloc'd memory should be freed before exit
- Environment variables are stored in a linked list that needs cleanup
- Readline allocates memory that must be freed after each command
- Current status: ⚠️ Memory management needs improvement (potential leaks)

## ⚠️ Current Limitations

### Known Issues

1. **Memory Leaks**: 
   - Not all dynamically allocated memory is properly freed
   - Need to implement comprehensive cleanup on exit

2. **Error Handling**:
   - Minimal error checking on system calls
   - No graceful handling of invalid commands
   - cd error messages not user-friendly

3. **Parsing**:
   - No proper tokenization of complex commands
   - Quotes are not handled
   - Pipes and redirections not implemented

4. **Signal Handling**:
   - Ctrl+C, Ctrl+D, Ctrl+\\ not properly handled
   - No job control

5. **Built-ins**:
   - Missing: export, unset, env
   - echo lacks -n flag
   - cd doesn't handle ~ or -

### Testing Needed

Before considering this production-ready:
- [ ] Test with very long commands
- [ ] Test with special characters
- [ ] Test memory usage (valgrind)
- [ ] Test all edge cases for each built-in
- [ ] Test with empty input
- [ ] Test with only whitespace

## 📚 Learning Outcomes

### Key Concepts Mastered

1. **Process Management**
   - Understanding fork(), exec(), wait()
   - Parent-child process relationships
   - Process IDs and exit status

2. **File Descriptors**
   - Standard input (0), output (1), error (2)
   - Redirection basics
   - Using dup2() for stream manipulation

3. **String Parsing**
   - Tokenization strategies
   - Handling quotes and special characters
   - Building command structures from user input

4. **System Calls**
   - getcwd(), chdir()
   - read(), write()
   - Working with errno

5. **Memory Management**
   - Dynamic allocation with malloc/free
   - Linked list operations
   - Avoiding memory leaks

### Challenges Faced

1. **Readline Integration**: Learning how to properly use readline library
2. **Environment Setup**: Copying and maintaining environment variables
3. **Code Organization**: Structuring a multi-file C project
4. **Makefile Complexity**: Managing dependencies and compilation rules

## 🎓 42 Curriculum Context

This project is part of the 42 common core curriculum, focusing on:
- Unix system programming
- Process management
- Low-level string manipulation
- Project organization and Makefile creation
- Collaboration (if done in pairs)

### Norminette Compliance

The code follows 42's norminette standards:
- Maximum 25 lines per function
- Maximum 5 functions per file
- Specific naming conventions
- No forbidden functions

Check compliance with:
```bash
make norm
```

## 👥 Authors

- **dajose-p** - [42Madrid](https://42madrid.com)

## 📝 Notes for Future Development

### Priority Improvements

1. **Implement proper parser**
   - Tokenization of input
   - Handle quotes correctly
   - Build command structures

2. **Add pipe support**
   - Create pipe with pipe()
   - Connect processes with dup2()
   - Manage multiple processes

3. **Implement redirections**
   - Input: `< file`
   - Output: `> file`
   - Append: `>> file`
   - Heredoc: `<< delimiter`

4. **Complete remaining built-ins**
   - export with proper validation
   - unset with error checking
   - env with formatting

5. **Signal handling**
   - Clean Ctrl+C behavior
   - Ctrl+D (EOF) handling
   - Ctrl+\\ (SIGQUIT)

### Code Quality Improvements

- [ ] Add comprehensive error handling
- [ ] Implement proper memory cleanup
- [ ] Add unit tests
- [ ] Better separation of concerns
- [ ] More descriptive variable names
- [ ] Comprehensive commenting

## 🔗 Resources

- [GNU Bash Manual](https://www.gnu.org/software/bash/manual/)
- [Advanced Programming in the UNIX Environment](https://www.apuebook.com/)
- [Beej's Guide to Unix IPC](https://beej.us/guide/bgipc/)
- [GNU Readline Documentation](https://tiswww.case.edu/php/chet/readline/rltop.html)

## 📄 License

This project is part of 42 School's curriculum. Code may be freely used for educational purposes.

---

**Last Updated**: January 2026  
**Status**: 🚧 Work in Progress  
**Version**: 0.1.0 (Initial Development)