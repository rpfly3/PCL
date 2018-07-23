#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/filters/statistical_outlier_removal.h>

int main(int, char**)
{
    std::cout << "Hello PCL !" << std:: endl;

    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered(new pcl::PointCloud<pcl::PointXYZ>);

    // Fill in the cloud data
    pcl::PCDReader reader;
    reader.read("../filters/table_scene_lms400.pcd", *cloud);

    std::cout << "Cloud before filtering: " << std::endl;
    std::cout << *cloud << std::endl;

    // Create the filtering object
    pcl::StatisticalOutlierRemoval<pcl::PointXYZ> sor;
    sor.setInputCloud(cloud);
    sor.setMeanK(50);
    sor.setStddevMulThresh(1.0);
    sor.filter(*cloud_filtered);

    std::cout << "Cloud after filtering: " << std::endl;
    std::cout << *cloud_filtered << std::endl;

    pcl::PCDWriter writer;
    writer.write("../filters/table_scene_lms400_inliers.pcd", *cloud_filtered, false);

    sor.setNegative(true);
    sor.filter(*cloud_filtered);
    writer.write("../filters/table_scene_lms400_outliers.pcd", *cloud_filtered, false);

    return 0;

}