# 🤖 Line Follower Robot

A line-following robot built using an **Arduino Nano**, IR sensor array, and TB6612FNG motor driver. The robot detects the line using the IR sensors and adjusts the motor speeds to follow the path.

## 🔧 Components Used

- Arduino Nano
- IR sensor array
- TB6612FNG motor driver
- 2 × DC motors
- Perfboard
- Buck converter
- 2 × Li-ion batteries

## ⚙️ How It Works

The IR sensor array detects the position of the line relative to the robot.

The sensor readings are used to calculate the line error. A **PD control algorithm** then adjusts the speed of the two motors to keep the robot following the line.

- Line to the left → robot turns left
- Line to the right → robot turns right
- Line at the center → robot moves forward
- No line detected → motors stop

## 💻 Software

- Arduino IDE


## 🚀 How to Run

1. Assemble the circuit on the perfboard.
2. Connect the IR sensor array and TB6612FNG motor driver to the Arduino Nano.
3. Connect the batteries through the buck converter as required.
4. Upload `Line_follower_bot.ino` to the Arduino Nano.
5. Place the robot on the line and power it on.
6. Tune the control parameters if required.

## ✨ Features

- IR sensor array for line detection
- PD-based line following
- Automatic motor speed adjustment
- Compact perfboard-based design
- Battery-powered operation

## 📁 Files

```text
Line-Follower-Robot/
├── Line_follower_bot.ino
└── README.md
```

## 📜 License

This project is created for educational and robotics experimentation purposes.
