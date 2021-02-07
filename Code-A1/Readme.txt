BITMAP FORMAT
BMP files begin with a 54-byte header:
offset		size		description
  18		 4  	      image width in pixels
  22  		 4            image height in pixels
  28   		 2            number of bits per pixel (1, 4, 8, or 24)

http://www.fastgraph.com/help/bmp_header_format.html