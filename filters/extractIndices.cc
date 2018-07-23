#include <iostream>

#include <pcl/point_types.h>
#include <pcl/filters/extract_indices.h>

int main(int, char**)
{
    std::cout << "Hello PCL !" << std:: endl;

    // define point cloud type
    typedef pcl::PointXYZ PointType;
    typedef pcl::PointCloud<PointType> CloudType;
    CloudType::Ptr cloud(new CloudType);
    cloud->is_dense = false;

    // fill out the cloud
    PointType p;
    for(unsigned int i = 0; i < 5; ++i)
    {
        p.x = p.y = p.z = static_cast<float> (i);
        cloud->push_back(p);
    }
    std::cout << "Cloud has " << cloud->points.size() << " points" << std::endl;

    // indices to be extracted
    pcl::PointIndices indices;
    indices.indices.push_back(0);
    indices.indices.push_back(2);

    // ExtractIndices: a filter for extracting a set of indices from a point cloud
    pcl::ExtractIndices<PointType> extract_indices;
    extract_indices.setIndices (boost::make_shared<const pcl::PointIndices> (indices));
    extract_indices.setInputCloud(cloud);
    // Output cloud
    pcl::PointCloud<pcl::PointXYZ>::Ptr output(new pcl::PointCloud<pcl::PointXYZ>);
    extract_indices.filter(*output);

    std::cout << "Output has " << output->points.size() << " points." << std::endl;

    return 0;

}