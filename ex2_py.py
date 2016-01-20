# Python 3.3.3 and 2.7.6
# python helloworld_python.py

from threading import Thread, Lock

i = 0

lock = Lock()
def threadAdder():
    global i
    for x in range(1000000):
        lock.acquire()
        try:
            i += 1
        finally:
            lock.release()

def threadSubtractor():
    global i
    for x in range(999999):
        lock.acquire()
        try:
            i -= 1
        finally:
            lock.release()

def main():
    adder = Thread(target = threadAdder, args = (),)
    subtractor = Thread(target = threadSubtractor, args = (),)

    adder.start()
    subtractor.start()

    adder.join()
    subtractor.join()

    print(i)


main()
