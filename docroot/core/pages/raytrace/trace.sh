./RayTrace6
#now = $(date + "%m-%d-%y_%H:%M:%S")
#now = $1
#convert traced.ppm traced_$now.jpg
convert traced.ppm traced.jpg
rm -f traced.ppm
echo "Image Rendered"