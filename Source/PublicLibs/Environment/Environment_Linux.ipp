/* Environment_Linux.ipp
 * 
 * Author           : Alexander J. Yee
 * Date Created     : 01/04/2015
 * Last Modified    : 01/04/2015
 * 
 */

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//  Dependencies

//  There are no header guards in cpuid.h.
#ifndef cpuid_H
#define cpuid_H
#include <cpuid.h>
#endif

#include <unistd.h>
#include "PublicLibs/ConsoleIO/BasicIO.h"
#include "PublicLibs/Time/Time.h"
#include "Environment.h"
namespace ymp{
namespace Environment{
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void LowerProcessPriority(){
    //  Not yet implemented for Linux.
}
bool LockToCore(upL_t core){
    Console::Warning("Thread affinity not supported.\n");
    return false;
}
////////////////////////////////////////////////////////////////////////////////
upL_t GetLogicalProcessors(){
    return sysconf(_SC_NPROCESSORS_ONLN);
}
upL_t GetFreePhysicalMemory(){
    uiL_t bytes = (uiL_t)sysconf(_SC_AVPHYS_PAGES) * sysconf(_SC_PAGE_SIZE);

    if (bytes > MAX_MEMORY)
        bytes = MAX_MEMORY;
    return static_cast<upL_t>(bytes);
}
uiL_t GetTotalPhysicalMemory(){
    return (uiL_t)sysconf(_SC_PHYS_PAGES) * sysconf(_SC_PAGE_SIZE);
}
////////////////////////////////////////////////////////////////////////////////
u64_t x86_rdtsc(){
    unsigned int lo, hi;
    __asm__ __volatile__ ("rdtsc" : "=a" (lo), "=d" (hi));
    return ((u64_t)hi << 32) | lo;
}
void x86_cpuid(u32_t eabcdx[4], u32_t eax, u32_t ecx){
    __cpuid_count(eax, ecx, eabcdx[0], eabcdx[1], eabcdx[2], eabcdx[3]);
}
uiL_t GetProcessorFrequency(){
    auto w_start = Time::WallClock::Now();
    u64_t r_start = x86_rdtsc();
    while (w_start.SecondsElapsed() < 0.0625);
    auto w_end = Time::WallClock::Now();
    u64_t r_end = x86_rdtsc();

    return (double)(r_end - r_start) / (w_end - w_start);
}
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
}
}
