/*
 * (C) Copyright 2023
 * Author:  Chung Duc Nguyen Dang
 * Email:   nguyendangchungduc1999@gmail.com
 *
 */

#ifndef __PORT_H
#define __PORT_H

#include "types.h"

class Port
{
protected:
    uint16_t m_portnumber;
    Port(uint16_t portnumber);
    ~Port(void);
};

class Port8Bit : public Port
{
public:
    Port8Bit(uint16_t portnumber);
    ~Port8Bit(void);
    virtual void Write(uint8_t data);
    virtual uint8_t Read(void);
};


class Port8BitSlow : public Port8Bit
{
public:
    Port8BitSlow(uint16_t portnumber);
    ~Port8BitSlow(void);
    virtual void Write(uint8_t data);
};

class Port16Bit : public Port
{
public:
    Port16Bit(uint16_t portnumber);
    ~Port16Bit(void);
    virtual void Write(uint16_t data);
    virtual uint16_t Read(void);
};

class Port32Bit : public Port
{
public:
    Port32Bit(uint16_t portnumber);
    ~Port32Bit(void);
    virtual void Write(uint32_t data);
    virtual uint32_t Read(void);
};

#endif
