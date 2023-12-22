class Publisher:
    def __init__(self, name):
        self.name = name
    
    def display(self):
        print(f"Publisher: {self.name}")

class Book(Publisher):
    def __init__(self, title, author):
        
        # Base class constructor invocation
        super().__init__(name="H&C")
        self.title = title
        self.author = author
    
    # Method overriding
    def display(self):
        print(f"{self.name}, Written by {self.author}, Published by {self.name}")
    
            
class Python(Book):
    def __init__(self, price, no_of_pages):
        super().__init__(title="Python", author="Galileo")
        self.price = price
        self.no_of_pages = no_of_pages
    
    def display(self):
        print(f"Python, Written by {self.author}, Published by {self.name}\nPrice: ${self.price}\n{self.no_of_pages} pages")

book = Python(price=29.99, no_of_pages="249")
book.display()