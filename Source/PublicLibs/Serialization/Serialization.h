/* Serialization.h - Serialization
 * 
 * Author           : Alexander J. Yee
 * Date Created     : 10/28/2012
 * Last Modified    : 09/26/2014
 * 
 *      Mostly used for checkpoint restart.
 * 
 */

#pragma once
#ifndef _ymp_Serialization_H
#define _ymp_Serialization_H
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//  Dependencies
#include <string>
#include "../Types.h"
namespace ymp{
namespace Serialization{
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void            write_line  (std::wstring& stream);
void            parse_line  (const wchar_t*& stream);
////////////////////////////////////////////////////////////////////////////////
void            write_siL   (std::wstring& stream, const std::wstring& label, siL_t x);
siL_t           parse_siL   (const wchar_t*& stream);
////////////////////////////////////////////////////////////////////////////////
void            write_float (std::wstring& stream, const std::wstring& label, double x);
double          parse_float (const wchar_t*& stream);
////////////////////////////////////////////////////////////////////////////////
void            write_str   (std::wstring& stream, const std::wstring& label, const std::wstring& x);
std::wstring    parse_str   (const wchar_t*& stream);
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
}
}
#endif