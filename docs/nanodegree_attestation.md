## Rubric Attestation

This project satisfies the following aspects of the rubric for the Udacity C++ Nanodegree Program:

* Readme
  * Outlines how to build and run the project.
  * Includes how to install any additional addons.
  * Indicates which project has been chosen (in this case, build and enhance a game).
* Compiling and Testing
  * The project compiles and runs successfully.
* Loops, functions, I/O
  * Project contains a variety of different functions and control flows.
  * Project accepts user inputs using SDL.
* Object-Oriented Programming
  * Project is broken down into the following classes:
    * Game
    * Session
    * Renderer
    * Controller
    * Ball
    * Paddle
    * Player
  * Classes contain both private and public variables, with getters/setters as appropriate.
  * Classes have constructors (with and without initialization lists) and destructors, as appropriate.
  * Classes encapsulate behavior and offer an adequate level of abstraction for other developers to follow.
* Memory Management
  * The project uses references or pointers where appropriate
  * The session object is responsible for creating and destroying the game objects between each rally, with rule of 5 implemented
  * The game object has an owning reference to Players and Session objects using a Unique Pointers to handle cleanup.