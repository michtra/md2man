# Shell Scripting

Shell scripting allows you to automate tasks in Linux by combining commands, control structures, and variables. This section covers basic shell scripting concepts for the Bash shell.

## Creating Scripts

A shell script is a text file containing a series of commands. To create a shell script:

1. Create a file with a `.sh` extension (e.g., `script.sh`)
2. Start with a shebang line to specify the interpreter
3. Add your commands
4. Make the script executable with `chmod +x script.sh`

**Basic Script Example:**
```bash
#!/bin/bash

# This is a comment
echo "Hello, World!"
```

## Shebang Line

The first line of a shell script should be the shebang line, which indicates which interpreter to use.

```bash
#!/bin/bash  # Use Bash interpreter
#!/bin/sh    # Use the system's default shell
#!/bin/zsh   # Use Zsh interpreter
```

## Variables

Variables store data that can be referenced and manipulated in a script.

**Declaring and Using Variables:**
```bash
# No spaces around the equals sign
name="John"
age=30
directory=$(pwd)  # Command substitution

# Access a variable by prefixing with $
echo "Name: $name"
echo "Age: $age"
echo "Current directory: $directory"

# Using curly braces for clarity or when needed
echo "Hello, ${name}!"
echo "In 5 years, you will be $((age + 5)) years old"
```

**Special Variables:**
- `$0`: Script name
- `$1, $2, ...`: Positional parameters (arguments passed to the script)
- `$#`: Number of arguments
- `$@`: All arguments as separate words
- `$*`: All arguments as a single word
- `$$`: Process ID of the current shell
- `$?`: Exit status of the last command
- `$!`: Process ID of the last background command

## Command Substitution

Captures the output of a command and uses it as part of another command.

```bash
current_date=$(date +%Y-%m-%d)
files_count=$(ls | wc -l)

echo "Today is $current_date"
echo "Number of files: $files_count"
```

## Input and Output

**Reading User Input:**
```bash
echo -n "Enter your name: "
read name

echo -n "Enter your age: "
read age

echo "Hello, $name! You are $age years old."
```

**Reading Multiple Values:**
```bash
echo -n "Enter your first and last name: "
read first_name last_name

echo "First name: $first_name"
echo "Last name: $last_name"
```

**Redirecting Output:**
```bash
# Redirect stdout to a file (overwrite)
echo "Hello, World!" > output.txt

# Append to a file
echo "Another line" >> output.txt

# Redirect stderr to a file
command 2> error.txt

# Redirect both stdout and stderr to a file
command > output.txt 2>&1

# Discard output
command > /dev/null
```

## Conditional Statements

**If-Else Statements:**
```bash
if [ condition ]; then
    # commands
elif [ another_condition ]; then
    # commands
else
    # commands
fi
```

**Common Conditional Tests:**
- File tests:
  - `-e file`: True if file exists
  - `-f file`: True if file is a regular file
  - `-d file`: True if file is a directory
  - `-r file`: True if file is readable
  - `-w file`: True if file is writable
  - `-x file`: True if file is executable
  - `-s file`: True if file is not empty

- String tests:
  - `-z string`: True if string is empty
  - `-n string`: True if string is not empty
  - `string1 = string2`: True if strings are equal
  - `string1 != string2`: True if strings are not equal

- Numeric comparisons:
  - `n1 -eq n2`: Equal
  - `n1 -ne n2`: Not equal
  - `n1 -lt n2`: Less than
  - `n1 -le n2`: Less than or equal
  - `n1 -gt n2`: Greater than
  - `n1 -ge n2`: Greater than or equal

**Examples:**
```bash
# Check if a file exists
if [ -f "$filename" ]; then
    echo "$filename exists"
else
    echo "$filename does not exist"
fi

# Check if a directory is empty
if [ -d "$directory" ] && [ "$(ls -A "$directory")" ]; then
    echo "$directory is not empty"
else
    echo "$directory is empty or doesn't exist"
fi

# String comparison
if [ "$password" = "secret" ]; then
    echo "Access granted"
else
    echo "Access denied"
fi

# Numeric comparison
if [ "$age" -ge 18 ]; then
    echo "You are an adult"
else
    echo "You are a minor"
fi

# Multiple conditions with AND/OR
if [ "$username" = "admin" ] && [ "$password" = "secret" ]; then
    echo "Admin access granted"
fi

if [ "$choice" = "yes" ] || [ "$choice" = "y" ]; then
    echo "You chose yes"
fi
```

**Modern Bash Conditional Syntax:**
```bash
# Using double brackets for enhanced features
if [[ "$string" == *wild* ]]; then
    echo "String contains 'wild'"
fi

# Arithmetic comparison
if (( num > 10 )); then
    echo "Number is greater than 10"
fi
```

## Case Statements

Case statements provide a cleaner way to match a variable against multiple values.

```bash
case "$variable" in
    pattern1)
        # commands
        ;;
    pattern2)
        # commands
        ;;
    pattern3|pattern4)
        # commands for either pattern3 or pattern4
        ;;
    *)
        # default commands
        ;;
esac
```

**Example:**
```bash
echo -n "Enter a fruit name: "
read fruit

case "$fruit" in
    apple)
        echo "Red fruit"
        ;;
    banana)
        echo "Yellow fruit"
        ;;
    orange|tangerine)
        echo "Orange fruit"
        ;;
    *)
        echo "Unknown fruit"
        ;;
esac
```

