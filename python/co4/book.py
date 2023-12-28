class Publisher:
    def __init__(self, name):
        self.name = name
    
    def display(self):
        print(f"Publisher: {self.name}")

class Book(Publisher):
    def __init__(self, name, title, author):
        
        # Base class constructor invocation
        super().__init__(name)
        self.title = title
        self.author = author
    
    # Method overriding
    def display(self):
        print(f"{self.title}, written by {self.author}")
        super().display()
    
            
class Python(Book):
    def __init__(self, name, title, author,  price, no_of_pages):
        super().__init__(name, title, author)
        self.price = price
        self.no_of_pages = no_of_pages
    
    def display(self):
        super().display()
        print(f"Price: ${self.price}\n{self.no_of_pages} pages")

book = Python(name="CET", title="Programming", author="Joe", price=29.99, no_of_pages=249)
book.display()