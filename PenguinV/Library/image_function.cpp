#include "image_function.h"

namespace Image_Function
{
	template <uint8_t bytes>
	void ParameterValidation( const BitmapImage <bytes> & image1 )
	{
		if( image1.empty() )
			throw imageException("Bad input parameters in image function");
	}

	template <uint8_t bytes1, uint8_t bytes2>
	void ParameterValidation( const BitmapImage <bytes1> & image1, const BitmapImage <bytes2> & image2 )
	{
		if( image1.empty() || image2.empty() || image1.width() != image2.width() || image1.height() != image2.height() )
			throw imageException("Bad input parameters in image function");
	}

	template <uint8_t bytes1, uint8_t bytes2, uint8_t bytes3>
	void ParameterValidation( const BitmapImage <bytes1> & image1, const BitmapImage <bytes2> & image2, const BitmapImage <bytes3> & image3 )
	{
		if( image1.empty() || image2.empty() || image3.empty() || image1.width() != image2.width() || image1.height() != image2.height() ||
			image1.width() != image3.width() || image1.height() != image3.height() )
			throw imageException("Bad input parameters in image function");
	}

	template <uint8_t bytes>
	void ParameterValidation( const BitmapImage <bytes> & image, uint32_t startX, uint32_t startY, uint32_t width, uint32_t height )
	{
		if( image.empty() || width == 0 || height == 0 || startX + width > image.width() || startY + height > image.height() )
			throw imageException("Bad input parameters in image function");
	}

	template <uint8_t bytes1, uint8_t bytes2>
	void ParameterValidation( const BitmapImage <bytes1> & image1, uint32_t startX1, uint32_t startY1, const BitmapImage <bytes2> & image2,
							  uint32_t startX2, uint32_t startY2, uint32_t width, uint32_t height )
	{
		if( image1.empty() || image2.empty() || width == 0 || height == 0 ||
			startX1 + width > image1.width() || startY1 + height > image1.height() ||
			startX2 + width > image2.width() || startY2 + height > image2.height() )
			throw imageException("Bad input parameters in image function");
	}

	template <uint8_t bytes1, uint8_t bytes2, uint8_t bytes3>
	void ParameterValidation( const BitmapImage <bytes1> & image1, uint32_t startX1, uint32_t startY1, const BitmapImage <bytes2> & image2,
							  uint32_t startX2, uint32_t startY2, const BitmapImage <bytes3> & image3, uint32_t startX3, uint32_t startY3,
							  uint32_t width, uint32_t height )
	{
		if( image1.empty() || image2.empty() || image3.empty() || width == 0 || height == 0 ||
			startX1 + width > image1.width() || startY1 + height > image1.height() ||
			startX2 + width > image2.width() || startY2 + height > image2.height() ||
			startX3 + width > image3.width() || startY3 + height > image3.height() )
			throw imageException("Bad input parameters in image function");
	}


	Image BitwiseAnd( const Image & in1, const Image & in2 )
	{
		ParameterValidation( in1, in2 );

		Image out( in1.width(), in1.height() );

		BitwiseAnd( in1, 0, 0, in2, 0, 0, out, 0, 0, out.width(), out.height() );

		return out;
	}

	void BitwiseAnd( const Image & in1, const Image & in2, Image & out )
	{
		ParameterValidation( in1, in2, out );

		BitwiseAnd( in1, 0, 0, in2, 0, 0, out, 0, 0, out.width(), out.height() );
	}

	Image BitwiseAnd( const Image & in1, uint32_t startX1, uint32_t startY1, const Image & in2, uint32_t startX2, uint32_t startY2,
					  uint32_t width, uint32_t height )
	{
		ParameterValidation( in1, startX1, startY1, in2, startX2, startY2, width, height );

		Image out( width, height );

		BitwiseAnd( in1, startX1, startY1, in2, startX2, startY2, out, 0, 0, out.width(), out.height() );

		return out;
	}

	void BitwiseAnd( const Image & in1, uint32_t startX1, uint32_t startY1, const Image & in2, uint32_t startX2, uint32_t startY2,
					 Image & out, uint32_t startXOut, uint32_t startYOut, uint32_t width, uint32_t height )
	{
		ParameterValidation( in1, startX1, startY1, in2, startX2, startY2, out, startXOut, startYOut, width, height );

		uint32_t rowSize1   = in1.rowSize();
		uint32_t rowSize2   = in2.rowSize();
		uint32_t rowSizeOut = out.rowSize();

		const uint8_t * in1Y = in1.data() + startY1   * rowSize1   + startX1;
		const uint8_t * in2Y = in2.data() + startY2   * rowSize2   + startX2;
		uint8_t       * outY = out.data() + startYOut * rowSizeOut + startXOut;

		const uint8_t * outYEnd = outY + height * rowSizeOut;

		for( ; outY != outYEnd; outY += rowSizeOut, in1Y += rowSize1, in2Y += rowSize2 ) {
			const uint8_t * in1X = in1Y;
			const uint8_t * in2X = in2Y;
			uint8_t       * outX = outY;

			const uint8_t * outXEnd = outX + width;

			for( ; outX != outXEnd; ++outX, ++in1X, ++in2X )
				(*outX) = (*in1X) & (*in2X);
		}
	}

