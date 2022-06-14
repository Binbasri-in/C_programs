# The File Extension Detector
#### Video Demo:  https://youtu.be/mXDPioqSA8k
#### Description:
TODO
A command-line program its purpose is to take a filename with its extension and with some process it output
the information about that extension and for what its used to. The whole program contains two files:

1. The CSV file that contains all the data about the files extensions represented as a 2D array with rows and colunms,
    where each row contains all the information about a single extension. The information provided are the short name of
    the extension for searching purposes, the full name of the extension, the Genre of this extension whither its for videos, audios, document
    or e-books, also the usage of this extension and why they use it, and the operating systems that support this extension, and lastly a link to the file-extension
    .org web site where the user can find detailed information about the provided extenstion, At the end all the data in this CSV file are from:

    https://www.file-extensions.org/

2. the C file that contaains the code for this program, this program has three main way to execute it using different command-line arguments:

    - the command-line argument "help" this show the user how to use this program and what exactly its work, it provide them a short explaination
      of the program and what other command-line arguments it take.

    - the command-line argument "add" by this command user have the ability to add a new row at the end of the CSV file in a specific order and style
        all explaind in the "help" section so it is nessecery to see the "help" command-line argument before using this program to know exsactlly what it does.

    - the main job of this program which is done by giving the filename as a command-line argument as an input, and then creat a linked list
        of all the data stored in the CSV file to itreate and search in it easily to find our extension.

    - the program take the requested extension from the file name and then process it through the linked list looking for a match and when its found
        the program print out all the available information about this extension or if its not found the program print out the place where you can
        make a deeper search in the world of file extensions through file-extensions.org website.

    - the program uses linked list to store all the data of the CSV file and read the and allocate memory dynamicly to achieve faster and dynamic searching program
        to be able to use it very fast and easily without and complexity.

The idea of this program came from my experiance at my project management work with Hadramout Foundation when one of the staff sent me the Budget in the
form of numbers which is a spreadsheet program for MacOS, and I was confused and it put me in an embaressed situation so I came up with this idea to solve
my own problem that other people could face it oneday espicially when the file extension numbers are growing very fast and it became very hard to know all of them.
