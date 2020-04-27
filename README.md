# UE4 FPS Tracking Demo
I had a few hours to spare refamiliarizing myself with Unreal Engine, and I put together this little FPS training tracking demo.  

## Overview
- Do your best to keep the targeting crosshair over the yellow target cylinder as long as you can.
- The cylinder will move around randomly.
  - The cylinder has two movemnent speeds (Sprinting/Walking) and will change between them at random as it moves around.
  - The cylinder will stop for a little moment when it reaches the end of it's current path, this is a good time to rack up points!
- You have 30 Seconds to target the cylinder as long as you can.

## Controls
- Standard FPS keyboard/mouse movement and aiming controls apply.
- Before the training starts you can press [NUM +] or [NUM -] to decrease/increase the difficulty of the training respectively.
- Press [SPACE] to start or restart the training.

## Other Technical Info
- Starting with the FPS template in UE4 gets you quite a ways started for a demo like this.
- The project is a decent mix of CPP and Blueprints...
  - Player character, HUD, and GameMode are CPP.
  - Cylinder(Bad Guy) and its AI are blueprint.
  - UMG for the UI elements.

## Have Fun!
My current record is **71%** on standard difficulty.

## Disclaimer
I don't know the first thing about FPS training, this is probably a really bad FPS training tool, don't use it for that.  There are better choices.
