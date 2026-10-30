////////////////////////////////////////////////////////////////////////////////
//
// testmove.h - команда сдвинуть слайд и класс FileSlide
//
////////////////////////////////////////////////////////////////////////////////
#ifndef __TESTMOVE_H
#define __TESTMOVE_H

#include <SArray.h>
#include <PArray.h>

class FileSlide
{
private:
  bool            m_fCommentary;  // Это комментарий
  PArray<CString> m_strings;      // Исходные строки       
  PArray<CString> m_movedStrings; // Строки после смещения
  SArray<bool>    m_isComment;    // Признак коментария 
public:
  FileSlide( LPCTSTR fileNameOld, LPCTSTR fileNameNew, int x, int y );
  ~FileSlide();

  bool    MoveElement ( CString & s, int x, int y );
  bool    IsCommentary( CString & buff );
  bool    ReadStrings ( CStdioFile & file );
  bool    WriteStrings( CStdioFile & file );
  bool    MoveElements(  int x, int y );
};

void MoveSlide();


#endif