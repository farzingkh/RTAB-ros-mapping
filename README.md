# AMCL Localization
This repo contains localization of a four wheeled mobile robot inside an office using ROS amcl localization package

### Directory Structure
<pre><font color="#3465A4"><b>.</b></font>
├── <font color="#3465A4"><b>catkin_ws</b></font>
│   └── <font color="#3465A4"><b>src</b></font>
│       ├── <font color="#3465A4"><b>amcl_localization</b></font>
│       │   ├── CMakeLists.txt
│       │   ├── <font color="#3465A4"><b>config</b></font>
│       │   │   ├── base_local_planner_params.yaml
│       │   │   ├── costmap_common_params.yaml
│       │   │   ├── global_costmap_params.yaml
│       │   │   ├── local_costmap_params.yaml
│       │   │   └── <font color="#3465A4"><b>__MACOSX</b></font>
│       │   ├── <font color="#3465A4"><b>launch</b></font>
│       │   │   └── amcl.launch
│       │   ├── <font color="#3465A4"><b>maps</b></font>
│       │   │   ├── <font color="#75507B"><b>map.pgm</b></font>
│       │   │   └── map.yaml
│       │   └── package.xml
│       ├── <span style="background-color:#2E3436"><font color="#CC0000"><b>CMakeLists.txt</b></font></span> -&gt; /opt/ros/kinetic/share/catkin/cmake/toplevel.cmake
│       ├── <font color="#3465A4"><b>pgm_map_creator</b></font>
│       │   ├── CMakeLists.txt
│       │   ├── <font color="#3465A4"><b>launch</b></font>
│       │   │   └── request_publisher.launch
│       │   ├── LICENSE
│       │   ├── <font color="#3465A4"><b>maps</b></font>
│       │   │   └── <font color="#75507B"><b>map.pgm</b></font>
│       │   ├── <font color="#3465A4"><b>msgs</b></font>
│       │   │   ├── CMakeLists.txt
│       │   │   └── collision_map_request.proto
│       │   ├── package.xml
│       │   ├── README.md
│       │   ├── <font color="#3465A4"><b>src</b></font>
│       │   │   ├── collision_map_creator.cc
│       │   │   └── request_publisher.cc
│       │   └── <font color="#3465A4"><b>world</b></font>
│       │       └── Office01
│       ├── <font color="#3465A4"><b>robot</b></font>
│       │   ├── CMakeLists.txt
│       │   ├── <font color="#3465A4"><b>launch</b></font>
│       │   │   ├── robot_description.launch
│       │   │   └── world.launch
│       │   ├── <font color="#3465A4"><b>meshes</b></font>
│       │   │   └── hokuyo.dae
│       │   ├── package.xml
│       │   ├── <font color="#3465A4"><b>rviz</b></font>
│       │   │   └── RViz.rviz
│       │   ├── <font color="#3465A4"><b>urdf</b></font>
│       │   │   ├── my_robot.gazebo
│       │   │   └── my_robot.xacro
│       │   └── <font color="#3465A4"><b>world</b></font>
│       │       ├── empty.world
│       │       └── office.world
│       └── <font color="#3465A4"><b>teleop_twist_keyboard</b></font>
│           ├── CHANGELOG.rst
│           ├── CMakeLists.txt
│           ├── package.xml
│           ├── README.md
│           └── <font color="#4E9A06"><b>teleop_twist_keyboard.py</b></font>
├── <font color="#3465A4"><b>image</b></font>
│   └── <font color="#75507B"><b>out.gif</b></font>
├── LICENSE
└── README.md
</pre>


### Steps to launch the simulation

#### Step 1 clone the repository and build it
```sh
$ git clone https://github.com/farzingkh/AMCL-Localization.git
$ cd AMCL_localization/catkin_ws
$ catkin_make
$ source devel/setup.bash
```

#### Step 3 Run the robot simulation 
```sh
$ roslaunch robot world.launch
```

#### Step 4 Run the processing and command nodes
```sh
$ roslaunch amcl_localization amcl.launch
$ rosrun teleop_twist_keyboard teleop_twist_keyboard.py
```
## Output

![alt text](image/out.gif)


    
 
