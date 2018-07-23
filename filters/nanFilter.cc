#include <iostream>
#include <limits>

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/filters/filter.h>

int main(int, char**)
{
    std::cout << "Hello PCL !" << std:: endl;

    // define point cloud type
    typedef pcl::PointCloud<pcl::PointXYZ> CloudType;
    CloudType::Ptr cloud(new CloudType);
    cloud->is_dense = false;

    // output_cloud stores the output after filtering
    CloudType::Ptr output_cloud(new CloudType);

    // add invalid data to original cloud
    CloudType::PointType p_nan;
    p_nan.x = std::numeric_limits<float>::quiet_NaN();
    p_nan.y = std::numeric_limits<float>::quiet_NaN();
    p_nan.z = std::numeric_limits<float>::quiet_NaN();
    cloud->push_back(p_nan);

    // add valid data to original cloud
    CloudType::PointType p_valid;
    p_valid.x = 1.0f;
    cloud->push_back(p_valid);

    std::cout << "size: " << cloud->points.size() << std::endl;

    // indices store the point mapping from output_cloud to cloud
    std::vector<int> indices;
    pcl::removeNaNFromPointCloud(*cloud, *output_cloud, indices);
    std::cout << "size: " << output_cloud->points.size() << std::endl;

    return 0;

}