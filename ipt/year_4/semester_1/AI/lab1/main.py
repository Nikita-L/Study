import numpy as np
import random
import matplotlib.pyplot as plt


def main():
    my_data = np.genfromtxt('data/data09.csv', delimiter=';')
    w1 = random.uniform(0., 1.)
    w2 = random.uniform(0., 1.)
    w0 = 1

    n = 0.01
    err = 0

    for i in range(0, 50000):
        k = random.randint(0, 79)
        y = w1 * my_data[k][0] + w2 * my_data[k][1] + w0
        if y < 0:
            y = 0
        else:
            y = 1

        if y != my_data[k][2]:
            w1 = w1 + n * (my_data[k][2] - y) * my_data[k][0]
            w2 = w2 + n * (my_data[k][2] - y) * my_data[k][1]
            w0 = w0 + n * (my_data[k][2] - y) * 1

    for j in range(80, 100):
        y = w1 * my_data[j][0] + w2 * my_data[j][1] + w0
        if y < 0:
            y = 0
        else:
            y = 1
        if y != my_data[j][2]:
            err = err + 1

    t = np.arange(0.0, 1.0, 0.1)

    zerox1_x2 = np.empty((20, 2))
    onex1_x2 = np.empty((20, 2))

    for k in range(0, 20):
        if my_data[k + 80, 2] == 0:
            zerox1_x2[k, 0] = my_data[k + 80, 0]
            zerox1_x2[k, 1] = my_data[k + 80, 1]
        elif my_data[k + 80, 2] == 1:
            onex1_x2[k, 0] = my_data[k + 80, 0]
            onex1_x2[k, 1] = my_data[k + 80, 1]

    plt.plot(zerox1_x2[:, 0], zerox1_x2[:, 1], 'ro', onex1_x2[:, 0],
             onex1_x2[:, 1], 'bo', t, (-w1 * t - w0) / w2, 'k')
    plt.axis([0, 1., 0, 1.])
    plt.title('Test(Blue) and Train(Red) samples')
    plt.grid(True)
    plt.show()

    print(f"Errors: {err}")
    print(f"w0: {w0}")
    print(f"w1: {w1}")
    print(f"w2: {w2}")


if __name__ == "__main__":
    main()
