#include "FilterTest.h"
#include <iostream>
#include <pcl/point_types.h>
#include <pcl/filters/passthrough.h>
#include <pcl/visualization/cloud_viewer.h>

using namespace std;

FilterTest::FilterTest(void)
{
}


FilterTest::~FilterTest(void)
{
}

void FilterTest::passThroughCloud(pcl::PointCloud<pcl::PointXYZ>::Ptr cloud) {
	cerr << "filter filter filter :-D" << endl;


 //pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered (new pcl::PointCloud<pcl::PointXYZ>);

  std::cerr << "Cloud before filtering: " << cloud->points.size() << std::endl;

  cerr << "checkpoint A" << endl;

  // Create the filtering object
  pcl::PassThrough<pcl::PointXYZ> pass;
  pass.setInputCloud (cloud);
  pass.setFilterFieldName ("z");
  pass.setFilterLimits (0.0, 1.0);
  //pass.setFilterLimitsNegative (true);
  pass.filter (*cloud_filtered);


  std::cerr << "Cloud after filtering: " << cloud_filtered->points.size () << std::endl;

  	pcl::visualization::CloudViewer viewer("cloud viewer");
	//viewer.showCloud(cloud);
	viewer.showCloud(cloud_filtered);
	while (!viewer.wasStopped());

   //cin.get();

}
void FilterTest::testPassThrough(void) {
	cerr << "filter filter filter" << endl;


 pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered (new pcl::PointCloud<pcl::PointXYZ>);

  // Fill in the cloud data
  cloud->width  = 5;
  cloud->height = 1;
  cloud->points.resize (cloud->width * cloud->height);

  for (size_t i = 0; i < cloud->points.size (); ++i)
  {
    cloud->points[i].x = 1024 * rand () / (RAND_MAX + 1.0f);
    cloud->points[i].y = 1024 * rand () / (RAND_MAX + 1.0f);
    cloud->points[i].z = 1024 * rand () / (RAND_MAX + 1.0f);
  }

  std::cerr << "Cloud before filtering: " << cloud->points.size() << std::endl;
  for (size_t i = 0; i < cloud->points.size (); ++i)
    std::cerr << "    " << cloud->points[i].x << " " 
                        << cloud->points[i].y << " " 
                        << cloud->points[i].z << std::endl;

  cerr << "checkpoint A" << endl;

  // Create the filtering object
  pcl::PassThrough<pcl::PointXYZ> pass;
  pass.setInputCloud (cloud);
  pass.setFilterFieldName ("z");
  pass.setFilterLimits (0.0, 1.0);
  //pass.setFilterLimitsNegative (true);
  pass.filter (*cloud_filtered);


  std::cerr << "Cloud after filtering: " << cloud_filtered->points.size () << std::endl;

  for (size_t i = 0; i < cloud_filtered->points.size (); ++i)
    std::cerr << "    " << cloud_filtered->points[i].x << " " 
                        << cloud_filtered->points[i].y << " " 
                        << cloud_filtered->points[i].z << std::endl;


	// 	pcl::visualization::CloudViewer viewer("cloud viewer");
	//viewer.showCloud(cloud);
	//viewer.showCloud(cloud_filtered);
	//while (!viewer.wasStopped());

   cin.get();

}
