#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: extra9 [car.jpeg / house.jpeg / mountain.jpeg / person.jpeg]\n";
        return 1;
    }

    std::string picture = argv[1];
    
    if (picture != "car.jpeg" && picture != "house.jpeg" && picture != "mountain.jpeg" && picture != "person.jpeg") {
        std::cout << "Usage: extra9 [car.jpeg / house.jpeg / mountain.jpeg / person.jpeg]\n";
        return 1;
    }

    std::string filterChoice;
    std::cout << "What filter do you want (black and white/blur)? ";
    std::cin >> filterChoice;

    cv::Mat image = cv::imread(picture);
    
    if (image.empty()) {
        std::cout << "Error loading image!\n";
        return 1;
    }

    if (filterChoice == "black" || filterChoice == "black and white") {
        cv::Mat grayImage;
        cv::cvtColor(image, grayImage, cv::COLOR_BGR2GRAY);
        cv::imwrite("post_" + picture, grayImage);
    } 
    else if (filterChoice == "blur") {
        cv::Mat blurredImage;
        cv::GaussianBlur(image, blurredImage, cv::Size(5, 5), 0);
        cv::imwrite("post_" + picture, blurredImage);
    } 
    else {
        std::cout << "Invalid filter choice!\n";
    }

    return 0;
}
