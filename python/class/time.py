class Time:
    def __init__(self, hour, minute, second):
        self.__hour = hour
        self.__minute = minute
        self.__second = second
    
    def __add__(self, other):
        s = self.__second + other.__second
        m = self.__minute + other.__minute
        h = self.__hour + other.__hour
        if s >= 60:
            s %= 60
            m += 1
        if m >= 60:
            m %= 60
            h += 1
        if h >= 24:
            h %= 24
        
        return Time(h, m, s)

    def display(self):
        print(f"{self.__hour:02d}:{self.__minute:02d}:{self.__second:02d}")

t1 = Time(12, 42, 37)
t2 = Time(12, 22, 59)
t = t1 + t2
t.display()

