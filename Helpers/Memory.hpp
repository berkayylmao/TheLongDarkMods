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
#include <windef.h>
#include <cstdint>

namespace Memory {
   static CRITICAL_SECTION cs;
   static DWORD oldMemoryAccess, memoryAccessAddress;
   static int32_t memoryAccessSize;

   static void openMemoryAccess(const DWORD64 address, const int32_t& size) {
      memoryAccessAddress = address;
      memoryAccessSize = size;
      VirtualProtect((LPVOID)address, size, PAGE_EXECUTE_READWRITE, &oldMemoryAccess);
   }
   static void restoreMemoryAccess() {
      VirtualProtect((LPVOID)memoryAccessAddress, memoryAccessSize, oldMemoryAccess, &oldMemoryAccess);
      memoryAccessAddress = 0;
      memoryAccessSize = 0;
   }

   static DWORD32 calculateRelativeAddress(const DWORD64 from, const DWORD64 to) {
      return (DWORD32)(to - from - 0x5);
   }

   static void writeCall(const DWORD64 from, const DWORD64 to) {
      EnterCriticalSection(&cs);

      openMemoryAccess(from, 5);
      *(BYTE*)(from) = 0xE8;
      *(DWORD32*)(from + 0x1) = calculateRelativeAddress(from, to);

      restoreMemoryAccess();
      LeaveCriticalSection(&cs);
   }

   static void writeJMP(const DWORD64 from, const DWORD64 to) {
      EnterCriticalSection(&cs);

      openMemoryAccess(from, 5);
      *(BYTE*)(from) = 0xE9;
      *(DWORD32*)(from + 0x1) = calculateRelativeAddress(from, to);

      restoreMemoryAccess();
      LeaveCriticalSection(&cs);
   }

   static void Init() {
      InitializeCriticalSection(&cs);
   }
}