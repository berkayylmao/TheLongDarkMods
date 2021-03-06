/*
   MIT License

   Copyright (c) 2019 Berkay Yigit <berkay2578@gmail.com>
       Copyright holder detail: Nickname(s) used by the copyright holder: 'berkay2578', 'berkayylmao'.

   Permission is hereby granted, free of charge, to any person obtaining a copy
   of this software and associated documentation files (the "Software"), to deal
   in the Software without restriction, including without limitation the rights
   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
   copies of the Software, and to permit persons to whom the Software is
   furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included in all
   copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
   SOFTWARE.
*/

#pragma once
#include <cstdint>
#include "../IL2CPPTypes/Il2CppString.hpp"

MOD_NAMESPACE_BEGIN() {
   struct SaveGameSlots {
      static inline uint64_t _ClassInstanceOffset = 0x3C498C8;

      /* +0x00 */ Il2CppString* AUTOSAVE_SLOT_NAME;
      /* +0x08 */ Il2CppString* SANDBOX_SLOT_PREFIX;
      /* +0x10 */ Il2CppString* STORY_SLOT_PREFIX;
      /* +0x18 */ Il2CppString* CHALLENGE_SLOT_PREFIX;
      /* +0x20 */ Il2CppString* CHECKPOINT_SLOT_PREFIX;
      /* +0x28 */ Il2CppString* AUTOSAVE_SLOT_PREFIX;
      /* +0x30 */ Il2CppString* QUICKSAVE_SLOT_PREFIX;
      /* +0x38 */ int32_t       MAX_AUTOSAVES;
      /* +0x3C */ int32_t       MAX_SAVESLOTS;
      /* +0x00 */ //SlotData m_AutoSaveSlot; 
      /* +0x00 */ //List<SlotData> m_SaveSlots; 
      /* +0x00 */ //HashSet<string> m_InvalidSlots; 
      /* +0x00 */ //Dictionary<string, string> m_SlotDisplayNames; 
   };
} MOD_NAMESPACE_END()
