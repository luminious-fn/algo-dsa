
# FAQ #

## strlen() vs sizeof() ##
strlen() return leng of string excluding last null char. It is runtime calculation.
sizeof() is a compile time unary operator. It tells size of the type (=variable) computed during compilation. 
So, for string, if they are stored in static arrays, even null byte is included in sizeof() computation.
