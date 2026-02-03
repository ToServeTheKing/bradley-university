#trap.py
from numpy import sin

def function(x):
    return sin(x*x)

def trap(a, b, n):
    deltaX = (b  -a) / n
    deltaXValues = []
    integral = 0

    for i in range (n+1):
        xSubscriptI = round((a + i * deltaX),5)
        deltaXValues.append(xSubscriptI)

    for i in range(n+1):
        if i == 0 or i == n:
            integral += function(deltaXValues[i])
        else:
            integral += 2 * function(deltaXValues[i])

    integral = round((deltaX/2) * integral, 7)
    return integral