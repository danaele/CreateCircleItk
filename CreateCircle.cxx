//Create Circle Image


#include "itkImage.h"
#include "itkImageFileWriter.h"
#include "itkImageRegionIterator.h"


int main( int argc , char *argv[])
{
  //Define image type
  //typedef unsigned char PixelType;
  //typedef unsigned int Dimension;
  typedef itk::Image <  unsigned char, 2> ImageType;

  ImageType::IndexType start;
  start[0]=0;
  start[1]=0;

  ImageType::SizeType size;
  size[0]=300;
  size[1]=300;

  ImageType::RegionType region;

  region.SetSize(size);
  region.SetIndex(start);

  ImageType::Pointer image = ImageType::New();
  image->SetRegions(region);
  image->Allocate();

  //iterator
  itk::ImageRegionIterator<ImageType> imageIterator(image,region);
  imageIterator.GoToBegin();
  while(!imageIterator.IsAtEnd())
     {
      int xIndex= imageIterator.GetIndex()[0] - size[0]/2;
      int yIndex = imageIterator.GetIndex()[1] - size[1]/2;
      int radius=100;

      if ((xIndex*xIndex)+(yIndex*yIndex)<(radius*radius))

        {
          imageIterator.Set(0);
        }
      else
        {
          imageIterator.Set(255);
        }


     ++imageIterator;
     }


  //Write Image
  typedef itk::ImageFileWriter< ImageType > WriterType ;
  WriterType::Pointer writer = WriterType::New();
  writer->SetInput( image );
  writer->SetFileName( argv[1]) ;
  writer->Update();

  return EXIT_SUCCESS;
}
