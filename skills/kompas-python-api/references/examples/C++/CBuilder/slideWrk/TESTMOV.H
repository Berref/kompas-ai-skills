////////////////////////////////////////////////////////////////////////////////
//
// testmov.h - Класс, обслуживающий текстовый файл - slide
//
////////////////////////////////////////////////////////////////////////////////
#ifndef __TESTMOV_H
#define __TESTMOV_H

#include <Classes.hpp>

class FileSlide
{
private:
  TFileStream * fOld;
  TFileStream * fNew;
  char        * fileBuff;  // Указатель на начало буфера  файла
  bool        error;       // Ошибка открытия
  unsigned    size;        // Размер файла
  unsigned    numb;        // Число прочитанных символов
  bool        fCommentary; // Это комментарий
public:
         FileSlide( char * fileNameOld, char * fileNameNew );
        ~FileSlide();

  int    MoveElement( char * s, int x, int y );
  void   FSetS ( char *buff );
  char * FGetS( char *buff , int len );
  int    CheckCommentary ( char *s );

  bool   IsError() { return error; }
  void   ToBegin(){ numb = 0; }
};


//-------------------------------------------------------------------------------
// Сдвинуть слайд
// ---
void MoveSlide();

#endif
