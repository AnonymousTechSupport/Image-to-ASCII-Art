#include <iostream>
#include <thread>
#include <fstream>
#include <opencv2/opencv.hpp>
#include <functions.h>

int main()
{

    std::string path;
    std::cout << "Enter the path to the image: ";
    std::cin >> path;

    if(!isImagePahValid(path))
    {
        std::cout << "The path to the image is invalid, please try again.\n";
        return EXIT_FAILURE;
    }

    cv::Mat image;
    image = cv::imread(path, cv::IMREAD_GRAYSCALE);

    // If there is image data, display the image
    // Resize the image to half its size
    cv::Size size(image.cols/2, image.rows/2);
    cv::resize(image, image, size);

    if (isDataValid(image))
    {
        std::string asciiArt = generateAsciiArt(image);
        writeToFile(asciiArt);
        std::cout << "Program successfully created your ASCII Art, check the directory of which you executed the program for the output file.\n";
    }


    return EXIT_SUCCESS;
}
