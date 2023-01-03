# Standard Template Library (STL):

## Why is this important for competitive programmers?

1. Competitive programming is a part of various job interviews & coding contests. And if you’re in one of those environments, you’ll be given a limited amount of time to code your program.
1. So, suppose in your program, you want to resize an array, or sort an array, or search for some element in your array.
1. You will always try to code a function which will execute the above mentioned things, and end up losing a great amount of time. But again, you’ll have a limited amount of time to code your program. Here is where STL becomes useful.

The C++ **STL** ***(Standard Template Library)*** is a powerful set of C++ template classes to provide some general-purpose classes and functions with templates that implement many popular and commonly used algorithms and data structures like vectors, lists, queues, and stacks. It saves you time and energy which you would have spent coding the same things for your use. This helps you reuse these well tested classes and functions for any number of times as per your own needs.

To put this simply, STL is used because it is not a good idea to reinvent something which is already built and can be used to innovate things further. Suppose you go to a company who builds cars, they will not ask you to start from scratch, but to start from where it is left. This is the basic idea behind using STL.

## Components of STL:

We have three components in STL:

1. Containers
1. Algorithm
1. Iterators

Let’s deal with them individually

## Containers:

Container is an object which stores data. We have different containers having their own benefits. These are objects of some template classes, for our use, which can be used just by including this library. You can even customise these template classes.

![](Img_Files\chapter65\CONTAINERS.png)

## Algorithms:

An Algorithm is a procedure to process the data to arrive at a desired outcome. These are sets of instructions which manipulates the input data to arrive at some desired result. In STL, we have already written algorithms, for example, to sort some data structure, or search some element in an array. These algorithms use template functions. 

## Iterators:

Iterators are objects which points to an element in a container. And we handle them very much similarly to a pointer. Their basic job is to connect algorithms to the container and play a vital role in manipulation of the data. 

Iterators are basically used to move through and manipulate the data of a container using an algorithm.

