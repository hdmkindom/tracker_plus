#!/bin/bash

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
    echo "找到 $device_count 个串口设备: $devices"

    # 检查是否有多个设备
    if [ "$device_count" -eq 1 ]; then
        # 只有一个串口设备
        echo "找到唯一的串口设备: $devices"
        if [[ "$devices" == "/dev/ttyACM0" ]]; then
            echo "检测到 /dev/ttyACM0，正在修改 $node_params_file..."

            # 使用 sed 修改device_name
            sed -i 's|^\(\s*device_name:\s*\).*|\1/dev/ttyACM0|' "$node_params_file"
            echo "$node_params_file 已更新。"
        elif [[ "$devices" == "/dev/ttyUSB0" ]]; then
            echo "检测到 /dev/ttyUSB0，正在修改 $node_params_file..."
            sed -i 's|^\(\s*device_name:\s*\).*|\1/dev/ttyUSB0|' "$node_params_file"
            echo "$node_params_file 已更新。"
        else
            echo "找到的唯一串口设备不是 ACM0或USB0，不进行修改。"
        fi
    elif [ "$device_count" -gt 1 ]; then
        echo "找到多个串口设备:"
        echo "$devices"
        echo "请手动修改 $node_params_file 中的 device_name。"
    else
        # 这个分支理论上不会执行，因为前面已经检查了 -z "$devices"
        echo "未找到任何串口设备 (此消息不应出现)。"
        exit 1
    fi

    # 修改 debug 部分
    echo "正在修改 $node_params_file 中 /armor_detector: 下的 debug 参数为 false..."
    # 使用 sed 修改 /armor_detector: 下的 debug: true 为 debug: false
    # 这个 sed 命令会查找以任意空格开头，然后是 "debug:"，然后是任意空格，然后是 "true" 的行，
    # 并将其中的 "true" 替换为 "false"。
    # 它通过分组 \(\s*debug:\s*\) 来保留 "debug: " 部分及其前面的空格。
    sed -i 's|^\(\s*debug:\s*\)true|\1false|' "$node_params_file"
    
    if grep -q "^\s*debug:\s*false" "$node_params_file"; then
        echo "/armor_detector: 下的 debug 参数已更新为 false。"
    else
        echo "警告: 未能成功更新 /armor_detector: 下的 debug 参数，请检查 $node_params_file 文件。"
    fi

    sudo chmod 777 /dev/tty*
    sleep 2
    ros2 launch rm_vision_bringup vision_bringup.launch.py
}

# 主程序
main() {
    INFO
    
    rm_vision_bringup
}

# 调用主程序
main "$@"
