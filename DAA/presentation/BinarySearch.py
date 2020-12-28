def binary_search(arr, target):
    n = len(arr)
    minimum = 0
    maximum = n-1
    counter = 1

    while True:
        print('\nIteration: ', counter)
        counter += 1
        print('\tmaximum: ', maximum)
        print('\tminimum: ', minimum)
        # If max < min, then stop: target is not present in array. Return -1.
        if (maximum < minimum):
            return -1

        # Compute guess as the average of max and min, rounded down (so that it is an integer).
        guess = round((maximum + minimum) / 2)
        print('\tguess: ', guess)
        print('\tarr[guess]: ', arr[guess])
        print('\ttarget: ', target)

        # If array[guess] equals target, then stop. You found it! Return guess.
        if arr[guess] == target:
            return guess
        # If the guess was too low, that is, array[guess] < target, then set min = guess + 1.
        elif arr[guess] < target:
            minimum = guess + 1
        # Otherwise, the guess was too high. Set max = guess - 1.
        else:
            maximum = guess - 1


if __name__ == "__main__":
    arr = [2, 5, 8, 12, 16, 23, 38, 56, 72, 91]
    arr.sort()
    target = 23

    index = binary_search(arr, target)

    if index == -1:
        print('\nTarget is not present in the array!')
    else:
        print('\nTarget is present at index: ', index)
