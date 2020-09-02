# RTAB ROS Mapping
This repo contains application of rtabmap_ros package to map a gazebo environment using Kinect

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
│       │   │   └── map.yaml
│       │   └── package.xml
│       ├── <span style="background-color:#2E3436"><font color="#CC0000"><b>CMakeLists.txt</b></font></span> -&gt; /opt/ros/kinetic/share/catkin/cmake/toplevel.cmake
│       ├── <font color="#3465A4"><b>pgm_map_creator</b></font>
│       │   ├── CMakeLists.txt
│       │   ├── <font color="#3465A4"><b>launch</b></font>
│       │   │   └── request_publisher.launch
│       │   ├── LICENSE
│       │   ├── <font color="#3465A4"><b>maps</b></font>
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
│       │   ├── <font color="#3465A4"><b>material</b></font>
│       │   │   └── <font color="#75507B"><b>kinect.jpg</b></font>
│       │   ├── <font color="#3465A4"><b>meshes</b></font>
│       │   │   ├── hokuyo.dae
│       │   │   └── kinect.dae
│       │   ├── package.xml
│       │   ├── <font color="#3465A4"><b>rviz</b></font>
│       │   │   └── RViz.rviz
│       │   ├── <font color="#3465A4"><b>urdf</b></font>
│       │   │   ├── my_robot.gazebo
│       │   │   └── my_robot.xacro
│       │   └── <font color="#3465A4"><b>world</b></font>
│       │       ├── empty.world
│       │       ├── office1.world
│       │       └── office.world
│       ├── <font color="#3465A4"><b>rtabmap_ros</b></font>
│       │   ├── <font color="#3465A4"><b>cfg</b></font>
│       │   │   └── <font color="#4E9A06"><b>Camera.cfg</b></font>
│       │   ├── CMakeLists.txt
│       │   ├── costmap_plugins.xml
│       │   ├── <font color="#3465A4"><b>database</b></font>
│       │   │   └── rtabmap.db
│       │   ├── <font color="#3465A4"><b>docker</b></font>
│       │   │   ├── <font color="#3465A4"><b>indigo</b></font>
│       │   │   │   ├── Dockerfile
│       │   │   │   └── <font color="#3465A4"><b>latest</b></font>
│       │   │   │       ├── Dockerfile
│       │   │   │       └── <font color="#3465A4"><b>hooks</b></font>
│       │   │   │           └── build
│       │   │   ├── <font color="#3465A4"><b>kinetic</b></font>
│       │   │   │   ├── Dockerfile
│       │   │   │   └── <font color="#3465A4"><b>latest</b></font>
│       │   │   │       ├── Dockerfile
│       │   │   │       └── <font color="#3465A4"><b>hooks</b></font>
│       │   │   │           └── build
│       │   │   ├── <font color="#3465A4"><b>melodic</b></font>
│       │   │   │   ├── Dockerfile
│       │   │   │   └── <font color="#3465A4"><b>latest</b></font>
│       │   │   │       ├── Dockerfile
│       │   │   │       └── <font color="#3465A4"><b>hooks</b></font>
│       │   │   │           └── build
│       │   │   ├── <font color="#3465A4"><b>noetic</b></font>
│       │   │   │   ├── Dockerfile
│       │   │   │   └── <font color="#3465A4"><b>latest</b></font>
│       │   │   │       ├── Dockerfile
│       │   │   │       └── <font color="#3465A4"><b>hooks</b></font>
│       │   │   │           └── build
│       │   │   └── README.md
│       │   ├── <font color="#3465A4"><b>eclipse-launch</b></font>
│       │   │   ├── <font color="#75507B"><b>eclipse48.png</b></font>
│       │   │   ├── eclipse.desktop
│       │   │   └── eclipse-launch.sh
│       │   ├── <font color="#4E9A06"><b>eclipse-launch.sh</b></font>
│       │   ├── <font color="#3465A4"><b>include</b></font>
│       │   │   └── <font color="#3465A4"><b>rtabmap_ros</b></font>
│       │   ├── <font color="#3465A4"><b>launch</b></font>
│       │   │   ├── <font color="#3465A4"><b>azimut3</b></font>
│       │   │   ├── <font color="#3465A4"><b>calibration</b></font>
│       │   │   ├── <font color="#3465A4"><b>config</b></font>
│       │   │   ├── <font color="#3465A4"><b>data</b></font>
│       │   │   ├── data_recorder.launch
│       │   │   ├── <font color="#3465A4"><b>demo</b></font>
│       │   │   ├── <font color="#3465A4"><b>jfr2018</b></font>
│       │   │   ├── localization.launch
│       │   │   ├── mapping.launch
│       │   │   ├── rgbd_mapping_kinect2.launch
│       │   │   ├── rgbd_mapping.launch
│       │   │   ├── rtabmap.launch
│       │   │   ├── stereo_mapping.launch
│       │   │   └── <font color="#3465A4"><b>tests</b></font>
│       │   ├── LICENSE
│       │   ├── mainpage.dox
│       │   ├── Makefile
│       │   ├── <font color="#3465A4"><b>msg</b></font>
│       │   ├── nodelet_plugins.xml
│       │   ├── package.xml
│       │   ├── <font color="#3465A4"><b>python</b></font>
│       │   ├── README.md
│       │   ├── rviz_plugins.xml
│       │   ├── <font color="#3465A4"><b>scripts</b></font>
│       │   ├── setup.py
│       │   ├── <font color="#3465A4"><b>src</b></font>
│       │   └── <font color="#3465A4"><b>srv</b></font>
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

#### Step 1 install rtabmap 
Clone the repository and build the source code

```sh
$ git clone https://github.com/introlab/rtabmap.git
$ cd build
$ cmake ..
$ make install
```

#### Step 1 clone the repository and build it
```sh
$ git clone https://github.com/farzingkh/RTAB-ros-mapping.git
$ cd RTAB-ros-mapping/catkin_ws
$ catkin_make
$ source devel/setup.bash
```

#### Step 3 Run the robot simulation 
```sh
$ roslaunch robot world.launch
```

#### Step 4 Run the processing and command nodes
```sh
$ roslaunch rtabmap_ros mapping.launch
```
In another terminal run the teleop package
```sh
$ rosrun teleop_twist_keyboard teleop_twist_keyboard.py
```
## Output

![alt text](image/out.gif)


    
 
