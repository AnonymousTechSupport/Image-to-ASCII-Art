//
// Created by corbn on 28/03/2024.
//

#ifndef MYPROGRAM_FUNCTIONS_H
#define MYPROGRAM_FUNCTIONS_H

#include <filesystem>

// Constants
const int pixelThreshold = 112;
const int sleepTime = 50; // Milliseconds

bool isImagePahValid(const std::string& path)
{
    return std::filesystem::exists(path);
}

/*
 * @param image: The image to check if it's valid
 * @brief: This function checks if the image data is valid
 *        If there's no image data, print an error message
 */
bool isDataValid(const cv::Mat& image)
{
    // If there's no image data, print an error message
    if (!image.data)
    {
        std::cout << "No image data\n";
        return false;
    } else {
        std::cout << "Image data found, allow the program a couple moments to complete\n";
        return true;
    }
}

/*
 * @param image: The image to loop through
 * @brief: This function loops through the image and creates an ASCII art image
 */
std::string generateAsciiArt(const cv::Mat& image)
{
    std::string asciiArt;

    for (int y = 0; y < image.rows; y+=2)
    {
        for (int x = 0; x < image.cols; x+=2)
        {
            int pixel = image.at<uchar>(y, x);

            if (pixel >= pixelThreshold)
            {
                asciiArt += ":";
            }
            else
            {
                asciiArt += " ";
            }
        }

        asciiArt += "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));
    }

    return asciiArt;
}

// Function to write ASCII art to file
void writeToFile(const std::string& asciiArt)
{
    std::ofstream outFile("output.txt");
    outFile << asciiArt;
    outFile.close();
}

#endif //MYPROGRAM_FUNCTIONS_H
