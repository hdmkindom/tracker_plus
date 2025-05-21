#!/bin/bash

node_params_file="src/rm_vision/rm_vision_bringup/config/node_params.yaml"

# 函数定义

function INFO(){

    source install/setup.bash
    source /opt/ros/humble/setup.bash
    
    echo "======================="
    echo "Welcome to use the rv!"
    echo "======================="
    echo ""
    echo "请检查 一下事项"
    echo "1. 相机线是否连接"
    echo "2. 串口线是否连接"
    echo "3. camera_info使用的是哪个相机"
    echo "4. 电控代码是否烧得是这一套"
    echo "5. 电控给速度是否正常"
    echo ""
    echo "早睡觉,莫熬夜.通宵会降低智力 :( "
    echo ""
}

function build() {
    rosdep install --from-paths src --ignore-src -r -y --rosdistro humble
    source /opt/ros/humble/setup.bash
    colcon build --symlink-install
}

function no_hardware(){
    ros2 launch rm_vision_bringup no_hardware.launch.py
}

function rm_vision_bringup(){
    devices=$(ls /dev/ttyACM[0-9]* /dev/ttyUSB[0-9]* 2>/dev/null)   # 隐藏报错
    if [ -z "$devices" ]; then
        echo "未找到任何串口设备"
        exit 1
    fi

    # 计算找到的设备数量
    device_count=$(echo "$devices" | wc -l)

    # 获取 node_params.yaml 的路径
    # 注意: 请确保这个相对路径是正确的，相对于 debug_rv.sh 脚本的位置
    # 或者你可以使用一个更可靠的方法来确定 node_params.yaml 的绝对路径
    
    
    # 检查 node_params.yaml 文件是否存在
    if [ ! -f "$node_params_file" ]; then
        echo "错误: $node_params_file 文件未找到。"
        exit 1
    fi

    if [ "$device_count" -eq 1 ]; then
        # 只有一个串口设备
        echo "找到唯一的串口设备: $devices"
        if [[ "$devices" == "/dev/ttyACM0" ]]; then
            echo "检测到 /dev/ttyACM0，正在修改 $node_params_file..."
            # 使用 sed 修改第10行 (假设 device_name 在第10行)
            # 更稳妥的方式是匹配包含 "device_name:" 的行
            sed -i 's|^\(\s*device_name:\s*\).*|\1/dev/ttyACM0|' "$node_params_file"
            echo "$node_params_file 已更新。"
        elif [[ "$devices" == "/dev/ttyUSB0" ]]; then
            echo "检测到 /dev/ttyUSB0，正在修改 $node_params_file..."
            sed -i 's|^\(\s*device_name:\s*\).*|\1/dev/ttyUSB0|' "$node_params_file"
            echo "$node_params_file 已更新。"
        else
            echo "找到的唯一串口设备不是 /dev/ttyACM0 或 /dev/ttyUSB0，不进行修改。"
        fi
    elif [ "$device_count" -gt 1 ]; then
        echo "找到多个串口设备:"
        echo "$devices"
        echo "请手动在 $node_params_file 中配置正确的 device_name。"
    else
        # 这个分支理论上不会执行，因为前面已经检查了 -z "$devices"
        echo "未找到任何串口设备 (此消息不应出现)。"
        exit 1
    fi

    echo "$devices"

    sudo chmod 777 /dev/tty*
    sleep 2
    ros2 launch rm_vision_bringup vision_bringup.launch.py
}

function foxglove(){
    ros2 launch foxglove_bridge foxglove_bridge_launch.xml port:=8765
}

function camera_calibration(){
    gnome-terminal  -- bash -c "ros2 launch hik_camera hik_camera.launch.py; exec bash"
    sleep 0.5
    ros2 run camera_calibration cameracalibrator --size 11x8 --square 0.02 image:=/image_raw camera:=/camera
}

# 主程序
main() {
    INFO

    sleep 1

    # 检查参数数量
    if [ "$#" -lt 1 ]; then
        echo "用法: $0 build || no_hardware || rm_vision_bringup || foxglove || calibration"
        exit 1
    fi

    # 处理参数
    case "$1" in
        b)
            build
            ;;
        n)
            no_hardware
            ;;
        r)
            rm_vision_bringup
            ;;
        f)
            foxglove
            ;;
        c)
            camera_calibration
            ;;
        *)
            echo "无效的参数: $1"
            echo "用法: $0 build || no_hardware || rm_vision_bringup || foxglove || calibration"
            exit 1
            ;;
    esac
}

# 调用主程序
main "$@"
