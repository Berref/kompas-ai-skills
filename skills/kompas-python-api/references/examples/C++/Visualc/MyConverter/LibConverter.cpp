////////////////////////////////////////////////////////////////////////////////
//
// Converter - Класс конвертера - мой конвертер
//
////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"

#include "LibConverter.h"
#include "Resource.h"
#include "MyConverter.h"
#include "KompasConverter.h"
#include "LibConverterParam.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern unsigned int WINAPI LIBRARYID();

// Создаёт диалог параметров конвертации
BOOL ShowPropDlg( CWnd * pParent = NULL );


// Указатель на конвертер
LibConverter * converter = NULL;


//-------------------------------------------------------------------------------
// Создание класса конвертера
// ---
LibConverter & GetLibConverter()
{
  if ( !converter )
    converter = new LibConverter();
  return *converter; 
}


//-------------------------------------------------------------------------------
// Удаление конвертера (происходит при выгрузке библиотеки см OnProcessDetach)
// ---
void ConverterDestroy() 
{
  delete converter;
  converter = NULL;
}


//-------------------------------------------------------------------------------
// Конструктор
// ---
LibConverter::LibConverter()
 : lineStyle        ( TRUE ),
   m_pConverter     ( NULL ),
   m_pConverterParam( NULL )
{
}


//-------------------------------------------------------------------------------
// Деструктор
// ---
LibConverter::~LibConverter()
{
}


//-------------------------------------------------------------------------------
// Получить класс оболочки для конвертера
// ---
KompasConverter * LibConverter::GetKompasConverter()
{
  if ( !m_pConverter )
    m_pConverter = new KompasConverter();  // При создании сделан AddRef 
  else
    m_pConverter->InternalAddRef();        // иначе делаем AddRef и возвращаем класс
  return m_pConverter;
}


//-----------------------------------------------------------------------------
// Создание класса параметров конвертера
// Т.к. интерфейс параметров один для всех команд - номер команды не обрабатывается
// ---
LibConverterParam * LibConverter::GetConvertParam( long command )
{
  if ( !m_pConverterParam )
    m_pConverterParam = new LibConverterParam();  // При создании сделан AddRef 
  else
    m_pConverterParam->InternalAddRef();          // иначе делаем AddRef и возвращаем класс
  return m_pConverterParam;
}

//-----------------------------------------------------------------------------
// Запустить визуальное редактирование параметров
// ---
BOOL LibConverter::VisualEditConvertParam( OLE_HANDLE parentHwnd, long command )
{
  CWnd * pCWnd = CWnd::FromHandlePermanent( (HWND)UlongToHandle(parentHwnd) );

  return ShowPropDlg( pCWnd );
}