	Image BitwiseOr( const Image & in1, const Image & in2 )
	{
		ParameterValidation( in1, in2 );

		Image out( in1.width(), in1.height() );

		BitwiseOr( in1, 0, 0, in2, 0, 0, out, 0, 0, out.width(), out.height() );

		return out;
	}

	void BitwiseOr( const Image & in1, const Image & in2, Image & out )
	{
		ParameterValidation( in1, in2, out );

		BitwiseOr( in1, 0, 0, in2, 0, 0, out, 0, 0, out.width(), out.height() );
	}

	Image BitwiseOr( const Image & in1, uint32_t startX1, uint32_t startY1, const Image & in2, uint32_t startX2, uint32_t startY2,
					 uint32_t width, uint32_t height )
	{
		ParameterValidation( in1, startX1, startY1, in2, startX2, startY2, width, height );

		Image out( width, height );

		BitwiseOr( in1, startX1, startY1, in2, startX2, startY2, out, 0, 0, out.width(), out.height() );

		return out;
	}

	void BitwiseOr( const Image & in1, uint32_t startX1, uint32_t startY1, const Image & in2, uint32_t startX2, uint32_t startY2,
					Image & out, uint32_t startXOut, uint32_t startYOut, uint32_t width, uint32_t height )
	{
		ParameterValidation( in1, startX1, startY1, in2, startX2, startY2, out, startXOut, startYOut, width, height );

		uint32_t rowSize1   = in1.rowSize();
		uint32_t rowSize2   = in2.rowSize();
		uint32_t rowSizeOut = out.rowSize();

		const uint8_t * in1Y = in1.data() + startY1   * rowSize1   + startX1;
		const uint8_t * in2Y = in2.data() + startY2   * rowSize2   + startX2;
		uint8_t       * outY = out.data() + startYOut * rowSizeOut + startXOut;

		const uint8_t * outYEnd = outY + height * rowSizeOut;

		for( ; outY != outYEnd; outY += rowSizeOut, in1Y += rowSize1, in2Y += rowSize2 ) {
			const uint8_t * in1X = in1Y;
			const uint8_t * in2X = in2Y;
			uint8_t       * outX = outY;

			const uint8_t * outXEnd = outX + width;

			for( ; outX != outXEnd; ++outX, ++in1X, ++in2X )
				(*outX) = (*in1X) | (*in2X);
		}
	}

	Image BitwiseXor( const Image & in1, const Image & in2 )
	{
		ParameterValidation( in1, in2 );

		Image out( in1.width(), in1.height() );

		BitwiseXor( in1, 0, 0, in2, 0, 0, out, 0, 0, out.width(), out.height() );

		return out;
	}

	void BitwiseXor( const Image & in1, const Image & in2, Image & out )
	{
		ParameterValidation( in1, in2, out );

		BitwiseXor( in1, 0, 0, in2, 0, 0, out, 0, 0, out.width(), out.height() );
	}

	Image BitwiseXor( const Image & in1, uint32_t startX1, uint32_t startY1, const Image & in2, uint32_t startX2, uint32_t startY2,
					  uint32_t width, uint32_t height )
	{
		ParameterValidation( in1, startX1, startY1, in2, startX2, startY2, width, height );

		Image out( width, height );

		BitwiseXor( in1, startX1, startY1, in2, startX2, startY2, out, 0, 0, out.width(), out.height() );

		return out;
	}

	void BitwiseXor( const Image & in1, uint32_t startX1, uint32_t startY1, const Image & in2, uint32_t startX2, uint32_t startY2,
					 Image & out, uint32_t startXOut, uint32_t startYOut, uint32_t width, uint32_t height )
	{
		ParameterValidation( in1, startX1, startY1, in2, startX2, startY2, out, startXOut, startYOut, width, height );

		uint32_t rowSize1   = in1.rowSize();
		uint32_t rowSize2   = in2.rowSize();
		uint32_t rowSizeOut = out.rowSize();

		const uint8_t * in1Y = in1.data() + startY1   * rowSize1   + startX1;
		const uint8_t * in2Y = in2.data() + startY2   * rowSize2   + startX2;
		uint8_t       * outY = out.data() + startYOut * rowSizeOut + startXOut;

		const uint8_t * outYEnd = outY + height * rowSizeOut;

		for( ; outY != outYEnd; outY += rowSizeOut, in1Y += rowSize1, in2Y += rowSize2 ) {
			const uint8_t * in1X = in1Y;
			const uint8_t * in2X = in2Y;
			uint8_t       * outX = outY;

			const uint8_t * outXEnd = outX + width;

			for( ; outX != outXEnd; ++outX, ++in1X, ++in2X )
				(*outX) = (*in1X) ^ (*in2X);
		}
	}

	void Convert( const Image & in, ColorImage & out )
	{
		ParameterValidation( in, out );

		Convert(in, 0, 0, out, 0, 0, out.width(), out.height());
	}

	void Convert( const ColorImage & in, Image & out )
	{
		ParameterValidation( in, out );

		Convert(in, 0, 0, out, 0, 0, out.width(), out.height());
	}

