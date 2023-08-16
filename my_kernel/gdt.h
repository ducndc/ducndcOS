#ifndef __GDT_H
#define __GDT_H

#include "types.h"

class GlobalDescriptorTable
{
    public:
        class SegmentDescriptor
        {
            private:
                uint16_t m_limit_lo;
                uint16_t m_base_lo;
                uint8_t m_base_hi;
                uint8_t m_type;
                uint8_t m_flags_limit_hi;
                uint8_t m_base_vhi;
            public:
                SegmentDescriptor(uint32_t base, uint32_t limit, uint8_t type);
                uint32_t Base();
                uint32_t Limit();

        } __attribute__((packed));

        SegmentDescriptor m_nullSegmentSelector;
        SegmentDescriptor m_unusedSegmentSelector;
        SegmentDescriptor m_codeSegmentSelector;
        SegmentDescriptor m_dataSegmentSelector;
    public:
        GlobalDescriptorTable();
        ~GlobalDescriptorTable();

        uint16_t CodeSegmentSelector();
        uint16_t DataSegmentSelector();

};


#endif
