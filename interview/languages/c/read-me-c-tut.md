
# FAQ #
- https://www.code2master.com/category/c/
- https://www.javatpoint.com/c-interview-questions
- https://www.interviewbit.com/c-interview-questions/#parenthesis-checker
- 
- convert string to int atoi(const char *str)
    - can we use ssscanf for this? yes, sscanf scans the string, extacts the fields and put them into
    right variable as per format specifier. so we never need to use sscanf.

    - int number;
      int string = "234";
      sscanf(str, "%d", &number) // put the string into number int variable.
- number can be converted to string
    - snprint(str, format, args) # print the formatted string to str variable as per format
    - snprintf(str, "%d", number) // number will go into string

- strlen() vs sizeof() ##
    strlen() return leng of string excluding last null char. It is runtime calculation.
    sizeof() is a compile time unary operator. It tells size of the type (=variable) computed during compilation. 
    So, for string, if they are stored in static arrays, even null byte is included in sizeof() computation.
- Volatile keyword
    - it is an instruction to compiler not to put the specified object into cpu registers. The
    intension is that, memory may be modified outside the code in question. ie. there may
    be more than one thread of execution which potentially modifies the memory.
    - used for accessing memory shared b/w Signal handlers, Interrupts, I/O memory, multi threaded application
    - Volatile is necessary but not sufficient for variables shared across threads. 
    So, we may need to use mutex or locks along with volatile ...
    -   
- variadic functions
    - https://www.cprogramming.com/tips/tip/do-not-use-printf-without-percent-s-to-print-a-string
    - https://en.cppreference.com/w/c/variadic
    