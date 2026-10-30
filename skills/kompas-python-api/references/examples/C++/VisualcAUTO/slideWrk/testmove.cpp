////////////////////////////////////////////////////////////////////////////////
//
// testmove.cpp - 
//
////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"

#ifndef __TESTMOVE_H
#include "testmove.h"
#endif

#ifndef  __SLIDE_RH
#include <slide.rh>
#endif

#include <comdef.h>

extern KompasObjectPtr kompas;

// ------------------------------------------------------------------------
// Конструктор по имени файла создает объект класса FileSlide
// выделяется буфер равный размеру файла и туда считывается
// информация из файла, fileBuff - указывает на начало буфера
//-------------------------------------------------------------------------
FileSlide::FileSlide( LPCTSTR fileNameOld, LPCTSTR fileNameNew, int x, int y ) 
: m_fCommentary( FALSE )
{
  OFSTRUCT ofs;
  if ( ::OpenFile(_bstr_t(fileNameOld), &ofs, OF_EXIST) != HFILE_ERROR ) 
  {
    CStdioFile file( _bstr_t(ofs.szPathName), CFile::modeRead );
    if ( file.GetLength() > 0 ) 
    {
      bool res = ReadStrings( file );
      file.Close();
      if ( res )
      {
        if ( MoveElements(x, y) )
        {
          file.Open( fileNameNew, CFile::modeCreate | CFile::modeWrite );
          WriteStrings( file );
        }  
      }  
      return;
    }
  }
  else
    kompas->ksError( _T("Файл не найден") );
}


//-------------------------------------------------------------------------------
// Удаляем буфер файла и объект класса TFile
// ---
FileSlide::~FileSlide() 
{
}

//-----------------------------------------------------------------------------
// Выкинуть пробелы
// ---
void CheckString( CString & str )
{
  int len  = str.GetLength(); 
  if ( len > 0 )
  {
    str.Replace( _T('\t'), _T(' ') );             // Заменим табуляцию на пробел
    int rPos = 0;
    int lPos = len ? len - 1 : 0;
    while ( lPos && str[lPos] == _T(' ') )        // Выкинем пробелы из конца строки
      lPos--;
    
    while ( rPos < lPos && str[rPos] == _T(' ') ) // Выкинем пробелы из начала строки
      rPos++;
    str = str.Mid( rPos, lPos - rPos + 1 );       // Получаем строку без лишних пробелов
    if ( str == _T(' ') )
      str = _T("");
  }
}


//-----------------------------------------------------------------------------
//
// ---
bool FileSlide::ReadStrings( CStdioFile & file )
{
  CString nextStr;
  while ( file.ReadString(nextStr) )
  {
    CheckString( nextStr );
    bool comment = nextStr.IsEmpty() || IsCommentary( nextStr );
    m_isComment.Add( comment ); 
    m_strings  .Add( new CString(nextStr) );
  }
  return m_strings.Count() > 0;
}


//-----------------------------------------------------------------------------
//
// ---
bool FileSlide::WriteStrings( CStdioFile & file )
{
  for ( int i = 0, count = m_movedStrings.Count(); i < count; i++ )
  {
    file.WriteString( *m_movedStrings[i] );
    file.WriteString( _T("\n") );
  }
  return m_strings.Count() > 0;
}

//-------------------------------------------------------------------------------
// Позиция строки
// ---
static int strpos( LPCTSTR s, int c ) 
{
 LPCTSTR pS= _tcschr( s, c );
 if ( pS )
   return int( pS - s );
 else
   return -1;
}


//-------------------------------------------------------------------------------
// Формирование строки
// ---
static int pr_str( LPCTSTR vh, LPTSTR res, int t)
{
  int i, j, k, m;

  j = _tcslen( vh );
  for ( i = j-1; i > 0; i-- )
    if ( *(vh+i) != _T(' ') )
      break;
  m = i;

  for ( i = 0; i < m; i++ )
    if ( *(vh+i) != _T(' ') )
      break;
  k = i;

  switch ( t ) 
  {
    case _T('H') : i = k;        break;
    case _T('E') : i = 0; j = m; break;
    case _T('B') : i = k; j = m; break;
  }

  k = j - i;

  for ( ;  i <= j; i++ )
    *res++ = *( vh+i );
  *res = _T('\0');

  return ( k );
}


