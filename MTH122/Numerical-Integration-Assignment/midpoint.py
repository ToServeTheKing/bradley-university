#midpoint.py
from numpy import sin

def function(x):
    return sin(x*x)

def midpoint(a, b, n):
    deltaX = (b - a) / n
    deltaXValues = []
    integral = 0

    for i in range (n+1):
        xSubscriptI = round((a + i * deltaX),5)
        deltaXValues.append(xSubscriptI)

    for i in range (n):
        input = (deltaXValues[i] + deltaXValues[i + 1]) / 2
        integral += function(input)

    return integral * deltaX