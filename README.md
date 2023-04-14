# PongPlusPlus - Pong with Powerups

PongPlusPlus is an in-progress experiment using C++ and SDL for game-design, inspired by the classic video game Pong.

## Features

### Interface

In the below image, various game objects have been highlighted with colored boxes:

![image](https://user-images.githubusercontent.com/24849659/231986672-0767b709-a752-4b7c-a3bc-eafa41e6ce16.png)

* Red: The paddle zone. Paddles will move up and down along this boundary.
* Yellow: The score board. Each side of the field has a score indicator for their respective players.
* Pink: Ball start. This is the location where the ball will always start before being served.
* Green: Current active powerup. Each player's powerup is displayed here by color. When used, the box becomes hollow.

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
  * <b>Duration:</b> 10 Hits

https://user-images.githubusercontent.com/24849659/232004811-7f357adf-bcd4-48bc-abc8-e44c5a73837e.mp4

* Ice
  * <b>Effect:</b> Each time a paddle is contacted by the ice ball, its speed decreases by 20%.
  * <b>Duration:</b> 10 Hits

https://user-images.githubusercontent.com/24849659/232004947-3ae92f77-feba-4a44-ba0f-389beb3c0a94.mp4

* Sun
  * <b>Effect:</b> Both players are blinded. The color contrast between the ball and the background become more difficult to distinguish.
  * <b>Duration:</b> 5 Hits

https://user-images.githubusercontent.com/24849659/232005008-96127924-4463-426e-b809-b1d9584f6e3c.mp4

* Shadow
  * <b>Effect:</b> Shadows erupt around the opposing player's side, rendering them unable to see their paddle.
  * <b>Duration:</b> 3 Hits

https://user-images.githubusercontent.com/24849659/232005063-64b73163-430b-46cd-ba3c-4e0a0779f11f.mp4

* Confusion
  * <b>Effect:</b> The ball begins to move in wave patterns and behaves in unexpected ways when objects are contacted.
  * <b>Duration:</b> 5 Hits

https://user-images.githubusercontent.com/24849659/232005111-76bd3700-243d-4ff5-9517-1bc893e218c7.mp4

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

* More Powerups:
  * Root ball
  * Shrink ball
  * Energy ball
  * LOVE ball
* Computer-controlled Player 2
* Menus, including power-up selection
* Stat-tracking