//--------------------------------------------------------------------------
// Проверяет является ли считанная строка комментарием или нет
// комментарий - /* ..... */, //......
// в случае комментария fCommentary = TRUE и возвращается 0
//-------------------------------------------------------------------------
bool FileSlide::IsCommentary( CString & s )
{
  bool res = false;
  int pos__  = -1;
  if ( !m_fCommentary )
  {
    pos__ = s.Find( _T("/*") );  // коментарий открывается
    if ( pos__ >= 0 )  
    {
      m_fCommentary = true;
      res = true;
      pos__ = s.Find(_T("*/"));
      if ( pos__ >= 0 )      // коментарий закрылся
        m_fCommentary = false;
    }
    else
    {
      pos__ = s.Find(_T("//") );
      if ( pos__ >= 0 )
        res = true;
    }
  }
  else
  {
    res = true;
    pos__ = s.Find(_T("*/"));
    if ( pos__ >= 0 )
      m_fCommentary = false;         // Коментарий закрылся
  }
  return res;
}


//-------------------------------------------------------------------------------
// Вернуть номер оъекта из слайда
// ---
static int ReturnNumberOperation( LPCTSTR s ) 
{
  if ( !_tcscmp( s, _T("LN")) ) // Отрисовать линию
    return LN;
  else 
  {
    if ( !_tcscmp( s, _T("CR")) ) // Отрисовать окружность
      return CR;
    else 
    {
      if ( !_tcscmp( s, _T("AR")) ) // Отрисовать дугу по углам
        return AR;
      else 
      {
        if ( !_tcscmp( s, _T("AR1")) ) // Отрисовать дугу  по точкам
          return AR1;
        else 
        {
          if ( !_tcscmp( s, _T("MA")) ) // Позиционироваться в точку
            return MA;
          else 
          {
            if ( !_tcscmp( s, _T("LA")) ) // Отрисовать линию и позиционироваться
              return LA;
            else 
            {
              if ( !_tcscmp( s, _T("EL")) ) // Отрисовать эллипс
                return EL;
              else 
              {
                if ( !_tcscmp( s, _T("PS")) ) // Отрисовать сектор
                  return PS;
                else 
                {
                  if ( !_tcscmp( s, _T("RT")) ) // Отрисовать прямоугольник
                    return RT;
                  else 
                  {
                    if ( !_tcscmp( s, _T("BR")) ) // Отрисовать и заполнить прямоугольник
                      return BR;
                    else 
                    {
                      if ( !_tcscmp( s, _T("DP")) ) // Отрисовать ломанную линию
                        return DP;
                      else 
                      {
                        if ( !_tcscmp( s, _T("FP")) ) // Заполнить многоугольник
                          return FP;
                        else 
                        {
                          if ( !_tcscmp( s, _T("FF")) ) // Заполнить область
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
static void FillNComponent( CString & s, int *ic, int count ) 
{
  TCHAR buff[50];
  for ( int i=0; i < count; i+=2 ) 
  {
    _stprintf_s ( buff, _T(" %d, %d,"),ic[0+i], ic[1+i] );
    s += buff;
  }
}


//-------------------------------------------------------------------------------
// Наполнение теустовой строки
// ---
void FillStr(int numb, CString & res, int *ic, int count ) 
{
  switch (numb) 
  {
    case LN  :   // LN, x1, y1, x2, y2,
      res.Format( _T("  LN, %d, %d, %d, %d,"), ic[0], ic[1], ic[2], ic[3] );
      break;
    case MA  :   // MA, x, y,
      res.Format( _T("  MA, %d, %d,"), ic[0], ic[1] );
      break;
    case LA  :   // LA, x, y,
      res.Format( _T("  LA, %d, %d,"), ic[0], ic[1] );
      break;
    case AR  :   // AR, xc, yc, fst, fen, rad
      res.Format( _T("  AR, %d, %d, %d, %d, %d,"), ic[0], ic[1], ic[2], ic[3], ic[4] );
      break;
    case PS  :   // PS, xc, yc, fst, fen, rad
      res.Format( _T("  PS, %d, %d, %d, %d, %d,"), ic[0], ic[1], ic[2], ic[3], ic[4] );
      break;
    case EL  :   // EL, xc, yc, fst, fen, rx, ry,
      res.Format( _T("  EL, %d, %d, %d, %d, %d, %d,"), ic[0], ic[1], ic[2], ic[3], ic[4], ic[5] );
      break;
    case AR1 :   // AR1, xc, yc, rad, x1, y1, x2, y2,
      res.Format( _T("  AR1, %d, %d, %d, %d, %d, %d, %d,"), ic[0], ic[1], ic[2], ic[3], ic[4], ic[5], ic[6] );
      break;
    case CR  :   // CR, xc, yc, rad,
      res.Format( _T("  CR, %d, %d, %d,"), ic[0], ic[1], ic[2] );
      break;
    case BR  :   // BR, x1, y1, x2, y2,
      res.Format( _T("  BR, %d, %d, %d, %d,"), ic[0], ic[1], ic[2], ic[3] );
      break;
    case FF  :   // FF, x, y, b,
      res.Format( _T("  FF, %d, %d, %d,") ,ic[0], ic[1], ic[2] );
      break;
    case DP  :   // DP, x1, y1, ... xn, yn,
      res = _T("  DP,");
      FillNComponent( res, ic, count );
      break;
    case FP  :   // FP, x1, y1 ... xn, yn,
      res = _T("  FP,");
      FillNComponent( res, ic, count );
      break;
    case RT  :   // RT, x1, y1, x2, y2,
      res.Format( _T("  RT, %d, %d, %d, %d,"), ic[0], ic[1], ic[2], ic[3] );
      break;
  }
}


//--------------------------------------------------------------------------
// Анализируется строка sOld, если сдвигаемый элемент
// выделяется память под число компонент элем (int*count),
// переводятся строки в int, вычисляются новые значения и собирается s,
// если не здвигаемый элемент ничего не делается возвращается 0
//--------------------------------------------------------------------------
bool FileSlide::MoveElement( CString & s, int x, int y ) 
{
  CString res;
  TCHAR name[10];
  int len = s.Find( _T(','));
  if ( len > 0 ) 
  {
    res = s.Left( len );
 
    pr_str(res, name, _T('B') );
    int numb = ReturnNumberOperation( name );
    if ( numb ) 
    {
      // Определим число компонент
      int count = -1;
      int len1 = len;
      while (  len1 > 0 ) 
      {
        count++;
        len1 = s.Find( _T(','), len1 + 1 );
      }

      if( CheckCount(numb, count) )  
      {
        int * component =  new int [sizeof(int)*count];
        // Конвертирует строковые значения в int
        int len1 = len;
        int lenght = s.GetLength();
        CString tmp;
        for( int i = 0; i < count; i++ ){
          len = s.Find( _T(','), len1 + 1 );
          tmp = s.Mid( len1 + 1, len - len1 - 1 );
          len1 = len;
          component[i] = _ttoi(tmp);
        }
        MoveEl( numb, component,  x,  y, count  );
        FillStr( numb, res, component, count );
        delete []component;
        s = res;
      }
    }
  }
  return TRUE;
}


//-----------------------------------------------------------------------------
//
// ---
bool FileSlide::MoveElements( int x, int y )
{
  for ( int i = 0, count = m_strings.Count(); i < count; i++ )
  {
    CString next( *m_strings[i] );
    if ( m_isComment[i] || MoveElement(next, x, y) )
    {
      m_movedStrings.Add( new CString(next) );
    }  
  }  
  return m_movedStrings.Count() > 0;
}


//-------------------------------------------------------------------------------
// Сдвинуть слайд 
// ---
void MoveSlide() 
{
  // Выбрать имя файла
  CString fileNameOld( (LPCTSTR)kompas->ksChoiceFile( _T("*.rc"), _T(""), 0) );
  if( !fileNameOld.IsEmpty() )
  {
    CString fileNameNew( (LPCTSTR)kompas->ksSaveFile( _T("*.rc"), _T(""), _T(""), false) );
    if(  fileNameNew.IsEmpty() )
    {
      long x, y;
      if( kompas->ksReadInt( _T("Введите сдвиг по X"), 0, -2000, 2000, &x) ) 
      {
        if( kompas->ksReadInt( _T("Введите сдвиг по Y"), 0, -2000, 2000, &y) ) 
        {
          FileSlide file( fileNameOld, fileNameNew, x, y );
          kompas->ksMessageBoxResult();
        }
      }
    }
  }
}
