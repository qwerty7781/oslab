#!/bin/bash

# Prompt the user to enter two numbers
echo "Enter two numbers:"
read num1
read num2

# Check which number is the largest
if [ $num1 -gt $num2 ]; then
    largest=$num1
else
    largest=$num2
fi

# Display the largest number
echo "The largest number is: $largest"