	void Convert( const Image & in, uint32_t startXIn, uint32_t startYIn, ColorImage & out, uint32_t startXOut, uint32_t startYOut,
				  uint32_t width, uint32_t height )
	{
		ParameterValidation(in, startXIn, startYIn, width, height);
		ParameterValidation(out, startXOut, startYOut, width, height);

		uint32_t rowSizeIn  = in.rowSize();
		uint32_t rowSizeOut = out.rowSize();

		const uint8_t * inY  = in.data()  + startYIn  * rowSizeIn  + startXIn;
		uint8_t       * outY = out.data() + startYOut * rowSizeOut + startXOut;

		const uint8_t * outYEnd = outY + height * rowSizeOut;

		for (; outY != outYEnd; outY += rowSizeOut, inY += rowSizeIn) {
			const uint8_t * inX  = inY;
			uint8_t       * outX = outY;

			const uint8_t * outXEnd = outX + width * 3;

			for (; outX != outXEnd; outX += 3, ++inX)
				*(outX) = *(outX + 1) = *(outX + 2) = (*inX);
		}
	}

	void Convert( const ColorImage & in, uint32_t startXIn, uint32_t startYIn, Image & out, uint32_t startXOut, uint32_t startYOut,
				  uint32_t width, uint32_t height )
	{
		ParameterValidation(in, startXIn, startYIn, width, height);
		ParameterValidation(out, startXOut, startYOut, width, height);

		uint32_t rowSizeIn  = in.rowSize();
		uint32_t rowSizeOut = out.rowSize();

		const uint8_t * inY  = in.data()  + startYIn  * rowSizeIn  + startXIn;
		uint8_t       * outY = out.data() + startYOut * rowSizeOut + startXOut;

		const uint8_t * outYEnd = outY + height * rowSizeOut;

		for (; outY != outYEnd; outY += rowSizeOut, inY += rowSizeIn) {
			const uint8_t * inX = inY;
			uint8_t       * outX = outY;

			const uint8_t * outXEnd = outX + width;

			for (; outX != outXEnd; ++outX, inX += 3)
				(*outX) = static_cast <uint8_t>( ( *(inX) + *(inX + 1) + *(inX + 2) ) / 3 ); // average of red, green and blue components
		}
	}

	void Copy( const Image & in, Image & out )
	{
		ParameterValidation( in, out );

		out = in;
	}

	Image Copy( const Image & in, uint32_t startXIn, uint32_t startYIn, uint32_t width, uint32_t height )
	{
		ParameterValidation( in, startXIn, startYIn, width, height );

		Image out( width, height );

		Copy( in, startXIn, startYIn, out, 0, 0, width, height );

		return out;
	}

	void Copy( const Image & in, uint32_t startXIn, uint32_t startYIn, Image & out, uint32_t startXOut, uint32_t startYOut,
			   uint32_t width, uint32_t height )
	{
		ParameterValidation( in, startXIn, startYIn, out, startXOut, startYOut, width, height );

		uint32_t rowSizeIn  = in.rowSize();
		uint32_t rowSizeOut = out.rowSize();

		const uint8_t * inY  = in.data()  + startYIn  * rowSizeIn  + startXIn;
		uint8_t       * outY = out.data() + startYOut * rowSizeOut + startXOut;

		const uint8_t * outYEnd = outY + height * rowSizeOut;

		for( ; outY != outYEnd; outY += rowSizeOut, inY += rowSizeIn )
			memcpy( outY, inY, sizeof(uint8_t) * width );
	}

	void Fill( Image & image, uint8_t value )
	{
		image.fill( value );
	}

	void Fill( Image & image, uint32_t x, int32_t y, uint32_t width, uint32_t height, uint8_t value )
	{
		ParameterValidation( image, x, y, width, height );

		uint32_t rowSize = image.rowSize();

		uint8_t * imageY = image.data() + y * rowSize + x;
		const uint8_t * imageYEnd = imageY + height * rowSize;

		for( ; imageY != imageYEnd; imageY += rowSize )
			memset( imageY, value, sizeof(uint8_t) * width );
	}

	Image Flip( const Image & in, bool horizontal, bool vertical )
	{
		ParameterValidation( in );

		Image out( in.width(), in.height() );

		Flip( in, 0, 0, out, 0, 0, out.width(), out.height(), horizontal, vertical );

		return out;
	}

	void Flip( const Image & in, Image & out, bool horizontal, bool vertical )
	{
		ParameterValidation( in, out );

		Flip( in, 0, 0, out, 0, 0, out.width(), out.height(), horizontal, vertical );
	}

	Image Flip( const Image & in, uint32_t startXIn, uint32_t startYIn, uint32_t width, uint32_t height,
				bool horizontal, bool vertical)
	{
		ParameterValidation( in, startXIn, startYIn, width, height );

		Image out( width, height );

		Flip( in, startXIn, startYIn, out, 0, 0, width, height, horizontal, vertical );

		return out;
	}

