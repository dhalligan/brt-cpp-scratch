#include "app.h"

App::App(int& argc, char** argv) : _argc(argc), _argv(argv)
{
  std::cout << "Creating aapplication..." << std::endl;
  std::cout << "Finished." << std::endl;
}

App::~App()
{
}

int App::exec()
{
  std::cout << "Running application..." << std::endl;
  std::cout << std::endl;


  std::vector<uint8_t> matrix;
  unsigned int width;
  unsigned int height;
  if(_argc < 2)
    {
      std::cout << "Error!  Please supply a filename on the command line." << std::endl;
      return 1;
    }

  readUint8Matrix(_argv[1], matrix, height, width);
  std::cout << "Read a matrix of size [" << height << "," << width << "]." << std::endl;

  // for(unsigned int ii = 0; ii < matrix.size(); ++ii)
  //   {
  //     std::cout << (int)matrix[ii] << " ";
  //   }
  // std::cout << std::endl;
  std::cout << std::endl;
  std::cout << "** Matrix histogram **" << std::endl;
  std::cout << std::endl;
  std::cout << "* = 32 elements" << std::endl;
  std::cout << std::endl;

  Matrix m(width, height, true);
  for (int i = 0; i < height; ++i) {
    for (int j = 0; j < width; ++j) {
      m.get_uint8(i, j) = matrix[i * width + j];
    }
  }

  vector<int> histogram = m.histogram(8);
  for (int k = 0; k < histogram.size(); ++k) {
    std::cout << "[" << std::setw(3) << k * 32 << ", " << std::setw(3) << (k + 1) * 32 - 1 << "]: ";
    for (int i = 0; i < histogram[k]; ++i) {
      if (i % 32 == 0) { std::cout << "*"; }
    }
    std::cout << std::endl;
  }

  return 0;

}
