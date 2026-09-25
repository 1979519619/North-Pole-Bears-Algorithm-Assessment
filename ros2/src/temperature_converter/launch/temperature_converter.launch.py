from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription([
        Node(
            package="temperature_converter",
            executable="fahrenheit_subscriber",
            name="fahrenheit_subscriber",
            output="screen",
        ),
        Node(
            package="temperature_converter",
            executable="celsius_publisher",
            name="celsius_publisher",
            output="screen",
            prefix="gnome-terminal --wait --",
        ),
    ])
