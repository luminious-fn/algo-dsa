

compiler -> linker  -> executable     -> loader
 scope   -> linkage -> code, data(bss)-> code, data, stack, heap 

- declaration 
    declaration_specifiers = storage_class_specifier type_qualifier modifier type_specifier 
    storage_class_specifier : extern, static, auto, register, mutable
    type_qualifier : const, volatile
    modifier : signed, unsigned, long, short
    type_specifier: void, bool, char, short, int, long, float, double, struct, union, enum 

- scope
    - is a region of program where a variable or function is visible. There are two scopes
    - local scope and global scope.
    - This is used doing complilation time
- linkage
    - it is about linking of files.
    - when linker is linking translation units, it links an identifier from one file to another.
    as per their scope. so, global scoped are linked across all files, but rest are with local scopes.
    - internal linkage, external linkage, none linkage.


- operator precedence and associativty
    - associtive is about how an operator binds to operand: 
    - if it left to right associate means, operator first binds to left side operand even though it has an operand
    at right side. if it needs one more operand, then it binds right side. Even, evaluation too happens on what binds
    first before evaluation of the later binded variable.
    - z = (a == b ? a : b ? c : d);
    - since above ?: operator is right to left associative, first ?: operator goes to group and evauate the right side operand
    so, right side oprand of first ?: is b?c:d so, this is grouped. but know that, just grouping happend.
    evaluation will not happen due to fact that ?: operator first evulates the first operand due to extra and special rule of 
    conditional operator. so, the 
    z =  a == (b ? a : (b ? c : d)); // and  NOT (a == b) ? a : (b ? c : d)  This is when if C wanted left to right evaluation for ?: 
    - https://stackoverflow.com/questions/7407273/why-is-the-conditional-operator-right-associative



- TODO
    - learn move semantic
- storage class
    - A storage class defines the scope (visibility) and life-time of variables and/or functions within a C++ Program.
    - auto, register, static, extern, mutable
- lvalue and rvalue
    - https://www.internalpointers.com/post/understanding-meaning-lvalues-and-rvalues-c
    - lvalue is a container, i.e., it is a memory address.
    - rvalue is a thing in container. Here address does not matter. only value matters.
    It is the data stored at some memory location.
    - lvalue can appear on right hand side or left hand side of an = operator.
    - int *y = &x; // x is lvalue, &x is rvalue. y is lvalue.
    - = require full lvalue expression at left side; full rvalue expression at right side.
    - a variable name itself is a lvalue expression. however, there is implicit
    lvalue-to-rvalue conversion happens at many places.
    - c++ implicitly creates a reference to constat rvalue. 
        - int &ref = 100;
        - const int& ref = 10;

 - reference Vs Pointers
    -reference are aliases to existing varible (= memory location).
    - alias can not refere to  nul object like pointer
    - once alias is init, it can't be changed,
    - functions can return alieas, thus can  make function as lvalue.

- smart pointer
    - https://www.internalpointers.com/post/beginner-s-look-smart-pointers-modern-c
    - https://www.educative.io/edpresso/what-are-smart-pointers
    