class Person:
    def __init__(self, fname, lname):
        self.firstname = fname
        self.lastname = lname
        print("in parents constructor")

    def printname(self):
        print(self.firstname, self.lastname)


class Student(Person):
    def __init__(self, fname, lname, age):
        print("In Student's constructor")
        self.age = age
        super().__init__(fname, lname)

    def __add__(self, obj):
        return self.firstname + obj.firstname, self.lastname + obj.lastname, self.age + obj.age

    def printage(self):
        print(self.age)


x = Student("Mike", "Olsen", 36)
x.printname()
x.printage()

y = Student("John", "Doe", 55)


print(x + y)
