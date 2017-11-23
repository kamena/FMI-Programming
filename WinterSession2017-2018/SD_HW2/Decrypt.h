#include <fstream>

class Decrypt {
public:
	Decrypt(const char* fname, const char* ofname);
	~Decrypt();

	void decrypt(char*);
private:
	void read();
	void write(const char*);

	std::ifstream iffile_;
	std::ofstream offile_;
};