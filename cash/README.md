<h1> Cash </h1>

This program calculates the number of coins to be given for a given amount of cents owed. The user inputs the number of cents owed, and the program calculates the number of quarters, dimes, nickels, and pennies to be given to the customer to make the correct change.

The program is implemented using several functions: get_cents, calculate_quarters, calculate_dimes, calculate_nickels, and calculate_pennies.

The get_cents function prompts the user to input the number of cents owed and ensures that the input is a positive integer.

The calculate_quarters, calculate_dimes, calculate_nickels, and calculate_pennies functions each calculate the number of coins of the given type to be given to the customer based on the amount of cents owed. These functions use a while loop to subtract the appropriate amount of cents for each coin type until there are no more cents left to give.

Finally, the program sums the number of coins and outputs the total number of coins to be given to the customer.

This program is a simple example of using functions and loops in C to perform a common task.


<h2>Implementation details </h2>

+ Implement <code>get_cents</code> in such a way that the function prompts the user for a number of cents using <code>get_int</code> and then returns that number as an <code>int</code>. If the user inputs a negative <code>int</code>, your code should prompt the user again. 
+ Implement <code>calculate_quarters</code> in such a way that the function calculates (and returns as an <code>int</code>) how many quarters a customer should be given if they’re owed some number of cents. For instance, if cents is 25, then <code>calculate_quarters</code> should return 1. If cents is 26 or 49 (or anything in between, then <code>calculate_quarters</code> should also return 1. If cents is 50 or 74 (or anything in between), then <code>calculate_quarters</code> should return 2. And so forth.
+ Implement <code>calculate_dimes</code> in such a way that the function calculates the same for dimes.
+ Implement <code> calculate_nickels</code> in such a way that the function calculates the same for nickels.
+ Implement <code> calculate_pennies</code> in such a way that the function calculates the same for pennies.