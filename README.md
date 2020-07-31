# ChaseIt
ROS simulation of a four wheeled mobile robot with skid steer control following a ball using a camera 

### Directory Structure
<pre><font color="#3465A4"><b>.</b></font>
├── <font color="#3465A4"><b>catkin_ws</b></font>
│   └── <font color="#3465A4"><b>src</b></font>
│       ├── <font color="#3465A4"><b>ball_chaser</b></font>
│       │   ├── CMakeLists.txt
│       │   ├── <font color="#3465A4"><b>launch</b></font>
│       │   │   └── ball_chaser.launch
│       │   ├── package.xml
│       │   ├── <font color="#3465A4"><b>src</b></font>
│       │   │   ├── drive_bot.cpp
│       │   │   └── process_image.cpp
│       │   └── <font color="#3465A4"><b>srv</b></font>
│       │       └── DriveToTarget.srv
│       ├── <span style="background-color:#2E3436"><font color="#CC0000"><b>CMakeLists.txt</b></font></span> -&gt; /opt/ros/kinetic/share/catkin/cmake/toplevel.cmake
│       └── <font color="#3465A4"><b>go_chase_it</b></font>
│           ├── CMakeLists.txt
│           ├── <font color="#3465A4"><b>launch</b></font>
│           │   ├── robot_description.launch
│           │   └── world.launch
│           ├── <font color="#3465A4"><b>meshes</b></font>
│           │   └── hokuyo.dae
│           ├── package.xml
│           ├── <font color="#3465A4"><b>urdf</b></font>
│           │   ├── my_robot.gazebo
│           │   └── my_robot.xacro
│           └── <font color="#3465A4"><b>world</b></font>
│               ├── empty.world
│               ├── myOffice.world
│               └── OfficeWithBall.world
└── README.md</pre>                


### Steps to launch the simulation

#### Step 1 clone the repository and build it
```sh
$ git clone https://github.com/farzingkh/ChaseIt.git
$ cd ChaseIt/catkin_ws
$ source devel/setup.bahs
$ catkin_make
```

#### Step 3 Run the robot simulation 
```sh
$ roslaunch go_chase_it world.launch
```

#### Step 4 Run the processing and command nodes
```sh
$ roslaunch ball_chaser world.launch
```
## Output

![alt text](image/out.gif)


    
 