	void Flip( const Image & in, uint32_t startXIn, uint32_t startYIn, Image & out, uint32_t startXOut, uint32_t startYOut,
			   uint32_t width, uint32_t height, bool horizontal, bool vertical )
	{
		ParameterValidation( in, startXIn, startYIn, out, startXOut, startYOut, width, height );

		if( !horizontal && !vertical ) {
			Copy( in, startXIn, startYIn, out, startXOut, startYOut, width, height );
		}
		else {
			uint32_t rowSizeIn  = in.rowSize();
			uint32_t rowSizeOut = out.rowSize();

			const uint8_t * inY    = in.data() + startYIn * rowSizeIn + startXIn;
			const uint8_t * inYEnd = inY + height * rowSizeIn;

			if( horizontal && !vertical ) {
				uint8_t * outY = out.data() + startYOut * rowSizeOut + startXOut + width - 1;

				for( ; inY != inYEnd; inY += rowSizeIn, outY += rowSizeOut ) {
					const uint8_t * inX    = inY;
					uint8_t       * outX   = outY;
					const uint8_t * inXEnd = inX + width;

					for( ; inX != inXEnd; ++inX, --outX )
						(*outX) = (*inX);
				}
			}
			else if( !horizontal && vertical ) {
				uint8_t * outY = out.data() + (startYOut + height - 1) * rowSizeOut + startXOut;

				for( ; inY != inYEnd; inY += rowSizeIn, outY -= rowSizeOut )
					memcpy( outY, inY, sizeof(uint8_t) * width );
			}
			else {
				uint8_t * outY = out.data() + (startYOut + height - 1) * rowSizeOut + startXOut + width - 1;

				for( ; inY != inYEnd; inY += rowSizeIn, outY -= rowSizeOut ) {
					const uint8_t * inX    = inY;
					uint8_t       * outX   = outY;
					const uint8_t * inXEnd = inX + width;

					for( ; inX != inXEnd; ++inX, --outX )
						(*outX) = (*inX);
				}
			}
		}
	}

	uint8_t GetPixel( const Image & image, uint32_t x, uint32_t y )
	{
		if( image.empty() || x >= image.width() || y >= image.height() )
			throw imageException("Bad input parameters in image function");

		return *(image.data() + y * image.rowSize() + x);
	}

	uint8_t GetThreshold( const std::vector < uint32_t > & histogram )
	{
		if( histogram.size() != 256 )
			throw imageException("Histogram size is not 256");

		uint8_t threshold = 0;

		// It is well-known Otsu's method to find threshold
		uint32_t pixelCount = histogram[0] + histogram[1];
		uint32_t sum = histogram[1];
		for(uint16_t i = 2; i < 256; ++i) {
			sum  = sum  + i * histogram[i];
			pixelCount += histogram[i];
		}

		uint32_t sumTemp = 0;
		uint32_t pixelCountTemp = 0;
		
		double maximumSigma = -1;

		for(uint16_t i = 0; i < 256; ++i) {
			pixelCountTemp += histogram[i];

			if(pixelCountTemp > 0 && pixelCountTemp != pixelCount) {
				sumTemp += i * histogram[i];

				double w1 = static_cast<double>(pixelCountTemp) / pixelCount;
				double a  = static_cast<double>(sumTemp       ) / pixelCountTemp -
						    static_cast<double>(sum - sumTemp ) / (pixelCount - pixelCountTemp);
				double sigma = w1 * (1 - w1) * a * a;

				if(sigma > maximumSigma) {
					maximumSigma = sigma;
					threshold = static_cast < uint8_t >(i);
				}
			}
		}

		return threshold;
	}

	std::vector < uint32_t > Histogram( const Image & image )
	{
		std::vector < uint32_t > histogram;

		Histogram( image, 0, 0, image.width(), image.height(), histogram );

		return histogram;
	}

	void Histogram( const Image & image, std::vector < uint32_t > & histogram )
	{
		Histogram( image, 0, 0, image.width(), image.height(), histogram );
	}

	std::vector < uint32_t > Histogram( const Image & image, uint32_t x, int32_t y, uint32_t width, uint32_t height )
	{
		ParameterValidation( image, x, y, width, height );

		std::vector < uint32_t > histogram;

		Histogram( image, x, y, width, height, histogram );

		return histogram;
	}

	void Histogram( const Image & image, uint32_t x, int32_t y, uint32_t width, uint32_t height, std::vector < uint32_t > & histogram )
	{
		ParameterValidation( image, x, y, width, height );

		histogram.resize( 256u );
		std::fill( histogram.begin(), histogram.end(), 0u );

		uint32_t rowSize = image.rowSize();

		const uint8_t * imageY = image.data() + y * rowSize + x;
		const uint8_t * imageYEnd = imageY + height * rowSize;

		for( ; imageY != imageYEnd; imageY += rowSize ) {
			const uint8_t * imageX    = imageY;
			const uint8_t * imageXEnd = imageX + width;

			for( ; imageX != imageXEnd; ++imageX )
				++histogram[*imageX];
		}
	}

	Image Invert( const Image & in )
	{
		ParameterValidation( in );

		Image out( in.width(), in.height() );

		Invert( in, 0, 0, out, 0, 0, out.width(), out.height() );

		return out;
	}

	void Invert( const Image & in, Image & out )
	{
		ParameterValidation( in, out );

		Invert( in, 0, 0, out, 0, 0, out.width(), out.height() );
	}

	Image Invert( const Image & in, uint32_t startXIn, uint32_t startYIn, uint32_t width, uint32_t height )
	{
		ParameterValidation( in, startXIn, startYIn, width, height );

		Image out( width, height );

		Invert( in, startXIn, startYIn, out, 0, 0, width, height );

		return out;
	}

