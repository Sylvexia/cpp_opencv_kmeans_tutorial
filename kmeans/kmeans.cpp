#include "kmeans.hpp"

cv::Mat show_mat(std::string filepath)
{
    cv::Mat ret = cv::imread(filepath, cv::IMREAD_COLOR);
    cv::imshow("winName", ret);
    cv::waitKey(0);
    return ret;
}