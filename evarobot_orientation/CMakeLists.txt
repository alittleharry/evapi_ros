cmake_minimum_required(VERSION 2.8.3)
project(evarobot_orientation)

set(EVAPI_LIB_SDK_PATH "../sdk/")
FILE(GLOB EVAPI_LIB_SDK_SRC "${EVAPI_LIB_SDK_PATH}/src/*.cpp")

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  sensor_msgs
  diagnostic_updater
)


catkin_package(
  INCLUDE_DIRS include
#  LIBRARIES evarobot_orientation
#  CATKIN_DEPENDS roscpp rospy sensor_msgs
#  DEPENDS system_lib
)

###########
## Build ##
###########
include_directories(
  ${catkin_INCLUDE_DIRS}
  ${EVAPI_LIB_SDK_PATH}/include
  ${EVAPI_LIB_SDK_PATH}/src  
  include
)

 add_executable(evarobot_orientation src/evarobot_orientation.cpp ${EVAPI_LIB_SDK_SRC})
 target_link_libraries(evarobot_orientation ${catkin_LIBRARIES})

