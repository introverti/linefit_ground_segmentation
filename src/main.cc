#include <pcl/io/pcd_io.h>

#include <memory>

#include "ground_segmentation.h"
int main(int argc, char** argv) {
    std::shared_ptr<GroundSegmentation> friday =
        std::make_shared<GroundSegmentation>();
    PointCloud cloud;
    pcl::io::loadPCDFile("/home/xavier/repos/linefit_ground_segmentation/match/v_flat.pcd", cloud);
    std::vector<int> res;
    friday->segment(cloud, &res);
    return 0;
}