class List:
    def __init__(self):
        self.list = []

    def add(self, value):
        self.list.append(value)

    def delete(self, index):
        if index >= len(self.list) or index < 0:
            print("Invalid!")
            return
        self.list.pop(index)
    
    def display(self):
        print(self.list)
    
l = List()
while True:
    choice = int(input(("Enter 1 to add, 2 to delete, 3 to display: ")))
    if choice == 1:
        l.add(int(input("Enter the value to insert: ")))
    elif choice == 2:
        l.delete(int(input("Enter the position to delete from: ")))
    elif choice == 3:
        l.display()
        