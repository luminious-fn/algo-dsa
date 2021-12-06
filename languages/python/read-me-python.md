# Python Read Me. #

## NEW THINGS FOR ME ##
- python can be released in compile only file. and we can ask python interpreter
to run python compile files instead of source file. read below  
https://docs.python.org/3/tutorial/modules.html#compiled-python-files

- understand standard library: https://docs.python.org/3/library/index.html
- understand all the built-in functions.
    - https://docs.python.org/3/library/functions.html#built-in-functions
    - Builtin functions are most important, available even in pico! 
    - interpreter does import builtin functions for us
        from builtins import *  
        Or, we can do this too if there is a name collision
        import builtins
        builtin.super()
- understand all string class functions.
- to recognize a folder as a package, please keep __init__.py file.
    else, you don't need that file at all.
- string slicing : -ve 
- global and nonlocal keywords
    - if a variable is used without assignment, it is assumed to be global, not local.
    - nonlocal keyword indicates the variable is not local, but exist in a scope just outside
    of the local scope, and, for any reference of that variable, interpret will use it.
- Top level code env or entry point
    - https://docs.python.org/3/library/__main__.html#module-__main__
    - __name__ and '__main__'
    - always try type annotation, even for 
     def main() -> int :
        pass
- map, filter and reduce ?
- decorators 
- forward declaration is not needed in python since no complilation is done.
only during execution, object are referenced and before that, function are created.

- grammar : https://docs.python.org/3/reference/grammar.html
- global variables across modules https://docs.python.org/3/faq/programming.html?highlight=cookbook#id11


## Basic ##
Always start with shebang  
#!/usr/bin/env python3
a comment starts with #  

### Line continuation ###
: when we add \ at the end of a line, line will continue to 
first column of the next line.  
Triple quoted string also continue to next line, but they
include the newline that comes at the end of each line. If we want to avoid this
we have to use line continuation marker \ as said above.
More here: 
https://docs.python.org/3/tutorial/introduction.html

python -m module_name will execute the module_name.py as script
if module name is dir, it will execute __main__.py script in that dir.
https://docs.python.org/3/using/cmdline.html#cmdoption-u

## built-in functions ##
- len( iterator_object) : give length of the iterator
- range()
- list()
- sorted() # out-of-place sorting. gives new seq?
- reversed() # just reverse order of sequence.

- set() or {} but with values separated by commas. See dict's {}
# create a new set (remove duplicates)
    - sorted(set(seq)) # ordered iteration of unique
- list(seq) or []
- dict((k:v), (k:y)) or {}
- tuple() or ()

- var() # dict of all local var()

## keywords ##
- Operators : `in`, `not in`, `is`, `is not`
- Boolen Operators : and, or, not 
    They are called short circuit operator because, they are evaluated 
    from left to right and it stops as soon as outcome is determined.
- Walrus Operator : := assignment inside an expression, not inside a statement
- statements: global, nonlocal 

Comparioson operators > < >= <= != ==
for while del

## strings ##
- https://docs.python.org/3/tutorial/introduction.html
- sequence type, immutable
- 'hello', "hello", '''hello''', """hello"""
- \ can be used define multiline string or multiline code.
- two strings side by side will be concatenated automatically
- string enclosed in parentheses will be concatenated  
x = ('a',
    'b',
    'c')
x = 'abc'
- string slicing supported to get substring
    - x[5:7]
    - x[start_included:end_excluded] # always move forward
    start_included : 0 default,  
      end_excluded : length of string + 1
      x[-2:] # from last second till end of string, included
      s[:i] + s[i:] = s # understand this.

- string indexing supported str[5], str[-5]
- raw strings starts with r
- format strings starts with f
- raw and format strings starts with rf

## List ##
l = [a, b, c]
- comma separated items with a brackets
- sequence type, mutable
- slicing
    - slicing returns a shallow new copy of original list.
    - slicing can be assigned
        - l[2:5] = ['a', 'b', 'c'] # replace 2,3,4
        - l[2:5] = [] # remove 2,3,4
        - l[:]  = [] # clear the list !
- + concatenates and gives new list
- list.append() will append to existing list at the end.
- len(list) gives the number of items in the list.

questions = ['name', 'quest', 'favorite color']
answers = ['lancelot', 'the holy grail', 'blue']
for q, a in zip(questions, answers):
    print(f'{q} {a}')


