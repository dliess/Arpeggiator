#ifndef BASE_ARP_SEQUENCE_H
#define BASE_ARP_SEQUENCE_H

#include <cstddef>
#include <memory_resource>
#include <list>

#include "print_alloc.h"

namespace base::arp
{
class ArpSequence
{
public:
   ArpSequence(std::pmr::unsynchronized_pool_resource& pool);
   void push_back(int note, float velocity);
   void clear() noexcept;
   struct NoteData
   {
      int note;
      float velocity;
   };
   NoteData get(int idx) const noexcept;
   size_t size() const noexcept;

private:
   std::pmr::list<NoteData> m_noteList;
};

}   // namespace base::arp

#endif