# <img src="./Data/graphics/logo.svg" width="5%" alt="XCSoar Logo"> XCSoar


This is a copy of XCSoar (http://www.xcsoar.org, https:://github.com/XCSoar/XCSoar), version 7.28, extended with a new start functions:
 - starting point within start cylinder at the moment and position of Pilot Event
 - maximum altitude loss between start of a task and finish

The repository will be updated until funtionality is included in a new release of The XCSoar Project

To activate start at PEV set this option in task rules to "Yes". Then start of the task takes place at the moment and location when "Pilot Event" is anounced if inside start zone. If outside start zone, start takes place at the moment and location of entering start zone for the first time after "Pilot Event".
Option "Max height loss", if greater than zero, will cause the final glide to be calculated to greatest of (first two as per original logic): 
 - finish point+safety height,
 - finish line altitude,
 - start altitude at PEV - max height loss.


PEV start wait time changes its function and will not allow to start again for set period of time (usually 15 mins on competition in PL).
PEV start window is not used in this start type.

