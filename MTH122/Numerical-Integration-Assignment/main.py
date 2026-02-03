from tabulate import tabulate
from trap import trap as t
from midpoint import midpoint as m
from simpson import simpson as s

l = [[10,  t(0, 4, 10), m(0, 4, 10), s(0, 4, 10)],
     [20,  t(0, 4, 20), m(0, 4, 20), s(0, 4, 20)],
     [40,  t(0, 4, 40), m(0, 4, 40), s(0, 4, 40)],
     [80,  t(0, 4, 80), m(0, 4, 80), s(0, 4, 80)],
     [100, t(0, 4, 100), m(0, 4, 100), s(0, 4, 100)],
    ]

print(tabulate(l, headers=['n', 'trapezoidal', 'midpoint', 'simpsons'], tablefmt='orgtbl'))