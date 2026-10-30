////////////////////////////////////////////////////////////////////////////////
//
// testmov.cpp - Класс, обслуживающий текстовый файл - slide
//
////////////////////////////////////////////////////////////////////////////////
#include <vcl.h>
#pragma hdrstop

#include "testmov.h"
#include "slide.rh"
#include <stdio.h>
#include <libtool.h>


// ------------------------------------------------------------------------
// Конструктор по имени файла создает объект класса FileSlide
// выделяется буфер равный размеру файла и туда считывается
// информация из файла, fileBuff - указывает на начало буфера
//-------------------------------------------------------------------------
FileSlide::FileSlide( char * fileNameOld, char * fileNameNew ):
                     fCommentary( FALSE ) 
{
  OFSTRUCT ofs;
  if ( OpenFile(fileNameOld , &ofs, OF_EXIST) != HFILE_ERROR ) {
    fOld = new  TFileStream( ofs.szPathName, fmOpenRead );
    long s;
    if ( (error = (s = fOld->Size) == -1) != TRUE ) {
      size = ( unsigned ) s;
      fileBuff = new char[ size ];
      fOld->Read( fileBuff, size );
      ToBegin();
      fNew = new TFileStream( fileNameNew, fmCreate|fmOpenWrite );
      return;
    }
  }
  else
		ErrorT( "Ошибка! Файл не найден" );
  fileBuff = NULL;
}


//-------------------------------------------------------------------------------
// Удаляем буфер файла и объект класса TFile
// ---
FileSlide::~FileSlide() 
{
  if ( !error ) 
  {
    delete fNew;
    
    delete [] fileBuff;
    delete fOld;
  }
}


//-------------------------------------------------------------------------------
// Позиция строки
// ---
static int strpos( char *s, int c ) 
{
 char *pS= strchr( s, c );
 if ( pS )
   return int( pS - s );
 else
   return -1;
}


//-------------------------------------------------------------------------------
// Формирование строки
// ---
static int pr_str(char *vh, char *res, int t)
{
  int i, j, k, m;

  j = strlen( vh );
  for ( i = j-1; i > 0; i-- )
    if ( *(vh+i) != ' ' )
      break;
  m = i;

  for ( i = 0; i < m; i++ )
    if ( *(vh+i) != ' ' )
      break;
  k = i;

  switch ( t ) 
  {
    case 'H' : i = k;        break;
    case 'E' : i = 0; j = m; break;
    case 'B' : i = k; j = m; break;
  }

  k = j - i;

  for ( ;  i <= j; i++ )
    *res++ = *( vh+i );
  *res = '\0';

  return ( k );
}


//--------------------------------------------------------------------------
// Проверяет является ли считанная строка комментарием или нет
// комментарий - /* ..... */, //......
// в случае комментария fCommentary = TRUE и возвращается 0
//-------------------------------------------------------------------------
int FileSlide::CheckCommentary ( char *s )
{
  char *c;
  c = s;
  if ( *c == '\0' )
    return 0;
  while ( *c == ' ' && *c != '\0' ) c++;
  if ( !fCommentary ) // Комментария еще нет
  { 
    if ( *c == '/' ) 
    {
      while ( *c == ' ' && *c != '\0' ) c++;
      c++;
      if ( *c  == '/' )
        return 0;
      if (  *c == '*' ) 
      {
        fCommentary = TRUE;
        c++;
      }
    }
  }
  if ( fCommentary ) // Это комментарий
  { 
    while ( *c != '\0' ) 
    {
      if ( *c == '*' ) 
      {
        while ( *c == ' ' && *c != '\0' ) c++;
        c++;
        if ( *c  == '/' ) 
        {
          fCommentary = FALSE;
          return 0;
        }
        if ( *c == '\0' )
          break;
      }
      c++;
    }
  }
  return !fCommentary ? 1 : 0;
}


