This is the readme for Forest, a running platform designed to help runners find people to run with.

Installation:

- Install node
- Install npm
- Install express: npm install express --save
- Install express-handlebars: npm install express-handlebars --save


To run the database file on Windows:
g++ db.cpp -o db.exe -std=c++11

Then run the exe file with ./db.exe

The executable will be waiting for input from the user. You can input an event in the following format:

title|longitude|latitude|pace

The following restrictions apply:
- There must be no spaces in the string entered (including in the "title" field)
- The longitude and latitude must be strings corresponding to valid signed single-precision floats
- The pace must be the string representation of an integer
- WARNING: Some values of longitude/latitude currently result in segmentation faults.
