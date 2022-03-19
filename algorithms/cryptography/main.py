# This is a sample Python script.

# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.

def fermats_primality_test(n):
    """ a**(n-1)%n == 1, it is prime. otherwise, it is composite
    a = 2.
    """
    if 1 == (2**(n-1) % n):
        print(f'{n}, ', end = '')
    else:
        print('composite')


# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    #fermats_primality_test(31987937737479355332620068643713101490952335301)
     fermats_primality_test(319879377)


# See PyCharm help at https://www.jetbrains.com/help/pycharm/