	void Invert( const Image & in, uint32_t startXIn, uint32_t startYIn, Image & out, uint32_t startXOut, uint32_t startYOut,
				 uint32_t width, uint32_t height )
	{
		ParameterValidation( in, startXIn, startYIn, out, startXOut, startYOut, width, height );

		uint32_t rowSizeIn  = in.rowSize();
		uint32_t rowSizeOut = out.rowSize();

		const uint8_t * inY  = in.data()  + startYIn  * rowSizeIn  + startXIn;
		uint8_t       * outY = out.data() + startYOut * rowSizeOut + startXOut;

		const uint8_t * outYEnd = outY + height * rowSizeOut;

		for( ; outY != outYEnd; outY += rowSizeOut, inY += rowSizeIn ) {
			const uint8_t * inX  = inY;
			uint8_t       * outX = outY;

			const uint8_t * outXEnd = outX + width;

			for( ; outX != outXEnd; ++outX, ++inX )
				(*outX) = ~(*inX);
		}
	}

	bool IsEqual( const Image & in1, const Image & in2 )
	{
		ParameterValidation( in1, in2 );

		return IsEqual( in1, 0, 0, in2, 0, 0, in1.width(), in1.height() );
	}

	bool IsEqual( const Image & in1, uint32_t startX1, uint32_t startY1, const Image & in2, uint32_t startX2, uint32_t startY2,
				  uint32_t width, uint32_t height )
	{
		ParameterValidation( in1, startX1, startY1, in2, startX2, startY2, width, height );

		uint32_t rowSize1  = in1.rowSize();
		uint32_t rowSize2 = in2.rowSize();

		const uint8_t * in1Y = in1.data()  + startY1  * rowSize1  + startX1;
		const uint8_t * in2Y = in2.data()  + startY2  * rowSize2  + startX2;

		const uint8_t * in1YEnd = in1Y + height * rowSize1;

		for( ; in1Y != in1YEnd; in1Y += rowSize1, in2Y += rowSize2 ) {
			const uint8_t * in1X = in1Y;
			const uint8_t * in2X = in2Y;
			const uint8_t * in1XEnd = in1X + width;

			for( ; in1X != in1XEnd; ++in1X, ++in2X ) {
				if( (*in1X) != (*in2X) )
					return false;
			}
		}

		return true;
	}

	Image Maximum( const Image & in1, const Image & in2 )
	{
		ParameterValidation( in1, in2 );

		Image out( in1.width(), in1.height() );

		Maximum( in1, 0, 0, in2, 0, 0, out, 0, 0, out.width(), out.height() );

		return out;
	}

	void Maximum( const Image & in1, const Image & in2, Image & out )
	{
		ParameterValidation( in1, in2, out );

		Maximum( in1, 0, 0, in2, 0, 0, out, 0, 0, out.width(), out.height() );
	}

	Image Maximum( const Image & in1, uint32_t startX1, uint32_t startY1, const Image & in2, uint32_t startX2, uint32_t startY2,
				   uint32_t width, uint32_t height )
	{
		ParameterValidation( in1, startX1, startY1, in2, startX2, startY2, width, height );

		Image out( width, height );

		Maximum( in1, startX1, startY1, in2, startX2, startY2, out, 0, 0, out.width(), out.height() );

		return out;
	}
	
	void Maximum( const Image & in1, uint32_t startX1, uint32_t startY1, const Image & in2, uint32_t startX2, uint32_t startY2,
				  Image & out, uint32_t startXOut, uint32_t startYOut, uint32_t width, uint32_t height )
	{
		ParameterValidation( in1, startX1, startY1, in2, startX2, startY2, out, startXOut, startYOut, width, height );

		uint32_t rowSize1   = in1.rowSize();
		uint32_t rowSize2   = in2.rowSize();
		uint32_t rowSizeOut = out.rowSize();

		const uint8_t * in1Y = in1.data() + startY1   * rowSize1   + startX1;
		const uint8_t * in2Y = in2.data() + startY2   * rowSize2   + startX2;
		uint8_t       * outY = out.data() + startYOut * rowSizeOut + startXOut;

		const uint8_t * outYEnd = outY + height * rowSizeOut;

		for( ; outY != outYEnd; outY += rowSizeOut, in1Y += rowSize1, in2Y += rowSize2 ) {
			const uint8_t * in1X = in1Y;
			const uint8_t * in2X = in2Y;
			uint8_t       * outX = outY;

			const uint8_t * outXEnd = outX + width;

			for( ; outX != outXEnd; ++outX, ++in1X, ++in2X )
				(*outX) = (*in2X) < (*in1X) ? (*in1X) : (*in2X);
		}
	}

	Image Minimum( const Image & in1, const Image & in2 )
	{
		ParameterValidation( in1, in2 );

		Image out( in1.width(), in1.height() );

		Minimum( in1, 0, 0, in2, 0, 0, out, 0, 0, out.width(), out.height() );

		return out;
	}

	void Minimum( const Image & in1, const Image & in2, Image & out )
	{
		ParameterValidation( in1, in2, out );

		Minimum( in1, 0, 0, in2, 0, 0, out, 0, 0, out.width(), out.height() );
	}

	Image Minimum( const Image & in1, uint32_t startX1, uint32_t startY1, const Image & in2, uint32_t startX2, uint32_t startY2,
				   uint32_t width, uint32_t height )
	{
		ParameterValidation( in1, startX1, startY1, in2, startX2, startY2, width, height );

		Image out( width, height );

		Minimum( in1, startX1, startY1, in2, startX2, startY2, out, 0, 0, out.width(), out.height() );

		return out;
	}

