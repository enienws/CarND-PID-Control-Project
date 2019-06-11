# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---
##What is a PID Controller
PID controller is a control loop feedback controller. This type of controller is used widely among different control problems. 

PID controller consists of three components named as Proportional, Integrative, Derivative. 

Proportional error is proportional to systems overall error. Derivative error is propportional to how fast the error increasing or decreasing. Integrative error is proportional to cumulative error that depends to system run before. 

Three errors are implemented by using the following code block:
	
	d_error = cte - p_error;
	p_error = cte;
	i_error += cte;

Each kind of error types are used to provide a smooth system act. Not all the systems need to have all the components simple P controllers or PD controllers may be implemented as well. 

##PID Controller Implementation
In the project source code we have PID.cpp and PID.h files. These files define the PID class which implements a simple PID controller. 

In UpdateError method, three different errors are defined. In TotalError method, total error of the system is calculated using three types of error. This result is given as a steering value to the simulator. 

##Tuning PID Parameters
I have chosen to tune PID parameters by a manual try and error way. Since P error affects the overall system a lot, I first start to tune P value by setting I and D values to 0. In other words, I started by a simple P controller as a first step. I started to tune D parameter as the P controller performs well and finally I parameter is tuned. 

Below you can find different videos related to different steps of tuning:

Tuning the P controller, Kp = 5
<video width="480" height="270" controls>
  <source src="videos/pid_controller_p_5-2019-06-11_11.18.40.mkv" type="video/mp4">
</video>

Tuning the P controller, Kp = 2.5
<video width="480" height="270" controls>
  <source src="videos/pid_controller_p_2_5-2019-06-11_11.20.12.mkv" type="video/mp4">
</video>

Tuning the P controller, Kp = 0.5
<video width="480" height="270" controls>
  <source src="videos/pid_controller_p_0_5-2019-06-11_11.21.08.mkv" type="video/mp4">
</video>

Tuning the P controller, Kp = 0.25
<video width="480" height="270" controls>
  <source src="videos/pid_controller_p_0_25-2019-06-11_11.22.00.mkv" type="video/mp4">
</video>

It seems P controller works well with Kp=0.25. After this step I started to work on Derivative term. 

Tuning the PD controller, Kp = 0.25, Kd = 
<video width="480" height="270" controls>
  <source src="videos/pid_controller_p_0_25_i_1_5-2019-06-11_11.23.12.mkv" type="video/mp4">
</video>

And finally the PID controller: Kp = 0.25, Kd = 1.5, Ki = 0.003
<video width="480" height="270" controls>
  <source src="videos/pid_controller_p_0_25_i_1_5_i-2019-06-11_11.25.49.mkv" type="video/mp4">
</video>

The final PID Controller: Kp = 0.25, Kd = 1.5, Ki = 0.0003
<video width="480" height="270" controls>
  <source src="videos/pid_controller_final-2019-06-11_11.27.46.mkv" type="video/mp4">
</video>

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1(mac, linux), 3.81(Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

Fellow students have put together a guide to Windows set-up for the project [here](https://s3-us-west-1.amazonaws.com/udacity-selfdrivingcar/files/Kidnapped_Vehicle_Windows_Setup.pdf) if the environment you have set up for the Sensor Fusion projects does not work for this project. There's also an experimental patch for windows in this [PR](https://github.com/udacity/CarND-PID-Control-Project/pull/3).

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

Tips for setting up your environment can be found [here](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/0949fca6-b379-42af-a919-ee50aa304e6a/lessons/f758c44c-5e40-4e01-93b5-1a82aa4e044f/concepts/23d376c7-0195-4276-bdf0-e02f1f3c665d)

## Editor Settings

We've purposefully kept editor configuration files out of this repo in order to
keep it as simple and environment agnostic as possible. However, we recommend
using the following settings:

* indent using spaces
* set tab width to 2 spaces (keeps the matrices in source code aligned)

## Code Style

Please (do your best to) stick to [Google's C++ style guide](https://google.github.io/styleguide/cppguide.html).

## Project Instructions and Rubric

Note: regardless of the changes you make, your project must be buildable using
cmake and make!

More information is only accessible by people who are already enrolled in Term 2
of CarND. If you are enrolled, see [the project page](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/f1820894-8322-4bb3-81aa-b26b3c6dcbaf/lessons/e8235395-22dd-4b87-88e0-d108c5e5bbf4/concepts/6a4d8d42-6a04-4aa6-b284-1697c0fd6562)
for instructions and the project rubric.

## Hints!

* You don't have to follow this directory structure, but if you do, your work
  will span all of the .cpp files here. Keep an eye out for TODOs.

## Call for IDE Profiles Pull Requests

Help your fellow students!

We decided to create Makefiles with cmake to keep this project as platform
agnostic as possible. Similarly, we omitted IDE profiles in order to we ensure
that students don't feel pressured to use one IDE or another.

However! I'd love to help people get up and running with their IDEs of choice.
If you've created a profile for an IDE that you think other students would
appreciate, we'd love to have you add the requisite profile files and
instructions to ide_profiles/. For example if you wanted to add a VS Code
profile, you'd add:

* /ide_profiles/vscode/.vscode
* /ide_profiles/vscode/README.md

The README should explain what the profile does, how to take advantage of it,
and how to install it.

Frankly, I've never been involved in a project with multiple IDE profiles
before. I believe the best way to handle this would be to keep them out of the
repo root to avoid clutter. My expectation is that most profiles will include
instructions to copy files to a new location to get picked up by the IDE, but
that's just a guess.

One last note here: regardless of the IDE used, every submitted project must
still be compilable with cmake and make./

## How to write a README
A well written README file can enhance your project and portfolio.  Develop your abilities to create professional README files by completing [this free course](https://www.udacity.com/course/writing-readmes--ud777).

