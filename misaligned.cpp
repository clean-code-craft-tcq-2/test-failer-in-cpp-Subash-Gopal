#include <iostream>
#include <assert.h>
#include <iomanip>
#include <sstream>
using namespace std;

const char* majorColor[] = { "White", "Red", "Black", "Yellow", "Violet" };
const char* minorColor[] = { "Blue", "Orange", "Green", "Brown", "Slate" };

std::string formatColorPairEntry(int majorColorIndex, int minorColorIndex) {
    ostringstream oss;
    auto cout_buff = cout.rdbuf(oss.rdbuf());
	cout<<std::setw(2)<<std::left<< majorColorIndex * 5 + minorColorIndex <<std::left << std::setw(3) << " | " << std::left << std::setw(6) << majorColor[majorColorIndex] << std::left << std::setw(3) << " | " << std::left << std::setw(3) << minorColor[minorColorIndex] << "\n";	  cout.rdbuf (cout_buff);
	cout.rdbuf(cout_buff);
    std::string formattedColorPairEntry  = oss.str();
	return formattedColorPairEntry;
}

int printColorMap ()
{
  const char *majorColor[] = { "White", "Red", "Black", "Yellow", "Violet" };
  const char *minorColor[] = { "Blue", "Orange", "Green", "Brown", "Slate" };
  int i = 0, j = 0;
  for (i = 0; i < 5; i++)
  {
      for (j = 0; j < 5; j++)
	{
	  std:string pairEntry = formatColorPairEntry(i,j);
	  cout<<pairEntry;
	}
  }
  return i * j;
}

void testColorPairEntry(std::string actualColorPairEntry, std::string expectedColorPairEntry)
{
	assert(expectedColorPairEntry.compare(actualColorPairEntry) == 0);
}

int main ()
{
  int result = printColorMap ();
  assert (result == 25);
  testColorPairEntry(formatColorPairEntry(0, 0), "1  | White  | Blue\n");
  testColorPairEntry(formatColorPairEntry(0, 1), "2  | White  | Orange\n");
  testColorPairEntry(formatColorPairEntry(0, 2), "3  | White  | Green\n");
  testColorPairEntry(formatColorPairEntry(0, 3), "4  | White  | Brown\n");
  testColorPairEntry(formatColorPairEntry(0, 4), "5  | White  | Slate\n");
  testColorPairEntry(formatColorPairEntry(1, 1), "7  | Red    | Orange\n");
  testColorPairEntry(formatColorPairEntry(3, 0), "16 | Yellow | Blue\n");
  testColorPairEntry(formatColorPairEntry(4, 4), "25 | Violet | Slate\n");
  
  std::cout << "All is well (maybe!)\n";
  
  return 0;
}
