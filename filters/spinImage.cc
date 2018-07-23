#include <iostream>
#include <vector>

#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/features/normal_3d.h>
#include <pcl/features/spin_image.h>

int main(int, char**)
{
    std::cout << "Hello PCL !" << std:: endl;

    std::string filename = argv[1];
    std::cout << "Reading " << filename << std::endl;

    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);

    if(pcl::io::loadPCDFile<pcl::PointXYZ>(filename.c_str(), *cloud) == -1)
    {
        PCL_ERROR("Couldn't read file.");
        return (-1);
    }

    std::cout << "Loaded " << cloud->points.size() << " points." << std::endl;

    // Compute the normals
    pcl::NormalEstimation<pcl::PointXYZ, pcl::Normal> normal_estimation;
    normal_estimation.setInputCloud(cloud);

    pcl::search::KdTree<pcl::PointXYZ>::Ptr kdtree(new pcl::search::KdTree<pcl::PointXYZ>);
    normal_estimation.setSearchMethod(kdtree);

    pcl::PointCloud<pcl::Normal>::Ptr normals (new pcl)


    std::cout << "Output has " << output->points.size() << " points." << std::endl;

    return 0;

}