#include <pcl/io/io.h>
#include <pcl/io/pcd_io.h>
#include <pcl/visualization/cloud_viewer.h>

int main ()
{
    pcl::visualization::CloudViewer viewer("Cloud Viewer");

    pcl::PointCloud<pcl::PointXYZ>::Ptr room1 (new pcl::PointCloud<pcl::PointXYZ>);
    pcl::io::loadPCDFile ("../room_scan1.pcd", *room1);

    pcl::PointCloud<pcl::PointXYZ>::Ptr room2 (new pcl::PointCloud<pcl::PointXYZ>);
    pcl::io::loadPCDFile ("../room_scan2.pcd", *room2);

    viewer.showCloud (room1, "Room1");
    viewer.showCloud (room2, "Room2");
    // viewer.showCloud (room1);
    // viewer.showCloud (room2);
    while (!viewer.wasStopped ())
    {
    }
    return 0;
}