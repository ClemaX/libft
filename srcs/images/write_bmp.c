#include <unistd.h>
#include <fcntl.h>

static unsigned char	*get_file_header(int w, int h)
{
	static unsigned char	file_header[14] = {'B','M', 0,0,0,0, 0,0, 0,0, 54};
	const int				file_size = 40 + 4 * w * h;

	file_header[2] = (unsigned char) (file_size);
	file_header[3] = (unsigned char) (file_size >> 8);
	file_header[4] = (unsigned char) (file_size >> 16);
	file_header[5] = (unsigned char) (file_size >> 24);
	return (file_header);
}

static unsigned char	*get_dib_header(int w, int h)
{
	static unsigned char	dib_header[40] = {
		40,0,0,0,
		0,0,0,0,
		0,0,0,0,
		1,0, 32,0
	};

	h = -h;
	dib_header[4] = (unsigned char) (w);
	dib_header[5] = (unsigned char) (w >> 8);
	dib_header[6] = (unsigned char) (w >> 16);
	dib_header[7] = (unsigned char) (w >> 24);
	dib_header[8] = (unsigned char) (h);
	dib_header[9] = (unsigned char) (h >> 8);
	dib_header[10] = (unsigned char) (h >> 16);
	dib_header[11] = (unsigned char) (h >> 24);
	return (dib_header);
}

int					write_bmp(const char *path, const char *buffer,
	int16_t w, int16_t h)
{
	int	fd;

	if ((fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, S_IWUSR | S_IRUSR)) < 0)
	{
		close(fd);
		return (-1);
	}
	if (write(fd, get_file_header(w, h), 14) == -1
	|| write(fd, get_dib_header(w, h), 40) == -1)
	{
		close(fd);
		return (-1);
	}
	if (write(fd, buffer, 4 * w * h) == -1)
	{
		close(fd);
		return (-1);
	}
	close (fd);
	return (1);
}
