#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;

struct Pixel {
    unsigned int r;  // value for red
    unsigned int g;  // value for green
    unsigned int b;  // value for blue
};

struct PpmArray {
    int size;      // number of pixels the array currently holds
    int capacity;  // number of pixels the array could hold, given current
                   // memory allocation to pixels
    int width;     // width of image
    int height;    // height of image
    Pixel *pixels;
};

static void ppmstore(int r, int g, int b, PpmArray& ppm);

void flipHorizontal(PpmArray &ppm);

void rotate(PpmArray &ppm);

void sepia(PpmArray &ppm);


void flipHorizontal(PpmArray &ppm)
{	
	for(int i = 0; i < ppm.size; i += ppm.width)
	{
		int chindex = ppm.width + i - 1;
		int j = i;

		while(j < chindex)
		{
			Pixel temp;
			temp.r = ppm.pixels[j].r;
			temp.g = ppm.pixels[j].g;
			temp.b = ppm.pixels[j].b;
			ppm.pixels[j].r = ppm.pixels[chindex].r;
			ppm.pixels[j].g = ppm.pixels[chindex].g;
			ppm.pixels[j].b = ppm.pixels[chindex].b;
			ppm.pixels[chindex].r = temp.r;
			ppm.pixels[chindex].g = temp.g;
			ppm.pixels[chindex].b = temp.b;
			j++;
			chindex--;
		}
	}
}

void rotate(PpmArray &ppm)
{
	Pixel* neway = new Pixel [ppm.capacity];
	int temp;

	for(int i = 0; i < ppm.width; i++)
	{
		for(int j = 0; j < ppm.height; j++)
		{
			neway[i * ppm.height + j].r = ppm.pixels[ppm.width * (ppm.height - j - 1) + i].r;
			neway[i * ppm.height + j].g = ppm.pixels[ppm.width * (ppm.height - j - 1) + i].g;
			neway[i * ppm.height + j].b = ppm.pixels[ppm.width * (ppm.height - j - 1) + i].b;		
		}
	}

	delete [] ppm.pixels;
	ppm.pixels = neway;

	temp = ppm.width;
	ppm.width = ppm.height;
	ppm.height = temp;
}

void sepia(PpmArray &ppm)
{
	Pixel* neway = new Pixel [ppm.capacity];

	for(int i = 0; i < ppm.size; i++)
	{
		Pixel temp = ppm.pixels[i];

		neway[i].r = temp.r * 0.393 + temp.g * 0.769 + temp.b * 0.189;
		neway[i].g = temp.r * 0.349 + temp.g * 0.686 + temp.b * 0.168;
		neway[i].b = temp.r * 0.272 + temp.g * 0.534 + temp.b * 0.131;

		if(neway[i].r > 255)
		{
			neway[i].r = 255;
		}

		if(neway[i].g > 255)
		{
			neway[i].g = 255;
		}

		if(neway[i].b > 255)
		{
			neway[i].b = 255;
		}
	}

	delete [] ppm.pixels;
	ppm.pixels = neway;
}



int main()
{
	int num, count=0, red, green, blue, cwidth=0;
	PpmArray ppm;
	ppm.size = 0;
	ppm.capacity =0;
	string trans;


	while(cin >> num)
	{
		if(count == 0)
		{
			red = num;
			count++; continue;
		}
		if (count == 1)
		{
			green = num;
			count++; continue;
		}
		if(count == 2)
		{
			blue = num;
			if(red > 255 || green > 255 || blue > 255 ||
				red < 0 || green < 0 || blue < 0)
			{
				cerr << "Pixel value out of range." << endl;
				return 1;
			}
			ppmstore(red, green, blue, ppm);
			count = 0;
		}

	}

	cin.clear();

	if(count == 2)
	{
		int total = red * green;
		if (total != ppm.size)
		{
			cerr << "Invalid pixel data" << endl;
			return 1;
		}
		ppm.width = red;
		ppm.height = green;
	}
	else
	{
		cerr << "Invalid pixel data" << endl;
		return 1;
	}

	while(cin >> trans)
	{
		if(trans == "rotate")
		{
			rotate(ppm); continue;
		}
		if(trans == "flip")
		{
			flipHorizontal(ppm); continue;
		}
		if(trans == "sepia")
		{
			sepia(ppm); continue;
		}
		cerr << "Invalid transformation command" << endl;
		return 1;	
	}

	cin.clear();

	if(ppm.size == 0)
	{
		return 0;
	}

	cout << "P3" << endl
	     << ppm.width << " " << ppm.height << endl
	     << "255" << endl;

	for(int index = 0; index < ppm.size; index++)
	{
		cout << ppm.pixels[index].r << " "
		     << ppm.pixels[index].g << " "
		     << ppm.pixels[index].b << " ";

		cwidth++;

		if(cwidth == ppm.width)
		{
			cout << endl;
			cwidth = 0;
		}		
	}

	delete [] ppm.pixels;

	return 0;
}

static void ppmstore(int r, int g, int b, PpmArray& ppm)
{
	if(ppm.capacity == 0)
	{
		ppm.pixels = new Pixel [5];
		ppm.capacity = 5;
	}

	if(ppm.size == ppm.capacity)
	{
		Pixel* resize = new Pixel [ppm.size*2];
		for(int i = 0; i < ppm.size; i++)
		{
			resize[i].r = ppm.pixels[i].r;
			resize[i].g = ppm.pixels[i].g;
			resize[i].b = ppm.pixels[i].b;
		}
		delete [] ppm.pixels;
		ppm.pixels = resize;
		ppm.capacity *= 2;
	}

	ppm.pixels[ppm.size].r = r;
	ppm.pixels[ppm.size].g = g;
	ppm.pixels[ppm.size].b = b;

	ppm.size++;
}


