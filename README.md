
# forgeworkgaia Wisp Library

# Irrigator

## Hardware: Arduino

This code is designed to use cycles in controlling a simple 3 wire valve.

## Required Libs
Repo: wisplib_valve_3wire

## Usage

### Cycles

All things in nature run on cycles, so wisps are built on this pattern.

Cycles are set up on a per valve basis.

#### Defining a cycle

Find the switch case in the Valve_3wire file. Each case is set up to be a custom defined cycle.

The default is case 1, which turns the valve on for five minutes every hour around the clock.


#### How the code works

Every five second this code steps into a function called ValveRun, which tests if its time to take action. Each valve that's defined will need a corresponding run function in loop().

Define your valve:

```c++
Valve compostValve(1,7,8,1);
```

```c++
Valve (int incId, byte incValveOnPin, byte incValveOffPin, int incMode)
```

    incID: Set a unique id for this valve.

    incValveOnPin: Pin on arduino that turns valve on.

    incValveOffPin: Pin on arduino that turns valve off.

    incMode: Sets cycle characteristics.


And then make sure you place the follwoing in loop():

`ValveRun(compostValve, currentMillis);`


