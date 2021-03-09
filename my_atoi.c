int my_atoi(char* param_1)
{   
    // Initialize result
    int res = 0;
 
    // Initialize sign as positive
    int sign = 1;
 
    // Initialize index of first digit
    int i = 0;
 
    // If number is negative,
    // then update sign
    if (param_1[0] == '-') {
        sign = -1;
 
        // Also update index of first digit
        i++;
    }
 
    // Iterate through all digits
    // and update the result
    for (; param_1[i] != '\0'; ++i)
        res = res * 10 + param_1[i] - '0';
 
    // Return result with sign
    return sign * res;
}