## control flow ##
Eef: https://docs.python.org/3/tutorial/controlflow.html
- 
if expression:
    pass
elif expression:
    pass
else:
    pass

- 
for items in iterator:
    pass
    break # or 
    continue
else:
    # this gets executed if there is no break above
    pass

Note: item itself can be a list
for a,b,c,d in iterator
    pass

- pass statement
    - it does nothing except to satisfy syntax rules
    - It  will be handy when we want to have a statements but we are not sure, so
        we just keep pass
    - 
- match statement
    - ref: https://docs.python.org/3/tutorial/controlflow.html
    match expression:
        case expression1:
            statements
        case expression2:
            stmt2
        case _:
            stmt3

## defining functions ##
Ref: https://docs.python.org/3/tutorial/controlflow.html

function arguments are always passed by "call by object reference" method.

`def` introduces a function definition.
first line of function can be (good practice) a doc string
a function always return None if no return statement is present or if simply a 
`return` is placed

- default argument
    my_lang = ['c', 'c++', 'python' ]
    - def my_function(name, age=40, children = 2, education = my_lang ):
        my_lang.append('javascript')
        my_lang.append('HTML')

    - default values are evaluated only once when function object is created.
    Thus, whatever value we give, it remains forever. but if the value itself a 
    reference to a mutable object, the object persists and keeps changing as per 
    your code.

    - keyword arguments

def fun(pos1, pos2, *pos3_variable_arg, **dict_args):
    print(f'{pos1=} {pos2}')
    
    for item in pos3_variable_arg:
        print(item)

    for k,v in dict_args:
        print(f'{k} : {v}')

https://docs.python.org/3/tutorial/controlflow.html
def fun(pos1, pos2, /, pos_or_kwd1, *, k_wd1, k_wd2):
- only positional args before /
- pos or kw after / but before *
- only KW args after *
- always / needs to be given, it should be given before *
- / and *, both are optional. any one can be given.

read from python manual
When a final formal parameter of the form **name is present, it receives a dictionary (see Mapping Types — dict) containing all keyword arguments except for those corresponding to a formal parameter. This may be combined with a formal parameter of the form *name (described in the next subsection) which receives a tuple containing the positional arguments beyond the formal parameter list. (*name must occur before **name.) For example, if we define a function like this:
def cheeseshop(kind, *arguments, **keywords):
    print("-- Do you have any", kind, "?")
    print("-- I'm sorry, we're all out of", kind)
    for arg in arguments:
        print(arg)
    print("-" * 40)
    for kw in keywords:
        print(kw, ":", keywords[kw])


```python 
# also *tuple, **dict can appear in function definition.

def f(pos1, pos2, /, pos_or_kwd, *, kwd1, kwd2):
      -----------    ----------     ----------
        |             |                  |
        |        Positional or keyword   |
        |                                - Keyword only
         -- Positional only

>>> def standard_arg(arg):
...     print(arg)
...
>>> def pos_only_arg(arg, /):
...     print(arg)
...
>>> def kwd_only_arg(*, arg):
...     print(arg)
...
>>> def combined_example(pos_only, /, standard, *, kwd_only):
...     print(pos_only, standard, kwd_only)
```

## 4.8.6 Lambda Expressions ## 
- https://docs.python.org/3/tutorial/controlflow.html#lambda-expressions


### docstrings ###
- https://docs.python.org/3/tutorial/controlflow.html#documentation-strings
- Do not exceed 79th column in text editor.
- use 4 space indentation

docstring is available as __doc__ attribute binding to any object.

single line doc string
def fib():
    """generates the fib numbers"""

multiline doc string
def fib():
    """generates the fib numbers
    LEAVE A BLANK LINE
    it indeed prints all fib numbers to screen.
    """

print(fib.__doc__) has above string.

Similarly for module: first (second line due to shebang) line of module.
same is for class

class class_name:
""" this is doc string. """
    def __init__(self):
        pass

### 4.8.8 Function annotation ###
- https://docs.python.org/3/tutorial/controlflow.html#function-annotations
### 4.9 coding style ###
- https://docs.python.org/3/tutorial/controlflow.html#intermezzo-coding-style



# 4. More Control Flow Tools¶ #
## 4.1 if statement ##
## 4.2 for statements ##
## 4.3 range() ##
## 4.4 break and continue, else clause on loops ##


