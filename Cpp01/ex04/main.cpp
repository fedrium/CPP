#include "Sed.hpp"

int main(int argc, char **argv)
{
	std::string file, line, s1, s2, res;
	std::ifstream fileName;
	int pos, currentPos;

	if (argc != 4)
	{
		std::cout << "invalid parameter" << std::endl;
	}
	currentPos = 0;
	s1 = argv[2];
	s2 = argv[3];
	fileName.open(argv[1]);
	while (getline(fileName, line))
		file.append(line).append("\n");
	while (file.find(s1, currentPos) != std::string::npos)
	{
		pos = file.find(s1, currentPos);
		res.append(file.substr(currentPos, pos - 1));
		res.append(s2);
		currentPos = pos + s1.size();
		// std::cout << res;
	}
	std::cout << currentPos;
	res.append(file.substr(currentPos + s1.size(), file.size()));
	std::cout << res;
}