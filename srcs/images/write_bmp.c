#include <unistd.h>
#include <stdint.h>
#include <fcntl.h>

int	write_bmp(const char *path, const char *buffer, uint16_t w, uint16_t h)
{
	char	file_header[14] = {'B','M', 0,0,0,0, 0,0, 0,0, 26,0,0,0};
	char	dib_header[12] = {12,0,0,0, 0,0, 0,0, 1,0, 24,0};
	int		file_size = 26 + 3 * w * h;
	int		fd;
	int		i;

	file_header[2] = (unsigned char) (file_size);
	file_header[3] = (unsigned char) (file_size >> 8);
	file_header[4] = (unsigned char) (file_size >> 16);
	file_header[5] = (unsigned char) (file_size >> 24);
	dib_header[4] = (unsigned char) (w);
	dib_header[5] = (unsigned char) (w >> 8);
	dib_header[6] = (unsigned char) (h);
	dib_header[7] = (unsigned char) (h >> 8);
	if ((fd = open(path, O_WRONLY)) < 0)
	{	
		close(fd);
		return (-1);
	}
	if (write(fd, file_header, 14) == -1 || write(fd, dib_header, 12) == -1)
	{	
		close(fd);
		return (-1);
	}
	i = 0;
	if ((write (fd, buffer, w * h * 3) == -1))
	{	
		close(fd);
		return (-1);
	}
	close (fd);
	return (1);
}
