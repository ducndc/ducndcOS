/*
 * (C) Copyright 2023
 * Author:  Chung Duc Nguyen Dang
 * Email:   nguyendangchungduc1999@gmail.com
 *
 */

#include "port.h"

Port::Port(
	uint16_t portnumber
)
{
    this->m_portnumber = portnumber;
}

Port::~Port(
	void
)
{
}

Port8Bit::Port8Bit(
	uint16_t portnumber
) : 
	Port(m_portnumber)
{
}

Port8Bit::~Port8Bit(
	void
)
{
}

void 
Port8Bit::Write(
	uint8_t data
)
{
    __asm__ volatile("outb %0, %1" : : "a" (data), "Nd" (m_portnumber));
}

uint8_t 
Port8Bit::Read(
	void
)
{
    uint8_t result;
    __asm__ volatile("inb %1, %0" : "=a" (result) : "Nd" (m_portnumber));
	
    return result;
}

Port8BitSlow::Port8BitSlow(
	uint16_t portnumber
) : 
	Port8Bit(m_portnumber)
{
}

Port8BitSlow::~Port8BitSlow(
	void
)
{
}

void 
Port8BitSlow::Write(
	uint8_t data
)
{
    __asm__ volatile("outb %0, %1\njmp 1f\n1: jmp 1f\n1:" : : "a" (data), "Nd" (m_portnumber));
}

Port16Bit::Port16Bit(
	uint16_t portnumber
) : 
	Port(m_portnumber)
{
}

Port16Bit::~Port16Bit(
	void
)
{
}

void 
Port16Bit::Write(
	uint16_t data
)
{
    __asm__ volatile("outw %0, %1" : : "a" (data), "Nd" (m_portnumber));
}

uint16_t 
Port16Bit::Read(
	void
)
{
    uint16_t result;
    __asm__ volatile("inw %1, %0" : "=a" (result) : "Nd" (m_portnumber));

    return result;
}

Port32Bit::Port32Bit(
	uint16_t portnumber
) : 
	Port(m_portnumber)
{
}

Port32Bit::~Port32Bit(
	void
)
{
}

void 
Port32Bit::Write(
	uint32_t data
)
{
    __asm__ volatile("outl %0, %1" : : "a" (data), "Nd" (m_portnumber));
}

uint32_t 
Port32Bit::Read(
	void
)
{
    uint32_t result;
    __asm__ volatile("inl %1, %0" : "=a" (result) : "Nd" (m_portnumber));

    return result;
}