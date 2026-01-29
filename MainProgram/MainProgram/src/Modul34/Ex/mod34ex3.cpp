#include <filesystem>
#include "header_modul34.h"

void mod34ex3() {
    std::cout << "3. Задание 3.\n";
    auto recursiveGetFileNamesByExtension =
            [](const std::filesystem::path &path,
               const std::string &extension) {
        std::vector<std::filesystem::path> fileNames;
        for (auto p: std::filesystem::recursive_directory_iterator(path)) {
            std::cout << p.path() << "\n";
            if (is_regular_file(p) && !p.path().extension().compare(extension)) {
                fileNames.push_back(p);
            }
        }
        return fileNames;
    };
    auto fileNames = recursiveGetFileNamesByExtension(
        "C:\\Users\\Linad\\Downloads\\", ".torrent");
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    for (const auto &i: fileNames) std::cout << i << "\n";
}
