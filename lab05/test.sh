#!/bin/bash

# Test the copy utility
./copy2 source.txt target.txt

# Display the contents of the target file
cat target.txt

# Compare the source and target files
diff source.txt target.txt

# Test the missing arguments
./copy2
./copy2 source.txt

# Test too many arguments
./copy2 source.txt target.txt extra

# Test missing source file
./copy2 missing.txt target.txt
