# PongPlusPlus - Pong with Powerups

PongPlusPlus is an in-progress experiment using C++ and SDL for game-design, inspired by the classic video game Pong.

![image](https://user-images.githubusercontent.com/24849659/231979384-a4ba8a02-b7ae-43ae-8abd-eede8930e52c.png)

## Features

### Gameplay

<b>Recommended Number of Players</b>: 2

<b>Gameplay Loop</b>:

* Each player takes control of a paddle.
* The serve owner serves the ball at the opposing player - on bootup, this will always be player 1. 
* Players move vertically on their respective halves of the field to bounce the ball back and forth, speeding the ball up each time.
* If the ball passes your paddle, the opposing player will be rewarded with a point. You will be awarded the next serve.
* Play continues until either player reaches 10 points, at which point the game will be reset.

### Powerups

Once per point, a user can attempt to catch the ball. Doing so successfully will award the user a game-altering powerup. 
But beware, missing a catch will reduce the size of the paddle by 10%, down to a minimum size of 30%.

**Powerup Varieties:**
* Fire
  * <b>Effect:</b> Increases the ball speed by 2x immediately. Each subsequent hit will increase ball speed by 10%, rather than the usual 5%.
  * <b>Duration:</b> 10 Turns
* Ice
  * <b>Effect:</b> Each time a paddle is contacted by the ice ball, its speed decreases by 20%.
  * <b>Duration:</b> 10 Turns
* Sun
  * <b>Effect:</b> Both players are blinded. The color contrast between the ball and the background become more difficult to distinguish.
  * <b>Duration:</b> 5 Turns
* Shadow
  * <b>Effect:</b> Shadows erupt around the opposing player's side, rendering them unable to see their paddle.
  * <b>Duration:</b> 3 Turns
* Confusion
  * <b>Effect:</b> The ball begins to move in wave patterns and behaves in unexpected ways when objects are contacted.
  * <b>Duration:</b> 5 Turns

### Controls

**Player 1**:
* Move Paddle Up: W
* Move Paddle Down: S
* Catch Ball: D
* Serve Ball: Space

**Player 2**:
* Move Paddle Up: Arrow-Up
* Move Paddle Down: Arrow-Down
* Catch Ball: Right-CTRL
* Serve Ball: Return (Enter) or Numpad-Enter

## Roadmap