## 5.2. The del statement¶ ##
del will delete a variable or a slice of list.
But it will not return any value. Hence, it is different from 
functions like pop(), which return a value.
del my_list[:] # delete all elements in my_list. but my_list is not deleted
del my_list # now my_list is deleted, hence its all elements too.

## 5.3. Tuples and Sequences ##
Tuples are immutable sequences.
my_tuple_0 = () # empty tuple
my_tupe_1 = ('name', ) # single item tuple. Add a trailing command
my_tuple_2 = 'name',  # round brackets are assumed

Sequence packing and unpacking is a python idiomatic programming.
I think, it can be used for 

tuple comprehension
my_tuple = ( i for in range(100))
supports indexing []. slicing, but slicing creates new tuple.

## 5.4. Sets ##
set are unordered, no duplicate sequence. It uses curly brackets { }.
Note: curly brackets are also used by dict, but the context determines.
ie, 
if curly brackets contains key:value and command, it is dict
if curly brackets contains value, it is set!

my_set = set() # empty set, do not use { }, because, it is reserved for dict
my_set  = { '1', '2', '2'}
supports & , |, -, ^ [] set operations!

set comprehension
my_set = {i for in range(100)}


## 5.5. Dictionaries¶  ##
https://docs.python.org/3/tutorial/datastructures.html#dictionaries

They are similar to Associative memories or associated arrays.
Dictionaries are indexed by immutable strings or numbers.
A Dictionary is a set of key:value pair sepeated by comma inside curly brackets { }
keys must be unique.

function dict will create a dict from a sequence of k:v pair
d = dict([(1:1), (3:9), ]) 
if keys are string
d = dict(k1=1, k2=5, k3 = 7)
dict comprehnsion 
d = { k:k**2 for k in range(10)}

looping 
for k, v in d.items()
    print(f'{k}:{v}')

for i, v in enumerate(['tic', 'tac', 'toe']):
    print(i, v)

questions = ['name', 'quest', 'favorite color']
    answers = ['lancelot', 'the holy grail', 'blue']
    for q, a in zip(questions, answers):
        print('What is your {0}?  It is {1}.'.format(q, a))

## 5.7. More on Conditions ##
https://docs.python.org/3/tutorial/datastructures.html#more-on-conditions

- comparisons can be chained as in natural language.

# Modules #
https://docs.python.org/3/tutorial/modules.html

A script is a text file which acts is main input to the (python)
interpreter

A module is a file containing python definitions and statements.
main module is the one that is executed at top level.
each module name is avaialble within the module as __name__ global variable.

modules can be imported into other modules using `import`.
module has its own private symbol table.

import module.py

to import just some names into current module
from module_name import name1, name2, name3 

to import all names into current module except the names
that start with _
from module_name import *
However, avoid using this as it is bad idea!

also `as` is used 

TODO: a module if imported twice, does it get improted again?
no, it seems. for this, use

To re-import a module
import importlib
importlib.reload(module_name)


if we run python module as 
python module.py <args>
the __name__ will not set to the "module" but to __main__

ie, it is running as top level module, hence __name__ will not 
contiant the file name but __main__
This is designed to use a module as a stand alone script as well
a importable module 
using  following construct
This is used for testing (test suite) purpose to test individual modules.

if __name__ == "__main__":
    import sys
    statements etc.

### 6.1.2 The module search path ###
search path is as per the value in 
sys.path = 
    current dir.
    PYTHONPATH (this is similar to bash PATH)
    site-package directory handled by site module TODO
So, sys.path init at the start, if we need a change after script is running
we should modify sys.path, not the PYTHONPATH or site-packages etc.



### 6.1.3. “Compiled” Python files¶
https://docs.python.org/3/tutorial/modules.html
Python interpreter will compile the source file to .pyc before running.
suc .pyc files are stored in ./__pychace__ folder.

On any subsequent run of the same files, python first looks into .pyc file,
if its date is same as actual src file, compiled file will be use, instead of 
src file.

Further, if the .pyc file is present in the src directory, Python will not 
load at all the actual .py file. It always loads the .pyc file. This means,
for compiled only distribution, we can remove actual src file and distibute the 
.pyc files only. as .pyc files are platform independent, we dont need to worry on 
this.
the module compileall can explicitly compile files to .pyc

Please read this : https://docs.python.org/3/tutorial/modules.html#compiled-python-files



## 6.2. Standard Modules¶
sys

To print all names (private global symbols of a module) lists all types of names: 
variables, modules, functions, etc.
dir(loaded_module_name) 

