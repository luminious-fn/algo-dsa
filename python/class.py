
from multimethod import multimethod

class Person():
    def __init__(self, fname, lname):
        self.fname = fname
        self.lname = lname
    @multimethod
    def print_name(self):
        print(f' {self.fname} {self.lname} ')

class Student(Person):
    def __init__(self, fname: str, lname: str, gyear: int) -> None:
        super().__init__(fname, lname)
        self.gyear = gyear

    def print_name(self):
        super().print_name()
        print(f' {self.fname} {self.lname}  {self.gyear}')

    def wlecome(self):
        pass

x = Student('prabhu', 'ullagaddi', '2003')
x.print_name()
