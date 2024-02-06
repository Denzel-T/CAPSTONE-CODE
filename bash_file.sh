#!/bin/bash
# Collect all C files in the current directory
c_files=$(ls *.c 2>/dev/null)
# Check if there are any C files
if [ -z "$c_files" ]; then
	echo "No C files found in the current directory."
	exit 1
fi
# Specify the output executable name
output="output_executable"
# Compile the C files and create the executable
gcc -o "$output" $c_files
# Check if compilation was successful
if [ $? -eq 0 ]; then
	echo "Compilation successful. Executable '$output' created."
else
	echo "Compilation failed. Please check for errors."
	exit 1
fi