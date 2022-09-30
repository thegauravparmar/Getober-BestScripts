from sympy import Intersection


# Python Script to Find the Intersection or Union of Two Rectangles.
from turtle import left, up
import cv2 as cv
import numpy as np


blank = np.zeros((700,700,3), dtype='uint8')


input_x1, input_y1 = [int(x) for x in input("Enter the x and y coordinate of 1st diagonal of first rectangle: ").split()]
input_x2, input_y2 = [int(x) for x in input("Enter the x and y coordinate of 2nd diagonal of first rectangle: ").split()]



input_x3, input_y3 = [int(x) for x in input("Enter the x and y coordinate of 1st diagonal of second rectangle:  ").split()]
input_x4, input_y4 = [int(x) for x in input("Enter the x and y coordinate of 2nd diagonal of second rectangle:").split()]

print()

cv.putText(blank, 'Input', (blank.shape[1]//2,50), cv.FONT_HERSHEY_TRIPLEX, 1.0, (255,255, 255), 1)
cv.rectangle(blank, (input_x1,input_y1), (input_x2,input_y2), (0,255,0), thickness=4)
cv.rectangle(blank, (input_x3,input_y3), (input_x4,input_y4), (255,0,0), thickness=4)

cv.imshow("Input", blank)

new_blank = np.zeros((700,700,3), dtype='uint8')
cv.putText(new_blank, 'Output', (new_blank.shape[1]//2,50), cv.FONT_HERSHEY_TRIPLEX, 1.0, (255,255, 255), 1)



x5 = max(input_x1, input_x3)
y5 = max(input_y1, input_y3)
x6 = min(input_x2, input_x4)
y6 = min(input_y2, input_y4)
cv.rectangle(new_blank, (x5,y5), (x6,y6), (0,255,0), thickness=4)

cv.imshow('Assignment-1: Computer Graphics Lab', new_blank)

cv.waitKey(0)
cv.destroyAllWindows()