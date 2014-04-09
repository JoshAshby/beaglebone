echo 74 >> /sys/class/gpio/export
echo 72 >> /sys/class/gpio/export
echo 70 >> /sys/class/gpio/export

echo out >> /sys/class/gpio/gpio74/direction
echo out >> /sys/class/gpio/gpio72/direction
echo out >> /sys/class/gpio/gpio70/direction

echo 1 >> /sys/class/gpio/gpio74/value
echo 1 >> /sys/class/gpio/gpio72/value
echo 1 >> /sys/class/gpio/gpio70/value

echo "Red!"
echo 0 >> /sys/class/gpio/gpio74/value
sleep 5
echo 1 >> /sys/class/gpio/gpio74/value

echo "Blue!"
echo 0 >> /sys/class/gpio/gpio72/value
sleep 5
echo 1 >> /sys/class/gpio/gpio72/value

echo "Green!"
echo 0 >> /sys/class/gpio/gpio70/value
sleep 5
echo 1 >> /sys/class/gpio/gpio70/value

echo 74 >> /sys/class/gpio/unexport
echo 72 >> /sys/class/gpio/unexport
echo 70 >> /sys/class/gpio/unexport
