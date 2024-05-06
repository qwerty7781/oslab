#!/bin/bash

# Prompt the user to enter three numbers
echo "Enter three numbers:"
read num1
read num2
read num3

# Check which number is the largest
if [ $num1 -gt $num2 ] && [ $num1 -gt $num3 ]; then
    largest=$num1
elif [ $num2 -gt $num1 ] && [ $num2 -gt $num3 ]; then
    largest=$num2
else
    largest=$num3
fi

# Display the largest number
echo "The largest number is: $largest"
