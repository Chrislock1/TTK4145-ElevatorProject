
# Python 3.3.3 and 2.7.6
# python helloworld_python.py

from threading import Thread

i = 0
def threadAdder():
    global i
    for x in range(1000000):
	i += 1

def threadSubtractor():
    global i
    for x in range(1000000):
	i -= 1
# Potentially useful thing:
#   In Python you "import" a global variable, instead of "export"ing it when you declare it
#   (This is probably an effort to make you feel bad about typing the word "global")



def main():
    adder = Thread(target = threadAdder, args = (),)
    subtractor = Thread(target = threadSubtractor, args = (),)

    adder.start()
    subtractor.start()

    adder.join()
    subtractor.join()

    print(i)


main()