//-------------------------------------------------------------------------------
// Вернуть номер оъекта из слайда
// ---
static int ReturnNumberOperation( char *s ) 
{
  if ( !strcmp( s, "LN") ) // Отрисовать линию
    return LN;
  else 
  {
    if ( !strcmp( s, "CR") ) // Отрисовать окружность
      return CR;
    else 
    {
      if ( !strcmp( s, "AR") ) // Отрисовать дугу по углам
        return AR;
      else 
      {
        if ( !strcmp( s, "AR1") ) // Отрисовать дугу  по точкам
          return AR1;
        else 
        {
          if ( !strcmp( s, "MA") ) // Позиционироваться в точку
            return MA;
          else 
          {
            if ( !strcmp( s, "LA") ) // Отрисовать линию и позиционироваться
              return LA;
            else 
            {
              if ( !strcmp( s, "EL") ) // Отрисовать эллипс
                return EL;
              else 
              {
                if ( !strcmp( s, "PS") ) // Отрисовать сектор
                  return PS;
                else 
                {
                  if ( !strcmp( s, "RT") ) // Отрисовать прямоугольник
                    return RT;
                  else 
                  {
                    if ( !strcmp( s, "BR") ) // Отрисовать и заполнить прямоугольник
                      return BR;
                    else 
                    {
                      if ( !strcmp( s, "DP") ) // Отрисовать ломанную линию
                        return DP;
                      else 
                      {
                        if ( !strcmp( s, "FP") ) // Заполнить многоугольник
                          return FP;
                        else 
                        {
                          if ( !strcmp( s, "FF") ) // Заполнить область
                            return FF;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return 0;
}


//-------------------------------------------------------------------------------
// Проверка количества параметров
// ---
static int CheckCount(int numb, BYTE count ) 
{
  switch (numb) 
  {
    case LN  :return count == 4   ? 1 : 0; // LN, x1, y1, x2, y2,
    case MA  :return count == 2   ? 1 : 0; // MA, x, y,
    case LA  :return count == 2   ? 1 : 0; // LA, x, y,
    case AR  :return count == 5   ? 1 : 0; // AR, xc, yc, fst, fen, rad
    case PS  :return count == 5   ? 1 : 0; // PS, xc, yc, fst, fen, rad
    case EL  :return count == 6   ? 1 : 0; // EL, xc, yc, fst, fen, rx, ry,
    case AR1 :return count == 7   ? 1 : 0; // AR1, xc, yc, rad, x1, y1, x2, y2,
    case CR  :return count == 3   ? 1 : 0; // CR, xc, yc, rad,
    case BR  :return count == 4   ? 1 : 0; // BR, x1, y1, x2, y2,
    case FF  :return count == 3   ? 1 : 0; // FF, x, y, b,
    case DP  :return !(count % 2) ? 1 : 0; // DP, x1, y1, ... xn, yn,
    case FP  :return !(count % 2) ? 1 : 0; // FP, x1, y1, ... xn, yn,
    case RT  :return count == 4   ? 1 : 0; // RT, x1, y1, x2, y2,
  }
  return 0;
}


//-------------------------------------------------------------------------------
// Сдвиг компонента
// ---
static void MoveEl(int numb, int* component, int x, int y, int count ) 
{
  switch (numb) 
  {
    case LN  : // LN, x1, y1, x2, y2,
    case BR  : // BR, x1, y1, x2, y2,
    case RT  : // RT, x1, y1, x2, y2,
      component[0] += x; 
      component[1] += y;
      component[2] += x; 
      component[3] += y;
      break;
    case MA  : // MA, x, y,
    case LA  : // LA, x, y,
    case FF  : // FF, x, y, b,
    case CR  : // CR, xc, yc, rad,
    case AR  : // AR, xc, yc, fst, fen, rad
    case PS  : // PS, xc, yc, fst, fen, rad
    case EL  : // EL, xc, yc, fst, fen, rx, ry,
      component[0] += x; 
      component[1] += y;
      break;
    case AR1 : // AR1, xc, yc, rad, x1, y1, x2, y2,
      component[0] += x; 
      component[1] += y;
      component[3] += x; 
      component[4] += y;
      component[5] += x; 
      component[6] += y;
      break;
    case DP  : // DP, x1, y1, ... xn, yn,
    case FP  : // DP, x1, y1, ... xn, yn,
    { 
      for( int i = 0; i < count; i+=2 )
      {
        component[0+i] += x;
        component[1+i] += y;
      }
      break;
    }
  }
}


//-------------------------------------------------------------------------------
// Наполнение компонента теустовой строки
// ---
static void FillNComponent( char* s, int *ic, int count ) 
{
  char *c= s + strlen( s );
  for ( int i=0; i < count; i+=2 ) 
  {
    sprintf ( c, " %d, %d,",ic[0+i], ic[1+i] );
    c += strlen( c );
  }
  strcat( s, "\r\n");
}


//-------------------------------------------------------------------------------
// Наполнение теустовой строки
// ---
void FillStr(int numb, char *s, int *ic, int count ) 
{
  switch (numb) 
  {
    case LN  :   // LN, x1, y1, x2, y2,
      sprintf ( s, "  LN, %d, %d, %d, %d,\r\n",ic[0], ic[1], ic[2], ic[3] );
      break;
    case MA  :   // MA, x, y,
      sprintf ( s, "  MA, %d, %d,\r\n",ic[0], ic[1] );
      break;
    case LA  :   // LA, x, y,
      sprintf ( s, "  LA, %d, %d,\r\n",ic[0], ic[1] );
      break;
    case AR  :   // AR, xc, yc, fst, fen, rad
      sprintf ( s, "  AR, %d, %d, %d, %d, %d,\r\n",ic[0], ic[1], ic[2], ic[3], ic[4] );
      break;
    case PS  :   // PS, xc, yc, fst, fen, rad
      sprintf ( s, "  PS, %d, %d, %d, %d, %d,\r\n",ic[0], ic[1], ic[2], ic[3], ic[4] );
      break;
    case EL  :   // EL, xc, yc, fst, fen, rx, ry,
      sprintf ( s, "  EL, %d, %d, %d, %d, %d, %d,\r\n",ic[0], ic[1], ic[2], ic[3], ic[4], ic[5] );
      break;
    case AR1 :   // AR1, xc, yc, rad, x1, y1, x2, y2,
      sprintf ( s, "  AR1, %d, %d, %d, %d, %d, %d, %d,\r\n",ic[0], ic[1], ic[2], ic[3], ic[4], ic[5], ic[6] );
      break;
    case CR  :   // CR, xc, yc, rad,
      sprintf ( s, "  CR, %d, %d, %d,\r\n",ic[0], ic[1], ic[2] );
      break;
    case BR  :   // BR, x1, y1, x2, y2,
      sprintf ( s, "  BR, %d, %d, %d, %d,\r\n",ic[0], ic[1], ic[2], ic[3] );
      break;
    case FF  :   // FF, x, y, b,
      sprintf ( s, "  FF, %d, %d, %d,\r\n",ic[0], ic[1], ic[2] );
      break;
    case DP  :   // DP, x1, y1, ... xn, yn,
      strcpy ( s, "  DP,");
      FillNComponent( s, ic, count );
      break;
    case FP  :   // FP, x1, y1 ... xn, yn,
      strcpy ( s, "  FP,");
      FillNComponent( s, ic, count );
      break;
    case RT  :   // RT, x1, y1, x2, y2,
      sprintf ( s, "  RT, %d, %d, %d, %d,\r\n",ic[0], ic[1], ic[2], ic[3] );
      break;
  }
}


//--------------------------------------------------------------------------
// Анализируется строка sOld, если сдвигаемый элемент
// выделяется память под число компонент элем (int*count),
// переводятся строки в int, вычисляются новые значения и собирается s,
// если не здвигаемый элемент ничего не делается возвращается 0
//--------------------------------------------------------------------------
int FileSlide::MoveElement( char * s, int x, int y ) 
{
  if ( ! error ) 
  {
    char *c;
    c = s;
    char name[10];
    int len;
    if ( (len = strpos(s, ',')) > 0 ) 
    {
      strncpy ( name, s , len );
      name[ len ] = '\0';

      pr_str(name, name, 'B');
      int numb = ReturnNumberOperation( name );
      if ( numb ) 
      {
        c += len+1;
        // Определим число компонент
        BYTE count = 0;
        while ( *c!='\0' ) 
        {
          c++;
          if( *c == ',' )
            count++;
        }

        if( CheckCount(numb, count ) )  
        {
          int * component =  new int [sizeof(int)*count];
          c = s;
          c += len+1;
          // Конвертирует строковые значения в int
          for( int i = 0; i < count; i++ ){
            c++;
            component[i] = atoi( c );
            while( *c != ',' && *c !='\0') c++;
          }
          MoveEl( numb, component,  x,  y, count  );
          FillStr( numb, s, component, count );
          delete []component;
          return 1;
        }
      }
    }
  }
  return 0;
}


//-------------------------------------------------------------------------------
// Позволяет считать строку из буфера текстового файла
// длиной len символов, buff считываемая строка
// ---
char * FileSlide::FGetS( char *buff , int len ) 
{
  if ( numb < size ) 
  {
    char *c, *b;
    int i=0;
    b=buff;
    c=fileBuff;
    while ( i < len-1 && numb < size ) 
    {
      char cc = c[ (numb)++ ];
      if ( cc != '\r' && cc != '\n' )
        b[i++] =(char ) cc;
      else 
      {
        if ( numb < size ) 
        {
          if ( (cc == '\r' && c[ numb ] == '\n') ||
               (cc == '\n' && c[ numb ] == '\r') )
            numb++;
        }
        break;
      }
    }
    b[i] = '\0';
    return buff;
  }
  return NULL;
}


//-------------------------------------------------------------------------------
// Позволяет записать строку в текстовый файл
// ---
void FileSlide::FSetS( char *buff ) 
{
  if ( fNew )
    fNew->Write( buff, strlen(buff) );
}


//-------------------------------------------------------------------------------
// Сдвинуть слайд 
// ---
void MoveSlide( ) 
{
  // Выбрать имя файла
  char fileNameOld[128];
  char fileNameNew[128];
  char s[128];
  if( ChoiceFile("*.rc", 0, fileNameOld, 128) )
  {
    if( SaveFile("*.rc",0,0, fileNameNew,128) )
    {
      int x, y;
      if( ReadInt( "Введите сдвиг по X",0,-2000,2000,&x) ) 
      {
        if( ReadInt( "Введите сдвиг по Y",0,-2000,2000,&y) ) 
        {
          FileSlide  * file = new FileSlide( fileNameOld, fileNameNew );
          if ( !file->IsError() ) 
          {
            while ( file->FGetS(s, 128 ) ) 
            {
              if ( file->CheckCommentary(s) ) 
              {
                if(!file->MoveElement( s, x, y ))
                  strcat( s, "\r\n");
              }
              else
                strcat( s, "\r\n");
              file->FSetS ( s );
            }
          }
          delete file;
          MessageBoxResult();
        }
      }
    }
  }
}
