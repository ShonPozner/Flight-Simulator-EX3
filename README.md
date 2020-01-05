# Flight-Simulator EX3
![fly](https://user-images.githubusercontent.com/59409570/71785140-c4530900-3004-11ea-8c6d-ce46b3becf18.jpg)

**Flight simulator - Ex3 -** Advanced Programming at Bar Ilan created by **Shon Pozner**

* gethub [Linke](https://github.com/ShonPozner/Flight-Simulator-EX3)

# The project's aim:

* **Lexer and parser** text file, that containing various commands for a flight simulator.
* Transferring information from and to flight simulator using **server and client**.

### Technologies:

* The project articles in language **C++ ver14**
* The project is optimized for working with the flight simulator- **FlightGear**
 [link to downoad](http://home.flightgear.org)

### Launch - how to run the project:

##### Creat the simulator:
* The simulator must first be **downloaded** (again [link](http://home.flightgear.org)).
* Than you need to add from **setting command**, request to open a server and clint.
* copy this **commands** to the setting command:
      ```sh
     --telnet=socket,in,10,127.0.0.1,5402,tcp
     --generic=socket,out,10,127.0.0.1,5400,tcp,generic_small
      ```

##### Now is the time to run this project:
* The **compile** command is -
    ```sh
    $ g++‬‬ ‫‪-std=c++14‬‬ */*.cpp ‫‪*.cpp‬‬ ‫‪-Wall‬‬ ‫‪-Wextra‬‬ ‫‪-Wshadow‬‬ ‫‪-Wnon-virtual-dtor‬‬ ‫‪-ped antic‬‬ ‫ ‪-o‬‬a.out-pthread"
    ````
* To **run** the code -
    ```sh
    $ ./a.out fly.txt  (you can Choose a different txt file)
    ````
* Now you see that the program is **waiting** for a cline
* And this is the right time to **start the simulator**
* Click on the start and **let the fun begin** 

‬
