#include <stddef.h>
#include <unistd.h>

// ssize_t m_write(int fd, const void *buf, size_t count);
ssize_t m_write(int fd, const void *buf, size_t count)
{
    write(fd,buf,count);
    return 0;
}

int main()
{
    m_write(1, "hiii\n", 5);
    return 0;
}