//-------------------------------------------------------------------------------
// Конвертировать файл  на входе:
// inputFile - имя входного файла
// outFile -  имя выходного файла
// command - команда из Перечисление команд конвертора(MyConvEnum)
// showParam - TRUE - показывать диалог параметров, FALSE - нет
// на выходе: 1 - удачно конвертировали, 0 - неудачно конвертировали
// ---
long LibConverter::Convert( LPCTSTR inputFile, LPCTSTR outFile, long command, BOOL showParam )
{
  long res = 0;
  // Если TRUE - вызываем диалог настройки параметров конвертации 
  if ( showParam )
    VisualEditConvertParam( (OLE_HANDLE)PtrToUint(::GetHWindow()), command );
  
  // Вспомогательные переменные
  CString mess;
  
  // В зависимости от команды формируем текст сообщения
  switch ( command )
  {
    case libConv_Exp_m3d :
    {  
      mess.Format( _T("Команда libConv_Exp_m3d\nКонвертация %sфайла модели Компаса %s\nв формат (*.mym3d) %s"), 
                    inputFile && _tcslen(inputFile) ? _T("") : _T("текущего "),
                    inputFile && _tcslen(inputFile) ? inputFile : _T(""),
                    outFile
                 );
      if ( !inputFile )
        ::SaveDocumentExT(::ksGetCurrentDocument(0), (LPTSTR)outFile, 0 );
      res = 1;
      break;
    }
    case libConv_Exp_a3d :
    { 
      mess.Format( _T("Команда libConv_Exp_a3d\nКонвертация %sфайла сборки Компаса %s\nв формат (*.mya3d) %s"), 
                    inputFile && _tcslen(inputFile) ? _T("") : _T("текущего "),
                    inputFile && _tcslen(inputFile) ? inputFile : _T(""),
                    outFile
                 );
      res = 1;
      break;
    }
    case libConv_Exp_frw :
    {
      mess.Format( _T("Команда libConv_Exp_frw\nКонвертация %sфрагмента Компаса %s\nв формат (*.myfrw) %s"), 
                    inputFile && _tcslen(inputFile) ? _T("") : _T("текущего "),
                    inputFile && _tcslen(inputFile) ? inputFile : _T(""),
                    outFile
                 );
      res = 1;
      break;
    }
    case libConv_Exp_cdw :
    { 
      mess.Format( _T("Команда libConv_Exp_cdw\nКонвертация %sфайла чертежа Компаса %s\nв формат (*.mycdw) %s"), 
                    inputFile && _tcslen(inputFile) ? _T("") : _T("текущего "),
                    inputFile && _tcslen(inputFile) ? inputFile : _T(""),
                    outFile
                 );
      res = 1;
      break;
    }
    case libConv_Exp_spw :
    {  
      mess.Format( _T("Команда libConv_Exp_spw\nКонвертация %sфайла спецификации Компаса %s\nв формат (*.myspw) %s"), 
                    inputFile && _tcslen(inputFile) ? _T("") : _T("текущего "),
                    inputFile && _tcslen(inputFile) ? inputFile : _T(""),
                    outFile
                 );
      res = 1;
      break;
    }
    case libConv_Exp_kdw :
    {
      mess.Format( _T("Команда libConv_Exp_kdw\nКонвертация текстового файла Компаса %s\nв формат (*.mykdw) %s"), 
                    inputFile && _tcslen(inputFile) ? _T("") : _T("текущего "),
                    outFile
                 );
      res = 1;
      break;
    }

   
    case libConv_Imp_m3d :
    { 
      mess.Format( _T("Команда libConv_Imp_m3d\nКонвертация файла (*.mym3d)\n %s ->\n%s  "), 
                    inputFile,
                    outFile && _tcslen(outFile) ? outFile : _T("в новый документ.")
                 );
      ::OpenDocument( (char *)inputFile, 0/*regim*/);
      res = 1;
      break;
    }
    case libConv_Imp_a3d :
    {
      mess.Format( _T("Команда libConv_Imp_a3d\nКонвертация файла (*.mya3d)\n %s ->\n%s  "), 
                    inputFile,
                    outFile && _tcslen(outFile) ? outFile : _T("в новый документ.")
                 );
      res = 1;
      break;
    }
    case libConv_Imp_frw :
    {
      mess.Format( _T("Команда libConv_Imp_frw\nКонвертация файла (*.myfrw)\n %s ->\n%s  "), 
                    inputFile,
                    outFile && _tcslen(outFile) ? outFile : _T("в новый документ.")
                 );
      res = 1;
      break;
    }
    case libConv_Imp_cdw :
    {
      mess.Format( _T("Команда libConv_Imp_cdw\nКонвертация файла (*.mycdw)\n %s ->\n%s  "), 
                    inputFile,
                    outFile && _tcslen(outFile) ? outFile : _T("в новый документ.")
                 );
      res = 1;
      break;
    }
    case libConv_Imp_spw :
    {
      mess.Format( _T("Команда libConv_Imp_spw\nКонвертация файла (*.myspw)\n %s ->\n%s  "), 
                    inputFile,
                    outFile && _tcslen(outFile) ? outFile : _T("в новый документ.")
                 );
      res = 1;
      break;
    }
    case libConv_Imp_kdw :
    {
      mess.Format( _T("Команда libConv_Imp_kdw\nКонвертация файла (*.mykdw)\n %s ->\n%s  "), 
                    inputFile,
                    outFile && _tcslen(outFile) ? outFile : _T("в новый документ")
                 );
      res = 1;
      break;
    }
  }
  
  // Покажем также параметры конвертации
  CString buf;
  buf.Format( _T("\nСвойтсво Стиль линий установлено как - %s"), lineStyle ? _T("сохранять.")
                                                                           : _T(" не сохранять."));
  mess += buf;
  // Выдаём сообщение
  LibMessage( mess );
  return res;
}



