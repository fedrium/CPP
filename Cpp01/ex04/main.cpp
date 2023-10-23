#include "Sed.hpp"

int main(int argc, char **argv)
{
	std::string file, line, s1, s2, res, outputName;
	std::ifstream fileName;
	int pos, currentPos;

	if (argc != 4)
	{
		std::cout << "invalid parameter" << std::endl;
	}
	currentPos = 0;
	s1 = argv[2];
	s2 = argv[3];
	fileName.open(argv[1], std::ios::in);
	while (getline(fileName, line))
		file.append(line).append("\n");
	while (file.find(s1, currentPos) != std::string::npos)
	{
		pos = file.find(s1, currentPos);
		res.append(file.substr(currentPos, pos - currentPos));
		res.append(s2);
		currentPos = pos + s1.length();
	}
	res.append(file.substr(currentPos, file.length() - currentPos));
	// std::cout << res;

	outputName = argv[1];
	outputName.append(".replace");

	std::ofstream output(outputName);
	output << res;
	output.close();
}