	void Minimum( const Image & in1, uint32_t startX1, uint32_t startY1, const Image & in2, uint32_t startX2, uint32_t startY2,
				  Image & out, uint32_t startXOut, uint32_t startYOut, uint32_t width, uint32_t height )
	{
		ParameterValidation( in1, startX1, startY1, in2, startX2, startY2, out, startXOut, startYOut, width, height );

		uint32_t rowSize1   = in1.rowSize();
		uint32_t rowSize2   = in2.rowSize();
		uint32_t rowSizeOut = out.rowSize();

		const uint8_t * in1Y = in1.data() + startY1   * rowSize1   + startX1;
		const uint8_t * in2Y = in2.data() + startY2   * rowSize2   + startX2;
		uint8_t       * outY = out.data() + startYOut * rowSizeOut + startXOut;

		const uint8_t * outYEnd = outY + height * rowSizeOut;

		for( ; outY != outYEnd; outY += rowSizeOut, in1Y += rowSize1, in2Y += rowSize2 ) {
			const uint8_t * in1X = in1Y;
			const uint8_t * in2X = in2Y;
			uint8_t       * outX = outY;

			const uint8_t * outXEnd = outX + width;

			for( ; outX != outXEnd; ++outX, ++in1X, ++in2X )
				(*outX) = (*in2X) > (*in1X) ? (*in1X) : (*in2X);
		}
	}

	Image Normalize( const Image & in )
	{
		ParameterValidation( in );

		Image out( in.width(), in.height() );

		Normalize( in, 0, 0, out, 0, 0, out.width(), out.height() );

		return out;
	}

	void Normalize( const Image & in, Image & out )
	{
		ParameterValidation( in, out );

		Normalize( in, 0, 0, out, 0, 0, out.width(), out.height() );
	}

	Image Normalize( const Image & in, uint32_t startXIn, uint32_t startYIn, uint32_t width, uint32_t height )
	{
		ParameterValidation( in, startXIn, startYIn, width, height );

		Image out( width, height );

		Normalize( in, startXIn, startYIn, out, 0, 0, width, height );

		return out;
	}
	
	void Normalize( const Image & in, uint32_t startXIn, uint32_t startYIn, Image & out, uint32_t startXOut, uint32_t startYOut,
					uint32_t width, uint32_t height )
	{
		ParameterValidation( in, startXIn, startYIn, out, startXOut, startYOut, width, height );

		uint32_t rowSizeIn  = in.rowSize();

		const uint8_t * inY    = in.data()  + startYIn  * rowSizeIn  + startXIn;
		const uint8_t * inYEnd = inY + height * rowSizeIn;

		uint8_t minimum = 255;
		uint8_t maximum = 0;

		for( ; inY != inYEnd; inY += rowSizeIn ) {
			const uint8_t * inX = inY;
			const uint8_t * inXEnd = inX + width;

			for( ; inX != inXEnd; ++inX ) {
				if( minimum > (*inX) )
					minimum = (*inX);

				if( maximum < (*inX) )
					maximum = (*inX);
			}
		}

		if( (minimum == 0 && maximum == 255) || (minimum == maximum) ) {
			Copy( in, startXIn, startYIn, out, startXOut, startYOut, width, height );
		}
		else {
			double correction = 255.0 / ( maximum - minimum );

			uint32_t rowSizeOut = out.rowSize();

			inY = in.data()  + startYIn  * rowSizeIn  + startXIn;
			uint8_t  * outY = out.data() + startYOut * rowSizeOut + startXOut;

			for( ; inY != inYEnd; inY += rowSizeIn, outY += rowSizeOut ) {
				const uint8_t * inX    = inY;
				uint8_t       * outX   = outY;
				const uint8_t * inXEnd = inX + width;

				for( ; inX != inXEnd; ++inX, ++outX )
					(*outX) = static_cast < uint8_t >( ( (*inX) - minimum ) * correction + 0.5);
			}
		}
	}

	std::vector < uint32_t > ProjectionProfile( const Image & image, bool horizontal )
	{
		std::vector < uint32_t > projection;

		ProjectionProfile( image, 0, 0, image.width(), image.height(), horizontal, projection );

		return projection;
	}

	void ProjectionProfile( const Image & image, bool horizontal, std::vector < uint32_t > & projection )
	{
		ProjectionProfile( image, 0, 0, image.width(), image.height(), horizontal, projection );
	}

	std::vector < uint32_t > ProjectionProfile( const Image & image, uint32_t x, int32_t y, uint32_t width, uint32_t height, bool horizontal )
	{
		std::vector < uint32_t > projection;

		ProjectionProfile( image, x, y, width, height, horizontal, projection );

		return projection;
	}

	void ProjectionProfile( const Image & image, uint32_t x, int32_t y, uint32_t width, uint32_t height, bool horizontal,
							std::vector < uint32_t > & projection )
	{
		ParameterValidation( image, x, y, width, height );

		projection.resize( horizontal ? width : height );
		std::fill( projection.begin(), projection.end(), 0u );

		uint32_t rowSize = image.rowSize();

		if( horizontal ) {
			const uint8_t * imageX = image.data() + y * rowSize + x;
			const uint8_t * imageXEnd = imageX + rowSize;

			for( ; imageX != imageXEnd; ++imageX ) {
				const uint8_t * imageY    = imageX;
				const uint8_t * imageYEnd = imageY + height * rowSize;
				std::vector < uint32_t > :: iterator data = projection.begin();

				for( ; imageY != imageYEnd; imageY += rowSize, ++data )
					(*data) += (*imageY);
			}
		}
		else {
			const uint8_t * imageY = image.data() + y * rowSize + x;
			const uint8_t * imageYEnd = imageY + height * rowSize;

			for( ; imageY != imageYEnd; imageY += rowSize ) {
				const uint8_t * imageX    = imageY;
				const uint8_t * imageXEnd = imageX + width;
				std::vector < uint32_t > :: iterator data = projection.begin();

				for( ; imageX != imageXEnd; ++imageX, ++data )
					(*data) += (*imageX);
			}
		}
	}