//-------------------------------------------------------------------------------
// Головная функция библиотеки - на входе идентификатор команды меню из rc2
// ---
BOOL LibConverter::GetCanUnLoadLibrary()
{
  return m_pConverterParam ? FALSE : TRUE;
}

//-------------------------------------------------------------------------------
// Головная функция библиотеки - на входе идентификатор команды меню из rc2
// ---
void LibConverter::ExecuteCommand( unsigned int comm )
{
  if ( comm )
  {
    // Конвертация файла
    long command;
    // Буфер для имени файла
    TCHAR buf[_MAX_PATH] = _T("");
    CString filter;
    // "Сохранение текущего файла"
    if ( comm == 1 )
    {
      reference ref = ::ksGetCurrentDocument(0); // Получаем reference текущего документа
      if ( ref )
      {
        // Получаем тип текущего документа
        int type = ::ksGetDocumentType( ref );   
        
        // Получаем фильтр и команду для конвертирования
        filter = GetFilter( type, true /*saveAs*/, &command );
        if ( filter )
        {
          // Вызываем диалог выбора файла - там получаем путь к файлу и его имя в buf
          if ( ::ksSaveFileT( (LPTSTR)(LPCTSTR)::FindExt( filter ),0, (LPTSTR)(LPCTSTR)filter, buf, _MAX_PATH, false ) 
               && buf [0] )
          {
            // Вызываем метод - конвертировать - с диалогом параметров конвертации
            Convert( NULL/*inputFile*/, buf, command/*command*/, TRUE /*showParam*/ );
          }
        }
        else
          ::LibMessage( IDS_ERROR_DOC_TYPE );
      }
      else
        ::LibMessage( IDS_ERR_DOC );
    }
    else // "Открыть файл"
    {
      // Получаем фильтр (все поддерживаемые)
      filter = GetFilter( -1, false /*saveAs*/, &command );
      
      if ( ::ksChoiceFileT( 0, (LPTSTR)(LPCTSTR)filter, buf, _MAX_PATH, false ) && buf [0] )
      {
        // Получаем команду уже для выбранного файла
        GetFilter( ::FindExt(buf), false /*saveAs*/, &command );
        // Вызываем метод - конвертировать
        Convert( buf/*inputFile*/, NULL /*outFile*/, command/*command*/, TRUE /*showParam*/ );
      }
    }
  }
}


//-------------------------------------------------------------------------------
// Получить фильтр и номер команды по расширению документа
// ---
BSTR LibConverter::GetFilter( LPCTSTR ext, BOOL saveAs, long * command )
{
  long docType = -1;
  // Сравниваем расширения файлов
  if ( _tcsicmp( ext, ::FindExt(::LoadStr(IDS_DOC_M3D))) )
    docType = lt_DocPart3D;
  else
    if ( _tcsicmp( ext, ::FindExt(::LoadStr(IDS_DOC_A3D))) )
      docType = lt_DocAssemble3D;
    else
      if ( _tcsicmp( ext, ::FindExt(::LoadStr(IDS_DOC_CDW))) )
        docType = lt_DocSheetStandart;
      else
        if ( _tcsicmp( ext, ::FindExt(::LoadStr(IDS_DOC_FRW))) )
          docType = lt_DocFragment;
        else
          if ( _tcsicmp( ext, ::FindExt(::LoadStr(IDS_DOC_SPW))) )
            docType = lt_DocSpc;
          else
            if ( _tcsicmp( ext, ::FindExt(::LoadStr(IDS_DOC_KDW))) )
              docType = lt_DocTxtStandart;

  return GetFilter( docType, saveAs, command );
}