import builtin # all built in functions like dict(), list()
dir(builtins)


## 6.4. Packages
https://docs.python.org/3/tutorial/modules.html#packages
Python module namespaces are provided by Python packages. 
They are structured using doted module name like A.B.C

Loosely speaking.
Python module = a python file!
Python package = A directory of many python files!

A directory to be treated as a python package must contain a file called
__init__.py. This file can be empty but can also contain some init code if needed.

how to import a module from a package - there are many ways
import module
from package import item

import a.b.c
# to use a.b.c.function()
from a.b import c
# c.function()
from a.b.c import function
# function()

So, from statement make the name available without full path
but if we use plain import statement, we must use full path.

from package import * # is bad bad practice!

Recommended way to import a python module is
from package import specific_submodule

next, better way is import module.
I like latter!!!

### 6.4.2. Intra-package References¶
OR relative import 
https://docs.python.org/3/tutorial/modules.html#intra-package-references

from . import item
from .. import item
from ..module_pkg import item



# 7. Input and Output¶ #
https://docs.python.org/3/tutorial/inputoutput.html

- format strings literals example
    - f'... {expression:n.m} ...'
    - if n is positive, it is right justified, -ve positive Justified TODO!

- str.format(arguments): This can take a dict of key_value to be formatted. This
is an powerful option to concisely format some strings!
    - str.rjust(), ljust(), center(), zfill()
- string.Template use $x place holder!

## 7.2. Reading and Writing Files
file_obj = open(filename:str, mode:str)
mode: r: read, w: write, a: append, r+ read+write
if we append b to it, it is binary mode. USe binary mode for all non-text files.

with open('my_file', 'w') as file_obj:
    read_data = file_obj.read()

With is the context manager for open() functions.

f.read(size:int), if size is omitted, it reads entire file into memory!
returns empty string '' if file pointer is reached EOF.
f.readline(): reads a until it hits a \n
if EOF reached , returns empty string ''

file object is an iterator based on newline.
for line in file_object:
    print(line)

for all lines
my_file_list = list(file_object)
str = f.readlines()

f.write(string or byte object)
string for text mode, byte_object for binary mode.


f.tell()
    - tell the current position in bytes for Binary files, a n opaque number for 
        text files.
f.seek(offset:int, whence:int)
    whence : 0: start of file
             1: current position
             2: end of file.
        

## 7.2. Reading and Writing Files
Python Object  --> string =   serializing 
string --> Python object  =de-serializing

my_list = ['a', 'b', 'c']
json.dump(my_list, file_object)
json.dumps(my_list)
my_list = json.load(file_object)

pickle is another module specific to python. but JSON is generic.

# 8. Errors and Exceptions #
Exception is an error that occurs while executing a line.
They are not syntax error.

try:
    print('hello world')
except Exception as ex:
    print(f'caught exception {ex}')
    exit(1)
else:
    print('this will execute if no exception occurred')
finally:
    print('this always gets executed')


# 9. Classes #

https://docs.python.org/3/tutorial/classes.html
https://www.codesdope.com/course/python-subclass-of-a-class/

parent class = super class = base class
child class  = sub class   = derived class 

To bundle data and its functionality together, we use classes.

anything that follows dot (.) is an attribute.

A scope is a textual region of a Python program where a namespace is directly accessible. “Directly accessible” here means that an unqualified reference to a name attempts to find the name in the namespace.

class class_name(base1, base2, base3):
    def __init__(self):
        pass

class has attributes : data and methods

method object Vs function object
    - Method Objects =  function objects binded to a class instance.  They bind to an object.
    hence, they always implicitly passed the object as first arg.
    -

obj.__class__ contain the class name.
isinstance(class_object, class)
issubclass(subclass, superclass)

## 9.8. Iterators ##
https://docs.python.org/3/tutorial/classes.html#iterators

## 9.9. Generators ##
https://docs.python.org/3/tutorial/classes.html#generators
## 9.10 Generator expressions ##
https://docs.python.org/3/tutorial/classes.html#generator-expressions


## References ##
- https://docs.python-guide.org/
- https://docs.python.org/3/faq/programming.html#id1
- https://docs.python.org/3/faq/index.html
- https://docs.python.org/3/faq/design.html#why-can-t-i-use-an-assignment-in-an-expression

## coroutine ##
- https://realpython.com/async-io-python/
- 
