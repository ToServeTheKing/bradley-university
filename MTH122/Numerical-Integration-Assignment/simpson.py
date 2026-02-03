#simpson.py
from numpy import sin

def function(x):
    return sin(x*x)

def multiple(m, n):
    return True if m % n == 0 else False

def simpson(a, b, n):
    deltaX = (b - a) / n
    deltaXValues = []
    integral = 0

    for i in range (n+1):
        xSubscriptI = round((a + i * deltaX),5)
        deltaXValues.append(xSubscriptI)

    i = 0
    for i in range (n+1):
        if i == 0 or i == n:
            integral += function(deltaXValues[i])
        elif multiple(i, 2) == True:
            integral = integral + (2 * function(deltaXValues[i]))
        else:
            integral = integral + (4 * function(deltaXValues[i]))
    
    integral = (deltaX/3) * integral
    return integral