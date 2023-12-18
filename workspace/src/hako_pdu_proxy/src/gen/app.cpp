
mros2::Publisher pub = node.create_publisher<sensor_msgs::msg::JointState>("xxx", xx);
mros2::Publisher pub = node.create_publisher<sensor_msgs::msg::Imu>("xxx", xx);
mros2::Publisher pub = node.create_publisher<nav_msgs::msg::Odometry>("xxx", xx);
mros2::Publisher pub = node.create_publisher<tf2_msgs::msg::TFMessage>("xxx", xx);
mros2::Publisher pub = node.create_publisher<sensor_msgs::msg::LaserScan>("xxx", xx);
mros2::Subscriber sub = node.create_subscription<geometry_msgs::msg::Twist>("xxx", xx, xxx);
