/* 
 * Kamena Dacheva, 71672
 *
 * Implementation for cropping BMP image files by reading from provided tdf file.
 * All you have to do is provide a working and existing tdf file with valid commands.
 * Ecample commands:
 *
 * ; Golden retriever thumbnail
 * dogs.bmp (0, 0, 100, 200) retriever.bmp
 * ; German shepherd thumbnail
 * dogs.bmp (100, 0, 100, 200) shepherd.bmp
 * ; Chihuahua thumbnail
 * dogs.bmp (0, 200, 100, 200) chihuahua.bmp
 * 
 * OS used: Linux
 */

#include <iostream>
#include <cstring>
#include <cstdlib>
#include "Bitmap.h"
#include "Tdf.h"

using namespace std;

int main(int argc, char const *argv[]) {
	if(argc == 1) {
		cout << "You need to enter a tdf file!" << endl;
		return 0;
	}

	if(!strstr(argv[1], ".tdf")) {
		cerr << "The file should be .tdf" << endl;
		return 0;
	}

    Tdf tdf(argv[1]);
    tdf.readAndCrop();

    return 0;
}
