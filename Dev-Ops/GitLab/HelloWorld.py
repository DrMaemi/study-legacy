class Hello:
    def say(self):
        print("Hello World !")

    def add(self, x, y):
        print("x+y={}".format(x+y))
        return x+y


if __name__ == "__main__":
    h = Hello()
    h.say()
    h.add(2, 3)