	Image Resize( const Image & in, uint32_t widthOut, uint32_t heightOut )
	{
		ParameterValidation( in );

		Image out( widthOut, heightOut );

		Resize( in, 0, 0, in.width(), in.height(), out, 0, 0, widthOut, heightOut );

		return out;
	}

	void Resize( const Image & in, Image & out )
	{
		ParameterValidation( in );
		ParameterValidation( out );

		Resize( in, 0, 0, in.width(), in.height(), out, 0, 0, out.width(), out.height() );
	}

	Image Resize( const Image & in, uint32_t startXIn, uint32_t startYIn, uint32_t widthIn, uint32_t heightIn,
				  uint32_t widthOut, uint32_t heightOut )
	{
		ParameterValidation( in, startXIn, startYIn, widthIn, heightIn );

		Image out( widthOut, heightOut );

		Resize( in, startXIn, startYIn, widthIn, heightIn, out, 0, 0, widthOut, heightOut );

		return out;
	}

	void Resize( const Image & in, uint32_t startXIn, uint32_t startYIn, uint32_t widthIn, uint32_t heightIn,
				 Image & out, uint32_t startXOut, uint32_t startYOut, uint32_t widthOut, uint32_t heightOut )
	{
		ParameterValidation( in,  startXIn,  startYIn,  widthIn,  heightIn );
		ParameterValidation( out, startXOut, startYOut, widthOut, heightOut );

		uint32_t rowSizeIn  = in.rowSize();
		uint32_t rowSizeOut = out.rowSize();

		const uint8_t * inY  = in.data()  + startYIn  * rowSizeIn  + startXIn;
		uint8_t       * outY = out.data() + startYOut * rowSizeOut + startXOut;

		const uint8_t * outYEnd = outY + heightOut * rowSizeOut;

		uint32_t idY = 0;

		for( ; outY != outYEnd; outY += rowSizeOut, ++idY ) {
			const uint8_t * inX  = inY + (idY * heightIn / heightOut) * rowSizeIn;
			uint8_t       * outX = outY;

			const uint8_t * outXEnd = outX + widthOut;

			uint32_t idX = 0;

			for( ; outX != outXEnd; ++outX, ++idX )
				(*outX) = *(inX + idX * widthIn / widthOut);
		}
	}

	void SetPixel( Image & image, uint32_t x, uint32_t y, uint8_t value )
	{
		if( image.empty() || x >= image.width() || y >= image.height() )
			throw imageException("Bad input parameters in image function");

		*(image.data() + y * image.rowSize() + x) = value;
	}

	void SetPixel( Image & image, const std::vector < uint32_t > & X, const std::vector < uint32_t > & Y, uint8_t value )
	{
		if( image.empty() || X.empty() || Y.empty() || X.size() != Y.size() )
			throw imageException("Bad input parameters in image function");

		uint32_t rowSize = image.rowSize();
		uint8_t * data   = image.data();

		std::vector < uint32_t >::const_iterator x   = X.begin();
		std::vector < uint32_t >::const_iterator y   = Y.begin();
		std::vector < uint32_t >::const_iterator end = X.end();

		for( ; x != end; ++x, ++y ) {
			if( (*x) >= image.width() || (*y) >= image.height() )
				throw imageException("Bad input parameters in image function");

			*(data + (*y) * rowSize + (*x)) = value;
		}
	}

	Image Subtract( const Image & in1, const Image & in2 )
	{
		ParameterValidation( in1, in2 );

		Image out( in1.width(), in1.height() );

		Subtract( in1, 0, 0, in2, 0, 0, out, 0, 0, out.width(), out.height() );

		return out;
	}

	void Subtract( const Image & in1, const Image & in2, Image & out )
	{
		ParameterValidation( in1, in2, out );

		Subtract( in1, 0, 0, in2, 0, 0, out, 0, 0, out.width(), out.height() );
	}

	Image Subtract( const Image & in1, uint32_t startX1, uint32_t startY1, const Image & in2, uint32_t startX2, uint32_t startY2,
					uint32_t width, uint32_t height )
	{
		ParameterValidation( in1, startX1, startY1, in2, startX2, startY2, width, height );

		Image out( width, height );

		Subtract( in1, startX1, startY1, in2, startX2, startY2, out, 0, 0, out.width(), out.height() );

		return out;
	}

