#include "../include/I2CBus.h"
#include <fcntl.h>
#include <linux/i2c-dev.h>

I2CBus::I2CBus(const char * deviceName)
{
      this->deviceName = deviceName;
//    fd = open(deviceName, O_RDWR);
//    if (fd == -1)
//    {
//        throw posix_error("Failed to open I2C device.");
//    }
}

I2CBus::~I2CBus()
{
//    close(fd);
}

void I2CBus::addressSet(uint8_t address)
{
//    int fd = -1;
//    fd = open(deviceName, O_RDWR);
//    if (fd == -1)
//    {
//        throw posix_error("Failed to open I2C device.");
//    }
	this->address = address;

//    int result = ioctl(fd, I2C_SLAVE, address);
//    if (result == -1)
//    {
//        throw posix_error("Failed to set address.");
//    }

//    close(fd);
}

void I2CBus::writeByte(uint8_t command, uint8_t data)
{
    int fd = -1;

    fd = open(deviceName, O_RDWR);
    if (fd == -1)
    {
        throw posix_error("Failed to open I2C device.");
    }

    int result = ioctl(fd, I2C_SLAVE, this->address);
    if (result == -1)
    {
        throw posix_error("Failed to set address.");
    }


    result = i2c_smbus_write_byte_data(fd, command, data);
    if (result == -1)
    {
        throw posix_error("Failed to write byte to I2C.");
    }

    close(fd);
}

uint8_t I2CBus::readByte(uint8_t command)
{
    int fd = -1;

    fd = open(deviceName, O_RDWR);
    if (fd == -1)
    {
        throw posix_error("Failed to open I2C device.");
    }

    int result = ioctl(fd, I2C_SLAVE, this->address);
    if (result == -1)
    {
        throw posix_error("Failed to set address.");
    }


    result = i2c_smbus_read_byte_data(fd, command);
    if (result == -1)
    {
        throw posix_error("Failed to read byte from I2C.");
    }

    close(fd);

    return result;
}

int I2CBus::tryReadByte(uint8_t command)
{
    int ret;
    int fd = -1;

    fd = open(deviceName, O_RDWR);
    if (fd == -1)
    {
        throw posix_error("Failed to open I2C device.");
    }

    int result = ioctl(fd, I2C_SLAVE, this->address);
    if (result == -1)
    {
        throw posix_error("Failed to set address.");
    }

    ret = i2c_smbus_read_byte_data(fd, command);

    close(fd);
    return ret;
}

void I2CBus::readBlock(uint8_t command, uint8_t size, uint8_t * data)
{
    int fd = -1;
    fd = open(deviceName, O_RDWR);
    if (fd == -1)
    {
        throw posix_error("Failed to open I2C device.");
    }

    int result = ioctl(fd, I2C_SLAVE, this->address);
    if (result == -1)
    {
        throw posix_error("Failed to set address.");
    }


    result = i2c_smbus_read_i2c_block_data(fd, command, size, data);
    if (result != size)
    {
        throw posix_error("Failed to read block from I2C.");
    }
 
    close(fd);
}
