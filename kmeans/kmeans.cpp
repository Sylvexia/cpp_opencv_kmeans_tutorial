#include "kmeans.hpp"

void print2d_float_vec(std::vector<std::vector<float>> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
        {
            std::cout << vec[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

float vec_distance(std::vector<float> a, std::vector<float> b)
{
    if (a.size() != b.size())
    {
        std::cout << "Error!! the dimension does not match"
                  << "\n";

        exit(-1);
        return -1.0f;
    }

    float square_sum = 0;

    for (int i = 0; i < a.size(); i++)
    {
        square_sum += std::pow(std::abs(a[i] - b[i]), 2);
    }

    return std::sqrt(square_sum);
}

bool vec_2d_equal_epsilon(std::vector<std::vector<float>> a, std::vector<std::vector<float>> b, float epsilon)
{
    // epsilon: 容許誤差
    // check if the size is the same
    if (a.size() != b.size())
    {
        std::cout << "Error!! the dimension does not match"
                  << "\n";

        exit(-1);
        return false;
    }

    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a[i].size(); j++)
        {
            if (std::abs(a[i][j] - b[i][j]) > epsilon)
                return false;
        }
    }

    return true;
}

std::vector<std::vector<float>> generate_random_k_centers(int k_num, int dim, int min, int max)
{
    std::vector<std::vector<float>> centers_vec;

    for (int i = 0; i < k_num; ++i)
    {
        std::vector<float> row_vec; // When loop back, the vector is re-initialized!

        for (int j = 0; j < dim; ++j)
            row_vec.push_back(rand() % (max - min + 1) + min);

        centers_vec.push_back(row_vec);
    }
    return centers_vec;
}

Kmeans_algo Kmeans_algorithm(std::vector<std::vector<float>> data_vec, int k_num, int dim)
{
    std::vector<std::vector<float>> old_centers_vec(k_num, std::vector<float>(dim, 0));          // K個中心點 每個中心點有dim個維度，初始值為0
    std::vector<std::vector<float>> centers_vec = generate_random_k_centers(k_num, dim, 0, 255); // K個中心點 每個中心點有dim個維度，初始值為0～255的隨機值
    std::vector<int> labels_vec(data_vec.size(), -1);                                            // n筆資料 每筆資料有1個label，初始值為-1

    while (!vec_2d_equal_epsilon(old_centers_vec, centers_vec, 0.0001))
    {
        old_centers_vec = centers_vec;

        // 1. assign each data to the nearest center
        for (int i = 0; i < data_vec.size(); i++)
        {
            float min_distance = 999999999.0f;
            int min_index = -1;

            for (int k = 0; k < k_num; k++)
            {
                float distance = vec_distance(data_vec[i], centers_vec[k]);

                if (distance < min_distance)
                {
                    min_distance = distance;
                    min_index = k;
                }
            }

            labels_vec[i] = min_index; // 第i筆資料的label為第min_index(k)個中心點
        }

        // 2. update k_num center
        for (int k = 0; k < k_num; k++)
        {
            std::vector<float> sum_vec(dim, 0);
            int count = 0;

            for (int i = 0; i < data_vec.size(); i++)
            {
                if (labels_vec[i] == k)
                {
                    for (int j = 0; j < dim; j++)
                    {
                        sum_vec[j] += data_vec[i][j];
                    }
                    count++;
                }
            }

            for (int j = 0; j < dim; j++)
            {
                centers_vec[k][j] = sum_vec[j] / count;
            }
        }
    }

    Kmeans_algo ret;
    ret.centers = centers_vec;
    ret.labels = labels_vec;

    return ret;
}

std::vector<std::vector<float>> replace_label_to_center(std::vector<std::vector<float>> data_vec, std::vector<int> labels_vec, std::vector<std::vector<float>> centers_vec)
{
    std::vector<std::vector<float>> ret_vec(data_vec.size(), std::vector<float>(data_vec[0].size(), 0));

    for (int i = 0; i < data_vec.size(); i++)
    {
        for (int j = 0; j < data_vec[i].size(); j++)
        {
            ret_vec[i][j] = centers_vec[labels_vec[i]][j];
        }
    }

    return ret_vec;
}

std::vector<std::vector<float>> mat_to_vec(cv::Mat img)
{
    std::vector<std::vector<float>> data_vec;

    switch (img.channels())
    {
    case 1:
        for (int i = 0; i < img.rows; i++)
        {
            for (int j = 0; j < img.cols; j++)
            {
                std::vector<float> row_vec;

                for (int k = 0; k < img.channels(); k++)
                {
                    row_vec.push_back(img.at<cv::Vec<uchar, 1>>(i, j)[k]);
                }

                data_vec.push_back(row_vec);
            }
        }
        break;

    case 3:
        for (int i = 0; i < img.rows; i++)
        {
            for (int j = 0; j < img.cols; j++)
            {
                std::vector<float> row_vec;

                for (int k = 0; k < img.channels(); k++)
                {
                    row_vec.push_back(img.at<cv::Vec<uchar, 3>>(i, j)[k]);
                }

                data_vec.push_back(row_vec);
            }
        }
        break;

    case 4:
        for (int i = 0; i < img.rows; i++)
        {
            for (int j = 0; j < img.cols; j++)
            {
                std::vector<float> row_vec;

                for (int k = 0; k < img.channels(); k++)
                {
                    row_vec.push_back(img.at<cv::Vec<uchar, 4>>(i, j)[k]);
                }

                data_vec.push_back(row_vec);
            }
        }
        break;

    default:
        std::cout << "error"
                  << "\n";

        exit(-1);
        break;
    }

    return data_vec;
}

cv::Mat vec_to_mat(std::vector<std::vector<float>> data_vec, int rows, int cols, int channels)
{
    cv::Mat ret(rows, cols, CV_MAKETYPE(CV_8U, channels));

    switch (channels)
    {
    case 1:
        for (int i = 0; i < data_vec.size(); i++)
        {
            for (int j = 0; j < data_vec[i].size(); j++)
            {
                ret.at<cv::Vec<uchar, 1>>(i / cols, i % cols)[j] = (float)data_vec[i][j];
            }
        }
        break;

    case 3:
        for (int i = 0; i < data_vec.size(); i++)
        {
            for (int j = 0; j < data_vec[i].size(); j++)
            {
                ret.at<cv::Vec<uchar, 3>>(i / cols, i % cols)[j] = (float)data_vec[i][j];
            }
        }
        break;

    case 4:
        for (int i = 0; i < data_vec.size(); i++)
        {
            for (int j = 0; j < data_vec[i].size(); j++)
            {
                ret.at<cv::Vec<uchar, 4>>(i / cols, i % cols)[j] = (float)data_vec[i][j];
            }
        }
        break;

    default:
        std::cout << "error"
                  << "\n";

        exit(-1);
        break;
    }

    return ret;
}