	void Subtract( const Image & in1, uint32_t startX1, uint32_t startY1, const Image & in2, uint32_t startX2, uint32_t startY2,
				   Image & out, uint32_t startXOut, uint32_t startYOut, uint32_t width, uint32_t height )
	{
		ParameterValidation( in1, startX1, startY1, in2, startX2, startY2, out, startXOut, startYOut, width, height );

		uint32_t rowSize1   = in1.rowSize();
		uint32_t rowSize2   = in2.rowSize();
		uint32_t rowSizeOut = out.rowSize();

		const uint8_t * in1Y = in1.data() + startY1   * rowSize1   + startX1;
		const uint8_t * in2Y = in2.data() + startY2   * rowSize2   + startX2;
		uint8_t       * outY = out.data() + startYOut * rowSizeOut + startXOut;

		const uint8_t * outYEnd = outY + height * rowSizeOut;

		for( ; outY != outYEnd; outY += rowSizeOut, in1Y += rowSize1, in2Y += rowSize2 ) {
			const uint8_t * in1X = in1Y;
			const uint8_t * in2X = in2Y;
			uint8_t       * outX = outY;

			const uint8_t * outXEnd = outX + width;

			for( ; outX != outXEnd; ++outX, ++in1X, ++in2X )
				(*outX) = (*in2X) > (*in1X) ? 0 : (*in1X) - (*in2X);		
		}
	}

	uint32_t Sum( const Image & image )
	{
		return Sum( image, 0, 0, image.width(), image.height() );
	}

	uint32_t Sum( const Image & image, uint32_t x, int32_t y, uint32_t width, uint32_t height )
	{
		ParameterValidation( image, x, y, width, height );

		uint32_t rowSize = image.rowSize();

		const uint8_t * imageY    = image.data() + y * rowSize + x;
		const uint8_t * imageYEnd = imageY + height * rowSize;

		uint32_t sum = 0;

		for( ; imageY != imageYEnd; imageY += rowSize ) {
			const uint8_t * imageX    = imageY;
			const uint8_t * imageXEnd = imageX + width;

			for( ; imageX != imageXEnd; ++imageX )
				sum += (*imageX);
		}

		return sum;
	}

	Image Threshold( const Image & in, uint8_t threshold )
	{
		ParameterValidation( in );

		Image out( in.width(), in.height() );

		Threshold( in, 0, 0, out, 0, 0, out.width(), out.height(), threshold );

		return out;
	}

	void Threshold( const Image & in, Image & out, uint8_t threshold )
	{
		ParameterValidation( in, out );

		Threshold( in, 0, 0, out, 0, 0, out.width(), out.height(), threshold );
	}

	Image Threshold( const Image & in, uint32_t startXIn, uint32_t startYIn, uint32_t width, uint32_t height, uint8_t threshold )
	{
		ParameterValidation( in, startXIn, startYIn, width, height );

		Image out( width, height );

		Threshold( in, startXIn, startYIn, out, 0, 0, width, height, threshold );

		return out;
	}

	void Threshold( const Image & in, uint32_t startXIn, uint32_t startYIn, Image & out, uint32_t startXOut, uint32_t startYOut,
					uint32_t width, uint32_t height, uint8_t threshold )
	{
		ParameterValidation( in, startXIn, startYIn, out, startXOut, startYOut, width, height );

		uint32_t rowSizeIn  = in.rowSize();
		uint32_t rowSizeOut = out.rowSize();

		const uint8_t * inY  = in.data()  + startYIn  * rowSizeIn  + startXIn;
		uint8_t       * outY = out.data() + startYOut * rowSizeOut + startXOut;

		const uint8_t * outYEnd = outY + height * rowSizeOut;

		for( ; outY != outYEnd; outY += rowSizeOut, inY += rowSizeIn ) {
			const uint8_t * inX  = inY;
			uint8_t       * outX = outY;

			const uint8_t * outXEnd = outX + width;

			for( ; outX != outXEnd; ++outX, ++inX )
				(*outX) = (*inX) < threshold ? 0 : 255;
		}
	}

	Image Transpose( const Image & in )
	{
		ParameterValidation( in );

		Image out(in.height(), in.width());

		Transpose( in, 0, 0, out, 0, 0, in.width(), in.height() );

		return out;
	}

	void Transpose( const Image & in, Image & out )
	{
		ParameterValidation( in );
		ParameterValidation( out );

		Transpose( in, 0, 0, out, 0, 0, in.width(), in.height() );
	}

	Image Transpose( const Image & in, uint32_t startXIn, uint32_t startYIn, uint32_t width, uint32_t height )
	{
		ParameterValidation( in, startXIn, startYIn, width, height );

		Image out(height, width);

		Transpose( in, startXIn, startYIn, out, 0, 0, in.width(), in.height() );

		return out;
	}
	
	void Transpose( const Image & in, uint32_t startXIn, uint32_t startYIn, Image & out, uint32_t startXOut, uint32_t startYOut,
					uint32_t width, uint32_t height )
	{
		ParameterValidation( in,  startXIn,  startYIn,  width,  height );
		ParameterValidation( out, startXOut, startYOut, height, width  );

		uint32_t rowSizeIn  = in.rowSize();
		uint32_t rowSizeOut = out.rowSize();

		const uint8_t * inX  = in.data()  + startYIn  * rowSizeIn  + startXIn;
		uint8_t       * outY = out.data() + startYOut * rowSizeOut + startXOut;

		const uint8_t * outYEnd = outY + height * rowSizeOut;

		for( ; outY != outYEnd; outY += rowSizeOut, ++inX ) {
			const uint8_t * inY  = inX;
			uint8_t       * outX = outY;

			const uint8_t * outXEnd = outX + width;

			for( ; outX != outXEnd; ++outX, inY += rowSizeIn )
				(*outX) = *(inY);
		}
	}
};
