#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {
    std::string filename = "videosubs.txt";

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return 1;
    }

    std::string line;
    std::vector<std::string> lines;
    while (std::getline(file, line, '\n')) {
        lines.push_back(line);
    }

    file.close();

    std::vector<std::string> reslines;
    for(int h = 0; h<1; h++) {
        reslines.clear();
        for(int i = 0; i<lines.size(); i++) {
            if(!(i>0 && lines[i-1].size()==0 && lines[i].size()!=0)) {
                reslines.push_back(lines[i]);
            }
        }
        lines = reslines;
    }

    for(int i = reslines.size()-1; i>=0; i--) {
        if(reslines[i].size()==29 && reslines[i].substr(12,5)==" --> ")
	    reslines.erase(reslines.begin()+i);
    }

    lines = reslines;
    reslines.clear();
    for(int i = 0; i<lines.size(); i++) {
        if(!(i>0 && lines[i-1].size()==0 && lines[i].size()!=0)) {
            reslines.push_back(lines[i]);
        }
    }


    for(int i = 0; i<reslines.size(); i++)
    if(reslines[i].size()>0)
    printf("%s", reslines[i].c_str());

    return 0;
}
