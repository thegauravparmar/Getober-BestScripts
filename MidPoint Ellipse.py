# Python Script for Mid-Point Ellipse Drawing Algorithm.
import matplotlib.pyplot as plt
plt.title("Mid-Point Ellipse Algorithm")
plt.xlabel("X Axis")
plt.ylabel("Y Axis")


def midptellipse(rx, ry, xc, yc):

    x = 0
    y = ry

    # Initial decision parameter of region 1
    d1 = ((ry * ry) - (rx * rx * ry) +
                      (0.25 * rx * rx))
    dx = 2 * ry * ry * x
    dy = 2 * rx * rx * y


    xcoordinates = [x]
    ycoordinates = [y]


    # For region 1
    while (dx < dy):

        # Print points based on 4-way symmetry

        xcoordinates.append(x + xc)
        ycoordinates.append(y + yc)

        xcoordinates.append(-x + xc)
        ycoordinates.append(y + yc)

        xcoordinates.append(x + xc)
        ycoordinates.append(-y + yc)

        xcoordinates.append(-x + xc)
        ycoordinates.append(-y + yc)



        print("(", x + xc, ",", y + yc, ")")
        print("(", -x + xc, ",", y + yc, ")")
        print("(", x + xc, ",", -y + yc, ")")
        print("(", -x + xc, ",", -y + yc, ")")

        # Checking and updating value of
        # decision parameter based on algorithm
        if (d1 < 0):
            x += 1
            dx = dx + (2 * ry * ry)
            d1 = d1 + dx + (ry * ry)
        else:
            x += 1
            y -= 1
            dx = dx + (2 * ry * ry)
            dy = dy - (2 * rx * rx)
            d1 = d1 + dx - dy + (ry * ry)

    # Decision parameter of region 2
    d2 = (((ry * ry) * ((x + 0.5) * (x + 0.5))) +
          ((rx * rx) * ((y - 1) * (y - 1))) -
          (rx * rx * ry * ry))

    # Plotting points of region 2
    while (y >= 0):


        xcoordinates.append(x + xc)
        ycoordinates.append(y + yc)

        xcoordinates.append(-x + xc)
        ycoordinates.append(y + yc)

        xcoordinates.append(x + xc)
        ycoordinates.append(-y + yc)

        xcoordinates.append(-x + xc)
        ycoordinates.append(-y + yc)


        # printing points based on 4-way symmetry
        print("(", x + xc, ",", y + yc, ")")
        print("(", -x + xc, ",", y + yc, ")")
        print("(", x + xc, ",", -y + yc, ")")
        print("(", -x + xc, ",", -y + yc, ")")

        # Checking and updating parameter
        # value based on algorithm
        if (d2 > 0):
            y -= 1
            dy = dy - (2 * rx * rx)
            d2 = d2 + (rx * rx) - dy
        else:
            y -= 1
            x += 1
            dx = dx + (2 * ry * ry)
            dy = dy - (2 * rx * rx)
            d2 = d2 + dx - dy + (rx * rx)

    plt.plot(ycoordinates, xcoordinates)
    plt.show()





def main():
    x1 = int(input("Enter the lenght of major axis: "))
    y1 = int(input("Enter the length of minor axis: "))
    x2 = int(input("Enter the center coordinate of x: "))
    y2 = int(input("Enter the center coordinate of y: "))

    midptellipse(x1, y1, x2, y2)
   


if __name__ == "__main__":
    main()














































# import matplotlib.pyplot as plt
# plt.title("Bresenham Algorithm")
# plt.xlabel("X Axis")
# plt.ylabel("Y Axis")


# def bres(x1, y1, x2, y2):
#     x, y = x1, y1
#     dx = abs(x2 - x1)
#     dy = abs(y2 - y1)
#     gradient = dy/float(dx)

#     if gradient > 1:
#         dx, dy = dy, dx
#         x, y = y, x
#         x1, y1 = y1, x1
#         x2, y2 = y2, x2

#     p = 2*dy - dx
#     print(f"x = {x}, y = {y}")
#     # Initialize the plotting points
#     xcoordinates = [x]
#     ycoordinates = [y]

#     for k in range(2, dx + 2):
#         if p > 0:
#             y = y + 1 if y < y2 else y - 1
#             p = p + 2 * (dy - dx)
#         else:
#             p = p + 2 * dy

#         x = x + 1 if x < x2 else x - 1

#         print(f"x = {x}, y = {y}")
#         xcoordinates.append(x)
#         ycoordinates.append(y)

#     plt.plot(xcoordinates, ycoordinates)
#     plt.show()


# def main():
#     x1 = int(input("Enter the Starting point of x: "))
#     y1 = int(input("Enter the Starting point of y: "))
#     x2 = int(input("Enter the end point of x: "))
#     y2 = int(input("Enter the end point of y: "))

#     bres(x1, y1, x2, y2)


# if __name__ == "__main__":
#     main()
