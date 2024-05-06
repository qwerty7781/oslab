#!/bin/bash

# Function to calculate factorial
factorial() {
    if [ $1 -eq 0 ]; then
        echo 1
    else
        local result=1
        for ((i = 1; i <= $1; i++)); do
            result=$((result * i))
        done
        echo $result
    fi
}

# Prompt the user to enter a number
echo "Enter a number:"
read num

# Call the factorial function with the input number
result=$(factorial $num)

# Display the result
echo "The factorial of $num is: $result"