//-------------------------------------------------------------------------------
// Получить фильтр и номер команды по типу документа
// Выдаёт информацию уже помещённую в реестр по пути
// [HKEY_LOCAL_MACHINE\SOFTWARE\ASCON\KOMPAS-3D\Converters\LibConverter]
// ---
BSTR LibConverter::GetFilter( long docType, BOOL saveAs, long * command )
{
  CString res;
  if ( command )
  {
    switch ( docType )
    {
      // Модель
      case lt_DocPart3D        : 
      {
        res = ::LoadStr( IDS_DOC_M3D );  // "Файлы моделей(*.mym3d)|*.mym3d|"
        *command = saveAs ? libConv_Exp_m3d : libConv_Imp_m3d;
        break;
      }
      // Сборка
      case lt_DocAssemble3D        : 
      {
        res = ::LoadStr( IDS_DOC_A3D ); // "Файлы сборок(*.mya3d)|*.mya3d|"
        *command = saveAs ? libConv_Exp_a3d : libConv_Imp_a3d;
        break;
      }
      // Чертёж и пользовательский чертёж
      case lt_DocSheetUser     :
      case lt_DocSheetStandart : 
      {
        res = ::LoadStr( IDS_DOC_CDW ); // "Файлы чертежей(*.mycdw)|*.mycdw|"
        *command = saveAs ? libConv_Exp_cdw : libConv_Imp_cdw;
        break;
      }
      // Фрагмент
      case lt_DocFragment        : 
      {
        res = ::LoadStr( IDS_DOC_FRW ); // "Файлы фрагментов(*.myfrw)|*.myfrw|";  
        *command = saveAs ? libConv_Exp_frw : libConv_Imp_frw;
        break;
      }
      // Спецификация и пользовательская спецификация
      case lt_DocSpcUser    :
      case lt_DocSpc        : 
      {
        res = ::LoadStr( IDS_DOC_SPW ); // "Файлы спецификаций(*.myspw)|*.myspw|";  
        *command = saveAs ? libConv_Exp_spw : libConv_Imp_spw;
        break;
      }
      // Текстовый документ и пользовательский текстовый документ
      case lt_DocTxtUser       :
      case lt_DocTxtStandart   : 
      {
        res = ::LoadStr( IDS_DOC_KDW ); // "Файлы текстовых документов(*.mykdw)|*.mykdw|";  
        *command = saveAs ? libConv_Exp_kdw : libConv_Imp_kdw;
        break;
      }
      // Сформировать фильтр из всех поддерживаемых форматов
      default:
      {
        res  = ::LoadStr( IDS_DOC_M3D );
        res += ::LoadStr( IDS_DOC_A3D );
        res += ::LoadStr( IDS_DOC_CDW );
        res += ::LoadStr( IDS_DOC_FRW );
        res += ::LoadStr( IDS_DOC_SPW );
        res += ::LoadStr( IDS_DOC_KDW );
        *command = -1;
        break;
      }
    }
  }
  return res.AllocSysString();
}


//-----------------------------------------------------------------------------
// Установить признак сохранения стиля линий 
// ---
void LibConverter::SetSaveLineStyle( bool val )
{
  lineStyle = val;
}

//-----------------------------------------------------------------------------
// Получить признак сохранения стиля линий 
// ---
bool LibConverter::GetSaveLineStyle()
{
  return lineStyle;
}