## Loops

**For Loops:**
```bash
# Iterate over a list
for item in apple banana orange; do
    echo "Fruit: $item"
done

# Iterate over files
for file in *.txt; do
    echo "Processing $file"
done

# C-style for loop
for ((i=1; i<=5; i++)); do
    echo "Number: $i"
done
```

**While Loops:**
```bash
# Counting with while
count=1
while [ $count -le 5 ]; do
    echo "Count: $count"
    ((count++))
done

# Reading a file line by line
while read line; do
    echo "Line: $line"
done < input.txt
```

**Until Loops:**
```bash
count=1
until [ $count -gt 5 ]; do
    echo "Count: $count"
    ((count++))
done
```

**Breaking and Continuing:**
```bash
# Break example
for i in 1 2 3 4 5; do
    if [ $i -eq 3 ]; then
        break  # Exit the loop
    fi
    echo "Number: $i"
done

# Continue example
for i in 1 2 3 4 5; do
    if [ $i -eq 3 ]; then
        continue  # Skip to next iteration
    fi
    echo "Number: $i"
done
```

## Functions

Functions help organize code into reusable blocks.

```bash
# Function definition
function_name() {
    # commands
    return value  # Optional return value (0-255)
}

# Alternatively
function function_name {
    # commands
}
```

**Examples:**
```bash
# Simple function
say_hello() {
    echo "Hello, $1!"
}

# Call the function
say_hello "World"  # Outputs: Hello, World!

# Function with a return value
is_even() {
    if (( $1 % 2 == 0 )); then
        return 0  # True in shell scripting
    else
        return 1  # False in shell scripting
    fi
}

# Using the function
if is_even 4; then
    echo "4 is even"
else
    echo "4 is odd"
fi

# Function with local variables
calculate_sum() {
    local num1=$1
    local num2=$2
    local sum=$((num1 + num2))
    echo $sum
}

# Capture function output
result=$(calculate_sum 5 3)
echo "Sum: $result"
```

## Arrays

Bash supports indexed and associative arrays.

**Indexed Arrays:**
```bash
# Declaration
fruits=("apple" "banana" "orange")

# Adding elements
fruits+=("grape")

# Accessing elements
echo "${fruits[0]}"  # First element
echo "${fruits[@]}"  # All elements
echo "${#fruits[@]}"  # Number of elements

# Iterating through array
for fruit in "${fruits[@]}"; do
    echo "Fruit: $fruit"
done
```

**Associative Arrays (Bash 4.0+):**
```bash
# Declaration
declare -A user
user[name]="John"
user[age]=30
user[city]="New York"

# Accessing elements
echo "${user[name]}"  # Value for key 'name'
echo "${!user[@]}"    # All keys
echo "${user[@]}"     # All values

# Iterating through associative array
for key in "${!user[@]}"; do
    echo "$key: ${user[$key]}"
done
```

## Error Handling

**Exit Status Checking:**
```bash
# Check exit status
if ! command; then
    echo "Command failed"
    exit 1
fi

# Or using the $? variable
command
if [ $? -ne 0 ]; then
    echo "Command failed"
    exit 1
fi
```

**Trap Command:**
```bash
# Cleanup on exit
cleanup() {
    echo "Cleaning up temporary files..."
    rm -f /tmp/tempfile.$$
}

trap cleanup EXIT

# Handle specific signals
trap "echo 'Script interrupted'; exit 1" INT TERM
```

**Handling Errors with Set:**
```bash
# Exit on error
set -e

# Exit on undefined variables
set -u

# Exit if any command in a pipe fails
set -o pipefail

# Combine options
set -euo pipefail
```

## Script Template

A basic template for shell scripts:

```bash
#!/bin/bash
#
# Script Name: script_name.sh
# Description: Brief description of the script
# Author: Your Name
# Date: YYYY-MM-DD
#
# Usage: ./script_name.sh [arguments]

# Exit on error, undefined variables, and pipe failures
set -euo pipefail

# Define constants
BACKUP_DIR="/path/to/backup"
LOG_FILE="/var/log/script.log"

# Define functions
log() {
    local timestamp=$(date +"%Y-%m-%d %H:%M:%S")
    echo "[$timestamp] $1" >> "$LOG_FILE"
    echo "[$timestamp] $1"
}

cleanup() {
    log "Cleaning up..."
    # Add cleanup commands here
}

# Set up trap for cleanup
trap cleanup EXIT

# Parse command line arguments
while getopts ":hvo:" opt; do
    case ${opt} in
        h)
            echo "Usage: $0 [-h] [-v] [-o output_file]"
            echo "  -h: Display this help message"
            echo "  -v: Verbose mode"
            echo "  -o: Specify output file"
            exit 0
            ;;
        v)
            VERBOSE=true
            ;;
        o)
            OUTPUT_FILE=$OPTARG
            ;;
        \?)
            echo "Invalid option: -$OPTARG" >&2
            exit 1
            ;;
        :)
            echo "Option -$OPTARG requires an argument" >&2
            exit 1
            ;;
    esac
done
shift $((OPTIND - 1))

# Main script logic
log "Script started"

# Check if required programs are installed
if ! command -v rsync &> /dev/null; then
    log "Error: rsync is not installed"
    exit 1
fi

# Your script code here

log "Script completed successfully"
exit 0
```
