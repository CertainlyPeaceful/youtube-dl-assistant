#include <iostream>

bool isValidLink(const std::string& str) {
    static const std::string key = "https://www.youtube.com/watch?v=";
    for (int index = 0; index < key.length(); index++)
        if (str[index] != key[index])
            return false;
    return true;
}

int main() {
    std::string basic = "youtube-dl -x --audio-format ", format = "", link = "", combined = "";
    char repeat = ' ';
    do
    {
        do
        {
            std::cout << "Enter a valid audio format (aac, flac, mp3, m4a): ";
            std::cin >> format;
        } while (format != "aac" && format != "flac" && format != "mp3" && format != "m4a");
        do
        {
            std::cout << "Enter the link of the YouTube video: ";
            std::cin >> link;
        } while (!isValidLink(link));

        combined = basic + format + " " + link;
        system(combined.c_str());

        repeat = ' ';
        do
        {
            std::cout << "Continue (y/n): ";
            std::cin >> repeat;
        } while (repeat != 'y' && repeat != 'n');
    } while (repeat == 'y');
}